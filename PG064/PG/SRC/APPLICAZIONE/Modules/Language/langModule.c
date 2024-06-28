/*
 * langModule.c
 *
 *  Created on: 15 set 2021
 *      Author: paoloc
 */


#include "langModule.h"

LangModTypeDef langModule;

uint8_t GetLang(void){
	return ReadLanguage();
}

void SetLang(uint8_t lang){
	WriteLanguage(lang);
}

void InitLangModule(){
	langModule.GetLanguage 	= GetLang;
	langModule.SetLanguage 	= SetLang;
	pLangModule				= &langModule;
}
