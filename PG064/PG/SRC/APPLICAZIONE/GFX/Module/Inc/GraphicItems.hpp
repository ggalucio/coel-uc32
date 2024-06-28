/*
 * GraphicItems.hpp
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#ifndef MODULE_INC_GRAPHICITEMS_HPP_
#define MODULE_INC_GRAPHICITEMS_HPP_

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
#include <touchgfx/containers/progress_indicators/CircleProgress.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>

extern "C"{
	#include "enumerators.h"
}

#define BUFF_SIZE 20

typedef struct{
	touchgfx::TextArea* TextArea;
	touchgfx::Unicode::UnicodeChar *Buffer;
	uint16_t Address;
	uint32_t Value;
	DataType Type;
	uint8_t Decimal;
	Protocol ProtocolType;
}GraphicItem;

typedef struct{
	uint16_t Address;
	uint8_t  Bit;
	uint8_t  On;
	uint32_t Ms;
	uint32_t CurrMs;
	Protocol ProtocolType;
}BeepItem;

typedef struct{
	int Address;
	uint32_t Value;
	TEXTS Text;
}TextLinkerItem;

typedef struct{
	touchgfx::Image* Image;
	uint32_t Value;
	uint16_t Bitmap;
}ImageWordOptionItem;

typedef struct{
	touchgfx::Image* Image;
	int Address;
	Protocol ProtocolType;
}ImageWordItem;

typedef struct{
	touchgfx::Image* Image;
	uint16_t Address;
	uint8_t Bit;
	uint16_t BitmapOn;
	uint16_t BitmapOff;
	Protocol ProtocolType;
}ImageItem;

typedef struct{
	touchgfx::Image* Image;
	uint16_t Address;
	uint8_t Bit;
	uint8_t Value;
}HideImageCondItem;


typedef struct{
	uint16_t Address;
	uint8_t Bit;
	touchgfx::TextArea* TextArea;
	TEXTS TextOn;
	TEXTS TextOff;
	Protocol ProtocolType;
}TextAssocBitItem;

typedef struct{
	touchgfx::Button* Button;
	uint16_t Address;
	uint8_t Bit;
	uint16_t BitmapOn;
	uint16_t BitmapOff;
	Protocol ProtocolType;
}ToggleItem;

typedef struct{
	touchgfx::Button* Button;
	uint16_t Address;
	uint16_t Value;
	uint16_t BitmapOn;
	uint16_t BitmapOff;
	Protocol ProtocolType;
}ButtonStateImgItem;

typedef struct{
	touchgfx::Button* Button;
	uint16_t Address;
	uint8_t Bit;
	uint8_t Value;
	Protocol ProtocolType;
}ButtonVisibilityItem;

typedef struct{
	touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* Button;
	uint16_t Address;
	uint8_t Bit;
	uint8_t Value;
	Protocol ProtocolType;
}FlexButtonVisibilityItem;

typedef struct{
	touchgfx::TextArea* Text;
	uint16_t Address;
	uint8_t Bit;
	uint8_t Value;
	Protocol ProtocolType;
}TextVisibilityItem;

typedef struct{
	touchgfx::Image* Image;
	uint16_t Address;
	uint8_t Bit;
	uint8_t Condition;
	Protocol ProtocolType;
}ImageVisibilityItem;

typedef struct{
	touchgfx::Container* Container;
	uint16_t Address;
	uint8_t Bit;
	uint8_t Condition;
	Protocol ProtocolType;
}ContainerVisibilityItem;

typedef struct{
	uint16_t Address;
	uint8_t Bit;
	TEXTS Message;
	TEXTS InvalidMessage;
	uint8_t Added;
	Protocol ProtocolType;
}AlarmItem;

typedef struct{
	touchgfx::TextArea* TextArea;
	touchgfx::Unicode::UnicodeChar *Buffer;
	uint32_t Value;
	char ValueStr[BUFF_SIZE];
	uint16_t Idx;
	DataType Type;
	uint8_t Decimal;
}JobItem;

typedef struct{
	touchgfx::Image* Image;
	uint16_t BitmapOn;
	uint16_t BitmapOff;
	uint32_t Value;
	uint8_t Idx;
	uint8_t Bit;
	uint8_t Flag;
}JobImageItem;

typedef struct{
	touchgfx::TextArea* TextArea;
	touchgfx::Unicode::UnicodeChar *Buffer;
	uint32_t Address;
	uint8_t Length;
	Protocol ProtocolType;
}ReadJobNameItem;

typedef struct{
	touchgfx::Image* Image;
	uint16_t Address;
	uint8_t Bit;
	uint16_t BitmapOn;
	uint16_t BitmapOff;
	uint16_t Value;
	uint32_t CurrMs;
	uint32_t Millisec;
	Protocol ProtocolType;
}BlinkImageModbusItem;

typedef struct{
	touchgfx::TextArea* Text;
	uint16_t Address;
	uint8_t Bit;
	uint16_t Value;
	uint32_t CurrMs;
	uint32_t Millisec;
	Protocol ProtocolType;
}BlinkTxtModbusItem;

typedef struct{
	touchgfx::Image* Image;
	uint16_t BitmapOn;
	uint16_t BitmapOff;
	uint32_t CurrMs;
	uint32_t Millisec;
}BlinkImageItem;

typedef struct{
	touchgfx::Button* Button;
	uint16_t Address;
	uint8_t  Bit;
	uint16_t Value;
	uint16_t DelayMilliseconds;
	uint16_t DataType;
	bool	 Pressed;
	touchgfx::GenericCallback<>* Callback;
	Protocol ProtocolType;
}ButtonPressedDly;

typedef struct{
	touchgfx::TextArea* TextArea;
	touchgfx::Unicode::UnicodeChar *Buffer;
	int *Indx;
	uint8_t Full;
}ScrollAlarmItem;

typedef struct{
	touchgfx::Container* Container;
	uint16_t Timeout;
	Protocol ProtocolType;
}ModbusErrContVisibility;

typedef struct{
	touchgfx::TextArea* TextArea;
	touchgfx::Unicode::UnicodeChar* Buffer;
	RTCType Type;
}RTCItem;

typedef struct{
	touchgfx::CircleProgress* CircleProgress;
	uint16_t Address;
	DataType Type;
	Protocol ProtocolType;
}CircularProgressItem;

typedef struct{
	touchgfx::SwipeContainer* SwipeContainer;
	uint16_t Address;
	uint32_t CurrMs;
}SwipeContainerItem;

void ClearItems();
void UpdateItem(uint16_t address, uint32_t value, Protocol protocol);
void AddRTCItem(touchgfx::TextArea *txt, touchgfx::Unicode::UnicodeChar* buffer, RTCType type);
void AddItem(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, uint16_t address, DataType dataType, uint8_t decimal, Protocol protocol);
void AddTextItem(int address, int value, TEXTS text);
void AddTextBitItem(uint16_t address, uint8_t bit, touchgfx::TextArea* textArea, TEXTS textOn, TEXTS textOff, Protocol protocol);
void AddImageItem(touchgfx::Image *image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, Protocol protocol);
void AddImageWordItem(touchgfx::Image *image, uint16_t address, uint16_t value, uint16_t bitmap, Protocol protocol);
void AddImageHDXItem(touchgfx::Image *image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff);
void AddToggleItem(touchgfx::Button *button, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, Protocol protocol);
void AddHideImageCondItem(touchgfx::Image *image, uint16_t address, uint8_t bit, uint8_t value);
void AddButtonImageStateItem(touchgfx::Button* button, uint16_t address, uint16_t imageOn, uint16_t imageOff, uint16_t value, Protocol protocol);
void AddFlexButtonVisibilityItem(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* button, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol);
void AddButtonVisibilityItem(touchgfx::Button* button, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol);
void AddTextVisibilityItem(touchgfx::TextArea* textArea, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol);
void AddContainerVisibilityItem(touchgfx::Container *container, uint16_t address, uint8_t bit, uint8_t condition, Protocol protocol);
void AddImageVisibilityItem(touchgfx::Image* image, uint16_t address, uint8_t bit, uint8_t condition, Protocol protocol);
void AddAlarmItem(uint16_t address, uint8_t bit, TEXTS message, TEXTS invMessage, Protocol protocol);
void AddButtonPressedDlyItem(touchgfx::Button* button, uint16_t address, uint8_t bit, int16_t value, uint16_t dly, uint16_t dataType, touchgfx::GenericCallback<>* callback, Protocol protocol);
void AddJobItem(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int idx, DataType dataType, uint8_t decimal);
void AddJobImageItem(touchgfx::Image *image, uint16_t bitmapOn, uint16_t bitmapOff, int idx, uint8_t bit);
void AddReadJobName(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, uint16_t address, uint8_t length, Protocol protocol);
void UpdateJobItems();
void RefreshJobItems();
void ClearJobsValue();
void RefreshBlinkingItems(void);
void RefreshRun(void);
uint16_t GetAddressByBuffer(touchgfx::Unicode::UnicodeChar* buffer);
void AddBlinkImage(touchgfx::Image* image, uint16_t bitmapOn, uint16_t bitmapOff, uint32_t ms);
void AddBlinkImageModbusItem(touchgfx::Image* image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint32_t ms, Protocol protocol);
void AddBlinkTxtModbusItem(touchgfx::TextArea* text, uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, Protocol protocol);
void AddScrollAlarmItem(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int* indx);
void AddModbusErrCommContainerVisibility(touchgfx::Container* container, uint16_t time, Protocol protocol);
void ReverseBitmap(touchgfx::Image* Image, uint16_t bitmapOn, uint16_t bitmapOff);
void AddCircularProgressItem(touchgfx::CircleProgress* progress, uint16_t address, DataType dataType, Protocol protocol);
void AddBeep(uint16_t address, uint8_t bit, uint32_t ms, Protocol protocol);
void AddSwipeContainer(touchgfx::SwipeContainer* swipeContainer, uint16_t address);

#endif /* MODULE_INC_GRAPHICITEMS_HPP_ */
