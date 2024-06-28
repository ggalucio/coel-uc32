/*
 * modbusServerTTLTest.c
 *
 *  Created on: Mar 11, 2022
 *      Author: paoloc
 */

#include <Components/Modbus/Serial/modbusSerialLib.h>
#include "Peripherals/Inc/modbusTTLTest.h"
#include "modbusServerTTLTest.h"
#include "stdlib.h"
#include "string.h"

/**
* Modbus server TTL Test function pointers and variables.
*/
ModbusServerTypeDef modbusTTLTestServer = {
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
		InitModbusTTLTest,
		StartReceivingModbusTTLTest,
		IsSerialFunctionCodeValid,
		IsSerialFrameValid,
		UnpackModbusSerialMultipleRead,
		UnpackModbusSerialMultipleWrite,
		UnpackModbusSerialSingleWrite,
		PackModbusSerialMultipleWriteResponse,
		PackModbusSerialMultipleReadResponse,
		PackModbusSerialSingleWriteResponse,
		PackSerialExceptions,
		ResetModbusTTLTestServer,
		IsModbusTTLTestServerEnable,
		NULL,
		NULL
};

/**
* @brief Modbus server reset
* This function resets buffers and variables
*/
void ResetModbusTTLTestRxBuff(){
	memset(modbusTTLTestServer.Buffer.pBuff, 0, sizeof(BYTE) * BUFFER_SIZE);
	modbusTTLTestServer.Buffer.length = 0;
	modbusTTLTestServer.Buffer.valid = 0;
}

/**
* @brief Modbus server reset state
* This function resets buffers and modbus server state.
*/
void ResetModbusTTLTestServer(){
	modbusTTLTestServer.ExceptionCode = MODBUS_CODE_NO_EXCEPTIONS;
	ResetModbusTTLTestRxBuff();
	ResetModbusTTLTest();
}

/**
* @brief Modbus server response package management
* This function receives response package from client and saves it in appropriate buffer.
* @param pRxData: package received from client.
* @param length: package length.
*/
void ModbusTTLTestRx(uint8_t* pRxData, int length){
	ResetModbusTTLTestRxBuff();
	memcpy(modbusTTLTestServer.Buffer.pBuff, pRxData, sizeof(BYTE) * length);
	modbusTTLTestServer.Buffer.length = length;
	modbusTTLTestServer.Buffer.valid = 1;
}

/**
* @brief Modbus server enable
* This function gets if modbus TTL Test server is enabled or not.
* @retval: 1 because modbus server TTL test is always enabled.
*/
BOOLEAN IsModbusTTLTestServerEnable(){
	return AT_TRUE;
}

/**
* @brief Modbus server initializer
* This function initializes modbus TTL Test server.
*/
void InitModbusTTLTestServer(){
	modbusTTLTestComm.State = MB_READY;
	modbusTTLTestComm.RstClbk = ResetModbusTTLTestServer;
	modbusTTLTestComm.ReceiveClbk = ModbusTTLTestRx;

	modbusTTLTestServer.Communication = &modbusTTLTestComm;
	pModbusTTLTestServer = &modbusTTLTestServer;
}



