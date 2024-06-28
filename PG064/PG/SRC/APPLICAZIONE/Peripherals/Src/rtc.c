/*
 * rtc.c
 *
 *  Created on: 8 giu 2021
 *      Author: paoloc
 */


#include "../Inc/rtc.h"
#include "../Utils/utils.h"

#define FLAG_REG RTC_BKP_DR0

RTC_HandleTypeDef hrtc;


uint8_t DetectRtcFlag(void){
	  return HAL_RTCEx_BKUPRead(&hrtc, FLAG_REG);
}

uint8_t IsRtcReady(void){
	return 1;
}

void DeInitRtc(void){
	//HAL_RTC_DeInit(&hrtc);
}

uint8_t InitRtc(void){
	/** Initialize RTC Only
	*/
	hrtc.Instance = RTC;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
	hrtc.Init.AsynchPrediv = 127;
	hrtc.Init.SynchPrediv = 255;
	hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
	hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
	if (HAL_RTC_Init(&hrtc) != HAL_OK)
	{
		return PERIPH_INIT_FAILED;
	}

	return PERIPH_INIT_SUCCESS;
}

void UpdateRtc(){
	RTC_TimeTypeDef sTime = {0};
	RTC_DateTypeDef sDate = {0};

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);

	RTC_HOUR_ADDRESS 	= sTime.Hours;
	RTC_MIN_ADDRESS 	= sTime.Minutes;
	RTC_SEC_ADDRESS 	= sTime.Seconds;
	RTC_DAY_ADDRESS		= sDate.Date;
	RTC_MONTH_ADDRESS	= sDate.Month;
	RTC_YEAR_ADDRESS	= sDate.Year;
}

void SetTime(uint8_t h, uint8_t m, uint8_t s){
	RTC_TimeTypeDef sTime = {0};
	sTime.Hours = h;
	sTime.Minutes = m;
	sTime.Seconds = s;

	HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
}

void SetDate(uint8_t d, uint8_t m, uint8_t y){
	RTC_DateTypeDef sDate = {0};
	sDate.Date = d;
	sDate.Month = m;
	sDate.Year = y;

	HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
}

