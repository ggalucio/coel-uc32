/*
 * modbusClientManager.h
 *
 *  Created on: 22 nov 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_CLIENT_MODBUSCLIENTMANAGER_H_
#define COMPONENTS_MODBUS_CLIENT_MODBUSCLIENTMANAGER_H_

#include <Components/Modbus/RS485/modbusClientRS485.h>
#include "Components/Modbus/TCPIP/modbusClientTCPIP.h"
#include "Components/Modbus/TTL/modbusClientTTL.h"
#include "Components/Modbus/INT/modbusClientINT.h"
#include "GFX/Module/Inc/enumerators.h"

void InitModbusClients(void);
void ModbusClientsRender(void);
void ModbusClientsRun();
void ClearModbusClients(Protocol, Access);
void InitModbusClientItem(InterfaceData*, int, uint16_t, uint8_t, uint8_t, uint8_t);
void UpdateBitModbusClient(InterfaceData*, InterfaceData*, int, int, uint16_t, uint8_t, uint8_t);
BOOLEAN ExistsClientItem(InterfaceData*, int, uint16_t);
BYTE SetCommand(uint8_t);
void ToggleBitModbusClient(void (*UpdateModbus)(uint16_t, double, uint8_t), InterfaceData* pRead, int rLength, uint16_t address, uint8_t bit);
void RefreshClients(InterfaceData* pModbusRead, int readModbusLen, void (*Refresh)(uint16_t, uint32_t));
void ReadModbusRegisters(InterfaceData* , int , uint16_t , uint8_t , uint16_t* );

#endif /* COMPONENTS_MODBUS_CLIENT_MODBUSCLIENTMANAGER_H_ */
