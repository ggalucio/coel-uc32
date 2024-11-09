/*
 * Extension.hpp
 *
 *  Created on: 26 de set de 2024
 *      Author: COELMATIC2022
 */

#ifndef MODULES_EXT_EXTENSION_HPP_
#define MODULES_EXT_EXTENSION_HPP_

#include <stdint.h>
#include <Module/Inc/enumerators.h>
#include <Module/Inc/enumerators_ext.h>

//  MODBUS RS485
extern void ReadWriteModbus485(uint16_t address, uint8_t decimal, DataType dataType, ReadMode readMode);
extern double ReadBufferModbus485(uint16_t address);

// JOB
extern void AddJob(int idx, DataType dataType, uint8_t decimal);
extern double ReadJob(int idx);

#endif /* MODULES_EXT_EXTENSION_HPP_ */
