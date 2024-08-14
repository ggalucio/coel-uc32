/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/reset_fabrica_screen/RESET_FABRICAViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

RESET_FABRICAViewBase::RESET_FABRICAViewBase() :
    buttonCallback(this, &RESET_FABRICAViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    textAreaLabel.setXY(86, 30);
    textAreaLabel.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel.setLinespacing(0);
    textAreaLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3791));

    buttonConfiguracao.setXY(8, 102);
    buttonConfiguracao.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));
    buttonConfiguracao.setAction(buttonCallback);

    buttonWithLabelResetFabrica.setXY(177, 196);
    buttonWithLabelResetFabrica.setBitmaps(touchgfx::Bitmap(BITMAP_SETOFF2S_ID), touchgfx::Bitmap(BITMAP_SETON2S_ID));
    buttonWithLabelResetFabrica.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3790));
    buttonWithLabelResetFabrica.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonWithLabelResetFabrica.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonWithLabelResetFabrica.setAction(buttonCallback);

    imageStatusPorta.setXY(200, 0);
    imageStatusPorta.setVisible(false);
    imageStatusPorta.setBitmap(touchgfx::Bitmap(BITMAP_PORTA_ID));

    textAreaStatusPorta.setXY(98, 13);
    textAreaStatusPorta.setVisible(false);
    textAreaStatusPorta.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaStatusPorta.setLinespacing(0);
    Unicode::snprintf(textAreaStatusPortaBuffer, TEXTAREASTATUSPORTA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4160).getText());
    textAreaStatusPorta.setWildcard(textAreaStatusPortaBuffer);
    textAreaStatusPorta.resizeToCurrentText();
    textAreaStatusPorta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4159));

    add(__background);
    add(boxFundo);
    add(textAreaLabel);
    add(buttonConfiguracao);
    add(buttonWithLabelResetFabrica);
    add(imageStatusPorta);
    add(textAreaStatusPorta);
}

void RESET_FABRICAViewBase::setupScreen()
{

    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    W_HDW5000 = 43;
    
    Clear();
    
    ReadWriteModbus485(&textAreaStatusPorta, textAreaStatusPortaBuffer, "553", 0, _INT_, REPEAT);

}

//Called when the screen transition ends
void RESET_FABRICAViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void RESET_FABRICAViewBase::handleTickEvent()
{
    //HandleTickEvent
    //When handleTickEvent is called execute C++ code
    //Execute C++ code
    reset_fabrica = buttonWithLabelResetFabrica.getPressedState();
    
    if ((touchgfx::Unicode::atoi(textAreaStatusPortaBuffer)) == 1){
    	imageStatusPorta.setVisible(true);
    }else{
    	imageStatusPorta.setVisible(false);
    }
    invalidate();
}

void RESET_FABRICAViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
}

void RESET_FABRICAViewBase::writeModbus(char const* address, double value)
{
    //WriteModbus
    //When writeModbus is called execute C++ code
    //Execute C++ code
    UpdateModbus485(address, value, _INT_);
    WriteModbus485(address, 1);
    Wait(50);
}

void RESET_FABRICAViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonConfiguracao)
    {
        //Configuracao
        //When buttonConfiguracao clicked change screen to Configuracao
        //Go to Configuracao with no screen transition
        application().gotoConfiguracaoScreenNoTransition();
    }
    else if (&src == &buttonWithLabelResetFabrica)
    {
        //ResetFabrica
        //When buttonWithLabelResetFabrica clicked execute C++ code
        //Execute C++ code
        Status_tecla_Congela = 1;			// MODO CONGELAR SONDA
        Timer_SP_MINUTOS = 120;			// Inicia com timer em 120 min CONGELAR TEMPO
        Timer_SP_MINUTOS_Resfriar = 120;		// Inicia com timer em 120 min RESFRIAR TEMPO
        	
        	
        SP_Conservar_Congelar = -250;		// SP Conservar_Congelar=-25ºC		
        Diferencial_Conservar_COngelar = 50;	// Diferencial_conservar_Congelar
        
        SP_Conservar_Resfriar = 30; 		// Setpoiint Conservar_resfriar = 3.0
        Diferencial_Conservar_Resfriar = 50; 	// Diferencial_conservar_resfriar=5.0
        
        CONGELAR_SONDA_SP=-180;			// SP modo COngelar SONDA
        
        SP_Congelar_Tempo = -400;			// SP congelar TEmpo
        Diferencial_Congelar_tempo = 50;		// Diferencial congelar Tempo
        
        SP_Resfriar_Sonda = 40; 			// SP Resfriar modo SOnda = 4.0ºC
        
        SP_Resfriar_Tempo_SOFT = -20;		// SP Tempo SOFT = -2.0
        SP_Resfriar_Tempo_HARD = -20;		// SP Tempo HARD  = -2.0
        Diferencial_Resfriar_Tempo = 50;		// Diferencial Tempo = 5.0ºC
        	
        logica_entrada_digital1 = 1;		// Logica da entrada digital (1 normal / -1 invertido)
        logica_entrada_digital2 = 1;		// Logica da entrada digital (1 normal / -1 invertido)
        
        writeModbus("10294", 1);			// Ventilador ligado durante Degelo
        writeModbus("10256", 1);			// i.F1 = Door Open "1"
        
        writeModbus("10256", 2);			// i.F1 = Entrada Digital 1 > Porta com parada ventilador (NA = porta fechada)
        writeModbus("10258", 5);			// i.F2 = Entrada Digital 2 > Alarme externo com desativação das saídas
        	
        writeModbus("10324", 0);			// Desativa buzzer do controlador
        
        timer_alarme_externo_SP_MINUTOS = 1;					// Tempo de retorno do alarme externi (min)
        Timer_Alarme_externo_SP = timer_alarme_externo_SP_MINUTOS * 6;	// Retorno do alarme em 1 minuto
        
        //W_HAW8214 = "Alarme de Tensao"		// Descrição do alarme externo
        //W_HAW8235 = "Consultar manual"
        
        flag_hab_desab_Tecla_REDIAL = 0;		// Tecla Redial desabilitado
        
        writeModbus("10255", 5);			// i.p4 = Entrada Digital 4
        
        Senha_Gravada = 123;			// Senha Inicial = 123
        
        writeModbus("10294", 0);			// Ventilador desligado durante o degelo
        degelo_porta_aberta = false;		// degelo entra independente da porta
        writeModbus("10265.0", 1); 		// Degelo por gas quente
        degelo_processo_automatico	= false;	// após término do degelo, Não inicia ultimo processo automaticamente
        writeModbus("10270", 1000);				// Duração do degelo 10.00 minutos
        writeModbus("10279", 1000);				// Duração do pós degelo (gotejamento) 10.00 minutos
        writeModbus("10295", 1003);				// Retardo para ativação do evaporador após o degelo 10 minutos e 3 segundos
        
        SP_SONDA_CONGELAR_CAMARA = -250;				// Setpoint da Camara no modo CONGELAR Sonda
        SP_SONDA_RESF_CAMARA = 0;					// Setpoint da Camara no modo RESFRIAR Sonda 
        	
        
        SP_Resf_Interno_F1 = -250;					// SP interno de resfriamento modo HARD - FAse 1
        Dif_Resf_Hard_F1 = Diferencial_Resfriar_Tempo;		// Diferencial interno de resfriamento modo HARD - FAse 1
        SP_Resf_Espeto_F1 = 150;					// SP ESpeto de resfriamento modo HARD - Troca FAse 1 para Fase 2	
        
        SP_Resf_Interno_F2 = SP_SONDA_RESF_CAMARA;		// SP interno de resfriamento modo HARD - FAse 1
        Dif_Resf_Hard_F2 = Diferencial_Resfriar_Tempo;		// Diferencial interno de resfriamento modo HARD - FAse 1	
        SP_Resf_Espeto_F2 = SP_Resfriar_Sonda;			// SP ESpeto de resfriamento modo HARD - Finalização
        
        Porc_Resf_preset_tempo_F1F2 = 6;				// Porcentagem /10 do tempo total do ciclo de refriamento 60% fase 1 > 40% fase 2
        	
        // RECEITA
        Tempo_receita_1 = 120;
        Tempo_receita_2 = 120;
        Tempo_receita_3 = 120;
        Tempo_receita_4 = 120;
        Tempo_receita_5 = 120;
        Tempo_receita_6 = 120;
        Tempo_receita_7 = 120;
        Tempo_receita_8 = 120;
        Tempo_receita_9 = 120;
        Tempo_receita_10 = 120;
        Tempo_receita_11 = 120;
        Tempo_receita_12 = 120;
        
        reset_fabrica = false;
        
        SoundBuzzerOn(25);
    }
}
