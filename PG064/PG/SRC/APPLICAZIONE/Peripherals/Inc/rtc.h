/*
 * rtc.h
 *
 *  Created on: 8 giu 2021
 *      Author: paoloc
 */

#ifndef INC_RTC_H_
#define INC_RTC_H_

#include "peripheral.h"

uint8_t InitRtc(void);
void DeInitRtc(void);
uint8_t DetectRtcFlag(void);
uint8_t IsRtcReady(void);
void UpdateRtc(void);
void SetDate(uint8_t d, uint8_t m, uint8_t y);
void SetTime(uint8_t h, uint8_t m, uint8_t s);

#endif /* INC_RTC_H_ */
