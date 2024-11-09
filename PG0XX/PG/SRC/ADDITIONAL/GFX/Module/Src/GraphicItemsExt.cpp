/*
 * GraphicItemsExt.cpp
 *
 *  Created on: 7 de jun de 2024
 *      Author: COELMATIC2022
 */

#include "../Inc/GraphicItemsExt.hpp"
#include "../Modules/Job/jobModuleExtension.hpp"
#include <stdlib.h>

bool stateBlink = false;
bool blockWriting = false;

int nCounterItems = 0;
int nObjectCounterItems = 0;
int nJobOtherItems = 0;

CounterItem			counterItem[20];
ObjectCounterItem	objectCounterItem[10];
JobOtherItem		jobOtherItem[10];

void ClearItemsExt(){
	nObjectCounterItems = 0;
	nJobOtherItems = 0;
}

double ArrayCharToDouble(char* src){
	char* endptr;
	double value = strtod(src, &endptr);
	if (src == endptr)
		return 0.0;
	else
		return value;
	return 0.0;
}


uint16_t UnicodeCharToArrayChar(touchgfx::Unicode::UnicodeChar* buffer, char* dst, uint16_t maxbytes){
	if((buffer == NULL) || (maxbytes == 0))
		return 0;

	uint16_t nbytes = 0;
	//uint8_t* utf8 = new uint8_t[maxbytes];
	uint8_t utf8[maxbytes];

	touchgfx::Unicode::toUTF8(buffer, utf8, maxbytes);

	bool null = false;
	for(int index=0; index < maxbytes; ++index){
		if(!null){
			if(utf8[index] != 0){
				dst[index] = (char)utf8[index];
				nbytes ++;
			}
			else
				null = true;
		}
		else
			dst[index] = '\0';
	}

	//delete utf8;

	return nbytes;
}

uint8_t StateBlink(){
	return stateBlink ? 0xff : 0x00;
}

bool IncreaseCounting(CounterItem* item){
	if (item->seconds == item->ref)
		return true;

	item->seconds ++;
	return false;
}
bool DecreaseCounting(CounterItem* item){
	if (item->seconds == 0)
		return true;

	item->seconds --;
	return false;
}
bool IncreaseDecreaseCounting(CounterItem* item){
	if (item->mode == INCREASE)
		return IncreaseCounting(item);
	else
		return DecreaseCounting(item);
}
void StopCounter(CounterItem* item){
	item->state = _STOP_;
	if (item->mode == INCREASE)
		item->seconds = 0;
	else
		item->seconds = item->ref;
}
void RefreshDigitalClock(touchgfx::DigitalClock* digitalClock, uint64_t seconds){
	uint8_t hour = (uint8_t)(seconds/3600);
	uint8_t minute = (uint8_t)((seconds - 3600*(uint64_t)hour)/60);
	uint8_t second = (uint8_t)(seconds - 3600*(uint64_t)hour - 60*(uint64_t)minute);
	digitalClock->setTime24Hour(hour, minute, second);
	digitalClock->invalidate();
}

void RefreshCounting(){
	if (nCounterItems == 0)
		return;

	int i;
	for (i=0; i<nCounterItems; i++){
		if (counterItem[i].state == _START_){
			if (IncreaseDecreaseCounting(&counterItem[i]))
				counterItem[i].state = _STOP_;
		}
		else if (counterItem[i].state == _STOP_)
			StopCounter(&counterItem[i]);
	}
}
void RefreshTextAreaCounting(){
	if (nObjectCounterItems == 0)
		return;

	int i;
	for (i=0; i<nObjectCounterItems; i++){
		int value = counterItem[objectCounterItem[i].Id].seconds;

		if (objectCounterItem[i].Buffer != NULL)
			touchgfx::Unicode::snprintf(objectCounterItem[i].Buffer, 20, "%d", value);

		if (objectCounterItem[i].TextArea != NULL)
			objectCounterItem[i].TextArea->invalidate();

		if (objectCounterItem[i].DigitalClock != NULL)
			RefreshDigitalClock(objectCounterItem[i].DigitalClock, value);
	}
}


void AddCounter(CountingMode countingMode, uint64_t seconds){
	if (nCounterItems == 20)
		return;

	counterItem[nCounterItems].seconds = (countingMode == INCREASE ? 0 : seconds);
	counterItem[nCounterItems].ref = seconds;
	counterItem[nCounterItems].mode = countingMode;
	counterItem[nCounterItems].state = _STOP_;
	nCounterItems ++;
}

void AddTextAreaCounterItem(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, int id){
	if (nObjectCounterItems == 10 || id < 0 || id >= nCounterItems || textArea == NULL || buffer == NULL)
		return;

	objectCounterItem[nObjectCounterItems].TextArea = textArea;
	objectCounterItem[nObjectCounterItems].Buffer = buffer;
	objectCounterItem[nObjectCounterItems].DigitalClock = NULL;
	objectCounterItem[nObjectCounterItems].Id = id;
	nObjectCounterItems ++;
}

void AddDigitalClockCounterItem(touchgfx::DigitalClock* digitalClock, int id){
	if (nObjectCounterItems == 10 || id < 0 || id >= nCounterItems || digitalClock == NULL)
		return;

	objectCounterItem[nObjectCounterItems].TextArea = NULL;
	objectCounterItem[nObjectCounterItems].Buffer = NULL;
	objectCounterItem[nObjectCounterItems].DigitalClock = digitalClock;
	objectCounterItem[nObjectCounterItems].Id = id;
	nObjectCounterItems ++;
}

void AddJobItem(touchgfx::ToggleButton *toggleButton, int idx){
	if (toggleButton == NULL || nJobOtherItems == 10)
		return;

	toggleButton->forceState(ReadJobData(idx) != 0 ? true : false);
	toggleButton->invalidate();

	jobOtherItem[nJobOtherItems].ToggleButton = toggleButton;
	jobOtherItem[nJobOtherItems].Idx = idx;
	nJobOtherItems ++;
}

void SetControlCounter(int id, ControlState state){
	if (nCounterItems == 0)
		return;

	if (id >= 0 && id < nCounterItems){
		if (counterItem[id].state != state){
			counterItem[id].state = state;
			//if (counterItem[id].state == _STOP_)
			//	StopCounter(&counterItem[id]);
		}
	}
}

void UpdateJobItemsOthers(){
	if (nJobOtherItems == 0)
		return;

	int i;
	for (i=0; i<nJobOtherItems; i++){
		int idx = jobOtherItem[i].Idx;
		uint8_t state = jobOtherItem[i].ToggleButton->getState() ? 0xFF : 0x00;
		AddJobDataToUpdate(idx, state, 1);
	}
}

void CountersRemoveAll(){
	nCounterItems = 0;
}

void RefreshTimerCounter(){
	RefreshCounting();
	stateBlink = !stateBlink;
}


void RefreshRunExt(){
	/* Refreshing TextArea Counting */
	RefreshTextAreaCounting();
}

