/*
 * job.h
 *
 *  Created on: 1 lug 2021
 *      Author: paoloc
 */

#ifndef JOB_JOBMODULE_H_
#define JOB_JOBMODULE_H_

#include "stdint.h"
#include "../Utils/moduleUtil.h"

typedef struct{
	void 	 (*JobName)(char*);
	void 	 (*JobNameAt)(int, char*);
	uint32_t (*ReadJobData)(int);
	uint32_t (*GetSelectedJob)(void);
	void 	 (*SelectJob)(int);
	void 	 (*IncreaseJob)(int,int);
	void 	 (*DecreaseJob)(int,int);
	void	 (*AddJobDataToUpdate)(int, double, uint8_t);
	void	 (*AddJobNameToUpdate)(char*);
	void	 (*UpdateJobsFlag)(void);
	uint8_t	 (*WriteJobData)(uint8_t*, uint32_t, uint32_t, uint32_t);
	void	 (*DeleteJob)(void);
	uint32_t (*ChosenJob)(void);
	void 	 (*ToggleJobData)(int idx, uint8_t bit);
}JobModTypeDef;

JobModTypeDef 	*pJobModule;
ModuleTypDef 	*pJobCycleModule;

void InitJobModule(void);


#endif /* JOB_JOBMODULE_H_ */
