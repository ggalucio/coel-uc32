/*
 * hycon.c
 *
 *  Created on: 27 ago 2021
 *      Author: paoloc
 */

/************ INCLUDES ************/

#include "hycon.h"
#include "../Utils/utils.h"

/************ DEFINITIONS ************/
/**
 *  Hycon tpuch screen driver I2C address.
*/
#define HYCON_I2C_ADDR  0x71

/**
 *  Detects if a touch occurred
*/
#define DETECT_TOUCH() 	(((hycon_periph_drv.Read(HYCON_I2C_ADDR, HYCON_TOUCH_STATUS, MEMADD_SIZE_8BIT) >> 6 ) & 3) == HYCON_TOUCH_STATUS_CONTACT)

/**
 *  Gets Hycon touch screen driver coordinates
*/
#define GET_COORDS(tsArr)											\
			uint8_t* pData = tsArr;									\
			uint8_t xH = (*pData++) & HYCON_TOUCH_POS_MSB_MASK;		\
			uint8_t xL = (*pData++) & HYCON_TOUCH_POS_LSB_MASK;		\
			uint8_t yH = (*pData++) & HYCON_TOUCH_POS_MSB_MASK;		\
			uint8_t yL = (*pData++) & HYCON_TOUCH_POS_LSB_MASK;		\
			*X = (xH << BYTE_BIT_NUM) | xL;							\
			*Y = (yH << BYTE_BIT_NUM) | yL;							\

/************ PRIVATE VARIABLES ************/

/**
 *  Hycon touch screen driver structure initialization
*/
TS_DrvTypeDef hycon_ts_drv = {
		hycon_Init,
		hycon_ReadID,
		hycon_TS_Start,
		hycon_TS_DetectTouch,
		hycon_TS_SetTsPeriphDrv
};

/**
 *  Hycon touch screen driver peripheral structure.
*/
TS_DrvPeriphTypeDef hycon_periph_drv;

/**
* @brief Hycon Touch Screen initializer
* This function detects if hycon driver is connected.
* @retval 1 if device is found, 0 otherwise
*/
uint8_t hycon_Init(){
	if(!hycon_periph_drv.DeviceReady(HYCON_I2C_ADDR))
		return AT_FALSE;

	if(!hycon_periph_drv.Init())
		return AT_FALSE;

	//Wait 200ms after power up before accessing gt911 registers
	hycon_periph_drv.Delay(200);
	return AT_TRUE;
}

/**
* @brief Hycon Touch Screen reset
* This function resets hycon touch screen driver (NOT USED)
*/
void hycon_Reset(){

}

/**
* @brief Hycon Touch Screen ID reader
* This function reads hycon touch screen driver ID
* @retval: 1 (it is not expected for this driver)
*/
uint8_t hycon_ReadID(){
	return 1;
}

/**
* @brief Hycon Touch Screen initializer
* This function initializes hycon touch screen driver
*/
void hycon_TS_Start(){
	/* Run mode */
	hycon_periph_drv.Write(HYCON_I2C_ADDR, HYCON_TP_RUN_MODE, MEMADD_SIZE_8BIT, HYCON_RUN_WORK_MODE);		// 0x00: Work mode - 0xc0: test mode

	/* Glove enable */
	hycon_periph_drv.Write(HYCON_I2C_ADDR, HYCON_GLOVE_EN_REG, MEMADD_SIZE_8BIT, HYCON_ENABLE);				// 0x00: Glove disable - 0x01: glove enable

	/* Touch threshold*/
	hycon_periph_drv.Write(HYCON_I2C_ADDR, HYCON_TOUCH_TH_REG, MEMADD_SIZE_8BIT, HYCON_TOUCH_TH_VALUE);		// Value: 1 - Default: 17

	/* Proximity sensor switch*/
	hycon_periph_drv.Write(HYCON_I2C_ADDR, HYCON_PROX_SENS_REG, MEMADD_SIZE_8BIT, HYCON_ENABLE);			// 0x00: Prox sensor disable - 0x01: Prox sensor enable

	/* Power noise enable*/
	hycon_periph_drv.Write(HYCON_I2C_ADDR, HYCON_PWR_NOISE_EN_REG, MEMADD_SIZE_8BIT, HYCON_ENABLE);			// Power noise: 0 - Disable, 1: enable

	/* Gain */
	hycon_periph_drv.Write(HYCON_I2C_ADDR, HYCON_GAIN_REG, MEMADD_SIZE_8BIT, HYCON_GAIN_5);					// Gain: from 0 to 5

	/* Delay */
	hycon_periph_drv.Delay(10);
}

/**
* @brief Hycon Touch Screen detection
* This function detects hycon screen touch and retrieves coordinates.
* @param X: X coordinate.
* @param X: Y coordinate
* @retval: 1 if a touch occurred, 0 otherwise
*/
uint8_t hycon_TS_DetectTouch(uint16_t *X, uint16_t *Y){
	uint8_t nbTouch = 0;
	uint8_t res = (hycon_periph_drv.Read(HYCON_I2C_ADDR, HYCON_TOUCH_STATUS, MEMADD_SIZE_8BIT) >> 6 ) & 3;
	if(res == HYCON_TOUCH_STATUS_CONTACT)
	//if(DETECT_TOUCH())
	{
		uint8_t tsData[HYCON_TOUCH_COORDS_NUM_REG];
		if(hycon_periph_drv.ReadMultiple(HYCON_I2C_ADDR, HYCON_COORD_X_MSB, MEMADD_SIZE_8BIT, tsData, HYCON_TOUCH_COORDS_NUM_REG)){
			GET_COORDS(tsData);
			nbTouch = 1;
		}
	}

	return nbTouch;
}

/**
* @brief Hycon Touch Screen peripheral driver setter
* This function sets appropriate peripheral driver for hycon touch screen
* @param periph_drv: peripheral driver for hycon touch screen.
*/
void hycon_TS_SetTsPeriphDrv(TS_DrvPeriphTypeDef* periph_drv){
	hycon_periph_drv = *periph_drv;
}
