/*
 * tcp_server.h
 *
 *  Created on: 26 nov 2021
 *      Author: paoloc
 */

#ifndef PERIPHERALS_INC_TCP_SERVER_H_
#define PERIPHERALS_INC_TCP_SERVER_H_

#include "../Inc/ethernet.h"

BOOLEAN InitModbusTcpIpServer(void);
void DeInitModbusTcpIpServer(void);
void StartReceivingModbusTCPIP(void);

#endif /* PERIPHERALS_INC_TCP_SERVER_H_ */
