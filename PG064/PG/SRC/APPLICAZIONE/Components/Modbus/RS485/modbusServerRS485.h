/*
 * modbusMaster.h
 *
 *  Created on: 1 ott 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_MODBUSSERVERRS485_H_
#define COMPONENTS_MODBUS_MODBUSSERVERRS485_H_

#include "stdint.h"
#include "Utils/modbusUtils.h"

ModbusServerTypeDef *pModbusRS485Server;

void ModbusRS485Rx(uint8_t* pRxData, int length);
void ResetModbusRS485Server();
void InitModbusRS485Server(void);
BOOLEAN IsModbusRS485ServerEnable(void);

#endif /* COMPONENTS_MODBUS_MODBUSSERVERRS485_H_ */
