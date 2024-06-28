/*
 * wait.h
 *
 *  Created on: 30 giu 2021
 *      Author: paoloc
 */

#ifndef INC_WAIT_H_
#define INC_WAIT_H_

#include "stm32f7xx_hal.h"
#include "../Utils/utils.h"
#include "stdint.h"

void WaitFor(uint32_t ms);
void StartNewTick(uint32_t *tick);
BOOLEAN ElapsedTick(uint32_t tick, uint32_t dly);

#endif /* INC_WAIT_H_ */
