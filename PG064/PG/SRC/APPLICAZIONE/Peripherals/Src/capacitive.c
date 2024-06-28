/*
 * capacitive.c
 *
 *  Created on: 10 set 2021
 *      Author: paoloc
 */

#include "../Inc/capacitive.h"

#define	TOT_I2C_ATTEMPTS 3

I2C_HandleTypeDef Ts_Drv;


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  //printf("OPLAAAA %d\n", count++);
}

void TS_DeInit(I2C_HandleTypeDef* i2c_handler){
	if(i2c_handler != NULL)
		HAL_I2C_DeInit(i2c_handler);

	RESET_TS_PERIPH_STATUS();
}

uint8_t  DeInitCapacitive(void){
	TS_DeInit(&Ts_Drv);
	return AT_TRUE;
}

uint8_t  TS_IO_DeviceReady(uint16_t DevAddress){
	if(!TS_IO_Init())
		return AT_FALSE;

	return HAL_I2C_IsDeviceReady(&Ts_Drv, DevAddress, 3, 1000) == HAL_OK ? AT_TRUE : AT_FALSE;
}

uint8_t TS_IO_Init(){

	TS_DeInit(&Ts_Drv);

	Ts_Drv.Instance = I2C3;
	//Ts_Drv.Init.Timing = 0x00C0EAFF;  //	100
	Ts_Drv.Init.Timing = 0x00401959;	//  400
	Ts_Drv.Init.OwnAddress1 = 0;
	Ts_Drv.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	Ts_Drv.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	Ts_Drv.Init.OwnAddress2 = 0;
	Ts_Drv.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	Ts_Drv.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	Ts_Drv.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&Ts_Drv) != HAL_OK)
	{
		return AT_FALSE;
	}
	/** Configure Analogue filter
	*/
	if (HAL_I2CEx_ConfigAnalogFilter(&Ts_Drv, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	{
		return AT_FALSE;
	}
	/** Configure Digital filter
	*/
	if (HAL_I2CEx_ConfigDigitalFilter(&Ts_Drv, 0) != HAL_OK)
	{
		return AT_FALSE;
	}

	SET_TS_PERIPH_STATUS();
	return AT_TRUE;
}

/**
  * @brief  Reads multiple data.
  * @param  i2c_handler : I2C handler
  * @param  Addr: I2C address
  * @param  Reg: Reg address
  * @param  MemAddress: Memory address
  * @param  Buffer: Pointer to data buffer
  * @param  Length: Length of the data
  * @retval Number of read data
  */
HAL_StatusTypeDef I2Cx_ReadMultiple(I2C_HandleTypeDef* i2c_handler,
                                           uint8_t Addr,
                                           uint16_t Reg,
                                           uint16_t MemAddress,
                                           uint8_t* Buffer,
                                           uint16_t Length)
{
	uint8_t attempts = 0;
    HAL_StatusTypeDef status = HAL_ERROR;

    while(status == HAL_ERROR && attempts < TOT_I2C_ATTEMPTS){
    	status = HAL_I2C_Mem_Read(i2c_handler, Addr, (uint16_t)Reg, MemAddress, Buffer, Length, 200);
    	attempts++;
    }

    /* Check the communication status */
    if (status != HAL_OK)
    {
        /* I2C error occurred */
        TS_Error();
    }

    return status;
}

/**
  * @brief  Writes a value in a register of the device through BUS in using DMA mode.
  * @param  i2c_handler : I2C handler
  * @param  Addr: Device address on BUS Bus.
  * @param  Reg: The target register address to write
  * @param  MemAddress: Memory address
  * @param  Buffer: The target register value to be written
  * @param  Length: buffer size to be written
  * @retval HAL status
  */
HAL_StatusTypeDef I2Cx_WriteMultiple(I2C_HandleTypeDef* i2c_handler,
                                            uint8_t Addr,
                                            uint16_t Reg,
                                            uint16_t MemAddress,
                                            uint8_t* Buffer,
                                            uint16_t Length)
{
    HAL_StatusTypeDef status = HAL_OK;

    status = HAL_I2C_Mem_Write(i2c_handler, Addr, (uint16_t)Reg, MemAddress, Buffer, Length, 200);

    /* Check the communication status */
    if (status != HAL_OK)
    {
        /* Re-Initiaize the I2C Bus */
    	TS_Error();
    }
    return status;
}

/**
  * @brief  Writes a single data.
  * @param  Addr: I2C address
  * @param  Reg: Reg address
  * @param  Value: Data to be written
  * @retval None
  */
void TS_IO_Write(uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t Value)
{
    I2Cx_WriteMultiple(&Ts_Drv, Addr, (uint16_t)Reg, MemAddress, (uint8_t*)&Value, 1);
}

/**
  * @brief  Reads a single data.
  * @param  Addr: I2C address
  * @param  Reg: Reg address
  * @retval Data to be read
  */
uint16_t TS_IO_Read(uint8_t Addr, uint16_t Reg, uint16_t MemAddress)
{
    uint8_t read_value = 0;

    I2Cx_ReadMultiple(&Ts_Drv, Addr, Reg, MemAddress, (uint8_t*)&read_value, 1);

    return (uint16_t)read_value;
}

/**
  * @brief  Reads a single data.
  * @param  Addr: I2C address
  * @param  Reg: Reg address
  * @retval Data to be read
  */
uint8_t TS_IO_Read_Multiple(uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t* pData, uint8_t len)
{
	if(pData == NULL)
		return AT_FALSE;

	HAL_StatusTypeDef status = I2Cx_ReadMultiple(&Ts_Drv, Addr, Reg, MemAddress, pData, len);
    return status == HAL_OK ? AT_TRUE : AT_FALSE;
}


void TS_Error(void){
	TS_DeInit(&Ts_Drv);
	TS_IO_Init();
}

uint8_t  TS_IO_Status(){
	return Ts_Drv.ErrorCode == 0;
}
