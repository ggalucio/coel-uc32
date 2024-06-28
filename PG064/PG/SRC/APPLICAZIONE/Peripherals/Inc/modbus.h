/*
 * modbus.h
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#ifndef INC_MODBUS_H_
#define INC_MODBUS_H_

#include "Utils/modbusUtils.h"
#include "Utils/integer.h"
#include "stm32f7xx_hal.h"

ModbusCommTypeDef modbusRS485Comm;

BOOLEAN InitModbusRS485();
BOOLEAN IsRS485PhyConnected(void);
BOOLEAN IsRS485ConnectionAvailable(void);
void DeInitModbusRS485(void);
void StartReceivingModbusRS485();
void ResetModbusTimer();
void StartModbusTimer();
void UpdateModbusTimer();
void ResetModbusRS485(void);

#endif /* INC_MODBUS_H_ */
