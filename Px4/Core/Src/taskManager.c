/*
 * taskManager.c
 *
 *  Created on: 8 giu 2021
 *      Author: paoloc
 */

#include "taskManager.h"
#include "app_touchgfx.h"
#include "cmsis_os.h"
#include "lwip.h"
#include "Modules/Manager/moduleManager.h"

#include "Module/Inc/taskManagerOthers.h"

void WriteJobEnable(void);

osThreadId touchDriverTaskHandle;
osThreadId modbusServerTaskHandle;
osThreadId modbusClientTaskHandle;
osThreadId jobTaskHandle;
osThreadId idleTaskHandle;
extern osThreadId touchGFXTaskHandle;

osSemaphoreId semJobHandle;
QueueHandle_t clientQueue;

void SuspendTouchGFXTask(){
	vTaskSuspend(touchGFXTaskHandle);
	osDelay(50);
}

void ResumeTouchGFXTask(){
	vTaskResume(touchGFXTaskHandle);
	osDelay(50);
}

void ModbusClientTask(void const * argument){

	while(1){
		int received = 0;
		if (xQueueReceive(clientQueue, &received, portMAX_DELAY) == pdTRUE) break;
	}

	vQueueDelete(clientQueue);

	osDelay(2000);

	if(DoesModbusClientTaskNeedToRun()){
		while(1){
			osDelay(1);
			if(pModbusClientCycle){
				if(pModbusClientCycle->Update)
					pModbusClientCycle->Update();
				if(pModbusClientCycle->Run)
					pModbusClientCycle->Run();
			}
		}
	}

	vTaskDelete(modbusClientTaskHandle);
}

void ModbusServerTask(void const * argument){

	MX_LWIP_Init();

	int startClient = 1;
	xQueueSend(clientQueue, &startClient, portMAX_DELAY);

	if(DoesModbusServerTaskNeedToRun()){
		while(1){
			osDelay(1);
			if(pModbusServerCycle){
				if(pModbusServerCycle->Update)
					pModbusServerCycle->Update();
				if(pModbusServerCycle->Run)
					pModbusServerCycle->Run();
			}
		}
	}

	vTaskDelete(modbusServerTaskHandle);
}

void TouchDriverTask(void const * argument){
	while(1){
		if(pTsCycle){
			if(pTsCycle->Run){
				osDelay(25);
				pTsCycle->Run();
			}
		}
	}
}

void JobTask(void const * argument){
	while(1){
		if(semJobHandle != NULL){
			if(xSemaphoreTake(semJobHandle, (TickType_t)10) == pdTRUE){
				if(pJobCycle){
					if(pJobCycle->Update){
						SuspendTouchGFXTask();
						pJobCycle->Update();
						ResumeTouchGFXTask();
					}
				}
			}
		}
	}
}

void IdleTask(void const * argument){
	while(1){
		osDelay(200);

		// Time
		if(pTimeCycle){
			if(pTimeCycle->Update)
				pTimeCycle->Update();
		}
	}
}


void InitTasks(){
	InitModules();
	SetJobCallback(WriteJobEnable);

	MX_TouchGFX_Init();

	// IDLE TASK
	osThreadDef(idleTask, IdleTask, osPriorityIdle, 0, 128);
	idleTaskHandle = osThreadCreate(osThread(idleTask), NULL);

	InitTaskExt();

	// TASK MODBUS CLIENT
	osThreadDef(modbusClientTask, ModbusClientTask, osPriorityNormal, 0, 1024);
	modbusClientTaskHandle = osThreadCreate(osThread(modbusClientTask), NULL);

	// TASK MODBUS SERVER
	osThreadDef(modbusServerTask, ModbusServerTask, osPriorityNormal, 0, 4096);
	modbusServerTaskHandle = osThreadCreate(osThread(modbusServerTask), NULL);

	// TASK TOUCH DRIVER
	osThreadDef(touchDriverTask, TouchDriverTask, osPriorityNormal, 0, 1024);
	touchDriverTaskHandle = osThreadCreate(osThread(touchDriverTask), NULL);

	// TASK JOB
	osThreadDef(jobTask, JobTask, osPriorityIdle, 0, 256);
	jobTaskHandle = osThreadCreate(osThread(jobTask), NULL);

	// SEMAPHORE JOB
	osSemaphoreDef(semJobs);
	semJobHandle = osSemaphoreCreate(osSemaphore(semJobs), 1);

	// QUEUE CLIENT
	clientQueue = xQueueCreate(1, sizeof (int));
}

void WriteJobEnable(){
	if(semJobHandle != NULL){
		xSemaphoreGive(semJobHandle);
	}
}
