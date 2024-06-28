/*
 * InterfaceUtils.h
 *
 *  Created on: 1 mar 2021
 *      Author: paoloc
 */

#ifndef UTILS_INTERFACEUTILS_H_
#define UTILS_INTERFACEUTILS_H_

#include "utils.h"
#include "integer.h"

#define WRITE_INVALIDATE_BIT 	0
#define WRITE_BY_USER_BIT 		1

#define READ_INVALIDATE_BIT 	0
#define READ_ONCE_BIT 			1
#define READ_GUI_REFRESH_BIT_1 	2
#define READ_GUI_REFRESH_BIT_2 	3

typedef struct
{
	DWORD 		baseAddress;
	DWORD 		value;
	BYTE		length;
	BYTE 		decimal;
	BYTE 		command;
}InterfaceData;

typedef struct{
	WORD 		Address;
	BYTE		Length;
}BaseRegTypeDef;

typedef struct{
	BOOLEAN valid;
	BYTE pBuff[BUFFER_SIZE];
	BYTE length;
}BufferTypeDef;

#endif /* UTILS_INTERFACEUTILS_H_ */
