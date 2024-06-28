/**
 ******************************************************************************
 * @file    gt911.c
 * @author  Joao Costa - costasjf@gmail.com
 * @brief   This file provides a set of functions needed to manage the GT911
 *          touch screen devices. This driver works with TouchGFX, using single
 *          point detection scheme.
 ******************************************************************************/

/************ INCLUDES ************/

#include "gt911.h"
#include "../Utils/utils.h"
//#include "../../Peripherals/Inc/capacitive.h"

/************ DEFINES ************/
#define GT911_I2C_ADDR  0xba

/* Touch screen driver structure initialization */
TS_DrvTypeDef gt911_ts_drv = {
		gt911_Init,
		gt911_ReadID,
		gt911_TS_Start,
		gt911_TS_DetectTouch,
		gt911_TS_SetTsPeriphDrv
};

TS_DrvPeriphTypeDef gt911_periph_drv;

/************ PRIVATE VARIABLES ************/

static gt911_handle_TypeDef gt911_ts_handle; //GT911 touch handle variable
static uint16_t coordX;
static uint16_t coordY;

/************ PUBLIC VARIABLES ************/


/************ PRIVATE FUNCTIONS PROTOTYPES ************/

/**
 * @brief  Returns if I2C was previous initialized or not.
 * @param  None.
 * @retval : I2C initialization status.
 */
static uint8_t gt911_Get_I2C_InitializedStatus(void);

/**
 * @brief  I2C initialize if needed.
 * @param  None.
 * @retval : None.
 */
static void gt911_I2C_InitializeIfRequired(void);

/**
 * @brief  Basic static configuration of TouchScreen
 * @param  DeviceAddr: GT911 Device address for communication on I2C Bus.
 * @retval Status GT911_STATUS_OK or GT911_STATUS_NOT_OK.
 */
static uint32_t gt911_TS_Configure(uint16_t DeviceAddr);


/************ PUBLIC FUNCTIONS DEFINITION ************/

void	gt911_TS_SetTsPeriphDrv(TS_DrvPeriphTypeDef* periph_drv){
	gt911_periph_drv = *periph_drv;
}

/**
 * @brief  Initializes the gt911 i2c communication bus from MCU to GT911
 * @param  DeviceAddr: gt911 address for i2c communication
 * @retval None
 */
uint8_t gt911_Init()
{
	if(!gt911_periph_drv.DeviceReady(GT911_I2C_ADDR))
		return AT_FALSE;

	if(!gt911_periph_drv.Init())
		return AT_FALSE;

	//Wait 200ms after power up before accessing gt911 registers
	gt911_periph_drv.Delay(200);

	/* Initialize I2C link if needed */
	gt911_I2C_InitializeIfRequired();

	gt911_ts_handle.i2cInitialized = GT911_I2C_NOT_INITIALIZED;
	gt911_ts_handle.currActiveTouchNb = 0;
	return AT_TRUE;
}

/**
 * @brief  Read the gt911 device ID, pre initialize I2C in case of need to be
 *         able to read the GT911 device ID, and verify this is a GT911.
 * @param  DeviceAddr: I2C GT911 Slave address.
 * @retval The Device ID (two bytes).
 */
uint8_t gt911_ReadID()
{
	uint8_t attemptscount = 0;
	uint8_t devicefounded = 0;

	//Initialize I2C link if needed
	gt911_I2C_InitializeIfRequired();

	//Maximum of 10 attempts to read ID
	for(attemptscount = 0; ((attemptscount < 9) && !(devicefounded)); attemptscount++)
	{
		//Read gt911 ID registers: ASCII -> "9110"
		if((gt911_periph_drv.Read(GT911_I2C_ADDR, GT911_CHIP_ID_REG1, MEMADD_SIZE_16BIT) == 0x39) && \
				(gt911_periph_drv.Read(GT911_I2C_ADDR, GT911_CHIP_ID_REG2, MEMADD_SIZE_16BIT) == 0x31) &&\
				(gt911_periph_drv.Read(GT911_I2C_ADDR, GT911_CHIP_ID_REG3, MEMADD_SIZE_16BIT) == 0x31) &&\
				(gt911_periph_drv.Read(GT911_I2C_ADDR, GT911_CHIP_ID_REG4, MEMADD_SIZE_16BIT) == 0x00))
		{
			/* Set device as found */
			devicefounded = 1;
		}
	}
	/* Return the device ID value */
	return devicefounded;
}

/**
 * @brief  Configures the touch Screen IC device to start detecting touches
 * @param  DeviceAddr: Device address on communication Bus (I2C slave address).
 * @retval None.
 */
void gt911_TS_Start()
{
	//uint8_t teste[2] = {0, 0};
	/* Minimum static configuration of GT911 */
	gt911_TS_Configure(GT911_I2C_ADDR);

	/* By default set GT911 IC in Polling mode : no INT generation on GT911 for new touch available */
	/* Note TS_INT is active low                                                                      */
	//gt911_TS_DisableIT(DeviceAddr);

	uint16_t chksum = 0;
	uint8_t checksum = 0;
	//	uint8_t touch_number = 0;

	//Reads current checksum value:
	checksum = gt911_periph_drv.Read(GT911_I2C_ADDR, 0x80FF, MEMADD_SIZE_16BIT);
	//	//Reads current touch number register velue:
	//	touch_number = TS_IO_Read(DeviceAddr, 0x804C);

	//Writes the number of touch points config register:
	gt911_periph_drv.Write(GT911_I2C_ADDR, 0x804C, MEMADD_SIZE_16BIT, 0x01);

	// Imposto il valore di soglia
	gt911_periph_drv.Write(GT911_I2C_ADDR, 0x8053, MEMADD_SIZE_16BIT, 90);	// Detected -> default: 90
	gt911_periph_drv.Write(GT911_I2C_ADDR, 0x8054, MEMADD_SIZE_16BIT, 60);	// Released -> default: 60
	gt911_periph_drv.Write(GT911_I2C_ADDR, 0x804D, MEMADD_SIZE_16BIT, 8);		// Axis switch over

	//Calculates new checksum:
	for(uint16_t reg = 0x8047; reg <= 0x80FE; ++reg)
	{
		chksum += gt911_periph_drv.Read(GT911_I2C_ADDR, reg, MEMADD_SIZE_16BIT);
	}
	chksum = ~chksum +1;
	checksum = (uint8_t)chksum;

	gt911_periph_drv.Write(GT911_I2C_ADDR, 0x80FF, MEMADD_SIZE_16BIT, checksum);
	gt911_periph_drv.Write(GT911_I2C_ADDR, 0x8100, MEMADD_SIZE_16BIT, 0x01);

	gt911_periph_drv.Write(GT911_I2C_ADDR, 0x8041, MEMADD_SIZE_16BIT, 0x00);

	gt911_periph_drv.Delay(10);

	//Cleans the status register for the new touch read
	gt911_periph_drv.Write(GT911_I2C_ADDR, GT911_TP_STAT_REG, MEMADD_SIZE_16BIT, 0);

	/* By default set GT911 IC in Polling mode : no INT generation on GT911 for new touch available */
	/* Note TS_INT is active low                                                                      */
	//gt911_TS_DisableIT(DeviceAddr);
}

/**
 * @brief  Return if there is touches detected or not.
 *         Try to detect new touches and forget the old ones (reset internal global
 *         variables).
 * @param  DeviceAddr: Device address on communication Bus.
 * @retval : Number of active touches detected (can be 0, 1 or 2).
 */

uint8_t coordinates[4] = {0, 0, 0, 0};

uint8_t gt911_TS_DetectTouch(uint16_t *X, uint16_t *Y)
{
	volatile uint8_t nbTouch = 0;
	volatile uint8_t touch_status = 0;
	volatile uint8_t ucReadData = 0;
	static uint16_t coord;

	//Read register GT911_TD_STAT_REG to check number of touches detection
	touch_status = gt911_periph_drv.Read(GT911_I2C_ADDR, GT911_TP_STAT_REG, MEMADD_SIZE_16BIT);
	//touch_status = TS_IO_Read(DeviceAddr, 0x81A8);
	nbTouch = touch_status & GT911_4LSB_MASK; //Just the 4 LSB refers to active touch points

	if(touch_status)
	{
		ucReadData = gt911_periph_drv.Read(GT911_I2C_ADDR, 0x8150, MEMADD_SIZE_16BIT);
		coord = (ucReadData & GT911_TOUCH_POS_LSB_MASK) >> GT911_TOUCH_POS_LSB_SHIFT;
		/* Read high part of X position */
		ucReadData = gt911_periph_drv.Read(GT911_I2C_ADDR, 0x8151, MEMADD_SIZE_16BIT);
		coord |= ((ucReadData & GT911_TOUCH_POS_MSB_MASK) >> GT911_TOUCH_POS_MSB_SHIFT) << 8;
		/* Send back ready X position to caller */
		*X = coord;
		coordX = coord;
		/* Read low part of Y position */
		ucReadData = gt911_periph_drv.Read(GT911_I2C_ADDR, 0x8152, MEMADD_SIZE_16BIT);
		coord = (ucReadData & GT911_TOUCH_POS_LSB_MASK) >> GT911_TOUCH_POS_LSB_SHIFT;
		/* Read high part of Y position */
		ucReadData = gt911_periph_drv.Read(GT911_I2C_ADDR, 0x8153, MEMADD_SIZE_16BIT);
		coord |= ((ucReadData & GT911_TOUCH_POS_MSB_MASK) >> GT911_TOUCH_POS_MSB_SHIFT) << 8;
		/* Send back ready Y position to caller */
		*Y = coord;
        coordY = coord;
		//Cleans the status register for the new touch read
        gt911_periph_drv.Write(GT911_I2C_ADDR, GT911_TP_STAT_REG, MEMADD_SIZE_16BIT, 0);

		//Is data ready for reading and touch detected?
		if(nbTouch > 1)
		{
			nbTouch = 0;
		}
	}

	/* Update gt911 driver internal global : current number of active touches */
	gt911_ts_handle.currActiveTouchNb = nbTouch;

	return(nbTouch);
}


/* Static functions bodies-----------------------------------------------*/


/**
 * @brief  Return the status of I2C was initialized or not.
 * @param  None.
 * @retval : I2C initialization status.
 */
static uint8_t gt911_Get_I2C_InitializedStatus(void)
{
	return(gt911_ts_handle.i2cInitialized);
}

/**
 * @brief  I2C initialize if needed.
 * @param  None.
 * @retval : None.
 */
static void gt911_I2C_InitializeIfRequired(void)
{
	if(gt911_Get_I2C_InitializedStatus() == GT911_I2C_NOT_INITIALIZED)
	{
		/* Initialize TS IO BUS layer (I2C) */
		//TS_IO_Init();

		/* Set state to initialized */
		gt911_ts_handle.i2cInitialized = GT911_I2C_INITIALIZED;
	}
}

/**
 * @brief  Basic static configuration of TouchScreen
 * @param  DeviceAddr: GT911 Device address for communication on I2C Bus.
 * @retval Status GT911_STATUS_OK or GT911_STATUS_NOT_OK.
 */
static uint32_t gt911_TS_Configure(uint16_t DeviceAddr)
{
	uint32_t status = GT911_STATUS_OK;

	/* Nothing special to be done for GT911 */

	return(status);
}
