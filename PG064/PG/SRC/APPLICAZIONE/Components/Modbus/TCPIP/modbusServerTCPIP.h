/*
 * modbusServerTCPIP.h
 *
 *  Created on: 17 nov 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_TCPIP_MODBUSSERVERTCPIP_H_
#define COMPONENTS_MODBUS_TCPIP_MODBUSSERVERTCPIP_H_

#include "stdint.h"
#include "Utils/modbusUtils.h"

ModbusServerTypeDef *pModbusTCPIPServer;

void ModbusTCPIPRx(uint8_t* pRxData, int length);
void ResetModbusTCPIPServer();
void InitModbusTCPIPServer(void);
BOOLEAN IsModbusTCPIPServerEnable(void);

#endif /* COMPONENTS_MODBUS_TCPIP_MODBUSSERVERTCPIP_H_ */
