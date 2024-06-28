/*
 * brightnessModule.c
 *
 *  Created on: 15 set 2021
 *      Author: paoloc
 */

#include "brightnessModule.h"
#include "../Settings/settings.h"
#include "../Peripherals/Inc/brightness.h"

#define MAX_BRIGHTNESS_VALUE 100
#define MIN_BRIGHTNESS_VALUE 10

void InitBrightnessModule(){
	ResetBrightnessValue();
}

void ResetBrightnessValue(){
	SetBrightness(0);
}

void RestoreBrightness(){
	BYTE br = MAX_BRIGHTNESS_VALUE - ReadBrightnessValue();
	WriteBrightnessValue(br);
}

uint8_t ReadBrightnessValue(){
	// Leggo da memoria il valore della luminosità.
	return ReadBrightness();
}

void WriteBrightnessValue(uint8_t brightness){

	if(brightness > MAX_BRIGHTNESS_VALUE)
		brightness = MAX_BRIGHTNESS_VALUE;

	if(brightness < MIN_BRIGHTNESS_VALUE)
			brightness = MIN_BRIGHTNESS_VALUE;

	// Cambio il nuovo valore della luminosità.
	SetBrightness(brightness);

	// Salvo in memoria il nuovo valore della luminosità.
	WriteBrightness(MAX_BRIGHTNESS_VALUE - brightness);
}

void ChangeBrightnessValue(int step){
	// Cambio runtime il nuovo valore della luminosità per step...
	int br = ChangeBrightness(step);

	// Salvo il nuovo valore.
	WriteBrightnessValue(br);
}

