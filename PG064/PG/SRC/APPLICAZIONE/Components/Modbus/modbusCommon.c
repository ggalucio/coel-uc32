/*
 * modbusCommon.c
 *
 *  Created on: 27 ott 2021
 *      Author: paoloc
 */

#include "modbusCommon.h"
#include "stdlib.h"
#include "stm32f7xx.h"

#define MODBUS_MAX_REGS_IN_CHUNK	32
#define MODBUS_MIN_PACKAGE_SIZE 	4

/**
* This function gets data requested
*/
#define GET_MODBUS_READ_VALUE(startDataIdx)																								\
	int i, w;																											\
	int nWords = nBytes / BYTES_IN_WORD;																				\
	for( w = 0; w < nWords; w++){																						\
		WORD val = 0;																									\
		for(i = 0; i < BYTES_IN_WORD; i++){																				\
			val |= (data[startDataIdx + offset + i + BYTES_IN_WORD * w] << (BYTE_BIT_NUM * (BYTES_IN_WORD - i - 1)));	\
		}																												\
		value |= (val << w * BYTE_BIT_NUM * BYTES_IN_WORD);																\
	}

/**
* @brief Response modbus data reader.
* This function reads modbus response package coming from remote device and
* unpacks it in order to get single data value in requested registers.
* @param data: modbus response package received from remote device
* @param buffLen: modbus response package length
* @param offset: index data to read
* @param nBytes: data to read bytes number (if it's a floating point 32 bit this number is 4, otherwise 2).
* @param startDataIdx: index where data starts inside modbus package
* @retval Wanted data value.
*/
DWORD ReadModbusDataResp(BYTE* data, int buffLen, int offset, int nBytes, BYTE startDataIdx){
	if(buffLen < MODBUS_MIN_PACKAGE_SIZE)
		return 0;

	DWORD value = 0;
	GET_MODBUS_READ_VALUE(startDataIdx);
	return value;
}

/**
* @brief Timout controller
* This function checks if time is running out.
* @param tick: time elapsed since the last timeout
* @param timeout: timeout value
* @retval 1 if timeout elapsed, 0 otherwise
*/
BOOLEAN TimeOutElapsed(DWORD tick, DWORD timeout){
	DWORD dly = HAL_GetTick() - tick;
	return (dly > timeout) ? AT_TRUE : AT_FALSE;
}

/**
* @brief Create data chunks
* This function creates data chunks for multiple address modbus requests.
* @param regs: Registers with information about addresses to collect
* @param length: Registers length
* @param chunks: Registers collected
* @param chunksLen: Collected registers length
* @retval None
*/
void CreateChunks(BaseRegTypeDef* regs, int length, BaseRegTypeDef* chunks, BYTE* chunksLen){

	if(length <= 0 || chunks == NULL)
		return;

	int i, j;
	BaseRegTypeDef temp = {0};
	 for (i = 0; i < length; i++) {
		for (j = i+1; j < length; j++) {
		   if(regs[i].Address > regs[j].Address) {
			   temp = regs[i];
			   regs[i] = regs[j];
			   regs[j] = temp;
		   }
		}
	}

	 //(*chunks) = (BaseRegTypeDef*)malloc(sizeof(BaseRegTypeDef));
	 (*chunksLen) = 0;

	 for(i = 0; i < length; i++){
		 for( j = 0; j < (*chunksLen); j++){
			 if(chunks[j].Address + MODBUS_MAX_REGS_IN_CHUNK > regs[i].Address + regs[i].Length){
				 chunks[j].Length = regs[i].Address - chunks[j].Address + regs[i].Length;
				 break;
			 }
		 }

		 if(j == (*chunksLen)){
			 chunks[(*chunksLen)].Address 	= regs[i].Address;
			 chunks[(*chunksLen)].Length	= regs[i].Length;
			 (*chunksLen)++;
		 }
	 }
}


