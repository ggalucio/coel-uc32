/*
 * modbusMaster.c
 *
 *  Created on: 1 ott 2021
 *      Author: paoloc
 */
#include <Components/Modbus/Serial/modbusSerialLib.h>
#include "Peripherals/Inc/modbus.h"
#include "Components/Modbus/RS485/modbusServerRS485.h"
#include "stdlib.h"
#include "string.h"

/**
* Modbus server RS485 function pointers and variables.
*/
ModbusServerTypeDef modbusRS485Server = {
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
		InitModbusRS485,
		StartReceivingModbusRS485,
		IsSerialFunctionCodeValid,
		IsSerialFrameValid,
		UnpackModbusSerialMultipleRead,
		UnpackModbusSerialMultipleWrite,
		UnpackModbusSerialSingleWrite,
		PackModbusSerialMultipleWriteResponse,
		PackModbusSerialMultipleReadResponse,
		PackModbusSerialSingleWriteResponse,
		PackSerialExceptions,
		ResetModbusRS485Server,
		IsModbusRS485ServerEnable,
		NULL,
		NULL
};

/**
* @brief Modbus server reset
* This function resets buffers and variables
*/
void ResetModbusRS485RxBuff(){
	memset(modbusRS485Server.Buffer.pBuff, 0, sizeof(BYTE) * BUFFER_SIZE);
	modbusRS485Server.Buffer.length = 0;
	modbusRS485Server.Buffer.valid = 0;
}

/**
* @brief Modbus server reset state
* This function resets buffers and modbus server state.
*/
void ResetModbusRS485Server(){
	modbusRS485Server.ExceptionCode = MODBUS_CODE_NO_EXCEPTIONS;
	ResetModbusRS485RxBuff();
	ResetModbusRS485();
}

/**
* @brief Modbus server response package management
* This function receives response package from client and saves it in appropriate buffer.
* @param pRxData: package received from client.
* @param length: package length.
*/
void ModbusRS485Rx(uint8_t* pRxData, int length){
	ResetModbusRS485RxBuff();
	memcpy(modbusRS485Server.Buffer.pBuff, pRxData, sizeof(BYTE) * length);
	modbusRS485Server.Buffer.length = length;
	modbusRS485Server.Buffer.valid = 1;
}

/**
* @brief Modbus server enable
* This function gets if modbus RS485 server is enabled or not.
* @retval: 1 if modbus RS485 server is enabled, 0 otherwise.
*/
BOOLEAN IsModbusRS485ServerEnable(){
	return READ_MODBUS_RS485_OPMODE() == MASTER;
}

/**
* @brief Modbus server initializer
* This function initializes modbus RS485 server.
*/
void InitModbusRS485Server(){
	modbusRS485Comm.State = MB_READY;
	modbusRS485Comm.RstClbk = ResetModbusRS485Server;
	modbusRS485Comm.ReceiveClbk = ModbusRS485Rx;

	modbusRS485Server.Communication = &modbusRS485Comm;
	pModbusRS485Server = &modbusRS485Server;
}
