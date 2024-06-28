/*
 * modbusClientTCPIP.h
 *
 *  Created on: 21 ott 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_TCPIP_MODBUSCLIENTTCPIP_H_
#define COMPONENTS_MODBUS_TCPIP_MODBUSCLIENTTCPIP_H_

#include "Utils/modbusUtils.h"

ModbusClientTypeDef *pModbusTCPIPClient;

BOOLEAN IsModbusTCPIPClientEnable();
BOOLEAN IsTcpIpClientConnLost();
void InitModbusTCPIPClient();

#endif /* COMPONENTS_MODBUS_TCPIP_MODBUSCLIENTTCPIP_H_ */
