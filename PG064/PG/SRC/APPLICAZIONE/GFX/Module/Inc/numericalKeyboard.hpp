/*
 * numericalKeyboard.h
 *
 *  Created on: 27 mag 2021
 *      Author: paoloc
 */

#ifndef MODULES_NUMERICALKEYBOARD_NUMERICALKEYBOARD_HPP_
#define MODULES_NUMERICALKEYBOARD_NUMERICALKEYBOARD_HPP_

#include <touchgfx/widgets/TextArea.hpp>
#include "enumerators.h"

void 	InitNumericalKeyboard(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer, uint16_t buffSize, touchgfx::TextArea *errTxt);
void 	AddNumericalKeyboardReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update, void (*pUpdateModbus)(uint16_t address, double value, uint8_t dataType), uint16_t address);
void 	AddRTCNumericalKeyboardReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, RTCType type, uint8_t update);
void    InitPasswordNumKeyboard(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer);
void    GetRangeValues(double* min, double *max, DataType* dataType,  RTCType* rtc, uint8_t* decimal);
void 	UpdatePwdNumericalKeyboard();
void 	AddNumericalKeyboard(char value);
void 	RemoveNumericalKeyboard();
double  GetNumericalKeyboardValue(touchgfx::TextArea **area, touchgfx::Unicode::UnicodeChar** buff, DataType* dataType,  uint8_t* decimal, uint8_t* update, void (**pUpdateModbus)(uint16_t address, double value, uint8_t dataType), uint16_t* address);
uint8_t CredentialSuccess();

void	SetAccessKey(uint16_t key);

#endif /* MODULES_NUMERICALKEYBOARD_NUMERICALKEYBOARD_HPP_ */
