/*
 * langModule.h
 *
 *  Created on: 15 set 2021
 *      Author: paoloc
 */

#ifndef MODULES_LANGUAGE_LANGMODULE_H_
#define MODULES_LANGUAGE_LANGMODULE_H_

#include "../Settings/settings.h"

typedef struct{
	uint8_t	 (*GetLanguage)(void);
	void	 (*SetLanguage)(uint8_t);
}LangModTypeDef;

LangModTypeDef * pLangModule;

void InitLangModule(void);



#endif /* MODULES_LANGUAGE_LANGMODULE_H_ */
