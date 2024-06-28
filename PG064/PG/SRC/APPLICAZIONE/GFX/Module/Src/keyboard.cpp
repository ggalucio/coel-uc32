/*
 * keyboard.cpp
 *
 *  Created on: 9 lug 2021
 *      Author: paoloc
 */

#include "../Inc/keyboard.hpp"
#include "string.h"

#define MAX_SIZE 20

char strValue[MAX_SIZE];
touchgfx::Unicode::UnicodeChar* inputBuffer;
touchgfx::TextArea *inputTextArea;
touchgfx::Unicode::UnicodeChar* refBuff;
touchgfx::TextArea *refTxtArea;
bool upperCase 	= true;
bool numCase 	= false;

void Refresh(){
	if(inputBuffer && inputTextArea){
		touchgfx::Unicode::strncpy(inputBuffer, strValue, MAX_SIZE);
		inputTextArea->invalidate();
	}
}

void AddTxtKeyboardRef(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer){
	memset(strValue, 0, sizeof(char) * MAX_SIZE);
	refTxtArea = textArea;
	refBuff = textBuffer;
	int len =touchgfx::Unicode::strlen(textBuffer);
	touchgfx::Unicode::toUTF8(textBuffer, (uint8_t*)strValue, len);
}

void InitTxtKeyboard(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer){
	inputBuffer = buffer;
	inputTextArea = textArea;
	Refresh();
}

void UpdateTxtKeyboard(){
	touchgfx::Unicode::strncpy(refBuff, inputBuffer, MAX_SIZE);
	refTxtArea->invalidate();
}

char GetValue(const char val){
	char value = val;
	if(!upperCase){
		if(val >= 65 && val <= 90){
			value += (97 - 65);
		}
		else{
			switch(val){
				case '/':
					value = '-';
					break;
				case ':':
					value = '.';
					break;
				case ';':
					value = ',';
					break;
				default:
					break;
			}
		}

	}

	if(numCase){
		switch(val){
			case 'Q': value = '1'; 	break;
			case 'W': value = '2'; 	break;
			case 'E': value = '3'; 	break;
			case 'R': value = '4'; 	break;
			case 'T': value = '5'; 	break;
			case 'Y': value = '6'; 	break;
			case 'U': value = '7'; 	break;
			case 'I': value = '8'; 	break;
			case 'O': value = '9'; 	break;
			case 'P': value = '0'; 	break;
			case '/': value = '@'; 	break;
			case 'A': value = '#'; 	break;
			case 'S': value = '$'; 	break;
			case 'D': value = '%'; 	break;
			case 'F': value = '&'; 	break;
			case 'G': value = '*'; 	break;
			case 'H': value = '_'; 	break;
			case 'J': value = '+'; 	break;
			case 'K': value = '('; 	break;
			case 'L': value = ')'; 	break;
			case ':': value = '!'; 	break;
			case ';': value = '\"'; break;
			case 'Z': value = '\''; break;
			case 'X': value = ':'; 	break;
			case 'C': value = ';'; 	break;
			case 'V': value = '/'; 	break;
			case 'B': value = '?'; 	break;
			case 'N': value = ','; 	break;
			case 'M': value = '.'; 	break;
		}
	}

	return value;
}

void keyboardBtnPressed(char val){
	int len = strlen(strValue);
	if(len < MAX_SIZE){
		char value = GetValue(val);
		strncat(strValue, &value, 1);
		Refresh();
	}
}

void keyboardDltPressed(){
	int len = strlen(strValue);

	if(len > 0){
		strValue[len - 1] = '\0';
		Refresh();
	}
}

void keyboardShfPressed(){
	if(!numCase){
		upperCase = !upperCase;
	}
}

void keyboardNumPressed(){
	numCase = !numCase;
}
