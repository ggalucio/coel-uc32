/*
 * utils.h
 *
 *  Created on: 22 feb 2021
 *      Author: paoloc
 */

#ifndef UTILS_H_
#define UTILS_H_

#define BYTE_MASK		255

#define WORD_MASK		65535

#define WORD_BIT_NUM	16

#define BYTE_BIT_NUM	8

#define BYTES_IN_WORD	2

#define AT_SET_BIT(REG, BIT)     	((REG) |= (1UL << BIT))

#define AT_CLEAR_BIT(REG, BIT)   	((REG) &= ~(1UL << BIT))

#define AT_READ_BIT(REG, BIT)    	((REG >> BIT) & 1U)

#define AT_TOGGLE_BIT(REG, BIT)    	((REG) ^= (1UL << BIT))

// RESISTIVE TOUCH SCREEN
#define RESISTIVE_CHANGE_SEQ_CMD	0	// Comando cambio sequenza
#define RESISTIVE_READ_TOUCH_CMD	1	// Comando rilevamento contatto
#define RESISTIVE_READ_X_COORD_CMD	2	// Comando lettura coordinata X
#define RESISTIVE_READ_Y_COORD_CMD	3	// Comando lettura coordinata Y

#define RESISTIVE_TOUCH_SEQUENCE	1	// Sequenza rilevamento contatto
#define RESISTIVE_READX_SEQUENCE	2	// Sequenza lettura coordinata X
#define RESISTIVE_READY_SEQUENCE	3	// Sequenza lettura coordinata Y

// PERIPHERAL STATUS BIT
#define MODBUS_RS485_PERIPH_STATUS_BIT		0
#define TS_PERIPH_STATUS_BIT				1
#define MODBUS_TCPIP_PERIPH_STATUS_BIT		2
#define MODBUS_TTL_PERIPH_STATUS_BIT		3
#define BUZZER_STATUS_BIT					4
#define SD_STATUS_BIT						5
#define MODBUS_TTL_TEST_PERIPH_STATUS_BIT	6

#define MODBUS_RS485_OPMODE_BIT			0	// Operational mode modbus bit (1: MASTER - 0: SLAVE)
#define MODBUS_TCPIP_OPMODE_BIT			1	// Operational mode modbus bit (1: MASTER - 0: SLAVE)
#define MODBUS_TTL_OPMODE_BIT			2	// Operational mode modbus bit (1: MASTER - 0: SLAVE)

#define MODBUS_RS485_TMR_CMD_BIT	0
#define MODBUS_TCPIP_TMR_CMD_BIT	1
#define MODBUS_TTL_TMR_CMD_BIT		2
#define MODBUS_TTLTEST_TMR_CMD_BIT	3

//#define MODBUS_REG_SIZE				65535 * 2				// MODBUS REGISTERS SIZE
#define MODBUS_REG_SIZE					4096					// MODBUS REGISTERS SIZE

// ADDRESS
#define PERIPHERAL_STATUS_ADDRESS  		*(uint16_t*)0xc0300000

#define TS_PRESS_TIMER_ADDRESS  		*(uint16_t*)0xc0300002	// 02: Timer parte bassa
																// 03: Timer parte alta
																// 04: Spare
																// 05: Spare

#define MODBUS_RS485_TIMER_ADDR			*(uint16_t*)0xc0300006	// 06: Timer modbus RS485 parte bassa
																// 07: Timer modbus RS485 parte alta

#define MODBUS_TCPIP_TIMER_ADDR			*(uint16_t*)0xc0300008	// 08: Timer modbus TCPIP parte bassa
																// 09: Timer modbus TCPIP parte alta

#define MODBUS_TTL_TIMER_ADDR			*(uint16_t*)0xc030000A	// 0A: Timer modbus TTL parte bassa
																// 0B: Timer modbus TTL parte alta

#define MODBUS_TIMER_CMD_ADDR			*(uint8_t*)0xc030000C	// 0C: Comandi modbus
																// bit0: RS485
																// bit1: TCPIP
																// bit2: TTL
																// bit3: TTL Test

#define COMM_OP_MODE_ADDRESS  			*(uint8_t*)0xc030000D	// 0D: Communication operation mode
																// bit 0: MODBUS RS485 (1: MASTER - 0: SLAVE)
																// bit 1: MODBUS TCPIP (1: MASTER - 0: SLAVE)
																// bit 2: MODBUS TTL   (1: MASTER - 0: SLAVE)

#define MODBUS_TTL_TEST_TIMER_ADDR		*(uint16_t*)0xc030000E	// 0E: Timer modbus TTL TEST parte bassa
																// 0F: Timer modbus TTL TEST parte alta

#define JOB_SELECTED_ADDRESS  			*(uint8_t*)0xc0300010	// Indice JOB selezionato

#define RTC_HOUR_ADDRESS  				*(uint8_t*)0xc0300011	// Indirizzo ora
#define RTC_MIN_ADDRESS  				*(uint8_t*)0xc0300012	// Indirizzo minuti
#define RTC_SEC_ADDRESS  				*(uint8_t*)0xc0300013	// Indirizzo secondi
#define RTC_DAY_ADDRESS  				*(uint8_t*)0xc0300014	// Indirizzo giorno
#define RTC_MONTH_ADDRESS  				*(uint8_t*)0xc0300015	// Indirizzo mese
#define RTC_YEAR_ADDRESS  				*(uint8_t*)0xc0300016	// Indirizzo anno

#define MODBUS_RS485_BAUDRATE			*(uint32_t*)0xc0300020	// Baudrate RS485
#define MODBUS_TTL_BAUDRATE				*(uint32_t*)0xc0300024	// Baudrate TTL

#define SELECTED_JOB_START_ADDR			*(uint8_t*)0xc0300100	// Selected Job
#define SELECTED_JOB_BYTE_SIZE			256


#define MODBUS_RS485_REG_ADDR			0xc0400000									// MODBUS RS485 REGISTERS
#define MODBUS_TCPIP_REG_ADDR 			MODBUS_RS485_REG_ADDR + MODBUS_REG_SIZE		// MODBUS TCPIP REGISTERS
#define MODBUS_SDRAM_REG_ADDR 			MODBUS_TCPIP_REG_ADDR + MODBUS_REG_SIZE		// MODBUS SDRAM REGISTERS

// MODBUS RS485 STATUS
#define SET_MODBUSRS485_PERIPH_STATUS()		(AT_SET_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_RS485_PERIPH_STATUS_BIT))
#define RESET_MODBUSRS485_PERIPH_STATUS()	(AT_CLEAR_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_RS485_PERIPH_STATUS_BIT))
#define READ_MODBUSRS485_PERIPH_STATUS()	(AT_READ_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_RS485_PERIPH_STATUS_BIT))

// MODBUS TCPIP STATUS
#define SET_MODBUSTCPIP_PERIPH_STATUS()		(AT_SET_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_TCPIP_PERIPH_STATUS_BIT))
#define RESET_MODBUSTCPIP_PERIPH_STATUS()	(AT_CLEAR_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_TCPIP_PERIPH_STATUS_BIT))
#define READ_MODBUSTCPIP_PERIPH_STATUS()	(AT_READ_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_TCPIP_PERIPH_STATUS_BIT))

// MODBUS TTL STATUS
#define SET_MODBUSTTL_PERIPH_STATUS()		(AT_SET_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_TTL_PERIPH_STATUS_BIT))
#define RESET_MODBUSTTL_PERIPH_STATUS()		(AT_CLEAR_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_TTL_PERIPH_STATUS_BIT))
#define READ_MODBUSTTL_PERIPH_STATUS()		(AT_READ_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_TTL_PERIPH_STATUS_BIT))

// MODBUS TTL TEST STATUS
#define SET_MODBUSTTLTEST_PERIPH_STATUS()	(AT_SET_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_TTL_TEST_PERIPH_STATUS_BIT))
#define RESET_MODBUSTTLTEST_PERIPH_STATUS()	(AT_CLEAR_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_TTL_TEST_PERIPH_STATUS_BIT))
#define READ_MODBUSTTLTEST_PERIPH_STATUS()	(AT_READ_BIT(PERIPHERAL_STATUS_ADDRESS, MODBUS_TTL_TEST_PERIPH_STATUS_BIT))

// TS STATUS
#define SET_TS_PERIPH_STATUS() 				(AT_SET_BIT(PERIPHERAL_STATUS_ADDRESS, TS_PERIPH_STATUS_BIT))
#define RESET_TS_PERIPH_STATUS()			(AT_CLEAR_BIT(PERIPHERAL_STATUS_ADDRESS, TS_PERIPH_STATUS_BIT))

// BUZZER STATUS
#define SET_BUZZER_PERIPH_STATUS()			(AT_SET_BIT(PERIPHERAL_STATUS_ADDRESS, BUZZER_STATUS_BIT))
#define RESET_BUZZER_PERIPH_STATUS()		(AT_CLEAR_BIT(PERIPHERAL_STATUS_ADDRESS, BUZZER_STATUS_BIT))
#define READ_BUZZER_PERIPH_STATUS()			(AT_READ_BIT(PERIPHERAL_STATUS_ADDRESS, BUZZER_STATUS_BIT))

// SD STATUS
#define SET_SD_PERIPH_STATUS()				(AT_SET_BIT(PERIPHERAL_STATUS_ADDRESS, SD_STATUS_BIT))
#define RESET_SD_PERIPH_STATUS()			(AT_CLEAR_BIT(PERIPHERAL_STATUS_ADDRESS, SD_STATUS_BIT))
#define READ_SD_PERIPH_STATUS()				(AT_READ_BIT(PERIPHERAL_STATUS_ADDRESS, SD_STATUS_BIT))

// MODBUS RS485 OPERATION MODE
#define SET_MODBUS_RS485_OPMODE_MASTER() 	(AT_SET_BIT(COMM_OP_MODE_ADDRESS, MODBUS_RS485_OPMODE_BIT))
#define SET_MODBUS_RS485_OPMODE_SLAVE() 	(AT_CLEAR_BIT(COMM_OP_MODE_ADDRESS, MODBUS_RS485_OPMODE_BIT))
#define READ_MODBUS_RS485_OPMODE()			(AT_READ_BIT(COMM_OP_MODE_ADDRESS, MODBUS_RS485_OPMODE_BIT))

// MODBUS TCPIP OPERATION MODE
#define SET_MODBUS_TCPIP_OPMODE_MASTER() 	(AT_SET_BIT(COMM_OP_MODE_ADDRESS, MODBUS_TCPIP_OPMODE_BIT))
#define SET_MODBUS_TCPIP_OPMODE_SLAVE() 	(AT_CLEAR_BIT(COMM_OP_MODE_ADDRESS, MODBUS_TCPIP_OPMODE_BIT))
#define READ_MODBUS_TCPIP_OPMODE()			(AT_READ_BIT(COMM_OP_MODE_ADDRESS, MODBUS_TCPIP_OPMODE_BIT))

// MODBUS TTL OPERATION MODE
#define SET_MODBUS_TTL_OPMODE_MASTER() 		(AT_SET_BIT(COMM_OP_MODE_ADDRESS, MODBUS_TTL_OPMODE_BIT))
#define SET_MODBUS_TTL_OPMODE_SLAVE() 		(AT_CLEAR_BIT(COMM_OP_MODE_ADDRESS, MODBUS_TTL_OPMODE_BIT))
#define READ_MODBUS_TTL_OPMODE()			(AT_READ_BIT(COMM_OP_MODE_ADDRESS, MODBUS_TTL_OPMODE_BIT))

// MODBUS RS485 TIMER COMMAND
#define SET_MODBUS_RS485_TMR_CMD() 		(AT_SET_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_RS485_TMR_CMD_BIT))
#define RESET_MODBUS_RS485_TMR_CMD()	(AT_CLEAR_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_RS485_TMR_CMD_BIT))
#define READ_MODBUS_RS485_TMR_CMD()		(AT_READ_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_RS485_TMR_CMD_BIT))

// MODBUS TCPIP TIMER COMMAND
#define SET_MODBUS_TCPIP_TMR_CMD() 		(AT_SET_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_TCPIP_TMR_CMD_BIT))
#define RESET_MODBUS_TCPIP_TMR_CMD()	(AT_CLEAR_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_TCPIP_TMR_CMD_BIT))
#define READ_MODBUS_TCPIP_TMR_CMD()		(AT_READ_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_TCPIP_TMR_CMD_BIT))

// MODBUS TTL TIMER COMMAND
#define SET_MODBUS_TTL_TMR_CMD() 		(AT_SET_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_TTL_TMR_CMD_BIT))
#define RESET_MODBUS_TTL_TMR_CMD()		(AT_CLEAR_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_TTL_TMR_CMD_BIT))
#define READ_MODBUS_TTL_TMR_CMD()		(AT_READ_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_TTL_TMR_CMD_BIT))

// MODBUS TTL TEST TIMER COMMAND
#define SET_MODBUS_TTLTEST_TMR_CMD() 	(AT_SET_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_TTLTEST_TMR_CMD_BIT))
#define RESET_MODBUS_TTLTEST_TMR_CMD()	(AT_CLEAR_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_TTLTEST_TMR_CMD_BIT))
#define READ_MODBUS_TTLTEST_TMR_CMD()	(AT_READ_BIT(MODBUS_TIMER_CMD_ADDR, MODBUS_TTLTEST_TMR_CMD_BIT))

#define SWITCH_ON						1
#define SWITCH_OFF						0

#define MASTER							1
#define SLAVE							0

#define BUFFER_SIZE						255

typedef enum{
	MP_DISCONNECTED = 0,
	MP_CONNECTED
}PHYCONNECTION;

typedef enum{
	FATFS_NONE,
	FATFS_WRITING,
	FATFS_WRITTEN,
	FATFS_READING,
	FATFS_ENABLE_TO_READ,
	FATFS_READ,
	FATFS_ERR,
}FATFS_STATUS;

typedef enum{
	AT_TRUE = 1,
	AT_FALSE = 0
}BOOLEAN;

#endif /* UTILS_H_ */