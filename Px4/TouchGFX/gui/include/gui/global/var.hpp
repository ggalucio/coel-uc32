/*
 * var.hpp
 *
 *  Created on: 16 de jul de 2024
 *      Author: COELMATIC2022
 */

#ifndef GUI_INCLUDE_GUI_GLOBAL_VAR_HPP_
#define GUI_INCLUDE_GUI_GLOBAL_VAR_HPP_

#include <stdint.h>

extern uint8_t selectedRecipeListPage;
extern uint8_t selectedRecipeItem;
extern int countCycleBlink;
extern bool isZeroValue;

// Scripts Global Variables
//Screen Congelar
extern int SP_SONDA_CONGELAR_CAMARA;
extern int Diferencial_Congelar_tempo;
extern int Timer_Congelar_DECORRIDO_SP;
extern int Timer_Congelar_DECORRIDO_ON;
extern bool flag_Processo_ANDAMENTO;
extern bool Timer_delay_ON;
extern bool flag_alarm_receita_vazia;
extern bool Status_tecla_Congela;

//Script 2
extern bool Timer_Congelar_DECORRIDO_OUT;
extern int flag_Conservar_S_N;
extern bool flag_transicao_Conservar;
extern bool flag_Conservar_Cong_Resf;
extern bool flag_Processo_ANDAMENTO;
extern bool Timer_buzzer_ON;
extern bool Timer_delay_OUT;




#endif /* GUI_INCLUDE_GUI_GLOBAL_VAR_HPP_ */
