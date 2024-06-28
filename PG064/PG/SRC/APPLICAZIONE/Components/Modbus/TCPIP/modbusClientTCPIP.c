/*
 * modbusClientTCPIP.c
 *
 *  Created on: 21 ott 2021
 *      Author: paoloc
 */

#include "Components/Modbus/TCPIP/modbusClientTCPIP.h"
#include "Components/Modbus/TCPIP/modbusTCPIPLib.h"
#include "Components/Modbus/modbusCommon.h"
#include "Peripherals/Inc/tcp_client.h"
#include "stdlib.h"
#include "string.h"

/**
* Modbus TCPIP connection timeout
*/
#define MODBUS_TCPIP_CONN_TIMEOUT 5000

/**
* Modbus client TCPIP data exchange structure.
*/
ModbusDataExchange modbusTCPIPDataExch;

/**
* Modbus TCPIP last error tick.
*/
DWORD lastTickErr = 0;

/**
* Modbus client TCPIP function pointers and variables.
*/
ModbusClientTypeDef modbusTCPIPClient = {
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
		START_TCPIP_DATA_RESP_IDX,			// Response data start index
		NULL,								// Handler
		DeInitModbusTcpIpClient,			// Deinitialize modbus
		InitModbusTcpIpClient,				// Initialize modbus
		IsEthPhyConnected,					// Is board physically connected
		IsEthConnAvailable,					// Is connection available
		PackTcpIpRequest,					// Pack request
		RespTcpipIsValid,					// Checksum
		ReadModbusDataResp,					// Read server response
		IsModbusTCPIPClientEnable,			// Is modbus client enable
		NULL,								// Is connection lost function
		ResetTcpIpModbusTimer,				// Reset modbus communication timer
		StartTcpIpModbusTimer,				// Start modbus communication timer
		UpdateTcpIpModbusTimer				// Update modbus communication timer
};

/**
* @brief Modbus client reset
* This function resets buffers and variables
*/
void ResetModbusClientTCPIPRxBuff(){
	memset(modbusTCPIPClient.RxBuffer.pBuff, 0, sizeof(BYTE) * BUFFER_SIZE);
	modbusTCPIPClient.RxBuffer.length = 0;
	modbusTCPIPClient.RxBuffer.valid = 0;
}

/**
* @brief Modbus client reset state
* This function resets buffers and modbus client state.
*/
void ResetModbusTCPIPClient(){
	ResetModbusClientTCPIPRxBuff();
	ResetModbusTCPIP();
}

/**
* @brief Modbus client response package management
* This function receives reponse package from server and saves it in appropriate buffer.
* @param pRxData: package received from server.
* @param length: package length.
*/
void ModbusClientTCPIPRx(uint8_t* pRxData, int length){
	ResetModbusClientTCPIPRxBuff();
	memcpy(modbusTCPIPClient.RxBuffer.pBuff, pRxData, sizeof(BYTE) * length);
	modbusTCPIPClient.RxBuffer.length = length;
	modbusTCPIPClient.RxBuffer.valid = 1;
}

/**
* @brief Modbus client enable
* This function gets if modbus TCPIP client is enabled or not.
* @retval: 1 if modbus TCPIP client is enabled, 0 otherwise.
*/
BOOLEAN IsModbusTCPIPClientEnable(){
	return READ_MODBUS_TCPIP_OPMODE() == SLAVE;
}

/**
* @brief Modbus client connection
* This function gets if modbus TCPIP client connection is lost or not
* @retval: 1 if modbus TCPIP client connection is lost, 0 otherwise.
*/
BOOLEAN IsTcpIpClientConnLost(){
	return MODBUS_TCPIP_TIMER_ADDR > MODBUS_TCPIP_CONN_TIMEOUT;
}

/**
* @brief Modbus client error manager
* This function manages modbus TCPIP errors.
*/
void ErrorTcpIp(){
	if(HAL_GetTick() - lastTickErr > 1000){
		InitModbusTcpIpClient();
		HAL_Delay(5);
		lastTickErr = HAL_GetTick();
	}
}

/**
* @brief Modbus client initializer
* This function initializes modbus TCPIP client.
*/
void InitModbusTCPIPClient(){
	modbusTCPIPComm.State = MB_READY;
	modbusTCPIPComm.RstClbk = ResetModbusTCPIPClient;
	modbusTCPIPComm.ReceiveClbk = ModbusClientTCPIPRx;
	modbusTCPIPComm.Error = ErrorTcpIp;

	modbusTCPIPClient.Handler = &modbusTCPIPComm;
	modbusTCPIPClient.ModbusDataExch = &modbusTCPIPDataExch;

	modbusTCPIPClient.exchDataState = MMS_INIT;
	modbusTCPIPClient.phyConnection = MP_DISCONNECTED;

	pModbusTCPIPClient = &modbusTCPIPClient;

	lastTickErr = HAL_GetTick();
}
