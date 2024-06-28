/*
 * usbDevice.h
 *
 *  Created on: Nov 4, 2021
 *      Author: paoloc
 */

#ifndef INC_USBDEVICE_H_
#define INC_USBDEVICE_H_

#include "stdint.h"
#include "Utils/modbusUtils.h"

ModbusServerTypeDef *pModbusUsbServer;

void ModbusUsbDeviceRx(uint8_t* pRxData, int length);
void ResetUsbModbusMaster();
void InitUsbModbusServer(void);
BOOLEAN IsUsbModbusServerEnable(void);

#endif /* INC_USBDEVICE_H_ */
