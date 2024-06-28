/*
 * adc.h
 *
 *  Created on: 10 set 2021
 *      Author: paoloc
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "stdint.h"
#include "stm32f7xx_hal.h"

#define X_CHANNEL ADC_CHANNEL_4
#define Y_CHANNEL ADC_CHANNEL_3

HAL_StatusTypeDef InitAdc(uint32_t channel);
HAL_StatusTypeDef DeInitAdc(void);
HAL_StatusTypeDef ADCConfig(uint32_t channel);
uint16_t ReadValue(void);


#endif /* INC_ADC_H_ */
