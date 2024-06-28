/*
 * modbus.c
 *
 *  Created on: 28 giu 2021
 *      Author: paoloc
 */

#include "../Inc/modbus.h"
#include "stm32f7xx_hal.h"
#include "stdlib.h"
#include "string.h"

#define MODBUS_MIN_PCKG_LEN 	2
#define MODBUS_TX_TIMEOUT 		1000

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;
ModbusTransceiverTypeDef modbusTransceiver = { 0 };

BOOLEAN WriteModbusRS485(BYTE* pData, WORD size);
uint32_t dataSize = 0;
uint16_t modbusTimer = 0;

void DisableInterrupts(){
	HAL_NVIC_DisableIRQ(DMA1_Stream5_IRQn);
	HAL_NVIC_DisableIRQ(DMA1_Stream6_IRQn);
	HAL_NVIC_DisableIRQ(USART2_IRQn);
}

void EnableInterrupts(){
	HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);

	/* DMA1_Stream5_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
	/* DMA1_Stream6_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);
}

void UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(huart->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PD4     ------> USART2_DE
    PD5     ------> USART2_TX
    PD6     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* USART2 DMA Init */
    /* USART2_RX Init */
    hdma_usart2_rx.Instance = DMA1_Stream5;
    hdma_usart2_rx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_rx.Init.Mode = DMA_NORMAL;
    hdma_usart2_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart2_rx.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
    hdma_usart2_rx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
    hdma_usart2_rx.Init.MemBurst = DMA_MBURST_SINGLE;
    hdma_usart2_rx.Init.PeriphBurst = DMA_PBURST_SINGLE;
    if (HAL_DMA_Init(&hdma_usart2_rx) != HAL_OK)
    {

    }

    __HAL_LINKDMA(huart,hdmarx,hdma_usart2_rx);

    /* USART2_TX Init */
    hdma_usart2_tx.Instance = DMA1_Stream6;
    hdma_usart2_tx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_tx.Init.Mode = DMA_NORMAL;
    hdma_usart2_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart2_tx.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
    hdma_usart2_tx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
    hdma_usart2_tx.Init.MemBurst = DMA_MBURST_SINGLE;
    hdma_usart2_tx.Init.PeriphBurst = DMA_PBURST_SINGLE;
    if (HAL_DMA_Init(&hdma_usart2_tx) != HAL_OK)
    {

    }

    __HAL_LINKDMA(huart,hdmatx,hdma_usart2_tx);
  }

}

/**
  * Enable DMA controller clock
  */
static void UART_DMA_Init(void)
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

}

void DisableTimeout(UART_HandleTypeDef *huart){
	__HAL_UART_DISABLE_IT(huart,UART_IT_RTO);
	__HAL_UART_CLEAR_IT(huart,UART_CLEAR_RTOF);
	HAL_UART_DisableReceiverTimeout(huart);
}

void PollingInitDma(){
	//__HAL_UART_CLEAR_IDLEFLAG(&huart2);
	//HAL_UART_Receive_DMA(&huart2, (uint8_t*)receiveBuff, BUFFER_SIZE);

	DisableTimeout(&huart2);

	huart2.RxState= HAL_UART_STATE_READY;

	modbusRS485Comm.State = MB_READY;

	// Avvio il Timeout di fine Ricezione: Modbus Standard: 3.5 char = 28bit
	HAL_UART_ReceiverTimeout_Config(&huart2, 28);

	EnableInterrupts();

	if(HAL_UART_EnableReceiverTimeout(&huart2) == HAL_OK )
	{
		// Svuoto il DR register prima di iniziare
		// qualsiasi altra operazione...
		__HAL_UART_FLUSH_DRREGISTER(&huart2);

		// Clear RTO Flag
		__HAL_UART_CLEAR_FLAG(&huart2,UART_CLEAR_RTOF);
		__HAL_UART_CLEAR_IT(&huart2,UART_CLEAR_RTOF);
		// Aabilito l'interrupt
		__HAL_UART_ENABLE_IT(&huart2,UART_IT_RTO);
		HAL_UART_Receive_IT(&huart2, &modbusTransceiver.RxData, 1);
	}
}



void ResetModbusRS485(){
	modbusRS485Comm.State = MB_RST;
	modbusTransceiver.RxIdx = 0;
	memset(modbusTransceiver.RxBuffer, 0, sizeof(modbusTransceiver.RxBuffer));

	DisableInterrupts();

	/*if(READ_MODBUS_RS485_OPMODE() == MASTER)
		PollingInitDma();*/
}

void MB_HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	if(huart->ErrorCode == 0)
		return;

	// Le HAL gestiscono la ricezione del dato come un TIMEOUT ERROR...
	// In tal caso gestisco il messaggio normalmente...
	if( huart->ErrorCode & HAL_UART_ERROR_RTO){
		if(modbusTransceiver.RxIdx > MODBUS_MIN_PCKG_LEN && modbusTransceiver.RxIdx < MODBUS_BUFFER_SIZE && modbusRS485Comm.ReceiveClbk){
			modbusRS485Comm.ReceiveClbk(modbusTransceiver.RxBuffer, modbusTransceiver.RxIdx);
			ResetModbusTimer();
			modbusRS485Comm.State = MB_RECEIVED;
		}
	}

	//DisableInterrupts();
	ResetModbusRS485();
}

void MB_HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	modbusTransceiver.RxBuffer[modbusTransceiver.RxIdx++] = modbusTransceiver.RxData;
	PollingInitDma();
	modbusRS485Comm.State = MB_RECEIVING;
}

void MB_HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	modbusRS485Comm.State = MB_TRANSMITTED;
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
BOOLEAN UART_RS485_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = MODBUS_RS485_BAUDRATE;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  return HAL_RS485Ex_Init(&huart2, UART_DE_POLARITY_HIGH, 0, 0) == HAL_OK;
}

/**
  * @brief Deinitialize UART and interrupts
  * @param None
  * @retval None
  */
void DeInitModbusRS485(){

	/* Reset modbus peripheral status*/
	RESET_MODBUSRS485_PERIPH_STATUS();

	/* Disable interrupts*/
	DisableInterrupts();

	/* Disable UART*/
	HAL_UART_DeInit(&huart2);

	/* Disable DMA clock*/
	__HAL_RCC_DMA1_CLK_DISABLE();
}

void StartReceivingModbusRS485(){
	PollingInitDma();
}

/**
  * @brief Initialize UART for modbus manage
  * @param None
  * @retval None
  */
BOOLEAN InitModbusRS485(void){

	/* Disable UART and DMA */
	DeInitModbusRS485();

	/* Start UART initialization */
	UART_DMA_Init();
	huart2.MspInitCallback = UART_MspInit;

	BOOLEAN res = UART_RS485_Init();

	if(!res)
		return AT_FALSE;

	//__HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE);

	/* Set pointers for data transmission and reset */
	modbusRS485Comm.Send 		= WriteModbusRS485;

	/* Register end of Rx callback */
	HAL_UART_RegisterCallback(&huart2,HAL_UART_RX_COMPLETE_CB_ID,MB_HAL_UART_RxCpltCallback);

	/* Register end of Tx callback */
	HAL_UART_RegisterCallback(&huart2,HAL_UART_TX_COMPLETE_CB_ID,MB_HAL_UART_TxCpltCallback);

	/* Register error callback */
	HAL_UART_RegisterCallback(&huart2,HAL_UART_ERROR_CB_ID,MB_HAL_UART_ErrorCallback);

	/* Set modbus peripheral status*/
	SET_MODBUSRS485_PERIPH_STATUS();

	// Resetto un po' di cose...
	ResetModbusRS485();

	return AT_TRUE;
}

/**
  * @brief Send modbus data.
  * @param pData: data package to send
  * @param size: package length
  * @retval UART transmission result (TRUE if everything works good, else FALSE)
  */
BOOLEAN WriteModbusRS485(BYTE* pData, WORD size){

	/* Disable every interrupt */
	DisableInterrupts();

	/* Check if peripheral initialization has been done successfully */
	if(READ_MODBUSRS485_PERIPH_STATUS() == 0)
		return AT_FALSE;

	/* Copy data into tx buffer */
	memcpy(modbusTransceiver.TxBuffer, pData, sizeof(BYTE) * size);

	CLEAR_BIT(huart2.Instance->CR1, USART_CR1_RXNEIE);

	PollingInitDma();

	/* Check if uart handler reports some error */
	if( huart2.ErrorCode != HAL_UART_ERROR_NONE){
		return AT_FALSE;
	}

	/* Send data via DMA */
	BOOLEAN txState = HAL_UART_Transmit_DMA(&huart2, modbusTransceiver.TxBuffer, size) == HAL_OK;

	/* Update communication state according to uart transmission result */
	modbusRS485Comm.State = txState ? MB_TRANSMITTING : MB_ERR;

	/* Return trasmission result */
	return txState;
}

/**
  * @brief Reset modbus transmission timer
  * @param None
  * @retval None
  */
void ResetModbusTimer(){
	MODBUS_RS485_TIMER_ADDR 	= (WORD)0;
	RESET_MODBUS_RS485_TMR_CMD();
	StartModbusTimer();
}

/**
  * @brief Start modbus transmission timer
  * @param None
  * @retval None
  */
void StartModbusTimer(){
	modbusTimer = HAL_GetTick();
}

/**
  * @brief Update modbus transmission timer
  * @param None
  * @retval None
  */
void UpdateModbusTimer(){
	MODBUS_RS485_TIMER_ADDR = HAL_GetTick() - modbusTimer;
}

BOOLEAN IsRS485PhyConnected(){
	return AT_TRUE;
}

BOOLEAN IsRS485ConnectionAvailable(){
	return AT_TRUE;
}

/*	DMA
#include "../Inc/modbus.h"
#include "Modbus/modbusManager.h"
#include "stm32f7xx_hal.h"
#include "stdlib.h"
#include "string.h"

#define BUFFER_SIZE 255
#define MODBUS_MIN_PCKG_LEN 2

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;

uint8_t receiveBuff[BUFFER_SIZE];

void Modbus_UART_IDLECallback();
BOOLEAN WriteModbusRS485(BYTE* pData, WORD size);

void UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(huart->Instance==USART2)
  {
    // Peripheral clock enable
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    //	USART2 GPIO Configuration
    //	PD4     ------> USART2_DE
    //	PD5     ------> USART2_TX
    //	PD6     ------> USART2_RX

    GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    // USART2 DMA Init
    // USART2_RX Init
    hdma_usart2_rx.Instance = DMA1_Stream5;
    hdma_usart2_rx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_rx.Init.Mode = DMA_NORMAL;
    hdma_usart2_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart2_rx.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
    hdma_usart2_rx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
    hdma_usart2_rx.Init.MemBurst = DMA_MBURST_SINGLE;
    hdma_usart2_rx.Init.PeriphBurst = DMA_PBURST_SINGLE;
    if (HAL_DMA_Init(&hdma_usart2_rx) != HAL_OK)
    {

    }

    __HAL_LINKDMA(huart,hdmarx,hdma_usart2_rx);

    // USART2_TX Init
    hdma_usart2_tx.Instance = DMA1_Stream6;
    hdma_usart2_tx.Init.Channel = DMA_CHANNEL_4;
    hdma_usart2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_tx.Init.Mode = DMA_NORMAL;
    hdma_usart2_tx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart2_tx.Init.FIFOMode = DMA_FIFOMODE_ENABLE;
    hdma_usart2_tx.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_FULL;
    hdma_usart2_tx.Init.MemBurst = DMA_MBURST_SINGLE;
    hdma_usart2_tx.Init.PeriphBurst = DMA_PBURST_SINGLE;
    if (HAL_DMA_Init(&hdma_usart2_tx) != HAL_OK)
    {

    }

    __HAL_LINKDMA(huart,hdmatx,hdma_usart2_tx);

    //USART2 interrupt Init
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  }

}


//Enable DMA controller clock
static void UART_DMA_Init(void)
{
  // DMA controller clock enable
  __HAL_RCC_DMA1_CLK_ENABLE();

  // DMA interrupt init
  // DMA1_Stream5_IRQn interrupt configuration
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
  // DMA1_Stream6_IRQn interrupt configuration
  HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);
}

void MB_HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
	__HAL_UART_DISABLE_IT(&huart2,UART_IT_RTO);
	__HAL_UART_CLEAR_IT(&huart2,UART_CLEAR_RTOF);
	HAL_UART_DisableReceiverTimeout(&huart2);

	Modbus_UART_IDLECallback();
}

void MB_HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	__HAL_UART_DISABLE_IT(&huart2,UART_IT_RTO);
	__HAL_UART_CLEAR_IT(&huart2,UART_CLEAR_RTOF);
	HAL_UART_DisableReceiverTimeout(&huart2);
}

static void USART2_UART_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 19200; //38400
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_RS485Ex_Init(&huart2, UART_DE_POLARITY_HIGH, 0, 0) != HAL_OK)
  {

  }

}

void InitModbusRS485(void){
	UART_DMA_Init();
	huart2.MspInitCallback = UART_MspInit;
	USART2_UART_Init();
	//__HAL_UART_ENABLE_IT(&huart2, UART_IT_IDLE);

	InitModbus();
	modbusRS485Comm.Send = WriteModbusRS485;

	//
	// Registro la Caalback di fine ricezione
	HAL_UART_RegisterCallback(&huart2,HAL_UART_RX_COMPLETE_CB_ID,MB_HAL_UART_RxCpltCallback);
	HAL_UART_RegisterCallback(&huart2,HAL_UART_ERROR_CB_ID,MB_HAL_UART_ErrorCallback);

}

void PollingInitDma(){
	//__HAL_UART_CLEAR_IDLEFLAG(&huart2);
	//HAL_UART_Receive_DMA(&huart2, (uint8_t*)receiveBuff, BUFFER_SIZE);

	__HAL_UART_DISABLE_IT(&huart2,UART_IT_RTO);
	__HAL_UART_CLEAR_IT(&huart2,UART_CLEAR_RTOF);
	HAL_UART_DisableReceiverTimeout(&huart2);

	// Avvio il Timeout di fine Ricezione: Modbus Standard: 3.5 char = 28bit
	HAL_UART_ReceiverTimeout_Config(&huart2, 28);

	if(HAL_UART_EnableReceiverTimeout(&huart2) == HAL_OK ){
		// Clear RTO Flag
		__HAL_UART_CLEAR_FLAG(&huart2,UART_CLEAR_RTOF);
		__HAL_UART_CLEAR_IT(&huart2,UART_CLEAR_RTOF);
		// Aabilito l'interrupt
		__HAL_UART_ENABLE_IT(&huart2,UART_IT_RTO);

		HAL_UART_Receive_DMA(&huart2, (uint8_t*)receiveBuff, BUFFER_SIZE);
	}
}


void USER_UART_IRQHandler(UART_HandleTypeDef *myhuart)
{
    if(huart2.Instance == USART2)                      //Determine whether it is serial port 1
    {
        if(RESET != __HAL_UART_GET_FLAG(&huart2, UART_FLAG_IDLE))   //Judging whether it is idle interruption
        {
            __HAL_UART_CLEAR_IDLEFLAG(&huart2);                     //Clear idle interrupt sign (otherwise it will continue to enter interrupt)
            //Modbus_UART_IDLECallback();                           	//Call interrupt handler
        }
    }
}

//int count  = 0;
void Modbus_UART_IDLECallback()
{
	__HAL_UART_CLEAR_IDLEFLAG(&huart2);

	//Stop this DMA transmission
    HAL_UART_DMAStop(&huart2);

    //Calculate the length of the received data
    uint8_t data_length  = BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart2_rx);

    if(data_length > MODBUS_MIN_PCKG_LEN && data_length < BUFFER_SIZE && modbusRS485Comm.ReceiveClbk){
    	modbusRS485Comm.ReceiveClbk(receiveBuff, data_length);
    	//printf("Dato ricevuto: %d %d %d %d %d %d %d\n", receiveBuff[0],
		//receiveBuff[1], receiveBuff[2], receiveBuff[3], receiveBuff[4],
		//receiveBuff[5], receiveBuff[6]);
    }

	//Zero Receiving Buffer
    data_length = 0;

   // __HAL_UART_DISABLE_IT(&huart2, UART_IT_IDLE);
}

BOOLEAN WriteModbusRS485(BYTE* pData, WORD size){
	BYTE wrData[size];
	memcpy(wrData, pData, sizeof(BYTE) * size);
	//memset(receiveBuff, 0, sizeof(uint8_t) * BUFFER_SIZE);
	PollingInitDma();
	return HAL_UART_Transmit_DMA(&huart2, wrData, size) == HAL_OK;
}

*/
