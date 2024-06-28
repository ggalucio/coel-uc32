/*
 * mpu.c
 *
 *  Created on: 14 giu 2021
 *      Author: paoloc
 */


#include "../Inc/mpu.h"

void DeInitMpu(void){
	HAL_MPU_Disable();
	SCB_DisableICache();
	SCB_DisableDCache();
}
void InitMpu(void){

	 /* Enable I-Cache---------------------------------------------------------*/
	  SCB_EnableICache();

	  /* Enable D-Cache---------------------------------------------------------*/
	  SCB_EnableDCache();

	 MPU_Region_InitTypeDef MPU_InitStruct = {0};

	  /* Disables the MPU */
	  HAL_MPU_Disable();
	  /** Initializes and configures the Region and the memory to be protected
	  */
	  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
	  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
	  MPU_InitStruct.BaseAddress = 0x90000000;
	  MPU_InitStruct.Size = MPU_REGION_SIZE_256MB;
	  MPU_InitStruct.SubRegionDisable = 0x0;
	  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
	  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
	  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
	  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
	  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
	  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

	  HAL_MPU_ConfigRegion(&MPU_InitStruct);
	  /** Initializes and configures the Region and the memory to be protected
	  */
	  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
	  MPU_InitStruct.Number = MPU_REGION_NUMBER1;
	  MPU_InitStruct.BaseAddress = 0x90000000;
	  MPU_InitStruct.Size = MPU_REGION_SIZE_16MB;
	  MPU_InitStruct.SubRegionDisable = 0x0;
	  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
	  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
	  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
	  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
	  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
	  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

	  HAL_MPU_ConfigRegion(&MPU_InitStruct);
	  /* Enables the MPU */
	  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}
