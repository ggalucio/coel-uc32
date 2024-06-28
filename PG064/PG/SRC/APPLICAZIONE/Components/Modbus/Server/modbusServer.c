/*
 * modbusServer.c
 *
 *  Created on: 16 nov 2021
 *      Author: paoloc
 */


#include "modbusServer.h"
#include "../modbusCommon.h"
#include "stdlib.h"
#include "string.h"

/**
* Transmitting timeout value
*/
#define TIMEOUT_TRANSMITTING 			2000

/**
* Minimum millisecond to elapse before managing same server.
*/
#define TIMEOUT_MODBUS_SERVER_CYCLE 	1

/**
* Current modbus server.
*/
ModbusServerTypeDef modbusServer;

/**
* Current modbus server pointer.
*/
volatile ModbusServerTypeDef *pModbusServer = { 0 };

/**
* @brief Modbus read response.
* This function sends read response back to client.
* @param pRespPack: modbus response package pointer.
* @param pPackLen: modbus response package length.
*/
void ReadHoldingRegisters(BYTE** pRespPack, BYTE* pPackLen){
	ModbusInfo modbusInfo;
	pModbusServer->ExceptionCode = pModbusServer->UnpackMultipleReadRequest((BYTE*)&pModbusServer->Buffer.pBuff, pModbusServer->Buffer.length, &modbusInfo);

	if(pModbusServer->ExceptionCode != MODBUS_CODE_NO_EXCEPTIONS)
		return;

	WORD registers[modbusInfo.RegisterNum];

	int i;
	for(i = 0; i < modbusInfo.RegisterNum; i++)
	{
		registers[i] = *(WORD*)(pModbusServer->LocalAddress + (modbusInfo.Address + i) * BYTES_IN_WORD);
	}
	*pPackLen = pModbusServer->PackMultipleReadResponse(pModbusServer->Buffer.pBuff[pModbusServer->SlaveAddrPos], *pRespPack, registers, modbusInfo);
}

/**
* @brief Modbus multiple write response.
* This function stores multiple data incoming from client and sends multiple write response back.
* @param pRespPack: modbus response package pointer.
* @param pPackLen: modbus response package length.
*/
void WriteMultipleHoldingRegisters(BYTE** pRespPack, BYTE* pPackLen){
	ModbusInfo modbusInfo;
	WORD* registers = NULL;
	pModbusServer->ExceptionCode = pModbusServer->UnpackMultipleWriteRequest((BYTE*)&pModbusServer->Buffer.pBuff, pModbusServer->Buffer.length, &registers, &modbusInfo);

	if(pModbusServer->ExceptionCode != MODBUS_CODE_NO_EXCEPTIONS)
		return;

	if(registers == NULL)
		return;

	int i;
	for(i = 0; i < modbusInfo.RegisterNum; i++)
		STOREMODBUS(modbusInfo.Address * BYTES_IN_WORD + i, pModbusServer->LocalAddress, registers[i], 1);

	free(registers);
	registers = NULL;

	*pPackLen = pModbusServer->PackMultipleWriteResponse(pModbusServer->Buffer.pBuff[pModbusServer->SlaveAddrPos], *pRespPack, modbusInfo);
}

/**
* @brief Modbus single write response.
* This function stores single data incoming from client and sends single write response back.
* @param pRespPack: modbus response package pointer.
* @param pPackLen: modbus response package length.
*/
void WriteSingleHoldingRegisters(BYTE** pRespPack, BYTE* pPackLen){
	ModbusInfo modbusInfo;
	pModbusServer->ExceptionCode = pModbusServer->UnpackSingleWriteRequest((BYTE*)&pModbusServer->Buffer.pBuff, pModbusServer->Buffer.length, &modbusInfo);

	if(pModbusServer->ExceptionCode != MODBUS_CODE_NO_EXCEPTIONS)
		return;

	STOREMODBUS(modbusInfo.Address, pModbusServer->LocalAddress, modbusInfo.Register, 1);
	*pPackLen = pModbusServer->PackSingleWriteResponse(pModbusServer->Buffer.pBuff[pModbusServer->SlaveAddrPos], *pRespPack, modbusInfo);
}

/**
* @brief Modbus peripheral initializer.
* This function initializes peripheral before starting modbus server management.
*/
void StartMaster(){

	if(pModbusServer->CloseConnection){
		pModbusServer->CloseConnection();
	}

	if(pModbusServer->InitPeripheral)
	{
		BOOLEAN init = pModbusServer->InitPeripheral();
		pModbusServer->State = init ? MMS_RST : MMS_INIT;
		//pModbusServer->State = init ? MMS_RECEIVE : MMS_INIT;
	}
	else{
		pModbusServer->State = MMS_INIT;
	}
}

/**
* @brief Waiting for modbus request.
* This function cleans data before waiting for new requests from client.
*/
void ReceiveMaster(){
	if(pModbusServer->StartReceiving){
		pModbusServer->StartReceiving();
		pModbusServer->State = MMS_RECEIVING;
	}
	else{
		pModbusServer->State = MMS_INIT;
	}
}

/**
* @brief Waiting for modbus request.
* This function is waiting for new requests from client.
* If a request arrives, it checks if package is consistent before sending response.
*/
void ReceivingMaster(){
	if(!pModbusServer->IsFunctionCodeValid 	||
			!pModbusServer->IsFrameValid 	/*||
			pModbusServer->Communication->State == MB_ERR*/)
	{
		pModbusServer->State = MMS_INIT;
		return;
	}

	if(pModbusServer->Communication->State == MB_RST)
		pModbusServer->State = MMS_RST;

	if(pModbusServer->Buffer.valid){
		pModbusServer->Buffer.valid = 0;

		if(pModbusServer->Buffer.length > 0){
			// Controllo che il codice funzione sia valido
			if(pModbusServer->IsFunctionCodeValid((BYTE*)&pModbusServer->Buffer.pBuff, pModbusServer->Buffer.length)){
				// Controllo che la checksum sia corretta.
				BOOLEAN isValid = pModbusServer->IsFrameValid((BYTE*)&pModbusServer->Buffer.pBuff, pModbusServer->Buffer.length);
				pModbusServer->State = isValid ? MMS_TRANSMIT : MMS_ERR;
			}
			else{
				pModbusServer->ExceptionCode = MODBUS_CODE_ILLEGAL_FUNCTION;
				pModbusServer->State = MMS_EXCEPTION;
			}
		}
		else{
			pModbusServer->State = MMS_ERR;
		}
	}
}

/**
* @brief Modbus response transmission.
* This function transmits new response.
*/
void TransmitMaster(){
	BYTE funcCode = pModbusServer->Buffer.pBuff[pModbusServer->FunctionCodePos];
	BYTE* pModbusResp;
	uint8_t respLen = 0;

	switch(funcCode){
		case MODBUS_CODE_READ_HOLDING_REG:	ReadHoldingRegisters(&pModbusResp, &respLen);			break;
		case MODBUS_CODE_SINGLE_WRITE:		WriteSingleHoldingRegisters(&pModbusResp, &respLen);	break;
		case MODBUS_CODE_MULTIPLE_WRITE:	WriteMultipleHoldingRegisters(&pModbusResp, &respLen);	break;
		default:																					break;
	}

	BOOLEAN sent = AT_FALSE;

	if(respLen > 0 && pModbusResp && pModbusServer->Communication){
		if(pModbusServer->Communication->Send)
			sent = pModbusServer->Communication->Send(pModbusResp, respLen);
	}

	pModbusServer->Tick = HAL_GetTick();
	pModbusServer->State = sent ? MMS_TRANSMITTING : (pModbusServer->ExceptionCode != MODBUS_CODE_NO_EXCEPTIONS ? MMS_ERR : MMS_EXCEPTION);
}

/**
* @brief Modbus response transmission in progress.
* This function is waiting until response is sent.
*/
void TransmittingMaster(){
	if(pModbusServer->Communication->State != MB_TRANSMITTING){
		pModbusServer->State = MMS_RST;
		//printf("TX in %d ms\n", HAL_GetTick() - pModbusServer->Tick);
	}

	if(TimeOutElapsed(pModbusServer->Tick, TIMEOUT_TRANSMITTING))
		pModbusServer->State = MMS_ERR;
}

/**
* @brief Modbus resetter.
* This function resets everything before waiting for new requests
*/
void RstMaster(){
	if(pModbusServer->Reset){
		pModbusServer->Reset();
		pModbusServer->State = MMS_RECEIVE;
	}
	else
		pModbusServer->State = MMS_ERR;
}

/**
* @brief Modbus exceptions manager.
* This function manages exceptions that must be sent to client.
*/
void ExceptionMaster(){
	if(pModbusServer->Buffer.pBuff){
		BYTE exceptionPack[MODBUS_EXCEPTION_RESPONSE_SIZE];
		pModbusServer->PackExceptions(exceptionPack, pModbusServer->Buffer.pBuff[pModbusServer->SlaveAddrPos],
				pModbusServer->Buffer.pBuff[pModbusServer->FunctionCodePos], pModbusServer->ExceptionCode);
		pModbusServer->Communication->Send(exceptionPack, MODBUS_EXCEPTION_RESPONSE_SIZE);
	}
	pModbusServer->State = MMS_ERR;
}

/**
* @brief Modbus error manager.
* This function manages some detected error/s which occurred during data exchange between devices.
*/
void ErrorMaster(){
	pModbusServer->Communication->RstClbk();
	RstMaster();
}

/**
* @brief Set next server pointer to manage.
* This function sets modbus server pointer to manage.
* @param pServer: server pointer to manage.
*/
void SetModbusServer(ModbusServerTypeDef *pServer){
	pModbusServer = pServer;
}

/**
* @brief Exchanged modbus packages manager.
* This function manages data exchange between connected devices.
*/
void ModbusServerCycleRun(){

	if(!TimeOutElapsed(pModbusServer->CycleTick, TIMEOUT_MODBUS_SERVER_CYCLE))
		return;

	switch(pModbusServer->State){
		case MMS_INIT:						StartMaster();			break;
		case MMS_RECEIVE:					ReceiveMaster();		break;
		case MMS_RECEIVING:					ReceivingMaster();		break;
		case MMS_TRANSMIT:					TransmitMaster();		break;
		case MMS_TRANSMITTING:				TransmittingMaster();	break;
		case MMS_RST:						RstMaster();			break;
		case MMS_EXCEPTION: 				ExceptionMaster();		break;
		case MMS_ERR:						ErrorMaster();			break;
		default:													break;
	}

	pModbusServer->CycleTick = HAL_GetTick();
}

/**
* @brief Remote device connection controller
* This function checks if server finds new connection.
*/
void ModbusCycleServerDisconnected(){

	pModbusServer->State = MMS_INIT;

	if(pModbusServer->IsPhyConnected){
		if(!pModbusServer->IsPhyConnected()){
			pModbusServer->phyConnection = MP_DISCONNECTED;
		}
		else
			pModbusServer->phyConnection = MP_CONNECTED;
	}
	else{
		pModbusServer->phyConnection = MP_CONNECTED;
	}
}

/**
* @brief Remote device connection controller
* This function checks if a connected client looses its physical connection or not.
*/
void ModbusCycleServerConnected(){
	if(pModbusServer->IsPhyConnected){
		if(!pModbusServer->IsPhyConnected()){
			pModbusServer->State = MMS_INIT;
			pModbusServer->phyConnection = MP_DISCONNECTED;
		}
		else{
			ModbusServerCycleRun();
		}
	}
	else{
		ModbusServerCycleRun();
	}
}

/**
* @brief Modbus server cycle machine state entry point.
* This function is the entry point for modbus RTU and TCPIP server management.
*/
void ModbusServerCycle(){
	if(!pModbusServer)
		return;

	if(!pModbusServer->IsEnable()){
		pModbusServer->State = MMS_INIT;
		return;
	}

	switch(pModbusServer->phyConnection){
		case MP_DISCONNECTED: 	ModbusCycleServerDisconnected(); 	break;
		case MP_CONNECTED:	 	ModbusCycleServerConnected();		break;
	}
}
