/*
 * var.cpp
 *
 *  Created on: 16 de jul de 2024
 *      Author: COELMATIC2022
 */

#include "gui/global/var.hpp"

uint8_t selectedRecipeListPage			= 0;
uint8_t selectedRecipeItem				= 0;
int countCycleBlink						= 0;
bool isZeroValue						= false;

// Scripts Global Variables
// Screen Congelar
double SP_SONDA_CONGELAR_CAMARA			= 0; //-250;
double Diferencial_Congelar_tempo		= 0;//30;
double Timer_Congelar_DECORRIDO_SP 		= 0;
double Timer_Congelar_DECORRIDO_ON 		= 0;
bool flag_Processo_ANDAMENTO			= false;
bool Timer_delay_ON						= false;
bool flag_alarm_receita_vazia			= true;
double Status_tecla_Congela				= true;

// Script 2
bool Timer_Congelar_DECORRIDO_OUT		= false;
bool flag_Conservar_S_N					= false;
bool flag_transicao_Conservar			= false;
bool flag_Conservar_Cong_Resf			= false;
bool Timer_buzzer_ON 					= false;
double Timer_delay_OUT 					= 0;

//
double SP_SONDA_RESF_CAMARA				= 0;
double SP_Resfriar_Sonda				= 0;
double SP_Resfriar_Tempo_SOFT			= 0;
double Diferencial_Resfriar_Tempo		= 0;
double SP_Resf_Hard_Interno_display		= 0;
double SP_Resf_Hard_Espeto_display		= 0;
double SP_Resf_Interno_F1				= 0;
double SP_Resf_Interno_F2				= 0;
double SP_Resf_Espeto_F1				= 0;
double SP_Resf_Espeto_F2				= 0;
double Hard_Resf_fase_numero			= 0;
double Dif_Resf_Hard_F1					= 0;
double Dif_Resf_Hard_F2					= 0;
double Timer_SP_MINUTOS_Resfriar		= 0;
double Preset_Resf_Tempo_F1				= 0;
double Preset_Resf_Tempo_F2				= 0;
double Porc_Resf_preset_tempo_F1F2		= 0;
bool xBeep_once							= false;
bool flag_Resfriar_HARD_SOFT			= false;
double W_HSW9 							= 0;
double Timer_buzzer_SP 					= 0;
double W_HAW8000 						= 0;
double Timer_COUNT_MINUTOS 				= 0;
double Timer_Delay_SP 					= 0;
double Timer_Degelo_SP 					= 0;
double Timer_degelo_delay_SP 			= 0;
double numero_receita					= 0;
double initial_value					= 0;
double Timer_SP_MINUTOS					= 0;
double SP_Conservar_Congelar			= 0;
double Diferencial_Conservar_COngelar	= 5;
double SP_Conservar_Resfriar			= 0;
double Diferencial_Conservar_Resfriar	= 0;
double CONGELAR_SONDA_SP				= 0;
double SP_Congelar_Tempo				= 0;
double SP_Resfriar_Tempo_HARD			= 0;
double logica_entrada_digital1			= 1;
double logica_entrada_digital2			= 0;
double timer_alarme_externo_SP_MINUTOS	= 0;
double Timer_Alarme_externo_SP			= 0;
double flag_hab_desab_Tecla_REDIAL		= 0;
double Senha_Gravada					= 123;
double Tempo_receita_1					= 0;
double Tempo_receita_2					= 0;
double Tempo_receita_3					= 0;
double Tempo_receita_4					= 0;
double Tempo_receita_5					= 0;
double Tempo_receita_6					= 0;
double Tempo_receita_7					= 0;
double Tempo_receita_8					= 0;
double Tempo_receita_9					= 0;
double Tempo_receita_10					= 0;
double Tempo_receita_11					= 0;
double Tempo_receita_12					= 0;
bool degelo_porta_aberta				= false;
bool degelo_processo_automatico			= false;
double Timer_Congelar_DECORRIDO_COUNT	= 0;
double Timer_Degelo_COUNT_MINUTOS		= 0;
double Timer_degelo_COUNT				= 0;
double Timer_higiene_MIN				= 0;
double Timer_higiene_COUNT				= 0;
double flag_alarme_externo_andamento	= 0;
double flag_alarme_externo				= 0;
double Timer_alarme_externo_ON			= 0;
double Tempo_estimado_Congelar_SONDA 	= 0;
double Tempo_estimado_Resfriar_Sonda 	= 0;
double Tempo_Estimado_Receita_Temperat	= 0;
double Timer_Buzzer_COUNT				= 0;
double Timer_BUzzer_OUT					= 0;
double Timer_buzzer_DEG_ON				= 0;
double Timer_Buzzer_DEG_COUNT			= 0;
bool Timer_BUzzer_DEG_OUT				= false;
double Timer_Delay_COUNT				= 0;
double Timer_degelo_delay_ON			= 0;
double Timer_degelo_delay_COUNT			= 0;
bool Timer_degelo_delay_OUT				= false;
double Timer_Degelo_CONTROL				= 0;
double Timer_Alarme_externo_COUNT		= 0;
double timer_higiene_ON					= 0;
bool Timer_Degelo_OUT					= false;
bool Timer_alarme_externo_OUT			= false;
bool timer_higiene_OUT					= false;
bool HSW4								= false;
bool reset_fabrica						= false;
bool cancelar_processo_SIM				= false;
double xbar_zero						= 0;
bool flag_Conservar_ANDAMENTO			= false;
double Status_Conservar					= 0;
double Receita_Cong_Resf_ATUAL			= 0;
double Status_Porta						= 0;
bool flag_porta							= false;
double Temperatura_Receita_ATUAL		= 0;
double W_HDW5000						= 0;
bool W_1_4553							= false;
double W_1_4554							= 0;
double W_1_4515							= 0;
extern double W_1_410242				= 0;
extern double W_1_410282				= 0;
extern double W_1_4645					= 0;
