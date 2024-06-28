/*
 * tcp_client.h
 *
 *  Created on: 26 nov 2021
 *      Author: paoloc
 */

#ifndef PERIPHERALS_INC_TCP_CLIENT_H_
#define PERIPHERALS_INC_TCP_CLIENT_H_

#include "../Inc/ethernet.h"

BOOLEAN InitModbusTcpIpClient(void);
void DeInitModbusTcpIpClient();

#endif /* PERIPHERALS_INC_TCP_CLIENT_H_ */
