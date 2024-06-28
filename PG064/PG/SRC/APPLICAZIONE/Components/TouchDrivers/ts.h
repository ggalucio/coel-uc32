/**
 ******************************************************************************
 * @file    ts.h
 * @author  MCD Application Team
 * @version V4.0.1
 * @date    21-July-2015
 * @brief   This file contains all the functions prototypes for the Touch Screen driver.
 ******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TS_H
#define __TS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

#define MEMADD_SIZE_NONE            (0x00000000U)
#define MEMADD_SIZE_8BIT            (0x00000001U)
#define MEMADD_SIZE_16BIT           (0x00000002U)

typedef struct {
	uint8_t    (*Init)(void);
	uint8_t    (*DeviceReady)(uint16_t);
	void       (*Write)(uint8_t, uint16_t, uint16_t, uint8_t);
	uint16_t   (*Read)(uint8_t, uint16_t, uint16_t);
	uint8_t    (*ReadMultiple)(uint8_t, uint16_t, uint16_t, uint8_t*, uint8_t);
	void       (*Delay)(uint32_t);
	void       (*Error)(void);
	uint8_t	   (*GetStatus)(void);
}TS_DrvPeriphTypeDef;

typedef struct {
	uint8_t    (*Init)(void);
	uint8_t    (*ReadID)(void);
	void       (*Start)(void);
	uint8_t    (*DetectTouch)(uint16_t*, uint16_t*);
	void	   (*SetTsPeriphDrv)(TS_DrvPeriphTypeDef*);

}TS_DrvTypeDef;

typedef struct{
	uint16_t X;
	uint16_t Y;
}Coord;

typedef struct{
	uint8_t  nTouch;
	Coord Coord;
}TS_DetectTypeDef;

typedef struct{
	Coord Raw;
	Coord Display;
}TsCoord;

typedef struct{
	uint8_t TouchNum;
	uint8_t SampleNum;
	TsCoord CoordsT0;
	TsCoord CoordsT1;
}TsResistivePanel;

TS_DetectTypeDef ts_Detector;

void TouchScreenRun(void);

#ifdef __cplusplus
}
#endif

#endif /* __TS_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

