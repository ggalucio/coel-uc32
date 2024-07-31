/*
 * AT_module_ext.hpp
 *
 *  Created on: 6 de jun de 2024
 *      Author: COELMATIC2022
 */

#ifndef GFX_AT_MODULE_EXT_HPP_
#define GFX_AT_MODULE_EXT_HPP_

#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/containers/progress_indicators/LineProgress.hpp>

#include <Module/Inc/enumerators_ext.h>

void ClearOthers(void);

// DIGITAL CLOCK
void Decrease(touchgfx::DigitalClock* digitalClock);
void Increase(touchgfx::DigitalClock* digitalClock);
void Update(touchgfx::DigitalClock* digitalClock, uint8_t hour, uint8_t minute, uint8_t second);
void RefreshDigitalClock(touchgfx::DigitalClock* digitalClock);
void VisibilityDigitalClock(touchgfx::DigitalClock* digitalClock, bool visibility);

// LINE PROGRESS
void Decrease(touchgfx::LineProgress* lineProgress);
void Increase(touchgfx::LineProgress* lineProgress);
void Update(touchgfx::LineProgress* lineProgress, int value);
void RefreshLineProgress(touchgfx::LineProgress* lineProgress);
void VisibilityLineProgress(touchgfx::LineProgress* lineProgress, bool visibility);

// TEXT AREA
void Update(touchgfx::Unicode::UnicodeChar* buffer, const char* src, uint16_t dstSize);
void Update(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char* src, uint16_t dstSize);
double GetNumberTextArea(touchgfx::Unicode::UnicodeChar* buffer, uint16_t dstSize);
double GetNumberTextArea(touchgfx::Unicode::UnicodeChar* buffer);

// COUNTER
void AddNewCounter(uint64_t time);
void AddNewCounter(CountingMode mode, uint64_t time);
void AddTextAreaCounter(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int id);
void AddDigitalClockCounter(touchgfx::DigitalClock* digitalClock, int id);
void SetCounter(int id, ControlState state);
void RemoveAllCounter(void);

// BUTTON
void Update(touchgfx::RadioButton* radioButton, bool select);
void Update(touchgfx::ToggleButton* toggleButton, bool state);

// BOX
void VisibilityBox(touchgfx::Box* box, bool visibility);
void SetColorBox(touchgfx::Box* box, uint8_t red, uint8_t green, uint8_t blue);
void SetColorBox(touchgfx::Box* box, const char* color);

// JOB
void AddJob(touchgfx::ToggleButton* toggleButton, int idx);

// TICK
void TickElapsedOthers(void);

#endif /* GFX_AT_MODULE_EXT_HPP_ */
