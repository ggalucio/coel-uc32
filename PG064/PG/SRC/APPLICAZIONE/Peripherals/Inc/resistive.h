/*
 * resistive.h
 *
 *  Created on: 10 set 2021
 *      Author: paoloc
 */

#ifndef INC_RESISTIVE_H_
#define INC_RESISTIVE_H_

#include "touch.h"
#include "gpio.h"

#define X_L_Pin 	GPIO_PIN_5
#define X_L_Port 	GPIOA
#define X_R_Pin 	GPIO_PIN_3
#define X_R_Port 	GPIOA
#define Y_T_Pin 	GPIO_PIN_6
#define Y_T_Port 	GPIOA
#define Y_B_Pin 	GPIO_PIN_4
#define Y_B_Port 	GPIOA

uint8_t  DeInitResistive(void);
uint8_t  Resistive_TS_IO_Init(void);
uint8_t  Resistive_TS_IO_DeviceReady(uint16_t DevAddress);
void 	 Resistive_TS_IO_Write(uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t Value);
uint16_t Resistive_TS_IO_Read(uint8_t Addr, uint16_t Reg, uint16_t MemAddress);
uint8_t  Resistive_TS_IO_Read_Multiple(uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t* pData, uint8_t len);
void 	 Resistive_Error(void);

#endif /* INC_RESISTIVE_H_ */
