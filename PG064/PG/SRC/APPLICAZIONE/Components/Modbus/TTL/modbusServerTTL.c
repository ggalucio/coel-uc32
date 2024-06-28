/*
 * modbusMaster.c
 *
 *  Created on: 1 ott 2021
 *      Author: paoloc
 */
#include <Components/Modbus/Serial/modbusSerialLib.h>
#include "Peripherals/Inc/modbusTTL.h"
#include "Components/Modbus/TTL/modbusServerTTL.h"
#include "stdlib.h"
#include "string.h"

/**
* Modbus server TTL function pointers and variables.
*/
ModbusServerTypeDef modbusTTLServer = {
		MP_DISCONNECTED,
		MMS_INIT,
		0,
		{ 0 },
		0,
		FUNCTION_CODE_IDX,
		SLAVE_ADDRESS_IDX,
		MODBUS_RS485_REG_ADDR,
		0,
		0,
		InitModbusTTL,
		StartReceivingModbusTTL,
		IsSerialFunctionCodeValid,
		IsSerialFrameValid,
		UnpackModbusSerialMultipleRead,
		UnpackModbusSerialMultipleWrite,
		UnpackModbusSerialSingleWrite,
		PackModbusSerialMultipleWriteResponse,
		PackModbusSerialMultipleReadResponse,
		PackModbusSerialSingleWriteResponse,
		PackSerialExceptions,
		ResetModbusTTLServer,
		IsModbusTTLServerEnable,
		NULL,
		NULL
};

/**
* @brief Modbus server reset
* This function resets buffers and variables
*/
void ResetModbusTTLRxBuff(){
	memset(modbusTTLServer.Buffer.pBuff, 0, sizeof(BYTE) * BUFFER_SIZE);
	modbusTTLServer.Buffer.length = 0;
	modbusTTLServer.Buffer.valid = 0;
}

/**
* @brief Modbus server reset state
* This function resets buffers and modbus server state.
*/
void ResetModbusTTLServer(){
	modbusTTLServer.ExceptionCode = MODBUS_CODE_NO_EXCEPTIONS;
	ResetModbusTTLRxBuff();
	ResetModbusTTL();
}

/**
* @brief Modbus server response package management
* This function receives response package from client and saves it in appropriate buffer.
* @param pRxData: package received from client.
* @param length: package length.
*/
void ModbusTTLRx(uint8_t* pRxData, int length){
	ResetModbusTTLRxBuff();
	memcpy(modbusTTLServer.Buffer.pBuff, pRxData, sizeof(BYTE) * length);
	modbusTTLServer.Buffer.length = length;
	modbusTTLServer.Buffer.valid = 1;
}

/**
* @brief Modbus server enable
* This function gets if modbus TTL server is enabled or not.
* @retval: 1 if modbus TTL server is enabled, 0 otherwise.
*/
BOOLEAN IsModbusTTLServerEnable(){
	return READ_MODBUS_TTL_OPMODE() == MASTER;
}

/**
* @brief Modbus server initializer
* This function initializes modbus TTL server.
*/
void InitModbusTTLServer(){
	modbusTTLComm.State = MB_READY;
	modbusTTLComm.RstClbk = ResetModbusTTLServer;
	modbusTTLComm.ReceiveClbk = ModbusTTLRx;

	modbusTTLServer.Communication = &modbusTTLComm;
	pModbusTTLServer = &modbusTTLServer;
}
