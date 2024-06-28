/*
 * displayModule.c
 *
 *  Created on: 23 set 2021
 *      Author: paoloc
 */

#include "displayModule.h"
#include "../Brightness/brightnessModule.h"
#include "../Peripherals/Inc/display.h"

void SwitchScreen(uint8_t);
void SwitchReset(uint8_t);

DisplayModuleTypDef displayModule = {
		SwitchScreen,
		SwitchReset
};

void InitDisplayModule(){
	SwitchScreen(0);
	ResetBrightnessValue();
	pDisplayModule = &displayModule;
}

void SwitchScreen(uint8_t on){
	void (*pBrightness)(void);
	pBrightness = on ? RestoreBrightness : ResetBrightnessValue;
	SwitchDisplay(on);
	pBrightness();
}

void SwitchReset(uint8_t rst){
	SwitchRst(rst);
}
