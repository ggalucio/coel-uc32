/*
 * buzzer.c
 *
 *  Created on: 30 giu 2021
 *      Author: paoloc
 */

#include "../Inc/buzzer.h"
#include "../Inc/gpio.h"

BOOLEAN DeInitBuzzer(){
	DeInitGpioPin(BUZZER_Port, BUZZER_Pin);
	return AT_TRUE;
}

void InitBuzzer(void){
	InitGpioPin(BUZZER_Port, BUZZER_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_LOW);
	SwitchBuzzerOFF();
}

void SwitchBuzzerON(){
	WritePin(BUZZER_Port, BUZZER_Pin, GPIO_PIN_SET);
	SET_BUZZER_PERIPH_STATUS();
}

void SwitchBuzzerOFF(){
	WritePin(BUZZER_Port, BUZZER_Pin, GPIO_PIN_RESET);
	RESET_BUZZER_PERIPH_STATUS();
}

void ToggleBuzzer(){
	TogglePin(BUZZER_Port, BUZZER_Pin);
}
