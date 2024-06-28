/*
 * GraphicsModule.c
 *
 *  Created on: 23 set 2021
 *      Author: paoloc
 */


#include "TimeModule.h"
#include "../Peripherals/Inc/wait.h"
#include "../Peripherals/Inc/rtc.h"

uint8_t ReadDay();
uint8_t ReadMonth();
uint8_t ReadYear();
uint8_t ReadHour();
uint8_t ReadMin();
uint8_t ReadSec();
void 	WriteHour(uint8_t);
void 	WriteMin(uint8_t);
void 	WriteSec(uint8_t);
void 	WriteDay(uint8_t);
void 	WriteMonth(uint8_t);
void 	WriteYear(uint8_t);

ModuleTypDef   timeCycleModule = {
		NULL,
		UpdateTime
};

TimeModuleTypDef timeModule = {
		Elapsed,
		ReadHour,
		ReadMin,
		ReadSec,
		ReadDay,
		ReadMonth,
		ReadYear,
		WriteHour,
		WriteMin,
		WriteSec,
		WriteDay,
		WriteMonth,
		WriteYear
};

void InitTimeModule(){
	pTimeCycleModule = &timeCycleModule;
	pTimeModule = &timeModule;
}

uint8_t Elapsed(uint32_t *ms, uint32_t timeout){
	uint8_t isElapsed = ElapsedTick(*ms, timeout);

	if(isElapsed)
		StartNewTick(ms);

	return isElapsed;
}

void UpdateTime(){
	UpdateRtc();
}

uint8_t ReadDay(){
	return RTC_DAY_ADDRESS;
}

uint8_t ReadMonth(){
	return RTC_MONTH_ADDRESS;
}

uint8_t ReadYear(){
	return RTC_YEAR_ADDRESS;
}

uint8_t ReadHour(){
	return RTC_HOUR_ADDRESS;
}

uint8_t ReadMin(){
	return RTC_MIN_ADDRESS;
}

uint8_t ReadSec(){
	return RTC_SEC_ADDRESS;
}

void WriteDay(uint8_t d){
	SetDate(d, RTC_MONTH_ADDRESS, RTC_YEAR_ADDRESS);
}

void WriteMonth(uint8_t m){
	SetDate(RTC_DAY_ADDRESS, m, RTC_YEAR_ADDRESS);
}

void WriteYear(uint8_t y){
	SetDate(RTC_DAY_ADDRESS, RTC_MONTH_ADDRESS, y);
}

void WriteHour(uint8_t h){
	SetTime(h, RTC_MIN_ADDRESS, RTC_SEC_ADDRESS);
}

void WriteMin(uint8_t m){
	SetTime(RTC_HOUR_ADDRESS, m, RTC_SEC_ADDRESS);
}

void WriteSec(uint8_t s){
	SetTime(RTC_HOUR_ADDRESS, RTC_MIN_ADDRESS, s);
}
