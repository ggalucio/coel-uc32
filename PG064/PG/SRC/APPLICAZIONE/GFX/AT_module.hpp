/*
 * AT_module.hpp
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#ifndef GENERATED_GUI_GENERATED_INCLUDE_GUI_GENERATED_COMMON_AT_MODULE_HPP_
#define GENERATED_GUI_GENERATED_INCLUDE_GUI_GENERATED_COMMON_AT_MODULE_HPP_

#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/scrollers/ScrollWheelWithSelectionStyle.hpp>
#include <touchgfx/containers/scrollers/ScrollWheel.hpp>
#include <touchgfx/containers/buttons/BoxWithBorderButtonStyle.hpp>
#include <touchgfx/containers/buttons/ClickButtonTrigger.hpp>
#include <touchgfx/containers/progress_indicators/CircleProgress.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>

#include <Module/Inc/enumerators.h>

#include <gui/containers/programContainer.hpp>
#include <gui/containers/programCenterContainer.hpp>
#include <gui/containers/alarmContainer.hpp>
#include <gui/containers/alarmCenterContainer.hpp>

extern "C" void TickElapsed(void);

void Clear();
void ClearWrites();
void Wait(uint32_t ms);

// MODBUS RS485
void Modbus485ErrCommContainerVisibility(touchgfx::Container* container, uint16_t time);
void SetModbus485As(uint8_t mode, uint32_t baud);
void SetModbus485ErrCommReadByUser();
void WriteModbus485(char const* address, uint8_t length);
void ReadWriteModbus485(char const* address, ReadMode readMode);
void ReadWriteModbus485(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal, DataType dataType, ReadMode readMode);
void ReadModbus485(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal, DataType dataType, ReadMode readMode);
void ButtonPressedDlyRS485(touchgfx::Button* button, char const* address, int16_t value, uint16_t dly, uint16_t dataType);
void ImageModbus485(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff);
void ImageWordModbusRS485(touchgfx::Image *image, char const* address, uint16_t value, uint16_t bitmap);
void ButtonModbus485(touchgfx::Button* button, char const* address, uint16_t bitmapOn, uint16_t bitmapOff);
void ToggleModbus485(char const* address);
void ReadModbus485TextAssoc(int address, int value, TEXTS text);
void ReadModbus485Alarm(char const* address, TEXTS message, TEXTS invMessage);
void UpdateModbus485(uint16_t address, double value, DataType dataType);
void UpdateModbus485(char const* address, double value, DataType dataType);
void UpdateModbus485(touchgfx::Unicode::UnicodeChar* buffer, char const* address, DataType dataType);
void WriteModbus485(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal);
void SetBitModbusRS485(char const* address, uint8_t value);
void ButtonRS485ImageState(touchgfx::Button* button, char const* address, uint16_t value, uint16_t imgOn, uint16_t imgOff);
void FlexButtonRS485Visibility(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* button, char const* address, uint8_t value);
void ButtonRS485Visibility(touchgfx::Button* button, char const* address, uint8_t value);
void TextRS485Visibility(touchgfx::TextArea* textArea, char const* address, uint8_t value);
void ContainerRS485Visibility(touchgfx::Container* container, char const* address, uint8_t condition);
void ImageRS485Visibility(touchgfx::Image* image, char const* address, uint8_t condition);
void ReadModbus485TextAssocBit(touchgfx::TextArea* textArea, char const* address, TEXTS textOn, TEXTS textOff);
void BlinkImageModbusRS485(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint32_t ms);
void SendJobIdModbus485(char const* address);
void SendJobParamAtModbus485(char const* address, int idx, DataType dataType);
void ReadJobNameModbus485(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t length);
void SendJobNameModbus485(char const*, uint8_t);
void CircularProgressRS485(touchgfx::CircleProgress* progress, char const* address, DataType dataType);
void AddNumKeyboardReferenceRS485(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update, uint16_t address);
void AddNumKeyboardReferenceRS485(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update);
void BeepRS485(const char* address, uint32_t ms);

// MODBUS TCPIP
void SetModbusTCPIPAs(uint8_t mode);
void WriteModbusTCPIP(char const* address, uint8_t length);
void ReadWriteModbusTCPIP(char const* address, ReadMode readMode);
void ReadWriteModbusTCPIP(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal, DataType dataType, ReadMode readMode);
void ImageModbusTCPIP(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff);
void ImageWordModbusTCPIP(touchgfx::Image *image, char const* address, uint16_t value, uint16_t bitmap);
void ReadModbusTCPIPTextAssocBit(touchgfx::TextArea* textArea, char const* address, TEXTS textOn, TEXTS textOff);
void ButtonModbusTCPIP(touchgfx::Button* button, char const* address, uint16_t bitmapOn, uint16_t bitmapOff);
void ButtonTCPIPVisibility(touchgfx::Button* button, char const* address, uint8_t value);
void FlexButtonTCPIPVisibility(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* button, char const* address, uint8_t value);
void TextTCPIPVisibility(touchgfx::TextArea* textArea, char const* address, uint8_t value);
void ContainerTCPIPVisibility(touchgfx::Container* container, char const* address, uint8_t condition);
void ImageTCPIPVisibility(touchgfx::Image* image, char const* address, uint8_t condition);
void ButtonTCPIPImageState(touchgfx::Button* button, char const* address, uint16_t value, uint16_t imgOn, uint16_t imgOff);
void ReadModbusTCPIPAlarm(char const* address, TEXTS message, TEXTS invMessage);
void ToggleModbusTCPIP(char const* address);
void UpdateModbusTCPIP(uint16_t address, double value, DataType dataType);
void UpdateModbusTCPIP(char const* address, double value, DataType dataType);
void UpdateModbusTCPIP(touchgfx::Unicode::UnicodeChar* buffer, char const* address, DataType dataType);
void SetBitModbusTCPIP(char const* address, uint8_t value);
void BlinkImageModbusTCPIP(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint32_t ms);
void BlinkTxtModbusTCPIP(touchgfx::TextArea* text, char const* address, uint8_t value, uint32_t ms);
void ModbusTCPIPErrCommContainerVisibility(touchgfx::Container* container, uint16_t time);
void ButtonPressedDlyTCPIP(touchgfx::Button* button, char const* address, int16_t value, uint16_t dly, uint16_t dataType);
void SetModbusTCPIPErrCommReadByUser();
void SendJobIdModbusTCPIP(char const* address);
void ReadJobNameModbusTCPIP(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t length);
void SendJobNameModbusTCPIP(char const* address, uint8_t length);
void SendJobParamAtModbusTCPIP(char const* address, int idx, DataType dataType);
void CircularProgressTCPIP(touchgfx::CircleProgress* progress, char const* address, DataType dataType);
void AddNumKeyboardReferenceTCPIP(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update, uint16_t address);
void AddNumKeyboardReferenceTCPIP(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update);
void BeepTCPIP(const char* address, uint32_t ms);

// MODBUS TTL
void SetModbusTTLAs(uint8_t mode, uint32_t baud);
void WriteModbusTTL(char const* address, uint8_t length);
void ReadWriteModbusTTL(char const* address, ReadMode readMode);
void ReadWriteModbusTTL(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal, DataType dataType, ReadMode readMode);
void ImageModbusTTL(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff);
void ImageWordModbusTTL(touchgfx::Image *image, char const* address, uint16_t value, uint16_t bitmap);
void ReadModbusTTLTextAssocBit(touchgfx::TextArea* textArea, char const* address, TEXTS textOn, TEXTS textOff);
void ButtonModbusTTL(touchgfx::Button* button, char const* address, uint16_t bitmapOn, uint16_t bitmapOff);
void ButtonTTLVisibility(touchgfx::Button* button, char const* address, uint8_t value);
void FlexButtonTTLVisibility(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* button, char const* address, uint8_t value);
void TextTTLVisibility(touchgfx::TextArea* textArea, char const* address, uint8_t value);
void ContainerTTLVisibility(touchgfx::Container* container, char const* address, uint8_t condition);
void ImageTTLVisibility(touchgfx::Image* image, char const* address, uint8_t condition);
void ButtonTTLImageState(touchgfx::Button* button, char const* address, uint16_t value, uint16_t imgOn, uint16_t imgOff);
void ReadModbusTTLAlarm(char const* address, TEXTS message, TEXTS invMessage);
void ToggleModbusTTL(char const* address);
void UpdateModbusTTL(uint16_t address, double value, DataType dataType);
void UpdateModbusTTL(char const* address, double value, DataType dataType);
void UpdateModbusTTL(touchgfx::Unicode::UnicodeChar* buffer, char const* address, DataType dataType);
void SetBitModbusTTL(char const* address, uint8_t value);
void BlinkImageModbusTTL(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint32_t ms);
void ModbusTTLErrCommContainerVisibility(touchgfx::Container* container, uint16_t time);
void ButtonPressedDlyTTL(touchgfx::Button* button, char const* address, int16_t value, uint16_t dly, uint16_t dataType);
void SetModbusTTLErrCommReadByUser();
void SendJobIdModbusTTL(char const* address);
void ReadJobNameModbusTTL(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t length);
void SendJobNameModbusTTL(char const* address, uint8_t length);
void SendJobParamAtModbusTTL(char const* address, int idx, DataType dataType);
void CircularProgressTTL(touchgfx::CircleProgress* progress, char const* address, DataType dataType);
void AddNumKeyboardReferenceTTL(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update, uint16_t address);
void AddNumKeyboardReferenceTTL(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update);
void BeepTTL(const char* address, uint32_t ms);

// INT
void AddSwipeContainer(touchgfx::SwipeContainer* swipeContainer, char const* address);
void ImageWordModbusINT(touchgfx::Image *image, char const* address, uint16_t value, uint16_t bitmap);
void ImageModbusINT(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff);
void ReadWriteModbusINT(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, char const* address, uint8_t decimal, DataType dataType, ReadMode readMode);
void UpdateModbusINT(char const* address, double value, DataType dataType);
void SetBitModbusINT(char const* address, uint8_t value);

// KEYBOARD
void InitNumKeyboard(touchgfx::TextArea *, touchgfx::Unicode::UnicodeChar*, touchgfx::TextArea *, touchgfx::Unicode::UnicodeChar*, touchgfx::TextArea *, touchgfx::Unicode::UnicodeChar*, uint16_t buffSize, touchgfx::TextArea*);
void InitNumKeyboard(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer, uint16_t buffSize, touchgfx::TextArea*);
void InitPwdNumKeyboard(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer);
void AddNumKeyboardReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update);
void UpdatePwdNumKeyboard();
void AddNumKeyboard(char value);
void RemoveNumKeyboard();
void CheckPwd(touchgfx::GenericCallback<>* successClbk, touchgfx::GenericCallback<>* failedClbk);
void UpdateNumKeyboardReference();
void UpdateNumKeyboardReference(touchgfx::GenericCallback<>* validRangeClbk, touchgfx::GenericCallback<>* outOfRangeClbk);
void AddRTCNumKeyboardReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, RTCType type, uint8_t update);
void InitKeyboard(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer);
void UpdateKeyboardReference();
void AddKeyboardReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer);
void KeyboardBtnPressed(char value);
void KeyboardDltPressed(void);
void KeyboardShfPressed(void);
void KeyboardNumPressed(void);

// TEXT AREA MANAGE
void Decrease(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, double step, double minVal, double maxVal, DataType dataType, uint8_t decimal);
void Increase(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, double step, double minVal, double maxVal, DataType dataType, uint8_t decimal);
void Update(touchgfx::TextArea* textArea, touchgfx::Unicode::UnicodeChar* buffer, double value, DataType dataType, uint8_t decimal);
void RefreshTextArea(touchgfx::TextArea* textArea);
void VisibilityTextArea(touchgfx::TextArea* textArea, bool visibility);

// BRIGHTNESS
void ChangeDisplayBrightness(int step);

// LANGUAGE
void ChangeLanguage(int lang);
void SetLang();

// CONTAINER
void ContainerVisibility(touchgfx::Container* container, bool visible);
void ContainerClear(touchgfx::Container* container);

// BUTTON
void ButtonVisibility(touchgfx::Button* button, bool visible);
void RefreshButton(touchgfx::Button* button);
void ButtonPressedDly(touchgfx::Button* button, uint16_t dly, touchgfx::GenericCallback<>* callback);

// BUZZER
void SoundBuzzerOn(uint32_t ms);

// JOB
void AddJob(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int idx, DataType dataType, uint8_t decimal);
void AddJob(touchgfx::Image *image, uint16_t bitmapOn, uint16_t bitmapOff, int idx, uint8_t bit);
void SelectJob(int idx);
void SelectJobChosen();
void UpdateJobs();
void IncreaseJob(int minIdx, int maxIdx);
void DecreaseJob(int minIdx, int maxIdx);
void DeleteJob();
void ToggleJob(int idx, uint8_t bit);
void ReadJobName(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int buffSize);
double ReadJobData(uint8_t idx, DataType dataType);
void ContainerJobVisibility(touchgfx::Container* container, char const* address, uint8_t condition);

// TICK
void TickElapsed(void);

// SCROLL
void AddJobScrollItems(touchgfx::ScrollWheelWithSelectionStyle *, touchgfx::DrawableListItems<programContainer, 6> *, touchgfx::DrawableListItems<programCenterContainer, 2> *);
void AddAlarmScrollItems(touchgfx::ScrollWheel *, touchgfx::DrawableListItems<alarmContainer, 5> *, touchgfx::DrawableListItems<alarmCenterContainer, 2> *);

// USER
void 	LogoutUser();
uint8_t UserIsLogged();

// IMAGE
void BlinkImage(touchgfx::Image* image, uint16_t bitmapOn, uint16_t bitmapOff, uint32_t ms);
void HideImageWhen(touchgfx::Image* image, const char* address, uint8_t value);
void ToggleImage(touchgfx::Image* image, uint16_t image1, uint16_t image2);

// PARAMETER
void ToggleParameter(uint16_t addr, uint8_t bit);
void WriteParameter(uint16_t addr, uint16_t value);
void WriteBitParameter(uint16_t addr, uint8_t bit, uint16_t value);

// HDX
void ImageHDX(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff);
void ButtonHDXVisibility(touchgfx::Button* button, char const* address, uint8_t value);
void ContainerHDXVisibility(touchgfx::Container* container, char const* address, uint8_t value);

// RTC
void RTC(touchgfx::TextArea* textArea,  touchgfx::Unicode::UnicodeChar* buffer, RTCType type);

// RECIPES
void StartAcceptingIncomingRecipes();
void StopAcceptingIncomingRecipes();

#endif /* GENERATED_GUI_GENERATED_INCLUDE_GUI_GENERATED_COMMON_AT_MODULE_HPP_ */
