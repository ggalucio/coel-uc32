/*
 * modbusClientTTL.c
 *
 *  Created on: 22 nov 2021
 *      Author: paoloc
 */

#include "modbusClientTTL.h"
#include "Components/Modbus/Serial/modbusSerialLib.h"
#include "Components/Modbus/modbusCommon.h"
#include "Peripherals/Inc/modbusTTL.h"
#include "stdlib.h"
#include "string.h"

/**
* Modbus client TTL data exchange structure.
*/
ModbusDataExchange modbusTTLDataExch;

/**
* Modbus client TTL function pointers and variables.
*/
ModbusClientTypeDef modbusTTLClient = {
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
		DeInitModbusTTL,					// Deinitialize modbus
		InitModbusTTL,						// Initialize modbus
		IsTTLPhyConnected,					// Is board physically connected
		IsTTLConnectionAvailable,			// Is connection available
		PackRequest,						// Pack request
		ApplyValidationCheck,				// Checksum
		ReadModbusDataResp,					// Read server response
		IsModbusTTLClientEnable,			// Is modbus client enable
		NULL,								// Is connection lost function
		ResetModbusTTLTimer,				// Reset modbus communication timer
		StartModbusTTLTimer,				// Start modbus communication timer
		UpdateModbusTTLTimer				// Update modbus communication timer
};

/**
* @brief Modbus client reset
* This function resets buffers and variables
*/
void ResetModbusClientTTLRxBuff(){
	memset(modbusTTLClient.RxBuffer.pBuff, 0, sizeof(BYTE) * BUFFER_SIZE);
	modbusTTLClient.RxBuffer.length = 0;
	modbusTTLClient.RxBuffer.valid = 0;
}

/**
* @brief Modbus client reset state
* This function resets buffers and modbus client state.
*/
void ResetModbusTTLClient(){
	ResetModbusClientTTLRxBuff();
	ResetModbusTTL();
}

/**
* @brief Modbus client response package management
* This function receives response package from server and saves it in appropriate buffer.
* @param pRxData: package received from server.
* @param length: package length.
*/
void ModbusClientTTLRx(uint8_t* pRxData, int length){
	ResetModbusClientTTLRxBuff();
	memcpy(modbusTTLClient.RxBuffer.pBuff, pRxData, sizeof(BYTE) * length);
	modbusTTLClient.RxBuffer.length = length;
	modbusTTLClient.RxBuffer.valid = 1;
}

/**
* @brief Modbus client enable
* This function gets if modbus TTL client is enabled or not.
* @retval: 1 if modbus TTL client is enabled, 0 otherwise.
*/
BOOLEAN IsModbusTTLClientEnable(){
	return READ_MODBUS_TTL_OPMODE() == SLAVE;
}

/**
* @brief Modbus client initizializer
* This function initializes modbus TTL client.
*/
void InitModbusTTLClient(){
	modbusTTLComm.State = MB_READY;
	modbusTTLComm.RstClbk = ResetModbusTTLClient;
	modbusTTLComm.ReceiveClbk = ModbusClientTTLRx;

	modbusTTLClient.Handler = &modbusTTLComm;
	modbusTTLClient.ModbusDataExch = &modbusTTLDataExch;

	modbusTTLClient.exchDataState = MMS_INIT;
	modbusTTLClient.phyConnection = MP_DISCONNECTED;

	pModbusTTLClient = &modbusTTLClient;
}


