/*
 * capacitive.h
 *
 *  Created on: 10 set 2021
 *      Author: paoloc
 */

#ifndef INC_CAPACITIVE_H_
#define INC_CAPACITIVE_H_

#include "touch.h"

uint8_t  DeInitCapacitive(void);
uint8_t  TS_IO_Init(void);
uint8_t  TS_IO_DeviceReady(uint16_t DevAddress);
void     TS_IO_Write(uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t Value);
uint16_t TS_IO_Read(uint8_t Addr, uint16_t Reg, uint16_t MemAddress);
uint8_t  TS_IO_Read_Multiple(uint8_t Addr, uint16_t Reg, uint16_t MemAddress, uint8_t* pData, uint8_t len);
void 	 TS_Error(void);
uint8_t  TS_IO_Status(void);

#endif /* INC_CAPACITIVE_H_ */
