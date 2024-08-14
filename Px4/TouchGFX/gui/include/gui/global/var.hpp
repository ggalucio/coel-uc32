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
// Screen Congelar
extern double SP_SONDA_CONGELAR_CAMARA;
extern double Diferencial_Congelar_tempo;
extern double Timer_Congelar_DECORRIDO_SP;
extern double Timer_Congelar_DECORRIDO_ON;
extern bool flag_Processo_ANDAMENTO;
extern bool Timer_delay_ON;
extern bool flag_alarm_receita_vazia;
extern double Status_tecla_Congela;

// Script 2
extern bool Timer_Congelar_DECORRIDO_OUT;
extern bool flag_Conservar_S_N;
extern bool flag_transicao_Conservar;
extern bool flag_Conservar_Cong_Resf;
extern bool Timer_buzzer_ON;
extern double Timer_delay_OUT;

//
extern double SP_SONDA_RESF_CAMARA;
extern double SP_Resfriar_Sonda;
extern double SP_Resfriar_Tempo_SOFT;
extern double Diferencial_Resfriar_Tempo;
extern double SP_Resf_Hard_Interno_display;
extern double SP_Resf_Hard_Espeto_display;
extern double SP_Resf_Interno_F1;
extern double SP_Resf_Interno_F2;
extern double SP_Resf_Espeto_F1;
extern double SP_Resf_Espeto_F2;
extern double Hard_Resf_fase_numero;
extern double Dif_Resf_Hard_F1;
extern double Dif_Resf_Hard_F2;
extern double Timer_SP_MINUTOS_Resfriar;
extern double Preset_Resf_Tempo_F1;
extern double Preset_Resf_Tempo_F2;
extern double Porc_Resf_preset_tempo_F1F2;
extern bool xBeep_once;
extern bool flag_Resfriar_HARD_SOFT;
extern double W_HSW9;
extern double Timer_buzzer_SP;
extern double W_HAW8000;
extern double Timer_COUNT_MINUTOS;
extern double Timer_Delay_SP;
extern double Timer_Degelo_SP;
extern double Timer_degelo_delay_SP;
extern double numero_receita;
extern double initial_value;
extern double Timer_SP_MINUTOS;
extern double SP_Conservar_Congelar;
extern double Diferencial_Conservar_COngelar;
extern double SP_Conservar_Resfriar;
extern double Diferencial_Conservar_Resfriar;
extern double CONGELAR_SONDA_SP;
extern double SP_Congelar_Tempo;
extern double SP_Resfriar_Tempo_HARD;
extern double logica_entrada_digital1;
extern double logica_entrada_digital2;
extern double timer_alarme_externo_SP_MINUTOS;
extern double Timer_Alarme_externo_SP;
extern double flag_hab_desab_Tecla_REDIAL;
extern double Senha_Gravada;
extern double Tempo_receita_1;
extern double Tempo_receita_2;
extern double Tempo_receita_3;
extern double Tempo_receita_4;
extern double Tempo_receita_5;
extern double Tempo_receita_6;
extern double Tempo_receita_7;
extern double Tempo_receita_8;
extern double Tempo_receita_9;
extern double Tempo_receita_10;
extern double Tempo_receita_11;
extern double Tempo_receita_12;
extern bool degelo_porta_aberta;
extern bool degelo_processo_automatico;
extern double Timer_Congelar_DECORRIDO_COUNT;
extern double Timer_Degelo_COUNT_MINUTOS;
extern double Timer_degelo_COUNT;
extern double Timer_higiene_MIN;
extern double Timer_higiene_COUNT;
extern double flag_alarme_externo_andamento;
extern double flag_alarme_externo;
extern double Timer_alarme_externo_ON;
extern double Tempo_estimado_Congelar_SONDA;
extern double Tempo_estimado_Resfriar_Sonda;
extern double Tempo_Estimado_Receita_Temperat;
extern double Timer_Buzzer_COUNT;
extern double Timer_BUzzer_OUT;
extern double Timer_buzzer_DEG_ON;
extern double Timer_Buzzer_DEG_COUNT;
extern bool Timer_BUzzer_DEG_OUT;
extern double Timer_Delay_COUNT;
extern double Timer_degelo_delay_ON;
extern double Timer_degelo_delay_COUNT;
extern bool Timer_degelo_delay_OUT;
extern double Timer_Degelo_CONTROL;
extern double Timer_Alarme_externo_COUNT;
extern double timer_higiene_ON;
extern bool Timer_Degelo_OUT;
extern bool Timer_alarme_externo_OUT;
extern bool timer_higiene_OUT;
extern bool HSW4;
extern bool reset_fabrica;
extern bool cancelar_processo_SIM;
extern double xbar_zero;
extern double W_HDW5000;
extern bool flag_Conservar_ANDAMENTO;
extern double Status_Conservar;
extern double Receita_Cong_Resf_ATUAL;

#endif /* GUI_INCLUDE_GUI_GLOBAL_VAR_HPP_ */
