/*
 * modbusModule.h
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#ifndef MODBUS_MODBUSMODULE_H_
#define MODBUS_MODBUSMODULE_H_

#include "stdint.h"
#include "../Utils/moduleUtil.h"
#include "Module/Inc/enumerators.h"

typedef struct {
	void (*AddReadItem)(uint16_t, uint8_t, 	uint8_t, uint8_t);
	void (*AddWriteItem)(uint16_t, uint8_t, 	uint8_t);
	void (*Clear)(void);
	void (*ClearWrites)(void);
	void (*Update)(uint16_t, double, DataType);
	void (*UpdateBit)(uint16_t, uint8_t, uint8_t);
	void (*ToggleBit)(uint16_t, uint8_t);
	void (*SearchUpdates)(void);
	void (*Refresh)(uint16_t, uint32_t);
	uint8_t (*BlinkImage)(uint16_t, uint8_t, uint8_t, uint32_t, uint32_t*);
	void (*AddBitDlyItem)(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
	void (*AddWordDlyItem)(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
	void (*ReadModbusRegisters)(uint16_t, uint8_t, uint16_t*);
	uint8_t (*TimeOutCommElapsed)(uint32_t);
	void (*SetTimerCmd)(void);
	void (*SetModeAs)(uint8_t, uint32_t);
}ModbusModuleTypDef;

typedef struct{
	uint16_t address;
	uint8_t  bit;
	uint16_t value;
	uint16_t dly;
	uint8_t  dataType;
	void (*UpdateBitModbus)(uint16_t, uint8_t, uint8_t);
}ModbusDataDlyTypedef;

void InitModbusModule();

ModbusModuleTypDef 		*pModbusRS485Module;
ModbusModuleTypDef 		*pModbusTCPIPModule;
ModbusModuleTypDef 		*pModbusTTLModule;
ModbusModuleTypDef 		*pModbusINTModule;
ModbusDataDlyTypedef	*pModbusBitDly;
ModbusDataDlyTypedef	*pModbusWordDly;
ModuleTypDef       		*pModbusClientCycleModule;
ModuleTypDef       		*pModbusServerCycleModule;

#endif /* MODBUS_MODBUSMODULE_H_ */
