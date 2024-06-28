/*
 * modbusClientManager.c
 *
 *  Created on: 22 nov 2021
 *      Author: paoloc
 */


#include "modbusClientManager.h"
#include "Components/Modbus/Client/modbusClient.h"
#include "Modules/Converter/converter.h"
#include "string.h"

/*
 * Max client number
 */
#define MODBUS_CLIENTS_NUM 3

/**
* Modbus clients array pointers
*/
ModbusClientTypeDef* pModbusClients[MODBUS_CLIENTS_NUM];

/**
* Modbus clients number
*/
BYTE nModbusClients;

/**
* When current modbus client changes, this counter increases.
*/
BYTE modbusClientsRenderCounter;

/**
* @brief Modbus clients initializer.
* This function initializes modbus clients.
*/
void InitModbusClients(void){
	InitModbusRS485Client();
	InitModbusTCPIPClient();
	InitModbusTTLClient();
	InitModbusINTClient();

	nModbusClients = 0;
	modbusClientsRenderCounter = 0;

	pModbusClients[nModbusClients++] = pModbusRS485Client;
	pModbusClients[nModbusClients++] = pModbusTCPIPClient;
	pModbusClients[nModbusClients++] = pModbusTTLClient;
}

/**
* @brief Change modbus client to manage.
* This function updates current modbus client to manage.
*/
void ModbusClientsRender(){
	ModbusClientTypeDef* modbusClient = pModbusClients[(++modbusClientsRenderCounter) % nModbusClients];
	SetModbusClient(modbusClient);
}

/**
* @brief Modbus client entry point.
* This function is the modbus client machine state entry point.
*/
void ModbusClientsRun(){
	ModbusClientCycle();
}

/**
* @brief Modbus data cleaner
* This function cleans modbus data client structure.
* @param pRead: modbus read interface
* @param pWrite: modbus write interface
* @param pReadLen: modbus read interface length
* @param pWriteLen: modbus write interface length
* @param offset: index where storing read data in RAM before cleaning.
* @param access: data client structure to clean, if read interface, write interface or both.
*/
void ClearModbus(InterfaceData* pRead, InterfaceData* pWrite, int* pReadLen, int* pWriteLen, int offset, Access access){

	uint8_t readRegNum = (*pReadLen);

	if(access == READ || access == READWRITE){
		(*pReadLen)  = 0;

		int i;
		for(i = 0; i < readRegNum; i++)
			STOREMODBUS(pRead[i].baseAddress, offset, pRead[i].value, pRead[i].length);

		memset((void*)pRead,  0, sizeof(InterfaceData) * MODBUS_DATA_SIZE);
	}

	if(access == WRITE || access == READWRITE){
		(*pWriteLen) = 0;
		memset((void*)pWrite, 0, sizeof(InterfaceData) * MODBUS_DATA_SIZE);
	}
}

/**
* @brief Modbus data cleaner
* This function decides which modbus data client structure to clean.
* @param protocol: data structure to clean.
* @param access: data client structure to clean, if read interface, write interface or both.
*/
void ClearModbusClients(Protocol protocol, Access access){
	switch(protocol){
		case MB_RS485:	ClearModbus(pModbusRS485Client->ModbusDataExch->ModbusDataRead,
				pModbusRS485Client->ModbusDataExch->ModbusDataWrite,
				&pModbusRS485Client->ModbusDataExch->ModbusDataReadLength,
				&pModbusRS485Client->ModbusDataExch->ModbusDataWriteLength,
				MODBUS_RS485_REG_ADDR,
				access);																break;
		case MB_TCPIP:	ClearModbus(pModbusTCPIPClient->ModbusDataExch->ModbusDataRead,
				pModbusTCPIPClient->ModbusDataExch->ModbusDataWrite,
				&pModbusTCPIPClient->ModbusDataExch->ModbusDataReadLength,
				&pModbusTCPIPClient->ModbusDataExch->ModbusDataWriteLength,
				MODBUS_TCPIP_REG_ADDR,
				access);																break;
		case MB_TTL:	ClearModbus(pModbusTTLClient->ModbusDataExch->ModbusDataRead,
				pModbusTTLClient->ModbusDataExch->ModbusDataWrite,
				&pModbusTTLClient->ModbusDataExch->ModbusDataReadLength,
				&pModbusTTLClient->ModbusDataExch->ModbusDataWriteLength,
				MODBUS_RS485_REG_ADDR,
				access);																break;
		case MB_INT:	ClearModbus(pModbusINTClient->ModbusDataExch->ModbusDataRead,
				pModbusINTClient->ModbusDataExch->ModbusDataWrite,
				&pModbusINTClient->ModbusDataExch->ModbusDataReadLength,
				&pModbusINTClient->ModbusDataExch->ModbusDataWriteLength,
				MODBUS_SDRAM_REG_ADDR,
				access);																break;
		default:																		break;
	}
}

/**
* @brief Modbus data adder
* This function adds new read or write interface item.
* @param pItem: interface structure to add item to.
* @param idx: interface structure length.
* @param address: item address
* @param decimal: item decimal value.
* @param command: item command value.
* @param length: item data registers number involved (if it's a floating point 32 bit this number is 2, otherwise 1).
*/
void InitModbusClientItem(InterfaceData* pItem, int idx, uint16_t address, uint8_t decimal, uint8_t command, uint8_t length){
	pItem[idx].baseAddress 	= address;
	pItem[idx].decimal 		= decimal;
	pItem[idx].command		= command;
	pItem[idx].length		= length;
	pItem[idx].value 		= 0;
}

/**
* @brief Modbus data already existing item
* This function checks if an item with same address has already be added.
* @param pItem: interface structure.
* @param nItem: interface structure length.
* @param address: item address.
* @retval: 1 if item already exists in interface structure, 0 otherwise.
*/
BOOLEAN ExistsClientItem(InterfaceData* pItem, int nItem, uint16_t address){
	if(pItem == NULL)
		return AT_FALSE;

	int i;
	for(i = 0; i < nItem; i++){
		if(pItem[i].baseAddress == address){
			return AT_TRUE;
		}
	}

	return AT_FALSE;
}

/**
* @brief Modbus data command setter.
* This function sets if modbus data must be read once or continuously.
* @param readMode: read mode to access data with.
* @retval: new command value.
*/
BYTE SetCommand(uint8_t readMode){
	BYTE cmd = 0;

	if(readMode <= 1)
		AT_SET_BIT(cmd, READ_ONCE_BIT);

	return cmd;
}

/**
* @brief Modbus value getter by address
* This function retrieves modbus read array index by register address.
* @param pItem: interface structure.
* @param nItem: interface structure length.
* @param address: register address.
* @retval: register value.
*/
WORD GetModbusClientValue(InterfaceData* pItem, int nItem, WORD address){
	if(pItem == NULL)
		return 0;

	int i;
	for(i = 0; i < nItem; i++){
		if(pItem[i].baseAddress == address){
			return pItem[i].value;
		}
	}

	return 0;
}

/**
* @brief Modbus bit reagister updater.
* This function updates single bit register value.
* @param pModbusWrite: interface write structure.
* @param pModbusRead: interface read structure.
* @param nItemWrite: interface write structure length.
* @param nItemRead: interface raad structure length.
* @param address: register address.
* @param bit: bit register value to update
* @param value: bit new value (0 or 1).
*/
void UpdateBitModbusClient(InterfaceData* pModbusWrite, InterfaceData* pModbusRead, int nItemWrite, int nItemRead, uint16_t address, uint8_t bit, uint8_t value){
	int i;
	for(i = 0; i < nItemWrite && pModbusWrite != NULL; i++){
		if(pModbusWrite[i].baseAddress == address)
		{
			uint16_t valU16 = GetModbusClientValue(pModbusRead, nItemRead, address);

			if( valU16 == 0 && AT_READ_BIT(pModbusWrite[i].command, WRITE_BY_USER_BIT))
				valU16 = pModbusWrite[i].value;

			if(value){
				AT_SET_BIT(valU16, bit);
			}
			else{
				AT_CLEAR_BIT(valU16, bit);
			}

			pModbusWrite[i].value = valU16;
			AT_SET_BIT(pModbusWrite[i].command, WRITE_INVALIDATE_BIT);
			AT_SET_BIT(pModbusWrite[i].command, WRITE_BY_USER_BIT);
			break;
		}
	}
}

/**
* @brief Modbus bit register toggler.
* This function toggles single bit register value.
* @param UpdateModbus: modbus function to invoke for update.
* @param pRead: interface read structure.
* @param rLength: interface raad structure length.
* @param address: register address.
* @param bit: bit register to update
*/
void ToggleBitModbusClient(void (*UpdateModbus)(uint16_t, double, uint8_t), InterfaceData* pRead, int rLength, uint16_t address, uint8_t bit){
	WORD value = GetModbusClientValue(pRead, rLength, address);
	AT_TOGGLE_BIT(value, bit);

	if(UpdateModbus)
		UpdateModbus(address, (double)value, _INT_);
}

/**
* @brief GUI refresher.
* This function updates incoming register values locally in interface structure
* and send command to refresh GUI.
* @param pModbusRead: interface read structure.
* @param readModbusLen: interface raad structure length.
* @param Refresh: function to invoke in order to refresh GUI.
*/
void RefreshClients(InterfaceData* pModbusRead, int readModbusLen, void (*Refresh)(uint16_t, uint32_t)){
	int i;
	for(i = 0; i < readModbusLen && pModbusRead != NULL; i++){
		BYTE cmd 			= pModbusRead[i].command;
		BYTE invalidate		= AT_READ_BIT(cmd, READ_INVALIDATE_BIT);
		BYTE readOnce 		= AT_READ_BIT(cmd, READ_ONCE_BIT);
		//BYTE guiRefresh1	= AT_READ_BIT(cmd, READ_GUI_REFRESH_BIT_1);
		BYTE guiRefresh2	= AT_READ_BIT(cmd, READ_GUI_REFRESH_BIT_2);
		WORD address		= pModbusRead[i].baseAddress;
		DWORD value			= pModbusRead[i].value;

		if(invalidate && (!readOnce || !guiRefresh2))
		{
			Refresh(address, value);
			AT_SET_BIT(pModbusRead[i].command, READ_GUI_REFRESH_BIT_1);
			AT_CLEAR_BIT(pModbusRead[i].command, READ_INVALIDATE_BIT);

			//if(guiRefresh1 && value != 0)
			AT_SET_BIT(pModbusRead[i].command, READ_GUI_REFRESH_BIT_2);
		}
	}
}

/**
* @brief Modbus register value retriever.
* This function retrieves some modbus register values starting from specific address.
* and send command to refresh GUI.
* @param pModbusRead: interface read structure.
* @param rLength: interface raad structure length.
* @param address: register address.
* @param len: register number to get.
* @param pData: pointer to fill with register values.
*/
void ReadModbusRegisters(InterfaceData* pModbusRead, int rLength, uint16_t address, uint8_t len, uint16_t* pData){
	int i;
	for(i = 0; i < len; i++){
		pData[i] = GetModbusClientValue(pModbusRead, rLength, address + i);
	}
}
