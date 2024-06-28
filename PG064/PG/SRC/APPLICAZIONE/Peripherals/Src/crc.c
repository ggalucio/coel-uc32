/*
 * crc.c
 *
 *  Created on: Dec 14, 2021
 *      Author: paoloc
 */

#include "../Inc/crc.h"

CRC_HandleTypeDef hcrc;

BOOLEAN InitCrc(){
	hcrc.Instance = CRC;
	hcrc.Init.DefaultPolynomialUse = DEFAULT_POLYNOMIAL_ENABLE;
	hcrc.Init.DefaultInitValueUse = DEFAULT_INIT_VALUE_ENABLE;
	hcrc.Init.InputDataInversionMode = CRC_INPUTDATA_INVERSION_NONE;
	hcrc.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_DISABLE;
	hcrc.InputDataFormat = CRC_INPUTDATA_FORMAT_BYTES;
	return HAL_CRC_Init(&hcrc) == HAL_OK;
}

BOOLEAN DeInitCrc(){
	return HAL_CRC_DeInit(&hcrc) == HAL_OK;
}
