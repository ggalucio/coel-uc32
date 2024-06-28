/*
 * modbusServerTTLTest.h
 *
 *  Created on: Mar 11, 2022
 *      Author: paoloc
 */

#ifndef TESTBENCH_TTLTEST_MODBUSSERVERTTLTEST_H_
#define TESTBENCH_TTLTEST_MODBUSSERVERTTLTEST_H_

#include "stdint.h"
#include "Utils/modbusUtils.h"

ModbusServerTypeDef *pModbusTTLTestServer;

void ModbusTTLTestRx(uint8_t* pRxData, int length);
void ResetModbusTTLTestServer();
void InitModbusTTLTestServer(void);
BOOLEAN IsModbusTTLTestServerEnable(void);

#endif /* TESTBENCH_TTLTEST_MODBUSSERVERTTLTEST_H_ */
