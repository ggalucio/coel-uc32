/*
 * numericalKeyboard.c
 *
 *  Created on: 27 mag 2021
 *      Author: paoloc
 */

#include "string.h"
#include "stdlib.h"
#include "../Inc/numericalKeyboard.hpp"

#define MAX_SIZE 20

void UpdatePwdNumericalKeyboard();

char numValue[MAX_SIZE];
char numPwdValue[MAX_SIZE];
touchgfx::TextArea *textArea;
touchgfx::TextArea *refTextArea;
touchgfx::TextArea *pwdTextArea;
touchgfx::TextArea *errTextArea;
touchgfx::Unicode::UnicodeChar* textBuffer;
touchgfx::Unicode::UnicodeChar* refBuffer;
touchgfx::Unicode::UnicodeChar* pwdBuffer;
uint16_t textBuffSize;
uint8_t updateData;
uint8_t decData;
uint16_t destAddress;
double minValue;
double maxValue;
DataType type;
RTCType rtcType;

void (*pUpdater)(uint16_t address, double value, uint8_t dataType);

bool firstPress;
uint16_t accessKey = 123;

void RefreshNum(){
	if(textArea != NULL && textBuffer != NULL){
		touchgfx::Unicode::strncpy(textBuffer, numValue, textBuffSize);
		textArea->invalidate();
	}

	UpdatePwdNumericalKeyboard();
}

void ClearData(){
	memset(numValue, '\0', sizeof(char) * MAX_SIZE);
	memset(numPwdValue, '\0', sizeof(char) * MAX_SIZE);
}

void ClearAll(){
	ClearData();
	RefreshNum();
}

void AddChar(char value){

	if(firstPress)
		ClearData();

	int len = strlen(numValue);
	if(len == 1){
		if(numValue[0] == '0' && value != '.'){
			RemoveNumericalKeyboard();
			len--;
		}
	}

	if(len < textBuffSize - 1){
		strncat(numValue, &value, 1);
		RefreshNum();
	}

	firstPress = false;
}

void ChangeSign(){
	int len = strlen(numValue);
	if(len > 0){
		char tmpNumVal[len];
		memcpy(tmpNumVal, numValue, sizeof(char) * len);
		ClearData();

		if(tmpNumVal[0] != '-'){
			numValue[0] = '-';
			memcpy(&numValue[1], tmpNumVal, sizeof(char) * len);
		}
		else{
			memcpy(numValue, &tmpNumVal[1], sizeof(char) * (len - 1));
		}

		RefreshNum();
	}
}

void InitNumericalKeyboard(touchgfx::TextArea *text, touchgfx::Unicode::UnicodeChar* buffer, uint16_t buffSize, touchgfx::TextArea *errTxt){

	textArea = text;
	textBuffer = buffer;
	textBuffSize = buffSize;
	errTextArea = errTxt;

	if(refBuffer != NULL && textArea != NULL && textBuffer != NULL){
		int len = touchgfx::Unicode::strlen(refBuffer);
		touchgfx::Unicode::toUTF8(refBuffer, (uint8_t*)numValue, len);
		touchgfx::Unicode::strncpy(textBuffer, refBuffer, textBuffSize);
		textArea->invalidate();
		numValue[len] = '\0';
	}

	pwdTextArea = NULL;
	pwdBuffer = NULL;
	firstPress = true;
}

void AddRTCNumericalKeyboardReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, RTCType rtc, uint8_t update){
	ClearData();
	refTextArea = textArea;
	refBuffer = textBuffer;
	minValue = min;
	maxValue = max;
	rtcType = rtc;
	updateData = update;
	decData = -1;
	type = _INT2_;
}

void AddNumericalKeyboardReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t update, void (*pUpdateModbus)(uint16_t address, double value, uint8_t dataType), uint16_t address)
{
	ClearData();
	refTextArea = textArea;
	refBuffer = textBuffer;
	minValue = min;
	maxValue = max;
	type = dataType;
	decData = decimal;
	updateData = update;
	pUpdater = pUpdateModbus;
	destAddress = address;
	rtcType = RTC_NONE;
}

void UpdatePwdNumericalKeyboard(){
	if(pwdTextArea != NULL && pwdBuffer != NULL){
		int len = strlen(numValue);
		memset(numPwdValue, 0,	 sizeof(char) * MAX_SIZE);
		memset(numPwdValue, '*', sizeof(char) * len);
		touchgfx::Unicode::strncpy(pwdBuffer, numPwdValue, 10);
		pwdTextArea->invalidate();
	}
}

void InitPasswordNumKeyboard(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer)
{
	ClearData();
	pwdTextArea = textArea;
	pwdBuffer = textBuffer;
}

void AddNumericalKeyboard(char value)
{
	// Un messaggio di errore è visualizzato!
	// Rimuovo il messaggio non appena l'utente inserisce un valore.
	if(errTextArea)
	{	if(errTextArea->isVisible())
		{
			ClearData();
			errTextArea->setVisible(false);
		}
	}
	// Se la condizione è vera, sto inserendo una password e quindi visualizzo
	// la textbox della password con l'asterisco corrispondente.
	// Altrimenti, visualizzo la textbox del valore numerico.
	if(pwdTextArea)
		pwdTextArea->setVisible(true);
	else
		textArea->setVisible(true);

	switch(value){
		case '<':
			ClearAll();
			break;
		case '+':
			ChangeSign();
			break;
		default:
			AddChar(value);
			break;
	}

	UpdatePwdNumericalKeyboard();
}


void RemoveNumericalKeyboard()
{
	int len = strlen(numValue);
	if(len > 0 && textArea != NULL && textBuffer != NULL){
		numValue[len - 1] = '\0';
		touchgfx::Unicode::strncpy(textBuffer, numValue, textBuffSize);
		textArea->invalidate();
	}

	UpdatePwdNumericalKeyboard();
}

double GetNumericalKeyboardValue(touchgfx::TextArea **area, touchgfx::Unicode::UnicodeChar** buff, DataType* dataType, uint8_t *decimal, uint8_t *update, void (**pUpdateModbus)(uint16_t address, double value, uint8_t dataType), uint16_t* address){

	*buff = refBuffer;
	*area = refTextArea;
	*dataType = type;
	*update = updateData;
	*decimal = decData;
	*pUpdateModbus = *pUpdater;
	*address = destAddress;

	int len = touchgfx::Unicode::strlen(textBuffer);
	if(len == 0){
		char zero = '0';
		touchgfx::Unicode::strncpy(textBuffer, (const char*)&zero, 1);
		touchgfx::Unicode::toUTF8(textBuffer, (uint8_t*)numValue, 1);
	}

	return atof(numValue);
}

uint8_t CredentialSuccess(){
	uint16_t pwd = atoi(numValue);
	return pwd == accessKey ? 1 : 0;
}

void GetRangeValues(double* min, double *max, DataType* dataType,  RTCType* rtc, uint8_t* decimal){
	*min = minValue;
	*max = maxValue;
	*dataType = type;
	*rtc = rtcType;
	*decimal = decData;
}

void SetAccessKey(uint16_t key){
	accessKey = key;
}
