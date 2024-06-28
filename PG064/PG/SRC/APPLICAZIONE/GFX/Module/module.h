/*
 * module.h
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#ifndef MODULE_MODULE_H_
#define MODULE_MODULE_H_

void 		(*pChangeBrightness)(int);
const char* (*pGetDecimalFormat)(uint8_t);
double  	(*pFromFloatingPointToDecimalSinglePrecision)(const double);
void 		(*pFromCharToAddress)(char const* addressStr, int* address, int* bit);
void	 	(*pToggleBitModbusRS485)(uint16_t address, uint8_t bit);
void 		(*pUpdateModbusRS485)(uint16_t address, double value, uint8_t dataType);
void 		(*pUpdateBitModbusRS485)(uint16_t address, uint8_t bit, uint8_t value);
void 		(*pWaitFor)(uint32_t ms);
void 		(*pSwitchBuzzerOn)(void);
void 		(*pSwitchBuzzerOff)(void);
void		(*pToggleBuzzer)(void);
void		(*pResumeClientTask)(void);
void		(*pSuspendClientTask)(void);

// TCPIP
void		(*pSetModeTCPIP)(uint8_t, uint32_t);
void 		(*pAddModbusTCPIPReadItem)(uint16_t, uint8_t, 	uint8_t, uint8_t);
void 		(*pAddModbusTCPIPWriteItem)(uint16_t, uint8_t, uint8_t);
void 		(*pClearModbusTCPIP)(void);
void 		(*pClearWritesModbusTCPIP)(void);
void 		(*pSearchUpdatesModbusTCPIP)(void);
void	 	(*pToggleBitModbusTCPIP)(uint16_t address, uint8_t bit);
void 		(*pUpdateModbusTCPIP)(uint16_t address, double value, uint8_t dataType);
void 		(*pUpdateBitModbusTCPIP)(uint16_t address, uint8_t bit, uint8_t value);
void 		(*pAddBitDlyItemTCPIP)(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
void 		(*pSetTimerTCPIP)(void);
void 		(*pReadRegistersTCPIP)(uint16_t, uint8_t, uint16_t*);
uint8_t		(*pBlinkingImageModbusTCPIP)(uint16_t, uint8_t, uint8_t, uint32_t, uint32_t*);
uint8_t 	(*pTimeoutCommTCPIP)(uint32_t);

// TTL
void		(*pSetModeTTL)(uint8_t, uint32_t);
void 		(*pAddModbusTTLReadItem)(uint16_t, uint8_t, 	uint8_t, uint8_t);
void 		(*pAddModbusTTLWriteItem)(uint16_t, uint8_t, uint8_t);
void 		(*pClearModbusTTL)(void);
void 		(*pClearWritesModbusTTL)(void);
void 		(*pSearchUpdatesModbusTTL)(void);
void	 	(*pToggleBitModbusTTL)(uint16_t address, uint8_t bit);
void 		(*pUpdateModbusTTL)(uint16_t address, double value, uint8_t dataType);
void 		(*pUpdateBitModbusTTL)(uint16_t address, uint8_t bit, uint8_t value);
void 		(*pAddBitDlyItemTTL)(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
void 		(*pSetTimerTTL)(void);
void 		(*pReadRegistersTTL)(uint16_t, uint8_t, uint16_t*);
uint8_t		(*pBlinkingImageModbusTTL)(uint16_t, uint8_t, uint8_t, uint32_t, uint32_t*);
uint8_t 	(*pTimeoutCommTTL)(uint32_t);

// INT
void 		(*pSearchUpdatesModbusINT)(void);
void 		(*pAddModbusINTReadItem)(uint16_t, uint8_t, 	uint8_t, uint8_t);
void 		(*pAddModbusINTWriteItem)(uint16_t, uint8_t, uint8_t);
void 		(*pClearModbusINT)(void);
void	 	(*pToggleBitModbusINT)(uint16_t address, uint8_t bit);
void 		(*pUpdateModbusINT)(uint16_t address, double value, uint8_t dataType);
void 		(*pUpdateBitModbusINT)(uint16_t address, uint8_t bit, uint8_t value);

void 		(*pAddModbusRS485ReadItem)(uint16_t, uint8_t, 	uint8_t, uint8_t);
void 		(*pAddModbusRS485WriteItem)(uint16_t, uint8_t, uint8_t);
void 		(*pClearModbusRS485)(void);
void 		(*pClearWritesModbusRS485)(void);
void 		(*pSearchUpdatesModbusRS485)(void);
void 		(*pAddBitDlyItemRS485)(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
void 		(*pAddWordDlyItem)(uint16_t, uint8_t, uint16_t, uint16_t, uint8_t);
uint32_t	(*pReadJobData)(int);
uint8_t		(*pBlinkingImageModbusRS485)(uint16_t, uint8_t, uint8_t, uint32_t, uint32_t*);
void 		(*pReadRegistersRS485)(uint16_t, uint8_t, uint16_t*);
uint8_t 	(*pTimeoutCommRS485)(uint32_t);
void 		(*pSetTimerRS485)(void);
void		(*pSetModeRS485)(uint8_t, uint32_t);
void 		(*pReadJobName)(char*);
void 		(*pReadJobNameAt)(int, char*);
void		(*pSelectJob)(int);
uint32_t	(*pChosenJob)(void);
void		(*pIncreaseJob)(int, int);
void		(*pDecreaseJob)(int, int);
uint32_t	(*pGetSelectedJob)(void);
void		(*pAddJobDataToUpdate)(int, double, uint8_t);
void		(*pAddJobNameToUpdate)(char*);
void		(*pUpdateJobsFlag)(void);
void 		(*pDeleteJobItem)(void);
void 		(*pToggleJobData)(int idx, uint8_t bit);
uint8_t 	(*pGetLanguage)(void);
void 		(*pSetLanguage)(uint8_t);
uint8_t 	(*pTsTimeoutElapsed)(uint32_t);
uint8_t 	(*pTimeElapsed)(uint32_t*, uint32_t);
uint8_t 	(*pTimeReadHour)(void);
uint8_t 	(*pTimeReadMin)(void);
uint8_t 	(*pTimeReadSec)(void);
uint8_t 	(*pTimeReadDay)(void);
uint8_t 	(*pTimeReadMonth)(void);
uint8_t 	(*pTimeReadYear)(void);
void 		(*pTimeWriteHour)(uint8_t);
void 		(*pTimeWriteMin)(uint8_t);
void 		(*pTimeWriteSec)(uint8_t);
void 		(*pTimeWriteDay)(uint8_t);
void 		(*pTimeWriteMonth)(uint8_t);
void 		(*pTimeWriteYear)(uint8_t);
void 		(*pToggleParameter)(uint16_t, uint8_t);
uint16_t 	(*pReadParameter)(uint16_t);
void		(*pWriteParameter)(uint16_t, uint16_t);
void		(*pWriteBitParameter)(uint16_t, uint8_t, uint16_t);

#endif /* MODULE_MODULE_H_ */
