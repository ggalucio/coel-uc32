/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/degelo_screen/DegeloViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

DegeloViewBase::DegeloViewBase() :
    buttonCallback(this, &DegeloViewBase::buttonCallbackHandler),
    finalizar_Degelo1CancelarProcessoCallback(this, &DegeloViewBase::finalizar_Degelo1CancelarProcessoCallbackHandler),
    finalizar_Degelo1NaoCallback(this, &DegeloViewBase::finalizar_Degelo1NaoCallbackHandler),
    timer1BeginCallback(this, &DegeloViewBase::timer1BeginCallbackHandler),
    timer1TickCallback(this, &DegeloViewBase::timer1TickCallbackHandler),
    timerCycle1sTickCallback(this, &DegeloViewBase::timerCycle1sTickCallbackHandler),
    timerCycle10TickCallback(this, &DegeloViewBase::timerCycle10TickCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxFundoAzul.setPosition(0, 0, 480, 53);
    boxFundoAzul.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    boxProcessOff.setPosition(5, 64, 392, 196);
    boxProcessOff.setColor(touchgfx::Color::getColorFromRGB(241, 241, 242));

    boxFlagProcessoAndamento.setPosition(5, 64, 392, 196);
    boxFlagProcessoAndamento.setVisible(false);
    boxFlagProcessoAndamento.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    boxWithBorder1.setPosition(93, 75, 298, 85);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxWithBorder1.setBorderSize(1);

    boxWithBorder1_1.setPosition(93, 167, 298, 85);
    boxWithBorder1_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder1_1.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxWithBorder1_1.setBorderSize(1);

    boxFundoAzul2.setPosition(189, 136, 105, 19);
    boxFundoAzul2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    boxFundoAzul2_1.setPosition(189, 227, 105, 19);
    boxFundoAzul2_1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    scalableImage1.setBitmap(touchgfx::Bitmap(BITMAP_AMPULHETA_ID));
    scalableImage1.setPosition(33, 191, 41, 43);
    scalableImage1.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    scalableImage2.setBitmap(touchgfx::Bitmap(BITMAP_EVAPORADOR_ID));
    scalableImage2.setPosition(25, 100, 57, 33);
    scalableImage2.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    imageIcon.setXY(8, 4);
    imageIcon.setBitmap(touchgfx::Bitmap(BITMAP_GOTA_ID));

    textAreaLabel3.setXY(98, 81);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3810));

    textAreaLabel3_1.setXY(98, 172);
    textAreaLabel3_1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaLabel3_1.setLinespacing(0);
    textAreaLabel3_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3811));

    textAreaUnidade1.setXY(332, 105);
    textAreaUnidade1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaUnidade1.setLinespacing(0);
    textAreaUnidade1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3808));

    textAreaUnidade2.setXY(324, 194);
    textAreaUnidade2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaUnidade2.setLinespacing(0);
    textAreaUnidade2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3809));

    textAreaTitle.setXY(48, 8);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTitle.setLinespacing(0);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3799));

    buttonFinalizarDegelo.setXY(406, 64);
    buttonFinalizarDegelo.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR_ID), touchgfx::Bitmap(BITMAP_VOLTAR_ID));
    buttonFinalizarDegelo.setAction(buttonCallback);

    toggleButtonDegeloProcessoAutomatico.setXY(406, 208);
    toggleButtonDegeloProcessoAutomatico.setBitmaps(touchgfx::Bitmap(BITMAP_STOP_ID), touchgfx::Bitmap(BITMAP_AUTO_ID));
    toggleButtonDegeloProcessoAutomatico.setAction(buttonCallback);

    textAreaFlagProcessoAndamento.setPosition(308, 14, 160, 25);
    textAreaFlagProcessoAndamento.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaFlagProcessoAndamento.setLinespacing(0);
    Unicode::snprintf(textAreaFlagProcessoAndamentoBuffer, TEXTAREAFLAGPROCESSOANDAMENTO_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4055).getText());
    textAreaFlagProcessoAndamento.setWildcard(textAreaFlagProcessoAndamentoBuffer);
    textAreaFlagProcessoAndamento.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4054));

    textArea14513.setPosition(180, 100, 121, 56);
    textArea14513.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textArea14513.setLinespacing(0);
    Unicode::snprintf(textArea14513Buffer, TEXTAREA14513_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3801).getText());
    textArea14513.setWildcard(textArea14513Buffer);
    textArea14513.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3800));

    textArea1410272.setPosition(189, 136, 105, 18);
    textArea1410272.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410272.setLinespacing(0);
    Unicode::snprintf(textArea1410272Buffer, TEXTAREA1410272_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3803).getText());
    textArea1410272.setWildcard(textArea1410272Buffer);
    textArea1410272.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3802));

    textAreaTimerDegeloCount.setPosition(307, 227, 81, 23);
    textAreaTimerDegeloCount.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaTimerDegeloCount.setLinespacing(0);
    Unicode::snprintf(textAreaTimerDegeloCountBuffer, TEXTAREATIMERDEGELOCOUNT_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4196).getText());
    textAreaTimerDegeloCount.setWildcard(textAreaTimerDegeloCountBuffer);
    textAreaTimerDegeloCount.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4195));

    textAreaTimerDegeloCountMinutos.setPosition(180, 191, 121, 56);
    textAreaTimerDegeloCountMinutos.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaTimerDegeloCountMinutos.setLinespacing(0);
    Unicode::snprintf(textAreaTimerDegeloCountMinutosBuffer, TEXTAREATIMERDEGELOCOUNTMINUTOS_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3805).getText());
    textAreaTimerDegeloCountMinutos.setWildcard(textAreaTimerDegeloCountMinutosBuffer);
    textAreaTimerDegeloCountMinutos.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3804));

    textArea1410270.setPosition(189, 227, 105, 18);
    textArea1410270.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410270.setLinespacing(0);
    Unicode::snprintf(textArea1410270Buffer, TEXTAREA1410270_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3807).getText());
    textArea1410270.setWildcard(textArea1410270Buffer);
    textArea1410270.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3806));

    finalizar_Degelo1.setXY(0, 0);
    finalizar_Degelo1.setVisible(false);
    finalizar_Degelo1.setCancelarProcessoCallback(finalizar_Degelo1CancelarProcessoCallback);
    finalizar_Degelo1.setNaoCallback(finalizar_Degelo1NaoCallback);

    background1.setXY(0, 0);

    timer1.setXY(0, 0);
    timer1.setVisible(false);

    timerCycle1s.setXY(0, 0);
    timerCycle1s.setVisible(false);
    timerCycle1s.setTickCallback(timerCycle1sTickCallback);

    timerCycle10.setXY(0, 0);
    timerCycle10.setVisible(false);
    timerCycle10.setTickCallback(timerCycle10TickCallback);

    add(__background);
    add(boxFundo);
    add(boxFundoAzul);
    add(boxProcessOff);
    add(boxFlagProcessoAndamento);
    add(boxWithBorder1);
    add(boxWithBorder1_1);
    add(boxFundoAzul2);
    add(boxFundoAzul2_1);
    add(scalableImage1);
    add(scalableImage2);
    add(imageIcon);
    add(textAreaLabel3);
    add(textAreaLabel3_1);
    add(textAreaUnidade1);
    add(textAreaUnidade2);
    add(textAreaTitle);
    add(buttonFinalizarDegelo);
    add(toggleButtonDegeloProcessoAutomatico);
    add(textAreaFlagProcessoAndamento);
    add(textArea14513);
    add(textArea1410272);
    add(textAreaTimerDegeloCount);
    add(textAreaTimerDegeloCountMinutos);
    add(textArea1410270);
    add(finalizar_Degelo1);
    add(background1);
    add(timer1);
    add(timerCycle1s);
    add(timerCycle10);
}

void DegeloViewBase::setupScreen()
{
    finalizar_Degelo1.initialize();
    background1.initialize();
    timer1.initialize();
    timerCycle1s.initialize();
    timerCycle10.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    WriteModbus485(10323, 1);
    WriteModbus485(10299, 1);
    WriteModbus485(10256, 1);
    WriteModbus485(10242, 1);
    WriteModbus485(645, 1);
    
    ReadWriteModbus485(&textArea1410272, textArea1410272Buffer, 10272, 1, _DOUBLE_, REPEAT);
    ReadWriteModbus485(&textArea1410270, textArea1410270Buffer, 10270, 2, _DOUBLE_, REPEAT);
    ReadWriteModbus485(&textArea14513, textArea14513Buffer, 513, 1, _DOUBLE_, REPEAT);
    
    ReadWriteModbus485(518, 0, _DOUBLE_, REPEAT);
    W_1_4518 = 2;
    
    Update(&textAreaTimerDegeloCountMinutos, textAreaTimerDegeloCountMinutosBuffer, Timer_Degelo_COUNT_MINUTOS, _DOUBLE_, 0);
    Update(&textAreaTimerDegeloCount, textAreaTimerDegeloCountBuffer, Timer_degelo_COUNT, _DOUBLE_, 0);
    Update(&textAreaFlagProcessoAndamento, textAreaFlagProcessoAndamentoBuffer, "  ", 20);
    Update(&toggleButtonDegeloProcessoAutomatico, degelo_processo_automatico);
    
    timerCycle1s.setWaitTime(1000);
    timerCycle1s.start();
    
    timerCycle10.setWaitTime(100);
    timerCycle10.start();

}

//Called when the screen transition ends
void DegeloViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void DegeloViewBase::finalizar_Degelo1CancelarProcessoCallbackHandler()
{
    //CancelarProcessoSim
    //When finalizar_Degelo1 cancelarProcesso execute C++ code
    //Execute C++ code
    flag_cancelar_degelo_SIM = true;
}

void DegeloViewBase::finalizar_Degelo1NaoCallbackHandler()
{
    //Nao
    //When finalizar_Degelo1 nao execute C++ code
    //Execute C++ code
    ContainerVisibility(&finalizar_Degelo1, false);
    SoundBuzzerOn(25);
}

void DegeloViewBase::timer1BeginCallbackHandler()
{
    //StartCycle100
    //When timer1 begin call setWaitTime on timer1
    //Call setWaitTime
    timer1.setWaitTime(1000);
}

void DegeloViewBase::timer1TickCallbackHandler()
{
    //Cycle100
    //When timer1 tick execute C++ code
    //Execute C++ code
    //'if @Status_degelo=0 and @Timer_degelo_delay_OUT=1 then		//' if degelo=off
    
    if (Timer_degelo_delay_OUT == 1){			//' if degelo=off
    	if (W_1_4518 != 2 && W_1_4518 != 3){ 	
    		Timer_buzzer_DEG_ON = 1;		//' inicia Timer_Buzzer
    	//'	@W_1:410242 = 999			//' SP = 99ºC
    		flag_degelo_andamento = false; 	//' Flag degelo em andamento=0
    
    
    		//''''@Timer_Degelo_ON=0		//' Timer_degelo_ON = 0
    		Timer_Degelo_CONTROL = 0;		//' timer_degelo_control=0
    		Timer_degelo_delay_ON = 0;		//' Timer Degelo Delay ON = 0
    		Timer_degelo_delay_OUT = 0;	//' Timer_degelo_delay_OUT=0
    		Timer_Degelo_OUT = 0;
    
    	}
    }
    
    
    W_1_4518 =  ReadBufferModbus485(518);
}

void DegeloViewBase::timerCycle1sTickCallbackHandler()
{
    //Cycle_1s
    //When timerCycle1s tick execute C++ code
    //Execute C++ code
    VisibilityTextArea(&textAreaFlagProcessoAndamento, (W_1_4518 == 2 ? false : true) || !textAreaFlagProcessoAndamento.isVisible());
}

void DegeloViewBase::timerCycle10TickCallbackHandler()
{
    //Cycle_100ms
    //When timerCycle10 tick execute C++ code
    //Execute C++ code
    VisibilityBox(&boxFlagProcessoAndamento, Status_degelo);
    
    if      (W_1_4518 == 0) Update(&textAreaFlagProcessoAndamento, textAreaFlagProcessoAndamentoBuffer, (char*)"Fim", 20);
    else if (W_1_4518 == 1) Update(&textAreaFlagProcessoAndamento, textAreaFlagProcessoAndamentoBuffer, (char*)"   ", 20);
    else if (W_1_4518 == 2) Update(&textAreaFlagProcessoAndamento, textAreaFlagProcessoAndamentoBuffer, (char*)"Em Andamento", 20);
    else if (W_1_4518 == 3) Update(&textAreaFlagProcessoAndamento, textAreaFlagProcessoAndamentoBuffer, (char*)"Pos Degelo", 20);
    
    Update(&textAreaTimerDegeloCountMinutos, textAreaTimerDegeloCountMinutosBuffer, Timer_Degelo_COUNT_MINUTOS, _DOUBLE_, 0);
    Update(&textAreaTimerDegeloCount, textAreaTimerDegeloCountBuffer, Timer_degelo_COUNT, _DOUBLE_, 0);
    
    W_1_4513  = 10.0 * GetNumberTextArea(textArea14513Buffer);
    
    Status_degelo = (W_1_4518 == 2 ? true : false);
}

void DegeloViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    UpdateModbus485(10323, 0, _DOUBLE_);
    
    Timer_BUzzer_DEG_OUT = false;
    Timer_buzzer_DEG_ON = false;
    
    Clear();
}

void DegeloViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonFinalizarDegelo)
    {
        //Voltar
        //When buttonFinalizarDegelo clicked execute C++ code
        //Execute C++ code
        ContainerVisibility(&finalizar_Degelo1, true);
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButtonDegeloProcessoAutomatico)
    {
        //DegeloProcessoAutomatico
        //When toggleButtonDegeloProcessoAutomatico clicked execute C++ code
        //Execute C++ code
        degelo_processo_automatico = toggleButtonDegeloProcessoAutomatico.getState();
        SoundBuzzerOn(25);
    }
}
