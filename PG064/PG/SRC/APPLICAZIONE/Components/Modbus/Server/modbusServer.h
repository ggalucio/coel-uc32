/*
 * modbusServer.h
 *
 *  Created on: 16 nov 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_SERVER_MODBUSSERVER_H_
#define COMPONENTS_MODBUS_SERVER_MODBUSSERVER_H_

#include "Utils/modbusUtils.h"

void ModbusServerCycle();
void SetModbusServer(ModbusServerTypeDef* pServer);

#endif /* COMPONENTS_MODBUS_SERVER_MODBUSSERVER_H_ */
