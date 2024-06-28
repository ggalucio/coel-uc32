/*
 * display.h
 *
 *  Created on: 23 set 2021
 *      Author: paoloc
 */

#ifndef PERIPHERALS_INC_DISPLAY_H_
#define PERIPHERALS_INC_DISPLAY_H_

#include "stdint.h"
#include "Utils/utils.h"

void InitDisplay(void);
void SwitchDisplay(uint32_t on);
void SwitchRst(uint32_t rst);
BOOLEAN DeInitDisplay(void);

#endif /* PERIPHERALS_INC_DISPLAY_H_ */
