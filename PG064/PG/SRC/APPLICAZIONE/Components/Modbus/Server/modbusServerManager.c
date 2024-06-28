/*
 * modbusServers.c
 *
 *  Created on: 16 nov 2021
 *      Author: paoloc
 */

#include <Components/Modbus/Server/modbusServerManager.h>
#include "Components/Modbus/RS485/modbusServerRS485.h"
#include "Components/Modbus/TTL/modbusServerTTL.h"
#include "Components/Modbus/TCPIP/modbusServerTCPIP.h"
#include "modbusServer.h"

#ifdef USB_MODBUS_SERVER
#include "UsbModbus/usbDevice.h"
#include "TTLTest/modbusServerTTLTest.h"
#endif

/*
 * Max server number
 */
#define  MODBUS_SERVERS_NUM 	5

/**
* Modbus servers array pointers
*/
ModbusServerTypeDef* pModbusServers[MODBUS_SERVERS_NUM];

/**
* Modbus server number
*/
int nModbusServers;

/**
* When current modbus server changes, this counter increases.
*/
BYTE modbusRenderCounter;

/**
* @brief Modbus servers initializer.
* This function initializes modbus servers.
*/
void InitModbusServers(){
#ifdef USB_MODBUS_SERVER
	InitUsbModbusServer();
	InitModbusTTLTestServer();
#endif

	InitModbusRS485Server();
	InitModbusTTLServer();
	InitModbusTCPIPServer();

	modbusRenderCounter = 0;
	nModbusServers = 0;

#ifdef USB_MODBUS_SERVER
	pModbusServers[nModbusServers++] = pModbusUsbServer;
	pModbusServers[nModbusServers++] = pModbusTTLTestServer;
#endif

	pModbusServers[nModbusServers++] = pModbusRS485Server;
	pModbusServers[nModbusServers++] = pModbusTTLServer;
	pModbusServers[nModbusServers++] = pModbusTCPIPServer;
}

/**
* @brief Change modbus server to manage.
* This function updates current modbus server to manage.
*/
void ModbusServersRender(){
	ModbusServerTypeDef* modbusServer = pModbusServers[(++modbusRenderCounter) % nModbusServers];
	SetModbusServer(modbusServer);
}

/**
* @brief Modbus server entry point.
* This function is the modbus server machine state entry point.
*/
void ModbusServersRun(){
	ModbusServerCycle();
}
