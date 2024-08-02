/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "app_touchgfx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "taskManager.h"
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define DVC_APPJMP_CURRENT_ADDRESS 0x08040000
#define DVC_APPJMP_CURRENT_ADDRESS 0x08000000
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

CRC_HandleTypeDef hcrc;

DMA2D_HandleTypeDef hdma2d;

I2C_HandleTypeDef hi2c3;

LTDC_HandleTypeDef hltdc;

SDRAM_HandleTypeDef hsdram1;

osThreadId touchGFXTaskHandle;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void StartTouchGFXTask(void const * argument);

void dvc_appjmp_init_vectors()  __attribute__((optimize("-O0")));
void dvc_appjmp_goto(uint32_t)	__attribute__((optimize("-O0")));
void dvc_appjmp_enable() 		__attribute__((optimize("-O0")));

/* USER CODE BEGIN PFP */
extern uint32_t g_pfnVectors[];
static uint32_t vectorTable_RAM[256] __attribute__(( aligned(0x200ul) ));
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int _write(int file, char *ptr, int len){
	int i = 0;
	for(i = 0; i < len; i++){
		ITM_SendChar((*ptr++));
	}

	return len;
}

void dvc_appjmp_init_vectors()
{
	__disable_irq();
	memmove(vectorTable_RAM,g_pfnVectors,256*sizeof(uint32_t));
	SCB->VTOR = DVC_APPJMP_CURRENT_ADDRESS;
	__DSB();
	__ISB();
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* Memory system access */
  __HAL_RCC_PWR_CLK_ENABLE();
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_BKPSRAM_CLK_ENABLE();

  /* Enable power memory */
  //RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAMEN;
  PWR->CSR1 |= PWR_CSR1_BRE;
  while(!(PWR->CSR1 & PWR_CSR1_BRR_Msk));

  /* Initialize vector table */
  dvc_appjmp_init_vectors();

  /* Initialize HAL LIBRARIES */
  HAL_Init();

  /* Enable IRQ */
  __enable_irq();

  /* Initialize peripherals and tasks */
  InitTasks();


  osThreadDef(touchGFXTask, StartTouchGFXTask, osPriorityNormal, 0, 4096);
  touchGFXTaskHandle = osThreadCreate(osThread(touchGFXTask), NULL);

  osKernelStart();

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/* USER CODE BEGIN Header_StartTouchGFXTask */
/**
  * @brief  Function implementing the touchGFXTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartTouchGFXTask */
void StartTouchGFXTask(void const * argument)
{
  /* USER CODE BEGIN StartTouchGFXTask */
  MX_TouchGFX_Process();
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTouchGFXTask */
}

 /**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
