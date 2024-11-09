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
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/containers/progress_indicators/LineProgress.hpp>

#include <Module/Inc/enumerators_ext.h>
#include <Module/Inc/enumerators.h>


bool GetStateBlink(void);

void ResetTickCount(uint32_t ms);
bool FireSingleCall(void);

double max(double value, double maxValue);
double min(double value, double minValue);
double minmax(double value, double minValue, double maxValue);

int32_t ConvertFromUint16(double value);
uint16_t ConvertToUint16(double value);

//  MODBUS RS485
void ReadWriteModbus485(uint16_t address, uint8_t decimal, DataType dataType, ReadMode readMode);
double ReadBufferModbus485(uint16_t address);

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
void SetRangeLineProgress(touchgfx::LineProgress* lineProgress, int minVal, int maxVal);
void RefreshLineProgress(touchgfx::LineProgress* lineProgress);
void VisibilityLineProgress(touchgfx::LineProgress* lineProgress, bool visibility);

// TEXT AREA
void Update(touchgfx::Unicode::UnicodeChar* buffer, const char* src, uint16_t dstSize);
void Update(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char* src, uint16_t dstSize);
void CopyTextArea(char* dst, touchgfx::Unicode::UnicodeChar* src, uint16_t dstSize);
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
void TouchButton(touchgfx::Button* button, bool enable);

// BOX
void VisibilityBox(touchgfx::Box* box, bool visibility);
void SetColorBox(touchgfx::Box* box, uint8_t red, uint8_t green, uint8_t blue);
void SetColorBox(touchgfx::Box* box, const char* color);

// JOB
void AddJob(touchgfx::ToggleButton* toggleButton, int idx);
void ReadJobName(void);

// SRAM
void AddLocalNumberMemory(double* value);
double ReadMemory(int id);
bool GetBooleanMemory(int);
void ReadDataMemory(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int id, uint8_t decimal);
void ReadDataMemory(char* dst, int id, int length);
void WriteMemory(int id, double value);
void WriteMemory(int id, touchgfx::Unicode::UnicodeChar* buffer);
void WriteMemory(int id, char* src, int length);
void ResetDataMemory();

// IMAGE
void VisibilityImage(touchgfx::Image* image, bool visibility);

// TICK
void TickElapsedOthers(void);

// GRAPHIC
void RefreshItem(touchgfx::Drawable* object);

#endif /* GFX_AT_MODULE_EXT_HPP_ */
