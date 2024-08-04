/*
 * var.cpp
 *
 *  Created on: 16 de jul de 2024
 *      Author: COELMATIC2022
 */

#include "gui/global/var.hpp"

uint8_t selectedRecipeListPage = 0;
uint8_t selectedRecipeItem = 0;
int countCycleBlink = 0;
bool isZeroValue = false;

// Scripts Global Variables
//Screen Congelar
int SP_SONDA_CONGELAR_CAMARA = -250;
int Diferencial_Congelar_tempo = 30;
int Timer_Congelar_DECORRIDO_SP = 0;
int Timer_Congelar_DECORRIDO_ON = 0;
bool flag_Processo_ANDAMENTO = false;
bool Timer_delay_ON = false;
bool flag_alarm_receita_vazia = true;
bool Status_tecla_Congela = true;

//Script 2
bool Timer_Congelar_DECORRIDO_OUT = false;

