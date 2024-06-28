/*
 * modbusClientRS485.h
 *
 *  Created on: 22 nov 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_RS485_MODBUSCLIENTRS485_H_
#define COMPONENTS_MODBUS_RS485_MODBUSCLIENTRS485_H_

#include "Utils/modbusUtils.h"

ModbusClientTypeDef *pModbusRS485Client;

BOOLEAN IsModbusRS485ClientEnable();
void InitModbusRS485Client();

#endif /* COMPONENTS_MODBUS_RS485_MODBUSCLIENTRS485_H_ */
