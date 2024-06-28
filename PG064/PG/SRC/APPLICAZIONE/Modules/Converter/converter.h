/*
 * converter.h
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#ifndef CONVERTER_CONVERTER_H_
#define CONVERTER_CONVERTER_H_

#include "Utils/integer.h"

void 	FromCharToAddress(char const* addressStr, int* address, int* bit);
void 	ConvertData(BYTE dataType, double value, BYTE decimal, DWORD *intValue, BYTE* nWords);

#endif /* CONVERTER_CONVERTER_H_ */
