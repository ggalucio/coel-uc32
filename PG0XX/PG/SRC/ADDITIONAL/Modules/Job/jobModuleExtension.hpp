/*
 * jobModuleExtension.hpp
 *
 *  Created on: 30 de jul de 2024
 *      Author: COELMATIC2022
 */

#ifndef MODULES_JOB_JOBMODULEEXTENSION_HPP_
#define MODULES_JOB_JOBMODULEEXTENSION_HPP_

#include <cstdint>

void AddJobDataToUpdate(int idx, double value, uint8_t length);
uint32_t ReadJobData(int idx);

#endif /* MODULES_JOB_JOBMODULEEXTENSION_HPP_ */
