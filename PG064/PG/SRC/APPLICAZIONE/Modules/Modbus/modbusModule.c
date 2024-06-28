/*
 * modbusModule.c
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#include "modbusModule.h"

#include <Components/Modbus/Server/modbusServerManager.h>
#include <Components/Modbus/Client/modbusClientManager.h>

#include "Modules/Converter/converter.h"
#include "../TS/tsModule.h"
#include "../Time/TimeModule.h"
#include "string.h"
#include "stdlib.h"

// Add items to write
void AddModbusRS485WriteItem(uint16_t address, uint8_t decimal, uint8_t len);
void AddModbusTCPIPWriteItem(uint16_t address, uint8_t decimal, uint8_t len);
void AddModbusTTLWriteItem(uint16_t address, uint8_t decimal, uint8_t len);
void AddModbusINTWriteItem(uint16_t address, uint8_t decimal, uint8_t len);

// Add items to read
void AddModbusRS485ReadItem(uint16_t address, uint8_t decimal, uint8_t readMode, uint8_t len);
void AddModbusTCPIPReadItem(uint16_t address, uint8_t decimal, uint8_t readMode, uint8_t len);
void AddModbusTTLReadItem(uint16_t address, uint8_t decimal, uint8_t readMode, uint8_t len);
void AddModbusINTReadItem(uint16_t address, uint8_t decimal, uint8_t readMode, uint8_t len);

// Toggle bits
void ToggleBitModbusRS485(uint16_t address, uint8_t bit);
void ToggleBitModbusTCPIP(uint16_t address, uint8_t bit);
void ToggleBitModbusTTL(uint16_t address, uint8_t bit);
void ToggleBitModbusINT(uint16_t address, uint8_t bit);

// Update Modbus
void UpdateModbusRS485(uint16_t address, double value, DataType dataType);
void UpdateModbusTCPIP(uint16_t address, double value, uint8_t dataType);
void UpdateModbusTTL(uint16_t address, double value, uint8_t dataType);
void UpdateModbusINT(uint16_t address, double value, uint8_t dataType);

// Update Bits
void UpdateBitModbusRS485(uint16_t address, uint8_t bit, uint8_t value);
void UpdateBitModbusTCPIP(uint16_t address, uint8_t bit, uint8_t value);
void UpdateBitModbusTTL(uint16_t address, uint8_t bit, uint8_t value);
void UpdateBitModbusINT(uint16_t address, uint8_t bit, uint8_t value);

// Refresh
void RefreshModbusRS485(void);
void RefreshModbusTCPIP(void);
void RefreshModbusTTL(void);
void RefreshModbusINT(void);

// Blink images
uint8_t BlinkingImageModbusRS485(uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, uint32_t* currTick);
uint8_t BlinkingImageModbusTCPIP(uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, uint32_t* currTick);
uint8_t BlinkingImageModbusTTL(uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, uint32_t* currTick);

void AddBitDlyItemRS485(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
void AddBitDlyItemTCPIP(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
void AddBitDlyItemTTL(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);

void AddWordDlyItemRS485(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
void AddWordDlyItemTCPIP(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
void AddWordDlyItemTTL(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);

// Read modbus registers
void ReadModbusRegistersRS485(uint16_t, uint8_t, uint16_t*);
void ReadModbusRegistersTCPIP(uint16_t, uint8_t, uint16_t*);
void ReadModbusRegistersTTL(uint16_t, uint8_t, uint16_t*);

uint8_t TimeOutRS485CommElapsed(uint32_t);
uint8_t TimeOutTCPIPCommElapsed(uint32_t);
uint8_t TimeOutTTLCommElapsed(uint32_t);

void SetRS485TimerCmd(void);
void SetTCPIPTimerCmd(void);
void SetTTLTimerCmd(void);

void SetModeRS485As(uint8_t, uint32_t);
void SetModeTCPIPAs(uint8_t, uint32_t);
void SetModeTTLAs(uint8_t, uint32_t);

void RefreshDlyItems();

// CLear
void ClearModbusRS485();
void ClearModbusTCPIP();
void ClearModbusTTL();
void ClearModbusINT();

// Clear Writes
void ClearWritesModbusRS485();
void ClearWritesModbusTCPIP();
void ClearWritesModbusTTL();

ModbusModuleTypDef modbusRS485Module = {
		AddModbusRS485ReadItem,
		AddModbusRS485WriteItem,
		ClearModbusRS485,
		ClearWritesModbusRS485,
		UpdateModbusRS485,
		UpdateBitModbusRS485,
		ToggleBitModbusRS485,
		RefreshModbusRS485,
		NULL,
		BlinkingImageModbusRS485,
		AddBitDlyItemRS485,
		AddWordDlyItemRS485,
		ReadModbusRegistersRS485,
		TimeOutRS485CommElapsed,
		SetRS485TimerCmd,
		SetModeRS485As
};

ModbusModuleTypDef modbusTCPIPModule = {
		AddModbusTCPIPReadItem,
		AddModbusTCPIPWriteItem,
		ClearModbusTCPIP,
		ClearWritesModbusTCPIP,
		UpdateModbusTCPIP,
		UpdateBitModbusTCPIP,
		ToggleBitModbusTCPIP,
		RefreshModbusTCPIP,
		NULL,
		BlinkingImageModbusTCPIP,
		AddBitDlyItemTCPIP,
		AddWordDlyItemTCPIP,
		ReadModbusRegistersTCPIP,
		TimeOutTCPIPCommElapsed,
		SetTCPIPTimerCmd,
		SetModeTCPIPAs
};

ModbusModuleTypDef modbusTTLModule = {
		AddModbusTTLReadItem,
		AddModbusTTLWriteItem,
		ClearModbusTTL,
		ClearWritesModbusTTL,
		UpdateModbusTTL,
		UpdateBitModbusTTL,
		ToggleBitModbusTTL,
		RefreshModbusTTL,
		NULL,
		BlinkingImageModbusTTL,
		AddBitDlyItemTTL,
		AddWordDlyItemTTL,
		ReadModbusRegistersTTL,
		TimeOutTTLCommElapsed,
		SetTTLTimerCmd,
		SetModeTTLAs
};

ModbusModuleTypDef modbusINTModule = {
		AddModbusINTReadItem,
		AddModbusINTWriteItem,
		ClearModbusINT,
		NULL,
		UpdateModbusINT,
		UpdateBitModbusINT,
		ToggleBitModbusINT,
		RefreshModbusINT,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL
};

ModuleTypDef   modbusClientCycleModule;
ModuleTypDef   modbusServerCycleModule;

void UpdateModbusClient(InterfaceData* pModbusWrite, int wLength, uint16_t address, double value, uint8_t dataType){
	int i;
	for(i = 0; i < wLength && pModbusWrite != NULL; i++){
		if(pModbusWrite[i].baseAddress == address)
		{
			DWORD intValue = 0;
			BYTE  nWords = 0;
			ConvertData(dataType, value, pModbusWrite[i].decimal, &intValue, &nWords);
			pModbusWrite[i].value = intValue;
			AT_SET_BIT(pModbusWrite[i].command, WRITE_INVALIDATE_BIT);
			AT_SET_BIT(pModbusWrite[i].command, WRITE_BY_USER_BIT);
			//pModbusRS485Write[i].command |= (nWords << 6);
			break;
		}
	}
}

void RefreshDlyItems(){
	if(pModbusBitDly){
		if(TsTimeoutElapsed(pModbusBitDly->dly) && pModbusBitDly->UpdateBitModbus){
			pModbusBitDly->UpdateBitModbus(pModbusBitDly->address, pModbusBitDly->bit, pModbusBitDly->value);
			free(pModbusBitDly);
			pModbusBitDly = NULL;
		}
	}

	if(pModbusWordDly){
		if(TsTimeoutElapsed(pModbusWordDly->dly) && pModbusBitDly->UpdateBitModbus){
			pModbusBitDly->UpdateBitModbus(pModbusWordDly->address, (double)pModbusWordDly->value, pModbusWordDly->dataType);
			free(pModbusWordDly);
			pModbusWordDly = NULL;
		}
	}
}

void AddDlyItem(ModbusDataDlyTypedef** pModbusDly, uint16_t addr, uint8_t bit, uint16_t value, uint16_t delay, uint8_t dt, void (*pUpdater)(uint16_t, uint8_t, uint8_t)){
	if((*pModbusDly)){
		free((*pModbusDly));
		(*pModbusDly) = NULL;
	}

	(*pModbusDly) = (ModbusDataDlyTypedef*)malloc(sizeof(ModbusDataDlyTypedef));
	(*pModbusDly)->address 			= addr;
	(*pModbusDly)->bit 				= bit;
	(*pModbusDly)->dly 				= delay;
	(*pModbusDly)->value 			= value;
	(*pModbusDly)->dataType 		= dt;
	(*pModbusDly)->UpdateBitModbus 	= pUpdater;
}

void AddBitDlyItemRS485(uint16_t addr, uint8_t bit, uint16_t value, uint16_t delay, uint8_t dt)
{
	AddDlyItem(&pModbusBitDly, addr, bit, value, delay, dt, UpdateBitModbusRS485);
}

void AddBitDlyItemTCPIP(uint16_t addr, uint8_t bit, uint16_t value, uint16_t delay, uint8_t dt)
{
	AddDlyItem(&pModbusBitDly, addr, bit, value, delay, dt, UpdateBitModbusTCPIP);
}

void AddBitDlyItemTTL(uint16_t addr, uint8_t bit, uint16_t value, uint16_t delay, uint8_t dt)
{
	AddDlyItem(&pModbusBitDly, addr, bit, value, delay, dt, UpdateBitModbusTTL);
}

void AddWordDlyItemRS485(uint16_t addr, uint8_t bit, uint16_t value, uint16_t delay, uint8_t dt)
{
	AddDlyItem(&pModbusWordDly, addr, bit, value, delay, dt, UpdateBitModbusRS485);
}

void AddWordDlyItemTCPIP(uint16_t addr, uint8_t bit, uint16_t value, uint16_t delay, uint8_t dt)
{
	AddDlyItem(&pModbusWordDly, addr, bit, value, delay, dt, UpdateBitModbusTCPIP);
}

void AddWordDlyItemTTL(uint16_t addr, uint8_t bit, uint16_t value, uint16_t delay, uint8_t dt)
{
	AddDlyItem(&pModbusWordDly, addr, bit, value, delay, dt, UpdateBitModbusTTL);
}

void UpdateBitModbusRS485(uint16_t address, uint8_t bit, uint8_t value){
	UpdateBitModbusClient(pModbusRS485Client->ModbusDataExch->ModbusDataWrite, pModbusRS485Client->ModbusDataExch->ModbusDataRead,
			pModbusRS485Client->ModbusDataExch->ModbusDataWriteLength, pModbusRS485Client->ModbusDataExch->ModbusDataReadLength, address, bit, value);
}

void UpdateBitModbusTCPIP(uint16_t address, uint8_t bit, uint8_t value){
	UpdateBitModbusClient(pModbusTCPIPClient->ModbusDataExch->ModbusDataWrite, pModbusTCPIPClient->ModbusDataExch->ModbusDataRead,
			pModbusTCPIPClient->ModbusDataExch->ModbusDataWriteLength, pModbusTCPIPClient->ModbusDataExch->ModbusDataReadLength, address, bit, value);
}

void UpdateBitModbusTTL(uint16_t address, uint8_t bit, uint8_t value){
	UpdateBitModbusClient(pModbusTTLClient->ModbusDataExch->ModbusDataWrite, pModbusTTLClient->ModbusDataExch->ModbusDataRead,
			pModbusTTLClient->ModbusDataExch->ModbusDataWriteLength, pModbusTTLClient->ModbusDataExch->ModbusDataReadLength, address, bit, value);
}

void UpdateBitModbusINT(uint16_t address, uint8_t bit, uint8_t value){
	UpdateBitModbusClient(pModbusINTClient->ModbusDataExch->ModbusDataWrite, pModbusINTClient->ModbusDataExch->ModbusDataRead,
			pModbusINTClient->ModbusDataExch->ModbusDataWriteLength, pModbusINTClient->ModbusDataExch->ModbusDataReadLength, address, bit, value);

	int i;
	for(i = 0; i < pModbusINTClient->ModbusDataExch->ModbusDataWriteLength; i++){
		if(pModbusINTClient->ModbusDataExch->ModbusDataWrite[i].baseAddress == address){
			AT_CLEAR_BIT(pModbusINTClient->ModbusDataExch->ModbusDataWrite[i].command, WRITE_INVALIDATE_BIT);
			AT_CLEAR_BIT(pModbusINTClient->ModbusDataExch->ModbusDataWrite[i].command, WRITE_BY_USER_BIT);
			STOREMODBUS(address, MODBUS_SDRAM_REG_ADDR, pModbusINTClient->ModbusDataExch->ModbusDataWrite[i].value, pModbusINTClient->ModbusDataExch->ModbusDataWrite[i].length);
		}
	}

	RefreshModbusINT();
}

uint8_t BlinkingImageModbus(InterfaceData* pModbusRead, int rLength, uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, uint32_t* currTick){
	int i;
	for(i = 0; i < rLength && pModbusRead != NULL; i++){
		if(pModbusRead[i].baseAddress == address){
			uint8_t bitVal = AT_READ_BIT(pModbusRead[i].value, bit);

			if(bitVal == value && Elapsed(currTick, ms)){
				return SWITCH_ON;
			}
			else{
				return SWITCH_OFF;
			}
		}
	}

	return SWITCH_OFF;
}

uint8_t BlinkingImageModbusRS485(uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, uint32_t* currTick){
	return BlinkingImageModbus(pModbusRS485Client->ModbusDataExch->ModbusDataRead, pModbusRS485Client->ModbusDataExch->ModbusDataReadLength,
			address, bit, value, ms, currTick);
}

uint8_t BlinkingImageModbusTCPIP(uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, uint32_t* currTick){
	return BlinkingImageModbus(pModbusTCPIPClient->ModbusDataExch->ModbusDataRead, pModbusTCPIPClient->ModbusDataExch->ModbusDataReadLength,
				address, bit, value, ms, currTick);
}

uint8_t BlinkingImageModbusTTL(uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, uint32_t* currTick){
	return BlinkingImageModbus(pModbusTTLClient->ModbusDataExch->ModbusDataRead, pModbusTTLClient->ModbusDataExch->ModbusDataReadLength,
				address, bit, value, ms, currTick);
}

void UpdateModbusRS485(uint16_t address, double value, uint8_t dataType){
	UpdateModbusClient(pModbusRS485Client->ModbusDataExch->ModbusDataWrite, pModbusRS485Client->ModbusDataExch->ModbusDataWriteLength, address, value, dataType);
}

void UpdateModbusTCPIP(uint16_t address, double value, uint8_t dataType){
	UpdateModbusClient(pModbusTCPIPClient->ModbusDataExch->ModbusDataWrite, pModbusTCPIPClient->ModbusDataExch->ModbusDataWriteLength, address, value, dataType);
}

void UpdateModbusTTL(uint16_t address, double value, uint8_t dataType){
	UpdateModbusClient(pModbusTTLClient->ModbusDataExch->ModbusDataWrite, pModbusTTLClient->ModbusDataExch->ModbusDataWriteLength, address, value, dataType);
}

void UpdateModbusINT(uint16_t address, double value, uint8_t dataType){
	UpdateModbusClient(pModbusINTClient->ModbusDataExch->ModbusDataWrite, pModbusINTClient->ModbusDataExch->ModbusDataWriteLength, address, value, dataType);

	int i;
	for(i = 0; i < pModbusINTClient->ModbusDataExch->ModbusDataWriteLength; i++){
		if(pModbusINTClient->ModbusDataExch->ModbusDataWrite[i].baseAddress == address){
			AT_CLEAR_BIT(pModbusINTClient->ModbusDataExch->ModbusDataWrite[i].command, WRITE_INVALIDATE_BIT);
			AT_CLEAR_BIT(pModbusINTClient->ModbusDataExch->ModbusDataWrite[i].command, WRITE_BY_USER_BIT);
			STOREMODBUS(address, MODBUS_SDRAM_REG_ADDR, pModbusINTClient->ModbusDataExch->ModbusDataWrite[i].value, pModbusINTClient->ModbusDataExch->ModbusDataWrite[i].length);
		}
	}

	RefreshModbusINT();
}

void AddModbusRS485ReadItem(uint16_t address, uint8_t decimal, uint8_t readMode, uint8_t len){
	if(ExistsClientItem(pModbusRS485Client->ModbusDataExch->ModbusDataRead, pModbusRS485Client->ModbusDataExch->ModbusDataReadLength, address) ||
			!pModbusRS485Module)
		return;

	DWORD value = 0;
	uint8_t command = SetCommand(readMode);
	InitModbusClientItem(pModbusRS485Client->ModbusDataExch->ModbusDataRead, pModbusRS485Client->ModbusDataExch->ModbusDataReadLength, address, decimal, command, len);
	READMODBUS(address, MODBUS_RS485_REG_ADDR, len);
	pModbusRS485Module->Refresh(address, value);
	pModbusRS485Client->ModbusDataExch->ModbusDataReadLength++;
}

void AddModbusRS485WriteItem(uint16_t address, uint8_t decimal, uint8_t len){
	if(ExistsClientItem(pModbusRS485Client->ModbusDataExch->ModbusDataWrite, pModbusRS485Client->ModbusDataExch->ModbusDataWriteLength, address))
		return;

	InitModbusClientItem(pModbusRS485Client->ModbusDataExch->ModbusDataWrite, pModbusRS485Client->ModbusDataExch->ModbusDataWriteLength, address, decimal, 0, len);
	pModbusRS485Client->ModbusDataExch->ModbusDataWriteLength++;
}

void AddModbusTCPIPReadItem(uint16_t address, uint8_t decimal, uint8_t readMode, uint8_t len){
	if(ExistsClientItem(pModbusTCPIPClient->ModbusDataExch->ModbusDataRead, pModbusTCPIPClient->ModbusDataExch->ModbusDataReadLength, address) || !pModbusTCPIPModule)
		return;

	DWORD value = 0;
	uint8_t command = SetCommand(readMode);
	InitModbusClientItem(pModbusTCPIPClient->ModbusDataExch->ModbusDataRead, pModbusTCPIPClient->ModbusDataExch->ModbusDataReadLength, address, decimal, command, len);
	READMODBUS(address, MODBUS_TCPIP_REG_ADDR, len);
	pModbusTCPIPModule->Refresh(address, value);
	pModbusTCPIPClient->ModbusDataExch->ModbusDataReadLength++;
}

void AddModbusTTLReadItem(uint16_t address, uint8_t decimal, uint8_t readMode, uint8_t len){
	if(ExistsClientItem(pModbusTTLClient->ModbusDataExch->ModbusDataRead, pModbusTTLClient->ModbusDataExch->ModbusDataReadLength, address) || !pModbusTTLModule)
		return;

	DWORD value = 0;
	uint8_t command = SetCommand(readMode);
	InitModbusClientItem(pModbusTTLClient->ModbusDataExch->ModbusDataRead, pModbusTTLClient->ModbusDataExch->ModbusDataReadLength, address, decimal, command, len);
	READMODBUS(address, MODBUS_RS485_REG_ADDR, len);
	pModbusTTLModule->Refresh(address, value);
	pModbusTTLClient->ModbusDataExch->ModbusDataReadLength++;
}

void AddModbusINTReadItem(uint16_t address, uint8_t decimal, uint8_t readMode, uint8_t len){
	if(ExistsClientItem(pModbusINTClient->ModbusDataExch->ModbusDataRead, pModbusINTClient->ModbusDataExch->ModbusDataReadLength, address) || !pModbusINTModule)
		return;

	DWORD value = 0;
	uint8_t command = SetCommand(readMode);
	InitModbusClientItem(pModbusINTClient->ModbusDataExch->ModbusDataRead, pModbusINTClient->ModbusDataExch->ModbusDataReadLength, address, decimal, command, len);
	READMODBUS(address, MODBUS_SDRAM_REG_ADDR, len);
	pModbusINTModule->Refresh(address, value);
	pModbusINTClient->ModbusDataExch->ModbusDataReadLength++;
}

void AddModbusTCPIPWriteItem(uint16_t address, uint8_t decimal, uint8_t len){
	if(ExistsClientItem(pModbusTCPIPClient->ModbusDataExch->ModbusDataWrite, pModbusTCPIPClient->ModbusDataExch->ModbusDataWriteLength, address))
			return;

	InitModbusClientItem(pModbusTCPIPClient->ModbusDataExch->ModbusDataWrite, pModbusTCPIPClient->ModbusDataExch->ModbusDataWriteLength, address, decimal, 0, len);
	pModbusTCPIPClient->ModbusDataExch->ModbusDataWriteLength++;
}

void AddModbusTTLWriteItem(uint16_t address, uint8_t decimal, uint8_t len){
	if(ExistsClientItem(pModbusTTLClient->ModbusDataExch->ModbusDataWrite, pModbusTTLClient->ModbusDataExch->ModbusDataWriteLength, address))
			return;

	InitModbusClientItem(pModbusTTLClient->ModbusDataExch->ModbusDataWrite, pModbusTTLClient->ModbusDataExch->ModbusDataWriteLength, address, decimal, 0, len);
	pModbusTTLClient->ModbusDataExch->ModbusDataWriteLength++;
}

void AddModbusINTWriteItem(uint16_t address, uint8_t decimal, uint8_t len){
	if(ExistsClientItem(pModbusINTClient->ModbusDataExch->ModbusDataWrite, pModbusINTClient->ModbusDataExch->ModbusDataWriteLength, address))
			return;

	InitModbusClientItem(pModbusINTClient->ModbusDataExch->ModbusDataWrite, pModbusINTClient->ModbusDataExch->ModbusDataWriteLength, address, decimal, 0, len);
	pModbusINTClient->ModbusDataExch->ModbusDataWriteLength++;
}

void ClearWritesModbusRS485(){
	ClearModbusClients(MB_RS485, WRITE);
}

void ClearWritesModbusTCPIP(){
	ClearModbusClients(MB_TCPIP, WRITE);
}

void ClearWritesModbusTTL(){
	ClearModbusClients(MB_TTL, WRITE);
}

void ClearModbusRS485(){
	ClearModbusClients(MB_RS485, READWRITE);
}

void ClearModbusTCPIP(){
	ClearModbusClients(MB_TCPIP, READWRITE);
}

void ClearModbusTTL(){
	ClearModbusClients(MB_TTL, READWRITE);
}

void ClearModbusINT(){
	ClearModbusClients(MB_INT, READWRITE);
}

void ToggleBitModbusRS485(uint16_t address, uint8_t bit){
	ToggleBitModbusClient(UpdateModbusRS485, pModbusRS485Client->ModbusDataExch->ModbusDataRead,
			pModbusRS485Client->ModbusDataExch->ModbusDataReadLength, address, bit);
}

void ToggleBitModbusTCPIP(uint16_t address, uint8_t bit){
	ToggleBitModbusClient(UpdateModbusTCPIP, pModbusTCPIPClient->ModbusDataExch->ModbusDataRead,
				pModbusTCPIPClient->ModbusDataExch->ModbusDataReadLength, address, bit);
}

void ToggleBitModbusTTL(uint16_t address, uint8_t bit){
	ToggleBitModbusClient(UpdateModbusTTL, pModbusTTLClient->ModbusDataExch->ModbusDataRead,
			pModbusTTLClient->ModbusDataExch->ModbusDataReadLength, address, bit);
}

void ToggleBitModbusINT(uint16_t address, uint8_t bit){
	ToggleBitModbusClient(UpdateModbusINT, pModbusINTClient->ModbusDataExch->ModbusDataRead,
			pModbusINTClient->ModbusDataExch->ModbusDataReadLength, address, bit);
}

void ReadModbusRegistersRS485(uint16_t address, uint8_t len, uint16_t* pData){
	ReadModbusRegisters(pModbusRS485Client->ModbusDataExch->ModbusDataRead, pModbusRS485Client->ModbusDataExch->ModbusDataReadLength, address, len, pData);
}

void ReadModbusRegistersTCPIP(uint16_t address, uint8_t len, uint16_t* pData){
	ReadModbusRegisters(pModbusTCPIPClient->ModbusDataExch->ModbusDataRead, pModbusTCPIPClient->ModbusDataExch->ModbusDataReadLength, address, len, pData);
}

void ReadModbusRegistersTTL(uint16_t address, uint8_t len, uint16_t* pData){
	ReadModbusRegisters(pModbusTTLClient->ModbusDataExch->ModbusDataRead, pModbusTTLClient->ModbusDataExch->ModbusDataReadLength, address, len, pData);
}

void RefreshModbusRS485(){
	RefreshClients(pModbusRS485Client->ModbusDataExch->ModbusDataRead, pModbusRS485Client->ModbusDataExch->ModbusDataReadLength, pModbusRS485Module->Refresh);
	RefreshDlyItems();
}

void RefreshModbusTCPIP(){
	RefreshClients(pModbusTCPIPClient->ModbusDataExch->ModbusDataRead, pModbusTCPIPClient->ModbusDataExch->ModbusDataReadLength, pModbusTCPIPModule->Refresh);
	RefreshDlyItems();
}

void RefreshModbusTTL(){
	RefreshClients(pModbusTTLClient->ModbusDataExch->ModbusDataRead, pModbusTTLClient->ModbusDataExch->ModbusDataReadLength, pModbusTTLModule->Refresh);
	RefreshDlyItems();
}

void RefreshModbusINT(){

	int i;
	for(i = 0; i < pModbusINTClient->ModbusDataExch->ModbusDataReadLength; i++){
		DWORD value = 0;
		READMODBUS(pModbusINTClient->ModbusDataExch->ModbusDataRead[i].baseAddress, MODBUS_SDRAM_REG_ADDR, pModbusINTClient->ModbusDataExch->ModbusDataRead[i].length);
		if(value != pModbusINTClient->ModbusDataExch->ModbusDataRead[i].value){
			pModbusINTClient->ModbusDataExch->ModbusDataRead[i].value = value;
			AT_SET_BIT(pModbusINTClient->ModbusDataExch->ModbusDataRead[i].command, READ_INVALIDATE_BIT);
		}
	}

	RefreshClients(pModbusINTClient->ModbusDataExch->ModbusDataRead, pModbusINTClient->ModbusDataExch->ModbusDataReadLength, pModbusINTModule->Refresh);
}

uint8_t TimeOutRS485CommElapsed(uint32_t ms){
	return ms < MODBUS_RS485_TIMER_ADDR && READ_MODBUS_RS485_TMR_CMD() == 0;
}

uint8_t TimeOutTCPIPCommElapsed(uint32_t ms){
	return ms < MODBUS_TCPIP_TIMER_ADDR && READ_MODBUS_TCPIP_TMR_CMD() == 0;
}

uint8_t TimeOutTTLCommElapsed(uint32_t ms){
	return ms < MODBUS_TTL_TIMER_ADDR && READ_MODBUS_TTL_TMR_CMD() == 0;
}

void SetRS485TimerCmd(){
	SET_MODBUS_RS485_TMR_CMD();
}

void SetTCPIPTimerCmd(){
	SET_MODBUS_TCPIP_TMR_CMD();
}

void SetTTLTimerCmd(){
	SET_MODBUS_TTL_TMR_CMD();
}

void SetModeRS485As(uint8_t mode, uint32_t baud){

	MODBUS_RS485_BAUDRATE = baud;

	// Resetto i registri
	memset((uint32_t*)MODBUS_RS485_REG_ADDR, 0, sizeof(uint8_t) * MODBUS_REG_SIZE);

	if(mode){
		// Master mode
		SET_MODBUS_RS485_OPMODE_MASTER();
		InitModbusRS485Server();
	}
	else{
		// Slave mode
		SET_MODBUS_RS485_OPMODE_SLAVE();
		InitModbusRS485Client();
	}
}

void SetModeTCPIPAs(uint8_t mode, uint32_t baud){

	// Resetto i registri
	memset((uint32_t*)MODBUS_RS485_REG_ADDR, 0, sizeof(uint8_t) * MODBUS_REG_SIZE);

	if(mode){
		// Master mode
		SET_MODBUS_TCPIP_OPMODE_MASTER();
		InitModbusTCPIPServer();
	}
	else{
		// Slave mode
		SET_MODBUS_TCPIP_OPMODE_SLAVE();
		InitModbusTCPIPClient();
	}
}

void SetModeTTLAs(uint8_t mode, uint32_t baud){

	MODBUS_TTL_BAUDRATE = baud;

	// Resetto i registri
	memset((uint32_t*)MODBUS_RS485_REG_ADDR, 0, sizeof(uint8_t) * MODBUS_REG_SIZE);

	if(mode){
		// Master mode
		SET_MODBUS_TTL_OPMODE_MASTER();
		InitModbusTTLServer();
	}
	else{
		// Slave mode
		SET_MODBUS_TTL_OPMODE_SLAVE();
		InitModbusTTLClient();
	}
}

void InitModbusModule(){
	InitModbusServers();
	InitModbusClients();

	pModbusRS485Module				= &modbusRS485Module;
	pModbusTCPIPModule 				= &modbusTCPIPModule;
	pModbusTTLModule 				= &modbusTTLModule;
	pModbusINTModule				= &modbusINTModule;

	// Parto come SLAVE
	SetModeRS485As(SLAVE, 19200);
	SetModeTCPIPAs(SLAVE, 19200);
	SetModeTTLAs(SLAVE, 19200);

	memset((uint8_t*)MODBUS_SDRAM_REG_ADDR, 0, sizeof(uint8_t) * MODBUS_REG_SIZE);

	modbusClientCycleModule.Run		= ModbusClientsRun;
	modbusClientCycleModule.Update 	= ModbusClientsRender;
	pModbusClientCycleModule 		= &modbusClientCycleModule;


	modbusServerCycleModule.Update  = ModbusServersRender;
	modbusServerCycleModule.Run  	= ModbusServersRun;
	pModbusServerCycleModule 		= &modbusServerCycleModule;
}
