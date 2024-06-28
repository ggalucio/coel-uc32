/*
 * usbDevice.c
 *
 *  Created on: Nov 4, 2021
 *      Author: paoloc
 */

#include <Components/Modbus/Serial/modbusSerialLib.h>
#include "Utils/common.h"
#include "usb_device.h"
#include "usbDevice.h"
#include "usbd_cdc_if.h"
#include "stdlib.h"

/**
* Modbus server USB function pointers and variables.
*/
ModbusServerTypeDef modbusUsbServer = {
		MP_DISCONNECTED,
		MMS_INIT,
		0,
		{ 0 },
		0,
		FUNCTION_CODE_IDX,
		SLAVE_ADDRESS_IDX,
		MODBUS_RS485_REG_ADDR,
		0,
		0,
		MX_USB_DEVICE_Init,
		DoNothing,
		IsSerialFunctionCodeValid,
		IsSerialFrameValid,
		UnpackModbusSerialMultipleRead,
		UnpackModbusSerialMultipleWrite,
		UnpackModbusSerialSingleWrite,
		PackModbusSerialMultipleWriteResponse,
		PackModbusSerialMultipleReadResponse,
		PackModbusSerialSingleWriteResponse,
		PackSerialExceptions,
		ResetUsbModbusMaster,
		IsUsbModbusServerEnable,
		NULL,
		NULL
};

/**
* @brief Modbus server reset state
* This function resets buffers and modbus server state.
*/
void ResetUsbModbusMaster(){
	memset(modbusUsbServer.Buffer.pBuff, 0, sizeof(BYTE) * BUFFER_SIZE);
	modbusUsbServer.Buffer.length = 0;
	modbusUsbServer.Buffer.valid = 0;
	modbusUsbServer.ExceptionCode = MODBUS_CODE_NO_EXCEPTIONS;
}

/**
* @brief Modbus server response package management
* This function receives response package from client and saves it in appropriate buffer.
* @param pRxData: package received from client.
* @param length: package length.
*/
void ModbusUsbDeviceRx(uint8_t* pRxData, int length){
	ResetUsbModbusMaster();
	memcpy(modbusUsbServer.Buffer.pBuff, pRxData, sizeof(BYTE) * length);
	modbusUsbServer.Buffer.length = length;
	modbusUsbServer.Buffer.valid = 1;


}

/**
* @brief Modbus server enable
* This function gets if modbus USB server is enabled or not.
* @retval: 1 because modbus server USB is always enabled.
*/
BOOLEAN IsUsbModbusServerEnable(){
	return AT_TRUE;
}

/**
* @brief Modbus server initializer
* This function initializes modbus USB server.
*/
void InitUsbModbusServer(){
	modbusUsbCommunication.State = MB_READY;
	modbusUsbCommunication.RstClbk = ResetUsbModbusMaster;
	modbusUsbCommunication.ReceiveClbk = ModbusUsbDeviceRx;
	modbusUsbCommunication.Send = CDC_Transmit_FS;

	modbusUsbServer.Communication = &modbusUsbCommunication;
	pModbusUsbServer = &modbusUsbServer;
}
