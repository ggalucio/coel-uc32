/*
 * modbusUtils.h
 *
 *  Created on: 24 feb 2021
 *      Author: paoloc
 */

#ifndef UTILS_MODBUSUTILS_H_
#define UTILS_MODBUSUTILS_H_

#include "Peripherals/Inc/memory.h"
#include "InterfaceUtils.h"

// FUNCTIONS CODE
#define MODBUS_CODE_READ_HOLDING_REG		3
#define MODBUS_CODE_READ_INPUT_REG  		4
#define MODBUS_CODE_SINGLE_WRITE			6
#define MODBUS_CODE_MULTIPLE_WRITE			16
#define MODBUS_CODE_NO_EXCEPTIONS			0
#define MODBUS_CODE_ILLEGAL_FUNCTION		1
#define MODBUS_CODE_ILLEGAL_DATA_ADDRESS	2
#define MODBUS_CODE_ILLEGAL_DATA_VALUE		3
#define MODBUS_CODE_SLAVE_DEVICE_FAILURE	4
#define MODBUS_CODE_SLAVE_DEVICE_BUSY		6

#define SLAVE_ADDR_POS						0
#define FUNCTION_CODE_POS					1
#define BYTES_NUM_POS						2
#define MODBUS_TCPIP_TRANSID_POS_H			0
#define MODBUS_TCPIP_TRANSID_POS_L			1
#define MODBUS_TCPIP_PROTOCOLID_POS_H		2
#define MODBUS_TCPIP_PROTOCOLID_POS_L		3
#define MODBUS_TCPIP_UNITID_RESP_POS		6
#define MODBUS_TCPIP_FUNCODE_RESP_POS		7

#define MODBUS_TCPIP_MULT_READ_PACK_SIZE	12
#define MODBUS_TCPIP_MULT_WRITE_RESP_SIZE	6
#define MODBUS_TCPIP_SINGLE_WRITE_PACK_SIZE	6
#define MODBUS_MULTIPLE_READ_PACK_SIZE		8
#define MODBUS_SINGLE_WRITE_PACK_SIZE		8
#define MODBUS_MULTIPLE_WRITE_PACK_SIZE(n)	(9 + n * 2)
#define MODBUS_TCPIP_MULT_WRITE_PACK_SIZE(n)(7 + n * 2)
#define MODBUS_TCPIP_MULT_READ_RESP_SIZE(n)	(3 + n * 2)

#define MODBUSTCPIP_MULTIPLE_READ_PACK_SIZE	12

// MODBUS MULTIPLE WRITE
#define MODBUS_RS485_MULTIPLE_WRITE_ADDRESS_H		2
#define MODBUS_RS485_MULTIPLE_WRITE_ADDRESS_L		3
#define MODBUS_RS485_MULTIPLE_WRITE_REG_NUM_H		4
#define MODBUS_RS485_MULTIPLE_WRITE_REG_NUM_L		5
#define MODBUS_RS485_MULTIPLE_WRITE_START_VAL		7
#define MODBUS_TCPIP_MULTIPLE_WRITE_ADDRESS_H		8
#define MODBUS_TCPIP_MULTIPLE_WRITE_ADDRESS_L		9
#define MODBUS_TCPIP_MULTIPLE_WRITE_REG_NUM_H		10
#define MODBUS_TCPIP_MULTIPLE_WRITE_REG_NUM_L		11
#define MODBUS_TCPIP_MULTIPLE_WRITE_START_VAL		13

// MODBUS SINGLE WRITE
#define MODBUS_RS485_SINGLE_WRITE_ADDRESS_H	2
#define MODBUS_RS485_SINGLE_WRITE_ADDRESS_L	3
#define MODBUS_RS485_SINGLE_WRITE_REG_H		4
#define MODBUS_RS485_SINGLE_WRITE_REG_L		5
#define MODBUS_TCPIP_SINGLE_WRITE_ADDRESS_H	8
#define MODBUS_TCPIP_SINGLE_WRITE_ADDRESS_L	9
#define MODBUS_TCPIP_SINGLE_WRITE_REG_H		10
#define MODBUS_TCPIP_SINGLE_WRITE_REG_L		11

// MODBUS MULTIPLE READ
#define MODBUS_MULTIPLE_READ_ADDRESS_H		2
#define MODBUS_MULTIPLE_READ_ADDRESS_L		3
#define MODBUS_MULTIPLE_READ_REG_NUM_H		4
#define MODBUS_MULTIPLE_READ_REG_NUM_L		5

#define MODBUS_TCPIP_MULTIPLE_READ_ADDRESS_H		8
#define MODBUS_TCPIP_MULTIPLE_READ_ADDRESS_L		9
#define MODBUS_TCPIP_MULTIPLE_READ_REG_NUM_H		10
#define MODBUS_TCPIP_MULTIPLE_READ_REG_NUM_L		11

// EXCEPTIONS
#define MODBUS_EXCEPTION_RESPONSE_SIZE		5
#define MODBUS_EXCEPTION_CODE_OFFSET		0x80

#define MODBUS_BUFFER_SIZE 					128

#define STOREMODBUS(address, offset, value, len){									\
			BYTE nBytes = len * BYTES_IN_WORD;										\
			BYTE pData[nBytes];														\
			int ii;																	\
			for(ii = 0; ii < nBytes; ii++){											\
				pData[ii] = (value >> (ii * BYTE_BIT_NUM)) & BYTE_MASK;				\
			}																		\
			WriteSdRam(pData, nBytes, address * BYTES_IN_WORD + offset);			\
		}																			\

#define READMODBUS(address, offset, len){											\
			BYTE nBytes = len * BYTES_IN_WORD;										\
			BYTE pData[nBytes];														\
			ReadSdRam(pData, nBytes, address * BYTES_IN_WORD + offset);				\
			int ii;																	\
			for(ii = 0; ii < nBytes; ii++)											\
				value |= (pData[ii] << (ii * BYTE_BIT_NUM));						\
		}																			\

#define MODBUS_DATA_SIZE 50

typedef enum{
	REQ_NONE,
	REQ_READ,
	REQ_WRITE
}REQ_TYPE;

typedef enum{
	MM_INIT = 0,
	MM_IDLE,
	MM_ENABLE_TO_READ,
	MM_ENABLE_TO_WRITE,
	MM_SENDING_REQ,
	MM_SENT_REQ,
	MM_WAIT_FOR_RESP,
	MM_RECV_RESP,
	MM_UNPACK_RESP,
	MM_ERROR,
	MM_NO_DATA
}MODBUS_STATUS;

typedef enum{
	MD_START = 0,
	MD_VALID,
	MD_WAIT_FOR_DATA,
	MD_INIT,
	MD_WAIT
}MODBUS_DATA;

typedef struct{
	InterfaceData ModbusDataRead[MODBUS_DATA_SIZE];		// Puntatore ai registri modbus da leggere.
	InterfaceData ModbusDataWrite[MODBUS_DATA_SIZE];	// Puntatore ai registri modbus da scrivere.
	int ModbusDataReadLength;							// Numero di registri modbus da leggere comandati dall'utente.
	int ModbusDataWriteLength;							// Numero di registri modbus da scrivere comandati dall'utente.
}ModbusDataExchange;

typedef struct{
	BaseRegTypeDef data[MODBUS_DATA_SIZE];
	BYTE length;
}ModbusChunks;

typedef enum{
	MB_READY,
	MB_TRANSMITTING,
	MB_TRANSMITTED,
	MB_RECEIVED,
	MB_RECEIVING,
	MB_ERR,
	MB_RST
}MbState;

typedef struct{
	BOOLEAN (*Send)(BYTE* pData, WORD size);
	void (*ReceiveClbk)(BYTE* data, int length);
	void (*RstClbk)(void);
	void (*Error)(void);
	MbState State;
}ModbusCommTypeDef;

typedef struct{
	WORD  Address;
	WORD  RegisterNum;
	WORD  Register;
	WORD  TransactionId;
	WORD  ProtocolId;
	BYTE  UnitId;
}ModbusInfo;

typedef struct{
	ModbusDataExchange *ModbusDataExch;
	REQ_TYPE reqType;
	BYTE currReadIdx;
	WORD currReadAddress;
	MODBUS_STATUS exchDataState;
	MODBUS_DATA managementDataState;
	PHYCONNECTION phyConnection;
	BufferTypeDef RxBuffer;
	BYTE readRegistersNum;
	ModbusChunks chunks;
	DWORD ackTimer;
	DWORD startTick;
	WORD transactionId;
	BYTE currSlaveAddress;
	BYTE currFunctionCode;
	BYTE ResponseDataIdx;
	ModbusCommTypeDef *Handler;
	void 	(*DeInit)(void);
	BOOLEAN (*Init)(void);
	BOOLEAN (*IsPhyConnected)(void);
	BOOLEAN (*IsConnectionAvailable)(void);
	BOOLEAN (*PackReq)(BYTE **, int*, int, int, ModbusInfo, int, WORD*);
	BOOLEAN (*RespIsValid)(BYTE*, BYTE, BYTE,  BYTE);
	DWORD (*ReadResponse)(BYTE*, int, int, int, BYTE);
	BOOLEAN (*IsEnable)(void);
	BOOLEAN (*IsConnectionLost)(void);
	void (*ResetTimer)(void);
	void (*StartTimer)(void);
	void (*UpdateTimer)(void);
}ModbusClientTypeDef;

typedef struct{
	uint8_t RxBuffer[MODBUS_BUFFER_SIZE];
	uint8_t TxBuffer[MODBUS_BUFFER_SIZE];
	uint8_t RxData;
	uint8_t RxIdx;
}ModbusTransceiverTypeDef;

typedef enum{
	MMS_INIT = 0,
	MMS_RECEIVE,
	MMS_RECEIVING,
	MMS_TRANSMIT,
	MMS_TRANSMITTING,
	MMS_RST,
	MMS_EXCEPTION,
	MMS_ERR
}ModbusServerState;

typedef struct{
	PHYCONNECTION phyConnection;
	ModbusServerState State;
	ModbusCommTypeDef *Communication;
	BufferTypeDef Buffer;
	int	ExceptionCode;
	int	FunctionCodePos;
	int	SlaveAddrPos;
	int LocalAddress;
	DWORD Tick;
	DWORD CycleTick;
	BOOLEAN (*InitPeripheral)(void);
	void (*StartReceiving)(void);
	BOOLEAN (*IsFunctionCodeValid)(BYTE*, BYTE);
	BOOLEAN (*IsFrameValid)(BYTE*, BYTE);
	int (*UnpackMultipleReadRequest)(BYTE*, BYTE, ModbusInfo*);
	int (*UnpackMultipleWriteRequest)(BYTE*, BYTE, WORD**, ModbusInfo*);
	int (*UnpackSingleWriteRequest)(BYTE*, BYTE, ModbusInfo*);
	int (*PackMultipleWriteResponse)(BYTE, BYTE*, ModbusInfo);
	int (*PackMultipleReadResponse)(BYTE, BYTE*, WORD*, ModbusInfo);
	int (*PackSingleWriteResponse)(BYTE, BYTE*, ModbusInfo);
	int (*PackExceptions)(BYTE*, BYTE, BYTE, BYTE);
	void (*Reset)(void);
	BOOLEAN (*IsEnable)(void);
	BOOLEAN (*IsPhyConnected)(void);
	void	(*CloseConnection)(void);
}ModbusServerTypeDef;

#endif /* UTILS_MODBUSUTILS_H_ */
