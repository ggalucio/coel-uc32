/*
 * AT_module.cpp
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#include "AT_module.hpp"
#include "Module/modulePlus.hpp"
#include "stdlib.h"
#include "string.h"

extern "C" {
	#include <Module/module.h>
}

extern void ClearOthers(void);
extern void UpdateJobsOthers(void);

bool enableSoundBuzzer = true;

void DecreaseDouble(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, double step, double minVal, double maxVal, uint8_t decimal);
void IncreaseDouble(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, double step, double minVal, double maxVal, uint8_t decimal);
void DecreaseInt(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, int step, int minVal, int maxVal, DataType dataType);
void IncreaseInt(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, int step, int minVal, int maxVal, DataType dataType);
void WriteDateTime(uint8_t value, RTCType type);
int waitCount = 0;

void Clear()
{
	ClearOthers();

	waitCount = 0;

	if(pClearItems)
		(*pClearItems)();

	if(pClearModbusRS485)
		(*pClearModbusRS485)();
	if(pClearModbusTCPIP)
		(*pClearModbusTCPIP)();
	if(pClearModbusTTL)
		(*pClearModbusTTL)();
	if(pClearModbusINT)
		(*pClearModbusINT)();

	Wait(50);
}

void ClearWrites(){
	if(pClearWritesModbusRS485)
		(*pClearWritesModbusRS485)();
	if(pClearWritesModbusTCPIP)
		(*pClearWritesModbusTCPIP)();
	if(pClearWritesModbusTTL)
		(*pClearWritesModbusTTL)();
}

void Wait(uint32_t ms){
	if(pWaitFor)
		(*pWaitFor)(ms);
}

/****************************************** TEXT AREA MANAGE *****************************************************************/

void IncreaseInt(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, int step, int minVal, int maxVal, DataType dataType){
	int value = touchgfx::Unicode::atoi(buffer) + step;

	if(value > maxVal)
		value = minVal;

	Update(textArea, buffer, (double)value, dataType, 0);
}

void DecreaseInt(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, int step, int minVal, int maxVal, DataType dataType){
	int value = touchgfx::Unicode::atoi(buffer) - step;

	if(value < minVal)
		value = maxVal;

	Update(textArea, buffer, (double)value, dataType, 0);
}

void IncreaseDouble(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, double step, double minVal, double maxVal, uint8_t decimal){
	double value = 0;
	if(pFromUnicodeToDouble)
		value = (*pFromUnicodeToDouble)(buffer) + step;

	if(value > maxVal)
		value = minVal;

	Update(textArea, buffer, (double)value, _DOUBLE_, decimal);
}

void DecreaseDouble(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, double step, double minVal, double maxVal, uint8_t decimal){
	double value = 0;
		if(pFromUnicodeToDouble)
			value = (*pFromUnicodeToDouble)(buffer) - step;

	if(value < minVal)
		value = maxVal;

	Update(textArea, buffer, (double)value, _DOUBLE_, decimal);
}

void Increase(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, double step, double minVal, double maxVal, DataType dataType, uint8_t decimal){
	switch(dataType){
		case _INT_:
		case _INT2_:
			IncreaseInt(textArea, buffer, (int)step, (int)minVal, (int)maxVal, dataType);
			break;
		case _DOUBLE_:
			IncreaseDouble(textArea, buffer, step, minVal, maxVal, decimal);
			break;
		default:
			break;
	}
}

void Decrease(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, double step, double minVal, double maxVal, DataType dataType, uint8_t decimal){
	switch(dataType){
		case _INT_:
		case _INT2_:
			DecreaseInt(textArea, buffer, (int)step, (int)minVal, (int)maxVal, dataType);
			break;
		case _DOUBLE_:
			DecreaseDouble(textArea, buffer, step, minVal, maxVal, decimal);
			break;
		default:
			break;
	}
}

void Update(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, double value, DataType dataType, uint8_t decimal){

	if(textArea != nullptr && buffer != nullptr && pGetDecimalFormat)
	{
		const char* format = (*pGetDecimalFormat)(decimal);

		switch(dataType){
			case _INT_:
				touchgfx::Unicode::snprintf(buffer, 10, "%d", (int)value);
				break;
			case _INT2_:
				touchgfx::Unicode::snprintf(buffer, 10, "%02d", (int)value);
				break;
			case _DOUBLE_:
			case _FP_32BIT_:
				touchgfx::Unicode::snprintfFloat(buffer, 10, format, value);
				break;
			default:
				break;
		}

		textArea->invalidate();
	}
}

/*****************************************************************************************************************************/

/********************************************* MODBUS TCPIP ******************************************************************/

void SetModbusTCPIPAs(uint8_t mode){
	if(pSetModeTCPIP)
		(*pSetModeTCPIP)(mode, 0);
}

void ReadWriteModbusTCPIP(char const* address, ReadMode readMode){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, readMode, 1);
	if(pAddModbusTCPIPWriteItem)
		(*pAddModbusTCPIPWriteItem)(addr, 0, 1);
}

void ReadWriteModbusTCPIP(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal, DataType dataType, ReadMode readMode){
	int addr = 0, bit = 0;
	uint8_t len = 0;

	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);


	switch(dataType){
		case _FP_32BIT_:
			len = 2;
			//addr++;
			break;
		default:
			len = 1;
			break;
	}


	if(pAddItem)
		(*pAddItem)(textArea, buffer, addr, dataType, decimal, MB_TCPIP);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, decimal, readMode, len);
	if(pAddModbusTCPIPWriteItem)
		(*pAddModbusTCPIPWriteItem)(addr, decimal, len);
}

void ImageModbusTCPIP(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddImageItem)
		(*pAddImageItem)(image, addr, bit, bitmapOn, bitmapOff, MB_TCPIP);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
}

void ImageWordModbusTCPIP(touchgfx::Image *image, char const* address, uint16_t value, uint16_t bitmap){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddImageWordItem)
		(*pAddImageWordItem)(image, addr, value, bitmap, MB_TCPIP);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
}

void ReadModbusTCPIPTextAssocBit(touchgfx::TextArea* textArea, char const* address, TEXTS textOn, TEXTS textOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddTextBitItem)
		(*pAddTextBitItem)(addr, bit, textArea, textOn, textOff, MB_TCPIP);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
}

void ButtonModbusTCPIP(touchgfx::Button* button, char const* address, uint16_t bitmapOn, uint16_t bitmapOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddToggleItem)
		(*pAddToggleItem)(button, addr, bit, bitmapOn, bitmapOff, MB_TCPIP);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
}

void ButtonTCPIPVisibility(touchgfx::Button* button, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
	if(pAddButtonVisibilityItem)
		(*pAddButtonVisibilityItem)(button, addr, bit, value, MB_TCPIP);
}

void FlexButtonTCPIPVisibility(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* button, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
	if(pAddFlexButtonVisibility)
		(*pAddFlexButtonVisibility)(button, addr, bit, value, MB_TCPIP);
}

void TextTCPIPVisibility(touchgfx::TextArea* textArea, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
	if(pAddTextVisibilityItem)
		(*pAddTextVisibilityItem)(textArea, addr, bit, value, MB_TCPIP);
}

void ContainerTCPIPVisibility(touchgfx::Container* container, char const* address, uint8_t condition){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
	if(pAddContainerVisibilityItem)
		(*pAddContainerVisibilityItem)(container, addr, bit, condition, MB_TCPIP);
}

void ImageTCPIPVisibility(touchgfx::Image* image, char const* address, uint8_t condition){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
	if(pAddImageVisibilityItem)
		(*pAddImageVisibilityItem)(image, addr, bit, condition, MB_TCPIP);
}

void ButtonTCPIPImageState(touchgfx::Button* button, char const* address, uint16_t value, uint16_t imgOn, uint16_t imgOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
	if(pAddButtonImageStateItem)
		(*pAddButtonImageStateItem)(button, addr, imgOn, imgOff, value, MB_TCPIP);
}

void ReadModbusTCPIPAlarm(char const* address, TEXTS message, TEXTS invMessage){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
	if(pAddAlarmItem)
		(*pAddAlarmItem)(addr, bit, message, invMessage, MB_TCPIP);
}

void ToggleModbusTCPIP(char const* address){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pToggleBitModbusTCPIP)
		(*pToggleBitModbusTCPIP)(addr, bit);

	Wait(50);
}

void UpdateModbusTCPIP(touchgfx::Unicode::UnicodeChar* buffer, char const* address, DataType dataType){
	double value = 0;

	if(pFromUnicodeToDouble)
		value = (*pFromUnicodeToDouble)(buffer);

	UpdateModbusTCPIP(address, value, dataType);
}

void UpdateModbusTCPIP(uint16_t address, double value, DataType dataType){
	if(pUpdateModbusTCPIP)
		(*pUpdateModbusTCPIP)(address, value, (uint8_t)dataType);

	Wait(50);
}

void UpdateModbusTCPIP(char const* address, double value, DataType dataType){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pUpdateModbusTCPIP)
		(*pUpdateModbusTCPIP)(addr, value, (uint8_t)dataType);

	Wait(50);
}

void SetBitModbusTCPIP(char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pUpdateBitModbusTCPIP)
		(*pUpdateBitModbusTCPIP)(addr, bit, value);
}

void BlinkImageModbusTCPIP(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint32_t ms){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	if(pAddBlinkImageModbusItem)
		(*pAddBlinkImageModbusItem)(image, addr, bit, bitmapOn, bitmapOff, value, ms, MB_TCPIP);

	ReadWriteModbusTCPIP(address, REPEAT);
}

void BlinkTxtModbusTCPIP(touchgfx::TextArea* text, char const* address, uint8_t value, uint32_t ms){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	if(pAddTxtImageModbusItem)
		(*pAddTxtImageModbusItem)(text, addr, bit, value, ms, MB_TCPIP);

	ReadWriteModbusTCPIP(address, REPEAT);
}

void ModbusTCPIPErrCommContainerVisibility(touchgfx::Container* container, uint16_t time){
	if(pAddModbusErrCommContainerVisibility)
		(*pAddModbusErrCommContainerVisibility)(container, time, MB_TCPIP);
}

void ButtonPressedDlyTCPIP(touchgfx::Button* button, char const* address, int16_t value, uint16_t dly, uint16_t dataType){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddButtonPressedDlyItem)
		(*pAddButtonPressedDlyItem)(button, addr, bit, value, dly, dataType, NULL, MB_TCPIP);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);
}

void SetModbusTCPIPErrCommReadByUser(){
	if(pSetTimerTCPIP)
		(*pSetTimerTCPIP)();
}

void WriteModbusTCPIP(char const* address, uint8_t length){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPWriteItem)
		(*pAddModbusTCPIPWriteItem)(addr, 0, length);
}

void SendJobIdModbusTCPIP(char const* address){
	if(pGetSelectedJob){
		uint32_t jobNum = pGetSelectedJob() + 1;
		UpdateModbusTCPIP(address, (double)jobNum, _INT_);
	}
}

void SendJobParamAtModbusTCPIP(char const* address, int idx, DataType dataType){
	if(pReadJobData && pFromFloatingPointToDecimalSinglePrecision){
		double decValueJobata = ReadJobData(idx, dataType);
		UpdateModbusTCPIP(address, decValueJobata, dataType);
	}
}

void ReadJobNameModbusTCPIP(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t length){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	int i;
	for(i = 0; i < length && pAddModbusTCPIPReadItem; i++){
		(*pAddModbusTCPIPReadItem)(addr + i, 0, REPEAT, 1);
	}

	if(pAddReadJobNameItem)
		(*pAddReadJobNameItem)(textArea, buffer, addr, length, MB_TCPIP);
}

void SendJobNameModbusTCPIP(char const* address, uint8_t length){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	StartAcceptingIncomingRecipes();

	if(pReadJobName){
		char name[20];
		(*pReadJobName)(name);
		int len = strlen(name);
		memset(&name[len], 0, sizeof(char) * (20 - len));
		int i;
		uint8_t offsetAddr = 0;
		for(i = 0; i < len; i += 2){
			char strL = name[i + 0];
			char strH = name[i + 1];
			uint16_t strW = (strH << 8) | strL;
			UpdateModbusTCPIP(addr + offsetAddr, (double)strW, _INT_);
			offsetAddr++;
		}

		UpdateModbusTCPIP(addr + offsetAddr, 0, _INT_);
	}

	StopAcceptingIncomingRecipes();
}

void CircularProgressTCPIP(touchgfx::CircleProgress* progress, char const* address, DataType dataType){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	if(pAddCircularProgressItem)
		(*pAddCircularProgressItem)(progress, addr, dataType, MB_TCPIP);
}

void AddNumKeyboardReferenceTCPIP(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update, uint16_t address){
	if(pAddNumericalKeyboardReference)
		(*pAddNumericalKeyboardReference)(textArea, textBuffer, min, max, dataType, decimal, update, pUpdateModbusTCPIP, address);
}

void AddNumKeyboardReferenceTCPIP(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update){
	if(pAddNumericalKeyboardReference)
		(*pAddNumericalKeyboardReference)(textArea, textBuffer, min, max, dataType, decimal, update, pUpdateModbusTCPIP, 0);
}

void BeepTCPIP(const char* address, uint32_t ms){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);

	if(pBeep)
		(*pBeep)(addr, bit, ms, MB_TCPIP);
}

/*****************************************************************************************************************************/

/********************************************* MODBUS TTL ******************************************************************/

void SetModbusTTLAs(uint8_t mode, uint32_t baud){
	if(pSetModeTTL)
		(*pSetModeTTL)(mode, baud);
}

void ReadWriteModbusTTL(char const* address, ReadMode readMode){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, readMode, 1);
	if(pAddModbusTTLWriteItem)
		(*pAddModbusTTLWriteItem)(addr, 0, 1);
}

void ReadWriteModbusTTL(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal, DataType dataType, ReadMode readMode){
	int addr = 0, bit = 0;
	uint8_t len = 0;

	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);


	switch(dataType){
		case _FP_32BIT_:
			len = 2;
			//addr++;
			break;
		default:
			len = 1;
			break;
	}


	if(pAddItem)
		(*pAddItem)(textArea, buffer, addr, dataType, decimal, MB_TTL);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, decimal, readMode, len);
	if(pAddModbusTTLWriteItem)
		(*pAddModbusTTLWriteItem)(addr, decimal, len);
}

void ImageModbusTTL(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddImageItem)
		(*pAddImageItem)(image, addr, bit, bitmapOn, bitmapOff, MB_TTL);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
}

void ReadModbusTTLTextAssocBit(touchgfx::TextArea* textArea, char const* address, TEXTS textOn, TEXTS textOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddTextBitItem)
		(*pAddTextBitItem)(addr, bit, textArea, textOn, textOff, MB_TTL);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
}

void ButtonModbusTTL(touchgfx::Button* button, char const* address, uint16_t bitmapOn, uint16_t bitmapOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddToggleItem)
		(*pAddToggleItem)(button, addr, bit, bitmapOn, bitmapOff, MB_TTL);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
}

void ButtonTTLVisibility(touchgfx::Button* button, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
	if(pAddButtonVisibilityItem)
		(*pAddButtonVisibilityItem)(button, addr, bit, value, MB_TTL);
}

void FlexButtonTTLVisibility(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* button, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
	if(pAddFlexButtonVisibility)
		(*pAddFlexButtonVisibility)(button, addr, bit, value, MB_TTL);
}

void TextTTLVisibility(touchgfx::TextArea* textArea, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
	if(pAddTextVisibilityItem)
		(*pAddTextVisibilityItem)(textArea, addr, bit, value, MB_TTL);
}

void ContainerTTLVisibility(touchgfx::Container* container, char const* address, uint8_t condition){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
	if(pAddContainerVisibilityItem)
		(*pAddContainerVisibilityItem)(container, addr, bit, condition, MB_TTL);
}

void ImageWordModbusTTL(touchgfx::Image *image, char const* address, uint16_t value, uint16_t bitmap){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddImageWordItem)
		(*pAddImageWordItem)(image, addr, value, bitmap, MB_TTL);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
}

void ImageTTLVisibility(touchgfx::Image* image, char const* address, uint8_t condition){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
	if(pAddImageVisibilityItem)
		(*pAddImageVisibilityItem)(image, addr, bit, condition, MB_TTL);
}

void ButtonTTLImageState(touchgfx::Button* button, char const* address, uint16_t value, uint16_t imgOn, uint16_t imgOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
	if(pAddButtonImageStateItem)
		(*pAddButtonImageStateItem)(button, addr, imgOn, imgOff, value, MB_TTL);
}

void ReadModbusTTLAlarm(char const* address, TEXTS message, TEXTS invMessage){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
	if(pAddAlarmItem)
		(*pAddAlarmItem)(addr, bit, message, invMessage, MB_TTL);
}

void ToggleModbusTTL(char const* address){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pToggleBitModbusTTL)
		(*pToggleBitModbusTTL)(addr, bit);

	Wait(50);
}

void UpdateModbusTTL(touchgfx::Unicode::UnicodeChar* buffer, char const* address, DataType dataType){
	double value = 0;

	if(pFromUnicodeToDouble)
		value = (*pFromUnicodeToDouble)(buffer);

	UpdateModbusTTL(address, value, dataType);
}

void UpdateModbusTTL(uint16_t address, double value, DataType dataType){
	if(pUpdateModbusTTL)
		(*pUpdateModbusTTL)(address, value, (uint8_t)dataType);

	Wait(50);
}

void UpdateModbusTTL(char const* address, double value, DataType dataType){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pUpdateModbusTTL)
		(*pUpdateModbusTTL)(addr, value, (uint8_t)dataType);

	Wait(50);
}

void SetBitModbusTTL(char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pUpdateBitModbusTTL)
		(*pUpdateBitModbusTTL)(addr, bit, value);
}

void BlinkImageModbusTTL(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint32_t ms){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	if(pAddBlinkImageModbusItem)
		(*pAddBlinkImageModbusItem)(image, addr, bit, bitmapOn, bitmapOff, value, ms, MB_TTL);

	ReadWriteModbusTTL(address, REPEAT);
}

void ModbusTTLErrCommContainerVisibility(touchgfx::Container* container, uint16_t time){
	if(pAddModbusErrCommContainerVisibility)
		(*pAddModbusErrCommContainerVisibility)(container, time, MB_TTL);
}

void ButtonPressedDlyTTL(touchgfx::Button* button, char const* address, int16_t value, uint16_t dly, uint16_t dataType){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddButtonPressedDlyItem)
		(*pAddButtonPressedDlyItem)(button, addr, bit, value, dly, dataType, NULL, MB_TTL);
	if(pAddModbusTTLReadItem)
		(*pAddModbusTTLReadItem)(addr, 0, REPEAT, 1);
}

void SetModbusTTLErrCommReadByUser(){
	if(pSetTimerTTL)
		(*pSetTimerTTL)();
}

void WriteModbusTTL(char const* address, uint8_t length){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTTLWriteItem)
		(*pAddModbusTTLWriteItem)(addr, 0, length);
}

void SendJobIdModbusTTL(char const* address){
	if(pGetSelectedJob){
		uint32_t jobNum = pGetSelectedJob() + 1;
		UpdateModbusTTL(address, (double)jobNum, _INT_);
	}
}

void SendJobParamAtModbusTTL(char const* address, int idx, DataType dataType){
	if(pReadJobData && pFromFloatingPointToDecimalSinglePrecision){
		double decValueJobata = ReadJobData(idx, dataType);
		UpdateModbusTTL(address, decValueJobata, dataType);
	}
}

void ReadJobNameModbusTTL(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t length){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	int i;
	for(i = 0; i < length && pAddModbusTTLReadItem; i++){
		(*pAddModbusTTLReadItem)(addr + i, 0, REPEAT, 1);
	}

	if(pAddReadJobNameItem)
		(*pAddReadJobNameItem)(textArea, buffer, addr, length, MB_TTL);
}

void SendJobNameModbusTTL(char const* address, uint8_t length){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	StartAcceptingIncomingRecipes();

	if(pReadJobName){
		char name[20];
		(*pReadJobName)(name);
		int len = strlen(name);
		memset(&name[len], 0, sizeof(char) * (20 - len));
		int i;
		uint8_t offsetAddr = 0;
		for(i = 0; i < len; i += 2){
			char strL = name[i + 0];
			char strH = name[i + 1];
			uint16_t strW = (strH << 8) | strL;
			UpdateModbusTTL(addr + offsetAddr, (double)strW, _INT_);
			offsetAddr++;
		}

		UpdateModbusTTL(addr + offsetAddr, 0, _INT_);
	}

	StopAcceptingIncomingRecipes();
}

void CircularProgressTTL(touchgfx::CircleProgress* progress, char const* address, DataType dataType){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	if(pAddCircularProgressItem)
		(*pAddCircularProgressItem)(progress, addr, dataType, MB_TTL);
}

void AddNumKeyboardReferenceTTL(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update, uint16_t address){
	if(pAddNumericalKeyboardReference)
		(*pAddNumericalKeyboardReference)(textArea, textBuffer, min, max, dataType, decimal, update, pUpdateModbusTTL, address);
}

void AddNumKeyboardReferenceTTL(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update){
	if(pAddNumericalKeyboardReference)
		(*pAddNumericalKeyboardReference)(textArea, textBuffer, min, max, dataType, decimal, update, pUpdateModbusTTL, 0);
}

void BeepTTL(const char* address, uint32_t ms){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);

	if(pBeep)
		(*pBeep)(addr, bit, ms, MB_TTL);
}

/*****************************************************************************************************************************/


/********************************************* MODBUS RS485 ******************************************************************/

void SetModbus485As(uint8_t mode, uint32_t baud){
	if(pSetModeRS485)
		(*pSetModeRS485)(mode, baud);
}

void SetModbus485ErrCommReadByUser(){
	if(pSetTimerRS485)
		(*pSetTimerRS485)();
}

void Modbus485ErrCommContainerVisibility(touchgfx::Container* container, uint16_t time){
	if(pAddModbusErrCommContainerVisibility)
		(*pAddModbusErrCommContainerVisibility)(container, time, MB_RS485);
}

void WriteModbus485(char const* address, uint8_t length){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485WriteItem)
		(*pAddModbusRS485WriteItem)(addr, 0, length);
}

void WriteModbus485(uint16_t address, uint8_t length){
	if (pAddModbusRS485WriteItem)
		(*pAddModbusRS485WriteItem)(address, 0, length);
}

void ReadWriteModbus485(char const* address, ReadMode readMode){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, readMode, 1);
	if(pAddModbusRS485WriteItem)
		(*pAddModbusRS485WriteItem)(addr, 0, 1);
}

void ReadWriteModbus485(uint16_t address, ReadMode readMode){
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(address, 0, readMode, 1);
	if(pAddModbusRS485WriteItem)
		(*pAddModbusRS485WriteItem)(address, 0, 1);
}

void ReadWriteModbus485(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, uint16_t address, uint8_t decimal, DataType dataType, ReadMode readMode){
	uint8_t len = 0;

	switch(dataType){
		case _FP_32BIT_:
			len = 2;
			//addr++;
			break;
		default:
			len = 1;
			break;
	}

	if(pAddItem)
		(*pAddItem)(textArea, buffer, address, dataType, decimal, MB_RS485);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(address, decimal, readMode, len);
	if(pAddModbusRS485WriteItem)
		(*pAddModbusRS485WriteItem)(address, decimal, len);
}

void ReadWriteModbus485(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal, DataType dataType, ReadMode readMode){
	int addr = 0, bit = 0;
	uint8_t len = 0;

	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);


	switch(dataType){
		case _FP_32BIT_:
			len = 2;
			//addr++;
			break;
		default:
			len = 1;
			break;
	}


	if(pAddItem)
		(*pAddItem)(textArea, buffer, addr, dataType, decimal, MB_RS485);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, decimal, readMode, len);
	if(pAddModbusRS485WriteItem)
		(*pAddModbusRS485WriteItem)(addr, decimal, len);
}

void BlinkImageModbusRS485(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint32_t ms){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	if(pAddBlinkImageModbusItem)
		(*pAddBlinkImageModbusItem)(image, addr, bit, bitmapOn, bitmapOff, value, ms, MB_RS485);

	ReadWriteModbus485(address, REPEAT);
}
void ButtonPressedDlyRS485(touchgfx::Button* button, char const* address, int16_t value, uint16_t dly, uint16_t dataType){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddButtonPressedDlyItem)
		(*pAddButtonPressedDlyItem)(button, addr, bit, value, dly, dataType, NULL, MB_RS485);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
}

void ImageModbus485(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddImageItem)
		(*pAddImageItem)(image, addr, bit, bitmapOn, bitmapOff, MB_RS485);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
}

void ButtonModbus485(touchgfx::Button* button, char const* address, uint16_t bitmapOn, uint16_t bitmapOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddToggleItem)
		(*pAddToggleItem)(button, addr, bit, bitmapOn, bitmapOff, MB_RS485);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
}

void ToggleModbus485(char const* address){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pToggleBitModbusRS485)
		(*pToggleBitModbusRS485)(addr, bit);

	Wait(50);
}

void ReadModbus485TextAssoc(int address, int value, TEXTS text){
	if(pAddTextItem)
		(*pAddTextItem)(address, value, text);
}

void ReadModbus485TextAssocBit(touchgfx::TextArea* textArea, char const* address, TEXTS textOn, TEXTS textOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	if(pAddTextBitItem)
		(*pAddTextBitItem)(addr, bit, textArea, textOn, textOff, MB_RS485);
}

void ReadModbus485Alarm(char const* address, TEXTS message, TEXTS invMessage){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
	if(pAddAlarmItem)
		(*pAddAlarmItem)(addr, bit, message, invMessage, MB_RS485);
}

void WriteModbus485(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485WriteItem)
		(*pAddModbusRS485WriteItem)(addr, decimal, 1);
}

void UpdateModbus485(touchgfx::Unicode::UnicodeChar* buffer, char const* address, DataType dataType){
	double value = 0;

	if(pFromUnicodeToDouble)
		value = (*pFromUnicodeToDouble)(buffer);

	UpdateModbus485(address, value, dataType);
}

void UpdateModbus485(uint16_t address, double value, DataType dataType){
	if(pUpdateModbusRS485)
		(*pUpdateModbusRS485)(address, value, (uint8_t)dataType);

	// Wait(50);
	Wait(170);
}

void UpdateModbus485(char const* address, double value, DataType dataType){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pUpdateModbusRS485)
		(*pUpdateModbusRS485)(addr, value, (uint8_t)dataType);

	// Wait(50);
	Wait(170);
}

void SetBitModbusRS485(char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pUpdateBitModbusRS485)
		(*pUpdateBitModbusRS485)(addr, bit, value);
}

void ButtonRS485ImageState(touchgfx::Button* button, char const* address, uint16_t value, uint16_t imgOn, uint16_t imgOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
	if(pAddButtonImageStateItem)
		(*pAddButtonImageStateItem)(button, addr, imgOn, imgOff, value, MB_RS485);
}

void FlexButtonRS485Visibility(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* button, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
	if(pAddFlexButtonVisibility)
		(*pAddFlexButtonVisibility)(button, addr, bit, value, MB_RS485);
}

void ButtonRS485Visibility(touchgfx::Button* button, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
	if(pAddButtonVisibilityItem)
		(*pAddButtonVisibilityItem)(button, addr, bit, value, MB_RS485);
}

void TextRS485Visibility(touchgfx::TextArea* textArea, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
	if(pAddTextVisibilityItem)
		(*pAddTextVisibilityItem)(textArea, addr, bit, value, MB_RS485);
}

void ContainerRS485Visibility(touchgfx::Container* container, char const* address, uint8_t condition){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
	if(pAddContainerVisibilityItem)
		(*pAddContainerVisibilityItem)(container, addr, bit, condition, MB_RS485);
}

void ImageWordModbusRS485(touchgfx::Image *image, char const* address, uint16_t value, uint16_t bitmap){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddImageWordItem)
		(*pAddImageWordItem)(image, addr, value, bitmap, MB_RS485);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
}

void ImageRS485Visibility(touchgfx::Image* image, char const* address, uint8_t condition){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
	if(pAddImageVisibilityItem)
		(*pAddImageVisibilityItem)(image, addr, bit, condition, MB_RS485);
}

void ReadJobNameModbus485(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t length){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	int i;
	for(i = 0; i < length && pAddModbusRS485ReadItem; i++){
		(*pAddModbusRS485ReadItem)(addr + i, 0, REPEAT, 1);
	}

	if(pAddReadJobNameItem)
		(*pAddReadJobNameItem)(textArea, buffer, addr, length, MB_RS485);
}

void SendJobNameModbus485(char const* address, uint8_t length){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	StartAcceptingIncomingRecipes();

	if(pReadJobName){
		char name[20];
		(*pReadJobName)(name);
		int len = strlen(name);
		memset(&name[len], 0, sizeof(char) * (20 - len));
		int i;
		uint8_t offsetAddr = 0;
		for(i = 0; i < len; i += 2){
			char strL = name[i + 0];
			char strH = name[i + 1];
			uint16_t strW = (strH << 8) | strL;
			UpdateModbus485(addr + offsetAddr, (double)strW, _INT_);
			offsetAddr++;
		}

		UpdateModbus485(addr + offsetAddr, 0, _INT_);
	}

	StopAcceptingIncomingRecipes();
}

void SendJobIdModbus485(char const* address){
	if(pGetSelectedJob){
		uint32_t jobNum = pGetSelectedJob() + 1;
		UpdateModbus485(address, (double)jobNum, _INT_);
	}
}

void SendJobParamAtModbus485(char const* address, int idx, DataType dataType){
	if(pReadJobData && pFromFloatingPointToDecimalSinglePrecision){
		double decValueJobata = ReadJobData(idx, dataType);
		UpdateModbus485(address, decValueJobata, dataType);
	}
}

void CircularProgressRS485(touchgfx::CircleProgress* progress, char const* address, DataType dataType){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	if(pAddCircularProgressItem)
		(*pAddCircularProgressItem)(progress, addr, dataType, MB_RS485);
}

void AddNumKeyboardReferenceRS485(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update, uint16_t address){
	if(pAddNumericalKeyboardReference)
		(*pAddNumericalKeyboardReference)(textArea, textBuffer, min, max, dataType, decimal, update, pUpdateModbusRS485, address);
}

void AddNumKeyboardReferenceRS485(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update){
	if(pAddNumericalKeyboardReference)
		(*pAddNumericalKeyboardReference)(textArea, textBuffer, min, max, dataType, decimal, update, pUpdateModbusRS485, 0);
}

void BeepRS485(const char* address, uint32_t ms){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusTCPIPReadItem)
		(*pAddModbusTCPIPReadItem)(addr, 0, REPEAT, 1);

	if(pBeep)
		(*pBeep)(addr, bit, ms, MB_RS485);
}

/*****************************************************************************************************************************/

/******************************************** INT ****************************************************************************/

void AddSwipeContainer(touchgfx::SwipeContainer* swipeContainer, char const* address){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	if(pAddModbusINTReadItem)
		(*pAddModbusINTReadItem)(addr, 0, REPEAT, 1);

	if(pAddModbusINTWriteItem)
		(*pAddModbusINTWriteItem)(addr, 0, 1);

	if(pAddSwipeContainer)
		(*pAddSwipeContainer)(swipeContainer, addr);
}

void ImageWordModbusINT(touchgfx::Image *image, char const* address, uint16_t value, uint16_t bitmap){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddImageWordItem)
		(*pAddImageWordItem)(image, addr, value, bitmap, MB_INT);
	if(pAddModbusINTReadItem)
		(*pAddModbusINTReadItem)(addr, 0, REPEAT, 1);
}

void ImageModbusINT(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddImageItem)
		(*pAddImageItem)(image, addr, bit, bitmapOn, bitmapOff, MB_INT);
	if(pAddModbusINTReadItem)
		(*pAddModbusINTReadItem)(addr, 0, REPEAT, 1);
}

void ReadWriteModbusINT(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal, DataType dataType, ReadMode readMode){
	int addr = 0, bit = 0;
	uint8_t len = 0;

	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);


	switch(dataType){
		case _FP_32BIT_:
			len = 2;
			//addr++;
			break;
		default:
			len = 1;
			break;
	}


	if(pAddItem)
		(*pAddItem)(textArea, buffer, addr, dataType, decimal, MB_INT);
	if(pAddModbusINTReadItem)
		(*pAddModbusINTReadItem)(addr, decimal, readMode, len);
	if(pAddModbusINTWriteItem)
		(*pAddModbusINTWriteItem)(addr, decimal, len);
}

void UpdateModbusINT(char const* address, double value, DataType dataType){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pUpdateModbusINT)
		(*pUpdateModbusINT)(addr, value, (uint8_t)dataType);

	Wait(50);
}

void SetBitModbusINT(char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pUpdateBitModbusINT)
		(*pUpdateBitModbusINT)(addr, bit, value);
}

/*****************************************************************************************************************************/

/***************************************** KEYBOARD **************************************************************************/

void AddNumKeyboardReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update){
	if(pAddNumericalKeyboardReference)
		(*pAddNumericalKeyboardReference)(textArea, textBuffer, min, max, dataType, decimal, update, NULL, 0);
}

void InitKeyboard(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer)
{
	if(pInitTxtKeyboard)
		(*pInitTxtKeyboard)(textArea, buffer);
}


void UpdateKeyboardReference(){
	if(pUpdateTxtKeyboard)
		(*pUpdateTxtKeyboard)();
}

void AddKeyboardReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer){
	if(pAddTxtKeyboardReference)
		(*pAddTxtKeyboardReference)(textArea, buffer);
}

void InitNumKeyboard(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer, uint16_t buffSize, touchgfx::TextArea *errText){
	if(pInitNumericalKeyboard)
		(*pInitNumericalKeyboard)(text, buffer, buffSize, errText);
}

void InitNumKeyboard(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer,
		touchgfx::TextArea *mintext, touchgfx::Unicode::UnicodeChar* minbuffer,
		touchgfx::TextArea *maxtext, touchgfx::Unicode::UnicodeChar* maxbuffer,
		uint16_t buffSize,
		touchgfx::TextArea *errText){
	if(pInitNumericalKeyboard)
		(*pInitNumericalKeyboard)(text, buffer, buffSize, errText);

	double min = 0, max = 0;
	DataType dt;
	uint8_t dec;
	RTCType rtc;

	if(pGetRangeValues)
		(*pGetRangeValues)(&min, &max, &dt, &rtc, &dec);

	Update(mintext, minbuffer, min, dt, dec);
	Update(maxtext, maxbuffer, max, dt, dec);
}

void InitPwdNumKeyboard(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer){
	if(pInitPwdNumKeyboard)
		(*pInitPwdNumKeyboard)(text, buffer);
}

void UpdatePwdNumKeyboard(){
	if(pUpdatePwdNumericalKeyboard)
		(*pUpdatePwdNumericalKeyboard)();
}

void AddNumKeyboard(char value){
	if(pAddNumericalKeyboard)
		(*pAddNumericalKeyboard)(value);
}

void KeyboardBtnPressed(char value){
	if(pKeyboardBtnPressed)
		(*pKeyboardBtnPressed)(value);
}

void KeyboardDltPressed(){
	if(pKeyboardDltPressed)
		(*pKeyboardDltPressed)();
}

void KeyboardShfPressed(){
	if(pKeyboardShfPressed)
		(*pKeyboardShfPressed)();
}

void KeyboardNumPressed(){
	if(pKeyboardNumPressed)
		(*pKeyboardNumPressed)();
}

void RemoveNumKeyboard(){
	if(pRemoveNumericalKeyboard)
		(*pRemoveNumericalKeyboard)();
}

void AddRTCNumKeyboardReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, RTCType type, uint8_t update){
	if(pAddRTCNumericalKeyboardReference)
		(*pAddRTCNumericalKeyboardReference)(textArea, textBuffer, min, max, type, update);
}

void UpdateNumKeyboardReference(touchgfx::GenericCallback<>* validRangeClbk, touchgfx::GenericCallback<>* outOfRangeClbk){
	touchgfx::TextArea *textArea = 0;
	touchgfx::Unicode::UnicodeChar* textBuff = 0;
	DataType dataType;
	RTCType rtc;
	uint8_t update;
	uint8_t decimal;
	uint16_t address;
	double value = 0;
	double min = 0, max = 0;
	void (*pUpdater)(uint16_t address, double value, uint8_t dataType) = NULL;

	if(pGetNumericalKeyboardValue)
		value = (*pGetNumericalKeyboardValue)(&textArea, &textBuff, &dataType, &decimal, &update, &pUpdater, &address);

	if(pGetRangeValues)
		(*pGetRangeValues)(&min, &max, &dataType, &rtc, &decimal);

	if(value >= min && value <= max){
		Update(textArea, textBuff, value, dataType, decimal);

		if(update && pUpdater && pGetAddressByBuffer && rtc == RTC_NONE){
			uint16_t addr = address != 0 ? address : (*pGetAddressByBuffer)(textBuff);
			(*pUpdater)(addr, value, (uint8_t)dataType);
		}

		if(rtc != RTC_NONE){
			WriteDateTime((uint8_t)value, rtc);
		}

		if(validRangeClbk != nullptr){
			if(validRangeClbk->isValid())
				validRangeClbk->execute();
		}
	}
	else{
		if(outOfRangeClbk != nullptr){
			if(outOfRangeClbk->isValid())
				outOfRangeClbk->execute();
		}
	}
}

void UpdateNumKeyboardReference(){
	touchgfx::TextArea *textArea = 0;
	touchgfx::Unicode::UnicodeChar* textBuff = 0;
	DataType dataType;
	uint8_t update;
	uint8_t decimal;
	uint16_t address;
	double value = 0;
	void (*pUpdater)(uint16_t address, double value, uint8_t dataType) = NULL;

	if(pGetNumericalKeyboardValue)
		value = (*pGetNumericalKeyboardValue)(&textArea, &textBuff, &dataType, &decimal, &update, &pUpdater, &address);

	Update(textArea, textBuff, value, dataType, decimal);

	if(update && pUpdater && pGetAddressByBuffer){
		uint16_t addr = address != 0 ? address : (*pGetAddressByBuffer)(textBuff);
		(*pUpdater)(addr, value, (uint8_t)dataType);
	}
}

void CheckPwd(touchgfx::GenericCallback<>* successClbk, touchgfx::GenericCallback<>* failedClbk){
	if(pCredentialSuccess){
		uint8_t success = (*pCredentialSuccess)();

		if(pLogin)
			(*pLogin)(success);

		if(success){
			if(successClbk != nullptr){
				if(successClbk->isValid())
					successClbk->execute();
			}
		}
		else{
			if(failedClbk != nullptr){
				if(failedClbk->isValid())
					failedClbk->execute();
			}
		}
	}
}

void SetKeyAccessPwdNumKeyboard(uint16_t key){
	if (pSetAccessKey)
		(*pSetAccessKey)(key);
}

/*****************************************************************************************************************************/


/********************************************* BRIGHTNESS ********************************************************************/

void ChangeDisplayBrightness(int step){
	if(pChangeBrightness)
		(*pChangeBrightness)(step);
}
/*****************************************************************************************************************************/

/********************************************* LANGUAGE **********************************************************************/

void ChangeLanguage(int lang){
	touchgfx::Texts::setLanguage(lang);

	if(pSetLanguage)
		(*pSetLanguage)(lang);
}

void SetLang(){
	uint8_t lang = 0;

	if(pGetLanguage)
		lang = (*pGetLanguage)();

	ChangeLanguage(lang);
}

/*****************************************************************************************************************************/

/********************************************* CONTAINER *********************************************************************/

void ContainerVisibility(touchgfx::Container* container, bool visible){
	container->setVisible(visible);

	container->invalidate();
}

void ContainerClear(touchgfx::Container* container){
	container->removeAll();
}

/*****************************************************************************************************************************/

/*********************************************** BUTTON **********************************************************************/

void ButtonVisibility(touchgfx::Button* button, bool visible){
	button->setVisible(visible);
	button->invalidate();
}

void RefreshButton(touchgfx::Button* button){
	button->invalidate();
}

void ButtonPressedDly(touchgfx::Button* button, uint16_t dly, touchgfx::GenericCallback<>* callback){
	if(pAddButtonPressedDlyItem)
		(*pAddButtonPressedDlyItem)(button, 0, 0, 0, dly, 0, callback, PROTOCOL_NONE);
}

/*****************************************************************************************************************************/

/********************************************* TEXT AREA *********************************************************************/
void RefreshTextArea(touchgfx::TextArea* textArea){
	textArea->invalidate();
}

void VisibilityTextArea(touchgfx::TextArea* textArea, bool visibility){
	textArea->setVisible(visibility);
	textArea->invalidate();
}
/*****************************************************************************************************************************/

/*********************************************** BUZZER **********************************************************************/

void SoundBuzzerOn(uint32_t ms){
	if (enableSoundBuzzer){
		if(pSwitchBuzzerOn)
			(*pSwitchBuzzerOn)();
		if(pWaitFor)
			(*pWaitFor)(ms);
		if(pSwitchBuzzerOff)
			(*pSwitchBuzzerOff)();
	}
	else if(pWaitFor)
		(*pWaitFor)(ms);
}

void EnableSoundBuzzer(bool enable){
	enableSoundBuzzer = enable;
}

/*****************************************************************************************************************************/

/************************************************* JOB ***********************************************************************/

void AddJob(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int idx, DataType dataType, uint8_t decimal){
	if(pAddJobItem){
		(*pAddJobItem)(textArea, buffer, idx, dataType, decimal);
	}
}

void AddJob(touchgfx::Image *image, uint16_t bitmapOn, uint16_t bitmapOff, int idx, uint8_t bit){
	if(pAddJobImageItem)
		(*pAddJobImageItem)(image, bitmapOn, bitmapOff, idx, bit);
}

void ToggleJob(int idx, uint8_t bit){
	if(pToggleJobData)
		(*pToggleJobData)(idx, bit);
}

void DeleteJob(){
	if(pDeleteJobItem)
		(*pDeleteJobItem)();

	if(pUpdateJobsFlag)
		(*pUpdateJobsFlag)();
}

void UpdateJobs(){
	if(pUpdateJobItems)
		(*pUpdateJobItems)();

	if(pUpdateJobsFlag)
		(*pUpdateJobsFlag)();

	if(pWaitFor)
		(*pWaitFor)(50);

	UpdateJobsOthers();
}

void SelectJobChosen(){
	if(pSelectJob && pChosenJob)
		(*pSelectJob)((*pChosenJob)());
}

void SelectJob(int idx){
	if(pSelectJob)
		(*pSelectJob)(idx);

	if(pClearJobsValue)
		(*pClearJobsValue)();
}


void IncreaseJob(int minIdx, int maxIdx){
	if(pIncreaseJob)
		(*pIncreaseJob)(minIdx, maxIdx);
}

void DecreaseJob(int minIdx, int maxIdx){
	if(pDecreaseJob)
		(*pDecreaseJob)(minIdx, maxIdx);
}

void ReadJobName(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int buffSize){
	if(pReadJobName && textArea && buffer){
		char str[20];
		(*pReadJobName)(str);
		touchgfx::Unicode::strncpy(buffer, str, buffSize);
		textArea->invalidate();
	}
}

void ReadJobName(char* dst){
	if(pReadJobName){
		(*pReadJobName)(dst);
	}
}

double ReadJobData(uint8_t idx, DataType dataType){
	double jobData = (double)(*pReadJobData)(idx);

	if(dataType == DT_NONE)
		return jobData;

	return (*pFromFloatingPointToDecimalSinglePrecision)(jobData);

}

void ContainerJobVisibility(touchgfx::Container* container, char const* address, uint8_t condition){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddModbusRS485ReadItem)
		(*pAddModbusRS485ReadItem)(addr, 0, REPEAT, 1);
	if(pAddContainerVisibilityItem)
		(*pAddContainerVisibilityItem)(container, addr, bit, condition, PT_JOB);
}

/*****************************************************************************************************************************/

/************************************************ TICK ***********************************************************************/

void TickElapsed(){
	if(waitCount > 10){
		if(pSearchUpdatesModbusRS485)
			(*pSearchUpdatesModbusRS485)();

		if(pSearchUpdatesModbusTCPIP)
			(*pSearchUpdatesModbusTCPIP)();

		if(pSearchUpdatesModbusTTL)
			(*pSearchUpdatesModbusTTL)();

		if(pSearchUpdatesModbusINT)
			(*pSearchUpdatesModbusINT)();

		if(pRefreshJobItems)
			(*pRefreshJobItems)();

		if(pRefreshRun)
			(*pRefreshRun)();

	}
	waitCount++;
}

/*****************************************************************************************************************************/

/********************************************** SCROLL ***********************************************************************/

void AddJobScrollItems(touchgfx::ScrollWheelWithSelectionStyle *scrollWheel, touchgfx::DrawableListItems<programContainer, 6> *items, touchgfx::DrawableListItems<programCenterContainer, 2> *selectedItems){
	if(pAddJobScroll)
		(*pAddJobScroll)(scrollWheel, items, selectedItems);
}

void AddAlarmScrollItems(touchgfx::ScrollWheel *scrollWheel, touchgfx::DrawableListItems<alarmContainer, 5> *items, touchgfx::DrawableListItems<alarmCenterContainer, 2> *selectedItems){
	if(pAddAlarmScroll)
		(*pAddAlarmScroll)(scrollWheel, items, selectedItems);
}

/*****************************************************************************************************************************/

/*********************************************** USER ************************************************************************/

void LogoutUser(){
	if(pLogout)
		(*pLogout)();
}

uint8_t UserIsLogged(){
	if(pIsLogged)
		return (*pIsLogged)();

	return 0;
}

/*****************************************************************************************************************************/

/********************************************** IMAGES ************************************************************************/

void BlinkImage(touchgfx::Image* image, uint16_t bitmapOn, uint16_t bitmapOff, uint32_t ms){
	if(pAddBlinkImage)
		(*pAddBlinkImage)(image, bitmapOn, bitmapOff, ms);
}

void HideImageWhen(touchgfx::Image* image, const char* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddHideImageCondItem)
		(*pAddHideImageCondItem)(image, addr, bit, value);
}

void ToggleImage(touchgfx::Image* image, uint16_t image1, uint16_t image2){
	if(pToggleImage)
		(*pToggleImage)(image, image1, image2);
}

/*****************************************************************************************************************************/

/******************************************** PARAMETERS *********************************************************************/

void ToggleParameter(uint16_t addr, uint8_t bit){
	if(pToggleParameter)
		(*pToggleParameter)(addr, bit);
}

void WriteParameter(uint16_t addr, uint16_t value){
	if(pWriteParameter)
		(*pWriteParameter)(addr, value);
}

void WriteBitParameter(uint16_t addr, uint8_t bit, uint16_t value){
	if(pWriteBitParameter)
		(*pWriteBitParameter)(addr, bit, value);
}

/*****************************************************************************************************************************/

/*********************************************** HDX *************************************************************************/

void ImageHDX(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddImageHDXItem)
		(*pAddImageHDXItem)(image, addr, bit, bitmapOn, bitmapOff);
}

void ButtonHDXVisibility(touchgfx::Button* button, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);
	if(pAddButtonVisibilityItem)
		(*pAddButtonVisibilityItem)(button, addr, bit, value, PT_HDX);
}

void ContainerHDXVisibility(touchgfx::Container* container, char const* address, uint8_t value){
	int addr = 0, bit = 0;
	if(pFromCharToAddress)
		(*pFromCharToAddress)(address, &addr, &bit);

	if(pAddContainerVisibilityItem)
		(*pAddContainerVisibilityItem)(container, addr, bit, value, PT_HDX);
}

/*****************************************************************************************************************************/

/*********************************************** RTC *************************************************************************/

void RTC(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, RTCType type){
	if(pAddRTCItem)
		(*pAddRTCItem)(textArea, buffer, type);
}

void WriteDateTime(uint8_t value, RTCType type){
	if(pTimeWriteDay && type == _DAY_)
		(*pTimeWriteDay)(value);
	if(pTimeWriteMonth && type == _MONTH_)
		(*pTimeWriteMonth)(value);
	if(pTimeWriteYear && type == _YEAR_)
		(*pTimeWriteYear)(value);
	if(pTimeWriteHour && type == _HOUR_)
		(*pTimeWriteHour)(value);
	if(pTimeWriteMin && type == _MIN_)
		(*pTimeWriteMin)(value);
	if(pTimeWriteSec && type == _SEC_)
		(*pTimeWriteSec)(value);
}
/*****************************************************************************************************************************/

/******************************************** RECIPES ************************************************************************/
void StartAcceptingIncomingRecipes(){
	if(pSuspendClientTask)
		(*pSuspendClientTask)();
}

void StopAcceptingIncomingRecipes(){
	if(pResumeClientTask)
		(*pResumeClientTask)();
}

/*****************************************************************************************************************************/
