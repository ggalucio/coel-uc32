/*
 * peripheralManager.c
 *
 *  Created on: 8 giu 2021
 *      Author: paoloc
 */

#include "../Inc/peripheralManager.h"
#include "Module/module.h"

void InitPeripherls(void){

	// Deinizializzo le periferiche
	DeInitPeripherals();

	// Inizializzazione RCC
	InitRcc();

	// Inizializzazione MPU
	//InitMpu();

	// Inizializzazione GPIO
	InitGpio();

	// Inizializzazione MEMORY
	InitMemory();

	// Inizializzazione LUMINOSITA' DISPLAY
	InitBrightness();

	// Inizializzazione BUZZER
	InitBuzzer();

	// Inizializzazione DISPLAY
	InitDisplay();

	// Inizializzazione RTC
	InitRtc();

	// Inizializzazione SD
	InitSd();

	// Inizializzazione DMA2D
	InitDma2D();

	// Inizializzazione CRC
	InitCrc();

	// Inizializzazione LTCD
	InitLtcd();
}

void DeInitPeripherals(void){

	// Deinizializzazione RCC
	DeInitRcc();

	// Deinizializzazione GPIO
	DeInitGpio();

	// Deinizializzazione MEMORY
	DeInitMemory();

	// Deinizializzazione LUMINOSITA' SCHERMO
	DeInitBrightness();

	// Deinizializzazione BUZZER
	DeInitBuzzer();

	// Deinizializzazione DISPLAY
	DeInitDisplay();

	// Deinizializzazione RTC
	DeInitRtc();

	// Deinizializzazione MODBUS
	DeInitModbusRS485();

	// Deinizializzazione Resistivo
	DeInitResistive();

	// Deinizializzazione Capacitivo
	DeInitCapacitive();

	// Deinizializzazione DMA2D
	DeInitDma2D();

	// Deinizializzazione CRC
	DeInitCrc();

	// Deinizializzazione LTCD
	DeInitLtcd();
}

void *GetInitRtc(){
	return (void*)&InitRtc;
}

void *GetInitUsb(){
	return (void*)&InitUsb;
}

void *GetDetectRtcFlag(){
	return (void*)&DetectRtcFlag;
}

void *GetDetectUsbFlag(){
	return (void*)&DetectUsbFlag;
}

void *GetIsRtcReady(){
	return (void*)&IsRtcReady;
}

void *GetIsUsbReady(){
	return (void*)&IsUsbReady;
}


