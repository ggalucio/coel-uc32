/*
 * sram.cpp
 *
 *  Created on: 26 de ago de 2024
 *      Author: COELMATIC2022
 */


#include "../Modules/Sram/sram.hpp"

#define	MAX_SIZE 256

extern void		(*pAddNumberMemory)(double* value);
extern void		(*pResetMemory)(void);
extern double	(*pReadMemory)(int id);
extern void		(*pWriteMemory)(int id, double value);
extern void 	(*pReadArraySRAM)(int id, char* array, int length);
extern void 	(*pWriteArraySRAM)(int id, char* array, int length);

/**************************************************************************************/

int nRefs = 0;

double*		doubleDataSRAM[MAX_SIZE];
double*		refs[MAX_SIZE];

void InitSRAM(){
	for (int i = 0; i < MAX_SIZE; i++)
		doubleDataSRAM[i] = (double*)(BKPSRAM_BASE + i * (0x00000008UL));

	pAddNumberMemory	= AddRefSRAM;
	pResetMemory		= ResetSRAM;
	pReadMemory			= ReadDataSRAM;
	pWriteMemory		= WriteDataSRAM;
	pReadArraySRAM		= ReadArraySRAM;
	pWriteArraySRAM		= WriteArraySRAM;
}

int GetIndex(int id){
	return id < 0 ? 0 : (id > MAX_SIZE-1 ? MAX_SIZE-1 : id);
}

double ReadDataSRAM(int id){
	return *doubleDataSRAM[GetIndex(id)];
}

void WriteDataSRAM(int id, double value){
	*doubleDataSRAM[GetIndex(id)] = value;
}

void ReadArraySRAM(int id, char* array, int length){
	if (length <= 0)
		return;

	char* ch = (char*)(doubleDataSRAM[GetIndex(id)]);
	for (int i=0; i<length; i++)
		array[i] = ch[i];
}

void WriteArraySRAM(int id, char* array, int length){
	if (length <= 0)
		return;

	char* ch = (char*)(doubleDataSRAM[GetIndex(id)]);
	for (int i=0; i<length; i++)
		ch[i] = array[i];
}

void ResetSRAM(void){
	for (int i=0; i<MAX_SIZE; i++)
		*doubleDataSRAM[i] = 0.0;
}

void AddRefSRAM(double* ref){
	if (nRefs == MAX_SIZE)
		return;

	refs[nRefs] = ref;
	*refs[nRefs] = *doubleDataSRAM[nRefs];
	nRefs++;
}

void RefreshSRAM(){
	for (int i=0; i<nRefs; i++)
		*doubleDataSRAM[i] = *refs[i];
}

void RefreshWriteMemory(){
	RefreshSRAM();
}
