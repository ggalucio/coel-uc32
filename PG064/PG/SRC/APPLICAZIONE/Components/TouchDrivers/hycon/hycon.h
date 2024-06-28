/*
 * hicon.h
 *
 *  Created on: 27 ago 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_TOUCHDRIVERS_HYCON_HYCON_H_
#define COMPONENTS_TOUCHDRIVERS_HYCON_HYCON_H_

/************ INCLUDES ************/

#include "../ts.h"

/************ DEFINITIONS ************/

// Hycon registers
#define HYCON_TP_RUN_MODE				((uint16_t)0x00)		// tp run mode
#define HYCON_TOUCH_STATUS				((uint16_t)0x03)		// Touch status
#define HYCON_COORD_X_MSB				((uint16_t)0x03)		// x coordinate resolution ( low byte )
#define HYCON_COORD_X_LSB				((uint16_t)0x04)		// x coordinate resolution ( high byte )
#define HYCON_COORD_Y_MSB				((uint16_t)0x05)		// y coordinate resolution ( low byte )
#define HYCON_COORD_Y_LSB				((uint16_t)0x06)		// y coordinate resolution ( high byte )
#define HYCON_TOUCH_TH_REG				((uint16_t)0x80)		// Touch threshold register
#define HYCON_PROX_SENS_REG				((uint16_t)0x81)		// Proximity sensor enable register
#define HYCON_GLOVE_EN_REG				((uint16_t)0x84)		// Glove enable	register
#define HYCON_PWR_NOISE_EN_REG			((uint16_t)0x89)		// Power noise enable register
#define HYCON_GAIN_REG					((uint16_t)0x92)		// Gain register

#define HYCON_TOUCH_POS_MSB_MASK		((uint8_t)0x0F)
#define HYCON_TOUCH_POS_LSB_MASK		((uint8_t)0xFF)
#define HYCON_RUN_WORK_MODE				((uint8_t)0x00)
#define HYCON_ENABLE					((uint8_t)0x01)
#define HYCON_DISABLE					((uint8_t)0x00)
#define HYCON_TOUCH_TH_VALUE			((uint8_t)0x01)

#define HYCON_TOUCH_COORDS_NUM_REG		((uint8_t)0x04)

// FINGER EVENT
#define HYCON_TOUCH_STATUS_DOWN			((uint8_t)0x00)
#define HYCON_TOUCH_STATUS_UP			((uint8_t)0x01)
#define HYCON_TOUCH_STATUS_CONTACT		((uint8_t)0x02)
#define HYCON_TOUCH_STATUS_RESERVED		((uint8_t)0x03)

#define HYCON_GAIN_0					((uint8_t)0x00)
#define HYCON_GAIN_1					((uint8_t)0x01)
#define HYCON_GAIN_2					((uint8_t)0x02)
#define HYCON_GAIN_3					((uint8_t)0x03)
#define HYCON_GAIN_4					((uint8_t)0x04)
#define HYCON_GAIN_5					((uint8_t)0x05)


/************ PUBLIC FUNCTIONS PROTOTYPES ************/

/**
 * @brief  Initialize the gt911 communication bus
 *         from MCU to GT911 : ie I2C channel initialization (if required).
 * @param  DeviceAddr: Device address on communication Bus (I2C slave address of GT911).
 * @retval None
 */
uint8_t hycon_Init();

/**
 * @brief  Software Reset the gt911.
 * @param  DeviceAddr: Device address on communication Bus (I2C slave address of GT911).
 * @retval None
 */
void hycon_Reset();

/**
 * @brief  Read the gt911 device ID, pre initialize I2C in case of need to be
 *         able to read the GT911 device ID, and verify this is a GT911.
 * @param  DeviceAddr: I2C GT911 Slave address.
 * @retval The Device ID (two bytes).
 */
uint8_t hycon_ReadID();

/**
 * @brief  Configures the touch Screen IC device to start detecting touches
 * @param  DeviceAddr: Device address on communication Bus (I2C slave address).
 * @retval None.
 */
void hycon_TS_Start();

/**
 * @brief  Return if there is touches detected or not.
 *         Try to detect new touches and forget the old ones (reset internal global
 *         variables).
 * @param  DeviceAddr: Device address on communication Bus.
 * @retval : Number of active touches detected (can be 0, 1 or 2).
 */
uint8_t hycon_TS_DetectTouch(uint16_t *X, uint16_t *Y);

void	hycon_TS_SetTsPeriphDrv(TS_DrvPeriphTypeDef*);


/************ EXTERN FUNCTIONS ************/
extern TS_DrvTypeDef hycon_ts_drv;


#endif /* COMPONENTS_TOUCHDRIVERS_HYCON_HYCON_H_ */
