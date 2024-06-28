/*
 * modbusTTLTest.c
 *
 *  Created on: 11 mar 2022
 *      Author: paoloc
 */

#include "../Inc/modbusTTLTest.h"
#include "stdlib.h"
#include "string.h"

#define MODBUS_TTL_TEST_MIN_PCKG_LEN 	2

UART_HandleTypeDef huart3;
ModbusTransceiverTypeDef modbusTTLTestTransceiver = { 0 };
uint16_t modbusTTLTestTimer = 0;

void DisableTTLTestInterrupts(){
	HAL_NVIC_DisableIRQ(USART3_IRQn);
}

void EnableTTLTestInterrupts(){
    HAL_NVIC_SetPriority(USART3_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
}

void UART_TTLTest_MspInit(UART_HandleTypeDef* huart)
{
	  GPIO_InitTypeDef GPIO_InitStruct = {0};
	  if(huart->Instance==USART3)
	  {
	  /* USER CODE BEGIN USART3_MspInit 0 */

	  /* USER CODE END USART3_MspInit 0 */
	    /* Peripheral clock enable */
	    __HAL_RCC_USART3_CLK_ENABLE();

	    __HAL_RCC_GPIOB_CLK_ENABLE();
	    /**USART3 GPIO Configuration
	    PB10     ------> USART3_TX
	    PB11     ------> USART3_RX
	    */
	    GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
	    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
	    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	  }
}

void DisableTTLTestTimeout(UART_HandleTypeDef *huart){
	__HAL_UART_DISABLE_IT(huart,UART_IT_RTO);
	__HAL_UART_CLEAR_IT(huart,UART_CLEAR_RTOF);
	HAL_UART_DisableReceiverTimeout(huart);
}

void ReceiveTTLTestEnable(){
	//__HAL_UART_CLEAR_IDLEFLAG(&huart2);
	//HAL_UART_Receive_DMA(&huart2, (uint8_t*)receiveBuff, BUFFER_SIZE);

	DisableTTLTestTimeout(&huart3);

	huart3.RxState= HAL_UART_STATE_READY;

	modbusTTLTestComm.State = MB_READY;

	// Avvio il Timeout di fine Ricezione: Modbus Standard: 3.5 char = 28bit
	HAL_UART_ReceiverTimeout_Config(&huart3, 28);

	EnableTTLTestInterrupts();

	if(HAL_UART_EnableReceiverTimeout(&huart3) == HAL_OK )
	{
		// Svuoto il DR register prima di iniziare
		// qualsiasi altra operazione...
		__HAL_UART_FLUSH_DRREGISTER(&huart3);

		// Clear RTO Flag
		__HAL_UART_CLEAR_FLAG(&huart3,UART_CLEAR_RTOF);
		__HAL_UART_CLEAR_IT(&huart3,UART_CLEAR_RTOF);
		// Aabilito l'interrupt
		__HAL_UART_ENABLE_IT(&huart3,UART_IT_RTO);
		HAL_UART_Receive_IT(&huart3, &modbusTTLTestTransceiver.RxData, 1);
	}
}

void ResetModbusTTLTest(){
	modbusTTLTestComm.State = MB_RST;
	modbusTTLTestTransceiver.RxIdx = 0;
	memset(modbusTTLTestTransceiver.RxBuffer, 0, sizeof(modbusTTLTestTransceiver.RxBuffer));

	DisableTTLTestInterrupts();

	/*if(READ_MODBUS_RS485_OPMODE() == MASTER)
		PollingInitDma();*/
}

void MB_HAL_UART_TTLTest_ErrorCallback(UART_HandleTypeDef *huart)
{
	if(huart->ErrorCode == 0)
		return;

	// Le HAL gestiscono la ricezione del dato come un TIMEOUT ERROR...
	// In tal caso gestisco il messaggio normalmente...
	if( huart->ErrorCode & HAL_UART_ERROR_RTO){
		if(modbusTTLTestTransceiver.RxIdx > MODBUS_TTL_TEST_MIN_PCKG_LEN && modbusTTLTestTransceiver.RxIdx < MODBUS_BUFFER_SIZE && modbusTTLTestComm.ReceiveClbk){
			modbusTTLTestComm.ReceiveClbk(modbusTTLTestTransceiver.RxBuffer, modbusTTLTestTransceiver.RxIdx);
			ResetModbusTTLTestTimer();
			modbusTTLTestComm.State = MB_RECEIVED;
		}
	}

	//DisableInterrupts();
	ResetModbusTTLTest();
}

void MB_HAL_UART_TTLTest_RxCpltCallback(UART_HandleTypeDef *huart){
	modbusTTLTestTransceiver.RxBuffer[modbusTTLTestTransceiver.RxIdx++] = modbusTTLTestTransceiver.RxData;
	ReceiveTTLTestEnable();
	modbusTTLTestComm.State = MB_RECEIVING;
}

/**
  * @brief USART7 Initialization Function
  * @param None
  * @retval None
  */
BOOLEAN UART_TTLTest_Init(void)
{
	huart3.Instance = USART3;
	huart3.Init.BaudRate = 9600;
	huart3.Init.WordLength = UART_WORDLENGTH_8B;
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	BOOLEAN status = HAL_UART_Init(&huart3) == HAL_OK;
	return status;
}

void DeInitModbusTTLTest(void){
	/* Reset modbus peripheral status*/
	RESET_MODBUSTTLTEST_PERIPH_STATUS();

	/* Disable interrupts*/
	DisableTTLTestInterrupts();

	/* Disable UART*/
	HAL_UART_DeInit(&huart3);
}

void StartReceivingModbusTTLTest(){
	ReceiveTTLTestEnable();
}

/**
  * @brief Send modbus data.
  * @param pData: data package to send
  * @param size: package length
  * @retval UART transmission result (TRUE if everything works good, else FALSE)
  */
BOOLEAN WriteModbusTTLTest(BYTE* pData, WORD size){

	/* Disable every interrupt */
	DisableTTLTestInterrupts();

	/* Check if peripheral initialization has been done successfully */
	if(READ_MODBUSTTLTEST_PERIPH_STATUS() == 0)
		return AT_FALSE;

	/* Copy data into tx buffer */
	memcpy(modbusTTLTestTransceiver.TxBuffer, pData, sizeof(BYTE) * size);

	CLEAR_BIT(huart3.Instance->CR1, USART_CR1_RXNEIE);

	ReceiveTTLTestEnable();

	/* Check if uart handler reports some error */
	if( huart3.ErrorCode != HAL_UART_ERROR_NONE){
		return AT_FALSE;
	}

	/* Send data via DMA */
	BOOLEAN txState = HAL_UART_Transmit(&huart3, modbusTTLTestTransceiver.TxBuffer, size, 1000) == HAL_OK;

	/* Update communication state according to uart transmission result */
	modbusTTLTestComm.State = txState ? MB_TRANSMITTED : MB_ERR;

	/* Return trasmission result */
	return txState;
}

void ResetModbusTTLTestTimer(){
	MODBUS_TTL_TEST_TIMER_ADDR 	= (WORD)0;
	RESET_MODBUS_TTLTEST_TMR_CMD();
	StartModbusTTLTestTimer();
}

void StartModbusTTLTestTimer(){
	modbusTTLTestTimer = HAL_GetTick();
}

void UpdateModbusTTLTestTimer(){
	MODBUS_TTL_TEST_TIMER_ADDR = HAL_GetTick() - modbusTTLTestTimer;
}

BOOLEAN IsTTLTestPhyConnected(){
	return AT_TRUE;
}

BOOLEAN IsTTLTestConnectionAvailable(){
	return AT_TRUE;
}

BOOLEAN InitModbusTTLTest(){
	/* Disable UART and DMA */
	DeInitModbusTTLTest();

	/* Start UART initialization */

	huart3.MspInitCallback = UART_TTLTest_MspInit;
	BOOLEAN res = UART_TTLTest_Init();

	if(!res)
		return AT_FALSE;

	//__HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE);

	/* Set pointers for data transmission and reset */
	modbusTTLTestComm.Send 		= WriteModbusTTLTest;

	/* Register end of Rx callback */
	HAL_UART_RegisterCallback(&huart3, HAL_UART_RX_COMPLETE_CB_ID, MB_HAL_UART_TTLTest_RxCpltCallback);

	/* Register error callback */
	HAL_UART_RegisterCallback(&huart3,HAL_UART_ERROR_CB_ID,MB_HAL_UART_TTLTest_ErrorCallback);

	/* Set modbus peripheral status*/
	SET_MODBUSTTLTEST_PERIPH_STATUS();

	// Resetto un po' di cose...
	ResetModbusTTLTest();

	return AT_TRUE;
}


