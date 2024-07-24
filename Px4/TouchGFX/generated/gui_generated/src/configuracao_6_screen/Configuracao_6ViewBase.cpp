/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/configuracao_6_screen/Configuracao_6ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Configuracao_6ViewBase::Configuracao_6ViewBase() :
    buttonCallback(this, &Configuracao_6ViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &Configuracao_6ViewBase::flexButtonCallbackHandler),
    numKeyboardContainer1OutOfRangeCallback(this, &Configuracao_6ViewBase::numKeyboardContainer1OutOfRangeCallbackHandler),
    numKeyboardContainer1ValidRangeCallback(this, &Configuracao_6ViewBase::numKeyboardContainer1ValidRangeCallbackHandler),
    numKeyboardContainer1HideKeypadTriggerCallback(this, &Configuracao_6ViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxVerde4.setPosition(72, 117, 66, 29);
    boxVerde4.setColor(touchgfx::Color::getColorFromRGB(125, 0, 255));

    boxVerde3.setPosition(72, 83, 66, 29);
    boxVerde3.setColor(touchgfx::Color::getColorFromRGB(125, 0, 255));

    boxVerde2.setPosition(72, 49, 66, 29);
    boxVerde2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    textAreaLabel1.setXY(151, 16);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3755));

    textAreaLabel2.setXY(151, 50);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3756));

    textAreaLabel3.setXY(151, 84);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3757));

    textAreaLabel4.setXY(151, 118);
    textAreaLabel4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel4.setLinespacing(0);
    textAreaLabel4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3758));

    textAreaLabel6.setXY(151, 193);
    textAreaLabel6.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel6.setLinespacing(0);
    textAreaLabel6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3759));

    textAreaLabel7.setXY(151, 165);
    textAreaLabel7.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel7.setLinespacing(0);
    textAreaLabel7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3760));

    buttonTelaInicial.setXY(433, 220);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR3_ID), touchgfx::Bitmap(BITMAP_VOLTAR3_ID));
    buttonTelaInicial.setAction(buttonCallback);

    buttonConfiguracao7.setXY(443, 102);
    buttonConfiguracao7.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE2_ID), touchgfx::Bitmap(BITMAP_AVANCE2_ID));
    buttonConfiguracao7.setAction(buttonCallback);

    buttonConfiguracao5.setXY(8, 102);
    buttonConfiguracao5.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));
    buttonConfiguracao5.setAction(buttonCallback);

    toggleButtonDegeloProcessoAutomatico.setXY(72, 193);
    toggleButtonDegeloProcessoAutomatico.setBitmaps(touchgfx::Bitmap(BITMAP_A3_ID), touchgfx::Bitmap(BITMAP_A4_ID));
    toggleButtonDegeloProcessoAutomatico.setAction(buttonCallback);

    toggleButton14102650.setXY(72, 156);
    toggleButton14102650.setBitmaps(touchgfx::Bitmap(BITMAP_A5_ID), touchgfx::Bitmap(BITMAP_A6_ID));
    toggleButton14102650.setAction(buttonCallback);

    toggleButtonDegeloPortaAberta.setXY(70, 11);
    toggleButtonDegeloPortaAberta.setBitmaps(touchgfx::Bitmap(BITMAP_B3_ID), touchgfx::Bitmap(BITMAP_B4_ID));
    toggleButtonDegeloPortaAberta.setAction(buttonCallback);

    textArea1410294.setPosition(66, 117, 78, 29);
    textArea1410294.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410294.setLinespacing(0);
    Unicode::snprintf(textArea1410294Buffer, TEXTAREA1410294_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3762).getText());
    textArea1410294.setWildcard(textArea1410294Buffer);
    textArea1410294.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3761));

    textArea1410295.setPosition(66, 83, 78, 29);
    textArea1410295.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410295.setLinespacing(0);
    Unicode::snprintf(textArea1410295Buffer, TEXTAREA1410295_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3764).getText());
    textArea1410295.setWildcard(textArea1410295Buffer);
    textArea1410295.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3763));

    textArea1410279.setPosition(66, 49, 78, 29);
    textArea1410279.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410279.setLinespacing(0);
    Unicode::snprintf(textArea1410279Buffer, TEXTAREA1410279_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3766).getText());
    textArea1410279.setWildcard(textArea1410279Buffer);
    textArea1410279.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3765));

    flexButton1410294.setBoxWithBorderPosition(0, 0, 66, 29);
    flexButton1410294.setBorderSize(5);
    flexButton1410294.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410294.setPosition(72, 117, 66, 29);
    flexButton1410294.setAlpha(0);
    flexButton1410294.setAction(flexButtonCallback);

    flexButton1410295.setBoxWithBorderPosition(0, 0, 66, 28);
    flexButton1410295.setBorderSize(5);
    flexButton1410295.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410295.setPosition(72, 84, 66, 28);
    flexButton1410295.setAlpha(0);
    flexButton1410295.setAction(flexButtonCallback);

    flexButton1410279.setBoxWithBorderPosition(0, 0, 66, 28);
    flexButton1410279.setBorderSize(5);
    flexButton1410279.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410279.setPosition(72, 50, 66, 28);
    flexButton1410279.setAlpha(0);
    flexButton1410279.setAction(flexButtonCallback);

    numKeyboardContainer1.setXY(0, 0);
    numKeyboardContainer1.setVisible(false);
    numKeyboardContainer1.setOutOfRangeCallback(numKeyboardContainer1OutOfRangeCallback);
    numKeyboardContainer1.setValidRangeCallback(numKeyboardContainer1ValidRangeCallback);
    numKeyboardContainer1.setHideKeypadTriggerCallback(numKeyboardContainer1HideKeypadTriggerCallback);

    add(__background);
    add(boxFundo);
    add(boxVerde4);
    add(boxVerde3);
    add(boxVerde2);
    add(textAreaLabel1);
    add(textAreaLabel2);
    add(textAreaLabel3);
    add(textAreaLabel4);
    add(textAreaLabel6);
    add(textAreaLabel7);
    add(buttonTelaInicial);
    add(buttonConfiguracao7);
    add(buttonConfiguracao5);
    add(toggleButtonDegeloProcessoAutomatico);
    add(toggleButton14102650);
    add(toggleButtonDegeloPortaAberta);
    add(textArea1410294);
    add(textArea1410295);
    add(textArea1410279);
    add(flexButton1410294);
    add(flexButton1410295);
    add(flexButton1410279);
    add(numKeyboardContainer1);
}

void Configuracao_6ViewBase::setupScreen()
{
    numKeyboardContainer1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Update(&textArea1410279, textArea1410279Buffer, 10.0, _DOUBLE_, 2);
    Update(&textArea1410295, textArea1410295Buffer, 10.03, _DOUBLE_, 2);
    Update(&textArea1410294, textArea1410294Buffer, 0, _INT_, 2);

}

//Called when the screen transition ends
void Configuracao_6ViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Configuracao_6ViewBase::numKeyboardContainer1OutOfRangeCallbackHandler()
{
    //OutOfRangeFIred
    //When numKeyboardContainer1 OutOfRange call OutOfRangeMsg on numKeyboardContainer1
    //Call OutOfRangeMsg
    numKeyboardContainer1.OutOfRangeMsg();
}

void Configuracao_6ViewBase::numKeyboardContainer1ValidRangeCallbackHandler()
{
    //InsideRangeFired
    //When numKeyboardContainer1 ValidRange call InputValidRange on numKeyboardContainer1
    //Call InputValidRange
    numKeyboardContainer1.InputValidRange();
}

void Configuracao_6ViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler()
{
    //HideNumKeyboard
    //When numKeyboardContainer1 HideKeypadTrigger execute C++ code
    //Execute C++ code
    ContainerVisibility(&numKeyboardContainer1, false);
    SoundBuzzerOn(25);
}

void Configuracao_6ViewBase::handleTickEvent()
{

}

void Configuracao_6ViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ContainerClear(&numKeyboardContainer1);
}

void Configuracao_6ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonTelaInicial)
    {
        //Telainicial
        //When buttonTelaInicial clicked change screen to Tela_Inicial
        //Go to Tela_Inicial with no screen transition
        application().gotoTela_InicialScreenNoTransition();
    }
    else if (&src == &buttonConfiguracao7)
    {
        //Configuracao7
        //When buttonConfiguracao7 clicked change screen to Configuracao_7
        //Go to Configuracao_7 with no screen transition
        application().gotoConfiguracao_7ScreenNoTransition();
    }
    else if (&src == &buttonConfiguracao5)
    {
        //Configuracao5
        //When buttonConfiguracao5 clicked change screen to Configuracao_5
        //Go to Configuracao_5 with no screen transition
        application().gotoConfiguracao_5ScreenNoTransition();
    }
    else if (&src == &toggleButtonDegeloProcessoAutomatico)
    {
        //DegeloProcessoAutomatico
        //When toggleButtonDegeloProcessoAutomatico clicked execute C++ code
        //Execute C++ code
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButton14102650)
    {
        //ADDR14102650
        //When toggleButton14102650 clicked execute C++ code
        //Execute C++ code
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButtonDegeloPortaAberta)
    {
        //DegeloPortaAberta
        //When toggleButtonDegeloPortaAberta clicked execute C++ code
        //Execute C++ code
        SoundBuzzerOn(25);
    }
}

void Configuracao_6ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButton1410294)
    {
        //ADDR1410294
        //When flexButton1410294 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textArea1410294, textArea1410294Buffer, 0.0, 9.0, _INT_, 0, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410294Keyboard
        //When ADDR1410294 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButton1410295)
    {
        //ADDR1410295
        //When flexButton1410295 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textArea1410295, textArea1410295Buffer, 0.00, 99.59, _DOUBLE_, 2, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410295Keyboard
        //When ADDR1410295 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButton1410279)
    {
        //ADDR1410279
        //When flexButton1410279 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textArea1410279, textArea1410279Buffer, 0.00, 99.59, _DOUBLE_, 2, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410279Keyboard
        //When ADDR1410279 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
}
