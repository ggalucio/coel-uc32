/*
 * modbusTTLTest.h
 *
 *  Created on: 11 mar 2022
 *      Author: paoloc
 */

#ifndef PERIPHERALS_INC_MODBUSTTLTEST_H_
#define PERIPHERALS_INC_MODBUSTTLTEST_H_

#include "Utils/modbusUtils.h"
#include "Utils/integer.h"
#include "stm32f7xx_hal.h"

ModbusCommTypeDef modbusTTLTestComm;

BOOLEAN IsTTLTestPhyConnected(void);
BOOLEAN IsTTLTestConnectionAvailable(void);
BOOLEAN InitModbusTTLTest();
void DeInitModbusTTLTest(void);
void StartReceivingModbusTTLTest();
void ResetModbusTTLTestTimer();
void StartModbusTTLTestTimer();
void UpdateModbusTTLTestTimer();
void ResetModbusTTLTest(void);



#endif /* PERIPHERALS_INC_MODBUSTTLTEST_H_ */
