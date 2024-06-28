/*
 * parameters.h
 *
 *  Created on: May 21, 2021
 *      Author: paoloc
 */

#ifndef PARAMETERS_PARAMETERS_H_
#define PARAMETERS_PARAMETERS_H_

#include "stdint.h"
#include "../Utils/utils.h"

BOOLEAN InitParameters(void);
BOOLEAN ReadParameters(uint8_t *pData,  uint16_t size, uint16_t DevAddress, uint16_t MemAddress);
BOOLEAN WriteParameters(uint8_t *pData,  uint16_t size, uint16_t DevAddress, uint16_t MemAddress);


#endif /* PARAMETERS_PARAMETERS_H_ */
