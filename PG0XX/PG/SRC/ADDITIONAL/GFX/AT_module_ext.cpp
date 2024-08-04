/*
 * AT_module_ext.cpp
 *
 *  Created on: 6 de jun de 2024
 *      Author: COELMATIC2022
 */

#include "AT_module_ext.hpp"
#include "Module/modulePlusExt.hpp"

#include <touchgfx/Color.hpp>
#include <cstdio>

void ClearOthers(){
	if (pClearItemsExt)
		(*pClearItemsExt)();
}

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
	if (digitalClock)
		digitalClock->invalidate();
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

void RefreshLineProgress(touchgfx::LineProgress* lineProgress){
	if (lineProgress)
		lineProgress->invalidate();
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

double GetNumberTextArea(touchgfx::Unicode::UnicodeChar* buffer,  uint16_t dstSize){
	if (pUnicodeCharToArrayChar){
		if (pArrayCharToDouble){
			char* p = new char[dstSize];
			if ((*pUnicodeCharToArrayChar)(buffer, p, dstSize) > 0){
				return (*pArrayCharToDouble)(p);
			}
		}
	}
	return 0;
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
	if (pRefreshRunExt)
		(*pRefreshRunExt)();
}
