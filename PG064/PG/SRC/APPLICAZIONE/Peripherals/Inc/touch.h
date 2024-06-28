/*
 * i2c3.h
 *
 *  Created on: 9 giu 2021
 *      Author: paoloc
 */

#ifndef INC_TOUCH_H_
#define INC_TOUCH_H_

#include "stdint.h"
#include "stm32f7xx_hal.h"
#include "../Utils/utils.h"

void ResetPressedTime();
void RefreshPressedTime();
void StartPressedTime();
void TS_IO_Delay(uint32_t Delay);
#endif /* INC_TOUCH_H_ */
