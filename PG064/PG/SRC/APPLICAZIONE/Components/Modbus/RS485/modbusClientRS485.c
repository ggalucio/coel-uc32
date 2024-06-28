/*
 * modbusClientRS485.c
 *
 *  Created on: 22 nov 2021
 *      Author: paoloc
 */


#include <Components/Modbus/RS485/modbusClientRS485.h>
#include "Components/Modbus/Serial/modbusSerialLib.h"
#include "Components/Modbus/modbusCommon.h"
#include "Peripherals/Inc/modbus.h"
#include "stdlib.h"
#include "string.h"

/**
* Modbus client RS485 data exchange structure.
*/
ModbusDataExchange modbusRS485DataExch;

/**
* Modbus client RS485 function pointers and variables.
*/
ModbusClientTypeDef modbusRS485Client = {
		NULL,								// modbusDataExch
		REQ_NONE,							// reqType
		0,									// currReadIdx
		0,									// currReadAddress
		MM_INIT,							// exchDataState
		MD_START,							// managementDataState
		MP_DISCONNECTED,					// phyConnection
		{AT_FALSE, {0}, 0},					// rxData
		0,									// readRegistersNum
		{{{0}}, 0},							// chunks
		0,									// ackTimer
		0,									// startTick
		0,									// transactionId
		0,									// currSlaveAddress
		0,									// currFunctionCode
		START_SERIAL_DATA_RESP_IDX,			// Response data start index
		NULL,								// Handler
		DeInitModbusRS485,					// Deinitialize modbus
		InitModbusRS485,					// Initialize modbus
		IsRS485PhyConnected,				// Is board physically connected
		IsRS485ConnectionAvailable,			// Is connection available
		PackRequest,						// Pack request
		ApplyValidationCheck,				// Checksum
		ReadModbusDataResp,					// Read server response
		IsModbusRS485ClientEnable,			// Is modbus client enable
		NULL,								// Is connection lost function
		ResetModbusTimer,					// Reset modbus communication timer
		StartModbusTimer,					// Start modbus communication timer
		UpdateModbusTimer					// Update modbus communication timer
};

/**
* @brief Modbus client reset
* This function resets buffers and variables
*/
void ResetModbusClientRS485RxBuff(){
	memset(modbusRS485Client.RxBuffer.pBuff, 0, sizeof(BYTE) * BUFFER_SIZE);
	modbusRS485Client.RxBuffer.length = 0;
	modbusRS485Client.RxBuffer.valid = 0;
}

/**
* @brief Modbus client reset state
* This function resets buffers and modbus client state.
*/
void ResetModbusRS485Client(){
	ResetModbusClientRS485RxBuff();
	ResetModbusRS485();
}

/**
* @brief Modbus client response package management
* This function receives reponse package from server and saves it in appropriate buffer.
* @param pRxData: package received from server.
* @param length: package length.
*/
void ModbusClientRS485Rx(uint8_t* pRxData, int length){
	ResetModbusClientRS485RxBuff();
	memcpy(modbusRS485Client.RxBuffer.pBuff, pRxData, sizeof(BYTE) * length);
	modbusRS485Client.RxBuffer.length = length;
	modbusRS485Client.RxBuffer.valid = 1;
}

/**
* @brief Modbus client enable
* This function gets if modbus RS485 client is enabled or not.
* @retval: 1 if modbus RS485 client is enabled, 0 otherwise.
*/
BOOLEAN IsModbusRS485ClientEnable(){
	return READ_MODBUS_RS485_OPMODE() == SLAVE;
}

/**
* @brief Modbus client initializer
* This function initializes modbus RS485 client.
*/
void InitModbusRS485Client(){
	modbusRS485Comm.State = MB_READY;
	modbusRS485Comm.RstClbk = ResetModbusRS485Client;
	modbusRS485Comm.ReceiveClbk = ModbusClientRS485Rx;

	modbusRS485Client.Handler = &modbusRS485Comm;
	modbusRS485Client.ModbusDataExch = &modbusRS485DataExch;

	modbusRS485Client.exchDataState = MMS_INIT;
	modbusRS485Client.phyConnection = MP_DISCONNECTED;

	pModbusRS485Client = &modbusRS485Client;
}
