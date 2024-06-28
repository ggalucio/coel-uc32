/**
  ******************************************************************************
  * @file   fatfs.c
  * @brief  Code for fatfs applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#include "fatfs.h"

uint8_t retSD;    /* Return value for SD */
char SDPath[4];   /* SD logical drive path */
uint8_t retUSBH;    /* Return value for USBH */
char USBHPath[4];   /* USBH logical drive path */
FATFS USBHFatFS;    /* File system object for USBH logical drive */
FATFS SDFatFS = {0};     /* File system object for SD logical drive */
FIL USBHFile;       /* File object for USBH */
FIL SDFile    = {0};     /* File object for SD */

/* USER CODE BEGIN Variables */

/* USER CODE END Variables */

void MX_FATFS_Init(void)
{
  /*## FatFS: Link the SD driver ###########################*/
  retSD = FATFS_LinkDriver(&SD_Driver, SDPath);
  /*## FatFS: Link the USBH driver ###########################*/
  retUSBH = FATFS_LinkDriver(&USBH_Driver, USBHPath);

  /* USER CODE BEGIN Init */
  /* additional user code for init */
  /* USER CODE END Init */
}

/**
  * @brief  Gets Time from RTC
  * @param  None
  * @retval Time in DWORD
  */
DWORD get_fattime(void)
{
  /* USER CODE BEGIN get_fattime */
  return 0;
  /* USER CODE END get_fattime */
}

/* USER CODE BEGIN Application */
FRESULT ReadSD(char* buffer, uint16_t size, char* filename){
	FRESULT res = FR_OK;

	char fullfilename[100];
	sprintf(fullfilename, "%s%s", SDPath, filename);

	res = f_mount(&SDFatFS, (TCHAR const*)SDPath, 0);

	if(res == FR_OK){
		res = f_open(&SDFile, fullfilename, FA_READ);

		if(res == FR_OK){
			/*	Tutto il file
			 * int bytesread;
			res = f_read(&SDFile, buffer, sizeof(char) * 100, (UINT*)&bytesread);*/

			/*	Ultima riga
			int lines = 0;
			for (lines = 0; (f_eof(&SDFile) == 0); lines++)
			{
			   f_gets((char*)buffer, size, &SDFile);
			}*/

			long fsize = f_size(&SDFile);
			f_lseek(&SDFile, fsize);//sets end of data
			long pos = fsize - 2;
			long startPos = pos;
			char chr = 0;
			int bytesread;

			// Loop backword util "\n" is found.
			while((chr != '\n') && (pos > 0)) {
				f_lseek(&SDFile, pos--);
				f_read(&SDFile, (char*)&chr, sizeof(char), (UINT*)&bytesread);
				printf("%c\n", chr);
			}

			int len = startPos - pos;
			char buff[len];

			if(pos <= 0){
				f_rewind(&SDFile);
				res = f_read(&SDFile, buff, sizeof(char) * len, (UINT*)&bytesread);
			}
			else{
				f_gets((char*)buff, sizeof(buff), &SDFile);
			}

			memcpy(buffer, buff, sizeof(char) * len);
			buffer[len] = '\n';
		}
		f_close(&SDFile);
	}

	/* Unregister work area */
	f_mount(0, (TCHAR const*)SDPath, 0);
	return res;
}

FRESULT WriteSD(char* buffer, char* filename){
	FRESULT res = FR_OK;
	char fullfilename[100];
	sprintf(fullfilename, "%s%s", SDPath, filename);

	res = f_mount(&SDFatFS, (TCHAR const*)SDPath, 0);

	if(res == FR_OK){
		res = f_open(&SDFile, fullfilename, FA_OPEN_EXISTING);
		f_close(&SDFile);

		uint8_t mode = FA_READ|FA_WRITE;

		if(res == FR_NO_FILE){
			mode |= FA_CREATE_NEW;
			res = FR_OK;
		}

		if(res == FR_OK){
			res = f_open(&SDFile, fullfilename, mode);
			if(res == FR_OK){
				f_lseek(&SDFile, f_size(&SDFile));//sets end of data
				f_puts(buffer, &SDFile);
			}

			f_close(&SDFile);
		}
	}

	/* Unregister work area */
	f_mount(0, (TCHAR const*)SDPath, 0);

	return res;
}

uint8_t FatFsLinkDrivers(){

	memset(&SDFatFS, 0, sizeof(FATFS));

	uint8_t linkSD = FATFS_LinkDriver(&SD_Driver, SDPath);
	uint8_t linkUSB = FATFS_LinkDriver(&USBH_Driver, USBHPath);
	return linkSD == 0 && linkUSB == 0;
}

uint8_t FatFsUnLinkDrivers(){
	uint8_t unlinkUSB = FATFS_UnLinkDriver(USBHPath);
	uint8_t unlinkSD = FATFS_UnLinkDriver(SDPath);
	return unlinkUSB == 0 && unlinkSD == 0;
}

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
