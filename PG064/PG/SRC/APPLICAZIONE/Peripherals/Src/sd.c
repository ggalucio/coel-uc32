/*
 * sd.c
 *
 *  Created on: Dec 1, 2021
 *      Author: paoloc
 */

#include "../Inc/sd.h"
#include "stm32f7xx_hal.h"

SD_HandleTypeDef hsd1;
DMA_HandleTypeDef hdma_sdmmc1_rx;
DMA_HandleTypeDef hdma_sdmmc1_tx;

BOOLEAN DeInitSd(){
	DeInitGpioPin(USD_DETECT_Port, USD_DETECT_Pin);
	return AT_TRUE;
}

/**
  * @brief SDMMC1 Initialization Function
  * @param None
  * @retval None
  */
BOOLEAN InitSd(void)
{
  hsd1.Instance = SDMMC1;
  hsd1.Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
  hsd1.Init.ClockBypass = SDMMC_CLOCK_BYPASS_DISABLE;
  hsd1.Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
  hsd1.Init.BusWide = SDMMC_BUS_WIDE_1B;
  hsd1.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
  hsd1.Init.ClockDiv = 0;

//  if(HAL_SD_Init(&hsd1) != HAL_OK)
//	  return AT_FALSE;

  InitGpioPin(USD_DETECT_Port, USD_DETECT_Pin, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_LOW);

  /* DMA controller clock enable */
   __HAL_RCC_DMA2_CLK_ENABLE();

   /* DMA interrupt init */
   /* DMA2_Stream3_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);
    /* DMA2_Stream6_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);

  return PERIPH_INIT_SUCCESS;
}

BOOLEAN IsSdInserted(){
	return ReadPin(USD_DETECT_Port, USD_DETECT_Pin) == GPIO_PIN_RESET;
}
