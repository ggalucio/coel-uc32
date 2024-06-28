/*
 * ethernet.h
 *
 *  Created on: 26 ott 2021
 *      Author: paoloc
 */

#ifndef PERIPHERALS_INC_ETHERNET_H_
#define PERIPHERALS_INC_ETHERNET_H_

#include "Utils/utils.h"
#include "Utils/modbusUtils.h"


typedef enum{
	Phy_Connected = 0,
	Phy_Not_Connected
}EthPhyState;

typedef struct{
	struct tcp_echoserver_struct *tes;
	struct tcp_pcb *tpcb;
	EthPhyState phyState;
	BOOLEAN connAvailable;
	uint32_t commTimer;
	uint32_t TxDataLen;
}EthTypeDef;


EthTypeDef ethHandler;
ModbusCommTypeDef modbusTCPIPComm;
ModbusTransceiverTypeDef modbusTcpIpTransceiver;

BOOLEAN IsEthPhyConnected();
BOOLEAN IsEthConnAvailable();
void ResetModbusTCPIP();
void ResetTcpIpModbusTimer();
void StartTcpIpModbusTimer();
void UpdateTcpIpModbusTimer();

#endif /* PERIPHERALS_INC_ETHERNET_H_ */
