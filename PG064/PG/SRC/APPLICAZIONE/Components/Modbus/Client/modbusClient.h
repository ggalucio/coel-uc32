/*
 * modbusClient.h
 *
 *  Created on: 22 nov 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_CLIENT_MODBUSCLIENT_H_
#define COMPONENTS_MODBUS_CLIENT_MODBUSCLIENT_H_

#include "Utils/modbusUtils.h"

void SetModbusClient(ModbusClientTypeDef* pClient);
void ModbusClientCycle(void);


#endif /* COMPONENTS_MODBUS_CLIENT_MODBUSCLIENT_H_ */
