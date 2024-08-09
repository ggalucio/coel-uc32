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

extern void Cycle50(void);
extern void Cycle500(void);
extern void Cycle25(void);
extern void TIMER_1S(void);
extern void TIMER_10S(void);

extern void RefreshTimerCounter(void);

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

void IdleTaskTimerCounter(void const * argument){
	while(1){
		osDelay(1000);
		oddpair = (oddpair == 0xff ? 0x00 : 0xff);
		RefreshTimerCounter();
	}
}

void IdleTaskCycle50(void const * argument){
	while(1){
		osDelay(500);
		Cycle50();
	}
}

void IdleTaskCycle500(void const * argument){
	while(1){
		osDelay(5000);
		Cycle500();
	}
}

void IdleTaskCycle25(void const * argument){
	while(1){
		osDelay(250);
		Cycle25();
	}
}

void IdleTaskTIMER_1S(void const * argument){
	while(1){
		osDelay(1000);
		TIMER_1S();
	}
}

void IdleTaskTIMER_10S(void const * argument){
	while(1){
		osDelay(10000);
		TIMER_10S();
	}
}

void InitTaskExt(){
	// IDLE TASK 1
	osThreadDef(idleTaskBuzzer, IdleTaskBuzzer, osPriorityIdle, 0, 128);
	osThreadCreate(osThread(idleTaskBuzzer), NULL);

	// IDLE TASK 2
	osThreadDef(idleTaskTimerCounter, IdleTaskTimerCounter, osPriorityIdle, 0, 128);
	osThreadCreate(osThread(idleTaskTimerCounter), NULL);

	// IDLE TASK CUSTOM
	osThreadDef(idleTaskCycle50, IdleTaskCycle50, osPriorityIdle, 0, 128);
	osThreadDef(idleTaskCycle500, IdleTaskCycle500, osPriorityIdle, 0, 128);
	osThreadDef(idleTaskCycle25, IdleTaskCycle25, osPriorityIdle, 0, 128);
	osThreadDef(idleTaskTIMER_1S, IdleTaskTIMER_1S, osPriorityIdle, 0, 128);
	osThreadDef(idleTaskTIMER_10S, IdleTaskTIMER_10S, osPriorityIdle, 0, 128);
	osThreadCreate(osThread(idleTaskCycle50), NULL);
	osThreadCreate(osThread(idleTaskCycle500), NULL);
	osThreadCreate(osThread(idleTaskCycle25), NULL);
	osThreadCreate(osThread(idleTaskTIMER_1S), NULL);
	osThreadCreate(osThread(idleTaskTIMER_10S), NULL);
}
