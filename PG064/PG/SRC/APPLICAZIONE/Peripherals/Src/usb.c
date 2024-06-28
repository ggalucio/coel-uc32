/*
 * usb.c
 *
 *  Created on: 8 giu 2021
 *      Author: paoloc
 */

#include "../Inc/usb.h"
#include "Libraries/FatFs/App/fatfs.h"
#include "usb_host.h"
#include "../Inc/gpio.h"

uint8_t DetectUsbFlag(void){
	return FR_OK;
}

uint8_t IsUsbReady(void){
	return 0;
}

uint8_t InitUsb(void){
	MX_FATFS_Init();
	MX_USB_HOST_Init();
	SetUsbVenPinON();
	return 1;
}
uint8_t OpenFwFile(void){
	return 0;
}

uint32_t ReadFwFileTotSize(void){
	return 0;
}

uint32_t ReadFwFile(uint8_t* pData, uint16_t* length){
	return 0;
}

void 	CloseFwFile(void){

}


