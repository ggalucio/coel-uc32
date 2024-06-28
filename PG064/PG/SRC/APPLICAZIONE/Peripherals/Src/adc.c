/*
 * adc.c
 *
 *  Created on: 10 set 2021
 *      Author: paoloc
 */

#include "../Inc/adc.h"

ADC_HandleTypeDef hadc;

HAL_StatusTypeDef InitAdc(uint32_t channel){
	 /* USER CODE BEGIN ADC1_Init 0 */

	  /* USER CODE END ADC1_Init 0 */

	  /* USER CODE BEGIN ADC1_Init 1 */

	  /* USER CODE END ADC1_Init 1 */
	  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
	  */
	  hadc.Instance = ADC1;
	  hadc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	  hadc.Init.Resolution = ADC_RESOLUTION_12B;
	  hadc.Init.ScanConvMode = ADC_SCAN_DISABLE;
	  hadc.Init.ContinuousConvMode = DISABLE;
	  hadc.Init.DiscontinuousConvMode = DISABLE;
	  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	  hadc.Init.NbrOfConversion = 1;
	  hadc.Init.DMAContinuousRequests = DISABLE;
	  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	  if(HAL_ADC_Init(&hadc) != HAL_OK)
		  return HAL_ERROR;

	  return ADCConfig(channel);
}

HAL_StatusTypeDef ADCConfig(uint32_t channel){
	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Channel = channel;
	sConfig.Rank = ADC_REGULAR_RANK_1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	return HAL_ADC_ConfigChannel(&hadc, &sConfig);
}

HAL_StatusTypeDef DeInitAdc(void){
	HAL_ADC_Stop(&hadc);
	return HAL_ADC_DeInit(&hadc);
}

uint16_t ReadValue(){
	HAL_ADC_Start(&hadc);
    HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);
	return HAL_ADC_GetValue(&hadc);
}


