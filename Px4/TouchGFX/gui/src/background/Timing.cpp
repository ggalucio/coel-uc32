/*
 * Timing.cpp
 *
 *  Created on: 8 de ago de 2024
 *      Author: COELMATIC2022
 */

#include <gui/background/Timing.hpp>
#include <gui/model/ModelListener.hpp>


void Cycle50()
{
	if (pTimingApplication != NULL)
		pTimingApplication->cycle50();
}

void Cycle500()
{
	if (pTimingApplication != NULL)
		pTimingApplication->cycle500();
}

void Cycle25()
{
	if (pTimingApplication != NULL)
		pTimingApplication->cycle25();
}

void TIMER_1S()
{
	if (pTimingApplication != NULL)
		pTimingApplication->timer_1S();
}

void TIMER_10S()
{
	if (pTimingApplication != NULL)
		pTimingApplication->timer_10S();
}

void TimeCongelarDecorridoOutCheck(){
	if (pTimingApplication != NULL)
		pTimingApplication->TimeCongelarDecorridoOutCheck();
}

void FlagCongelarTempoCheck(){
	if (pTimingApplication != NULL)
		pTimingApplication->FlagCongelarTempoCheck();
}
