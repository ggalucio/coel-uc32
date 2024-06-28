/*
 * GraphicsModule.h
 *
 *  Created on: 23 set 2021
 *      Author: paoloc
 */

#ifndef MODULES_GRAPHICS_GRAPHICSMODULE_H_
#define MODULES_GRAPHICS_GRAPHICSMODULE_H_

#include "stdint.h"
#include "../Utils/moduleUtil.h"

typedef struct{
	uint8_t (*Elapsed)(uint32_t*, uint32_t);
	uint8_t (*ReadHour)(void);
	uint8_t (*ReadMin)(void);
	uint8_t (*ReadSec)(void);
	uint8_t (*ReadDay)(void);
	uint8_t (*ReadMonth)(void);
	uint8_t (*ReadYear)(void);
	void	(*WriteHour)(uint8_t);
	void	(*WriteMin)(uint8_t);
	void	(*WriteSec)(uint8_t);
	void	(*WriteDay)(uint8_t);
	void	(*WriteMonth)(uint8_t);
	void	(*WriteYear)(uint8_t);

}TimeModuleTypDef;

TimeModuleTypDef *pTimeModule;
ModuleTypDef     *pTimeCycleModule;

void InitTimeModule();
uint8_t Elapsed(uint32_t *ms, uint32_t timeout);
void UpdateTime(void);

#endif /* MODULES_GRAPHICS_GRAPHICSMODULE_H_ */
