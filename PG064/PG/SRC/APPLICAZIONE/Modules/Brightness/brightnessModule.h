/*
 * brightnessModule.h
 *
 *  Created on: 15 set 2021
 *      Author: paoloc
 */

#ifndef MODULES_BRIGHTNESS_BRIGHTNESSMODULE_H_
#define MODULES_BRIGHTNESS_BRIGHTNESSMODULE_H_

#include "Utils/utils.h"
#include "Utils/integer.h"

void InitBrightnessModule();
void WriteBrightnessValue(BYTE brightness);
BYTE ReadBrightnessValue();
void ChangeBrightnessValue(int step);
void ResetBrightnessValue();
void RestoreBrightness();

#endif /* MODULES_BRIGHTNESS_BRIGHTNESSMODULE_H_ */
