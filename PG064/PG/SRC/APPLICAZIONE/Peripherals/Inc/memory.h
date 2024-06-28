/*
 * memory.h
 *
 *  Created on: 8 giu 2021
 *      Author: paoloc
 */

#ifndef INC_MEMORY_H_
#define INC_MEMORY_H_

#include "peripheral.h"
#include "Utils/integer.h"
#include "stdbool.h"

#define EXT_FLASH_START_ADDRESS 0x90000000

typedef enum{
	InternalFlash,
	ExternalFlash
}MemoryTarget;

typedef struct{
	UINT srcAddress;
	UINT dstAddress;
	UINT length;
	MemoryTarget memoryTarget;
}AppTarget;

int InitMemory(void);
void DeInitMemory(void);

// SDRAM
void WriteSdRam(BYTE* pBuff, int length, DWORD startAddress);
void ReadSdRam(BYTE* pBuff, int length, DWORD startAddress);

// FLASH
uint8_t ExtFlashWrite(uint8_t* pData, uint32_t Size, uint32_t address, uint32_t div);
bool WriteIntFlashMemory(uint8_t *src, uint32_t dest, uint32_t Len);
uint8_t EraseExtSectors(uint32_t address);


bool InitMemoryToWrite();
uint32_t GetExtMemorySize();

#endif /* INC_MEMORY_H_ */
