/*
 * buzzerModule.h
 *
 *  Created on: 1 lug 2021
 *      Author: paoloc
 */

#ifndef BUZZERMODULE_H_
#define BUZZERMODULE_H_

typedef struct{
	void (*On)(void);
	void (*Off)(void);
	void (*Toggle)(void);
}BuzzerModTypeDef;

BuzzerModTypeDef * pBuzzerModule;

void InitBuzzerModule(void);

#endif /* BUZZERMODULE_H_ */
