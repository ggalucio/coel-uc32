/*
 * displayModule.h
 *
 *  Created on: 23 set 2021
 *      Author: paoloc
 */

#ifndef MODULES_DISPLAY_DISPLAYMODULE_H_
#define MODULES_DISPLAY_DISPLAYMODULE_H_

#include "stdint.h"

typedef struct{
	void (*SwitchScreen)(uint8_t);
	void (*SwitchReset)(uint8_t);
}DisplayModuleTypDef;

DisplayModuleTypDef *pDisplayModule;

void InitDisplayModule();

#endif /* MODULES_DISPLAY_DISPLAYMODULE_H_ */
