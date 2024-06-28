/*
 * modbusTTL.h
 *
 *  Created on: 19 nov 2021
 *      Author: paoloc
 */

#ifndef PERIPHERALS_INC_MODBUSTTL_H_
#define PERIPHERALS_INC_MODBUSTTL_H_

#include "Utils/modbusUtils.h"
#include "Utils/integer.h"
#include "stm32f7xx_hal.h"

ModbusCommTypeDef modbusTTLComm;

BOOLEAN IsTTLPhyConnected(void);
BOOLEAN IsTTLConnectionAvailable(void);
BOOLEAN InitModbusTTL();
void DeInitModbusTTL(void);
void StartReceivingModbusTTL();
void ResetModbusTTLTimer();
void StartModbusTTLTimer();
void UpdateModbusTTLTimer();
void ResetModbusTTL(void);

#endif /* PERIPHERALS_INC_MODBUSTTL_H_ */
