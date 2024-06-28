/*
 * brightness.h
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#ifndef INC_BRIGHTNESS_H_
#define INC_BRIGHTNESS_H_

#include "Utils/utils.h"
#include "Utils/integer.h"

BOOLEAN InitBrightness(void);
BOOLEAN DeInitBrightness(void);
BYTE ChangeBrightness(int step);
void SetBrightness(int brightness);

#endif /* INC_BRIGHTNESS_H_ */
