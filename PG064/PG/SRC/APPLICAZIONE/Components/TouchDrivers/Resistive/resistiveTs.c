/*
 * resistiveTs.c
 *
 *  Created on: 10 set 2021
 *      Author: paoloc
 */

#include "resistiveTs.h"
#include "Utils/utils.h"

/************ PRIVATE VARIABLES ************/

/**
 *  Resistive touch screen driver structure initialization
*/
TS_DrvTypeDef resistive_ts_drv = {
		resistive_Init,
		resistive_ReadID,
		resistive_TS_Start,
		resistive_TS_DetectTouch,
		resistive_TS_SetTsPeriphDrv
};

/**
 *  Resistive touch screen driver peripheral structure.
*/
TS_DrvPeriphTypeDef *res_ts_periph_drv;

/**
 * Resistive structure with raw and panel coordinates.
 */
TsResistivePanel resistivePanel;

/*TsCoord coords1 = {{1010, 1130}, {96, 55}};
TsCoord coords2 = {{3170, 1070}, {384, 55}};
TsCoord coords3 = {{2110, 2170}, {240, 136}};
TsCoord coords4 = {{1010, 3110}, {96, 218}};
TsCoord coords5 = {{3170, 3120}, {384, 218}};*/

/**
* Coordinates reading from ADC [mV]
*/
TsCoord coords1 = {{1002, 1275}, {96, 55}};
TsCoord coords2 = {{3130, 1265}, {384, 55}};
TsCoord coords3 = {{2075, 2125}, {240, 136}};
TsCoord coords4 = {{1025, 3010}, {96, 218}};
TsCoord coords5 = {{3180, 3045}, {384, 218}};

/**
* Change reference base parameters.
*/
double A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;

/**
* Touch detection and reading coordinates states enumerators.
*/
typedef enum{
	DETECTION_MODE,
	DETECT,
	READX,
	READY,
	UPDATECOORDS
}ResistiveTSSequenceTypeDef;

/**
* Machine state for touch detection and reading coordinates.
*/
ResistiveTSSequenceTypeDef resistiveTsSeq;

/**
* @brief Resistive Touch Screen base change
* This function finds parameters for changing reference base.
*/
void CalcParameters(){
	uint64_t alpha = coords1.Raw.X * coords1.Raw.X +
			coords2.Raw.X * coords2.Raw.X +
			coords3.Raw.X * coords3.Raw.X +
			coords4.Raw.X * coords4.Raw.X +
			coords5.Raw.X * coords5.Raw.X;
	uint64_t beta = coords1.Raw.Y * coords1.Raw.Y +
			coords2.Raw.Y * coords2.Raw.Y +
			coords3.Raw.Y * coords3.Raw.Y +
			coords4.Raw.Y * coords4.Raw.Y +
			coords5.Raw.Y * coords5.Raw.Y;
	uint64_t chi = coords1.Raw.X * coords1.Raw.Y +
			coords2.Raw.X * coords2.Raw.Y +
			coords3.Raw.X * coords3.Raw.Y +
			coords4.Raw.X * coords4.Raw.Y +
			coords5.Raw.X * coords5.Raw.Y;
	uint64_t epsilon 	= coords1.Raw.X + 	coords2.Raw.X + coords3.Raw.X + coords4.Raw.X + coords5.Raw.X;
	uint64_t phi 		= coords1.Raw.Y + 	coords2.Raw.Y + coords3.Raw.Y + coords4.Raw.Y + coords5.Raw.Y;
	uint64_t kx 		= coords1.Raw.X * coords1.Display.X +
			coords2.Raw.X * coords2.Display.X +
			coords3.Raw.X * coords3.Display.X +
			coords4.Raw.X * coords4.Display.X +
			coords5.Raw.X * coords5.Display.X;
	uint64_t Ix	= coords1.Raw.Y * coords1.Display.X +
			coords2.Raw.Y * coords2.Display.X +
			coords3.Raw.Y * coords3.Display.X +
			coords4.Raw.Y * coords4.Display.X +
			coords5.Raw.Y * coords5.Display.X;

	uint64_t mx = coords1.Display.X + 	coords2.Display.X + coords3.Display.X + coords4.Display.X + coords5.Display.X;
	uint64_t my = coords1.Display.Y + 	coords2.Display.Y + coords3.Display.Y + coords4.Display.Y + coords5.Display.Y;

	uint64_t ky = coords1.Raw.X * coords1.Display.Y +
			coords2.Raw.X * coords2.Display.Y +
			coords3.Raw.X * coords3.Display.Y +
			coords4.Raw.X * coords4.Display.Y +
			coords5.Raw.X * coords5.Display.Y;
	uint64_t Iy	= coords1.Raw.Y * coords1.Display.Y +
			coords2.Raw.Y * coords2.Display.Y +
			coords3.Raw.Y * coords3.Display.Y +
			coords4.Raw.Y * coords4.Display.Y +
			coords5.Raw.Y * coords5.Display.Y;

	long long d = 5 * (alpha * beta - chi * chi) + 2 * chi * epsilon * phi - alpha * phi * phi - beta * epsilon * epsilon;
	long long dx1 = 5 * (kx * beta - Ix * chi) + phi * (Ix * epsilon - kx * phi) + mx * (chi * phi - beta * epsilon);
	long long dx2 = 5 * (Ix * alpha - kx * chi) + epsilon * (kx * phi - Ix * epsilon) + mx * (chi * epsilon - alpha * phi);
	long long dx3 = kx * (chi * phi - beta * epsilon) + Ix * (chi * epsilon - alpha * phi) + mx * (alpha * beta - chi * chi);
	long long dy1 = 5 * (ky * beta - Iy * chi) + phi * (Iy * epsilon - ky * phi) + my * (chi * phi - beta * epsilon);
	long long dy2 = 5 * (Iy * alpha - ky * chi) + epsilon * (ky * phi - Iy * epsilon) + my * (chi * epsilon - alpha * phi);
	long long dy3 = ky * (chi * phi - beta * epsilon) + Iy * (chi * epsilon - alpha * phi) + my * (alpha * beta - chi * chi);

	A = (double)dx1 / (double)d;
	B = (double)dx2 / (double)d;
	C = (double)dx3 / (double)d;
	D = (double)dy1 / (double)d;
	E = (double)dy2 / (double)d;
	F = (double)dy3 / (double)d;
}

/**
* @brief Resistive Touch Screen initializer
* This function detects if resistive driver is connected.
* @retval 1 if device is found, 0 otherwise
*/
uint8_t resistive_Init(){
	CalcParameters();
	if(res_ts_periph_drv){
		res_ts_periph_drv->Init();
		resistiveTsSeq = DETECTION_MODE;
		return AT_TRUE;
	}
	else{
		return AT_FALSE;
	}
}

/**
* @brief Resistive Touch Screen reset
* This function resets resistive touch screen driver (NOT USED)
*/
void 	resistive_Reset(){

}

/**
* @brief Resistive Touch Screen ID reader
* This function reads resistive touch screen driver ID
* @retval: 1 (it is not expected for this driver)
*/
uint8_t resistive_ReadID(){
	return AT_TRUE;
}

/**
* @brief Resistive Touch Screen initializer
* This function initializes resistive touch screen driver
*/
void 	resistive_TS_Start(){
	if(res_ts_periph_drv)
		return res_ts_periph_drv->Delay(10);
}

/**
* @brief Resistive Touch Screen detection
* This function start touch detection mode.
*/
void DetectionModeSeq(){
	res_ts_periph_drv->Read(RESISTIVE_CHANGE_SEQ_CMD, RESISTIVE_TOUCH_SEQUENCE, MEMADD_SIZE_NONE);
	resistiveTsSeq = DETECT;
}

/**
* @brief Resistive Touch Screen detection
* This function start reading X raw coordinate.
*/
void ReadXModeSeq(){
	res_ts_periph_drv->Read(RESISTIVE_CHANGE_SEQ_CMD, RESISTIVE_READX_SEQUENCE, MEMADD_SIZE_NONE);
}

/**
* @brief Resistive Touch Screen detection
* This function start reading Y raw coordinate.
*/
void ReadYModeSeq(){
	res_ts_periph_drv->Read(RESISTIVE_CHANGE_SEQ_CMD, RESISTIVE_READY_SEQUENCE, MEMADD_SIZE_NONE);
}

/**
* @brief Resistive Touch Screen detection
* This function detects if touch occurs. If so, start launches mode for reading coordinates.
*/
void DetectStatus(){
	uint8_t isTouched = res_ts_periph_drv->Read(RESISTIVE_READ_TOUCH_CMD,0, MEMADD_SIZE_NONE);

	if(isTouched){
		resistiveTsSeq = READY;
	}
	else{
		resistivePanel.TouchNum = 0;
		resistivePanel.SampleNum = 0;
		resistiveTsSeq = DETECT;
	}
}

/**
* @brief Resistive Touch Screen detection
* This function reads X raw coordinate.
*/
void ReadXStatus(){
	// Aggiorno la sequenza per la lettura della coordinata X.
	ReadXModeSeq();

	// Lettura della coordinata RAW di X.
	resistivePanel.CoordsT0.Raw.X = res_ts_periph_drv->Read(RESISTIVE_READ_X_COORD_CMD, 0, MEMADD_SIZE_NONE);
	resistiveTsSeq = UPDATECOORDS;
}

/**
* @brief Resistive Touch Screen detection
* This function reads Y raw coordinate.
*/
void ReadYStatus(){
	// Aggiorno la sequenza per la lettura della coordinata Y.
	ReadYModeSeq();

	// Lettura della coordinata RAW di Y.
	resistivePanel.CoordsT0.Raw.Y = res_ts_periph_drv->Read(RESISTIVE_READ_Y_COORD_CMD, 0, MEMADD_SIZE_NONE);
	resistiveTsSeq = READX;
}

/**
* @brief Resistive Touch Screen detection
* This function applies conversion from raw to panel coordinates.
*/
void UpdateCoords(){
	resistiveTsSeq = DETECTION_MODE;

	// Aggiornamento valori coordinate display all'istante T1
	resistivePanel.CoordsT1.Display.X 	= resistivePanel.CoordsT0.Display.X;
	resistivePanel.CoordsT1.Display.Y 	= resistivePanel.CoordsT0.Display.Y;

	// Aggiornamento valori coordinate display all'istante T0
	resistivePanel.CoordsT0.Display.X = A * resistivePanel.CoordsT0.Raw.X + B * resistivePanel.CoordsT0.Raw.Y + C;
	resistivePanel.CoordsT0.Display.Y = D * resistivePanel.CoordsT0.Raw.X + E * resistivePanel.CoordsT0.Raw.Y + F;

	// Aggiornamento contatori
	if(resistivePanel.SampleNum > 0)
		resistivePanel.TouchNum = 1;

	resistivePanel.SampleNum++;
}

/**
* @brief Resistive Touch Screen detection
* This function detects resistive screen touch and retrieves coordinates.
* @param X: X coordinate.
* @param X: Y coordinate
* @retval: 1 if a touch occurred, 0 otherwise
*/
uint8_t resistive_TS_DetectTouch(uint16_t *X, uint16_t *Y){

	if(!res_ts_periph_drv)
		return 0;

	switch(resistiveTsSeq){
		case DETECTION_MODE:	DetectionModeSeq(); 			break;
		case DETECT:			DetectStatus();					break;
		case READX:				ReadXStatus();					break;
		case READY:				ReadYStatus();					break;
		case UPDATECOORDS:		UpdateCoords();					break;
		default:				resistivePanel.TouchNum = 0;	break;
	}

	// Se è stato rilevato un contatto, aggiorno i valori
	// delle coordinate all'istante T1.
	if(resistivePanel.TouchNum){
		*X = resistivePanel.CoordsT1.Display.X;
		*Y = resistivePanel.CoordsT1.Display.Y;
	}

	return resistivePanel.TouchNum;
}

/**
* @brief Resistive Touch Screen peripheral driver setter
* This function sets appropriate peripheral driver for resistive touch screen
* @param periph_drv: peripheral driver for resistive touch screen.
*/
void	resistive_TS_SetTsPeriphDrv(TS_DrvPeriphTypeDef* periph_drv){
	res_ts_periph_drv = periph_drv;
}
