/*
 * graphic_ext.cpp
 *
 *  Created on: 13 de jun de 2024
 *      Author: COELMATIC2022
 */

#include "../Inc/graphic_ext.hpp"
#include "../Inc/GraphicItemsExt.hpp"

#include <touchgfx/widgets/TextArea.hpp>

extern "C"{
	#include "../GFX/Module/Inc/enumerators_ext.h"
}

extern void		(*pAddContainer)(touchgfx::Screen* screen);
extern void		(*pAddCounter)(CountingMode countingMode, uint64_t seconds);
extern void		(*pAddTextAreaCounterItem)(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int id);
extern void 	(*pAddDigitalClockCounterItem)(touchgfx::DigitalClock* digitalClock, int id);
extern void		(*pAddJobButton)(touchgfx::ToggleButton* toggleButton, int idx);
extern void		(*pUpdateJobItemsOthers)(void);
extern void		(*pSetControlCounter)(int id, ControlState state);
extern void		(*pCountersRemoveAll)(void);
extern void		(*pClearItemsExt)(void);
extern void		(*pRefreshRunExt)(void);

extern double	(*pArrayCharToDouble)(char* src);
extern uint16_t (*pUnicodeCharToArrayChar)(touchgfx::Unicode::UnicodeChar* buffer, char* dst, uint16_t maxbytes);

void InitGraphicModulePtrExt(){

	pAddContainer				= AddContainer;

	pAddCounter					= AddCounter;
	pAddTextAreaCounterItem		= AddTextAreaCounterItem;
	pAddDigitalClockCounterItem	= AddDigitalClockCounterItem;
	pSetControlCounter			= SetControlCounter;
	pCountersRemoveAll			= CountersRemoveAll;

	pArrayCharToDouble 			= ArrayCharToDouble;
	pUnicodeCharToArrayChar		= UnicodeCharToArrayChar;

	pClearItemsExt				= ClearItemsExt;
	pRefreshRunExt				= RefreshRunExt;

	pAddJobButton				= AddJobItem;
	pUpdateJobItemsOthers		= UpdateJobItemsOthers;
}
