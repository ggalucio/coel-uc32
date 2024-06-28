/*
 * modbusCommon.h
 *
 *  Created on: 27 ott 2021
 *      Author: paoloc
 */

#ifndef COMPONENTS_MODBUS_MODBUSCOMMON_H_
#define COMPONENTS_MODBUS_MODBUSCOMMON_H_

#include "Utils/integer.h"
#include "Utils/InterfaceUtils.h"

#define TIMEOUT_REQ 500//2000

#define PACKWRITEDATA(pack, data, len)			\
		int k;									\
		for(k = 0; k < len; k++){				\
			pack[k] = data >> k * WORD_BIT_NUM;	\
		}										\

#define FINDWRITEDATAINDEX(pModbusWrite, wLen)									\
		int i;																	\
		for(i = 0; i < wLen; i++){												\
			if(AT_READ_BIT(pModbusWrite[i].command, WRITE_INVALIDATE_BIT)){		\
				AT_CLEAR_BIT(pModbusWrite[i].command, WRITE_INVALIDATE_BIT);	\
				break;															\
			}																	\
		}

void CreateChunks(BaseRegTypeDef* addrs, int length, BaseRegTypeDef* chunks, BYTE* chunksLen);
BOOLEAN TimeOutElapsed(DWORD tick, DWORD timeout);
DWORD ReadModbusDataResp(BYTE*, int, int, int, BYTE);

#endif /* COMPONENTS_MODBUS_MODBUSCOMMON_H_ */
