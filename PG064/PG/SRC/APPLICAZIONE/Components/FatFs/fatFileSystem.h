/*
 * fatfs.h
 *
 *  Created on: Dec 1, 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_FATFS_FATFILESYSTEM_H_
#define COMPONENTS_FATFS_FATFILESYSTEM_H_

#define FATFS_BUFF_SIZE			64
#define FATFS_FILENAME_SIZE		16

#include "Utils/utils.h"

typedef struct{
	FATFS_STATUS State;
	char TxBuffer[FATFS_BUFF_SIZE];
	char RxBuffer[FATFS_BUFF_SIZE];
	char FileName[FATFS_FILENAME_SIZE];
}FatFsDrvTypeDef;

FatFsDrvTypeDef uSD_Drv;

void FatFsRun(void);

#endif /* COMPONENTS_FATFS_FATFILESYSTEM_H_ */
