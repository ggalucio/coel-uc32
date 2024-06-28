/*
 * resistive.c
 *
 *  Created on: 10 set 2021
 *      Author: paoloc
 */

#include "../Inc/resistive.h"
#include "../Inc/adc.h"

void DeInitPins(){

	/* Deinizzializzazione pin XL*/
	DeInitGpioPin(X_L_Port, X_L_Pin);

	/* Deinizzializzazione pin XR*/
	DeInitGpioPin(X_R_Port, X_R_Pin);

	/* Deinizzializzazione pin YTL*/
	DeInitGpioPin(Y_T_Port, Y_T_Pin);

	/* Deinizzializzazione pin YB*/
	DeInitGpioPin(Y_B_Port, Y_B_Pin);

	/* Deinizializzazione ACD*/
	DeInitAdc();
}

void StartTouchSeq(){

	/* Deinizializzazione GPIO pins */
	DeInitPins();

	/*Configure GPIO pin : X_L_Pin */
	InitGpioPin(X_L_Port, X_L_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW);

	/*Configure GPIO pin : X_R_Pin */
	InitGpioPin(X_R_Port, X_R_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW);

	/*Configure GPIO pin : Y_B_Pin */
	InitGpioPin(Y_B_Port, Y_B_Pin, GPIO_MODE_INPUT, GPIO_PULLDOWN, GPIO_SPEED_FREQ_LOW);

	/* Polarizzo elettrodo di sinistra */
	WritePin(X_L_Port, X_L_Pin, GPIO_PIN_SET);

	/* Polarizzo elettrodo di destra */
	WritePin(X_R_Port, X_R_Pin, GPIO_PIN_SET);
}

void StartReadXSeq(){

	/* Deinizializzazione GPIO pins */
	DeInitPins();

	/*Configure GPIO pin : X_L_Pin */
	InitGpioPin(X_L_Port, X_L_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW);

	/*Configure GPIO pin : X_R_Pin */
	InitGpioPin(X_R_Port, X_R_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW);

	/* Polarizzo elettrodo di sinistra */
	WritePin(X_L_Port, X_L_Pin, GPIO_PIN_RESET);

	/* Polarizzo elettrodo di destra */
	WritePin(X_R_Port, X_R_Pin, GPIO_PIN_SET);

	/* Inizializzazione ACD*/
	InitAdc(X_CHANNEL);
}

void StartReadYSeq(){

	uint32_t mask = 512;

	/* Deinizializzazione GPIO pins */
	DeInitPins();

	/*Configure GPIO pin : Y_T_Pin */
	InitGpioPin(Y_T_Port, Y_T_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW);

	/*Configure GPIO pin : Y_B_Pin */
	InitGpioPin(Y_B_Port, Y_B_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW);

	/* Polarizzo elettrodo in alto*/
	WritePin(Y_T_Port, Y_T_Pin, GPIO_PIN_RESET);

	/* Polarizzo elettrodo in basso */
	WritePin(Y_B_Port, Y_B_Pin, GPIO_PIN_SET);

	/* Inizializzazione ACD*/
	InitAdc(Y_CHANNEL);

	GPIOA->MODER &= ~mask;
	GPIOA->MODER |= (3 << (Y_CHANNEL * 2));
}

uint8_t DeInitResistive(void){
	DeInitPins();
	return AT_TRUE;
}

uint8_t Resistive_TS_IO_Init(void){
	StartTouchSeq();
	return AT_TRUE;
}

uint8_t  Resistive_TS_IO_DeviceReady(uint16_t DevAddress){
	return AT_TRUE;
}

void 	Resistive_TS_IO_Write(uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t Value){

}

uint16_t Resistive_TS_IO_Read(uint8_t Addr, uint16_t Reg, uint16_t MemAddress){
	// Sfrutto questa funzione anche per cambiare le sequenze del touch resistivo
	// Se Addr = 0 	-> cambio di stato della sequenza (quale? me lo dice Reg)
	//			 	-> Reg = 1: sequenza rilevamento contatto
	// 				-> Reg = 2: sequenza lettura della coordinata X
	// 				-> Reg = 3: sequenza lettura della coordinata Y

	if(Addr == RESISTIVE_CHANGE_SEQ_CMD){
		// Cambio sequenza...
		switch(Reg){
			case RESISTIVE_TOUCH_SEQUENCE: 		StartTouchSeq();	break;
			case RESISTIVE_READX_SEQUENCE: 		StartReadXSeq();	break;
			case RESISTIVE_READY_SEQUENCE: 		StartReadYSeq();	break;
			default:												break;
		}
	}
	else if(Addr == RESISTIVE_READ_TOUCH_CMD){
		// Stato rilevamento TOUCH
		return ReadPin(Y_B_Port, Y_B_Pin) ? AT_TRUE : AT_FALSE;
	}
	else if(Addr == RESISTIVE_READ_X_COORD_CMD){
		// Stato lettura coordinata X
		return ReadValue();
	}
	else if(Addr == RESISTIVE_READ_Y_COORD_CMD){
		// Stato lettura coordinata Y
		return ReadValue();
	}

	return AT_FALSE;
}

uint8_t Resistive_TS_IO_Read_Multiple(uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t* pData, uint8_t len){
	return 1;
}

void 	Resistive_Error(void){

}

