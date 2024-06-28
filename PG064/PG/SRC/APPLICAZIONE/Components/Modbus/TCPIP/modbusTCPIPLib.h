/*
 * modbusCommonTCIPI.h
 *
 *  Created on: 29 ott 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_TCPIP_MODBUSTCPIPLIB_H_
#define COMPONENTS_MODBUS_TCPIP_MODBUSTCPIPLIB_H_

#include "Utils/integer.h"
#include "Utils/utils.h"
#include "Utils/modbusUtils.h"

#define START_TCPIP_DATA_RESP_IDX 		9

int PackTCPIPExceptions(BYTE* pData, BYTE id, BYTE code, BYTE exception);
int UnpackModbusTCPIPMultipleRead(BYTE* pData, BYTE len,  ModbusInfo* modbusInfo);
int UnpackModbusTCPIPSingleWrite(BYTE* pData, BYTE len, ModbusInfo*);
int UnpackModbusTCPIPMultipleWrite(BYTE* pData, BYTE len, WORD** registers, ModbusInfo*);
int PackModbusTCPIPMultipleReadResponse(BYTE slaveAddress, BYTE* pData, WORD* registers, ModbusInfo modbusInfo);
int PackModbusTCPIPSingleWriteResponse(BYTE slaveAddress, BYTE* pData, ModbusInfo);
int PackModbusTCPIPMultipleWriteResponse(BYTE slaveAddress, BYTE* pData, ModbusInfo);
BOOLEAN PackTcpIpRequest(BYTE **data, int* size, int id, int code, ModbusInfo, int length, WORD* value);
BOOLEAN RespTcpipIsValid(BYTE* pData, BYTE, BYTE slaveAddrTaret,  BYTE funcCodeTarget);
BOOLEAN IsTCPIPFrameValid(BYTE* pData, BYTE len);
BOOLEAN IsTCPIPFunctionCodeValid(BYTE* data, BYTE len);

#endif /* COMPONENTS_MODBUS_TCPIP_MODBUSTCPIPLIB_H_ */
