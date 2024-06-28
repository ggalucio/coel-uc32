/*
 * modbusCommonTCPIP.c
 *
 *  Created on: 29 ott 2021
 *      Author: paoloc
 */

#include <Components/Modbus/TCPIP/modbusTCPIPLib.h>
#include "Utils/modbusUtils.h"
#include "stdlib.h"
#include "string.h"

/**
 * Modbus TCPIP protocol ID definition
 */
#define PROTOCOL_ID 0

/**
* @brief Pack modbus TCPIP header pakage
* This function packs modbus TCPIP header package
* @param pData: modbus package pointer
* @param transactionId: modbus TCPIP transaction ID
* @param protocolId: modbus TCPIP protocol ID
* @param nBytes: data bytes number
* @param unitId: modbus TCPIP unit ID
* @retval: modbus package length
*/
int PackTcpIpHeader(BYTE* pData, WORD transactionId, WORD protocolId, WORD nBytes, BYTE unitId){
	int i = 0;
	pData[i++] = ((transactionId >> BYTE_BIT_NUM) & BYTE_MASK) ;	// Transaction Identifier Hi
	pData[i++] = ((transactionId >> 0) & BYTE_MASK);				// Transaction Identifier Lo
	pData[i++] = ((protocolId >> BYTE_BIT_NUM) & BYTE_MASK) ;		// Protocol Identifier Hi
	pData[i++] = ((protocolId >> 0) & BYTE_MASK);					// Protocol Identifier Lo
	pData[i++] = ((nBytes >> BYTE_BIT_NUM) & BYTE_MASK) ;			// Bytes number Hi
	pData[i++] = ((nBytes >> 0) & BYTE_MASK);						// Bytes number Lo
	pData[i++] = unitId;											// Unit Identifier
	return i;
}

/**
* @brief Pack modbus TCPIP request
* This function packs modbus TCPIP multiple read request
* @param pData: modbus package pointer
* @param transactionId: modbus TCPIP transaction ID
* @param protocolId: modbus TCPIP protocol ID
* @param unitId: modbus TCPIP unit ID
* @param startAddress: start register address
* @param length: registers number to read
* @retval: modbus package length
*/
int PackModbusTcpIpMultipleRead(BYTE* pData, WORD transactionId, WORD protocolId, BYTE unitId, WORD startAddress, WORD length)
{
	int i = PackTcpIpHeader(pData, transactionId, protocolId, 6, unitId);	// Impacchettamento Header
	pData[i++] = MODBUS_CODE_READ_HOLDING_REG;								// Function Code
	pData[i++] = ((startAddress >> BYTE_BIT_NUM) & BYTE_MASK) ;				// Starting address Hi
	pData[i++] = ((startAddress >> 0) & BYTE_MASK);							// Starting address Lo
	pData[i++] = ((length >> BYTE_BIT_NUM) & BYTE_MASK) ;					// Quantity of Registers Hi
	pData[i++] = ((length >> 0) & BYTE_MASK);								// Quantity of Registers Lo
	return i;
}

/**
* @brief Pack modbus TCPIP request
* This function packs modbus TCPIP single write request
* @param pData: modbus package pointer
* @param transactionId: modbus TCPIP transaction ID
* @param protocolId: modbus TCPIP protocol ID
* @param unitId: modbus TCPIP unit ID
* @param startAddress: start register address
* @param value: new register value pointer
* @retval: modbus package length
*/
int PackModbusTcpIpSingleWrite(BYTE* pData, WORD transactionId, WORD protocolId, BYTE unitId, WORD startAddress, WORD *value){
	int i = PackTcpIpHeader(pData, transactionId, protocolId, 6, unitId);	// Impacchettamento Header
	pData[i++] = MODBUS_CODE_SINGLE_WRITE;									// Function Code
	pData[i++] = ((startAddress >> BYTE_BIT_NUM) & BYTE_MASK) ;				// Starting address Hi
	pData[i++] = ((startAddress >> 0) & BYTE_MASK);							// Starting address Lo
	pData[i++] = (((*value) >> BYTE_BIT_NUM) & BYTE_MASK) ;					// Data Hi
	pData[i++] = (((*value) >> 0) & BYTE_MASK);								// Data Lo
	return i;
}

/**
* @brief Pack modbus TCPIP request
* This function packs modbus TCPIP multiple write request
* @param pData: modbus package pointer
* @param transactionId: modbus TCPIP transaction ID
* @param protocolId: modbus TCPIP protocol ID
* @param unitId: modbus TCPIP unit ID
* @param startAddress: start register address
* @param value: new registers values pointer
* @param length: registers number to write
* @retval: modbus package length
*/
int PackModbusTcpIpMultipleWrite(BYTE* pData, WORD transactionId, WORD protocolId, BYTE unitId, WORD startAddress, WORD *value, int length){
	int i = PackTcpIpHeader(pData, transactionId, protocolId,
			MODBUS_TCPIP_MULT_WRITE_PACK_SIZE(length), unitId);				// Impacchettamento Header
	pData[i++] = MODBUS_CODE_MULTIPLE_WRITE;								// Function Code
	pData[i++] = ((startAddress >> BYTE_BIT_NUM) & BYTE_MASK) ;				// Starting address Hi
	pData[i++] = ((startAddress >> 0) & BYTE_MASK);							// Starting address Lo
	pData[i++] = ((length >> BYTE_BIT_NUM) & BYTE_MASK) ;					// Quantity of Registers Hi
	pData[i++] = ((length >> 0) & BYTE_MASK);								// Quantity of Registers Lo

	pData[i++] = length * 2;												// The number of data bytes to follow

	int ii;
	for( ii = 0; ii < length; ii++){
		pData[i++] = (((value[ii]) >> BYTE_BIT_NUM) & BYTE_MASK) ;			// Data Hi
		pData[i++] = (((value[ii]) >> 0) & BYTE_MASK);						// Data Lo
	}

	return i;
}

/**
* @brief Pack modbus TCPIP exception package
* This function packs exception package to send back
* @param pData: modbus package pointer
* @param id: modbus slave address
* @param code: modbus function code
* @param exception: exception code
* @retval: modbus package length
*/
int PackTCPIPExceptions(BYTE* pData, BYTE id, BYTE code, BYTE exception){

	// TO DO
	return 0;
}

/**
* @brief Unpack modbus TCPIP package
* This function unpacks modbus TCPIP multiple read package
* @param pData: modbus package to unpack
* @param len: modbus package length
* @param modbusInfo: modbus package information getting from request
* @retval: exception code.
*/
int UnpackModbusTCPIPMultipleRead(BYTE* pData, BYTE len, ModbusInfo* pModbusInfo){
	if(pData[MODBUS_TCPIP_FUNCODE_RESP_POS] != MODBUS_CODE_READ_HOLDING_REG)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	if(len != MODBUS_TCPIP_MULT_READ_PACK_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	pModbusInfo->UnitId			= pData[MODBUS_TCPIP_UNITID_RESP_POS];
	pModbusInfo->TransactionId 	= (pData[MODBUS_TCPIP_TRANSID_POS_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_TRANSID_POS_L];
	pModbusInfo->ProtocolId		= (pData[MODBUS_TCPIP_PROTOCOLID_POS_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_PROTOCOLID_POS_L];
	pModbusInfo->Address 		= (pData[MODBUS_TCPIP_MULTIPLE_READ_ADDRESS_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_MULTIPLE_READ_ADDRESS_L];
	pModbusInfo->RegisterNum	= (pData[MODBUS_TCPIP_MULTIPLE_READ_REG_NUM_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_MULTIPLE_READ_REG_NUM_L];

	if(pModbusInfo->Address > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	if((pModbusInfo->Address) + (pModbusInfo->RegisterNum) > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_ADDRESS;

	return MODBUS_CODE_NO_EXCEPTIONS;
}

/**
* @brief Unpack modbus TCPIP package
* This function unpacks modbus TCPIP single write package
* @param pData: modbus package to unpack
* @param len: modbus package length
* @param modbusInfo: modbus package information getting from request
* @retval: exception code.
*/
int UnpackModbusTCPIPSingleWrite(BYTE* pData, BYTE len, ModbusInfo *pModbusInfo){
	if(pData[MODBUS_TCPIP_FUNCODE_RESP_POS] != MODBUS_CODE_SINGLE_WRITE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	if(len != (MODBUS_TCPIP_SINGLE_WRITE_PACK_SIZE *2 ))
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	pModbusInfo->UnitId			= pData[MODBUS_TCPIP_UNITID_RESP_POS];
	pModbusInfo->TransactionId 	= (pData[MODBUS_TCPIP_TRANSID_POS_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_TRANSID_POS_L];
	pModbusInfo->ProtocolId		= (pData[MODBUS_TCPIP_PROTOCOLID_POS_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_PROTOCOLID_POS_L];
	pModbusInfo->Address 		= (pData[MODBUS_TCPIP_SINGLE_WRITE_ADDRESS_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_SINGLE_WRITE_ADDRESS_L];
	pModbusInfo->Register 		= (pData[MODBUS_TCPIP_SINGLE_WRITE_REG_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_SINGLE_WRITE_REG_L];
	pModbusInfo->RegisterNum	= 1;

	if(pModbusInfo->Address > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	if((pModbusInfo->Address) + (pModbusInfo->RegisterNum) > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_ADDRESS;

	return MODBUS_CODE_NO_EXCEPTIONS;
}

/**
* @brief Unpack modbus TCPIP package
* This function unpacks modbus TCPIP multiple write package
* @param pData: modbus package to unpack
* @param len: modbus package length
* @param registers: registers values pointer
* @param modbusInfo: modbus package information getting from request
* @retval: exception code.
*/
int UnpackModbusTCPIPMultipleWrite(BYTE* pData, BYTE len, WORD** registers, ModbusInfo *pModbusInfo){
	if(!pModbusInfo)
		return 0;

	BYTE test[len];
	memcpy(test, pData, sizeof(BYTE) * len);

	BYTE fCode = pData[MODBUS_TCPIP_FUNCODE_RESP_POS];
	if( fCode != MODBUS_CODE_MULTIPLE_WRITE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	pModbusInfo->UnitId			= pData[MODBUS_TCPIP_UNITID_RESP_POS];
	pModbusInfo->TransactionId 	= (pData[MODBUS_TCPIP_TRANSID_POS_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_TRANSID_POS_L];
	pModbusInfo->ProtocolId		= (pData[MODBUS_TCPIP_PROTOCOLID_POS_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_PROTOCOLID_POS_L];
	pModbusInfo->Address		= (pData[MODBUS_TCPIP_MULTIPLE_WRITE_ADDRESS_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_MULTIPLE_WRITE_ADDRESS_L];
	pModbusInfo->RegisterNum	= (pData[MODBUS_TCPIP_MULTIPLE_WRITE_REG_NUM_H] << BYTE_BIT_NUM) | pData[MODBUS_TCPIP_MULTIPLE_WRITE_REG_NUM_L];
	*registers 					= (WORD*)malloc(sizeof(WORD) * (pModbusInfo->RegisterNum));

	if(pModbusInfo->Address > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	if((pModbusInfo->Address) + (pModbusInfo->RegisterNum) > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_ADDRESS;

	DWORD valuesIdx	= MODBUS_TCPIP_MULTIPLE_WRITE_START_VAL;
	WORD* pRegisters = *registers;
	int i;
	for(i = 0; i < pModbusInfo->RegisterNum; i++){
		BYTE valH = pData[valuesIdx++];
		BYTE valL = pData[valuesIdx++];
		*pRegisters++ = ((valH << BYTE_BIT_NUM) | valL);
	}

	return MODBUS_CODE_NO_EXCEPTIONS;
}

/**
* @brief Pack modbus TCPIP response
* This function packs modbus TCPIP multiple read response
* @param slaveAddress:	slave address
* @param pData: modbus package pointer
* @param registers: registers values pointer
* @param modbusInfo: modbus package information getting from request
* @retval: modbus package length
*/
int PackModbusTCPIPMultipleReadResponse(BYTE slaveAddress, BYTE* pData, WORD* registers, ModbusInfo modbusInfo){
	int i = PackTcpIpHeader(pData, modbusInfo.TransactionId,modbusInfo.ProtocolId,
			MODBUS_TCPIP_MULT_READ_RESP_SIZE(modbusInfo.RegisterNum), modbusInfo.UnitId);	// Impacchettamento Header
	pData[i++] 	= MODBUS_CODE_READ_HOLDING_REG;												// Codice funzione
	pData[i++] 	= (modbusInfo.RegisterNum) * BYTES_IN_WORD;									// Contatore bytes

	int iVal = 0;
	for(iVal = 0; iVal < modbusInfo.RegisterNum; iVal++){
		pData[i++] 	= (registers[iVal] >> BYTE_BIT_NUM) & BYTE_MASK;						// Valore (parte alta)
		pData[i++] 	= (registers[iVal] >> 0) 			& BYTE_MASK;						// Valore (parte bassa)
	}

	return i;
}

/**
* @brief Pack modbus TCPIP response
* This function packs modbus TCPIP single write response
* @param slaveAddress:	slave address
* @param pData: modbus package pointer
* @param modbusInfo: modbus package information getting from request
* @retval: modbus package length
*/
int PackModbusTCPIPSingleWriteResponse(BYTE slaveAddress, BYTE* pData, ModbusInfo modbusInfo){
	int i = PackTcpIpHeader(pData, modbusInfo.TransactionId,modbusInfo.ProtocolId,
			MODBUS_TCPIP_SINGLE_WRITE_PACK_SIZE, modbusInfo.UnitId);	// Impacchettamento Header
	pData[i++] 	= MODBUS_CODE_SINGLE_WRITE;								// Codice funzione
	pData[i++] 	= (modbusInfo.Address >> BYTE_BIT_NUM) & BYTE_MASK;		// Indirizzo (parte alta)
	pData[i++] 	= (modbusInfo.Address >> 0) 			& BYTE_MASK;	// Indirizzo (parte bassa)
	pData[i++] 	= (modbusInfo.Register >> BYTE_BIT_NUM) & BYTE_MASK;	// Valore (parte alta)
	pData[i++] 	= (modbusInfo.Register >> 0) 			& BYTE_MASK;	// Valore (parte bassa)
	return i;
}

/**
* @brief Pack modbus TCPIP response
* This function packs modbus TCPIP multiple write response
* @param slaveAddress:	slave address
* @param pData: modbus package pointer
* @param modbusInfo: modbus package information getting from request
* @retval: modbus package length
*/
int PackModbusTCPIPMultipleWriteResponse(BYTE slaveAddress, BYTE* pData, ModbusInfo modbusInfo){
	int i = PackTcpIpHeader(pData, modbusInfo.TransactionId,modbusInfo.ProtocolId,
				MODBUS_TCPIP_MULT_WRITE_RESP_SIZE, modbusInfo.UnitId);		// Impacchettamento Header
	pData[i++] 	= MODBUS_CODE_MULTIPLE_WRITE;								// Codice funzione
	pData[i++] 	= (modbusInfo.Address 	  >> BYTE_BIT_NUM)  & BYTE_MASK;	// Indirizzo (parte alta)
	pData[i++] 	= (modbusInfo.Address 	  >> 0) 			& BYTE_MASK;	// Indirizzo (parte bassa)
	pData[i++] 	= (modbusInfo.RegisterNum >> BYTE_BIT_NUM)  & BYTE_MASK;	// Valore (parte alta)
	pData[i++] 	= (modbusInfo.RegisterNum >> 0) 			& BYTE_MASK;	// Valore (parte bassa)
	return i;
}

/**
* @brief Pack modbus TCPIP request
* This function packs modbus TCPIP package
* @param data: modbus package pointer
* @param size: modbus package length
* @param id: modbus slave address
* @param code: modbus function code
* @param modbusInfo: modbus package information.
* @param length: modbus registers number.
* @param value: data to write. If it's a read request, this parameter is NULL.
* @retval: 1 if modbus package has been done, 0 otherwise.
*/
BOOLEAN PackTcpIpRequest(BYTE **data, int* size, int id, int code, ModbusInfo modbusInfo, int length, WORD* value){
	BOOLEAN res = AT_FALSE;

	if(code == MODBUS_CODE_READ_HOLDING_REG || code == MODBUS_CODE_READ_INPUT_REG){
		*data = (BYTE*)malloc(sizeof(BYTE) * MODBUSTCPIP_MULTIPLE_READ_PACK_SIZE);
		(*size) = PackModbusTcpIpMultipleRead(*data, modbusInfo.TransactionId, PROTOCOL_ID, id, modbusInfo.Address, length);
		res = AT_TRUE;
	}

	if(code == MODBUS_CODE_SINGLE_WRITE){
		*data = (BYTE*)malloc(sizeof(BYTE) * MODBUS_SINGLE_WRITE_PACK_SIZE);
		(*size) = PackModbusTcpIpSingleWrite(*data, modbusInfo.TransactionId, PROTOCOL_ID, id, modbusInfo.Address, value);
		res = AT_TRUE;
	}

	if(code == MODBUS_CODE_MULTIPLE_WRITE){
		*data = (BYTE*)malloc(sizeof(BYTE) * MODBUS_MULTIPLE_WRITE_PACK_SIZE(length));
		(*size) = PackModbusTcpIpMultipleWrite(*data, modbusInfo.TransactionId, PROTOCOL_ID, id, modbusInfo.Address, value, length);
		res = AT_TRUE;
	}

	return res;
}

/**
* @brief Modbus TCPIP response package validator
* This function checks if function code is valid or not
* @param data: modbus package pointer
* @param len: modbus package length
* @retval: 1 if modbus package is valid, 0 otherwise.
*/
BOOLEAN IsTCPIPFunctionCodeValid(BYTE* data, BYTE len){

	if(len < MODBUS_TCPIP_FUNCODE_RESP_POS || !data)
		return AT_FALSE;

	BYTE code = data[MODBUS_TCPIP_FUNCODE_RESP_POS];
	return code == MODBUS_CODE_SINGLE_WRITE || code == MODBUS_CODE_MULTIPLE_WRITE || code == MODBUS_CODE_READ_HOLDING_REG;
}

/**
* @brief Modbus TCPIP response package validator
* This function checks if server package response is valid or not
* @param pData: modbus package pointer
* @param len: modbus package length
* @param slaveAddrTaret: modbus slave address
* @param funcCodeTarget: modbus function code
* @retval: 1 if modbus package is valid, 0 otherwise.
*/
BOOLEAN RespTcpipIsValid(BYTE* pData, BYTE len, BYTE slaveAddrTaret,  BYTE funcCodeTarget){
	if(!pData || len < MODBUS_TCPIP_FUNCODE_RESP_POS)
		return AT_FALSE;

	return pData[MODBUS_TCPIP_UNITID_RESP_POS] == slaveAddrTaret &&
			pData[MODBUS_TCPIP_FUNCODE_RESP_POS] == funcCodeTarget;
}

/**
* @brief Modbus TCPIP response package validator
* This function checks if server package response is valid or not
* @param pData: modbus package pointer
* @param len: modbus package length
* @retval: 1 if modbus package is valid, 0 otherwise.
*/
BOOLEAN IsTCPIPFrameValid(BYTE* pData, BYTE len){
	if(!pData)
		return AT_FALSE;

	return AT_TRUE;
}
