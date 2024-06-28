/*
 * graphic.cpp
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#include "../Inc/graphic.hpp"

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

#include "Module/Inc/converter.hpp"
#include "Module/Inc/numericalKeyboard.hpp"
#include "Module/Inc/Keyboard.hpp"
#include "Module/Inc/GraphicItems.hpp"
#include "Module/Inc/scroll.hpp"
#include "Module/Inc/user.hpp"

#include <gui/containers/programContainer.hpp>
#include <gui/containers/programCenterContainer.hpp>

extern "C"{
	#include "Module/Inc/enumerators.h"
}

extern void 		(*pAddItem)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, uint16_t address, DataType dataType, uint8_t decimal, Protocol protocol);
extern void 		(*pAddRTCItem)(touchgfx::TextArea *txt,  touchgfx::Unicode::UnicodeChar* buffer, RTCType type);
extern void 		(*pAddImageItem)(touchgfx::Image *image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, Protocol protocol);
extern void 		(*pAddImageWordItem)(touchgfx::Image *image, uint16_t address, uint16_t value, uint16_t bitmap, Protocol protocol);
extern void 		(*pAddImageHDXItem)(touchgfx::Image *image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff);
extern void 		(*pAddHideImageCondItem)(touchgfx::Image* image, uint16_t address, uint8_t bit, uint8_t value);
extern void 		(*pAddToggleItem)(touchgfx::Button *button, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, Protocol protocol);
extern void 		(*pAddTextItem)(int address, int value, TEXTS text);
extern void 		(*pAddAlarmItem)(uint16_t address, uint8_t bit, TEXTS message, TEXTS invMessage, Protocol protocol);
extern void 		(*pAddButtonImageStateItem)(touchgfx::Button* button, uint16_t address, uint16_t imageOn, uint16_t imageOff, uint16_t value, Protocol protocol);
extern void 		(*pAddButtonVisibilityItem)(touchgfx::Button *button, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol);
extern void 		(*pAddFlexButtonVisibility)(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* button, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol);
extern void 		(*pAddTextVisibilityItem)(touchgfx::TextArea* textArea, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol);
extern void 		(*pAddContainerVisibilityItem)(touchgfx::Container *container, uint16_t address, uint8_t bit, uint8_t condition, Protocol protocol);
extern void 		(*pAddImageVisibilityItem)(touchgfx::Image* image, uint16_t address, uint8_t bit, uint8_t condition, Protocol protocol);
extern double 		(*pFromUnicodeToDouble)(touchgfx::Unicode::UnicodeChar* unicode);
extern void 		(*pClearItems)(void);
extern uint16_t 	(*pGetAddressByBuffer)(touchgfx::Unicode::UnicodeChar* buffer);
extern uint8_t 		(*pCredentialSuccess)();
extern void 		(*pAddTextBitItem)(uint16_t address, uint8_t bit, touchgfx::TextArea* textArea, TEXTS textOn, TEXTS textOff, Protocol protocol);
extern void 		(*pAddBlinkImageModbusItem)(touchgfx::Image* image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint32_t ms, Protocol protocol);
extern void			(*pAddTxtImageModbusItem)(touchgfx::TextArea* text, uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, Protocol protocol);
extern void 		(*pAddBlinkImage)(touchgfx::Image* image, uint16_t bitmapOn, uint16_t bitmapOff, uint32_t ms);
extern void 		(*pAddButtonPressedDlyItem)(touchgfx::Button* button, uint16_t address, uint8_t bit, int16_t value, uint16_t dly, uint16_t dataType, touchgfx::GenericCallback<>* callback, Protocol protocol);
extern void 		(*pAddModbusErrCommContainerVisibility)(touchgfx::Container* container, uint16_t time, Protocol protocol);
extern void 		(*pAddCircularProgressItem)(touchgfx::CircleProgress* progress, uint16_t address, DataType dataType, Protocol protocol);
extern void 		(*pBeep)(uint16_t address, uint8_t bit, uint32_t ms, Protocol protocol);
extern void			(*pAddSwipeContainer)(touchgfx::SwipeContainer* swipeContainer, uint16_t address);

// KEYBOARD
extern void 		(*pInitTxtKeyboard)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer);
extern void 		(*pInitNumericalKeyboard)(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer, uint16_t buffSize, touchgfx::TextArea *errText);
extern void 		(*pGetRangeValues)(double*, double*, DataType*,  RTCType*, uint8_t*);
extern void 		(*pInitPwdNumKeyboard)(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer);
extern void 		(*pUpdatePwdNumericalKeyboard)();
extern void 		(*pAddNumericalKeyboard)(char value);
extern void 		(*pRemoveNumericalKeyboard)();
extern void 		(*pAddNumericalKeyboardReference)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update, void (*pUpdateModbus)(uint16_t address, double value, uint8_t dataType), uint16_t address);
extern void 		(*pAddRTCNumericalKeyboardReference)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, RTCType type, uint8_t update);
extern double  		(*pGetNumericalKeyboardValue)(touchgfx::TextArea **area, touchgfx::Unicode::UnicodeChar** buff, DataType* dataType,  uint8_t* decimal, uint8_t* update, void (**pUpdater)(uint16_t address, double value, uint8_t dataType), uint16_t* address);
extern void 		(*pAddTxtKeyboardReference)(touchgfx::TextArea*, touchgfx::Unicode::UnicodeChar* buff);
extern void 		(*pUpdateTxtKeyboard)();
extern void 		(*pKeyboardBtnPressed)(char);
extern void 		(*pKeyboardDltPressed)();
extern void 		(*pKeyboardShfPressed)();
extern void 		(*pKeyboardNumPressed)(void);
extern void 		(*pClearJobsValue)(void);
extern void 		(*pRefreshRun)(void);

// JOB
extern void 		(*pAddReadJobNameItem)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, uint16_t address, uint8_t length, Protocol protocol);
extern void			(*pAddJobItem)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int idx, DataType dataType, uint8_t decimal);
extern void 		(*pAddJobImageItem)(touchgfx::Image* image, uint16_t bitmapOn, uint16_t bitmapOff, int idx, uint8_t bit);
extern void			(*pUpdateJobItems)(void);
extern void 		(*pRefreshJobItems)(void);

// USER
extern void 		(*pLogin)(uint8_t);
extern void 		(*pLogout)(void);
extern uint8_t		(*pIsLogged)(void);

// SCROLL
extern void 		(*pAddJobScroll)(touchgfx::ScrollWheelWithSelectionStyle *, touchgfx::DrawableListItems<programContainer, 6> *, touchgfx::DrawableListItems<programCenterContainer, 2> *);
extern void 		(*pAddAlarmScroll)(touchgfx::ScrollWheel *, touchgfx::DrawableListItems<alarmContainer, 5> *, touchgfx::DrawableListItems<alarmCenterContainer, 2> *);
Scroll	scroll;

// IMAGE
extern void 		(*pToggleImage)(touchgfx::Image*, uint16_t, uint16_t);

void AddJobScroll(touchgfx::ScrollWheelWithSelectionStyle *jobWheel, touchgfx::DrawableListItems<programContainer, 6> *items, touchgfx::DrawableListItems<programCenterContainer, 2> *selItems){
	scroll.AddJobScroll(jobWheel, items, selItems);
}

void AddAlarmScroll(touchgfx::ScrollWheel *alarmWheel, touchgfx::DrawableListItems<alarmContainer, 5> *items, touchgfx::DrawableListItems<alarmCenterContainer, 2> *selItems){
	scroll.AddAlarmScroll(alarmWheel, items, selItems);
}

void InitGraphicModulePtr(void){
	pAddItem 								= AddItem;
	pAddRTCItem								= AddRTCItem;
	pAddImageItem 							= AddImageItem;
	pAddImageWordItem						= AddImageWordItem;
	pAddImageHDXItem						= AddImageHDXItem;
	pAddHideImageCondItem					= AddHideImageCondItem;
	pAddToggleItem 							= AddToggleItem;
	pAddTextItem 							= AddTextItem;
	pAddAlarmItem 							= AddAlarmItem;
	pAddButtonImageStateItem 				= AddButtonImageStateItem;
	pAddButtonVisibilityItem				= AddButtonVisibilityItem;
	pAddFlexButtonVisibility				= AddFlexButtonVisibilityItem;
	pAddTextVisibilityItem					= AddTextVisibilityItem;
	pAddContainerVisibilityItem				= AddContainerVisibilityItem;
	pAddImageVisibilityItem					= AddImageVisibilityItem;
	pClearItems 							= ClearItems;
	pFromUnicodeToDouble 					= FromUnicodeToDouble;
	pGetAddressByBuffer						= GetAddressByBuffer;
	pCredentialSuccess						= CredentialSuccess;
	pAddTextBitItem							= AddTextBitItem;
	pAddBlinkImageModbusItem				= AddBlinkImageModbusItem;
	pAddTxtImageModbusItem					= AddBlinkTxtModbusItem;
	pAddBlinkImage							= AddBlinkImage;
	pRefreshRun								= RefreshRun;
	pAddButtonPressedDlyItem				= AddButtonPressedDlyItem;
	pAddModbusErrCommContainerVisibility 	= AddModbusErrCommContainerVisibility;
	pAddCircularProgressItem				= AddCircularProgressItem;
	pAddSwipeContainer						= AddSwipeContainer;

	// BUZZER
	pBeep									= AddBeep;

	// KEYBOARD
	pGetRangeValues						= GetRangeValues;
	pInitTxtKeyboard					= InitTxtKeyboard;
	pInitNumericalKeyboard				= InitNumericalKeyboard;
	pInitPwdNumKeyboard					= InitPasswordNumKeyboard;
	pUpdatePwdNumericalKeyboard			= UpdatePwdNumericalKeyboard;
	pAddNumericalKeyboard 				= AddNumericalKeyboard;
	pRemoveNumericalKeyboard			= RemoveNumericalKeyboard;
	pAddNumericalKeyboardReference		= AddNumericalKeyboardReference;
	pAddRTCNumericalKeyboardReference 	= AddRTCNumericalKeyboardReference;
	pAddTxtKeyboardReference			= AddTxtKeyboardRef;
	pGetNumericalKeyboardValue			= GetNumericalKeyboardValue;
	pUpdateTxtKeyboard					= UpdateTxtKeyboard;
	pKeyboardBtnPressed					= keyboardBtnPressed;
	pKeyboardDltPressed					= keyboardDltPressed;
	pKeyboardShfPressed					= keyboardShfPressed;
	pKeyboardNumPressed					= keyboardNumPressed;

	// JOB
	pAddReadJobNameItem				= AddReadJobName;
	pAddJobItem						= AddJobItem;
	pAddJobImageItem				= AddJobImageItem;
	pUpdateJobItems					= UpdateJobItems;
	pRefreshJobItems				= RefreshJobItems;
	pClearJobsValue					= ClearJobsValue;

	// SCROLL
	pAddJobScroll					= AddJobScroll;
	pAddAlarmScroll					= AddAlarmScroll;

	// USER
	pLogin							= Login;
	pLogout							= Logout;
	pIsLogged						= IsLogged;

	// IMAGE
	pToggleImage					= ReverseBitmap;

}

void RefreshUIRS485(uint16_t address, uint32_t value){
	UpdateItem(address, value, MB_RS485);
}

void RefreshUITCPIP(uint16_t address, uint32_t value){
	UpdateItem(address, value, MB_TCPIP);
}

void RefreshUITTL(uint16_t address, uint32_t value){
	UpdateItem(address, value, MB_TTL);
}

void RefreshUIINT(uint16_t address, uint32_t value){
	UpdateItem(address, value, MB_INT);
}
