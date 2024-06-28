/*
 * wait.c
 *
 *  Created on: 30 giu 2021
 *      Author: paoloc
 */

#include "../Inc/wait.h"

void WaitFor(uint32_t ms){
	uint32_t start = HAL_GetTick();
	while(!ElapsedTick(start, ms));
}

BOOLEAN ElapsedTick(uint32_t tick, uint32_t dly){
	return (HAL_GetTick() - tick) > dly;
}

void StartNewTick(uint32_t *tick){
	*tick = HAL_GetTick();
}
