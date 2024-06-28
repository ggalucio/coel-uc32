/*
 * ts.c
 *
 *  Created on: 9 giu 2021
 *      Author: paoloc
 */

/************ INCLUDES ************/
#include <stddef.h>
#include "ts.h"
#include "gt911/gt911.h"
#include "hycon/hycon.h"
#include "Resistive/resistiveTs.h"
#include "../Modules/Display/displayModule.h"
#include "../Peripherals/Inc/touch.h"
#include "../Peripherals/Inc/capacitive.h"
#include "../Peripherals/Inc/resistive.h"
#include "../Peripherals/Inc/buzzer.h"

/**
* Touch screen driver structure for device and peripherals.
*/
typedef struct{
	TS_DrvTypeDef *drv;
	TS_DrvPeriphTypeDef* periph_drv;
}TS_TypeDef;

/**
* Touch Screen driver
*/
TS_DrvTypeDef *ts_drv;

/**
* Touch Screen peripheral driver
*/
TS_DrvPeriphTypeDef* ts_periph_drv;

/**
 *  Capacitive touch screen driver structure initialization
 */
TS_DrvPeriphTypeDef capacitive_ts_periphDrv = {
		TS_IO_Init,
		TS_IO_DeviceReady,
		TS_IO_Write,
		TS_IO_Read,
		TS_IO_Read_Multiple,
		TS_IO_Delay,
		TS_Error,
		TS_IO_Status
};

/**
 *  Resistive touch screen driver structure initialization
 */
TS_DrvPeriphTypeDef resistive_ts_periphDrv = {
		Resistive_TS_IO_Init,
		Resistive_TS_IO_DeviceReady,
		Resistive_TS_IO_Write,
		Resistive_TS_IO_Read,
		Resistive_TS_IO_Read_Multiple,
		TS_IO_Delay,
		Resistive_Error,
		NULL
};

/**
 * Touch screens device drivers and peripherals driver
 */
TS_TypeDef tsTypes[] = {
		{&gt911_ts_drv, 	&capacitive_ts_periphDrv},
		{&hycon_ts_drv, 	&capacitive_ts_periphDrv},
		{&resistive_ts_drv, &resistive_ts_periphDrv}
};

/**
 * Touch screens machine state enumerators
 */
typedef enum{
	TS_IDLE,
	TS_INIT_PERIPH,
	TS_INIT,
	TS_READID,
	TS_START,
	TS_DETECT_TOUCH,
	TS_CONTACT,
	TS_ENTER_RST_MODE,
	TS_EXIT_RST_MODE,
	TS_ENTER_RST_TOUCH_DRV_MODE,
	TS_EXIT_RST_TOUCH_DRV_MODE
}TS_State;

/**
 * Touch screens machine state
 */
TS_State ts_state;

/**
 * Touch screens index
 */
uint8_t tsTypeIdx = 0;

/**
* @brief Touch Screen reset
* This function resets touch screen driver and display
* @params rst: 1 starts reset, 0 stops reet
*/
void TsReset(uint8_t rst){
	if(pDisplayModule->SwitchReset)
		pDisplayModule->SwitchReset(rst);
}

/**
* @brief Touch Screen reset
* This function switches display on or off.
* @params on: 1 switches display on, 0 switches display off
*/
void TsDisplay(uint8_t on){
	if(pDisplayModule->SwitchScreen)
		pDisplayModule->SwitchScreen(on);
}

/**
* @brief Touch Screen reset
* This function exits from reset mode without switching display status.
*/
void TSEnterTsDrvMode(){
	if(ts_periph_drv->Error)
		ts_periph_drv->Error();

	TsReset(SWITCH_OFF);
	ts_state = TS_EXIT_RST_TOUCH_DRV_MODE;
}

/**
* @brief Touch Screen reset
* This function enters in reset mode without switching display status.
*/
void TSExitTsDrvMode(){
	TsReset(SWITCH_ON);
	ts_state = TS_DETECT_TOUCH;
}

/**
* @brief Touch Screen detector
* This function retrieves capacitive TS peripheral status.
* If an error is detected, enters in reset mode.
*/
void TsReadPerStatus(){
	if(ts_periph_drv){
		if(ts_periph_drv->GetStatus){
			if(!ts_periph_drv->GetStatus()){
				//SwitchBuzzerON();
				//ts_periph_drv->Delay(50);
				//SwitchBuzzerOFF();
				ts_state = TS_ENTER_RST_TOUCH_DRV_MODE;
			}
		}
	}
}

/**
* @brief Touch Screen detector
* This function is called when a touch has been detected and retrieves its coordinates.
*/
void TsContact(){
	RefreshPressedTime();
	ts_Detector.nTouch = ts_drv->DetectTouch(&ts_Detector.Coord.X, &ts_Detector.Coord.Y);
	if( ts_Detector.nTouch == 0 ){
		ts_state = TS_DETECT_TOUCH;
	}

	TsReadPerStatus();
}

/**
* @brief Touch Screen detector
* This function is in polling mode listening to user's screen touches.
*/
void TsDetectTouch(){
	ResetPressedTime();
	ts_Detector.nTouch = ts_drv->DetectTouch(&ts_Detector.Coord.X, &ts_Detector.Coord.Y);
	if(ts_Detector.nTouch > 0)
	{
		StartPressedTime();
		ts_state = TS_CONTACT;
	}

	TsReadPerStatus();
}

/**
* @brief Touch Screen reset mode
* This function enters in reset state and switches display off.
*/
void TSEnterRstModeState(){
	if(ts_periph_drv->Error)
		ts_periph_drv->Error();

	TsDisplay(SWITCH_OFF);
	TsReset(SWITCH_OFF);
	ts_state = TS_EXIT_RST_MODE;
}

/**
* @brief Touch Screen reset mode
* This function exits from reset state and switches display on.
*/
void TSExitRstModeState(){
	TsReset(SWITCH_ON);
	TsDisplay(SWITCH_ON);
	ts_state = TS_INIT_PERIPH;
}

/**
* @brief Touch Screen starter
* This function initializes detected TS driver peripherals.
*/
void TsInitPeriphs(){
	if(ts_drv->SetTsPeriphDrv)
		ts_drv->SetTsPeriphDrv(ts_periph_drv);

	ts_state = TS_INIT;
}

/**
* @brief Touch Screen starter
* This function sets new current TS driver to search.
*/
void TsIdle(){
	ts_drv = NULL;
	ts_drv 			= tsTypes[tsTypeIdx % sizeof(tsTypes)].drv;
	ts_periph_drv 	= tsTypes[tsTypeIdx % sizeof(tsTypes)].periph_drv;
	ts_state = ts_drv == NULL || pDisplayModule == NULL ? TS_IDLE : TS_ENTER_RST_MODE;
	tsTypeIdx++;
}

/**
* @brief Touch Screen starter
* This function initializes detected TS driver sending some parameters.
*/
void TsStart(){
	ts_drv->Start();
	ts_state = TS_DETECT_TOUCH;
}

/**
* @brief Touch Screen Id reader
* This function reads touch screen ID.
*/
void TsReadId(){
	uint8_t readId = ts_drv->ReadID();
	ts_state = readId ? TS_START : TS_IDLE;
}

/**
* @brief Touch Screen initializer
* This function makes the touch screen driver initialization
*/
void TsInit(){
	ts_state = ts_drv->Init() ? TS_READID : TS_IDLE;
}

/**
* @brief Touch Screen cycle machine state entry point.
* This function is the entry point for touch screen management.
*/
void TouchScreenRun(){
	switch(ts_state){
		case TS_IDLE:						TsIdle();				break;
		case TS_INIT_PERIPH:				TsInitPeriphs();		break;
		case TS_INIT:						TsInit();				break;
		case TS_READID:						TsReadId();  			break;
		case TS_START:						TsStart();				break;
		case TS_DETECT_TOUCH:				TsDetectTouch();		break;
		case TS_CONTACT:					TsContact();			break;
		case TS_ENTER_RST_MODE:				TSEnterRstModeState();	break;
		case TS_EXIT_RST_MODE:				TSExitRstModeState();	break;
		case TS_ENTER_RST_TOUCH_DRV_MODE:	TSEnterTsDrvMode();     break;
		case TS_EXIT_RST_TOUCH_DRV_MODE:	TSExitTsDrvMode();      break;
		default:							ts_state = TS_IDLE;		break;
	}
}


