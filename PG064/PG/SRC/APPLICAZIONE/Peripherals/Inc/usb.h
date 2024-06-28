/*
 * usb.h
 *
 *  Created on: 8 giu 2021
 *      Author: paoloc
 */

#ifndef INC_USB_H_
#define INC_USB_H_

#include "peripheral.h"

uint8_t  InitUsb(void);
uint8_t  DetectUsbFlag(void);
uint8_t  IsUsbReady(void);
uint8_t  OpenFwFile(void);
uint32_t ReadFwFile(uint8_t* pData, uint16_t* length);
void 	 CloseFwFile(void);
uint32_t ReadFwFileTotSize(void);

#endif /* INC_USB_H_ */
