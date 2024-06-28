/*
 * modbusServerTCPIP.c
 *
 *  Created on: 17 nov 2021
 *      Author: paoloc
 */

#include "modbusServerTCPIP.h"
#include <Components/Modbus/TCPIP/modbusTCPIPLib.h>
#include "Peripherals/Inc/tcp_server.h"
#include "stdlib.h"
#include "string.h"

/**
* Modbus server TCPIP function pointers and variables.
*/
ModbusServerTypeDef modbusTCPIPServer = {
		MP_DISCONNECTED,
		MMS_INIT,
		0,
		{ 0 },
		0,
		MODBUS_TCPIP_FUNCODE_RESP_POS,
		MODBUS_TCPIP_UNITID_RESP_POS,
		MODBUS_RS485_REG_ADDR,
		0,
		0,
		InitModbusTcpIpServer,
		StartReceivingModbusTCPIP,
		IsTCPIPFunctionCodeValid,
		IsTCPIPFrameValid,
		UnpackModbusTCPIPMultipleRead,
		UnpackModbusTCPIPMultipleWrite,
		UnpackModbusTCPIPSingleWrite,
		PackModbusTCPIPMultipleWriteResponse,
		PackModbusTCPIPMultipleReadResponse,
		PackModbusTCPIPSingleWriteResponse,
		PackTCPIPExceptions,
		ResetModbusTCPIPServer,
		IsModbusTCPIPServerEnable,
		IsEthPhyConnected,
		DeInitModbusTcpIpServer
};

/**
* @brief Modbus server reset
* This function resets buffers and variables
*/
void ResetModbusTCPIPRxBuff(){
	memset(modbusTCPIPServer.Buffer.pBuff, 0, sizeof(BYTE) * BUFFER_SIZE);
	modbusTCPIPServer.Buffer.length = 0;
	modbusTCPIPServer.Buffer.valid = 0;
}

/**
* @brief Modbus server response package management
* This function receives response package from client and saves it in appropriate buffer.
* @param pRxData: package received from client.
* @param length: package length.
*/
void ModbusTCPIPRx(uint8_t* pRxData, int length){
	ResetModbusTCPIPRxBuff();
	memcpy(modbusTCPIPServer.Buffer.pBuff, pRxData, sizeof(BYTE) * length);
	modbusTCPIPServer.Buffer.length = length;
	modbusTCPIPServer.Buffer.valid = 1;
}

/**
* @brief Modbus server reset state
* This function resets buffers and modbus server state.
*/
void ResetModbusTCPIPServer(){
	modbusTCPIPServer.ExceptionCode = MODBUS_CODE_NO_EXCEPTIONS;
	ResetModbusTCPIPRxBuff();
	ResetModbusTCPIP();
}

/**
* @brief Modbus server initializer
* This function initializes modbus TCPIP server.
*/
void InitModbusTCPIPServer(void){
	modbusTCPIPComm.State = MB_READY;
	modbusTCPIPComm.RstClbk = ResetModbusTCPIPServer;
	modbusTCPIPComm.ReceiveClbk = ModbusTCPIPRx;
	modbusTCPIPServer.Communication = &modbusTCPIPComm;
	pModbusTCPIPServer = &modbusTCPIPServer;
}

/**
* @brief Modbus server enable
* This function gets if modbus TCPIP server is enabled or not.
* @retval: 1 if modbus TCPIP server is enabled, 0 otherwise.
*/
BOOLEAN IsModbusTCPIPServerEnable(void){
	return READ_MODBUS_TCPIP_OPMODE() == MASTER;
}
