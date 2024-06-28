/*
 * modbus.c
 *
 *  Created on: 22 feb 2021
 *      Author: paoloc
 */

#include <Components/Modbus/Serial/modbusSerialLib.h>
#include "stdlib.h"

//#define MIN_PACKAGE_SIZE 	5
#define NBYTES_IDX 			2
//#define START_DATA_IDX 		3
//#define BYTES_IN_WORD		2
#define BYTE_OFFSET			8
/*
#define GET_READ_VALUE()																								\
	int i, w;																											\
	int nWords = nBytes / BYTES_IN_WORD;																				\
	for( w = 0; w < nWords; w++){																						\
		WORD val = 0;																									\
		for(i = 0; i < BYTES_IN_WORD; i++){																				\
			val |= (data[START_DATA_IDX + offset + i + BYTES_IN_WORD * w] << (BYTE_OFFSET * (BYTES_IN_WORD - i - 1)));	\
		}																												\
		value |= (val << w * BYTE_OFFSET * BYTES_IN_WORD);																\
	}																													\
*/

/**
* @brief Pack modbus RTU request
* This function packs modbus RTU multiple read request
* @param slaveAddress:	slave address
* @param startAddress: start register address
* @param addressNum: registers number
* @param pData: modbus package pointer
* @retval: modbus package length
*/
int PackModbusMultipleRead(BYTE slaveAddress, WORD startAddress, WORD addressNum, BYTE* pData)
{
	int i = 0;
	pData[i++] 	= slaveAddress;							// Indirizzo SLAVE
	pData[i++] 	= MODBUS_CODE_READ_HOLDING_REG;			// Codice funzione
	pData[i++] 	= (startAddress >> 8) & BYTE_MASK;		// Indirizzo (parte alta)
	pData[i++] 	= (startAddress >> 0) & BYTE_MASK;		// Indirizzo (parte bassa)
	pData[i++] 	= (addressNum >> 8) & BYTE_MASK;		// Numero indirizzi richiesti (parte alta)
	pData[i++] 	= (addressNum >> 0) & BYTE_MASK;		// Numero indirizzi richiesti (parte alta)
	DWORD crc 	= crc_16(pData, i);						// Checksum
	pData[i++] 	= ( crc >> 0 ) & BYTE_MASK;
	pData[i++] 	= ( crc >> 8 ) & BYTE_MASK;
	return i;
}

/**
* @brief Pack modbus RTU request
* This function packs modbus RTU single write request
* @param slaveAddress:	slave address
* @param address: start register address
* @param pData: modbus package pointer
* @param value: register new value
* @retval: modbus package length
*/
int PackModbusSingleWrite(BYTE slaveAddress, WORD address, BYTE* pData, WORD value){
	int i = 0;
	pData[i++] 	= slaveAddress;							// Indirizzo SLAVE
	pData[i++] 	= MODBUS_CODE_SINGLE_WRITE;				// Codice funzione
	pData[i++] 	= (address >> 8) 		& BYTE_MASK;	// Indirizzo (parte alta)
	pData[i++] 	= (address >> 0) 		& BYTE_MASK;	// Indirizzo (parte bassa)
	pData[i++] 	= (value >> 8) 			& BYTE_MASK;	// Indirizzo (parte alta)
	pData[i++] 	= (value >> 0) 			& BYTE_MASK;	// Indirizzo (parte bassa)
	DWORD crc 	= crc_16(pData, i);						// Checksum
	pData[i++] 	= ( crc >> 0 ) & BYTE_MASK;
	pData[i++] 	= ( crc >> 8 ) & BYTE_MASK;
	return i;
}

/**
* @brief Pack modbus RTU request
* This function packs modbus RTU multiple write request
* @param slaveAddress:	slave address
* @param address: start register address
* @param pData: modbus package pointer
* @param registers: registers new values pointer
* @param registersNum: registers number to write
* @retval: modbus package length
*/
int PackModbusMultipleWrite(BYTE slaveAddress, WORD address, BYTE* pData, WORD* registers, BYTE registersNum){
	int i = 0;
	pData[i++] 	= slaveAddress;											// Indirizzo SLAVE
	pData[i++] 	= MODBUS_CODE_MULTIPLE_WRITE;							// Codice funzione
	pData[i++] 	= (address >> BYTE_BIT_NUM) 			& BYTE_MASK;	// Indirizzo (parte alta)
	pData[i++] 	= (address >> 0) 						& BYTE_MASK;	// Indirizzo (parte bassa)
	pData[i++] 	= (registersNum >> BYTE_BIT_NUM) 		& BYTE_MASK;	// Lunghezza (parte alta)
	pData[i++] 	= (registersNum >> 0) 					& BYTE_MASK;	// Lunghezza (parte bassa)
	pData[i++] 	= registersNum * 2;										// Contatore bytes

	int iVal = 0;
	for(iVal = 0; iVal < registersNum; iVal++){
		pData[i++] 	= (registers[iVal] >> BYTE_BIT_NUM) & BYTE_MASK;	// Valore (parte alta)
		pData[i++] 	= (registers[iVal] >> 0) 			& BYTE_MASK;	// Valore (parte bassa)
	}

	DWORD crc 	= crc_16(pData, i);										// Checksum
	pData[i++] 	= ( crc >> 0 ) & BYTE_MASK;								// Checksum (parte bassa)
	pData[i++] 	= ( crc >> BYTE_BIT_NUM ) & BYTE_MASK;					// Checksum (parte alta)
	return i;
}

/**
* @brief Pack modbus RTU response
* This function packs modbus RTU multiple write response
* @param slaveAddress:	slave address
* @param pData: modbus package pointer
* @param modbusInfo: modbus package information getting from request
* @retval: modbus package length
*/
int PackModbusSerialMultipleWriteResponse(BYTE slaveAddress, BYTE* pData, ModbusInfo modbusInfo){
	int i = 0;
	pData[i++] 	= slaveAddress;												// Indirizzo SLAVE
	pData[i++] 	= MODBUS_CODE_MULTIPLE_WRITE;								// Codice funzione
	pData[i++] 	= (modbusInfo.Address     >> BYTE_BIT_NUM) & BYTE_MASK;		// Indirizzo (parte alta)
	pData[i++] 	= (modbusInfo.Address     >> 0) 			& BYTE_MASK;	// Indirizzo (parte bassa)
	pData[i++] 	= (modbusInfo.RegisterNum >> BYTE_BIT_NUM) 	& BYTE_MASK;	// Numero registri (parte alta)
	pData[i++] 	= (modbusInfo.RegisterNum >> 0) 			& BYTE_MASK;	// Numero registri (parte bassa)
	DWORD crc 	= crc_16(pData, i);											// Checksum
	pData[i++] 	= ( crc >> 0 ) & BYTE_MASK;									// Checksum (parte bassa)
	pData[i++] 	= ( crc >> BYTE_BIT_NUM ) & BYTE_MASK;						// Checksum (parte alta)
	return i;
}

/**
* @brief Pack modbus RTU response
* This function packs modbus RTU single write response
* @param slaveAddress:	slave address
* @param pData: modbus package pointer
* @param modbusInfo: modbus package information getting from request
* @retval: modbus package length
*/
int PackModbusSerialSingleWriteResponse(BYTE slaveAddress, BYTE* pData, ModbusInfo modbusInfo){
	int i = 0;
	pData[i++] 	= slaveAddress;											// Indirizzo SLAVE
	pData[i++] 	= MODBUS_CODE_SINGLE_WRITE;								// Codice funzione
	pData[i++] 	= (modbusInfo.Address >> BYTE_BIT_NUM) & BYTE_MASK;		// Indirizzo (parte alta)
	pData[i++] 	= (modbusInfo.Address >> 0) 			& BYTE_MASK;	// Indirizzo (parte bassa)
	pData[i++] 	= (modbusInfo.Register >> BYTE_BIT_NUM) & BYTE_MASK;	// Valore (parte alta)
	pData[i++] 	= (modbusInfo.Register >> 0) 			& BYTE_MASK;	// Valore (parte bassa)
	DWORD crc 	= crc_16(pData, i);										// Checksum
	pData[i++] 	= ( crc >> 0 ) & BYTE_MASK;								// Checksum (parte bassa)
	pData[i++] 	= ( crc >> BYTE_BIT_NUM ) & BYTE_MASK;					// Checksum (parte alta)
	return i;
}

/**
* @brief Pack modbus RTU response
* This function packs modbus RTU multiple read response
* @param slaveAddress:	slave address
* @param pData: modbus package pointer
* @param registers: registers values pointer
* @param modbusInfo: modbus package information getting from request
* @retval: modbus package length
*/
int PackModbusSerialMultipleReadResponse(BYTE slaveAddress, BYTE* pData, WORD* registers, ModbusInfo modbusInfo){
	int i = 0;
	pData[i++] 	= slaveAddress;											// Indirizzo SLAVE
	pData[i++] 	= MODBUS_CODE_READ_HOLDING_REG;							// Codice funzione
	pData[i++] 	= (modbusInfo.RegisterNum) * BYTES_IN_WORD;				// Contatore bytes

	int iVal = 0;
	for(iVal = 0; iVal < modbusInfo.RegisterNum; iVal++){
		pData[i++] 	= (registers[iVal] >> BYTE_BIT_NUM) & BYTE_MASK;	// Valore (parte alta)
		pData[i++] 	= (registers[iVal] >> 0) 			& BYTE_MASK;	// Valore (parte bassa)
	}

	DWORD crc 	= crc_16(pData, i);										// Checksum
	pData[i++] 	= ( crc >> 0 ) & BYTE_MASK;								// Checksum (parte bassa)
	pData[i++] 	= ( crc >> BYTE_BIT_NUM ) & BYTE_MASK;					// Checksum (parte alta)
	return i;
}

/**
* @brief Unpack modbus RTU package
* This function unpacks modbus RTU multiple write package
* @param pData: modbus package to unpack
* @param len: modbus package length
* @param registers: registers values pointer
* @param modbusInfo: modbus package information getting from request
* @retval: exception code.
*/
int UnpackModbusSerialMultipleWrite(BYTE* pData, BYTE len, WORD** registers, ModbusInfo* pModbusInfo){

	if(!pModbusInfo)
		return 0;

	if(pData[FUNCTION_CODE_IDX] != MODBUS_CODE_MULTIPLE_WRITE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	pModbusInfo->Address		= (pData[MODBUS_RS485_MULTIPLE_WRITE_ADDRESS_H] << BYTE_BIT_NUM) | pData[MODBUS_RS485_MULTIPLE_WRITE_ADDRESS_L];
	pModbusInfo->RegisterNum	= (pData[MODBUS_RS485_MULTIPLE_WRITE_REG_NUM_H] << BYTE_BIT_NUM) | pData[MODBUS_RS485_MULTIPLE_WRITE_REG_NUM_L];
	*registers					= (WORD*)malloc(sizeof(WORD) * (pModbusInfo->RegisterNum));

	if(pModbusInfo->Address > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	if((pModbusInfo->Address) + (pModbusInfo->RegisterNum) > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_ADDRESS;

	DWORD valuesIdx	= MODBUS_RS485_MULTIPLE_WRITE_START_VAL;
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
* @brief Unpack modbus RTU package
* This function unpacks modbus RTU single write package
* @param pData: modbus package to unpack
* @param len: modbus package length
* @param modbusInfo: modbus package information getting from request
* @retval: exception code.
*/
int UnpackModbusSerialSingleWrite(BYTE* pData, BYTE len, ModbusInfo* pModbusInfo){

	if(!pModbusInfo)
		return 0;

	if(pData[FUNCTION_CODE_IDX] != MODBUS_CODE_SINGLE_WRITE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	if(len != MODBUS_SINGLE_WRITE_PACK_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	pModbusInfo->Address 		= (pData[MODBUS_RS485_SINGLE_WRITE_ADDRESS_H] << BYTE_BIT_NUM) | pData[MODBUS_RS485_SINGLE_WRITE_ADDRESS_L];
	pModbusInfo->Register		= (pData[MODBUS_RS485_SINGLE_WRITE_REG_H] << BYTE_BIT_NUM) | pData[MODBUS_RS485_SINGLE_WRITE_REG_L];
	pModbusInfo->RegisterNum	= 1;

	if(pModbusInfo->Address > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	return MODBUS_CODE_NO_EXCEPTIONS;
}

/**
* @brief Unpack modbus RTU package
* This function unpacks modbus RTU multiple read package
* @param pData: modbus package to unpack
* @param len: modbus package length
* @param modbusInfo: modbus package information getting from request
* @retval: exception code.
*/
int UnpackModbusSerialMultipleRead(BYTE* pData, BYTE len, ModbusInfo *modbusInfo)
{
	if(pData[FUNCTION_CODE_IDX] != MODBUS_CODE_READ_HOLDING_REG)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	if(len != MODBUS_MULTIPLE_READ_PACK_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	modbusInfo->Address		= (pData[MODBUS_MULTIPLE_READ_ADDRESS_H] << BYTE_BIT_NUM) | pData[MODBUS_MULTIPLE_READ_ADDRESS_L];
	modbusInfo->RegisterNum = (pData[MODBUS_MULTIPLE_READ_REG_NUM_H] << BYTE_BIT_NUM) | pData[MODBUS_MULTIPLE_READ_REG_NUM_L];

	if(modbusInfo->Address	 > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_VALUE;

	if((modbusInfo->Address) + (modbusInfo->RegisterNum) > MODBUS_REG_SIZE)
		return MODBUS_CODE_ILLEGAL_DATA_ADDRESS;

	return MODBUS_CODE_NO_EXCEPTIONS;
}

/**
* @brief Modbus RTU checksum
* This function calculates 16 bit checksum value processing an input byte array
* @param buffer: data to check
* @param length: data package length
* @retval: checksum 16 value.
*/
DWORD crc_16 (BYTE *buffer, DWORD length)
{
	DWORD i, j, temp_bit, temp_int, crc;
	crc = 0xFFFF;
	for ( i = 0; i < length; i++ ) {
			temp_int = (BYTE) *buffer++;
			crc ^= temp_int;
			for ( j = 0; j < 8; j++ ) {
				temp_bit = crc & 0x0001;
				crc >>= 1;
				if ( temp_bit != 0 )
					crc ^= 0xA001;
			}
	}
	return (crc);
}

/**
* @brief Modbus RTU checksum
* This function calculates 16 bit checksum value processing an input byte array
* and compares it with the checksum stored in input array.
* @param pData: data to check
* @param len: data package length
* @retval: 1 if checksums are equals, 0 otherwise
*/
BOOLEAN RunChecksum(BYTE* pData, int len){
	DWORD crc = crc_16(pData, len - 2);
	BYTE bl = pData[len - 2];
	BYTE bh = pData[len - 1];
	DWORD cs = (bh << 8) | bl;
	return cs == crc ? AT_TRUE : AT_FALSE;
}
/*
DWORD ReadData(BYTE* data, int buffLen, int offset, int nBytes){
	if(buffLen < MIN_PACKAGE_SIZE)
		return 0;

	DWORD value = 0;
	GET_READ_VALUE();
	return value;
}
*/

/**
* @brief Pack modbus RTU request
* This function packs modbus RTU package
* @param data: modbus package pointer
* @param size: modbus package length
* @param id: modbus slave address
* @param code: modbus function code
* @param modbusInfo: modbus package information.
* @param length: modbus registers number.
* @param value: data to write. If it's a read request, this parameter is NULL.
* @retval: 1 if modbus package has been done, 0 otherwise.
*/
BOOLEAN PackRequest(BYTE **data, int* size, int id, int code, ModbusInfo modbusInfo, int length, WORD* value){
	BOOLEAN res = AT_FALSE;

	if(code == MODBUS_CODE_READ_HOLDING_REG || code == MODBUS_CODE_READ_INPUT_REG){
		*data = (BYTE*)malloc(sizeof(BYTE) * MODBUS_MULTIPLE_READ_PACK_SIZE);
		(*size) = PackModbusMultipleRead(id, modbusInfo.Address, length, *data);
		res = AT_TRUE;
	}

	if(code == MODBUS_CODE_SINGLE_WRITE){
		*data = (BYTE*)malloc(sizeof(BYTE) * MODBUS_SINGLE_WRITE_PACK_SIZE);
		(*size) = PackModbusSingleWrite(id, modbusInfo.Address, *data, *value);
		res = AT_TRUE;
	}

	if(code == MODBUS_CODE_MULTIPLE_WRITE){
		*data = (BYTE*)malloc(sizeof(BYTE) * MODBUS_MULTIPLE_WRITE_PACK_SIZE(length));
		(*size) = PackModbusMultipleWrite(id, modbusInfo.Address, *data, value, length);
		res = AT_TRUE;
	}

	return res;
}

/**
* @brief Modbus RTU response package validator
* This function checks if server package response is valid or not
* @param pData: modbus package pointer
* @param len: modbus package length
* @param id: modbus slave address
* @param code: modbus function code
* @retval: 1 if modbus package is valid, 0 otherwise.
*/
BOOLEAN ApplyValidationCheck(BYTE* pData, BYTE len, BYTE id, BYTE code){

	if(pData == NULL || len < 2)
		return AT_FALSE;

	BOOLEAN checkSumRes = RunChecksum(pData, len);

	if(!checkSumRes)
		return AT_FALSE;

	return id == pData[SLAVE_ADDRESS_IDX] && code == pData[FUNCTION_CODE_IDX];
}

/**
* @brief Pack modbus RTU exception package
* This function packs exception package to send back
* @param pData: modbus package pointer
* @param id: modbus slave address
* @param code: modbus function code
* @param exception: exception code
* @retval: modbus package length
*/
int PackSerialExceptions(BYTE* pData, BYTE id, BYTE code, BYTE exception){
	int i = 0;
	pData[i++]  = id;									// Slave address
	pData[i++]  = code + MODBUS_EXCEPTION_CODE_OFFSET;	// Request function code + 0x80
	pData[i++]  = exception;							// Exception code
	DWORD crc 	= crc_16(pData, i);						// Checksum
	pData[i++] 	= ( crc >> 0 ) & BYTE_MASK;				// Checksum (parte bassa)
	pData[i++] 	= ( crc >> BYTE_BIT_NUM ) & BYTE_MASK;	// Checksum (parte alta)
	return i;
}

/**
* @brief Modbus RTU response package validator
* This function checks if function code is valid or not
* @param data: modbus package pointer
* @param len: modbus package length
* @retval: 1 if modbus package is valid, 0 otherwise.
*/
BOOLEAN IsSerialFunctionCodeValid(BYTE* data, BYTE len){

	if(len < FUNCTION_CODE_IDX || !data)
		return AT_FALSE;

	BYTE code = data[FUNCTION_CODE_IDX];
	return code == MODBUS_CODE_SINGLE_WRITE || code == MODBUS_CODE_MULTIPLE_WRITE || code == MODBUS_CODE_READ_HOLDING_REG;
}

/**
* @brief Modbus RTU response package validator
* This function checks if server package response is valid or not
* @param data: modbus package pointer
* @param len: modbus package length
* @retval: 1 if modbus package is valid, 0 otherwise.
*/
BOOLEAN IsSerialFrameValid(BYTE* data, BYTE len){

	if(len < FUNCTION_CODE_IDX || !data)
			return AT_FALSE;

	return ApplyValidationCheck(data, len, 1, data[FUNCTION_CODE_IDX]);
}
