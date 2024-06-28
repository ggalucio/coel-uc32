/*
 * modbusServers.h
 *
 *  Created on: 16 nov 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_SERVER_MODBUSSERVERMANAGER_H_
#define COMPONENTS_MODBUS_SERVER_MODBUSSERVERMANAGER_H_

//#define USB_MODBUS_SERVER

#include <Components/Modbus/RS485/modbusServerRS485.h>
#include "Components/Modbus/TCPIP/modbusServerTCPIP.h"
#include "Components/Modbus/TTL/modbusServerTTL.h"

void ModbusServersRender(void);
void ModbusServersRun(void);
void InitModbusServers(void);


#endif /* COMPONENTS_MODBUS_SERVER_MODBUSSERVERMANAGER_H_ */
