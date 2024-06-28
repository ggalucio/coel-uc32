/*
 * memoryModule.h
 *
 *  Created on: 2 lug 2021
 *      Author: paoloc
 */

#ifndef MEMORY_MEMORYMODULE_H_
#define MEMORY_MEMORYMODULE_H_

#include "stdint.h"
#include "Utils/integer.h"

typedef struct{
	uint8_t	 (*WriteExt)(uint8_t*, uint32_t, uint32_t,  uint32_t);
	uint8_t	 (*WriteInt)(uint8_t*, uint32_t, uint32_t);
}MemoryModTypeDef;

MemoryModTypeDef * pMemoryModule;

void InitMemoryModule(void);
void WriteRam(BYTE* pBuff, int length, DWORD startAddress);
void ReadRam(BYTE* pBuff, int length, DWORD startAddress);

#endif /* MEMORY_MEMORYMODULE_H_ */
