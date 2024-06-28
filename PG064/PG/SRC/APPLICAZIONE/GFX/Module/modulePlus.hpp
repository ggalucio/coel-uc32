/*
 * modulePlus.hpp
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#ifndef MODULE_MODULEPLUS_HPP_
#define MODULE_MODULEPLUS_HPP_


#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/Bitmap.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/scrollers/ScrollWheelWithSelectionStyle.hpp>

#include <gui/containers/programContainer.hpp>
#include <gui/containers/programCenterContainer.hpp>

extern "C"{
	#include "../Module/Inc/enumerators.h"
}

void 		(*pAddModbusErrCommContainerVisibility)(touchgfx::Container* container, uint16_t time, Protocol protocol);
double 		(*pFromUnicodeToDouble)(touchgfx::Unicode::UnicodeChar* unicode);
void 		(*pAddItem)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, uint16_t address, DataType dataType, uint8_t decimal, Protocol protocol);
void 		(*pAddRTCItem)(touchgfx::TextArea *txt,  touchgfx::Unicode::UnicodeChar* buffer, RTCType type);
void 		(*pAddBlinkImageModbusItem)(touchgfx::Image* image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint32_t ms, Protocol protocol);
void		(*pAddTxtImageModbusItem)(touchgfx::TextArea* text, uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, Protocol protocol);
void 		(*pAddBlinkImage)(touchgfx::Image* image, uint16_t bitmapOn, uint16_t bitmapOff, uint32_t ms);
void 		(*pAddHideImageCondItem)(touchgfx::Image* image, uint16_t address, uint8_t bit, uint8_t value);
void 		(*pAddImageItem)(touchgfx::Image *image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, Protocol protocol);
void 		(*pAddImageWordItem)(touchgfx::Image *image, uint16_t address, uint16_t value, uint16_t bitmap, Protocol protocol);
void 		(*pAddImageHDXItem)(touchgfx::Image *image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff);
void 		(*pAddButtonPressedDlyItem)(touchgfx::Button* button, uint16_t address, uint8_t bit, int16_t value, uint16_t dly, uint16_t dataType, touchgfx::GenericCallback<>* callback, Protocol protocol);
void 		(*pAddCircularProgressItem)(touchgfx::CircleProgress* progress, uint16_t address, DataType dataType, Protocol protocol);
void 		(*pBlinkImageItem)(touchgfx::Image* image, char const* address, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint16_t ms);
void 		(*pAddToggleItem)(touchgfx::Button *button, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, Protocol protocol);
void 		(*pAddTextItem)(int address, int value, TEXTS text);
void 		(*pAddTextBitItem)(uint16_t address, uint8_t bit, touchgfx::TextArea* textArea, TEXTS textOn, TEXTS textOff, Protocol protocol);
void 		(*pAddAlarmItem)(uint16_t address, uint8_t bit, TEXTS message, TEXTS invMessage, Protocol protocol);
void 		(*pAddButtonImageStateItem)(touchgfx::Button* button, uint16_t address, uint16_t imageOn, uint16_t imageOff, uint16_t value, Protocol protocol);
void 		(*pAddButtonVisibilityItem)(touchgfx::Button *button, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol);
void 		(*pAddFlexButtonVisibility)(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* button, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol);
void 		(*pAddTextVisibilityItem)(touchgfx::TextArea* textArea, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol);
void 		(*pAddContainerVisibilityItem)(touchgfx::Container *container, uint16_t address, uint8_t bit, uint8_t condition, Protocol protocol);
void 		(*pAddImageVisibilityItem)(touchgfx::Image* image, uint16_t address, uint8_t bit, uint8_t condition, Protocol protocol);
void 		(*pBeep)(uint16_t address, uint8_t bit, uint32_t ms, Protocol protocol);
void		(*pAddSwipeContainer)(touchgfx::SwipeContainer* swipeContainer, uint16_t address);
void 		(*pUpdateTxtKeyboard)();
void 		(*pInitTxtKeyboard)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer);
void 		(*pInitNumericalKeyboard)(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer, uint16_t buffSize, touchgfx::TextArea *errText);
void 		(*pGetRangeValues)(double*, double*, DataType*, RTCType*, uint8_t*);
void 		(*pInitPwdNumKeyboard)(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer);
void 		(*pUpdatePwdNumericalKeyboard)();
void 		(*pAddNumericalKeyboard)(char value);
void 		(*pKeyboardBtnPressed)(char);
void 		(*pKeyboardDltPressed)(void);
void 		(*pKeyboardShfPressed)(void);
void 		(*pKeyboardNumPressed)(void);
void 		(*pRemoveNumericalKeyboard)();
void 		(*pAddNumericalKeyboardReference)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update, void (*pUpdateModbus)(uint16_t address, double value, uint8_t dataType), uint16_t address);
void 		(*pAddRTCNumericalKeyboardReference)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, RTCType type, uint8_t update);
void 		(*pAddTxtKeyboardReference)(touchgfx::TextArea*, touchgfx::Unicode::UnicodeChar*);
double  	(*pGetNumericalKeyboardValue)(touchgfx::TextArea **area, touchgfx::Unicode::UnicodeChar** buff, DataType* dataType,  uint8_t* decimal, uint8_t* update, void (**pUpdater)(uint16_t address, double value, uint8_t dataType), uint16_t* address);
uint16_t 	(*pGetAddressByBuffer)(touchgfx::Unicode::UnicodeChar* buffer);
uint8_t 	(*pCredentialSuccess)();
void 		(*pAddJobItem)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int idx, DataType dataType, uint8_t decimal);
void 		(*pAddJobImageItem)(touchgfx::Image* image, uint16_t bitmapOn, uint16_t bitmapOff, int idx, uint8_t bit);
void 		(*pAddReadJobNameItem)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, uint16_t address, uint8_t length, Protocol protocol);
void 		(*pClearJobsValue)(void);
void 		(*pUpdateJobItems)(void);
void 		(*pRefreshJobItems)(void);
void 		(*pRefreshRun)(void);
void 		(*pClearItems)(void);
void 		(*pAddJobScroll)(touchgfx::ScrollWheelWithSelectionStyle *, touchgfx::DrawableListItems<programContainer, 6> *, touchgfx::DrawableListItems<programCenterContainer, 2> *);
void 		(*pAddAlarmScroll)(touchgfx::ScrollWheel *, touchgfx::DrawableListItems<alarmContainer, 5> *, touchgfx::DrawableListItems<alarmCenterContainer, 2> *);
void 		(*pLogin)(uint8_t);
void 		(*pLogout)(void);
uint8_t		(*pIsLogged)(void);

// IMAGE
void 		(*pToggleImage)(touchgfx::Image*, uint16_t, uint16_t);

#endif /* MODULE_MODULEPLUS_HPP_ */
