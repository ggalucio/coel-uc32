/*
 * modbusClientINT.c
 *
 *  Created on: 17 feb 2022
 *      Author: paoloc
 */

#include "modbusClientINT.h"

/**
* Modbus client INT data exchange structure.
*/
ModbusDataExchange modbusINTDataExch;

/**
* Modbus client INT function pointers and variables.
*/
ModbusClientTypeDef modbusINTClient = {
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
		0,									// Response data start index
		NULL,								// Handler
		NULL,								// Deinitialize modbus
		NULL,								// Initialize modbus
		NULL,								// Is board physically connected
		NULL,								// Is connection available
		NULL,								// Pack request
		NULL,								// Checksum
		NULL,								// Read server response
		NULL,								// Is modbus client enable
		NULL,								// Is connection lost function
		NULL,								// Reset modbus communication timer
		NULL,								// Start modbus communication timer
		NULL								// Update modbus communication timer
};

/**
* @brief Modbus client initializer
* This function initializes modbus internal memory RAM client.
*/
void InitModbusINTClient(){
	modbusINTClient.ModbusDataExch = &modbusINTDataExch;
	pModbusINTClient = &modbusINTClient;
}
