/*
 * gpio.c
 *
 *  Created on: 8 giu 2021
 *      Author: paoloc
 */


#include "Peripherals/Inc/gpio.h"

#define LCD_INT_Pin 			GPIO_PIN_13
#define LCD_INT_GPIO_Port 		GPIOI
#define USB_VEN_Pin 			GPIO_PIN_14
#define USB_VEN_GPIO_Port 		GPIOB
#define LCD_BL_CTRL_Pin 		GPIO_PIN_3
#define LCD_BL_CTRL_GPIO_Port 	GPIOK

void DeInitGpio(void){
	HAL_GPIO_DeInit(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin);
	HAL_GPIO_DeInit(USB_VEN_GPIO_Port, USB_VEN_Pin);
	HAL_GPIO_DeInit(LCD_INT_GPIO_Port, LCD_INT_Pin);

	__HAL_RCC_GPIOA_CLK_DISABLE();
	__HAL_RCC_GPIOB_CLK_DISABLE();
	__HAL_RCC_GPIOC_CLK_DISABLE();
	__HAL_RCC_GPIOD_CLK_DISABLE();
	__HAL_RCC_GPIOE_CLK_DISABLE();
	__HAL_RCC_GPIOF_CLK_DISABLE();
	__HAL_RCC_GPIOG_CLK_DISABLE();
	__HAL_RCC_GPIOH_CLK_DISABLE();
	__HAL_RCC_GPIOI_CLK_DISABLE();
	__HAL_RCC_GPIOJ_CLK_DISABLE();
	__HAL_RCC_GPIOK_CLK_DISABLE();
}

void InitGpio(void){

	DeInitGpio();

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOJ_CLK_ENABLE();
	__HAL_RCC_GPIOK_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(USB_VEN_GPIO_Port, USB_VEN_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, GPIO_PIN_SET);

	/*Configure GPIO pin : LCD_INT_Pin */
	//InitGpioPin(LCD_INT_GPIO_Port, LCD_INT_Pin, GPIO_MODE_INPUT, GPIO_PULLDOWN, GPIO_SPEED_FREQ_HIGH);
	InitGpioPin(LCD_INT_GPIO_Port, LCD_INT_Pin, GPIO_MODE_IT_FALLING, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH);

	/*Configure GPIO pin : USB_VEN_Pin */
	InitGpioPin(USB_VEN_GPIO_Port, USB_VEN_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH);

	/*Configure GPIO pin : ETH_RXERR_Pin */
	//InitGpioPin(ETH_RXERR_GPIO_Port, ETH_RXERR_Pin, GPIO_MODE_INPUT, GPIO_PULLDOWN, GPIO_SPEED_FREQ_HIGH);

	/*Configure GPIO pin : LCD_BL_CTRL_Pin */
	InitGpioPin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH);

    /* EXTI interrupt init*/
	/*HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);*/
}

void SetUsbVenPinON(){
	HAL_GPIO_WritePin(USB_VEN_GPIO_Port, USB_VEN_Pin, GPIO_PIN_SET);
}

void WritePin(GPIO_TypeDef* port, uint32_t pin, GPIO_PinState state){
	HAL_GPIO_WritePin(port, pin, state);
}

GPIO_PinState ReadPin(GPIO_TypeDef* port, uint32_t pin){
	return HAL_GPIO_ReadPin(port, pin);
}

void TogglePin(GPIO_TypeDef* port, uint32_t pin){
	HAL_GPIO_TogglePin(port, pin);
}

void InitGpioPin(GPIO_TypeDef* port, uint32_t pin, uint32_t mode, uint32_t pull, uint32_t speed){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = mode;
	GPIO_InitStruct.Pull = pull;
	GPIO_InitStruct.Speed = speed;
	HAL_GPIO_Init(port, &GPIO_InitStruct);
}

void DeInitGpioPin(GPIO_TypeDef* port, uint32_t pin){
	HAL_GPIO_DeInit(port, pin);
}
