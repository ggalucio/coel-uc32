/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/configuracao_5_screen/Configuracao_5ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Configuracao_5ViewBase::Configuracao_5ViewBase() :
    buttonCallback(this, &Configuracao_5ViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &Configuracao_5ViewBase::flexButtonCallbackHandler),
    numKeyboardContainer1OutOfRangeCallback(this, &Configuracao_5ViewBase::numKeyboardContainer1OutOfRangeCallbackHandler),
    numKeyboardContainer1ValidRangeCallback(this, &Configuracao_5ViewBase::numKeyboardContainer1ValidRangeCallbackHandler),
    numKeyboardContainer1HideKeypadTriggerCallback(this, &Configuracao_5ViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler),
    keyboardContainer21HideKeyboardCallback(this, &Configuracao_5ViewBase::keyboardContainer21HideKeyboardCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxWithBorder5.setPosition(53, 72, 380, 107);
    boxWithBorder5.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorder5.setBorderColor(touchgfx::Color::getColorFromRGB(168, 168, 168));
    boxWithBorder5.setBorderSize(1);

    boxWithBorder1.setPosition(138, 144, 204, 27);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(255, 128, 128));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder1.setBorderSize(1);

    boxWithBorder4.setPosition(51, 227, 64, 33);
    boxWithBorder4.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));
    boxWithBorder4.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder4.setBorderSize(1);

    boxWithBorder3.setPosition(138, 109, 204, 27);
    boxWithBorder3.setColor(touchgfx::Color::getColorFromRGB(255, 128, 128));
    boxWithBorder3.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder3.setBorderSize(1);

    boxWithBorder2.setPosition(52, 31, 64, 33);
    boxWithBorder2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxWithBorder2.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder2.setBorderSize(1);

    textAreaLabel1_1.setXY(143, 83);
    textAreaLabel1_1.setColor(touchgfx::Color::getColorFromRGB(99, 99, 99));
    textAreaLabel1_1.setLinespacing(0);
    textAreaLabel1_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3746));

    textAreaLabel1.setXY(121, 28);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3745));

    textAreaLabel1_2.setXY(121, 194);
    textAreaLabel1_2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel1_2.setLinespacing(0);
    textAreaLabel1_2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3753));

    textAreaLabel1_2_1.setXY(121, 234);
    textAreaLabel1_2_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel1_2_1.setLinespacing(0);
    textAreaLabel1_2_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3754));

    buttonTelaInicial.setXY(433, 220);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR3_ID), touchgfx::Bitmap(BITMAP_VOLTAR3_ID));
    buttonTelaInicial.setAction(buttonCallback);

    buttonConfiguracao6.setXY(443, 102);
    buttonConfiguracao6.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE2_ID), touchgfx::Bitmap(BITMAP_AVANCE2_ID));
    buttonConfiguracao6.setAction(buttonCallback);

    buttonConfiguracao4.setXY(8, 102);
    buttonConfiguracao4.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));
    buttonConfiguracao4.setAction(buttonCallback);

    toggleButtonFlagHabDesabTeclaRedial.setXY(51, 187);
    toggleButtonFlagHabDesabTeclaRedial.setBitmaps(touchgfx::Bitmap(BITMAP_S1S_ID), touchgfx::Bitmap(BITMAP_S2S_ID));
    toggleButtonFlagHabDesabTeclaRedial.setAction(buttonCallback);

    textArea1410299.setPosition(51, 227, 64, 33);
    textArea1410299.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410299.setLinespacing(0);
    Unicode::snprintf(textArea1410299Buffer, TEXTAREA1410299_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3752).getText());
    textArea1410299.setWildcard(textArea1410299Buffer);
    textArea1410299.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3751));

    textAreaHAW8235.setPosition(138, 144, 204, 27);
    textAreaHAW8235.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaHAW8235.setLinespacing(0);
    Unicode::snprintf(textAreaHAW8235Buffer, TEXTAREAHAW8235_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3750).getText());
    textAreaHAW8235.setWildcard(textAreaHAW8235Buffer);
    textAreaHAW8235.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3749));

    textAreaHAW8214.setPosition(138, 109, 204, 27);
    textAreaHAW8214.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaHAW8214.setLinespacing(0);
    Unicode::snprintf(textAreaHAW8214Buffer, TEXTAREAHAW8214_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3748).getText());
    textAreaHAW8214.setWildcard(textAreaHAW8214Buffer);
    textAreaHAW8214.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3747));

    textAreaTimerAlarmeExternoSpMinutos.setPosition(52, 31, 64, 33);
    textAreaTimerAlarmeExternoSpMinutos.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTimerAlarmeExternoSpMinutos.setLinespacing(0);
    Unicode::snprintf(textAreaTimerAlarmeExternoSpMinutosBuffer, TEXTAREATIMERALARMEEXTERNOSPMINUTOS_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3744).getText());
    textAreaTimerAlarmeExternoSpMinutos.setWildcard(textAreaTimerAlarmeExternoSpMinutosBuffer);
    textAreaTimerAlarmeExternoSpMinutos.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3743));

    flexButtonHAW8235.setBoxWithBorderPosition(0, 0, 204, 27);
    flexButtonHAW8235.setBorderSize(5);
    flexButtonHAW8235.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonHAW8235.setPosition(138, 144, 204, 27);
    flexButtonHAW8235.setAlpha(0);
    flexButtonHAW8235.setAction(flexButtonCallback);

    flexButtonHAW8214.setBoxWithBorderPosition(0, 0, 204, 27);
    flexButtonHAW8214.setBorderSize(5);
    flexButtonHAW8214.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonHAW8214.setPosition(138, 109, 204, 27);
    flexButtonHAW8214.setAlpha(0);
    flexButtonHAW8214.setAction(flexButtonCallback);

    flexButton1410299.setBoxWithBorderPosition(0, 0, 63, 33);
    flexButton1410299.setBorderSize(5);
    flexButton1410299.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410299.setPosition(52, 227, 63, 33);
    flexButton1410299.setAlpha(0);
    flexButton1410299.setAction(flexButtonCallback);

    flexButtonTimerAlarmeExternoSpMinutos.setBoxWithBorderPosition(0, 0, 63, 33);
    flexButtonTimerAlarmeExternoSpMinutos.setBorderSize(5);
    flexButtonTimerAlarmeExternoSpMinutos.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonTimerAlarmeExternoSpMinutos.setPosition(53, 31, 63, 33);
    flexButtonTimerAlarmeExternoSpMinutos.setAlpha(0);
    flexButtonTimerAlarmeExternoSpMinutos.setAction(flexButtonCallback);

    keyboardContainer21.setXY(0, 0);
    keyboardContainer21.setVisible(false);
    keyboardContainer21.setHideKeyboardCallback(keyboardContainer21HideKeyboardCallback);

    numKeyboardContainer1.setXY(0, 0);
    numKeyboardContainer1.setVisible(false);
    numKeyboardContainer1.setOutOfRangeCallback(numKeyboardContainer1OutOfRangeCallback);
    numKeyboardContainer1.setValidRangeCallback(numKeyboardContainer1ValidRangeCallback);
    numKeyboardContainer1.setHideKeypadTriggerCallback(numKeyboardContainer1HideKeypadTriggerCallback);

    background1.setXY(0, 0);

    add(__background);
    add(boxFundo);
    add(boxWithBorder5);
    add(boxWithBorder1);
    add(boxWithBorder4);
    add(boxWithBorder3);
    add(boxWithBorder2);
    add(textAreaLabel1_1);
    add(textAreaLabel1);
    add(textAreaLabel1_2);
    add(textAreaLabel1_2_1);
    add(buttonTelaInicial);
    add(buttonConfiguracao6);
    add(buttonConfiguracao4);
    add(toggleButtonFlagHabDesabTeclaRedial);
    add(textArea1410299);
    add(textAreaHAW8235);
    add(textAreaHAW8214);
    add(textAreaTimerAlarmeExternoSpMinutos);
    add(flexButtonHAW8235);
    add(flexButtonHAW8214);
    add(flexButton1410299);
    add(flexButtonTimerAlarmeExternoSpMinutos);
    add(keyboardContainer21);
    add(numKeyboardContainer1);
    add(background1);
}

void Configuracao_5ViewBase::setupScreen()
{
    keyboardContainer21.initialize();
    numKeyboardContainer1.initialize();
    background1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Clear();
    
    ReadWriteModbus485(&textArea1410299, textArea1410299Buffer, 10299, 2, _DOUBLE_, REPEAT);
    
    Update(&textAreaTimerAlarmeExternoSpMinutos, textAreaTimerAlarmeExternoSpMinutosBuffer, timer_alarme_externo_SP_MINUTOS, _INT_, 0);
    Update(&textAreaHAW8214, textAreaHAW8214Buffer, W_HAW8214, 20);
    Update(&textAreaHAW8235, textAreaHAW8235Buffer, W_HAW8235, 20);
    Update(&toggleButtonFlagHabDesabTeclaRedial, flag_hab_desab_Tecla_REDIAL);

}

//Called when the screen transition ends
void Configuracao_5ViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Configuracao_5ViewBase::numKeyboardContainer1OutOfRangeCallbackHandler()
{
    //OutOfRangeFIred
    //When numKeyboardContainer1 OutOfRange call OutOfRangeMsg on numKeyboardContainer1
    //Call OutOfRangeMsg
    numKeyboardContainer1.OutOfRangeMsg();
}

void Configuracao_5ViewBase::numKeyboardContainer1ValidRangeCallbackHandler()
{
    //InsideRangeFired
    //When numKeyboardContainer1 ValidRange call InputValidRange on numKeyboardContainer1
    //Call InputValidRange
    numKeyboardContainer1.InputValidRange();
}

void Configuracao_5ViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler()
{
    //HideNumKeyboard
    //When numKeyboardContainer1 HideKeypadTrigger execute C++ code
    //Execute C++ code
    ContainerVisibility(&numKeyboardContainer1, false);
    SoundBuzzerOn(25);
}

void Configuracao_5ViewBase::keyboardContainer21HideKeyboardCallbackHandler()
{
    //HideKeyboard
    //When keyboardContainer21 HideKeyboard execute C++ code
    //Execute C++ code
    ContainerVisibility(&keyboardContainer21, false);
    SoundBuzzerOn(25);
}

void Configuracao_5ViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    timer_alarme_externo_SP_MINUTOS = GetNumberTextArea(textAreaTimerAlarmeExternoSpMinutosBuffer);
    
    CopyTextArea(W_HAW8214, textAreaHAW8214Buffer, 20);
    CopyTextArea(W_HAW8235, textAreaHAW8235Buffer, 20);
    
    WriteMemory(54, W_HAW8214, 20);
    WriteMemory(57, W_HAW8235, 20);
    
    Clear();
    
    Timer_Alarme_externo_SP = timer_alarme_externo_SP_MINUTOS * 6; 	// transforma minutos em seg10
}

void Configuracao_5ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonTelaInicial)
    {
        //TelaInicial
        //When buttonTelaInicial clicked change screen to Tela_Inicial
        //Go to Tela_Inicial with no screen transition
        application().gotoTela_InicialScreenNoTransition();
    }
    else if (&src == &buttonConfiguracao6)
    {
        //Configuracao6
        //When buttonConfiguracao6 clicked change screen to Configuracao_6
        //Go to Configuracao_6 with no screen transition
        application().gotoConfiguracao_6ScreenNoTransition();
    }
    else if (&src == &buttonConfiguracao4)
    {
        //Configuracao4
        //When buttonConfiguracao4 clicked change screen to Configuracao_4
        //Go to Configuracao_4 with no screen transition
        application().gotoConfiguracao_4ScreenNoTransition();
    }
    else if (&src == &toggleButtonFlagHabDesabTeclaRedial)
    {
        //FlagHabDesabTeclaRedial
        //When toggleButtonFlagHabDesabTeclaRedial clicked execute C++ code
        //Execute C++ code
        flag_hab_desab_Tecla_REDIAL = toggleButtonFlagHabDesabTeclaRedial.getState();
        WriteMemory(51, flag_hab_desab_Tecla_REDIAL);
        SoundBuzzerOn(25);
    }
}

void Configuracao_5ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButtonHAW8235)
    {
        //HAW8235
        //When flexButtonHAW8235 clicked execute C++ code
        //Execute C++ code
        AddKeyboardReference(&textAreaHAW8235, textAreaHAW8235Buffer);
        keyboardContainer21.restore();
        ContainerVisibility(&keyboardContainer21, true);
        SoundBuzzerOn(25);

        //LaunchHAW8235Keyboard
        //When HAW8235 completed call LaunchKeyboard on keyboardContainer21
        //Call LaunchKeyboard
        keyboardContainer21.LaunchKeyboard();
    }
    else if (&src == &flexButtonHAW8214)
    {
        //HAW8214
        //When flexButtonHAW8214 clicked execute C++ code
        //Execute C++ code
        AddKeyboardReference(&textAreaHAW8214, textAreaHAW8214Buffer);
        keyboardContainer21.restore();
        ContainerVisibility(&keyboardContainer21, true);
        SoundBuzzerOn(25);

        //LaunchHAW8214Keyboard
        //When HAW8214 completed call LaunchKeyboard on keyboardContainer21
        //Call LaunchKeyboard
        keyboardContainer21.LaunchKeyboard();
    }
    else if (&src == &flexButton1410299)
    {
        //ADDR1410299
        //When flexButton1410299 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReferenceRS485(&textArea1410299, textArea1410299Buffer, 0.00, 99.0, _DOUBLE_, 2, 1, 10299);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410299Keyboard
        //When ADDR1410299 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonTimerAlarmeExternoSpMinutos)
    {
        //TimerAlarmeExternoSpMinutos
        //When flexButtonTimerAlarmeExternoSpMinutos clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaTimerAlarmeExternoSpMinutos, textAreaTimerAlarmeExternoSpMinutosBuffer, 0.0, 30.0, _INT_, 0, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchTimerAlarmeExternoSpMinutosKeyboard
        //When TimerAlarmeExternoSpMinutos completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
}
