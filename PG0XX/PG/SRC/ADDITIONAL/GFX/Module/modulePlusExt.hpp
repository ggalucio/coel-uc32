/*
 * modulePlusExt.hpp
 *
 *  Created on: 13 de jun de 2024
 *      Author: COELMATIC2022
 */

#ifndef GFX_MODULE_MODULEPLUSEXT_HPP_
#define GFX_MODULE_MODULEPLUSEXT_HPP_

#include <touchgfx/widgets/TextArea.hpp>

extern "C"{
	#include "../GFX/Module/Inc/enumerators_ext.h"
}

void		(*pAddCounter)(CountingMode countingMode, uint64_t seconds);
void		(*pAddTextAreaCounterItem)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int id);
void		(*pAddDigitalClockCounterItem)(touchgfx::DigitalClock* digitalClock, int id);
void		(*pAddJobButton)(touchgfx::ToggleButton* toggleButton, int idx);
void		(*pUpdateJobItemsOthers)(void);
void		(*pSetControlCounter)(int id, ControlState state);
void		(*pCountersRemoveAll)(void);
void		(*pClearItemsExt)(void);
void		(*pRefreshRunExt)(void);

double		(*pArrayCharToDouble)(char* src);
uint16_t	(*pUnicodeCharToArrayChar)(touchgfx::Unicode::UnicodeChar* buffer, char* dst, uint16_t maxbytes);

#endif /* GFX_MODULE_MODULEPLUSEXT_HPP_ */
