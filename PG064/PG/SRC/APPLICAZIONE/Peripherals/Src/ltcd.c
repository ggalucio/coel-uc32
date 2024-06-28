// ===========================================================================
// ####DESCRIPTION BEGIN####
//
//! \author     Paolo Codecasa
//!
//! \note
//! Riferimenti Aziendali:						\n
//! AsconTecnologic S.r.l.                   	\n
//! Via Indipendenza 56                       	\n
//! 27029, Vigevano                         	\n
//! Pavia                                   	\n
//! Italy                                    	\n
//!
//! \brief Functions for setting display parameters
//!
//! \file ltcd.c
//!
//! \date       14-12-2021
//! \author     Paolo Codecasa
//! \note       Prima Emissione
//!
// ###DESCRIPTION END####
// ===========================================================================

/************ INCLUDES ************/
#include "../Inc/ltcd.h"
#include "display_config.h"

/************ PRIVATE VARIABLES ************/
LTDC_HandleTypeDef hltdc;

/************ PUBLIC FUNCTIONS DEFINITION ************/

//---------------------------------------------------------------------------
//
// Function:    InitLtcd()
//
// Description: function for initialize LTCD module
//
// Parameters:  None
//
// Return:      BOOLEAN     =   AT_TRUE if initialization was successful
//							=   AT_FALSE otherwise
//
//
//---------------------------------------------------------------------------
BOOLEAN InitLtcd(){

	LTDC_LayerCfgTypeDef pLayerCfg = {0};

	// 4 pollici
#ifdef USE_DISPLAY_4
	hltdc.Instance = LTDC;
	hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
	hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
	hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
	hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
	hltdc.Init.HorizontalSync = 40;
	hltdc.Init.VerticalSync = 9;
	hltdc.Init.AccumulatedHBP = 53;
	hltdc.Init.AccumulatedVBP = 11;
	hltdc.Init.AccumulatedActiveW = 533;
	hltdc.Init.AccumulatedActiveH = 283;
	hltdc.Init.TotalWidth = 565;
	hltdc.Init.TotalHeigh = 285;
	hltdc.Init.Backcolor.Blue = 0;
	hltdc.Init.Backcolor.Green = 0;
	hltdc.Init.Backcolor.Red = 0;
	if (HAL_LTDC_Init(&hltdc) != HAL_OK)
	{
		return AT_FALSE;
	}

	pLayerCfg.WindowX0 = 0;
	pLayerCfg.WindowX1 = 480;
	pLayerCfg.WindowY0 = 0;
	pLayerCfg.WindowY1 = 272;
	pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
	pLayerCfg.Alpha = 255;
	pLayerCfg.Alpha0 = 0;
	pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
	pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
	pLayerCfg.FBStartAdress = 0xC0000000;
	pLayerCfg.ImageWidth = 480;
	pLayerCfg.ImageHeight = 272;
	pLayerCfg.Backcolor.Blue = 0;
	pLayerCfg.Backcolor.Green = 0;
	pLayerCfg.Backcolor.Red = 0;
	return HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) == HAL_OK;
#endif

	// 7 pollici
#ifdef USE_DISPLAY_7
	hltdc.Instance = LTDC;
	hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
	hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
	hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
	hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
	hltdc.Init.HorizontalSync = 29;
	hltdc.Init.VerticalSync = 5;
	hltdc.Init.AccumulatedHBP = 189;
	hltdc.Init.AccumulatedVBP = 28;
	hltdc.Init.AccumulatedActiveW = 1213;
	hltdc.Init.AccumulatedActiveH = 628;
	hltdc.Init.TotalWidth = 1373;
	hltdc.Init.TotalHeigh = 635;
	hltdc.Init.Backcolor.Blue = 0;
	hltdc.Init.Backcolor.Green = 0;
	hltdc.Init.Backcolor.Red = 0;
	if (HAL_LTDC_Init(&hltdc) != HAL_OK)
	{
		return AT_FALSE;
	}

	pLayerCfg.WindowX0 = 0;
	pLayerCfg.WindowX1 = 1024;
	pLayerCfg.WindowY0 = 0;
	pLayerCfg.WindowY1 = 600;
	pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
	pLayerCfg.Alpha = 255;
	pLayerCfg.Alpha0 = 0;
	pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
	pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
	pLayerCfg.FBStartAdress = 0xC0000000;
	pLayerCfg.ImageWidth = 1024;
	pLayerCfg.ImageHeight = 600;
	pLayerCfg.Backcolor.Blue = 0;
	pLayerCfg.Backcolor.Green = 0;
	pLayerCfg.Backcolor.Red = 0;
	return HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) == HAL_OK;
#endif

}

//---------------------------------------------------------------------------
//
// Function:    DeInitLtcd()
//
// Description: function for deinitialize LTCD module
//
// Parameters:  None
//
// Return:      BOOLEAN     =   AT_TRUE if initialization was successful
//							=   AT_FALSE otherwise
//
//
//---------------------------------------------------------------------------
BOOLEAN DeInitLtcd(){
	return HAL_LTDC_DeInit(&hltdc) == HAL_OK;
}
