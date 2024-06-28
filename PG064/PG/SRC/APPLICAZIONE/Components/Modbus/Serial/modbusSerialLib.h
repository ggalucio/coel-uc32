/*
 * modbus.h
 *
 *  Created on: 22 feb 2021
 *      Author: paoloc
 */

#ifndef MODBUSCLIENT_H_
#define MODBUSCLIENT_H_

#include "main.h"
#include "../modbusCommon.h"
#include "Utils/utils.h"
#include "Utils/modbusUtils.h"
#include "Utils/integer.h"

#define SLAVE_ADDRESS_IDX 				0
#define FUNCTION_CODE_IDX 				1
#define START_SERIAL_DATA_RESP_IDX 		3

int PackModbusMultipleRead(BYTE slaveAddress, WORD startAddress, WORD addressNum, BYTE* pData);
int PackModbusSingleWrite(BYTE slaveAddress, WORD address, BYTE* pData, WORD value);
int PackModbusMultipleWrite(BYTE slaveAddress, WORD address, BYTE* pData, WORD* value, BYTE length);
int PackModbusSerialMultipleReadResponse(BYTE slaveAddress, BYTE* pData, WORD* registers, ModbusInfo modbusInfo);
int PackModbusSerialSingleWriteResponse(BYTE slaveAddress, BYTE* pData, ModbusInfo);
int PackModbusSerialMultipleWriteResponse(BYTE slaveAddress, BYTE* pData, ModbusInfo);
int PackSerialExceptions(BYTE* pData, BYTE id, BYTE code, BYTE exception);
int UnpackModbusSerialMultipleRead(BYTE* pData, BYTE len, ModbusInfo *modbusInfo);
int UnpackModbusSerialSingleWrite(BYTE* pData, BYTE len, ModbusInfo*);
int UnpackModbusSerialMultipleWrite(BYTE* pData, BYTE len, WORD**, ModbusInfo*);
DWORD crc_16 (BYTE *buffer, DWORD length);
BOOLEAN RunChecksum(BYTE* pData, int len);
//DWORD ReadData(BYTE* data, int buffLen, int offset, int nBytes);
BOOLEAN PackRequest2(BYTE **data, int* size, int id, int code, DWORD address, int length, WORD* value);
BOOLEAN PackRequest(BYTE **data, int* size, int id, int code, ModbusInfo modbusInfo, int length, WORD* value);
BOOLEAN ApplyValidationCheck(BYTE* data, BYTE len, BYTE id, BYTE code);
BOOLEAN IsSerialFunctionCodeValid(BYTE* data, BYTE len);
BOOLEAN IsSerialFrameValid(BYTE* data, BYTE len);


#endif /* MODBUSCLIENT_H_ */
