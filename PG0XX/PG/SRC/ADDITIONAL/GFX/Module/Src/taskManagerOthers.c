/*
 * taskManagerOthers.c
 *
 *  Created on: 24 de jun de 2024
 *      Author: COELMATIC2022
 */

#include "../Inc/taskManagerOthers.h"
#include "../APPLICAZIONE/Modules/Buzzer/buzzerModule.h"
#include "cmsis_os.h"

uint32_t	taskBuzzerCount = 0;
uint8_t		oddpair = 0x00;

extern void RefreshTimerCounter(void);
extern void RefreshWriteMemory(void);

void AsyncSoundBuzzerOn(uint32_t ms){
	taskBuzzerCount = ms;
}

void IdleTaskBuzzer(void const * argument){
	while(1){
		osDelay(1);
		if(taskBuzzerCount > 0){
			pBuzzerModule->On();
			--taskBuzzerCount;
		}
		else
			pBuzzerModule->Off();
	}
}

void IdleTaskSRAM(void const * argument){
	while(1){
		osDelay(5);
		RefreshWriteMemory();
	}
}

void IdleTaskTimerCounter(void const * argument){
	while(1){
		osDelay(1000);
		oddpair = (oddpair == 0xff ? 0x00 : 0xff);
		RefreshTimerCounter();
	}
}


void InitTaskExt(){
	// IDLE TASK 1
	osThreadDef(idleTaskBuzzer, IdleTaskBuzzer, osPriorityIdle, 0, 128);
	osThreadCreate(osThread(idleTaskBuzzer), NULL);

	// IDLE TASK 2
	osThreadDef(idleTaskTimerCounter, IdleTaskTimerCounter, osPriorityIdle, 0, 128);
	osThreadCreate(osThread(idleTaskTimerCounter), NULL);

	// IDLE TASK 3
	osThreadDef(idleTaskSRAM, IdleTaskSRAM, osPriorityIdle, 0, 128);
	osThreadCreate(osThread(idleTaskSRAM), NULL);
}
