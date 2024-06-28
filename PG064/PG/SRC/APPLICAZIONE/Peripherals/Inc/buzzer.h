/*
 * buzzer.h
 *
 *  Created on: 30 giu 2021
 *      Author: paoloc
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "Utils/utils.h"

void InitBuzzer(void);
BOOLEAN DeInitBuzzer(void);
void SwitchBuzzerON();
void SwitchBuzzerOFF();
void ToggleBuzzer(void);


#endif /* INC_BUZZER_H_ */
