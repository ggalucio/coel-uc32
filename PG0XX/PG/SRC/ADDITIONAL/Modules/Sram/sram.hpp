/*
 * sram.hpp
 *
 *  Created on: 26 de ago de 2024
 *      Author: COELMATIC2022
 */

#ifndef MODULES_SRAM_SRAM_HPP_
#define MODULES_SRAM_SRAM_HPP_

/* ===== VARIABLES SIZE ======
 *
 *	TYPE		SIZE
 *	--------------------
 * 	char		(0x01UL)
 *	byte		(0x01UL)
 *	int8_t		(0x01UL)
 *	int16_t		(0x02UL)
 *	int32_t		(0x04UL)
 *	float		(0x04UL)
 *	int64_t		(0x08UL)
 *	double		(0x08UL)
 *	long double	(0x10UL)
 *
 * ===========================
 * */

#include <stdint.h>

// BASE ADDRESS FOR SRAM
#define BKPSRAM_BASE	0x40024000UL		// to x256 of type double.

/**************************************************************************************/

extern "C" void RefreshWriteMemory(void);
void RefreshWriteMemory(void);

void InitSRAM(void);

void AddRefSRAM(double* ref);
double ReadDataSRAM(int id);
void WriteDataSRAM(int id, double value);
void ReadArraySRAM(int id, char* array, int length);
void WriteArraySRAM(int id, char* array, int length);
void ResetSRAM(void);

#endif /* MODULES_SRAM_SRAM_HPP_ */
