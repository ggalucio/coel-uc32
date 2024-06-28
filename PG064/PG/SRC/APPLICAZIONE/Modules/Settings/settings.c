/*
 * settings.c
 *
 *  Created on: May 21, 2021
 *      Author: paoloc
 */


#include "settings.h"
#include "../Peripherals/Inc/parameters.h"

SettingsModuleTypDef settingsModule = {
		ToggleUserParameter,
		ReadUserParameter,
		WriteUserParameter,
		WriteBitUserParameter
};

/**
 * Setting initialization function.
 */
void InitSettings(){
	InitParameters();
	pSettingsModule = &settingsModule;
}

/**
 * Toggle bit user parameter value stored in FRAM.
 * User parameter are stored as WORD values, so address is multiplied by two
 * @param address	: user parameter start address.
 * @param bit		: bit number to toggle.
 */
void ToggleUserParameter(uint16_t address, uint8_t bit){
	uint16_t addr = address * 2;
	if(addr < START_USER_ADDR || addr > (START_USER_ADDR + TOT_USER_REG_SIZE))
		return;

	uint8_t registers[USER_DEVICE_SIZE];
	ReadParameters(registers, USER_DEVICE_SIZE, USER_DEVICE_ADDR, addr);

	uint8_t idx 	= bit / BYTE_BIT_NUM;
	uint8_t new_bit = bit % BYTE_BIT_NUM;

	AT_TOGGLE_BIT(registers[idx], new_bit);
	WriteParameters(registers, USER_DEVICE_SIZE, USER_DEVICE_ADDR, addr);
}

/**
 * Set bit user parameter value stored in FRAM.
 * User parameter are stored as WORD values, so address is multiplied by two
 * @param address	: user parameter start address.
 * @param bit		: bit number to set.
 * @param value		: bit value to set. It should be or 0 or 1.
 */
void WriteBitUserParameter(uint16_t address, uint8_t bit, uint16_t value){
	uint16_t addr = address * 2;
	if(addr < START_USER_ADDR || addr > (START_USER_ADDR + TOT_USER_REG_SIZE))
		return;

	uint8_t registers[USER_DEVICE_SIZE];
	ReadParameters(registers, USER_DEVICE_SIZE, USER_DEVICE_ADDR, addr);

	uint8_t idx 	= bit / BYTE_BIT_NUM;
	uint8_t new_bit = bit % BYTE_BIT_NUM;

	if(value)
		AT_SET_BIT(registers[idx], new_bit);
	else
		AT_CLEAR_BIT(registers[idx], new_bit);

	WriteParameters(registers, USER_DEVICE_SIZE, USER_DEVICE_ADDR, addr);
}

/**
 * Read user parameter stored in FRAM
 * User parameter are stored as WORD values, so address is multiplied by two
 * @param address: user parameter start address.
 */
uint16_t ReadUserParameter(uint16_t address){
	uint16_t addr = address * 2;
	if(addr < START_USER_ADDR || addr > (START_USER_ADDR + TOT_USER_REG_SIZE))
		return 0;

	uint8_t registers[USER_DEVICE_SIZE];
	ReadParameters(registers, USER_DEVICE_SIZE, USER_DEVICE_ADDR, addr);

	uint16_t reg = registers[0] | (registers[1] << BYTE_BIT_NUM);
	return reg;
}

/**
 * Store user parameter in FRAM
 * User parameter are stored as WORD values, so address is multiplied by two
 * @param address: 	user parameter start address.
 * @param value: 	value to store.
 */
void WriteUserParameter(uint16_t address, uint16_t value){
	uint16_t addr = address * 2;
	if(addr < START_USER_ADDR || addr > (START_USER_ADDR + TOT_USER_REG_SIZE))
		return;

	uint8_t values[USER_DEVICE_SIZE];
	values[0] =	value & BYTE_MASK;
	values[1] =	( value >> BYTE_BIT_NUM ) & BYTE_MASK;

	WriteParameters(values, USER_DEVICE_SIZE, USER_DEVICE_ADDR, addr);
}

/**
 * Read display setted brightness value.
 * @param none.
 */
uint8_t ReadBrightness(){
	uint8_t brightness = 0;
	ReadParameters(&brightness, BRIGHTNESS_DEVICE_SIZE, BRIGHTNESS_DEVICE_ADDR, BRIGHTNESS_DEVICE_MEM);
	return brightness;
}

/**
 * Set new display setted brightness value.
 * @param brightness: 	brightness to set. This value should be between 10 and 100.
 */
void WriteBrightness(uint8_t brightness){
	WriteParameters(&brightness, BRIGHTNESS_DEVICE_SIZE, BRIGHTNESS_DEVICE_ADDR, BRIGHTNESS_DEVICE_MEM);
}

uint8_t ReadLanguage(){
	uint8_t lang = 0;
	ReadParameters(&lang, LANGUAGE_DEVICE_SIZE, LANGUAGE_DEVICE_ADDR, LANGUAGE_DEVICE_MEM);
	return lang;
}

void WriteLanguage(uint8_t lang){
	WriteParameters(&lang, LANGUAGE_DEVICE_SIZE, LANGUAGE_DEVICE_ADDR, LANGUAGE_DEVICE_MEM);
}

uint8_t ReadSetting(uint16_t address, uint8_t len, uint8_t section){
	uint8_t reg = 0;
	ReadParameters(&reg, len, section, address);
	return reg;
}

void WriteSetting(uint16_t address, uint8_t len, uint8_t section, uint8_t value){
	WriteParameters(&value, len, section, address);
}
