/*
 * ModbusTools.cpp
 *
 *  Created on: 26 de set de 2024
 *      Author: COELMATIC2022
 */

#include <touchgfx/Unicode.hpp>

#include <AT_module.hpp>
#include <AT_module_ext.hpp>
#include <Modules/Ext/Extension.hpp>

#define GRAPH_ITEM_SIZE		25

typedef struct{
	touchgfx::Unicode::UnicodeChar buffer[10];
	uint16_t address;
}
BufferTextArea;
BufferTextArea vectorBufferTextArea[GRAPH_ITEM_SIZE];
int nCount = 0;

touchgfx::Unicode::UnicodeChar bufferReadJobName[20];

void ClearArray(){
	nCount = 0;
}

int ContainAddress(uint16_t address){
	for (int i=0; i<nCount; i++){
		if (vectorBufferTextArea[i].address == address)
			return i;
	}
	return -1;
}

/********************************************* MODBUS RS485 ******************************************************************/

void ReadWriteModbus485(uint16_t address, uint8_t decimal, DataType dataType, ReadMode readMode){
	if (nCount == GRAPH_ITEM_SIZE || ContainAddress(address) != -1)
		return;

	ReadWriteModbus485(NULL, vectorBufferTextArea[nCount].buffer, address, decimal, dataType, readMode);
	vectorBufferTextArea[nCount].address = address;
	nCount ++;
}

double ReadBufferModbus485(uint16_t address){
	int index = ContainAddress(address);
	if (index != -1){
		return GetNumberTextArea(vectorBufferTextArea[index].buffer);
	}
	return 0.0;
}

/*****************************************************************************************************************************/

/*************************************************** JOB *********************************************************************/

void AddJob(int idx, DataType dataType, uint8_t decimal){
	if (nCount == GRAPH_ITEM_SIZE || ContainAddress(idx) != -1)
		return;

	AddJob(NULL, vectorBufferTextArea[nCount].buffer, idx, dataType, decimal);
	vectorBufferTextArea[nCount].address = idx;
	nCount ++;
}

double ReadJob(int idx){
	return ReadBufferModbus485(idx);
}

/*****************************************************************************************************************************/

