/*
 * ethernet.c
 *
 *  Created on: 26 ott 2021
 *      Author: paoloc
 */

#include "../Inc/ethernet.h"
#include "lwip/pbuf.h"
#include "lwip/tcp.h"
#include "stdio.h"
#include "string.h"

void ethernetif_notify_conn_changed(struct netif *netif){
	if(netif_is_link_up(netif)){
		ethHandler.phyState = Phy_Connected;
		netif_set_up(netif);
	}
	else{
		ethHandler.phyState = Phy_Not_Connected;
		RESET_MODBUSTCPIP_PERIPH_STATUS();
		//netif_set_down(netif);
	}

	ethHandler.connAvailable = AT_FALSE;
}

void ResetModbusTCPIP(){
	modbusTCPIPComm.State = MB_READY;
}

BOOLEAN IsEthPhyConnected(){
	return ethHandler.phyState == Phy_Connected;
}

BOOLEAN IsEthConnAvailable(){
	return ethHandler.connAvailable;
}

void ResetTcpIpModbusTimer(){
	MODBUS_TCPIP_TIMER_ADDR 	= (WORD)0;
	RESET_MODBUS_TCPIP_TMR_CMD();
	StartTcpIpModbusTimer();
}

void StartTcpIpModbusTimer(){
	ethHandler.commTimer = HAL_GetTick();
}

void UpdateTcpIpModbusTimer(){
	MODBUS_TCPIP_TIMER_ADDR = HAL_GetTick() - ethHandler.commTimer;
}
