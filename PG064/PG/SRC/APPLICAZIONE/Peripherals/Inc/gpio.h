/*
 * gpio.h
 *
 *  Created on: 8 giu 2021
 *      Author: paoloc
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "peripheral.h"
#include "pins.h"

void InitGpio(void);
void DeInitGpio(void);
void SetUsbVenPinON(void);
void InitGpioPin(GPIO_TypeDef* port, uint32_t pin, uint32_t mode, uint32_t pull, uint32_t speed);
void DeInitGpioPin(GPIO_TypeDef* port, uint32_t pin);
void WritePin(GPIO_TypeDef* port, uint32_t pin, GPIO_PinState state);
GPIO_PinState ReadPin(GPIO_TypeDef* port, uint32_t pin);
void TogglePin(GPIO_TypeDef* port, uint32_t pin);

#endif /* INC_GPIO_H_ */
