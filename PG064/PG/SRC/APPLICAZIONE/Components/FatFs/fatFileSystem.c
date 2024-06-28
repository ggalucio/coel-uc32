/*
 * fatfs.c
 *
 *  Created on: Dec 1, 2021
 *      Author: paoloc
 */

#include <Components/FatFs/fatFileSystem.h>
#include "Peripherals/Inc/sd.h"
#include "Libraries/FatFs/src/ff.h"
#include "Libraries/FatFs/App/fatfs.h"

PHYCONNECTION pyhFatFsState = MP_DISCONNECTED;

void FatsDisconnect(){
	pyhFatFsState = MP_DISCONNECTED;
	FatFsUnLinkDrivers();
	uSD_Drv.State = FATFS_NONE;
}

void FatsConnect(){

	FatFsUnLinkDrivers();

	if(FatFsLinkDrivers()){
		pyhFatFsState = MP_CONNECTED;
		uSD_Drv.State = FATFS_NONE;
	}
}

void FatsDisconnectedState(){

	RESET_SD_PERIPH_STATUS();

	if(IsSdInserted()){
		FatsConnect();
	}
}

void FatfsWrite(){
	FRESULT wRes = WriteSD(uSD_Drv.TxBuffer, uSD_Drv.FileName);
	uSD_Drv.State = wRes == FR_OK ? FATFS_WRITTEN : FATFS_ERR;
}

void FatfsRead(){
	FRESULT rRes = ReadSD(uSD_Drv.RxBuffer, sizeof(char) * FATFS_BUFF_SIZE, uSD_Drv.FileName);
	uSD_Drv.State = rRes == FR_OK ? FATFS_READ : FATFS_ERR;
}

void FatfsErr(){
	FatsDisconnect();
}

void FatfsConnRun(){
	switch(uSD_Drv.State){
		case FATFS_WRITING:	FatfsWrite();	break;
		case FATFS_READING:	FatfsRead();	break;
		case FATFS_ERR:		FatfsErr();		break;
		default:							break;
	}
}

void FatsConnectedState(){

	SET_SD_PERIPH_STATUS();

	if(!IsSdInserted()){
		FatsDisconnect();
	}
	else{
		FatfsConnRun();
	}
}

void FatFsRun(void){
	switch(pyhFatFsState){
		case MP_DISCONNECTED: 	FatsDisconnectedState();	break;
		case MP_CONNECTED: 		FatsConnectedState();		break;
	}
}
