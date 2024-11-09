/*
 * GraphicItems.cpp
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#include "../Inc/GraphicItems.hpp"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

#define GRAPH_ITEM_SIZE			25
#define JOB_ITEM_SIZE			100
#define JOB_IMG_ITEM_SIZE		50

extern double		(*pFromUnicodeToDouble)(touchgfx::Unicode::UnicodeChar* unicode);
extern const char* 	(*pGetDecimalFormat)(uint8_t);
extern double  		(*pFromFloatingPointToDecimalSinglePrecision)(const double);
extern uint32_t		(*pReadJobData)(int);
extern uint32_t		(*pGetSelectedJob)(void);
extern void			(*pReadJobName)(char*);
extern double		(*pFromUnicodeToDouble)(touchgfx::Unicode::UnicodeChar* unicode);
extern void			(*pAddJobDataToUpdate)(int, double, uint8_t);
extern void 		(*pAddJobNameToUpdate)(char*);
extern uint8_t		(*pBlinkingImageModbusRS485)(uint16_t, uint8_t, uint8_t, uint32_t, uint32_t*);
extern uint8_t		(*pBlinkingImageModbusTCPIP)(uint16_t, uint8_t, uint8_t, uint32_t, uint32_t*);
extern uint8_t		(*pBlinkingImageModbusTTL)(uint16_t, uint8_t, uint8_t, uint32_t, uint32_t*);
extern void 		(*pAddBitDlyItemRS485)(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
extern void 		(*pAddBitDlyItemTCPIP)(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
extern void 		(*pAddBitDlyItemTTL)(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
extern void 		(*pReadRegistersRS485)(uint16_t, uint8_t, uint16_t*);
extern void 		(*pReadRegistersTCPIP)(uint16_t, uint8_t, uint16_t*);
extern void 		(*pReadRegistersTTL)(uint16_t, uint8_t, uint16_t*);
extern uint8_t 		(*pTsTimeoutElapsed)(uint32_t);
extern uint8_t 		(*pTimeElapsed)(uint32_t*, uint32_t);
extern uint8_t 		(*pReadParameter)(uint16_t);
extern uint8_t		(*pTimeReadHour)(void);
extern uint8_t		(*pTimeReadMin)(void);
extern uint8_t		(*pTimeReadSec)(void);
extern uint8_t		(*pTimeReadDay)(void);
extern uint8_t		(*pTimeReadMonth)(void);
extern uint8_t		(*pTimeReadYear)(void);
extern uint8_t		(*pTimeoutCommRS485)(uint32_t);
extern uint8_t 		(*pTimeoutCommTCPIP)(uint32_t);
extern uint8_t 		(*pTimeoutCommTTL)(uint32_t);
extern void 		(*pSwitchBuzzerOff)(void);
extern void			(*pToggleBuzzer)(void);
extern void 		(*pUpdateModbusINT)(uint16_t, double, uint8_t);

int nItems;
int nTextItems;
int nImageWordOptionItems;
int nImageWordItems;
int nBeepItems;
int nImageItems;
int nImageHDXItems;
int nHideImageCondItems;
int nToggleItems;
int nBtnStateImgItems;
int nButtonVisibilityItems;
int nFlexButtonVisibilityItems;
int nTextVisibilityItems;
int nCntVisibilityItems;
int nImageVisibilityItems;
int nAlarmItems;
int nJobItems;
int nJobImageItems;
int nTextAssocBitItem;
int nBlinkImageModbusItem;
int nBlinkTxtModbusItem;
int nBlinkImageItem;
int nScrollAlarmItems;
int nButtonPressedDlyItems;
int nRTCItems;
int nModbusErrContVisibilityItems;
int nCircularProgressItems;
int nReadJobNameItems;
int nSwipeContainerItems;

GraphicItem 					graphicItems[GRAPH_ITEM_SIZE];
TextLinkerItem 					textLinkerItems[GRAPH_ITEM_SIZE];
ImageWordOptionItem				imageWordOptionItems[GRAPH_ITEM_SIZE];
ImageWordItem					imageWordItems[GRAPH_ITEM_SIZE];
ImageItem 						imageItems[GRAPH_ITEM_SIZE];
ImageItem 						imageHDXItems[GRAPH_ITEM_SIZE];
HideImageCondItem				hideImageCondItems[GRAPH_ITEM_SIZE];
ToggleItem  					toggleItems[GRAPH_ITEM_SIZE];
ButtonStateImgItem 	    		btnStateImgItems[GRAPH_ITEM_SIZE];
ButtonVisibilityItem 			btnVisibilityItems[GRAPH_ITEM_SIZE];
FlexButtonVisibilityItem		flexBtnVisibilityItems[GRAPH_ITEM_SIZE];
TextVisibilityItem	 			txtVisibilityItems[GRAPH_ITEM_SIZE];
ContainerVisibilityItem 		cntVisibilityItems[GRAPH_ITEM_SIZE];
ImageVisibilityItem 			imageVisibilityItems[GRAPH_ITEM_SIZE];
AlarmItem						alarmItems[GRAPH_ITEM_SIZE];
ScrollAlarmItem 				scrollAlarmItems[GRAPH_ITEM_SIZE];
JobImageItem					jobImageItems[JOB_IMG_ITEM_SIZE];
JobItem 						jobItems[JOB_ITEM_SIZE];			// Gestore dei JOB memorizzati nel pannellino.
ReadJobNameItem 				readJobNameItem;					// Il nome del JOB letto da PLC.
TextAssocBitItem				textAssocBitItem[GRAPH_ITEM_SIZE];
BlinkImageModbusItem			blinkImageModbusItem[GRAPH_ITEM_SIZE];
BlinkTxtModbusItem				blinkTxtModbusItem[GRAPH_ITEM_SIZE];
BlinkImageItem					blinkImageItem[GRAPH_ITEM_SIZE];
ButtonPressedDly				buttonPressedDlyItems[3];
ModbusErrContVisibility 		modbusErrContVisibilityItems[3];
RTCItem 						rtcItems[10];
CircularProgressItem			circularProgressItems[10];
BeepItem						beepItems[10];
SwipeContainerItem				swipeContainerItems[3];

TEXTS getTexts(int address, uint32_t value){
	int i;
	for(i = 0; i < nTextItems && textLinkerItems != NULL; i++){
		if(textLinkerItems[i].Address == address){
			if(value == textLinkerItems[i].Value)
				return textLinkerItems[i].Text;
		}
	}

	return T_INVALID;
}

uint16_t getOptionBitmap(touchgfx::Image *image, uint32_t value){
	int i;
	for(i = 0; i < nImageWordOptionItems && imageWordOptionItems != NULL; i++){
		if(imageWordOptionItems[i].Image == image &&
				imageWordOptionItems[i].Value == value){
				return imageWordOptionItems[i].Bitmap;
		}
	}

	return 0xFFFF;
}

void RefreshDouble(touchgfx::Unicode::UnicodeChar* buffer, double value, const char* format){
	touchgfx::Unicode::snprintfFloat(buffer, BUFF_SIZE, format, value);
}

int FormatToInt(uint32_t value){
	if (value & 0x8000){
		int ivalue = ((~value) & 0x0000FFFF) + 1;
		ivalue *= -1;
		return ivalue;
	}

	return value;
}


void RefreshDouble(touchgfx::Unicode::UnicodeChar* buffer, uint32_t value, const uint8_t decimal){
	const char* format = 0;//GetDecimalFormat(decimal);

	if(pGetDecimalFormat)
		format = pGetDecimalFormat(decimal);

	//double doubleValue = ((double)value) / pow(10, decimal);
	double doubleValue = ((double)(FormatToInt(value))) / pow(10, decimal);
	RefreshDouble(buffer, doubleValue, format);
}

void RefreshInt(touchgfx::Unicode::UnicodeChar* buffer, uint32_t value){
	touchgfx::Unicode::snprintf(buffer, BUFF_SIZE, "%d", value);
}

void RefreshInt2(touchgfx::Unicode::UnicodeChar* buffer, uint32_t  value){
	touchgfx::Unicode::snprintf(buffer, BUFF_SIZE, "%02d", value);
}

void RefreshString(touchgfx::TextArea *textArea, int address, uint32_t value){
	if (textArea != NULL)
		textArea->setTypedText(touchgfx::TypedText(getTexts(address, value)));
}

void RefreshString(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, char* str){
	touchgfx::Unicode::strncpy(buffer, str, BUFF_SIZE);
	if (textArea != NULL)
		textArea->invalidate();
}

void RefreshFP32BitFloat(touchgfx::Unicode::UnicodeChar* buffer, uint32_t value, uint8_t decimal){
	const char* format = NULL;	// 	= GetDecimalFormat(decimal);
	double val = 0;				// 	= FromFloatingPointToDecimalSinglePrecision(value);

	if(pGetDecimalFormat)
		format = pGetDecimalFormat(decimal);

	if(pFromFloatingPointToDecimalSinglePrecision)
		val = pFromFloatingPointToDecimalSinglePrecision((double)value);

	RefreshDouble(buffer, val, format);
}

uint32_t GetRealValue(uint32_t value, DataType dataType, uint8_t decimal){
	uint32_t val = 0;
	switch(dataType){
		case _FP_32BIT_:
		{
			if(pFromFloatingPointToDecimalSinglePrecision)
				val = pFromFloatingPointToDecimalSinglePrecision((double)value);
		}
			break;
		default:
			val = value;
			break;
	}

	return val;
}

void RefreshData(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int address, uint32_t value, DataType dataType, uint8_t decimal){
	switch(dataType){
		case _INT_:
			RefreshInt(buffer, value);
			break;
		case _INT2_:
			RefreshInt2(buffer, value);
			break;
		case _DOUBLE_:
			RefreshDouble(buffer, value, decimal);
			break;
		case _STRING_:
			RefreshString(textArea, address, value);
			break;
		case _FP_32BIT_:
			RefreshFP32BitFloat(buffer, value, decimal);
			break;
		default:
			break;

	}
}

void ClearItems(){
	nItems = 0;
	nTextItems = 0;
	nImageWordOptionItems = 0;
	nImageWordItems = 0;
	nImageItems = 0;
	nImageHDXItems = 0;
	nHideImageCondItems = 0;
	nToggleItems = 0;
	nBtnStateImgItems = 0;
	nButtonVisibilityItems = 0;
	nFlexButtonVisibilityItems = 0;
	nTextVisibilityItems = 0;
	nCntVisibilityItems = 0;
	nImageVisibilityItems = 0;
	nJobItems = 0;
	nJobImageItems = 0;
	nTextAssocBitItem = 0;
	nBlinkImageModbusItem = 0;
	nBlinkTxtModbusItem = 0;
	nBlinkImageItem = 0;
	nAlarmItems = 0;
	nScrollAlarmItems = 0;
	nButtonPressedDlyItems = 0;
	nRTCItems = 0;
	nModbusErrContVisibilityItems = 0;
	nCircularProgressItems = 0;
	nBeepItems = 0;
	nReadJobNameItems = 0;
	nSwipeContainerItems = 0;

	memset(jobItems, 0, sizeof(JobItem) * JOB_ITEM_SIZE);

	if(pSwitchBuzzerOff)
		(*pSwitchBuzzerOff)();
}

void RefreshModbusCommErrVisibility(uint8_t (*pTimeoutComm)(uint32_t), Protocol protocol){

	if(!pTimeoutComm)
		return;

	int i;
	for(i = 0; i < nModbusErrContVisibilityItems; i++){
		if(modbusErrContVisibilityItems[i].Container){
			if(modbusErrContVisibilityItems[i].ProtocolType == protocol){
				if((*pTimeoutComm)(modbusErrContVisibilityItems[i].Timeout)){
					if(!modbusErrContVisibilityItems[i].Container->isVisible()){
						modbusErrContVisibilityItems[i].Container->setVisible(true);
						modbusErrContVisibilityItems[i].Container->invalidate();
					}
				}
				else{
					if(modbusErrContVisibilityItems[i].Container->isVisible())
					{
						modbusErrContVisibilityItems[i].Container->setVisible(false);
						modbusErrContVisibilityItems[i].Container->invalidate();
					}
				}
			}
		}
	}
}

void AddRTCItem(touchgfx::TextArea *txt, touchgfx::Unicode::UnicodeChar* buffer, RTCType type){
/*	if(rtcItems == NULL)
		rtcItems = (RTCItem*)malloc(sizeof(RTCItem));

	rtcItems = (RTCItem*)realloc(rtcItems, sizeof(RTCItem) * (nRTCItems + 1));
*/
	rtcItems[nRTCItems].TextArea = txt;
	rtcItems[nRTCItems].Buffer = buffer;
	rtcItems[nRTCItems].Type = type;
	nRTCItems++;
}

void AddButtonPressedDlyItem(touchgfx::Button* button,
		uint16_t address,
		uint8_t bit,
		int16_t value,
		uint16_t dly,
		uint16_t dataType,
		touchgfx::GenericCallback<>* callback,
		Protocol protocol){
/*	if(buttonPressedDlyItems == NULL)
		buttonPressedDlyItems = (ButtonPressedDly*)malloc(sizeof(ButtonPressedDly));

	buttonPressedDlyItems = (ButtonPressedDly*)realloc(buttonPressedDlyItems, sizeof(ButtonPressedDly) * (nButtonPressedDlyItems + 1));
*/
	buttonPressedDlyItems[nButtonPressedDlyItems].Button 			= button;
	buttonPressedDlyItems[nButtonPressedDlyItems].Address 			= address;
	buttonPressedDlyItems[nButtonPressedDlyItems].Bit 				= bit;
	buttonPressedDlyItems[nButtonPressedDlyItems].DelayMilliseconds = dly;
	buttonPressedDlyItems[nButtonPressedDlyItems].Value		 		= value;
	buttonPressedDlyItems[nButtonPressedDlyItems].DataType	 		= dataType;
	buttonPressedDlyItems[nButtonPressedDlyItems].Callback	 		= callback;
	buttonPressedDlyItems[nButtonPressedDlyItems].ProtocolType 		= protocol;
	nButtonPressedDlyItems++;
}

void AddScrollAlarmItem(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int* indx){
/*	if(scrollAlarmItems == NULL)
		scrollAlarmItems = (ScrollAlarmItem*)malloc(sizeof(ScrollAlarmItem));

	scrollAlarmItems = (ScrollAlarmItem*)realloc(scrollAlarmItems, sizeof(ScrollAlarmItem) * (nScrollAlarmItems + 1));
*/

	scrollAlarmItems[nScrollAlarmItems].TextArea = textArea;
	scrollAlarmItems[nScrollAlarmItems].Buffer 	= buffer;
	scrollAlarmItems[nScrollAlarmItems].Indx 	= indx;
	scrollAlarmItems[nScrollAlarmItems].Full	= 0;
	nScrollAlarmItems++;
}

void AddBlinkImage(touchgfx::Image* image, uint16_t bitmapOn, uint16_t bitmapOff, uint32_t ms){
/*	if(blinkImageItem == NULL)
		blinkImageItem = (BlinkImageItem*)malloc(sizeof(BlinkImageItem));


	blinkImageItem = (BlinkImageItem*)realloc(blinkImageItem, sizeof(BlinkImageItem) * (nBlinkImageItem + 1));
*/

	blinkImageItem[nBlinkImageItem].Image 		= image;
	blinkImageItem[nBlinkImageItem].BitmapOn 	= bitmapOn;
	blinkImageItem[nBlinkImageItem].BitmapOff 	= bitmapOff;
	blinkImageItem[nBlinkImageItem].Millisec 	= ms;
	blinkImageItem[nBlinkImageItem].CurrMs 		= 0;
	nBlinkImageItem++;
}

void AddBlinkImageModbusItem(touchgfx::Image* image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, uint8_t value, uint32_t ms, Protocol protocol){
/*	if(blinkImageModbusItem == NULL)
		blinkImageModbusItem = (BlinkImageModbusItem*)malloc(sizeof(BlinkImageModbusItem));

	blinkImageModbusItem = (BlinkImageModbusItem*)realloc(blinkImageModbusItem, sizeof(BlinkImageModbusItem) * (nBlinkImageModbusItem + 1));
*/

	blinkImageModbusItem[nBlinkImageModbusItem].Image 			= image;
	blinkImageModbusItem[nBlinkImageModbusItem].Address 		= address;
	blinkImageModbusItem[nBlinkImageModbusItem].Bit				= bit;
	blinkImageModbusItem[nBlinkImageModbusItem].BitmapOn 		= bitmapOn;
	blinkImageModbusItem[nBlinkImageModbusItem].BitmapOff 		= bitmapOff;
	blinkImageModbusItem[nBlinkImageModbusItem].Value 			= value;
	blinkImageModbusItem[nBlinkImageModbusItem].Millisec		= ms;
	blinkImageModbusItem[nBlinkImageModbusItem].CurrMs			= 0;
	blinkImageModbusItem[nBlinkImageModbusItem].ProtocolType	= protocol;
	nBlinkImageModbusItem++;
}

void AddBlinkTxtModbusItem(touchgfx::TextArea* text, uint16_t address, uint8_t bit, uint8_t value, uint32_t ms, Protocol protocol){
/*	if(blinkTxtModbusItem == NULL)
		blinkTxtModbusItem = (BlinkTxtModbusItem*)malloc(sizeof(BlinkTxtModbusItem));

	blinkTxtModbusItem = (BlinkTxtModbusItem*)realloc(blinkTxtModbusItem, sizeof(BlinkTxtModbusItem) * (nBlinkTxtModbusItem + 1));
*/

	blinkTxtModbusItem[nBlinkTxtModbusItem].Text 			= text;
	blinkTxtModbusItem[nBlinkTxtModbusItem].Address 		= address;
	blinkTxtModbusItem[nBlinkTxtModbusItem].Bit				= bit;
	blinkTxtModbusItem[nBlinkTxtModbusItem].Value 			= value;
	blinkTxtModbusItem[nBlinkTxtModbusItem].Millisec		= ms;
	blinkTxtModbusItem[nBlinkTxtModbusItem].CurrMs			= 0;
	blinkTxtModbusItem[nBlinkTxtModbusItem].ProtocolType	= protocol;
	nBlinkTxtModbusItem++;
}

void AddItem(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, uint16_t address, DataType dataType, uint8_t decimal, Protocol protocol){
/*
	if(graphicItems == NULL)
		graphicItems = (GraphicItem*)malloc(sizeof(GraphicItem));

	graphicItems = (GraphicItem*)realloc(graphicItems, sizeof(GraphicItem) * (nItems + 1));
*/
	graphicItems[nItems].Address 		= address;
	graphicItems[nItems].TextArea 		= textArea;
	graphicItems[nItems].Buffer			= buffer;
	graphicItems[nItems].Type			= dataType;
	graphicItems[nItems].Decimal		= decimal;
	graphicItems[nItems].ProtocolType	= protocol;
	graphicItems[nItems].Value			= 0;
	nItems++;
}

void AddTextBitItem(uint16_t address, uint8_t bit, touchgfx::TextArea* textArea, TEXTS textOn, TEXTS textOff, Protocol protocol){
/*	if(textAssocBitItem == NULL)
		textAssocBitItem = (TextAssocBitItem*)malloc(sizeof(TextAssocBitItem));

	textAssocBitItem = (TextAssocBitItem*)realloc(textAssocBitItem, sizeof(TextAssocBitItem) * (nTextAssocBitItem + 1));
*/
	textAssocBitItem[nTextAssocBitItem].Address 		= address;
	textAssocBitItem[nTextAssocBitItem].Bit 			= bit;
	textAssocBitItem[nTextAssocBitItem].TextArea		= textArea;
	textAssocBitItem[nTextAssocBitItem].TextOn			= textOn;
	textAssocBitItem[nTextAssocBitItem].TextOff			= textOff;
	textAssocBitItem[nTextAssocBitItem].ProtocolType	= protocol;
	nTextAssocBitItem++;
}

void AddTextItem(int address, int value, TEXTS text){
/*	if(textLinkerItems == NULL)
		textLinkerItems = (TextLinkerItem*)malloc(sizeof(TextLinkerItem));


	textLinkerItems = (TextLinkerItem*)realloc(textLinkerItems, sizeof(TextLinkerItem) * (nTextItems + 1));
*/

	textLinkerItems[nTextItems].Address 	= address;
	textLinkerItems[nTextItems].Value 		= value;
	textLinkerItems[nTextItems].Text		= text;
	nTextItems++;
}

void AddHideImageCondItem(touchgfx::Image *image, uint16_t address, uint8_t bit, uint8_t value){
/*	if(hideImageCondItems == NULL)
		hideImageCondItems = (HideImageCondItem*)malloc(sizeof(HideImageCondItem));

	hideImageCondItems = (HideImageCondItem*)realloc(hideImageCondItems , sizeof(HideImageCondItem) * (nHideImageCondItems + 1));
*/
	hideImageCondItems[nHideImageCondItems].Image 	= image;
	hideImageCondItems[nHideImageCondItems].Address	= address;
	hideImageCondItems[nHideImageCondItems].Bit 	= bit;
	hideImageCondItems[nHideImageCondItems].Value	= value;
	nHideImageCondItems++;
}

void AddImageHDXItem(touchgfx::Image *image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff){
/*	if(imageHDXItems == NULL)
		imageHDXItems = (ImageItem*)malloc(sizeof(ImageItem));

	imageHDXItems = (ImageItem*)realloc(imageHDXItems, sizeof(ImageItem) * (nImageHDXItems + 1));
*/

	imageHDXItems[nImageHDXItems].Image 	= image;
	imageHDXItems[nImageHDXItems].Address 	= address;
	imageHDXItems[nImageHDXItems].Bit 		= bit;
	imageHDXItems[nImageHDXItems].BitmapOn	= bitmapOn;
	imageHDXItems[nImageHDXItems].BitmapOff	= bitmapOff;
	nImageHDXItems++;
}

void AddImageItem(touchgfx::Image *image, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, Protocol protocol){
/*	if(imageItems == NULL)
		imageItems = (ImageItem*)malloc(sizeof(ImageItem));

	imageItems = (ImageItem*)realloc(imageItems, sizeof(ImageItem) * (nImageItems + 1));
*/

	imageItems[nImageItems].Image 			= image;
	imageItems[nImageItems].Address 		= address;
	imageItems[nImageItems].Bit 			= bit;
	imageItems[nImageItems].BitmapOn		= bitmapOn;
	imageItems[nImageItems].BitmapOff		= bitmapOff;
	imageItems[nImageItems].ProtocolType	= protocol;
	nImageItems++;
}

void AddImageWordItem(touchgfx::Image *image, uint16_t address, uint16_t value, uint16_t bitmap, Protocol protocol){
/*	if(imageWordOptionItems == NULL)
		imageWordOptionItems = (ImageWordOptionItem*)malloc(sizeof(ImageWordOptionItem));

	imageWordOptionItems = (ImageWordOptionItem*)realloc(imageWordOptionItems, sizeof(ImageWordOptionItem) * (nImageWordOptionItems + 1));
*/

	imageWordOptionItems[nImageWordOptionItems].Image 			= image;
	imageWordOptionItems[nImageWordOptionItems].Value 			= value;
	imageWordOptionItems[nImageWordOptionItems].Bitmap			= bitmap;
	nImageWordOptionItems++;

	/*if(imageWordItems == NULL)
		imageWordItems = (ImageWordItem*)malloc(sizeof(ImageWordItem));*/

	int i;
	for(i = 0; i < nImageWordItems; i++){
		if(imageWordItems[i].Image == image)	break;
	}

	if(i >= nImageWordItems){
		//imageWordItems = (ImageWordItem*)realloc(imageWordItems, sizeof(ImageWordItem) * (nImageWordItems + 1));

		imageWordItems[nImageWordItems].Image 			= image;
		imageWordItems[nImageWordItems].Address			= address;
		imageWordItems[nImageWordItems].ProtocolType	= protocol;
		nImageWordItems++;
	}
}

void AddSwipeContainer(touchgfx::SwipeContainer* swipeContainer, uint16_t address){
	swipeContainerItems[nSwipeContainerItems].SwipeContainer	= swipeContainer;
	swipeContainerItems[nSwipeContainerItems].Address 			= address;
	swipeContainerItems[nSwipeContainerItems].CurrMs 			= 0;
	nSwipeContainerItems++;
}

void AddBeep(uint16_t address, uint8_t bit, uint32_t ms, Protocol protocol){
/*
	if(beepItems == NULL)
		beepItems = (BeepItem*)malloc(sizeof(BeepItem));

	beepItems = (BeepItem*)realloc(beepItems, sizeof(BeepItem) * (nBeepItems + 1));
*/
	beepItems[nBeepItems].Address 			= address;
	beepItems[nBeepItems].Bit 				= bit;
	beepItems[nBeepItems].ProtocolType 		= protocol;
	beepItems[nBeepItems].Ms		 		= ms;
	beepItems[nBeepItems].CurrMs			= 0;
	nBeepItems++;
}

void AddCircularProgressItem(touchgfx::CircleProgress* progress, uint16_t address, DataType dataType, Protocol protocol){
/*
	if(circularProgressItems == NULL)
		circularProgressItems = (CircularProgressItem*)malloc(sizeof(CircularProgressItem));

	circularProgressItems = (CircularProgressItem*)realloc(circularProgressItems, sizeof(CircularProgressItem) * (nCircularProgressItems + 1));
*/

	circularProgressItems[nCircularProgressItems].CircleProgress	= progress;
	circularProgressItems[nCircularProgressItems].Address 			= address;
	circularProgressItems[nCircularProgressItems].Type 				= dataType;
	circularProgressItems[nCircularProgressItems].ProtocolType 		= protocol;
	nCircularProgressItems++;
}

void AddToggleItem(touchgfx::Button *button, uint16_t address, uint8_t bit, uint16_t bitmapOn, uint16_t bitmapOff, Protocol protocol){
/*	if(toggleItems == NULL)
		toggleItems = (ToggleItem*)malloc(sizeof(ToggleItem));

	toggleItems = (ToggleItem*)realloc(toggleItems, sizeof(ToggleItem) * (nToggleItems + 1));
*/
	toggleItems[nToggleItems].Button		= button;
	toggleItems[nToggleItems].Address 		= address;
	toggleItems[nToggleItems].Bit 			= bit;
	toggleItems[nToggleItems].BitmapOn		= bitmapOn;
	toggleItems[nToggleItems].BitmapOff		= bitmapOff;
	toggleItems[nToggleItems].ProtocolType	= protocol;
	nToggleItems++;
}

void AddButtonImageStateItem(touchgfx::Button* button, uint16_t address, uint16_t imageOn, uint16_t imageOff, uint16_t value, Protocol protocol){
/*	if(btnStateImgItems == NULL)
		btnStateImgItems = (ButtonStateImgItem*)malloc(sizeof(ButtonStateImgItem));

	btnStateImgItems = (ButtonStateImgItem*)realloc(btnStateImgItems, sizeof(ButtonStateImgItem) * (nBtnStateImgItems + 1));
*/
	btnStateImgItems[nBtnStateImgItems].Button			= button;
	btnStateImgItems[nBtnStateImgItems].Address 		= address;
	btnStateImgItems[nBtnStateImgItems].Value 			= value;
	btnStateImgItems[nBtnStateImgItems].BitmapOn		= imageOn;
	btnStateImgItems[nBtnStateImgItems].BitmapOff		= imageOff;
	btnStateImgItems[nBtnStateImgItems].ProtocolType	= protocol;
	nBtnStateImgItems++;
}

void AddFlexButtonVisibilityItem(touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >* button, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol){
/*	if(flexBtnVisibilityItems == NULL)
		flexBtnVisibilityItems = (FlexButtonVisibilityItem*)malloc(sizeof(FlexButtonVisibilityItem));

	flexBtnVisibilityItems = (FlexButtonVisibilityItem*)realloc(flexBtnVisibilityItems, sizeof(FlexButtonVisibilityItem) * (nFlexButtonVisibilityItems + 1));
*/
	flexBtnVisibilityItems[nFlexButtonVisibilityItems].Button		= button;
	flexBtnVisibilityItems[nFlexButtonVisibilityItems].Address 		= address;
	flexBtnVisibilityItems[nFlexButtonVisibilityItems].Bit 			= bit;
	flexBtnVisibilityItems[nFlexButtonVisibilityItems].Value 		= value;
	flexBtnVisibilityItems[nFlexButtonVisibilityItems].ProtocolType = protocol;
	nFlexButtonVisibilityItems++;
}

void AddButtonVisibilityItem(touchgfx::Button *button, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol){
/*	if(btnVisibilityItems == NULL)
		btnVisibilityItems = (ButtonVisibilityItem*)malloc(sizeof(ButtonVisibilityItem));

	btnVisibilityItems = (ButtonVisibilityItem*)realloc(btnVisibilityItems, sizeof(ButtonVisibilityItem) * (nButtonVisibilityItems + 1));
*/
	btnVisibilityItems[nButtonVisibilityItems].Button			= button;
	btnVisibilityItems[nButtonVisibilityItems].Address 			= address;
	btnVisibilityItems[nButtonVisibilityItems].Bit 				= bit;
	btnVisibilityItems[nButtonVisibilityItems].Value 			= value;
	btnVisibilityItems[nButtonVisibilityItems].ProtocolType 	= protocol;
	nButtonVisibilityItems++;
}

void AddTextVisibilityItem(touchgfx::TextArea *textArea, uint16_t address, uint8_t bit, uint8_t value, Protocol protocol){
/*	if(txtVisibilityItems == NULL)
		txtVisibilityItems = (TextVisibilityItem*)malloc(sizeof(TextVisibilityItem));

	txtVisibilityItems = (TextVisibilityItem*)realloc(txtVisibilityItems, sizeof(TextVisibilityItem) * (nTextVisibilityItems + 1));
*/
	txtVisibilityItems[nTextVisibilityItems].Text			= textArea;
	txtVisibilityItems[nTextVisibilityItems].Address 		= address;
	txtVisibilityItems[nTextVisibilityItems].Bit 			= bit;
	txtVisibilityItems[nTextVisibilityItems].Value 			= value;
	txtVisibilityItems[nTextVisibilityItems].ProtocolType	= protocol;
	nTextVisibilityItems++;
}

void AddImageVisibilityItem(touchgfx::Image* image, uint16_t address, uint8_t bit, uint8_t condition, Protocol protocol){
/*	if(imageVisibilityItems == NULL)
		imageVisibilityItems = (ImageVisibilityItem*)malloc(sizeof(ImageVisibilityItem));


	imageVisibilityItems = (ImageVisibilityItem*)realloc(imageVisibilityItems, sizeof(ImageVisibilityItem) * (nImageVisibilityItems + 1));
*/
	imageVisibilityItems[nImageVisibilityItems].Image			= image;
	imageVisibilityItems[nImageVisibilityItems].Address 		= address;
	imageVisibilityItems[nImageVisibilityItems].Bit 			= bit;
	imageVisibilityItems[nImageVisibilityItems].Condition		= condition;
	imageVisibilityItems[nImageVisibilityItems].ProtocolType	= protocol;
	nImageVisibilityItems++;
}

void AddContainerVisibilityItem(touchgfx::Container *container, uint16_t address, uint8_t bit, uint8_t condition, Protocol protocol){
/*	if(cntVisibilityItems == NULL)
		cntVisibilityItems = (ContainerVisibilityItem*)malloc(sizeof(ContainerVisibilityItem));


	cntVisibilityItems = (ContainerVisibilityItem*)realloc(cntVisibilityItems, sizeof(ContainerVisibilityItem) * (nCntVisibilityItems + 1));
*/
	cntVisibilityItems[nCntVisibilityItems].Container		= container;
	cntVisibilityItems[nCntVisibilityItems].Address 		= address;
	cntVisibilityItems[nCntVisibilityItems].Bit 			= bit;
	cntVisibilityItems[nCntVisibilityItems].Condition		= condition;
	cntVisibilityItems[nCntVisibilityItems].ProtocolType	= protocol;
	nCntVisibilityItems++;
}

void AddModbusErrCommContainerVisibility(touchgfx::Container* container, uint16_t time, Protocol protocol){
/*	if(modbusErrContVisibilityItems == NULL)
		modbusErrContVisibilityItems = (ModbusErrContVisibility*)malloc(sizeof(ModbusErrContVisibility));

	modbusErrContVisibilityItems = (ModbusErrContVisibility*)realloc(modbusErrContVisibilityItems, sizeof(ModbusErrContVisibility) * (nModbusErrContVisibilityItems + 1));
*/

	modbusErrContVisibilityItems[nModbusErrContVisibilityItems].Container 		= container;
	modbusErrContVisibilityItems[nModbusErrContVisibilityItems].Timeout 		= time;
	modbusErrContVisibilityItems[nModbusErrContVisibilityItems].ProtocolType 	= protocol;
	nModbusErrContVisibilityItems++;
}

void AddAlarmItem(uint16_t address, uint8_t bit, TEXTS message, TEXTS invMessage, Protocol protocol){
/*	if(alarmItems == NULL)
		alarmItems = (AlarmItem*)malloc(sizeof(AlarmItem));

	alarmItems = (AlarmItem*)realloc(alarmItems, sizeof(AlarmItem) * (nAlarmItems + 1));
*/

	alarmItems[nAlarmItems].InvalidMessage	= invMessage;
	alarmItems[nAlarmItems].Message			= message;
	alarmItems[nAlarmItems].Address 		= address;
	alarmItems[nAlarmItems].Bit 			= bit;
	alarmItems[nAlarmItems].Added 			= 0;
	alarmItems[nAlarmItems].ProtocolType	= protocol;
	nAlarmItems++;
}

void AddReadJobName(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, uint16_t address, uint8_t length, Protocol protocol){
/*	if(readJobNameItem != NULL){
		free(readJobNameItem);
		readJobNameItem = NULL;
	}

	readJobNameItem = (ReadJobNameItem*)malloc(sizeof(ReadJobNameItem));
*/
	nReadJobNameItems = 1;
	readJobNameItem.TextArea 		= textArea;
	readJobNameItem.Buffer 			= buffer;
	readJobNameItem.Address 		= address;
	readJobNameItem.Length 			= length;
	readJobNameItem.ProtocolType 	= protocol;
}

void UpdateTextItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nItems == 0)
		return;

	GraphicItem items[nItems];
	memcpy(items, graphicItems, sizeof(GraphicItem) * nItems);

	int i = 0;
	for(i = 0; i < nItems; i++){
		/*
		if(items[i].Address == address && items[i].TextArea != NULL && items[i].ProtocolType == protocol){
			if(items[i].TextArea){
				items[i].Value = value;
				RefreshData(items[i].TextArea, items[i].Buffer, items[i].Address, items[i].Value, items[i].Type, items[i].Decimal);
				items[i].TextArea->invalidate();
			}
		}
		*/
		if (items[i].Address == address && items[i].ProtocolType == protocol){
			items[i].Value = value;
			RefreshData(items[i].TextArea, items[i].Buffer, items[i].Address, items[i].Value, items[i].Type, items[i].Decimal);
			if (items[i].TextArea != NULL)
				items[i].TextArea->invalidate();
		}
	}
}

void UpdateTextAssocBitItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nTextAssocBitItem == 0)
		return;

	TextAssocBitItem items[nTextAssocBitItem];
	memcpy(items, textAssocBitItem, sizeof(TextAssocBitItem) * nTextAssocBitItem);

	int i = 0;
	for(i = 0; i < nTextAssocBitItem; i++){
		if(items[i].Address == address && items[i].ProtocolType == protocol){
			uint8_t bitVal = (value >> items[i].Bit) & 0x01;
			if(items[i].TextArea){
				items[i].TextArea->setTypedText(touchgfx::TypedText(bitVal ? items[i].TextOn : items[i].TextOff));
				items[i].TextArea->invalidate();
			}
		}
	}
}

uint8_t GetRTCItem(RTCType type){

	if(type == _DAY_ && pTimeReadDay)
		return (*pTimeReadDay)();

	if(type == _MONTH_ && pTimeReadMonth)
		return (*pTimeReadMonth)();

	if(type == _YEAR_ && pTimeReadYear)
		return (*pTimeReadYear)();

	if(type == _HOUR_ && pTimeReadHour)
		return (*pTimeReadHour)();

	if(type == _MIN_ && pTimeReadMin)
		return (*pTimeReadMin)();

	if(type == _SEC_ && pTimeReadSec)
		return (*pTimeReadSec)();

	return 0;
}

void RefreshSwipeContainers(){
	int i;
	for(i = 0; i < nSwipeContainerItems && pUpdateModbusINT; i++){
		if(swipeContainerItems[i].SwipeContainer){
			if((*pTimeElapsed)(&swipeContainerItems[i].CurrMs, 500)){
				uint8_t selectedPage = swipeContainerItems[i].SwipeContainer->getSelectedPage();
				(*pUpdateModbusINT)(swipeContainerItems[i].Address, (double)selectedPage, _INT_);
			}
		}
	}
}

void RefreshRTC(){
	if(nRTCItems == 0)
		return;

	int i;
	for(i = 0; i < nRTCItems; i++) {
		uint8_t item = GetRTCItem(rtcItems[i].Type);
		/*
		if(rtcItems[i].TextArea){
			RefreshData(rtcItems[i].TextArea, rtcItems[i].Buffer, 0, item, _INT2_, 0);
			rtcItems[i].TextArea->invalidate();
		}
		*/
		RefreshData(rtcItems[i].TextArea, rtcItems[i].Buffer, 0, item, _INT2_, 0);
		if (rtcItems[i].TextArea != NULL)
			rtcItems[i].TextArea->invalidate();
	}
}

void RefreshImageHDX(){
	if(nImageHDXItems == 0)
		return;

	ImageItem items[nImageHDXItems];
	memcpy(items, imageHDXItems, sizeof(ImageItem) * nImageHDXItems);

	int i = 0;
	for(i = 0; i < nImageHDXItems && pReadParameter; i++){
		uint16_t addr = items[i].Address;
		uint8_t value = (*pReadParameter)(addr);
		uint8_t bitVal = (value >> items[i].Bit) & 0x01;
		uint16_t bitmap = items[i].Image->getBitmap();

		if(bitVal && bitmap != items[i].BitmapOn){
			items[i].Image->setBitmap(touchgfx::Bitmap(items[i].BitmapOn));
			items[i].Image->invalidate();
		}

		if(!bitVal && bitmap != items[i].BitmapOff){
			items[i].Image->setBitmap(touchgfx::Bitmap(items[i].BitmapOff));
			items[i].Image->invalidate();
		}
	}
}

void RefreshButtonHDXVisibility(){
	int i;
	for(i = 0; i < nButtonVisibilityItems; i++){
		if(btnVisibilityItems[i].Button != NULL){
			if(btnVisibilityItems[i].ProtocolType == PT_HDX){
				uint16_t addr = btnVisibilityItems[i].Address;
				uint8_t value = (*pReadParameter)(addr);
				uint8_t bitVal = (value >> btnVisibilityItems[i].Bit) & 0x01;
				bool visibility = bitVal == btnVisibilityItems[i].Value;

				if(btnVisibilityItems[i].Button){
					bool isVisible = btnVisibilityItems[i].Button->isVisible();

					if(visibility && !isVisible){
						btnVisibilityItems[i].Button->setVisible(true);
						btnVisibilityItems[i].Button->invalidate();
					}

					if(!visibility && isVisible){
						btnVisibilityItems[i].Button->setVisible(false);
						btnVisibilityItems[i].Button->invalidate();
					}
				}
			}
		}
	}
}

void RefreshContainerHDXVisibility(){
	int i;
	for(i = 0; i < nCntVisibilityItems; i++){
		if(cntVisibilityItems[i].Container != NULL){
			if(cntVisibilityItems[i].ProtocolType == PT_HDX){
				uint16_t addr = cntVisibilityItems[i].Address;
				uint8_t value = (*pReadParameter)(addr);
				uint8_t bitVal = (value >> cntVisibilityItems[i].Bit) & 0x01;
				bool visibility = bitVal == cntVisibilityItems[i].Condition;

				if(cntVisibilityItems[i].Container){
					bool isVisible = cntVisibilityItems[i].Container->isVisible();

					if(visibility && !isVisible){
						cntVisibilityItems[i].Container->setVisible(true);
						cntVisibilityItems[i].Container->invalidate();
					}

					if(!visibility && isVisible){
						cntVisibilityItems[i].Container->setVisible(false);
						cntVisibilityItems[i].Container->invalidate();
					}
				}
			}
		}
	}
}

void UpdateImageItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nImageItems == 0)
		return;

	ImageItem items[nImageItems];
	memcpy(items, imageItems, sizeof(ImageItem) * nImageItems);

	int i = 0;
	for(i = 0; i < nImageItems; i++){
		if(items[i].Address == address && items[i].ProtocolType == protocol){
			uint8_t bitVal = (value >> items[i].Bit) & 0x01;

			if(items[i].Image){
				uint16_t bitmap = items[i].Image->getBitmap();

				if(bitVal && bitmap != items[i].BitmapOn){
					items[i].Image->setBitmap(touchgfx::Bitmap(items[i].BitmapOn));
					items[i].Image->invalidate();
				}

				if(!bitVal && bitmap != items[i].BitmapOff){
					items[i].Image->setBitmap(touchgfx::Bitmap(items[i].BitmapOff));
					items[i].Image->invalidate();
				}
			}
		}
	}
}

void UpdateImageWordItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nImageWordItems == 0)
		return;

	ImageWordItem items[nImageWordItems];
	memcpy(items, imageWordItems, sizeof(ImageWordItem) * nImageWordItems);

	int i = 0;
	for(i = 0; i < nImageWordItems; i++){
		if(items[i].Address == address &&
				items[i].ProtocolType == protocol){

			if(items[i].Image){
				uint16_t currBitmap = items[i].Image->getBitmap();
				uint16_t bitmap = getOptionBitmap(items[i].Image, value);

				if(bitmap == 0xFFFF){
					if(items[i].Image->isVisible()){
						items[i].Image->setVisible(false);
						items[i].Image->invalidate();
					}
				}
				else{
					if(!items[i].Image->isVisible()){
						items[i].Image->setVisible(true);
						items[i].Image->invalidate();
					}

					if(bitmap != currBitmap){
						items[i].Image->setBitmap(touchgfx::Bitmap(bitmap));
						items[i].Image->invalidate();
					}
				}
			}
		}
	}
}

void UpdateToggleItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nToggleItems == 0)
		return;

	ToggleItem items[nToggleItems];
	memcpy(items, toggleItems, sizeof(ToggleItem) * nToggleItems);

	int i = 0;
	for(i = 0; i < nToggleItems; i++){
		if(items[i].Address == address && items[i].ProtocolType == protocol){
			uint8_t bitVal = (value >> items[i].Bit) & 0x01;
			Bitmap bitmap = items[i].Button->getCurrentlyDisplayedBitmap();

			if(bitmap.getId() == items[i].BitmapOn && !bitVal){
				items[i].Button->setBitmaps(touchgfx::Bitmap(items[i].BitmapOff), touchgfx::Bitmap(items[i].BitmapOff));
				items[i].Button->invalidate();
			}

			if(bitmap.getId() == items[i].BitmapOff && bitVal){
				items[i].Button->setBitmaps(touchgfx::Bitmap(items[i].BitmapOn), touchgfx::Bitmap(items[i].BitmapOn));
				items[i].Button->invalidate();
			}
		}
	}
}

void UpdateBtnStateImgItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nBtnStateImgItems == 0)
		return;

	ButtonStateImgItem items[nBtnStateImgItems];
	memcpy(items, btnStateImgItems, sizeof(ButtonStateImgItem) * nBtnStateImgItems);

	int i = 0;
	for(i = 0; i < nBtnStateImgItems; i++){
		if(items[i].Address == address && items[i].ProtocolType == protocol){

			if(items[i].Button){
				Bitmap bitmap = items[i].Button->getCurrentlyDisplayedBitmap();

				if(items[i].Value == value && bitmap.getId() == items[i].BitmapOff){
					items[i].Button->setBitmaps(touchgfx::Bitmap(items[i].BitmapOn), touchgfx::Bitmap(items[i].BitmapOn));
					items[i].Button->invalidate();
				}

				if(items[i].Value != value && bitmap.getId() == items[i].BitmapOn){
					items[i].Button->setBitmaps(touchgfx::Bitmap(items[i].BitmapOff), touchgfx::Bitmap(items[i].BitmapOff));
					items[i].Button->invalidate();
				}
			}
		}
	}
}

void UpdateFlexBtnVisibilityItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nFlexButtonVisibilityItems == 0)
		return;

	FlexButtonVisibilityItem items[nFlexButtonVisibilityItems];
	memcpy(items, flexBtnVisibilityItems, sizeof(FlexButtonVisibilityItem) * nFlexButtonVisibilityItems);

	int i = 0;
	for(i = 0; i < nFlexButtonVisibilityItems; i++){
		if(items[i].Address == address && items[i].ProtocolType == protocol){
			uint8_t bitVal = (value >> items[i].Bit) & 0x01;
			bool visibility = bitVal == items[i].Value;

			if(items[i].Button){
				bool isVisible = items[i].Button->isVisible();

				if(visibility && !isVisible){
					items[i].Button->setVisible(true);
					items[i].Button->setTouchable(true);
					items[i].Button->invalidate();
				}

				if(!visibility && isVisible){
					items[i].Button->setVisible(false);
					items[i].Button->setTouchable(false);
					items[i].Button->invalidate();
				}
			}
		}
	}
}

void UpdateBtnVisibilityItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nButtonVisibilityItems == 0)
		return;

	ButtonVisibilityItem items[nButtonVisibilityItems];
	memcpy(items, btnVisibilityItems, sizeof(ButtonVisibilityItem) * nButtonVisibilityItems);

	int i = 0;
	for(i = 0; i < nButtonVisibilityItems; i++){
		if(items[i].Address == address && items[i].ProtocolType == protocol){
			uint8_t bitVal = (value >> items[i].Bit) & 0x01;
			bool visibility = bitVal == items[i].Value;

			if(items[i].Button){
				bool isVisible = items[i].Button->isVisible();

				if(visibility && !isVisible){
					items[i].Button->setVisible(true);
					items[i].Button->invalidate();
				}

				if(!visibility && isVisible){
					items[i].Button->setVisible(false);
					items[i].Button->invalidate();
				}
			}
		}
	}
}

void UpdateTxtVisibilityItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nTextVisibilityItems == 0)
		return;

	TextVisibilityItem  items[nTextVisibilityItems];
	memcpy(items, txtVisibilityItems, sizeof(TextVisibilityItem) * nTextVisibilityItems);

	int i = 0;
	for(i = 0; i < nTextVisibilityItems; i++){
		if(items[i].Address == address && items[i].ProtocolType == protocol){
			uint8_t bitVal = (value >> items[i].Bit) & 0x01;
			bool visibility = bitVal == items[i].Value;

			if(items[i].Text){
				bool isVisible = items[i].Text->isVisible();

				if(visibility && !isVisible){
					items[i].Text->setVisible(visibility);
					items[i].Text->invalidate();
				}

				if(!visibility && isVisible){
					items[i].Text->setVisible(visibility);
					items[i].Text->invalidate();
				}
			}
		}
	}
}

void UpdateImageVisibilityItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nImageVisibilityItems == 0)
		return;

	ImageVisibilityItem  items[nImageVisibilityItems];
	memcpy(items, imageVisibilityItems, sizeof(ImageVisibilityItem) * nImageVisibilityItems);

	int i = 0;
	for(i = 0; i < nImageVisibilityItems; i++){
		if(items[i].Address == address && items[i].ProtocolType == protocol){
			uint8_t bitVal = (value >> items[i].Bit) & 0x01;

			if(items[i].Image){
				if(bitVal == items[i].Condition && !items[i].Image->isVisible()){
					items[i].Image->setVisible(true);
					items[i].Image->invalidate();
				}

				if(bitVal != items[i].Condition && items[i].Image->isVisible()){
					items[i].Image->setVisible(false);
					items[i].Image->invalidate();
				}
			}
		}
	}
}

void UpdateCntVisibilityItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nCntVisibilityItems == 0)
		return;

	ContainerVisibilityItem  items[nCntVisibilityItems];
	memcpy(items, cntVisibilityItems, sizeof(ContainerVisibilityItem) * nCntVisibilityItems);

	int i = 0;
	for(i = 0; i < nCntVisibilityItems; i++){
		if(items[i].Address == address && items[i].ProtocolType == protocol){
			uint8_t bitVal = (value >> items[i].Bit) & 0x01;

			if(items[i].Container){
				if(bitVal == items[i].Condition && !items[i].Container->isVisible()){
					items[i].Container->setVisible(true);
					items[i].Container->invalidate();
				}

				if(bitVal != items[i].Condition && items[i].Container->isVisible()){
					items[i].Container->setVisible(false);
					items[i].Container->invalidate();
				}
			}
		}
	}
}

void UpdateBeepItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nBeepItems == 0)
		return;

	int i;
	for(i = 0; i < nBeepItems; i++){
		if(beepItems[i].Address == address && beepItems[i].ProtocolType == protocol){
			uint8_t bit = (( value >> beepItems[i].Bit ) & 0x01);

			if(bit && pTimeElapsed && pToggleBuzzer){
				if((*pTimeElapsed)(&beepItems[i].CurrMs, beepItems[i].Ms)){
					(*pToggleBuzzer)();
				}
			}

			if(beepItems[i].On != bit && pSwitchBuzzerOff){
				(*pSwitchBuzzerOff)();
			}

			beepItems[i].On = bit;
		}
	}
}

void UpdateCircularProgressItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nCircularProgressItems == 0)
		return;

	CircularProgressItem items[nCircularProgressItems];
	memcpy(items, circularProgressItems, sizeof(CircularProgressItem) * nCircularProgressItems);

	int i = 0;
	for(i = 0; i < nCircularProgressItems; i++){
		if(items[i].Address == address &&
				items[i].ProtocolType == protocol){
			if(items[i].CircleProgress != NULL){
				uint16_t currValue = items[i].CircleProgress->getValue();
				uint32_t realValue = GetRealValue(value, items[i].Type, 0);
				if(currValue != realValue){
					items[i].CircleProgress->setValue(realValue);
					items[i].CircleProgress->invalidate();
				}
			}
		}
	}
}

void UpdateAlarmItem(uint16_t address, uint32_t value, Protocol protocol){
	if(nAlarmItems == 0 || nScrollAlarmItems == 0)
		return;

	AlarmItem items[nAlarmItems];
	memcpy(items, alarmItems, sizeof(AlarmItem) * nAlarmItems);

	ScrollAlarmItem scrollItems[nScrollAlarmItems];
	memcpy(scrollItems, scrollAlarmItems, sizeof(ScrollAlarmItem) * nScrollAlarmItems);

	int i = 0, j = 0, nAlarms = 0, isAllarmAddress = 0;
	ScrollAlarmItem temp;

	 for (i = 0; i < nScrollAlarmItems; i++) {
		for (j = i + 1; j < nScrollAlarmItems; j++) {
		   if((*scrollItems[i].Indx) > (*scrollItems[j].Indx)) {
			   temp = scrollItems[i];
			   scrollItems[i] = scrollItems[j];
			   scrollItems[j] = temp;
		   }
		}
	}

	int startScrollIdx = *scrollItems[0].Indx;
	int scrollIdx = 0;

	for(i = 0; i < nAlarmItems; i++){
		if(address == items[i].Address && protocol == items[i].ProtocolType)
		{
			isAllarmAddress = 1;
			uint8_t bit = (value >> items[i].Bit) & 0x01;
			if(bit){
				if(nAlarms >= startScrollIdx && scrollIdx < nScrollAlarmItems){
					scrollItems[scrollIdx].TextArea->setTypedText(touchgfx::TypedText(items[i].Message));
					scrollItems[scrollIdx].TextArea->invalidate();
					scrollIdx++;
				}
				nAlarms++;
			}
		}
	}

	for(i = scrollIdx; i < nScrollAlarmItems && isAllarmAddress; i++){
		scrollItems[i].TextArea->setTypedText(touchgfx::TypedText(items[0].InvalidMessage));
		scrollItems[i].TextArea->invalidate();
	}
}

uint16_t GetAddressByBuffer(touchgfx::Unicode::UnicodeChar* buffer){
	if(graphicItems == NULL || nItems == 0)
		return 0;

	GraphicItem items[nItems];
	memcpy(items, graphicItems, sizeof(GraphicItem) * nItems);

	int i = 0;
	for(i = 0; i < nItems; i++){
		if(items[i].Buffer == buffer){
			return items[i].Address;
		}
	}

	return 0;
}

void AddJobImageItem(touchgfx::Image *image, uint16_t bitmapOn, uint16_t bitmapOff, int idx, uint8_t bit){
/*	if(jobImageItems == NULL)
		jobImageItems = (JobImageItem*)malloc(sizeof(JobImageItem));

	jobImageItems = (JobImageItem*)realloc(jobImageItems, sizeof(JobImageItem) * (nJobImageItems + 1));
*/
	jobImageItems[nJobImageItems].Image	= image;
	jobImageItems[nJobImageItems].BitmapOn = bitmapOn;
	jobImageItems[nJobImageItems].BitmapOff = bitmapOff;
	jobImageItems[nJobImageItems].Idx = idx;
	jobImageItems[nJobImageItems].Bit = bit;
	jobImageItems[nJobImageItems].Value = 0;
	jobImageItems[nJobImageItems].Flag = 255;
	nJobImageItems++;
}

void AddJobItem(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int idx, DataType dataType, uint8_t decimal)
{
	if(textArea == NULL || buffer == NULL)
		return;

/*	if(jobItems == NULL)
		jobItems = (JobItem*)malloc(sizeof(JobItem));


	jobItems = (JobItem*)realloc(jobItems, sizeof(JobItem) * (nJobItems + 1));
*/

	jobItems[nJobItems].TextArea	= textArea;
	jobItems[nJobItems].Buffer		= buffer;
	jobItems[nJobItems].Idx 		= idx;
	jobItems[nJobItems].Type 		= dataType;
	jobItems[nJobItems].Decimal		= decimal;
	jobItems[nJobItems].Value		= 0;
	//jobItems[nJobItems].ValueStr	= (char*)malloc(sizeof(char) * BUFF_SIZE);
	nJobItems++;
}

void UpdateButtonPressedItems(void (*pAddBitDlyItem)(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t), Protocol protocol){

	int i;
	for(i = 0; i < nButtonPressedDlyItems; i++){
		if(protocol == buttonPressedDlyItems[i].ProtocolType){
			if(buttonPressedDlyItems[i].Button){
				bool pressed = buttonPressedDlyItems[i].Button->getPressedState();
				if(pressed){
					if(!buttonPressedDlyItems[i].Pressed && pAddBitDlyItem &&
							!buttonPressedDlyItems[i].Callback){
						// Aggiornamento Modbus
						(*pAddBitDlyItem)(buttonPressedDlyItems[i].Address,
								buttonPressedDlyItems[i].Bit,
								buttonPressedDlyItems[i].Value,
								buttonPressedDlyItems[i].DelayMilliseconds,
								buttonPressedDlyItems[i].DataType);
					}

					if(buttonPressedDlyItems[i].Callback && pTsTimeoutElapsed){
						// Gestione evento...
						if((*pTsTimeoutElapsed)(buttonPressedDlyItems[i].DelayMilliseconds)){
							if(buttonPressedDlyItems[i].Callback->isValid())
								buttonPressedDlyItems[i].Callback->execute();
						}
					}
				}

				buttonPressedDlyItems[i].Pressed = pressed;
			}
		}
	}
}

uint8_t ImageVisibilityEnable(touchgfx::Image* Image){
	int i;
	for(i = 0; i < nHideImageCondItems && hideImageCondItems && pReadParameter; i++){
		if(Image == hideImageCondItems[i].Image){
			uint16_t addr 	= hideImageCondItems[i].Address;
			uint8_t bit  	= hideImageCondItems[i].Bit;
			uint8_t value 	= hideImageCondItems[i].Value;
			uint8_t val 	= ((*pReadParameter)(addr) >> bit ) & 0x01;
			return value != val;
		}
	}

	return 1;
}

void ReverseBitmap(touchgfx::Image* Image, uint16_t bitmapOn, uint16_t bitmapOff){
	BitmapId bitmap = Image->getBitmap();
	Image->setBitmap(touchgfx::Bitmap(bitmap == bitmapOff ? bitmapOn : bitmapOff));
	Image->setVisible(ImageVisibilityEnable(Image));
	Image->invalidate();
}

void SwitchImageOff(touchgfx::Image* Image, uint16_t bitmapOff){

	if(!Image)
		return;

	BitmapId bitmap = Image->getBitmap();
	if(bitmap != bitmapOff ){
		Image->setBitmap(touchgfx::Bitmap(bitmapOff));
		Image->invalidate();
	}
}

void SwitchTxtOff(touchgfx::TextArea* Text){

	if(!Text)
		return;

	if(Text->isVisible()){
		Text->setVisible(false);
		Text->invalidate();
	}
}

void ReverseTxtVisibility(touchgfx::TextArea* Text){
	if(!Text)
		return;

	if(Text->isVisible()){
		SwitchTxtOff(Text);
	}
	else{
		Text->setVisible(true);
		Text->invalidate();
	}
}

void RefreshBlinkingItems(uint16_t address, uint32_t value, Protocol protocol){
	uint8_t (*pBlinkingImageModbus)(uint16_t, uint8_t, uint8_t, uint32_t, uint32_t*) = NULL;

	if(MB_RS485 == protocol)
		pBlinkingImageModbus = pBlinkingImageModbusRS485;
	if(MB_TCPIP == protocol)
		pBlinkingImageModbus = pBlinkingImageModbusTCPIP;
	if(MB_TTL == protocol)
		pBlinkingImageModbus = pBlinkingImageModbusTTL;

	int i;
	if(pBlinkingImageModbus){
		for(i = 0; i < nBlinkImageModbusItem; i++){
			if(blinkImageModbusItem[i].Image){
				if(blinkImageModbusItem[i].ProtocolType == protocol &&
						blinkImageModbusItem[i].Address == address){

					uint8_t val = (value >> blinkImageModbusItem[i].Bit) & 0x01;

					if(val != blinkImageModbusItem[i].Value){
						SwitchImageOff(blinkImageModbusItem[i].Image, blinkImageModbusItem[i].BitmapOff);
					}
					else{
						if((*pBlinkingImageModbus)(blinkImageModbusItem[i].Address, blinkImageModbusItem[i].Bit, blinkImageModbusItem[i].Value, blinkImageModbusItem[i].Millisec, &blinkImageModbusItem[i].CurrMs))
							ReverseBitmap(blinkImageModbusItem[i].Image, blinkImageModbusItem[i].BitmapOn, blinkImageModbusItem[i].BitmapOff);
					}
				}
			}
		}
	}

	if(pBlinkingImageModbus){
		for(i = 0; i < nBlinkTxtModbusItem; i++){
			if(blinkTxtModbusItem[i].Text){
				if(blinkTxtModbusItem[i].ProtocolType == protocol &&
						blinkTxtModbusItem[i].Address == address){

					uint8_t val = (value >> blinkTxtModbusItem[i].Bit) & 0x01;

					if(val != blinkTxtModbusItem[i].Value){
						SwitchTxtOff(blinkTxtModbusItem[i].Text);
					}
					else{
						if((*pBlinkingImageModbus)(blinkTxtModbusItem[i].Address, blinkTxtModbusItem[i].Bit, blinkTxtModbusItem[i].Value, blinkTxtModbusItem[i].Millisec, &blinkTxtModbusItem[i].CurrMs))
							ReverseTxtVisibility(blinkTxtModbusItem[i].Text);
					}
				}
			}
		}
	}

	if(pTimeElapsed){
		for(i = 0; i < nBlinkImageItem; i++){
			if(blinkImageItem[i].Image){
				if((*pTimeElapsed)(&blinkImageItem[i].CurrMs, blinkImageItem[i].Millisec))
					ReverseBitmap(blinkImageItem[i].Image, blinkImageItem[i].BitmapOn, blinkImageItem[i].BitmapOff);
			}
		}
	}
}

void RefreshJobImages(){
	// If It's gonna be display jobs parameters...
	int i = 0;

	// Update image bitmaps according to corresponding bit.
	for(i = 0; i < nJobImageItems; i++){
		int idx = jobImageItems[i].Idx;
		uint32_t rawValue = (*pReadJobData)(idx);

		/* If FLAG == 255 it means images has never been refreshed */
		if(rawValue != jobImageItems[i].Value || jobImageItems[i].Flag == 255){
			uint8_t bit = (rawValue >> jobImageItems[i].Bit ) & 0x01;

			if(jobImageItems[i].Image){
				jobImageItems[i].Image->setBitmap(bit > 0 ?
						touchgfx::Bitmap(jobImageItems[i].BitmapOn) : touchgfx::Bitmap(jobImageItems[i].BitmapOff));
				jobImageItems[i].Image->invalidate();
				jobImageItems[i].Value = rawValue;
				jobImageItems[i].Flag = 0;
			}
		}
	}
}

void RefreshJobValues(){
	// Updating job's parameters numerical values.

	int i;
	for(i = 0; i < nJobItems; i++){
		int idx = jobItems[i].Idx;
		uint32_t rawValue = 0;

		if(jobItems[i].TextArea == NULL)
			continue;

		if(jobItems[i].Type != _STRING_){

			/* Check if current job item is job index */
			bool isIndxValue = jobItems[i].Idx == 0xff;
			if(pReadJobData && pGetSelectedJob)
				rawValue = isIndxValue ? (*pGetSelectedJob)() + 1 : (*pReadJobData)(idx);

			if(pFromFloatingPointToDecimalSinglePrecision == NULL)
				continue;

			uint32_t val2Disp = (jobItems[i].Type == _FP_32BIT_ || isIndxValue) ? rawValue :
					((uint32_t)(*pFromFloatingPointToDecimalSinglePrecision)((double)rawValue));

			/* Check if saved data and displayed one are different */
			if(rawValue != jobItems[i].Value)
			{
				/* Refresh displayed job data */
				RefreshData(jobItems[i].TextArea, jobItems[i].Buffer, 0, val2Disp, isIndxValue ? _INT_ : jobItems[i].Type, jobItems[i].Decimal);
				if (jobItems[i].TextArea != NULL)
					jobItems[i].TextArea->invalidate();
				jobItems[i].Value = rawValue;
			}
		}
		else{

			/* Program name management */
			char name[BUFF_SIZE];

			/* Read current program name */
			if(pReadJobName)
				(*pReadJobName)(name);

			/* Check if saved program name and displayed one are different */
			if(strcmp(jobItems[i].ValueStr, name) != 0)
			{
				/* Refresh displayed program name */
				RefreshString(jobItems[i].TextArea, jobItems[i].Buffer, name);
				strcpy(jobItems[i].ValueStr, name);
			}
		}
	}
}

void ReadJobNameFromRemoteDevice(){
	// If It's gonna be display job's name read from PLC...

	if(nReadJobNameItems > 0){
		void (*pReadRegisters)(uint16_t, uint8_t, uint16_t*);

		pReadRegisters = NULL;
		if(readJobNameItem.ProtocolType == MB_RS485)
			pReadRegisters = pReadRegistersRS485;

		if(readJobNameItem.ProtocolType == MB_TCPIP)
			pReadRegisters = pReadRegistersTCPIP;

		if(readJobNameItem.ProtocolType == MB_TTL)
			pReadRegisters = pReadRegistersTTL;

		if(pReadRegisters){
			int itemsNum = readJobNameItem.Length;
			uint16_t rawName[itemsNum];
			uint8_t  programName[itemsNum * 2];
			(*pReadRegisters)(readJobNameItem.Address, readJobNameItem.Length, rawName);

			int i = 0, j = 0;
			for(i = 0; i < itemsNum; i++){
				programName[j++] = ( rawName[i] >> 0 ) & 0xff;
				programName[j++] = ( rawName[i] >> 8 ) & 0xff;
			}

			RefreshString(readJobNameItem.TextArea, readJobNameItem.Buffer, (char*)programName);
		}
	}
}

void RefreshJobContainers(){
	int i;
	for(i = 0; i < nCntVisibilityItems && pReadJobData; i++){
		if(cntVisibilityItems[i].ProtocolType == PT_JOB &&
				cntVisibilityItems[i].Container){
			uint8_t jData = (uint32_t)((*pReadJobData)(cntVisibilityItems[i].Address) >> cntVisibilityItems[i].Bit) & 0x01;
			if(jData == cntVisibilityItems[i].Condition && !cntVisibilityItems[i].Container->isVisible()){
				cntVisibilityItems[i].Container->setVisible(true);
				cntVisibilityItems[i].Container->invalidate();
			}

			if(jData != cntVisibilityItems[i].Condition && cntVisibilityItems[i].Container->isVisible()){
				cntVisibilityItems[i].Container->setVisible(false);
				cntVisibilityItems[i].Container->invalidate();
			}
		}
	}
}

void RefreshJobItems(){
	/* Refresh images according to some particular bit value between job's data */
	RefreshJobImages();

	/* Refresh job's data values */
	RefreshJobValues();

	/* Refresh containers' visibility according to some particular bit value between job's data */
	RefreshJobContainers();

	/* Read current job name stored in remote device and displaying it */
	ReadJobNameFromRemoteDevice();
}

void UpdateJobItems(){
	int i;

	/* Updating both job's numerical and name parameters */
	for(i = 0; i < nJobItems; i++){
		if(pAddJobDataToUpdate && jobItems[i].Type != _STRING_){
			int len = touchgfx::Unicode::strlen(jobItems[i].Buffer) + 1;
			char chBuff[len];
			touchgfx::Unicode::toUTF8(jobItems[i].Buffer, (uint8_t*)chBuff, len );
			double value = atof(chBuff);
			//double value = (*pFromUnicodeToDouble)(jobItems[i].Buffer);
			(*pAddJobDataToUpdate)(jobItems[i].Idx, value, 1);
		}

		if(pAddJobNameToUpdate && jobItems[i].Type == _STRING_){
			char name[BUFF_SIZE];
			touchgfx::Unicode::toUTF8(jobItems[i].Buffer, (uint8_t*)name, BUFF_SIZE);
			(*pAddJobNameToUpdate)(name);
		}
	}
}

void ClearJobsValue(){
	int i;
	for(i = 0; i < nJobItems; i++){
		jobItems[i].Value = -1;
		//memset(jobItems[i].ValueStr, 0xff, sizeof(char) * BUFF_SIZE);
	}
}

void UpdateItem(uint16_t address, uint32_t value, Protocol protocol){

	/* Updating text areas' displaying data according to read value */
	UpdateTextItem(				address, value, protocol);

	/* Updating images' to be displyed according to read bit value */
	UpdateImageItem(			address, value, protocol);

	/* Updating images' to be displyed according to read word value */
	UpdateImageWordItem( 		address, value, protocol);

	/* Updating text areas' displaying user data according to read value */
	UpdateTextAssocBitItem(		address, value, protocol);

	/* Updating images' to be displayed according to read bit value */
	UpdateToggleItem(			address, value, protocol);

	/* Updating buttons' visibility according to read value */
	UpdateBtnVisibilityItem(	address, value, protocol);

	/* Updating flex buttons' visibility according to read value */
	UpdateFlexBtnVisibilityItem(address, value, protocol);

	/* Updating text areas' visibility according to read value */
	UpdateTxtVisibilityItem(	address, value, protocol);

	/* Updating containers' visibility according to read value */
	UpdateCntVisibilityItem(	address, value, protocol);

	/* Updating images' visibility according to read value */
	UpdateImageVisibilityItem(	address, value, protocol);

	/* Updating buttons' images according to read value */
	UpdateBtnStateImgItem(		address, value, protocol);

	/* Updating alarm items according to read value */
	UpdateAlarmItem(			address, value, protocol);

	/* Updating circular progress items according to read value */
	UpdateCircularProgressItem( address, value, protocol);

	/* Updating sound sequence management */
	UpdateBeepItem(				address, value, protocol);

	/* Refreshing items to be blinked */
	RefreshBlinkingItems(		address, value, protocol);
}

void RefreshRun(){
	/* Updating pressing button delay for RS485 */
	UpdateButtonPressedItems(pAddBitDlyItemRS485, MB_RS485);

	/* Updating pressing button delay for TCPIP */
	UpdateButtonPressedItems(pAddBitDlyItemTCPIP, MB_TCPIP);

	/* Updating pressing button delay for TTL */
	UpdateButtonPressedItems(pAddBitDlyItemTTL, MB_TTL);

	/* Updating pressing button delay for generic usage */
	UpdateButtonPressedItems(NULL, PROTOCOL_NONE);

	/* Refreshing error container visibility for RS485 */
	RefreshModbusCommErrVisibility(pTimeoutCommRS485, MB_RS485);

	/* Refreshing error container visibility for TCPIP */
	RefreshModbusCommErrVisibility(pTimeoutCommTCPIP, MB_TCPIP);

	/* Refreshing error container visibility for TTL */
	RefreshModbusCommErrVisibility(pTimeoutCommTTL, MB_TTL);

	/* Refreshing images according to some particular bit value stored in FRAM memory */
	RefreshImageHDX();

	/* Refreshing button visibility according to some particular bit value stored in FRAM memory */
	RefreshButtonHDXVisibility();

	/* Refreshing container visibility according to some particular bit value stored in FRAM memory */
	RefreshContainerHDXVisibility();

	/* Refreshing RTC variables */
	RefreshRTC();

	/* Refreshing swipe container selected page number locally */
	RefreshSwipeContainers();
}




