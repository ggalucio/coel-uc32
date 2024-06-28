/*
 * fatFsModule.c
 *
 *  Created on: Dec 1, 2021
 *      Author: paoloc
 */

#include "fatFsModule.h"

ModuleTypDef   fatFsCycleModule;

void InitFatFsModule(){
	fatFsCycleModule.Run = FatFsRun;
	pFatFsCycleModule = &fatFsCycleModule;
}
