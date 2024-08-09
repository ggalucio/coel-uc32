/*
 * Timing.hpp
 *
 *  Created on: 8 de ago de 2024
 *      Author: COELMATIC2022
 */

#ifndef GUI_INCLUDE_GUI_BACKGROUND_TIMING_HPP_
#define GUI_INCLUDE_GUI_BACKGROUND_TIMING_HPP_

extern "C" void Cycle50(void);
extern "C" void Cycle500(void);
extern "C" void Cycle25(void);
extern "C" void TIMER_1S(void);
extern "C" void TIMER_10S(void);

void Cycle50(void);
void Cycle500(void);
void Cycle25(void);
void TIMER_1S(void);
void TIMER_10S(void);

#endif /* GUI_INCLUDE_GUI_BACKGROUND_TIMING_HPP_ */
