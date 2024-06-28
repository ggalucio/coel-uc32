/*
 * sd.h
 *
 *  Created on: Dec 1, 2021
 *      Author: paoloc
 */

#ifndef PERIPHERALS_INC_SD_H_
#define PERIPHERALS_INC_SD_H_

#include "gpio.h"

BOOLEAN InitSd(void);
BOOLEAN DeInitSd();
BOOLEAN IsSdInserted();

#endif /* PERIPHERALS_INC_SD_H_ */
