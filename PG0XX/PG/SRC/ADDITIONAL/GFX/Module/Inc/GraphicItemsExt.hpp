/*
 * GraphicItemsExt.hpp
 *
 *  Created on: 7 de jun de 2024
 *      Author: COELMATIC2022
 */

#ifndef GFX_MODULE_INC_GRAPHICITEMSEXT_HPP_
#define GFX_MODULE_INC_GRAPHICITEMSEXT_HPP_

#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <stdint.h>

extern "C" void RefreshTimerCounter(void);
extern "C" void RefreshWriteModbus(void);

extern "C"{
	#include "enumerators_ext.h"
	#include "GFX/Module/Inc/enumerators.h"
}

typedef struct{
	uint64_t seconds;
	uint64_t ref;
	CountingMode mode;
	ControlState state;
}CounterItem;

typedef struct{
	touchgfx::TextArea *TextArea;
	touchgfx::Unicode::UnicodeChar* Buffer;
	touchgfx::DigitalClock* DigitalClock;
	int Id;
}ObjectCounterItem;

typedef struct{
	touchgfx::ToggleButton *ToggleButton;
	int Idx;
}JobOtherItem;

void ClearItemsExt(void);
double ArrayCharToDouble(char* src);
uint16_t UnicodeCharToArrayChar(touchgfx::Unicode::UnicodeChar* buffer, char* dst, uint16_t maxbytes);
uint8_t StateBlink();

void AddCounter(CountingMode countingMode, uint64_t seconds);
void AddTextAreaCounterItem(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int id);
void AddDigitalClockCounterItem(touchgfx::DigitalClock* digitalClock, int id);
void AddJobItem(touchgfx::ToggleButton *toggleButton, int idx);
void SetControlCounter(int id, ControlState state);
void UpdateJobItemsOthers(void);
void CountersRemoveAll(void);
void RefreshTimerCounter(void);
void RefreshWriteModbus(void);
void RefreshRunExt(void);

#endif /* GFX_MODULE_INC_GRAPHICITEMSEXT_HPP_ */
