/*
 * buzzerModule.c
 *
 *  Created on: 1 lug 2021
 *      Author: paoloc
 */

#include "buzzerModule.h"
#include "../Peripherals/Inc/buzzer.h"

BuzzerModTypeDef buzzerModule;

void InitBuzzerModule(){
	buzzerModule.On 	= SwitchBuzzerON;
	buzzerModule.Off 	= SwitchBuzzerOFF;
	buzzerModule.Toggle	= ToggleBuzzer;
	pBuzzerModule		= &buzzerModule;
}



