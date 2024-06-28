/*
 * settings.h
 *
 *  Created on: May 21, 2021
 *      Author: paoloc
 */

#ifndef SETTINGS_SETTINGS_H_
#define SETTINGS_SETTINGS_H_

#include "stdint.h"

// GENERIC
#define DEVICE_ADDR_PAGE1		0xAA
#define DEVICE_ADDR_PAGE2		0xA8
#define MEM_SETTINGS_SIZE		256

// BRIGHTNESS DEFINES
#define BRIGHTNESS_DEVICE_ADDR	0xAA
#define BRIGHTNESS_DEVICE_MEM	128
#define BRIGHTNESS_DEVICE_SIZE	1

// LANGUAGE DEFINES
#define LANGUAGE_DEVICE_ADDR	0xAA
#define LANGUAGE_DEVICE_MEM		129
#define LANGUAGE_DEVICE_SIZE	1

// USER
#define START_USER_ADDR 		0x00
#define TOT_USER_REG_SIZE		128
#define USER_DEVICE_ADDR		0xAA
#define USER_DEVICE_SIZE		2

typedef struct{
	void 		(*Toggle)(uint16_t, uint8_t);
	uint16_t 	(*Read)(uint16_t);
	void 		(*Write)(uint16_t, uint16_t);
	void 		(*WriteBit)(uint16_t, uint8_t, uint16_t);
}SettingsModuleTypDef;

SettingsModuleTypDef *pSettingsModule;

void 		InitSettings();
uint8_t 	ReadBrightness();
void 		WriteBrightness(uint8_t brightness);
uint8_t 	ReadLanguage();
void 		WriteLanguage(uint8_t lang);
void 		ToggleUserParameter(uint16_t address, uint8_t bit);
uint16_t 	ReadUserParameter(uint16_t address);
void		WriteUserParameter(uint16_t address, uint16_t value);
void 		WriteBitUserParameter(uint16_t address, uint8_t bit, uint16_t value);

void 		WriteSetting(uint16_t address, uint8_t len, uint8_t section, uint8_t value);
uint8_t 	ReadSetting(uint16_t address, uint8_t len, uint8_t section);

#endif /* SETTINGS_SETTINGS_H_ */
