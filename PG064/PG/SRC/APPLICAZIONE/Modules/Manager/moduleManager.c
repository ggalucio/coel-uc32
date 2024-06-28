/*
 * moduleManager.c
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#include "moduleManager.h"
#include "../Math/maths.h"
#include "../Converter/converter.h"
#include "Module/module.h"
#include "../../Peripherals/Inc/peripheral.h"
#include "../../Peripherals/Inc/wait.h"
#include "../Modbus/modbusModule.h"
#include "../TS/tsModule.h"
#include "../Time/timeModule.h"
#include "../Buzzer/buzzerModule.h"
#include "../Memory/memoryModule.h"
#include "../Job/jobModule.h"
#include "../Settings/settings.h"
#include "../Brightness/brightnessModule.h"
#include "../Language/langModule.h"
#include "../Display/displayModule.h"
#include "../FatFs/fatFsModule.h"

extern void InitGraphicModulePtr();
extern void RefreshUIRS485(uint16_t, uint32_t);
extern void RefreshUITCPIP(uint16_t, uint32_t);
extern void RefreshUITTL(uint16_t, uint32_t);
extern void RefreshUIINT(uint16_t, uint32_t);

extern void InitGraphicModulePtrExt();

void InitModulesPtrs(void){
	// MATHS
	pGetDecimalFormat 							= GetDecimalFormat;
	pFromFloatingPointToDecimalSinglePrecision 	= FromFloatingPointToDecimalSinglePrecision;

	// CONVERTERS
	pFromCharToAddress 							= FromCharToAddress;

	// WAIT
	pWaitFor									= WaitFor;

	// BUZZER
	pSwitchBuzzerOn								= pBuzzerModule->On;
	pSwitchBuzzerOff							= pBuzzerModule->Off;
	pToggleBuzzer								= pBuzzerModule->Toggle;

	// JOB
	pReadJobName								= pJobModule->JobName;
	pReadJobNameAt								= pJobModule->JobNameAt;
	pReadJobData								= pJobModule->ReadJobData;
	pAddJobDataToUpdate							= pJobModule->AddJobDataToUpdate;
	pAddJobNameToUpdate							= pJobModule->AddJobNameToUpdate;
	pUpdateJobsFlag								= pJobModule->UpdateJobsFlag;
	pSelectJob									= pJobModule->SelectJob;
	pChosenJob									= pJobModule->ChosenJob;
	pIncreaseJob								= pJobModule->IncreaseJob;
	pDecreaseJob								= pJobModule->DecreaseJob;
	pGetSelectedJob								= pJobModule->GetSelectedJob;
	pDeleteJobItem								= pJobModule->DeleteJob;
	pToggleJobData								= pJobModule->ToggleJobData;

	// RS485
	pToggleBitModbusRS485 						= pModbusRS485Module->ToggleBit;
	pUpdateModbusRS485 							= pModbusRS485Module->Update;
	pUpdateBitModbusRS485 						= pModbusRS485Module->UpdateBit;
	pAddModbusRS485ReadItem 					= pModbusRS485Module->AddReadItem;
	pAddModbusRS485WriteItem 					= pModbusRS485Module->AddWriteItem;
	pClearModbusRS485							= pModbusRS485Module->Clear;
	pClearWritesModbusRS485						= pModbusRS485Module->ClearWrites;
	pSearchUpdatesModbusRS485					= pModbusRS485Module->SearchUpdates;
	pBlinkingImageModbusRS485					= pModbusRS485Module->BlinkImage;
	pAddBitDlyItemRS485							= pModbusRS485Module->AddBitDlyItem;
	pAddWordDlyItem								= pModbusRS485Module->AddWordDlyItem;
	pReadRegistersRS485							= pModbusRS485Module->ReadModbusRegisters;
	pTimeoutCommRS485							= pModbusRS485Module->TimeOutCommElapsed;
	pSetTimerRS485								= pModbusRS485Module->SetTimerCmd;
	pSetModeRS485								= pModbusRS485Module->SetModeAs;
	pModbusRS485Module->Refresh					= RefreshUIRS485;

	// TCPIP
	pToggleBitModbusTCPIP 						= pModbusTCPIPModule->ToggleBit;
	pUpdateModbusTCPIP							= pModbusTCPIPModule->Update;
	pUpdateBitModbusTCPIP						= pModbusTCPIPModule->UpdateBit;
	pAddModbusTCPIPReadItem 					= pModbusTCPIPModule->AddReadItem;
	pAddModbusTCPIPWriteItem 					= pModbusTCPIPModule->AddWriteItem;
	pClearModbusTCPIP							= pModbusTCPIPModule->Clear;
	pClearWritesModbusTCPIP						= pModbusTCPIPModule->ClearWrites;
	pSearchUpdatesModbusTCPIP					= pModbusTCPIPModule->SearchUpdates;
	pBlinkingImageModbusTCPIP					= pModbusTCPIPModule->BlinkImage;
	pAddBitDlyItemTCPIP							= pModbusTCPIPModule->AddBitDlyItem;
	pReadRegistersTCPIP							= pModbusTCPIPModule->ReadModbusRegisters;
	pTimeoutCommTCPIP							= pModbusTCPIPModule->TimeOutCommElapsed;
	pSetTimerTCPIP								= pModbusTCPIPModule->SetTimerCmd;
	pSetModeTCPIP								= pModbusTCPIPModule->SetModeAs;
	pModbusTCPIPModule->Refresh					= RefreshUITCPIP;

	// TTL
	pToggleBitModbusTTL 						= pModbusTTLModule->ToggleBit;
	pUpdateModbusTTL							= pModbusTTLModule->Update;
	pUpdateBitModbusTTL							= pModbusTTLModule->UpdateBit;
	pAddModbusTTLReadItem	 					= pModbusTTLModule->AddReadItem;
	pAddModbusTTLWriteItem 						= pModbusTTLModule->AddWriteItem;
	pClearModbusTTL								= pModbusTTLModule->Clear;
	pClearWritesModbusTTL						= pModbusTTLModule->ClearWrites;
	pSearchUpdatesModbusTTL						= pModbusTTLModule->SearchUpdates;
	pBlinkingImageModbusTTL						= pModbusTTLModule->BlinkImage;
	pAddBitDlyItemTTL							= pModbusTTLModule->AddBitDlyItem;
	pReadRegistersTTL							= pModbusTTLModule->ReadModbusRegisters;
	pTimeoutCommTTL								= pModbusTTLModule->TimeOutCommElapsed;
	pSetTimerTTL								= pModbusTTLModule->SetTimerCmd;
	pSetModeTTL									= pModbusTTLModule->SetModeAs;
	pModbusTTLModule->Refresh					= RefreshUITTL;

	// INT
	pAddModbusINTReadItem	 					= pModbusINTModule->AddReadItem;
	pAddModbusINTWriteItem 						= pModbusINTModule->AddWriteItem;
	pClearModbusINT								= pModbusINTModule->Clear;
	pToggleBitModbusINT 						= pModbusINTModule->ToggleBit;
	pUpdateModbusINT							= pModbusINTModule->Update;
	pUpdateBitModbusINT							= pModbusINTModule->UpdateBit;
	pSearchUpdatesModbusINT						= pModbusINTModule->SearchUpdates;
	pModbusINTModule->Refresh					= RefreshUIINT;

	// MEMORY
	pJobModule->WriteJobData					= pMemoryModule->WriteExt;

	// LANGUAGE
	pGetLanguage								= pLangModule->GetLanguage;
	pSetLanguage								= pLangModule->SetLanguage;

	// TS
	pTsTimeoutElapsed							= pTsModule->TimeoutElapsed;

	// TIME
	pTimeElapsed								= pTimeModule->Elapsed;
	pTimeReadHour								= pTimeModule->ReadHour;
	pTimeReadMin								= pTimeModule->ReadMin;
	pTimeReadSec								= pTimeModule->ReadSec;
	pTimeReadDay								= pTimeModule->ReadDay;
	pTimeReadMonth								= pTimeModule->ReadMonth;
	pTimeReadYear								= pTimeModule->ReadYear;
	pTimeWriteHour								= pTimeModule->WriteHour;
	pTimeWriteMin								= pTimeModule->WriteMin;
	pTimeWriteSec								= pTimeModule->WriteSec;
	pTimeWriteDay								= pTimeModule->WriteDay;
	pTimeWriteMonth								= pTimeModule->WriteMonth;
	pTimeWriteYear								= pTimeModule->WriteYear;

	// SETTINGS
	pToggleParameter							= pSettingsModule->Toggle;
	pReadParameter								= pSettingsModule->Read;
	pWriteParameter								= pSettingsModule->Write;
	pWriteBitParameter							= pSettingsModule->WriteBit;
}

void InitModules(void){
	InitGraphicModulePtr();	InitGraphicModulePtrExt();
	InitPeripherls();
	InitMemoryModule();
	InitModbusModule();
	InitTSModule();
	InitTimeModule();
	InitBuzzerModule();
	InitJobModule();
	InitSettings();
	InitBrightnessModule();
	InitLangModule();
	InitDisplayModule();
	InitFatFsModule();
	InitModulesPtrs();

	pModbusClientCycle 	= pModbusClientCycleModule;
	pModbusServerCycle 	= pModbusServerCycleModule;

	pFatsCycle 			= pFatFsCycleModule;
	pTsCycle 			= pTsCycleModule;
	pJobCycle			= pJobCycleModule;
	pTimeCycle			= pTimeCycleModule;

	pBuzzerModule->On();
	WaitFor(250);
	pBuzzerModule->Off();
}

void SetJobCallback(void* Callback){
	if(pJobModule){
		pUpdateJobsFlag = pJobModule->UpdateJobsFlag = Callback;
	}
}

void SuspendClientTaskCallback(void* Callback){
	pSuspendClientTask = Callback;
}

void ResumeClientTaskCallback(void* Callback){
	pResumeClientTask = Callback;
}

BOOLEAN DoesModbusServerTaskNeedToRun(){
	if(READ_MODBUS_RS485_OPMODE() == SLAVE &&
			READ_MODBUS_TTL_OPMODE() == SLAVE &&
			READ_MODBUS_TCPIP_OPMODE() == SLAVE){
		return AT_FALSE;
	}

	return AT_TRUE;
}

BOOLEAN DoesModbusClientTaskNeedToRun(){
	if(READ_MODBUS_RS485_OPMODE() == MASTER &&
			READ_MODBUS_TTL_OPMODE() == MASTER &&
			READ_MODBUS_TCPIP_OPMODE() == MASTER){
		return AT_FALSE;
	}

	return AT_TRUE;
}
