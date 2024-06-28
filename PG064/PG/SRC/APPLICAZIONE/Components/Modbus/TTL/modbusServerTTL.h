/*
 * modbusMaster.h
 *
 *  Created on: 1 ott 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_MODBUSSERVERTTL_H_
#define COMPONENTS_MODBUS_MODBUSSERVERTTL_H_

#include "stdint.h"
#include "Utils/modbusUtils.h"

ModbusServerTypeDef *pModbusTTLServer;

void ModbusTTLRx(uint8_t* pRxData, int length);
void ResetModbusTTLServer();
void InitModbusTTLServer(void);
BOOLEAN IsModbusTTLServerEnable(void);

#endif /* COMPONENTS_MODBUS_MODBUSSERVERTTL_H_ */
