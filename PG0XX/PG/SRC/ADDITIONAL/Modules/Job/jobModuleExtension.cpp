/*
 * jobModuleExtension.cpp
 *
 *  Created on: 30 de jul de 2024
 *      Author: COELMATIC2022
 */

#include "../Modules/Job/jobModuleExtension.hpp"

#include "../Modules/Job/jobModule.h"

void AddJobDataToUpdate(int idx, double value, uint8_t length){
	if (pJobModule)
		pJobModule->AddJobDataToUpdate(idx, value, length);
}

uint32_t ReadJobData(int idx){
	if (pJobModule)
		return pJobModule->ReadJobData(idx);

	return 0;
}
