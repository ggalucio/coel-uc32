/*
 * display.c
 *
 *  Created on: 23 set 2021
 *      Author: paoloc
 */

#include "../Inc/display.h"
#include "../Inc/gpio.h"

#define LCD_DISP_GPIO_Pin		GPIO_PIN_12
#define LCD_DISP_GPIO_Port 		GPIOI
#define LCD_RST_GPIO_Pin		GPIO_PIN_6
#define LCD_RST_GPIO_Port 		GPIOI

BOOLEAN DeInitDisplay(void){
	// DEINIT
	DeInitGpioPin(LCD_DISP_GPIO_Port, LCD_DISP_GPIO_Pin);
	DeInitGpioPin(LCD_RST_GPIO_Port, LCD_RST_GPIO_Pin);
	return AT_TRUE;
}

void InitDisplay(void){
	/*Configure GPIO pin : LCD_DISP_Pin */
	InitGpioPin(LCD_DISP_GPIO_Port, LCD_DISP_GPIO_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH);

	/*Configure GPIO pin : LCD_RST_Pin */
	InitGpioPin(LCD_RST_GPIO_Port, LCD_RST_GPIO_Pin, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_FREQ_HIGH);

	SwitchDisplay(SWITCH_OFF);
	SwitchRst(SWITCH_OFF);
}

void SwitchDisplay(uint32_t on){
	WritePin(LCD_DISP_GPIO_Port, LCD_DISP_GPIO_Pin, on ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void SwitchRst(uint32_t rst){
	WritePin(LCD_RST_GPIO_Port, LCD_RST_GPIO_Pin, rst ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

