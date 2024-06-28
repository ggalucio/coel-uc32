/*
 * moduleManager.h
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#ifndef MANAGER_MODULEMANAGER_H_
#define MANAGER_MODULEMANAGER_H_

#include "../Utils/moduleUtil.h"
#include "Utils/utils.h"

ModuleTypDef *pModbusClientCycle;
ModuleTypDef *pModbusServerCycle;
ModuleTypDef *pTsCycle;
ModuleTypDef *pJobCycle;
ModuleTypDef *pTimeCycle;
ModuleTypDef *pFatsCycle;

void InitModules(void);
void SetJobCallback(void* Callback);
void SuspendClientTaskCallback(void* Callback);
void ResumeClientTaskCallback(void* Callback);
BOOLEAN DoesModbusClientTaskNeedToRun(void);
BOOLEAN DoesModbusServerTaskNeedToRun(void);

#endif /* MANAGER_MODULEMANAGER_H_ */
