/*
 * memoryModule.c
 *
 *  Created on: 2 lug 2021
 *      Author: paoloc
 */

#include "memoryModule.h"
#include "../Peripherals/Inc/memory.h"

MemoryModTypeDef memoryModule;

void InitMemoryModule(void){
	memoryModule.WriteExt 	= ExtFlashWrite;
	pMemoryModule			= &memoryModule;
}

void WriteRam(BYTE* pBuff, int length, DWORD startAddress){
	WriteSdRam(pBuff, length, startAddress);
}

void ReadRam(BYTE* pBuff, int length, DWORD startAddress){
	ReadSdRam(pBuff, length, startAddress);
}
