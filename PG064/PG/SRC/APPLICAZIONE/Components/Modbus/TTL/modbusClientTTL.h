/*
 * modbusClientTTL.h
 *
 *  Created on: 22 nov 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_TTL_MODBUSCLIENTTTL_H_
#define COMPONENTS_MODBUS_TTL_MODBUSCLIENTTTL_H_

#include "Utils/modbusUtils.h"

ModbusClientTypeDef *pModbusTTLClient;
InterfaceData pModbusTTLRead[25];
InterfaceData pModbusTTLWrite[25];
int modbusTTLReadLength;
int modbusTTLWriteLength;

BOOLEAN IsModbusTTLClientEnable();
void InitModbusTTLClient();



#endif /* COMPONENTS_MODBUS_TTL_MODBUSCLIENTTTL_H_ */
