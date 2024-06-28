/*
 * resistiveTs.h
 *
 *  Created on: 10 set 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_TOUCHDRIVERS_RESISTIVE_RESISTIVETS_H_
#define COMPONENTS_TOUCHDRIVERS_RESISTIVE_RESISTIVETS_H_

#include "../ts.h"

uint8_t 	resistive_Init();
void 		resistive_Reset();
uint8_t 	resistive_ReadID();
void 		resistive_TS_Start();
uint8_t 	resistive_TS_DetectTouch(uint16_t *X, uint16_t *Y);
void		resistive_TS_SetTsPeriphDrv(TS_DrvPeriphTypeDef* periph_drv);


extern TS_DrvTypeDef resistive_ts_drv;



#endif /* COMPONENTS_TOUCHDRIVERS_RESISTIVE_RESISTIVETS_H_ */
