/*
 * job.c
 *
 *  Created on: 1 lug 2021
 *      Author: paoloc
 */

#include "jobModule.h"

#include "Utils/utils.h"
#include "stdlib.h"
#include "string.h"
#include "../Modules/Math/maths.h"

#define JOB_BASE_ABS_ADDR 	0x90E00000
#define JOB_BASE_REL_ADDR 	0x00E00000
#define JOB_NAME_BYTES		20
#define JOB_SIZE			512
#define BLOCK_SIZE			4096
#define NBYTES_IN_DWORD		4
#define NJOBS_IN_BLOCK		8 //16
#define INVALID_VALUE		0xffffffff
#define INVALID_CHAR		0xff


#define DELETEJOB()														\
				WORD idx = ((jobSelected % NJOBS_IN_BLOCK) * JOB_SIZE);	\
				memset(&pDataCurrBlk[idx], INVALID_CHAR, sizeof(char) * JOB_SIZE);	\

#define PACKNAME(name)																	\
				WORD nameAddr = ((jobSelected % NJOBS_IN_BLOCK) * JOB_SIZE);			\
				memcpy(&pDataCurrBlk[nameAddr], name, sizeof(char) * JOB_NAME_BYTES);	\

#define PACKJOB(val, jidx)																							\
			WORD baseAddr = ((jobSelected % NJOBS_IN_BLOCK) * JOB_SIZE) + JOB_NAME_BYTES + jidx * NBYTES_IN_DWORD;	\
			int i;																									\
			for(i = 0; i < NBYTES_IN_DWORD; i++){																	\
				pDataCurrBlk[baseAddr++] = (val >> (i * 8)) & 0xff;												\
			}																										\

#define LOADCURRENTBLOCK()																		\
			BYTE nBlock = (jobSelected * JOB_SIZE) / BLOCK_SIZE;								\
			DWORD baseAddr = JOB_BASE_ABS_ADDR + nBlock * BLOCK_SIZE;							\
			int i;																				\
			for(i = 0; i < BLOCK_SIZE; i++){													\
				pDataCurrBlk[i] = *(BYTE*)(baseAddr + i);										\
			}																					\

#define JOBNAMECHECKER()									\
			int i;											\
			for(i = 0; i < JOB_NAME_BYTES; i++){			\
				if(name[i] == '0')							\
					name[i] = '\0';							\
				if(name[i] == INVALID_CHAR)					\
					break;									\
			}												\
			if(i != JOB_NAME_BYTES){						\
				memset(&name[0], '-', sizeof(char) * 2);	\
				memset(&name[2], '\0', sizeof(char) * 18);	\
			}												\

void GetJobName(char* jobName);
void GetJobNameAt(int idx, char* jobName);
uint32_t GetJobData(int idx);
uint32_t GetSelectedJob();
uint32_t GetChosenJob();
void SelectJob(int idx);
void IncreaseJob(int min, int max);
void DecreaseJob(int min, int max);
void AddJobDataToUpdate(int idx, double value, uint8_t);
void AddJobNameToUpdate(char* name);
void DeleteJob(void);
void ToggleJobData(int idx, uint8_t bit);

int jobSelected = -1;

JobModTypeDef jobModule = {
		GetJobName,
		GetJobNameAt,
		GetJobData,
		GetSelectedJob,
		SelectJob,
		IncreaseJob,
		DecreaseJob,
		AddJobDataToUpdate,
		AddJobNameToUpdate,
		NULL,
		NULL,
		DeleteJob,
		GetChosenJob,
		ToggleJobData
};

ModuleTypDef  jobCycleModule;
BYTE pDataCurrBlk[BLOCK_SIZE];

void DeleteJob(void){
	DELETEJOB();
}

uint32_t GetJobData(int idx){
	//uint32_t addr = JOB_BASE_ABS_ADDR + jobSelected * JOB_SIZE + JOB_NAME_BYTES + NBYTES_IN_DWORD * idx;
	//uint32_t val = *(uint32_t*)(addr);

	uint32_t val = 0;
	int mod = jobSelected % NJOBS_IN_BLOCK;
	int startAddrBlock = mod * JOB_SIZE;

	int i;
	for(i = 0; i < NBYTES_IN_DWORD; i++)
		val |= (pDataCurrBlk[startAddrBlock + JOB_NAME_BYTES + (idx * NBYTES_IN_DWORD) + i] << ( i * BYTE_BIT_NUM));

	if(INVALID_VALUE == val)
		val = 0;

	return val;
}

void SetJobData(int idx, uint32_t val){
	int i;
	int mod = jobSelected % NJOBS_IN_BLOCK;
	int startAddrBlock = mod * JOB_SIZE;

	for(i = 0; i < NBYTES_IN_DWORD; i++)
		pDataCurrBlk[startAddrBlock + JOB_NAME_BYTES + (idx * NBYTES_IN_DWORD) + i] = (val >> ( i * BYTE_BIT_NUM)) & BYTE_MASK;

}

void ToggleJobData(int idx, uint8_t bit){
	uint32_t val = GetJobData(idx);

	AT_TOGGLE_BIT(val, bit);

	SetJobData(idx, val);
}

void GetJobName(char* jobName){
	char name[JOB_NAME_BYTES];

	int mod = jobSelected % NJOBS_IN_BLOCK;
	int startAddrBlock = mod * JOB_SIZE;
	memcpy(name, &pDataCurrBlk[startAddrBlock], sizeof(char) * JOB_NAME_BYTES);
	JOBNAMECHECKER();

	strcpy(jobName, name);
}

void GetJobNameAt(int idx, char* jobName){
	char name[JOB_NAME_BYTES];
	memcpy(name, (void*)(JOB_BASE_ABS_ADDR + idx * JOB_SIZE), sizeof(char) * JOB_NAME_BYTES);
	JOBNAMECHECKER();
	strcpy(jobName, name);
}

void AddJobNameToUpdate(char* name){
	char nameToUpdate[JOB_NAME_BYTES];
	strcpy(nameToUpdate, name);
	int len = strlen(nameToUpdate);
	memset(&nameToUpdate[len], '\0', sizeof(char) * (JOB_NAME_BYTES - len));

	if(strlen(nameToUpdate) > 0){
		PACKNAME(nameToUpdate);
	}
}

void AddJobDataToUpdate(int idx, double value, uint8_t applyConversion){
	DWORD val = FromDecimalToFloatingPointSinglePrecision((float)value);
	PACKJOB(val, idx);
}

void UpdateJobs(){
	if(jobModule.WriteJobData && jobSelected >= 0){
		BYTE nBlock = (jobSelected * JOB_SIZE) / BLOCK_SIZE;
		DWORD address = JOB_BASE_REL_ADDR + nBlock * BLOCK_SIZE;
		jobModule.WriteJobData(pDataCurrBlk, BLOCK_SIZE, address, 32);
	}
}

void SelectJob(int idx){
	jobSelected = idx;
	LOADCURRENTBLOCK();
}

uint32_t GetSelectedJob(){
	return (uint32_t)jobSelected;
}

void IncreaseJob(int min, int max){

	if(min < 0)
		min = 0;

	int sel = jobSelected + 1;

	if(sel > max)
		sel = min;

	SelectJob(sel);
}

void DecreaseJob(int min, int max){
	if(min < 0)
		min = 0;

	int sel = jobSelected - 1;

	if(sel < min)
		sel = max;

	SelectJob(sel);
}

uint32_t GetChosenJob(){
	return JOB_SELECTED_ADDRESS;
}

void InitJobModule(void){
	pJobModule 						= &jobModule;

	jobCycleModule.Update 			= UpdateJobs;
	pJobCycleModule 				= &jobCycleModule;

	LOADCURRENTBLOCK();
}
