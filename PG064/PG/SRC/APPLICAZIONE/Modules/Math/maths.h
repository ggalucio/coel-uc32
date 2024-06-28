/*
 * maths.h
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#ifndef MATH_MATHS_H_
#define MATH_MATHS_H_

#include "stdint.h"
#include "Utils/integer.h"

const char* GetDecimalFormat(uint8_t decimal);
double  	FromFloatingPointToDecimalSinglePrecision(const double value);
uint32_t	FromDecimalToFloatingPointSinglePrecision(const double value);



#endif /* MATH_MATHS_H_ */
