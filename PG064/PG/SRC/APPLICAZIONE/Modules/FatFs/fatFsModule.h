/*
 * fatFsModule.h
 *
 *  Created on: Dec 1, 2021
 *      Author: paoloc
 */

#ifndef MODULES_FATFS_FATFSMODULE_H_
#define MODULES_FATFS_FATFSMODULE_H_

#include "../Utils/moduleUtil.h"
#include <Components/FatFs/fatFileSystem.h>

ModuleTypDef    *pFatFsCycleModule;

void InitFatFsModule(void);

#endif /* MODULES_FATFS_FATFSMODULE_H_ */
