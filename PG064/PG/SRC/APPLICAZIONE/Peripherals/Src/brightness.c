/*
 * brightness.c
 *
 *  Created on: May 21, 2021
 *      Author: paoloc
 */


#include "../Inc/brightness.h"
#include "stm32f7xx_hal.h"

extern void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim);

TIM_HandleTypeDef brightnessTim;

void SetBrightness(int brightness){
	brightnessTim.Instance->CCR1 = brightness;
}

BYTE ChangeBrightness(int step){
	return (BYTE)(brightnessTim.Instance->CCR1 + step);
}

BOOLEAN DeInitBrightness(){

	// Deinizializzazione PWM
	HAL_StatusTypeDef pwmState = HAL_TIM_PWM_Stop(&brightnessTim, TIM_CHANNEL_1);
	HAL_StatusTypeDef deInitPwmState = HAL_TIM_PWM_DeInit(&brightnessTim);

	// Deinizializzazione periferica TIM
	HAL_StatusTypeDef deInitTimState = HAL_TIM_Base_DeInit(&brightnessTim);

	return pwmState & deInitPwmState & deInitTimState;
}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
BOOLEAN InitBrightness(void)
{

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  brightnessTim.Instance = TIM1;
  brightnessTim.Init.Prescaler = 2400 - 1;
  brightnessTim.Init.CounterMode = TIM_COUNTERMODE_UP;
  brightnessTim.Init.Period = 100 - 1;
  brightnessTim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  brightnessTim.Init.RepetitionCounter = 0;
  brightnessTim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&brightnessTim) != HAL_OK)
	  return AT_FALSE;

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&brightnessTim, &sMasterConfig) != HAL_OK)
	  return AT_FALSE;

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&brightnessTim, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	  return AT_FALSE;

  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&brightnessTim, &sBreakDeadTimeConfig) != HAL_OK)
	  return AT_FALSE;

  HAL_TIM_MspPostInit(&brightnessTim);

  return HAL_TIM_PWM_Start(&brightnessTim, TIM_CHANNEL_1) == HAL_OK;

  //uint8_t brightness = 80;//100;//ReadBrightness();
  //SetBrightness(brightness);
}
