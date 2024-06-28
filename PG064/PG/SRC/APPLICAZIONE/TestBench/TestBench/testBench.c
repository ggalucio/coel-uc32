/*
 * testBench.c
 *
 *  Created on: 5 nov 2021
 *      Author: paoloc
 */

#include "testBench.h"
#include "Utils/modbusUtils.h"
#include "cmsis_os.h"
#include "string.h"
#include <stdio.h>
#include "../Modules/Settings/settings.h"
#include "../Modules/Brightness/brightnessModule.h"
#include "../Modules/Buzzer/buzzerModule.h"
#include "../Modules/FatFs/fatFsModule.h"

// REGISTER ADDRESS
#define TESTBENCH_COMMANDS_R_ADDR	100
#define TESTBENCH_COMMANDS_S_ADDR	101
#define TESTBENCH_RTC_HOUR_ADDR		102
#define TESTBENCH_RTC_MIN_ADDR		103
#define TESTBENCH_RTC_SEC_ADDR		104
#define TESTBENCH_RTC_DAY_ADDR		105
#define TESTBENCH_RTC_MONTH_ADDR	106
#define TESTBENCH_RTC_YEAR_ADDR		107
#define TESTBENCH_BR_REMOTE_ADDR	108
#define TESTBENCH_BR_LOCAL_ADDR		109
#define TESTBENCH_BUZZER_ADDR		110
#define TESTBENCH_TS_ADDR			111
#define TESTBENCH_SD_ADDR			112


// COMMANDS
#define TESTBENCH_NONE_CMD			0
#define TESTBENCH_RTC_READ_CMD		1
#define TESTBENCH_RTC_WRITE_CMD		2
#define TESTBENCH_AUTO_FRAM_CMD		3
#define TESTBENCH_PWM_BRIGHT_CMD	4
#define TESTBENCH_BUZZER_CMD		5
#define TESTBENCH_RST_TS_CMD		6
#define TESTBENCH_SD_CMD			7

#define TESTBENCH_STATUS_BIT		0
#define TESTBENCH_FAILED_BIT		1
#define TESTBENCH_PASS_BIT			2
#define TESTBENCH_BZ_REMOTE_BIT		0
#define TESTBENCH_BZ_LOCAL_BIT		1

void ResetCommandRegister(){
	STOREMODBUS(TESTBENCH_COMMANDS_R_ADDR, MODBUS_RS485_REG_ADDR, 0, 1);
}

WORD ReadModbusRegistersForTestBench(DWORD address, DWORD offset){
	WORD value = 0;
	READMODBUS(address, offset, 1);
	return value;
}

void SetCommStatusBit(){
	WORD commReg =  ReadModbusRegistersForTestBench(TESTBENCH_COMMANDS_S_ADDR, MODBUS_RS485_REG_ADDR);
	AT_SET_BIT(commReg, TESTBENCH_STATUS_BIT);
	STOREMODBUS(TESTBENCH_COMMANDS_S_ADDR, MODBUS_RS485_REG_ADDR, commReg, 1);
}

void SetFailedStatusBit(){
	WORD commReg =  ReadModbusRegistersForTestBench(TESTBENCH_COMMANDS_S_ADDR, MODBUS_RS485_REG_ADDR);
	AT_SET_BIT(commReg, TESTBENCH_FAILED_BIT);
	STOREMODBUS(TESTBENCH_COMMANDS_S_ADDR, MODBUS_RS485_REG_ADDR, commReg, 1);
}

void SetPassedStatusBit(){
	WORD commReg =  ReadModbusRegistersForTestBench(TESTBENCH_COMMANDS_S_ADDR, MODBUS_RS485_REG_ADDR);
	AT_SET_BIT(commReg, TESTBENCH_PASS_BIT);
	STOREMODBUS(TESTBENCH_COMMANDS_S_ADDR, MODBUS_RS485_REG_ADDR, commReg, 1);
}

void ReadRTCForTestBench(){
	SetCommStatusBit();
	if(pTimeModule){
		STOREMODBUS(TESTBENCH_RTC_DAY_ADDR, MODBUS_RS485_REG_ADDR, pTimeModule->ReadDay(), 1);
		STOREMODBUS(TESTBENCH_RTC_MONTH_ADDR, MODBUS_RS485_REG_ADDR, pTimeModule->ReadMonth(), 1);
		STOREMODBUS(TESTBENCH_RTC_YEAR_ADDR, MODBUS_RS485_REG_ADDR, pTimeModule->ReadYear(), 1);
		STOREMODBUS(TESTBENCH_RTC_HOUR_ADDR, MODBUS_RS485_REG_ADDR, pTimeModule->ReadHour(), 1);
		STOREMODBUS(TESTBENCH_RTC_MIN_ADDR, MODBUS_RS485_REG_ADDR, pTimeModule->ReadMin(), 1);
		STOREMODBUS(TESTBENCH_RTC_SEC_ADDR, MODBUS_RS485_REG_ADDR, pTimeModule->ReadSec(), 1);
	}
}

void WriteRTCForTestBench(){
	SetCommStatusBit();
	RTC_DAY_ADDRESS 	= ReadModbusRegistersForTestBench(TESTBENCH_RTC_DAY_ADDR, MODBUS_RS485_REG_ADDR);
	RTC_MONTH_ADDRESS 	= ReadModbusRegistersForTestBench(TESTBENCH_RTC_MONTH_ADDR, MODBUS_RS485_REG_ADDR);
	RTC_YEAR_ADDRESS 	= ReadModbusRegistersForTestBench(TESTBENCH_RTC_YEAR_ADDR, MODBUS_RS485_REG_ADDR);
	RTC_HOUR_ADDRESS 	= ReadModbusRegistersForTestBench(TESTBENCH_RTC_HOUR_ADDR, MODBUS_RS485_REG_ADDR);
	RTC_MIN_ADDRESS 	= ReadModbusRegistersForTestBench(TESTBENCH_RTC_MIN_ADDR, MODBUS_RS485_REG_ADDR);
	RTC_SEC_ADDRESS 	= ReadModbusRegistersForTestBench(TESTBENCH_RTC_SEC_ADDR, MODBUS_RS485_REG_ADDR);

	pTimeModule->WriteDay(RTC_DAY_ADDRESS);
	pTimeModule->WriteMonth(RTC_MONTH_ADDRESS);
	pTimeModule->WriteYear(RTC_YEAR_ADDRESS);
	pTimeModule->WriteHour(RTC_HOUR_ADDRESS);
	pTimeModule->WriteMin(RTC_MIN_ADDRESS);
	pTimeModule->WriteSec(RTC_SEC_ADDRESS);
}

BOOLEAN TestFram(uint8_t page){
	int i = 0;
	for( i = 0; i < MEM_SETTINGS_SIZE; i++)
		WriteSetting(i, 1, page, i);

	for( i = 0; i < MEM_SETTINGS_SIZE; i++){
		uint8_t reg = ReadSetting(i, 1, page);

		if(reg != i){
			return AT_FALSE;
		}
	}

	return AT_TRUE;
}

void ResetFramPage(uint8_t page){
	int i = 0;
	for( i = 0; i < MEM_SETTINGS_SIZE; i++)
		WriteSetting(i, 1, page, 0);
}

void ResetFram(){
	ResetFramPage(DEVICE_ADDR_PAGE1);
	ResetFramPage(DEVICE_ADDR_PAGE2);
}

void StartFRAMAutoTest(){
	SetCommStatusBit();

	BOOLEAN testpage1 = TestFram(DEVICE_ADDR_PAGE1);
	BOOLEAN testpage2 = TestFram(DEVICE_ADDR_PAGE2);

	if(testpage1 & testpage2)
		SetPassedStatusBit();
	else
		SetFailedStatusBit();

	ResetFram();
	ResetCommandRegister();
}

void ChangeBrightnessForTest(){
	SetCommStatusBit();
	WORD remoteBr = ReadModbusRegistersForTestBench(TESTBENCH_BR_REMOTE_ADDR, MODBUS_RS485_REG_ADDR);
	WriteBrightnessValue(remoteBr);

	WORD localBr = 100 - ReadBrightnessValue();
	STOREMODBUS(TESTBENCH_BR_LOCAL_ADDR, MODBUS_RS485_REG_ADDR, localBr, 1);
}

void ExecuteBuzzerCommandForTest(){
	SetCommStatusBit();
	BYTE buzzer = AT_READ_BIT(ReadModbusRegistersForTestBench(TESTBENCH_BUZZER_ADDR, MODBUS_RS485_REG_ADDR), TESTBENCH_BZ_REMOTE_BIT);

	if(pBuzzerModule){
		if(buzzer > 0 && pBuzzerModule->On){
			pBuzzerModule->On();
		}

		if(buzzer == 0 && pBuzzerModule->Off){
			pBuzzerModule->Off();
		}
	}
}

void ResetTsForTest(){
	SetCommStatusBit();
	STOREMODBUS(TESTBENCH_TS_ADDR, MODBUS_RS485_REG_ADDR, 0, 1);
}

void RefreshForTest(){
	// BUZZER
	BYTE bzStatus 	= READ_BUZZER_PERIPH_STATUS();
	WORD buzzer 	= ReadModbusRegistersForTestBench(TESTBENCH_BUZZER_ADDR, MODBUS_RS485_REG_ADDR);

	if(bzStatus)
		AT_SET_BIT(buzzer, TESTBENCH_BZ_LOCAL_BIT);
	else
		AT_CLEAR_BIT(buzzer, TESTBENCH_BZ_LOCAL_BIT);

	STOREMODBUS(TESTBENCH_BUZZER_ADDR, MODBUS_RS485_REG_ADDR, buzzer, 1);

	// SD
	BYTE sdStatus 	= READ_SD_PERIPH_STATUS();
	STOREMODBUS(TESTBENCH_SD_ADDR, MODBUS_RS485_REG_ADDR, sdStatus, 1);
}

void ExecuteSdCommandForTest(){
	SetCommStatusBit();

	if(uSD_Drv.State == FATFS_NONE){
		sprintf(uSD_Drv.FileName, "AT_TB.TXT");
		sprintf(uSD_Drv.TxBuffer, "AT_testBench: aggiornamento delle ore %d:%d:%d\n", RTC_HOUR_ADDRESS, RTC_MIN_ADDRESS,RTC_SEC_ADDRESS);
		uSD_Drv.State = FATFS_WRITING;
	}

	if(uSD_Drv.State == FATFS_WRITTEN){
		memset(uSD_Drv.RxBuffer, 0, sizeof(char) * FATFS_BUFF_SIZE);
		uSD_Drv.State = FATFS_READING;
	}

	if(uSD_Drv.State == FATFS_READ){
		uSD_Drv.State = FATFS_NONE;
		ResetCommandRegister();
		if(strcmp(uSD_Drv.TxBuffer, uSD_Drv.RxBuffer) == 0){
			SetPassedStatusBit();
		}
		else{
			SetFailedStatusBit();
		}
	}

	if(uSD_Drv.State == FATFS_ERR || READ_SD_PERIPH_STATUS() == 0){
		ResetCommandRegister();
		SetFailedStatusBit();
	}
}

void TestBenchRun(){
	WORD value = 0;
	READMODBUS(TESTBENCH_COMMANDS_R_ADDR, MODBUS_RS485_REG_ADDR, 1);

	RefreshForTest();

	switch(value){
		case TESTBENCH_RTC_READ_CMD:	ReadRTCForTestBench();			break;
		case TESTBENCH_RTC_WRITE_CMD:	WriteRTCForTestBench();			break;
		case TESTBENCH_AUTO_FRAM_CMD:	StartFRAMAutoTest();			break;
		case TESTBENCH_PWM_BRIGHT_CMD:	ChangeBrightnessForTest();		break;
		case TESTBENCH_BUZZER_CMD:		ExecuteBuzzerCommandForTest();	break;
		case TESTBENCH_RST_TS_CMD:		ResetTsForTest();				break;
		case TESTBENCH_SD_CMD:			ExecuteSdCommandForTest();		break;
		default:														break;
	}
}

