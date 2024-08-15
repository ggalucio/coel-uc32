/*
 * Timing.cpp
 *
 *  Created on: 8 de ago de 2024
 *      Author: COELMATIC2022
 */

#include <gui/background/Timing.hpp>
#include <gui/global/var.hpp>


void Cycle50()
{
	Timer_COUNT_MINUTOS = Timer_Congelar_DECORRIDO_COUNT / 6;	// Transforma contagem decorrido em minutos
	Timer_Degelo_COUNT_MINUTOS = Timer_degelo_COUNT / 6; 		// Transforma contagem decorrido em minutos
	Timer_higiene_MIN = Timer_higiene_COUNT / 6;  				// Transforma contagem decorrido em minutos

	if (W_1_4553)
	{
		Status_Porta = 1;
		flag_porta = true;
	}
	else
	{
		Status_Porta = 0;
		flag_porta = false;
	}
}

void Cycle500()
{
	// Monitoramento de estado da entrada digital 2
	int a;

	a = logica_entrada_digital2 * (int)W_1_4554; 		// Compara logica da entrada digital2 com o valor lido da dig2 do controlador

	if (a != 0 && flag_alarme_externo_andamento == 0)	// se logica_entrada2 <> status Dig2 and alarme_externo_andamento=0 (indica que estava sem alarme)
		flag_alarme_externo = 1;						// bit flag de alarme ativo

	if (a == 0 && flag_alarme_externo_andamento == 1) 	// se logica_entrada2 <> status Dig2 and alarme_externo_andamento=0 (indica que estava sem alarme)
		Timer_alarme_externo_ON = 1;					// Start timer de retorno saída da tela de alarme externo
}

void Cycle25()
{
	int a, b, c, d, spi1, spe1, spi2, spe2;

	if (Status_tecla_Congela == 1 || Status_tecla_Congela == 3){
		b = (uint16_t)W_1_4515;						// b = valor Pr3
	}
	else{
		c = (uint16_t)W_1_4515;						// c = valor Pr3
		d = (uint16_t)Temperatura_Receita_ATUAL;	// d = Temperatura_receita_ATUAL
	}


	// *********************

	if (Status_tecla_Congela == 1) 				// if modo COngelar
		a = (int16_t)CONGELAR_SONDA_SP;			// a= SP congelar SOnda

	if (Status_tecla_Congela == 3){ 			// if modo resfriar
		a = (int16_t)SP_Resfriar_Sonda;			// a= SP Resfriar SOnda

		spe1 = (int16_t)SP_Resf_Espeto_F1;		// SPe1 = signedint16 (SP_REsf_Espeto_F1)
		spe2 = (int16_t)SP_Resf_Espeto_F2;		// SPe2 = signedint16 (SP_Resf_Espeto_F2)
	}

	// *********************

	// Modo COngelar
	if (flag_Processo_ANDAMENTO == 1 && Status_tecla_Congela == 1 && Timer_delay_OUT == 1){		// IF flag_processo_Andamento=1 and CONGELAR_Modo_SONDA and Timer_Delay_out
		if (b <= a){												// IF PR3<=SP
			Tempo_estimado_Congelar_SONDA = Timer_COUNT_MINUTOS;	// Tempo_estimado_ongelar_SONDA = Timer_COngelar_COUNT_MINUTOS
			Timer_Congelar_DECORRIDO_ON = 0;						// Timer_CONG_ON=0
			Timer_Congelar_DECORRIDO_OUT = 1;						// Timer_CONG_OUT=1
		}
	}


	// Modo Resfriar
	if (flag_Processo_ANDAMENTO == 1 && Status_tecla_Congela == 3 && Timer_delay_OUT == 1){		// IF flag_processo_Andamento=1 and Resfriar_Modo_SONDA

		 if (flag_Resfriar_HARD_SOFT == false){ // SE MODO SOFT
			if (b <= a){							// IF PR3<=SP
				Tempo_estimado_Resfriar_Sonda = Timer_COUNT_MINUTOS;	// Tempo estimado Resfriar
				Timer_Congelar_DECORRIDO_ON = 0;						// Timer_CONG_ON=0
				Timer_Congelar_DECORRIDO_OUT = 1;						// Timer_CONG_OUT=1
			}
		}
		else{ // SE MODO HARD
		 	if (b <= spe1 && Hard_Resf_fase_numero == 1){ // IF PR3<=SPe1 And Fase 1
				//Beep()
				Hard_Resf_fase_numero = 2;

				//@W_1:410242 = @SP_Resf_Interno_F2					' SP X34 = SP_Interno_F2_Processo
				//@W_1:410282 = @Dif_Resf_Hard_F2						' Diferencial X34 = diferencial fase 2
				//@W_1:4645 = 1											' Controlador em modo COntrole

				SP_Resf_Hard_Interno_display =  SP_Resf_Interno_F2;
				SP_Resf_Hard_Espeto_display = SP_Resf_Espeto_F2;

		 	}

			if (b <= spe2 && Hard_Resf_fase_numero == 2){ // IF PR3<=SPe2 And Fase 2
				Hard_Resf_fase_numero = 0;

				Tempo_estimado_Resfriar_Sonda = Timer_COUNT_MINUTOS;	// Tempo estimado Resfriar
				Timer_Congelar_DECORRIDO_ON = 0;						// Timer_CONG_ON=0
				Timer_Congelar_DECORRIDO_OUT = 1;						// Timer_CONG_OUT=1
			}

		}
	}

	// Modo Receita
	if (flag_Processo_ANDAMENTO == 1 && Status_tecla_Congela == 0 and Timer_delay_OUT == 1){		// IF flag_processo_Andamento=1 and Resfriar_Modo_SONDA (receita)
		if (c <= d){												// IF PR3<=SP
			Tempo_Estimado_Receita_Temperat = Timer_COUNT_MINUTOS;	// Tempo estimado Resfriar
			Timer_Congelar_DECORRIDO_ON = 0;						// Timer_CONG_ON=0
			Timer_Congelar_DECORRIDO_OUT = 1;						// Timer_CONG_OUT=1
		}
	}

	// MODO Resfriar Tempo
	if (flag_Processo_ANDAMENTO == 1 && Status_tecla_Congela == 4){		// IF flag_processo_Andamento=1 and Resfriar_Modo_ TEMPO
		if (flag_Resfriar_HARD_SOFT == true && Timer_Congelar_DECORRIDO_ON == 1){ // SE MODO HARD
			if (Timer_Congelar_DECORRIDO_COUNT == Preset_Resf_Tempo_F1){

				if (xBeep_once == false){
					//Beep()
					xBeep_once = true;
				}

				Hard_Resf_fase_numero = 2;

				//@W_1:410242 = @SP_Resf_Interno_F2					// SP X34 = SP_Interno_F2_Processo
				//@W_1:410282 = @Dif_Resf_Hard_F2					// Diferencial X34 = diferencial fase 2
				//@W_1:4645 = 1										// Controlador em modo COntrole

				SP_Resf_Hard_Interno_display =  SP_Resf_Interno_F2;
			}
		}
	}
}

void TIMER_1S()
{
	// TIMER BUZZER
	if (Timer_buzzer_ON == 1){
		if (Timer_Buzzer_COUNT >= Timer_buzzer_SP - 1)
			Timer_BUzzer_OUT = true;
		else
			Timer_Buzzer_COUNT = Timer_Buzzer_COUNT + 1;
	}
	else
		Timer_Buzzer_COUNT = 0;

	// TIMER BUZZER DEGELO
	if (Timer_buzzer_DEG_ON == 1){
		if (Timer_Buzzer_DEG_COUNT >= Timer_buzzer_SP - 1)
			Timer_BUzzer_DEG_OUT = true;
		else
			Timer_Buzzer_DEG_COUNT = Timer_Buzzer_DEG_COUNT + 1;
	}
	else
		Timer_Buzzer_DEG_COUNT = 0;

	// TIMER DELAY
	if (Timer_delay_ON == 1){
		if (Timer_Delay_COUNT >= Timer_Delay_SP - 1)
			Timer_delay_OUT = true;
		else
			Timer_Delay_COUNT = Timer_Delay_COUNT  + 1;
	}
	else
		Timer_Delay_COUNT = 0;

	// TImer Degelo Delay
	if (Timer_degelo_delay_ON == 1){
		if (Timer_degelo_delay_COUNT >= Timer_degelo_delay_SP - 1)
			Timer_degelo_delay_OUT = true;
		else
			Timer_degelo_delay_COUNT = Timer_degelo_delay_COUNT + 1;
	}
	else
		Timer_degelo_delay_COUNT = 0;

	// VERIFICA TIMERS 10 SEG PARA RESET

	// TIMER DEGELO
	if (Timer_Degelo_CONTROL == 0)
		Timer_degelo_COUNT  = 0;

	// TIMER PROCESSO DECORRIDO
	if (Timer_Congelar_DECORRIDO_ON == 0)
		Timer_Congelar_DECORRIDO_COUNT = 0;

	// TIMER ALARME EXTERNO
	if (Timer_alarme_externo_ON == 0)
		Timer_Alarme_externo_COUNT = 0;

	// TIMER HIGIENE
	if (timer_higiene_ON == 0)
		Timer_higiene_COUNT = 0;
}

void TIMER_10S()
{
	// TIMER DEGELO
	if (Timer_Degelo_CONTROL == 1){
		if (Timer_degelo_COUNT >= Timer_Degelo_SP -1)
			Timer_Degelo_OUT = true;
		else
			Timer_degelo_COUNT = Timer_degelo_COUNT + 1;
	}
	else
		Timer_degelo_COUNT = 0;

	// TIMER PROCESSO DECORRIDO
	if (Timer_Congelar_DECORRIDO_ON == 1){
		if (Timer_Congelar_DECORRIDO_COUNT >= Timer_Congelar_DECORRIDO_SP -1)
			Timer_Congelar_DECORRIDO_OUT = true;
		else
			Timer_Congelar_DECORRIDO_COUNT = Timer_Congelar_DECORRIDO_COUNT + 1;
	}
	else
		Timer_Congelar_DECORRIDO_COUNT = 0;

	// TIMER ALARME EXTERNO
	if (Timer_alarme_externo_ON == 1){
		if (Timer_Alarme_externo_COUNT >= Timer_Alarme_externo_SP - 1)
			Timer_alarme_externo_OUT = true;
		else
			Timer_Alarme_externo_COUNT = Timer_Alarme_externo_COUNT + 1;
	}
	else
		Timer_Alarme_externo_COUNT = 0;



	// TIMER HIGIENE
	if (timer_higiene_ON == 1){
		if (Timer_higiene_COUNT >= 65000 -1)
			timer_higiene_OUT = true;
		else
			Timer_higiene_COUNT = Timer_higiene_COUNT + 1;
	}
	else
		Timer_higiene_COUNT = 0;
}
