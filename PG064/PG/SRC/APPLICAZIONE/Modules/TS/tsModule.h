/*
 * tsModule.h
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#ifndef TS_TSMODULE_H_
#define TS_TSMODULE_H_


#include "../Utils/moduleUtil.h"

typedef struct{
	uint8_t (*TimeoutElapsed)(uint32_t);
}TsModuleTypDef;

ModuleTypDef    *pTsCycleModule;
TsModuleTypDef 	*pTsModule;

void InitTSModule();
uint8_t TsTimeoutElapsed(uint32_t ms);

#endif /* TS_TSMODULE_H_ */
