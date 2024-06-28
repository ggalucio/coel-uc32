/*
 * enumerators.h
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#ifndef MODULE_ENUMERATORS_H_
#define MODULE_ENUMERATORS_H_

typedef enum{
	READ,
	WRITE,
	READWRITE
}Access;

typedef enum{
	RM_NONE = 0,
	ONCE,
	REPEAT
}ReadMode;

typedef enum{
	DT_NONE = 0,
	_INT_,
	_INT2_,
	_DOUBLE_,
	_STRING_,
	_FP_32BIT_
}DataType;

typedef enum{
	RTC_NONE,
	_HOUR_,
	_MIN_,
	_SEC_,
	_DAY_,
	_MONTH_,
	_YEAR_
}RTCType;

typedef enum{
	PROTOCOL_NONE,
	MB_RS485,
	MB_TCPIP,
	MB_TTL,
	MB_INT,
	PT_HDX,
	PT_JOB
}Protocol;

#endif /* MODULE_ENUMERATORS_H_ */
