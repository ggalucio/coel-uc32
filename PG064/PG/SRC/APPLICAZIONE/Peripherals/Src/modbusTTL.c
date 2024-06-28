/*
 * modbusTTL.c
 *
 *  Created on: 19 nov 2021
 *      Author: paoloc
 */

#include "../Inc/modbusTTL.h"
#include "stdlib.h"
#include "string.h"

#define MODBUS_TTL_MIN_PCKG_LEN 	2

UART_HandleTypeDef huart7;
DMA_HandleTypeDef hdma_uart7_tx;
ModbusTransceiverTypeDef modbusTTLTransceiver = { 0 };
uint16_t modbusTTLTimer = 0;

void DisableTTLInterrupts(){
	HAL_NVIC_DisableIRQ(DMA1_Stream1_IRQn);
	HAL_NVIC_DisableIRQ(UART7_IRQn);
}

void EnableTTLInterrupts(){
	HAL_NVIC_SetPriority(UART7_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(UART7_IRQn);

	/* DMA1_Stream1_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Stream1_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream1_IRQn);
}

/**
  * Enable DMA controller clock
  */
static void UART_TTL_DMA_Init(void)
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

}

void UART_TTL_MspInit(UART_HandleTypeDef* huart)
{
	 GPIO_InitTypeDef GPIO_InitStruct = {0};
	  if(huart->Instance==UART7)
	  {
	  /* USER CODE BEGIN UART7_MspInit 0 */

	  /* USER CODE END UART7_MspInit 0 */
	    /* Peripheral clock enable */
	    __HAL_RCC_UART7_CLK_ENABLE();

	    __HAL_RCC_GPIOF_CLK_ENABLE();
	    /**UART7 GPIO Configuration
	    PF6     ------> UART7_RX
	    PF7     ------> UART7_TX
	    PF8     ------> UART7_DE
	    */
	    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8;
	    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	    GPIO_InitStruct.Alternate = GPIO_AF8_UART7;
	    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

	    /* UART7 DMA Init */
	    /* UART7_TX Init */
	    hdma_uart7_tx.Instance = DMA1_Stream1;
	    hdma_uart7_tx.Init.Channel = DMA_CHANNEL_5;
	    hdma_uart7_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
	    hdma_uart7_tx.Init.PeriphInc = DMA_PINC_DISABLE;
	    hdma_uart7_tx.Init.MemInc = DMA_MINC_ENABLE;
	    hdma_uart7_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	    hdma_uart7_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	    hdma_uart7_tx.Init.Mode = DMA_NORMAL;
	    hdma_uart7_tx.Init.Priority = DMA_PRIORITY_LOW;
	    hdma_uart7_tx.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
	    hdma_uart7_tx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
	    hdma_uart7_tx.Init.MemBurst = DMA_MBURST_SINGLE;
	    hdma_uart7_tx.Init.PeriphBurst = DMA_PBURST_SINGLE;
	    if (HAL_DMA_Init(&hdma_uart7_tx) != HAL_OK)
	    {

	    }

	    __HAL_LINKDMA(huart,hdmatx,hdma_uart7_tx);
	  }
}

void DisableTTLTimeout(UART_HandleTypeDef *huart){
	__HAL_UART_DISABLE_IT(huart,UART_IT_RTO);
	__HAL_UART_CLEAR_IT(huart,UART_CLEAR_RTOF);
	HAL_UART_DisableReceiverTimeout(huart);
}

void ReceiveTTLEnable(){
	//__HAL_UART_CLEAR_IDLEFLAG(&huart2);
	//HAL_UART_Receive_DMA(&huart2, (uint8_t*)receiveBuff, BUFFER_SIZE);

	DisableTTLTimeout(&huart7);

	huart7.RxState= HAL_UART_STATE_READY;

	modbusTTLComm.State = MB_READY;

	// Avvio il Timeout di fine Ricezione: Modbus Standard: 3.5 char = 28bit
	HAL_UART_ReceiverTimeout_Config(&huart7, 28);

	EnableTTLInterrupts();

	if(HAL_UART_EnableReceiverTimeout(&huart7) == HAL_OK )
	{
		// Svuoto il DR register prima di iniziare
		// qualsiasi altra operazione...
		__HAL_UART_FLUSH_DRREGISTER(&huart7);

		// Clear RTO Flag
		__HAL_UART_CLEAR_FLAG(&huart7,UART_CLEAR_RTOF);
		__HAL_UART_CLEAR_IT(&huart7,UART_CLEAR_RTOF);
		// Aabilito l'interrupt
		__HAL_UART_ENABLE_IT(&huart7,UART_IT_RTO);
		HAL_UART_Receive_IT(&huart7, &modbusTTLTransceiver.RxData, 1);
	}
}

void ResetModbusTTL(){
	modbusTTLComm.State = MB_RST;
	modbusTTLTransceiver.RxIdx = 0;
	memset(modbusTTLTransceiver.RxBuffer, 0, sizeof(modbusTTLTransceiver.RxBuffer));

	DisableTTLInterrupts();

	/*if(READ_MODBUS_RS485_OPMODE() == MASTER)
		PollingInitDma();*/
}

void MB_HAL_UART_TTL_ErrorCallback(UART_HandleTypeDef *huart)
{
	if(huart->ErrorCode == 0)
		return;

	// Le HAL gestiscono la ricezione del dato come un TIMEOUT ERROR...
	// In tal caso gestisco il messaggio normalmente...
	if( huart->ErrorCode & HAL_UART_ERROR_RTO){
		if(modbusTTLTransceiver.RxIdx > MODBUS_TTL_MIN_PCKG_LEN && modbusTTLTransceiver.RxIdx < MODBUS_BUFFER_SIZE && modbusTTLComm.ReceiveClbk){
			modbusTTLComm.ReceiveClbk(modbusTTLTransceiver.RxBuffer, modbusTTLTransceiver.RxIdx);
			ResetModbusTTLTimer();
			modbusTTLComm.State = MB_RECEIVED;
		}
	}

	//DisableInterrupts();
	ResetModbusTTL();
}

void MB_HAL_UART_TTL_RxCpltCallback(UART_HandleTypeDef *huart){
	modbusTTLTransceiver.RxBuffer[modbusTTLTransceiver.RxIdx++] = modbusTTLTransceiver.RxData;
	ReceiveTTLEnable();
	modbusTTLComm.State = MB_RECEIVING;
}

void MB_HAL_UART_TTL_TxCpltCallback(UART_HandleTypeDef *huart){
	modbusTTLComm.State = MB_TRANSMITTED;
}

/**
  * @brief USART7 Initialization Function
  * @param None
  * @retval None
  */
BOOLEAN UART_TTL_Init(void)
{
	huart7.Instance = UART7;
	huart7.Init.BaudRate = MODBUS_TTL_BAUDRATE;//9600;
	huart7.Init.WordLength = UART_WORDLENGTH_8B;
	huart7.Init.StopBits = UART_STOPBITS_1;
	huart7.Init.Parity = UART_PARITY_NONE;
	huart7.Init.Mode = UART_MODE_TX_RX;
	huart7.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart7.Init.OverSampling = UART_OVERSAMPLING_16;
	huart7.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart7.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	BOOLEAN status = HAL_RS485Ex_Init(&huart7, UART_DE_POLARITY_HIGH, 0, 0) == HAL_OK;
	return status;
}

void DeInitModbusTTL(void){
	/* Reset modbus peripheral status*/
	RESET_MODBUSTTL_PERIPH_STATUS();

	/* Disable interrupts*/
	DisableTTLInterrupts();

	/* Disable UART*/
	HAL_UART_DeInit(&huart7);

	/* Disable DMA clock*/
	__HAL_RCC_DMA1_CLK_DISABLE();
}

void StartReceivingModbusTTL(){
	ReceiveTTLEnable();
}

/**
  * @brief Send modbus data.
  * @param pData: data package to send
  * @param size: package length
  * @retval UART transmission result (TRUE if everything works good, else FALSE)
  */
BOOLEAN WriteModbusTTL(BYTE* pData, WORD size){

	/* Disable every interrupt */
	DisableTTLInterrupts();

	/* Check if peripheral initialization has been done successfully */
	if(READ_MODBUSTTL_PERIPH_STATUS() == 0)
		return AT_FALSE;

	/* Copy data into tx buffer */
	memcpy(modbusTTLTransceiver.TxBuffer, pData, sizeof(BYTE) * size);

	CLEAR_BIT(huart7.Instance->CR1, USART_CR1_RXNEIE);

	ReceiveTTLEnable();

	/* Check if uart handler reports some error */
	if( huart7.ErrorCode != HAL_UART_ERROR_NONE){
		return AT_FALSE;
	}

	/* Send data via DMA */
	BOOLEAN txState = HAL_UART_Transmit_DMA(&huart7, modbusTTLTransceiver.TxBuffer, size) == HAL_OK;

	/* Update communication state according to uart transmission result */
	modbusTTLComm.State = txState ? MB_TRANSMITTING : MB_ERR;

	/* Return trasmission result */
	return txState;
}

void ResetModbusTTLTimer(){
	MODBUS_TTL_TIMER_ADDR 	= (WORD)0;
	RESET_MODBUS_TTL_TMR_CMD();
	StartModbusTTLTimer();
}

void StartModbusTTLTimer(){
	modbusTTLTimer = HAL_GetTick();
}

void UpdateModbusTTLTimer(){
	MODBUS_TTL_TIMER_ADDR = HAL_GetTick() - modbusTTLTimer;
}

BOOLEAN IsTTLPhyConnected(){
	return AT_TRUE;
}

BOOLEAN IsTTLConnectionAvailable(){
	return AT_TRUE;
}

BOOLEAN InitModbusTTL(){
	/* Disable UART and DMA */
	DeInitModbusTTL();

	/* Start UART initialization */
	UART_TTL_DMA_Init();
	huart7.MspInitCallback = UART_TTL_MspInit;
	BOOLEAN res = UART_TTL_Init();

	if(!res)
		return AT_FALSE;

	//__HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE);

	/* Set pointers for data transmission and reset */
	modbusTTLComm.Send 		= WriteModbusTTL;

	/* Register end of Rx callback */
	HAL_UART_RegisterCallback(&huart7,HAL_UART_RX_COMPLETE_CB_ID,MB_HAL_UART_TTL_RxCpltCallback);

	/* Register end of Tx callback */
	HAL_UART_RegisterCallback(&huart7,HAL_UART_TX_COMPLETE_CB_ID,MB_HAL_UART_TTL_TxCpltCallback);

	/* Register error callback */
	HAL_UART_RegisterCallback(&huart7,HAL_UART_ERROR_CB_ID,MB_HAL_UART_TTL_ErrorCallback);

	/* Set modbus peripheral status*/
	SET_MODBUSTTL_PERIPH_STATUS();

	// Resetto un po' di cose...
	ResetModbusTTL();

	return AT_TRUE;
}
