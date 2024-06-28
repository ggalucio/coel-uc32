/*
 * tsModule.c
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#include "tsModule.h"
#include "Components/TouchDrivers/ts.h"
#include "Utils/utils.h"

ModuleTypDef   tsCycleModule;

TsModuleTypDef tsModule = {
		TsTimeoutElapsed
};

void InitTSModule(){
	tsCycleModule.Run = TouchScreenRun;
	pTsCycleModule = &tsCycleModule;
	pTsModule = &tsModule;
}

uint8_t TsTimeoutElapsed(uint32_t ms){
	return (ms < TS_PRESS_TIMER_ADDRESS);
}


