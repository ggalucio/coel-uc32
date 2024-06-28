/*
 * peripheral.h
 *
 *  Created on: 8 giu 2021
 *      Author: paoloc
 */

#ifndef INC_PERIPHERAL_H_
#define INC_PERIPHERAL_H_

#include <stdint.h>
#include "stm32f7xx_hal.h"
#include "Utils/utils.h"

#define PERIPH_INIT_SUCCESS 1
#define PERIPH_INIT_FAILED 	0

void* GetDetectUsbFlag(void);
void* GetDetectRtcFlag(void);
void* GetInitRtc();
void* GetInitUsb();
void InitPeripherls(void);
void DeInitPeripherals(void);
void *GetIsRtcReady();
void *GetIsUsbReady();

#endif /* INC_PERIPHERAL_H_ */
