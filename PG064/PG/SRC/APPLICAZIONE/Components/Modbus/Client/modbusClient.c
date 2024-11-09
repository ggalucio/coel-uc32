/*
 * modbusClient.c
 *
 *  Created on: 22 nov 2021
 *      Author: paoloc
 */

#include "modbusClient.h"
#include "Components/Modbus/modbusCommon.h"
#include "Utils/modbusUtils.h"
#include "stdlib.h"
#include "string.h"

/**
* Invalid value
*/
#define INVALIDE_VALUE 0xffff

/**
* Current modbus client pointer.
*/
ModbusClientTypeDef *pModbusClient = { 0 };

/**
* @brief Modbus read registers index retriever
* This function retrieves modbus read array index from register address.
* @param addr: register address.
* @retval: index corresponging register address.
*/
int GetModbusReadByAddress(DWORD addr){
	int i;
	for(i = 0; pModbusClient->ModbusDataExch->ModbusDataRead != NULL &&
		i < pModbusClient->ModbusDataExch->ModbusDataReadLength; i++){
			if(pModbusClient->ModbusDataExch->ModbusDataRead[i].baseAddress == addr)
				return i;
	}

	return -1;
}

/**
* @brief Modbus write registers index retriever
* This function retrieves modbus write array index from register address.
* @param addr: register address.
* @retval: index corresponging register address.
*/
int GetModbusWriteByAddress(DWORD addr){
	int i;
	for(i = 0; pModbusClient->ModbusDataExch->ModbusDataWrite != NULL &&
		i < pModbusClient->ModbusDataExch->ModbusDataWriteLength; i++){
			if(pModbusClient->ModbusDataExch->ModbusDataWrite[i].baseAddress == addr)
				return i;
	}

	return -1;
}

/**
* @brief Modbus registers reader
* This function reads data register from the received package.
* @param data: received modbus package.
* @param buffLen: received modbus package length.
* @param offset: data index to read.
* @param nBytes: data to read bytes number (if it's a floating point 32 bit this number is 4, otherwise 2).
* @retval: register data.
*/
DWORD ReadResponse(BYTE* data, int buffLen, int offset, int nBytes){
	return pModbusClient->ReadResponse(data, buffLen, offset, nBytes, pModbusClient->ResponseDataIdx);
	//return ReadModbusDataResp(data, buffLen, offset, nBytes, TCPIP_START_DATA_IDX);
}

/**
* @brief Modbus registers updater
* A read response has been received.
* This function retrieves data from the received package and updates corresponding local values.
* @param idx: chunks structure index to update.
*/
void UpdateRegisters(int idx){
	int mIdx;
	int offset = 0;
	DWORD addr = pModbusClient->chunks.data[idx].Address;

	for(mIdx = 0; pModbusClient->chunks.data != NULL &&
			mIdx < pModbusClient->chunks.data[idx].Length; mIdx++){
		int modbusIdx = GetModbusReadByAddress(addr);
		if(modbusIdx >= 0){
			BYTE len = pModbusClient->ModbusDataExch->ModbusDataRead[modbusIdx].length * 2;

			// Leggo il valore ricevuto e lo aggiorno.
			DWORD dataSent = ReadResponse(pModbusClient->RxBuffer.pBuff, pModbusClient->RxBuffer.length, offset, len);
			pModbusClient->ModbusDataExch->ModbusDataRead[modbusIdx].value = dataSent;

			// Alzo un FLAG per segnalare che il valore è stato aggiornato.
			AT_SET_BIT(pModbusClient->ModbusDataExch->ModbusDataRead[modbusIdx].command, READ_INVALIDATE_BIT);

		}
		addr++;
		offset += 2;
	}
}

/**
* @brief Modbus resetter.
* This function resets everything before sending new requests
*/
void ResetModbus(){
	pModbusClient->currReadAddress = 0;
	pModbusClient->reqType = REQ_NONE;
	pModbusClient->exchDataState = MM_IDLE;
	//_ResetRxBuff();

	if(pModbusClient->Handler->RstClbk)
		pModbusClient->Handler->RstClbk();
}

/**
* @brief Modbus request initializer.
* This function clear all before sending new requests.
*/
void InitModbus(){
	pModbusClient->currReadIdx = 0;
	ResetModbus();
}

/**
* @brief Modbus write request registers counter.
* A write request has been detected.
* This function checks how many registers have to be written in order to understand
* if a single or multiple write request has to be sent.
* @retval: registers number to write
*/
BYTE HowManyDataToWrite(void){
	BYTE countDatatoWrite = 0;
	int i;
	for(i = 0; i < pModbusClient->ModbusDataExch->ModbusDataWriteLength; i++)
	{
		if(AT_READ_BIT(pModbusClient->ModbusDataExch->ModbusDataWrite[i].command, WRITE_INVALIDATE_BIT)){
			countDatatoWrite++;
		}
	}

	return countDatatoWrite;
	//return 1;
}

/**
* @brief Modbus write request controller.
* Write requests have priority on read requests.
* This function checks if some write requests occurred or not.
* @retval: 1 if a write request occurred, 0 otherwise.
*/
BOOLEAN HasDataToWrite(void){
	int i;
	for(i = 0; i < pModbusClient->ModbusDataExch->ModbusDataWriteLength; i++)
	{
		if(AT_READ_BIT(pModbusClient->ModbusDataExch->ModbusDataWrite[i].command, WRITE_INVALIDATE_BIT)){
			return AT_TRUE;
		}
	}

	return AT_FALSE;
}

/**
* @brief Modbus new request enabled.
* This function checks if there are conditions new request to send.
* @retval: 1 if a request can be sent, 0 otherwise.
*/
BOOLEAN IsReqEnabled(){
	return pModbusClient->exchDataState == MM_ENABLE_TO_READ ||
			pModbusClient->exchDataState == MM_ENABLE_TO_WRITE ? AT_TRUE : AT_FALSE;
}

/**
* @brief Modbus generic request sender.
* This function sends a generic request.
* @param id: modbus slave address.
* @param code: modbus function code.
* @param address: modbus start address.
* @param length: modbus registers number.
* @param value:	data to write. If it's a read request, this parameter is NULL.
* @retval: 1 if a write request is sending, 0 if an error occurred
*/
BOOLEAN SendRequest(int id, int code, DWORD address, int length, uint16_t* value){
	BOOLEAN sentReq = AT_FALSE;

	if(IsReqEnabled())
	{
		BYTE* pModbusReq = NULL;
		int size = 0;

		ModbusInfo modbusInfo;
		modbusInfo.Address = address;
		modbusInfo.TransactionId = pModbusClient->transactionId++;

		BOOLEAN isPack = pModbusClient->PackReq(&pModbusReq, &size, id, code, modbusInfo, length, value);

		if(isPack &&  pModbusClient->Handler->Send)
		{
			pModbusClient->currSlaveAddress = id;
			pModbusClient->currFunctionCode = code;
			sentReq = pModbusClient->Handler->Send(pModbusReq, size);
		}

		free(pModbusReq);
		pModbusReq = NULL;
	}

	return sentReq;
}

/**
* @brief Modbus read request sender.
* This function sends a read request.
* @param id: slave address.
* @param address: modbus start address to read.
* @param length: modbus registers number to read.
* @retval: 1 if a read request is sending, 0 if an error occurred
*/
BOOLEAN ReadRequest(int id, DWORD address, BYTE length){
	return SendRequest(id, MODBUS_CODE_READ_HOLDING_REG, address, length, 0);
}

/**
* @brief Modbus write request sender.
* This function sends a write request.
* @param id: slave address.
* @param address: modbus start address to write.
* @param length: modbus registers number to write.
* @param value:	data to write.
* @retval: 1 if a write request is sending, 0 if an error occurred
*/
BOOLEAN WriteRequest(int id, DWORD address, int length, WORD* value){
	return SendRequest(id, length > 1 ? MODBUS_CODE_MULTIPLE_WRITE : MODBUS_CODE_SINGLE_WRITE, address, length, value);
}

/**
* @brief Modbus read request sender.
* This function retrieves parameters and sends a read request.
* @retval: 1 if a read request is sending, 0 if an error occurred
*/
BOOLEAN SendReadRequest(){
	// Recupero le informazioni che mi servono per impacchettare il dato per la lettura.
	int idx 		= pModbusClient->currReadIdx % pModbusClient->chunks.length;//pModbusClient->readRegistersNum;
	DWORD addr 		= pModbusClient->chunks.data[idx].Address;
	BYTE length 	= pModbusClient->chunks.data[idx].Length;

	// Tengo traccia dell'indirizzo del dato richiesto per confronti successivi.
	pModbusClient->currReadAddress	= addr;

	// Invio la richiesta in lettura.
	return ReadRequest(1, addr, length);
}

/**
* @brief Modbus multiple write request sender.
* This function retrieves parameters and sends a multiple write request.
* @retval: 1 if a write request is sending, 0 if an error occurred
*/
BOOLEAN SendMultipleWriteRequest(){
	BaseRegTypeDef baseRegs[pModbusClient->ModbusDataExch->ModbusDataWriteLength];
	int i;
	for(i = 0; i < pModbusClient->ModbusDataExch->ModbusDataWriteLength; i++){
		baseRegs[i].Address = (volatile WORD)(pModbusClient->ModbusDataExch->ModbusDataWrite[i].baseAddress);
		baseRegs[i].Length  = (volatile BYTE)(pModbusClient->ModbusDataExch->ModbusDataWrite[i].length);
	}

	ModbusChunks chunks = { 0 };
	CreateChunks(baseRegs, pModbusClient->ModbusDataExch->ModbusDataWriteLength, chunks.data, &chunks.length);

	WORD baseAddr = INVALIDE_VALUE;
	WORD *pValues = (WORD*)malloc(sizeof(WORD));
	BYTE registersToWriteNum = 0;
	for(i = 0; i < chunks.length && baseAddr == INVALIDE_VALUE; i++){
		WORD address = chunks.data[i].Address;
		WORD endAddress = address + chunks.data[i].Length;

		while(address < endAddress){
			int idx = GetModbusWriteByAddress(address);
			if(idx >= 0){

				DWORD value	= pModbusClient->ModbusDataExch->ModbusDataWrite[idx].value;
				BYTE length = pModbusClient->ModbusDataExch->ModbusDataWrite[idx].length;

				if(AT_READ_BIT(pModbusClient->ModbusDataExch->ModbusDataWrite[idx].command, WRITE_INVALIDATE_BIT)){

					AT_CLEAR_BIT(pModbusClient->ModbusDataExch->ModbusDataWrite[idx].command, WRITE_INVALIDATE_BIT);

					if(baseAddr == INVALIDE_VALUE){
						baseAddr = address;
					}

					WORD pValue[length];
					// Popolo l'array di WORD da mandare in scrittura.
					PACKWRITEDATA(pValue, value, length);

					BYTE baseIdx = address - baseAddr;
					registersToWriteNum = baseIdx + length;
					pValues = (WORD*)realloc(pValues, sizeof(WORD) * registersToWriteNum);
					memcpy(&pValues[baseIdx], pValue, sizeof(WORD) * length);
				}

				// Update address
				address += length;
			}
			else address++;
		}
	}

	WORD values[registersToWriteNum];
	memcpy(values, pValues, sizeof(WORD) * registersToWriteNum);

	free(pValues);
	pValues = NULL;
	return WriteRequest(1, baseAddr, registersToWriteNum, values);
}

/**
* @brief Modbus single write request sender.
* This function retrieves parameters and sends a single write request.
* @retval: 1 if a write request is sending, 0 if an error occurred
*/
BOOLEAN SendSingleWriteRequest(){
	// Recupero l'indice del dato che deve essere scritto.
	FINDWRITEDATAINDEX(pModbusClient->ModbusDataExch->ModbusDataWrite, pModbusClient->ModbusDataExch->ModbusDataWriteLength);

	/*
	 * Se la condizione è vera, significa che non sono stati individuati dati da scrivere.
	 * Non dovrei mai trovarmi in questa situazione, ma non si sa mai...
	 * */
	if(i >= pModbusClient->ModbusDataExch->ModbusDataWriteLength)
		return AT_FALSE;

	// Recupero le informazioni che mi servono per impacchettare il dato per la scrittura.
	BYTE length = pModbusClient->ModbusDataExch->ModbusDataWrite[i].length;
	DWORD addr 	= pModbusClient->ModbusDataExch->ModbusDataWrite[i].baseAddress;
	DWORD value	= pModbusClient->ModbusDataExch->ModbusDataWrite[i].value;


	uint16_t pValue[length];

	// Popolo l'array di WORD da mandare in scrittura.
	PACKWRITEDATA(pValue, value, length);
	return WriteRequest(1, addr, length, pValue);
}

/**
* @brief Modbus reset.
* This function resets all before start new modbus data exchange.
*/
void ModbusInit(){
	pModbusClient->currReadIdx = 0;
	ResetModbus();
}

/**
* @brief Modbus request type detection.
* A modbus request is going to be send.
* This function tries to understand which request type has to be sent, if read or write.
*/
void ModbusIdle(){
	if(pModbusClient->IsConnectionAvailable())
	{
		pModbusClient->currReadIdx++;
		//_ResetRxBuff();
		pModbusClient->ackTimer = HAL_GetTick();
		pModbusClient->exchDataState = HasDataToWrite() ? MM_ENABLE_TO_WRITE : MM_ENABLE_TO_READ;
	}
	else{
		pModbusClient->exchDataState = MM_ERROR;
	}
}

/**
* @brief Modbus read request.
* This function sends a read request to remote device.
*/
void ModbusEnableToRead(){

	if(pModbusClient->chunks.length == 0){
		ResetModbus();
		return;
	}

	pModbusClient->reqType = REQ_READ;
	BOOLEAN sentReqRes = SendReadRequest();
	pModbusClient->ackTimer = HAL_GetTick();
	pModbusClient->exchDataState = sentReqRes ? MM_SENDING_REQ : MM_ERROR;
}

/**
* @brief Modbus write request.
* This function sends a write request to remote device.
*/
void ModbusEnableToWrite(){

	// In case of multiple registers to write, it waits some milliseconds
	// in order to be sure to have updated all write commands.
	if(TimeOutElapsed(pModbusClient->ackTimer, 100)){
		pModbusClient->reqType = REQ_WRITE;
		//BYTE regToWriteNum = HowManyDataToWrite();
		//BOOLEAN sentReqRes = regToWriteNum > 1 ?  SendMultipleWriteRequest() : SendSingleWriteRequest();
		BOOLEAN sentReqRes = SendSingleWriteRequest();
		pModbusClient->exchDataState = sentReqRes ? MM_SENDING_REQ : MM_ERROR;
	}
}

/**
* @brief Modbus sending request.
* This function waits for a request to be sent.
*/
void ModbusSendingReq(){
	if(pModbusClient->Handler->State != MB_TRANSMITTING){
		pModbusClient->exchDataState = MM_SENT_REQ;
	}

	if( TimeOutElapsed( pModbusClient->ackTimer, TIMEOUT_REQ))
		pModbusClient->exchDataState = MM_ERROR;
}

/**
* @brief Modbus sent request.
* This function updates timer after a request has been sent.
*/
void ModbusSentReq(){
	pModbusClient->ackTimer = HAL_GetTick();
	pModbusClient->exchDataState = MM_WAIT_FOR_RESP;
}

/**
* @brief Modbus pending response.
* This function is waiting for a response after a request has been sent.
* If it takes too long, an error is generated.
*/
void ModbusWaitForResp(){
	if(TimeOutElapsed(pModbusClient->ackTimer, TIMEOUT_REQ))
	{
		pModbusClient->exchDataState = MM_ERROR;
	}
	if(pModbusClient->RxBuffer.valid){
		//printf("Client Time Elapsed: %d\n", HAL_GetTick() - pModbusClient->ackTimer);
		pModbusClient->RxBuffer.valid = AT_FALSE;
		pModbusClient->exchDataState = MM_RECV_RESP;
	}
}

/**
* @brief Modbus response validation checker.
* This function checks if modbus response is valid or not.
*/
void ModbusRecvResp(){
	pModbusClient->exchDataState =
			pModbusClient->RespIsValid(pModbusClient->RxBuffer.pBuff, pModbusClient->RxBuffer.length, pModbusClient->currSlaveAddress, pModbusClient->currFunctionCode) ?
			//RespTcpipIsValid(pModbusCycleTypeDef->rxData.pBuff, pModbusCycleTypeDef->currSlaveAddress, pModbusCycleTypeDef->currFunctionCode) ?
					MM_UNPACK_RESP : MM_ERROR;
}

/**
* @brief Modbus response unpacker.
* This function unpacks response package received from remote device.
*/
void ModbusUnpackResp(){
	if(pModbusClient->reqType == REQ_READ){
		//int idx = pModbusClient->currReadIdx % pModbusClient->readRegistersNum;
		int idx = pModbusClient->currReadIdx % pModbusClient->chunks.length;
		if(pModbusClient->currReadAddress == pModbusClient->chunks.data[idx].Address &&
				TimeOutElapsed(pModbusClient->startTick, 200)){
			UpdateRegisters(idx);
		}
	}
	ResetModbus();
}

/**
* @brief Modbus error manager.
* This function manages some detected error/s which occurred during data exchange between devices.
*/
void ModbusError(){
	ResetModbus();

	if(pModbusClient->Handler->Error){
		pModbusClient->Handler->Error();
	}
}

/**
* @brief No more modbus requests detected.
* This function is called when no more requests are detected,
* so resets some variables and stops data exchanges.
*/
void ModbusNoData(){
	//pModbusClient->ModbusDataExch->ModbusDataReadLength  = 0;
	//pModbusClient->ModbusDataExch->ModbusDataWriteLength = 0;
	pModbusClient->readRegistersNum = 0;

	pModbusClient->exchDataState = MM_INIT;
	pModbusClient->managementDataState = MD_WAIT_FOR_DATA;
}

/**
* @brief Modbus init and reset.
* This function initializes and resets variables before starting modbus data exchanges.
*/
void ModbusCycleStart(){
	InitModbus();
	pModbusClient->managementDataState = MD_WAIT_FOR_DATA;
}

/**
* @brief Modbus requests not yet detected.
* This function is waiting for new requests to arrive.
*/
void ModbusCycleNoData(){
	// Faccio il reset del timer modbus TCPIP...
	pModbusClient->ResetTimer();

	// Se ho ricevuto nuovi dati, faccio il cambio di stato e
	// passo a MD_WAIT, in caso contrario tutto rimane invariato...
	if(pModbusClient->ModbusDataExch->ModbusDataReadLength != 0 ||
			pModbusClient->ModbusDataExch->ModbusDataWriteLength != 0){
		pModbusClient->managementDataState	= MD_WAIT;
		pModbusClient->ackTimer = HAL_GetTick();
	}
}

/**
* @brief Modbus waiter
* This function waits for some few milliseconds before starting new requests.
*/
void ModbusCycleWait(){
	if(TimeOutElapsed(pModbusClient->ackTimer, 50)){
		pModbusClient->chunks.length = 0;
		pModbusClient->managementDataState	= MD_INIT;
	}
}

/**
* @brief Modbus local data and structures initializer
* This function initializes data and creates chunks.
*/
void ModbusCycleInit(){
	BaseRegTypeDef baseRegs[pModbusClient->ModbusDataExch->ModbusDataReadLength];
	int i;
	for(i = 0; i < pModbusClient->ModbusDataExch->ModbusDataReadLength; i++){
		baseRegs[i].Address = (volatile WORD)(pModbusClient->ModbusDataExch->ModbusDataRead[i].baseAddress);
		baseRegs[i].Length  = (volatile BYTE)(pModbusClient->ModbusDataExch->ModbusDataRead[i].length);
	}

	for(i = 0; i < pModbusClient->ModbusDataExch->ModbusDataWriteLength; i++)
		pModbusClient->ModbusDataExch->ModbusDataWrite[i].command = 0;

	pModbusClient->currReadIdx = 0;
	memset(pModbusClient->chunks.data, 0, sizeof(BaseRegTypeDef) * MODBUS_DATA_SIZE);
	CreateChunks(baseRegs, pModbusClient->ModbusDataExch->ModbusDataReadLength, pModbusClient->chunks.data, &pModbusClient->chunks.length);
	pModbusClient->readRegistersNum = pModbusClient->ModbusDataExch->ModbusDataReadLength;
	pModbusClient->StartTimer();
	pModbusClient->startTick			= HAL_GetTick();
	pModbusClient->managementDataState	= MD_VALID;
	pModbusClient->exchDataState		= MM_INIT;
}

/**
* @brief Exchanged modbus packages manager.
* This function manages data exchange between connected devices.
*/
void ModbusCycleRun(){
	/*
	 * Non ho dati validi a disposizione.
	 * Dealloco tutte le risorse che sto occupando e azzero le variabili.
	 * */
	if(pModbusClient->ModbusDataExch->ModbusDataReadLength == 0 &&
			pModbusClient->ModbusDataExch->ModbusDataWriteLength == 0){
		pModbusClient->exchDataState = MM_NO_DATA;
	}

	/*
	 * Potrebbe accadere che sono stati aggiunti nuovi dati.
	 * Rialloco tutte le mie risorse da zero.
	 * */
	if(pModbusClient->readRegistersNum < pModbusClient->ModbusDataExch->ModbusDataReadLength)
	{
		pModbusClient->exchDataState = MM_NO_DATA;
	}

	switch(pModbusClient->exchDataState){
		case MM_INIT: 				ModbusInit();									break;
		case MM_IDLE: 				ModbusIdle();									break;
		case MM_ENABLE_TO_READ: 	ModbusEnableToRead();							break;
		case MM_ENABLE_TO_WRITE: 	ModbusEnableToWrite();							break;
		case MM_SENDING_REQ:		ModbusSendingReq();								break;
		case MM_SENT_REQ: 			ModbusSentReq();								break;
		case MM_WAIT_FOR_RESP: 		ModbusWaitForResp();							break;
		case MM_RECV_RESP: 			ModbusRecvResp();								break;
		case MM_UNPACK_RESP: 		ModbusUnpackResp();								break;
		case MM_ERROR: 				ModbusError();									break;
		case MM_NO_DATA: 			ModbusNoData();									break;
		default: 					pModbusClient->exchDataState = MM_INIT;			break;
	}
}

/**
* @brief Connected remote device controller
* This function manages and prepares local data and structures
* according to register address and number client wants to query.
*/
void ModbusClientDataManagement(){
	switch(pModbusClient->managementDataState){
		case MD_START:			ModbusCycleStart();								break;
		case MD_WAIT_FOR_DATA:	ModbusCycleNoData();							break;
		case MD_WAIT:			ModbusCycleWait();								break;
		case MD_INIT:			ModbusCycleInit();								break;
		case MD_VALID:			ModbusCycleRun();								break;
		default:				pModbusClient->managementDataState = MD_START; 	break;
	}
}

/**
* @brief Remote device connection controller
* This function checks if a disconnected client finds a physical connection to remote device or not.
*/
void ModbusCycleDisconnected(){
	if(pModbusClient->IsPhyConnected()){
		pModbusClient->Init();
		pModbusClient->phyConnection = MP_CONNECTED;
	}

	pModbusClient->managementDataState	= MD_START;
	pModbusClient->exchDataState 		= MM_INIT;
}

/**
* @brief Remote device connection controller
* This function checks if a connected client looses its physical connection with remote device or not.
*/
void ModbusCycleConnected(){
	if(!pModbusClient->IsPhyConnected()){
		pModbusClient->DeInit();
		pModbusClient->phyConnection = MP_DISCONNECTED;
	}
	else{
		ModbusClientDataManagement();
	}
}

/**
* @brief Set next client pointer to manage.
* This function sets modbus client pointer to manage.
* @param pClient: client pointer to manage.
*/
void SetModbusClient(ModbusClientTypeDef *pClient){
	pModbusClient = pClient;
}

/**
* @brief Modbus client cycle machine state entry point.
* This function is the entry point for modbus RTU and TCPIP client management.
*/
void ModbusClientCycle(){

	if(!pModbusClient)
		return;

	if(!pModbusClient->IsEnable()){
		pModbusClient->exchDataState = MMS_INIT;
		pModbusClient->phyConnection = MP_DISCONNECTED;
		return;
	}

	// Aggiorno il timer della comunicazione modbus...
	if(pModbusClient->UpdateTimer)
		pModbusClient->UpdateTimer();

	switch(pModbusClient->phyConnection){
		case MP_DISCONNECTED: 	ModbusCycleDisconnected(); 	break;
		case MP_CONNECTED:	 	ModbusCycleConnected();		break;
	}

}
