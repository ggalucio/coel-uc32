/*
 * parameters.c
 *
 *  Created on: May 21, 2021
 *      Author: paoloc
 */

#include "../Inc/parameters.h"
#include "stm32f7xx_hal.h"

I2C_HandleTypeDef hi2c4;

BOOLEAN ReadParameters(uint8_t *pData,  uint16_t size, uint16_t DevAddress, uint16_t MemAddress){
	HAL_StatusTypeDef ret = HAL_I2C_Mem_Read(&hi2c4, DevAddress, MemAddress, 1, pData, size, 50);
	return ret == HAL_OK;
}

BOOLEAN WriteParameters(uint8_t *pData,  uint16_t size, uint16_t DevAddress, uint16_t MemAddress){
	HAL_StatusTypeDef ret = HAL_I2C_Mem_Write(&hi2c4, DevAddress, MemAddress, 1, pData, size, 50);
	return ret == HAL_OK;
}

/**
  * @brief I2C4 Initialization Function
  * @param None
  * @retval None
  */
BOOLEAN InitParameters(void)
{
	hi2c4.Instance = I2C4;
	hi2c4.Init.Timing = 0x00401959;
	hi2c4.Init.OwnAddress1 = 0;
	hi2c4.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c4.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c4.Init.OwnAddress2 = 0;
	hi2c4.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	hi2c4.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c4.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c4) != HAL_OK)
	  return AT_FALSE;

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c4, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	  return AT_FALSE;

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c4, 0) != HAL_OK)
	  return AT_FALSE;

  return AT_TRUE;
}
