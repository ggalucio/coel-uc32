/*
 * converter.cpp
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#include "stdlib.h"
#include "../Inc/converter.hpp"


double FromUnicodeToDouble(touchgfx::Unicode::UnicodeChar* unicode){
	int len = touchgfx::Unicode::strlen(unicode) + 1;

	if(len == 0)
		return 0.0;

	touchgfx::Unicode::UnicodeChar unicCodeChar;
	touchgfx::Unicode::strncpy(&unicCodeChar, unicode, len);

	char chBuff[len];
	touchgfx::Unicode::toUTF8(&unicCodeChar, (uint8_t*)chBuff, len);
	return atof(chBuff);
}
