/*
 * dma2D.c
 *
 *  Created on: Dec 14, 2021
 *      Author: paoloc
 */

#include "../Inc/dma2D.h"

DMA2D_HandleTypeDef hdma2d;

BOOLEAN InitDma2D(void){
	hdma2d.Instance = DMA2D;
	hdma2d.Init.Mode = DMA2D_M2M;
	hdma2d.Init.ColorMode = DMA2D_OUTPUT_ARGB8888;
	hdma2d.Init.OutputOffset = 0;
	hdma2d.LayerCfg[1].InputOffset = 0;
	hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_ARGB8888;
	hdma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
	hdma2d.LayerCfg[1].InputAlpha = 0;
	if (HAL_DMA2D_Init(&hdma2d) != HAL_OK)
	{
		return AT_FALSE;
	}

	return HAL_DMA2D_ConfigLayer(&hdma2d, 1) == HAL_OK;
}

BOOLEAN DeInitDma2D(void){
	return HAL_DMA2D_DeInit(&hdma2d) == HAL_OK;
}
