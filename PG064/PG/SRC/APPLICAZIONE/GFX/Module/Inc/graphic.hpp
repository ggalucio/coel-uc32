/*
 * graphic.hpp
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#ifndef MODULE_SRC_GRAPHIC_HPP_
#define MODULE_SRC_GRAPHIC_HPP_

#include "GraphicItems.hpp"

extern "C" void InitGraphicModulePtr(void);
extern "C" void RefreshUIRS485(uint16_t address, uint32_t value);
extern "C" void RefreshUITCPIP(uint16_t address, uint32_t value);
extern "C" void RefreshUITTL(uint16_t address, uint32_t value);
extern "C" void RefreshUIINT(uint16_t address, uint32_t value);

void InitGraphicModulePtr(void);
void RefreshUIRS485(uint16_t address, uint32_t value);
void RefreshUITCPIP(uint16_t address, uint32_t value);
void RefreshUITTL(uint16_t address, uint32_t value);
void RefreshUIINT(uint16_t address, uint32_t value);

#endif /* MODULE_SRC_GRAPHIC_HPP_ */
