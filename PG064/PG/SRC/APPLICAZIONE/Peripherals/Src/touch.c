/*
 * i2c3.c
 *
 *  Created on: 9 giu 2021
 *      Author: paoloc
 */

#include <stddef.h>
#include "../Inc/touch.h"

uint32_t startPressedTime = 0;

void ResetPressedTime(){
	TS_PRESS_TIMER_ADDRESS = (uint16_t)0;
}

void RefreshPressedTime(){
	TS_PRESS_TIMER_ADDRESS = (uint16_t)(HAL_GetTick() - startPressedTime);
}

void StartPressedTime(){
	startPressedTime = HAL_GetTick();
}

/**
  * @brief  TS delay
  * @param  Delay: Delay in ms
  * @retval None
  */
void TS_IO_Delay(uint32_t Delay)
{
    HAL_Delay(Delay);
}
