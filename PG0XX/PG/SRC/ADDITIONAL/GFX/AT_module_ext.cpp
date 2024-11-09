/*
 * AT_module_ext.cpp
 *
 *  Created on: 6 de jun de 2024
 *      Author: COELMATIC2022
 */

#include "AT_module_ext.hpp"
#include "Module/modulePlusExt.hpp"

#include <AT_module.hpp>

#include <touchgfx/Color.hpp>
#include <cstdio>
#include <math.h>

extern void ClearArray();

void ClearOthers(){
	ClearArray();

	if (pClearItemsExt)
		(*pClearItemsExt)();
}

bool GetStateBlink(){
	if (pStateBlink)
		return (*pStateBlink)() != 0 ? true : false;

	return false;
}

uint32_t refCountModel = 0;
uint32_t countTickModel = 0;
bool triggerCall = false;
bool startTickCount = false;

void ResetTickCount(uint32_t ms){
	if(!startTickCount && ms > 0){
		refCountModel = ms;
		startTickCount = true;
		triggerCall = false;
	}
}
bool FireSingleCall(){
	if (triggerCall){
		triggerCall = false;
		return true;
	}
	return false;
}

double max(double value, double maxValue){
	return value > maxValue ? maxValue : value;
}

double min(double value, double minValue){
	return value < minValue ? minValue : value;
}

double minmax(double value, double minValue, double maxValue){
	return max(min(value, minValue), maxValue);
}


int32_t ConvertFromUint16(double value) {
    uint16_t input = (uint16_t)value;
    return input > 32768 ? (int32_t)input - 65536 : (int32_t)input;
}

uint16_t ConvertToUint16(double value){
	int32_t input = (int32_t)value;
	return input < 0 ? (uint16_t)(input + 65536) : (uint16_t)input;
	return 0;
}

/************************************************ GRAPHIC ********************************************************************/

void RefreshItem(touchgfx::Drawable* object){
	if (object != NULL)
		object->invalidate();
}

/**************************************************************************************************************************/

/****************************************** DIGITAL CLOCK *****************************************************************/

void Decrease(touchgfx::DigitalClock* digitalClock){
	if (digitalClock)
	{
		uint8_t hour = digitalClock->getCurrentHour24();
		uint8_t minute = digitalClock->getCurrentMinute();
		uint8_t second = digitalClock->getCurrentSecond();

		if (second == 0){
			second = 59;
			// ----
		}
		else
			second --;

		digitalClock->setTime24Hour(hour, minute, second);
		digitalClock->invalidate();
	}
}

void Increase(touchgfx::DigitalClock* digitalClock){
	if (digitalClock)
	{
		uint8_t hour = digitalClock->getCurrentHour24();
		uint8_t minute = digitalClock->getCurrentMinute();
		uint8_t second = digitalClock->getCurrentSecond();

		second ++;
		if (second > 59){
			second = 0;
			minute ++;
			if (minute > 59){
				minute = 0;
				hour ++;
				if (hour > 23)
					hour = 0;
			}
		}

		digitalClock->setTime24Hour(hour, minute, second);
		digitalClock->invalidate();
	}
}

void Update(touchgfx::DigitalClock* digitalClock, uint8_t hour, uint8_t minute, uint8_t second){
	if (digitalClock)
	{
		digitalClock->setTime24Hour(hour, minute, second);
		digitalClock->invalidate();
	}
}

void RefreshDigitalClock(touchgfx::DigitalClock* digitalClock){
	RefreshItem(digitalClock);
}

void VisibilityDigitalClock(touchgfx::DigitalClock* digitalClock, bool visibility){
	if (digitalClock)
		if (digitalClock->isVisible() != visibility)
			digitalClock->setVisible(visibility);
}

/*****************************************************************************************************************************/

/****************************************** LINE PROGRESS ********************************************************************/

void Decrease(touchgfx::LineProgress* lineProgress){
	if (lineProgress)
	{
		lineProgress->setValue(lineProgress->getValue() - 1);
		lineProgress->invalidate();
	}
}

void Increase(touchgfx::LineProgress* lineProgress){
	if (lineProgress)
	{
		lineProgress->setValue(lineProgress->getValue() + 1);
		lineProgress->invalidate();
	}
}

void Update(touchgfx::LineProgress* lineProgress, int value){
	if (lineProgress)
	{
		lineProgress->setValue(value);
		lineProgress->invalidate();
	}
}

void SetRangeLineProgress(touchgfx::LineProgress* lineProgress, int minVal, int maxVal){
	if(lineProgress)
	{
		lineProgress->setRange(minVal, maxVal);
		lineProgress->invalidate();
	}
}

void RefreshLineProgress(touchgfx::LineProgress* lineProgress){
	RefreshItem(lineProgress);
}

void VisibilityLineProgress(touchgfx::LineProgress* lineProgress, bool visibility){
	if (lineProgress)
		if (lineProgress->isVisible() != visibility)
			lineProgress->setVisible(visibility);
}

/*****************************************************************************************************************************/

/****************************************** TEXT AREA ************************************************************************/

void Update(touchgfx::Unicode::UnicodeChar* buffer, const char* src, uint16_t dstSize){
	if (buffer)
		touchgfx::Unicode::strncpy(buffer, src, dstSize);
}

void Update(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char* src, uint16_t dstSize){
	if (textArea){
		Update(buffer, src, dstSize);
		textArea->invalidate();
	}
}

void CopyTextArea(char* dst, touchgfx::Unicode::UnicodeChar* src, uint16_t dstSize){
	if (pUnicodeCharToArrayChar)
		(*pUnicodeCharToArrayChar)(src, dst, dstSize);
}

double GetNumberTextArea(touchgfx::Unicode::UnicodeChar* buffer,  uint16_t dstSize){
	double value = 0.0;
	if (pUnicodeCharToArrayChar){
		if (pArrayCharToDouble){
			//char* p = new char[dstSize];
			char p[dstSize];
			if ((*pUnicodeCharToArrayChar)(buffer, p, dstSize) > 0){
				value = (*pArrayCharToDouble)(p);
			}
			//delete p;
		}
	}
	return value;
}

double GetNumberTextArea(touchgfx::Unicode::UnicodeChar* buffer){
	return GetNumberTextArea(buffer, 10);
}

/*****************************************************************************************************************************/

/************************************************ COUNTER ********************************************************************/

void AddNewCounter(CountingMode mode, uint64_t time){
	if (pAddCounter)
		(*pAddCounter)(mode, time);
}

void AddNewCounter(uint64_t time){
	AddNewCounter(INCREASE, time);
}

void AddTextAreaCounter(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int id){
	if (pAddTextAreaCounterItem)
		(*pAddTextAreaCounterItem)(textArea, buffer, id);
}

void AddDigitalClockCounter(touchgfx::DigitalClock* digitalClock, int id){
	if (pAddDigitalClockCounterItem)
		(*pAddDigitalClockCounterItem)(digitalClock, id);
}

void SetCounter(int id, ControlState state){
	if (pSetControlCounter)
		(*pSetControlCounter)(id, state);
}

void RemoveAllCounter(){
	if (pCountersRemoveAll)
		(*pCountersRemoveAll)();
}

/*****************************************************************************************************************************/

/************************************************ BUTTON *********************************************************************/

void Update(touchgfx::RadioButton* radioButton, bool select){
	if (radioButton){
		if (radioButton->getSelected() != select){
			radioButton->setSelected(select);
			radioButton->invalidate();
		}
	}
}

void Update(touchgfx::ToggleButton* toggleButton, bool state){
	if (toggleButton){
		if (toggleButton->getState() != state){
			toggleButton->forceState(state);
			toggleButton->invalidate();
		}
	}
}

void TouchButton(touchgfx::Button* button, bool enable){
	if (button){
		if (button->isTouchable() != enable){
			button->setTouchable(enable);
			button->invalidate();
		}
	}
}

/*****************************************************************************************************************************/

/************************************************ BOX ************************************************************************/

void VisibilityBox(touchgfx::Box* box, bool visibility){
	if (box){
		if (box->isVisible() != visibility){
			box->setVisible(visibility);
			box->invalidate();
		}
	}
}

void SetColorBox(touchgfx::Box* box, uint8_t red, uint8_t green, uint8_t blue){
	if (box){
		box->setColor(touchgfx::Color::getColorFromRGB(red, green, blue));
		box->invalidate();
	}
}

void SetColorBox(touchgfx::Box* box, const char* color){
	unsigned int red = 0x00, green = 0x00, blue = 0x00;
	if (sscanf(color, "%2x%2x%2x", &red, &green, &blue) == 3)
		SetColorBox(box, red, green, blue);
}

/*****************************************************************************************************************************/

/************************************************ JOB ************************************************************************/

void AddJob(touchgfx::ToggleButton* toggleButton, int idx){
	if (pAddJobButton)
		(*pAddJobButton)(toggleButton, idx);
}

void UpdateJobsOthers(){
	if (pUpdateJobItemsOthers)
		(*pUpdateJobItemsOthers)();
}

/*****************************************************************************************************************************/

/************************************************ SRAM ***********************************************************************/

void AddLocalNumberMemory(double* value){
	if (pAddNumberMemory)
		(*pAddNumberMemory)(value);
}

double ReadMemory(int id){
	if (pReadMemory)
		return (*pReadMemory)(id);

	return 0.0;
}

bool GetBooleanMemory(int id){
	return (int)(ReadMemory(id)) != 0 ? true : false;
}

void ReadDataMemory(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int id, uint8_t decimal){
	Update(textArea, buffer, ReadMemory(id), _DOUBLE_, decimal);
}

void ReadDataMemory(char* dst, int id, int length){
	if (pReadArraySRAM)
		(*pReadArraySRAM)(id, dst, length);
}

void WriteMemory(int id, double value){
	if (pWriteMemory)
		(*pWriteMemory)(id, value);
}

void WriteMemory(int id, touchgfx::Unicode::UnicodeChar* buffer){
	WriteMemory(id, GetNumberTextArea(buffer));
}

void WriteMemory(int id, char* src, int length){
	if (pWriteArraySRAM)
		(*pWriteArraySRAM)(id, src, length);
}

void ResetDataMemory(){
	if (pResetMemory)
		(*pResetMemory)();
}

/*****************************************************************************************************************************/

/************************************************ IMAGE **********************************************************************/

void VisibilityImage(touchgfx::Image* image, bool visibility){
	if (image){
		if (image->isVisible() != visibility){
			image->setVisible(visibility);
			image->invalidate();
		}
	}
}

/*****************************************************************************************************************************/

void TickElapsedOthers(){
	if (startTickCount){
		if (refCountModel > 0){
			if (countTickModel < refCountModel)
				countTickModel += 16;
			else{
				countTickModel = 0;
				startTickCount = false;
				triggerCall = true;
			}
		}
	}

	if (pRefreshRunExt)
		(*pRefreshRunExt)();
}

/*****************************************************************************************************************************/

