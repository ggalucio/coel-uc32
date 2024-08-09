/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/configuracao_3_screen/Configuracao_3ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Configuracao_3ViewBase::Configuracao_3ViewBase() :
    buttonCallback(this, &Configuracao_3ViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &Configuracao_3ViewBase::flexButtonCallbackHandler),
    numKeyboardContainer1OutOfRangeCallback(this, &Configuracao_3ViewBase::numKeyboardContainer1OutOfRangeCallbackHandler),
    numKeyboardContainer1ValidRangeCallback(this, &Configuracao_3ViewBase::numKeyboardContainer1ValidRangeCallbackHandler),
    numKeyboardContainer1HideKeypadTriggerCallback(this, &Configuracao_3ViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxWithBorderBranco.setPosition(66, 192, 78, 29);
    boxWithBorderBranco.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorderBranco.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorderBranco.setBorderSize(1);

    boxVerde4.setPosition(66, 117, 78, 29);
    boxVerde4.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));

    boxVerde3.setPosition(66, 83, 78, 29);
    boxVerde3.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));

    boxVerde2.setPosition(66, 49, 78, 29);
    boxVerde2.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));

    boxVerde.setPosition(66, 15, 78, 29);
    boxVerde.setColor(touchgfx::Color::getColorFromRGB(125, 0, 255));

    textAreaLabel1.setXY(151, 16);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(125, 0, 255));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3712));

    textAreaLabel2.setXY(151, 57);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3713));

    textAreaLabel3.setXY(151, 91);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3714));

    textAreaLabel4.setXY(151, 125);
    textAreaLabel4.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));
    textAreaLabel4.setLinespacing(0);
    textAreaLabel4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3715));

    textAreaLabel6.setXY(151, 200);
    textAreaLabel6.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel6.setLinespacing(0);
    textAreaLabel6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3717));

    textAreaLabel7.setXY(151, 165);
    textAreaLabel7.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel7.setLinespacing(0);
    textAreaLabel7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3731));

    buttonTelaInicial.setXY(433, 220);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR3_ID), touchgfx::Bitmap(BITMAP_VOLTAR3_ID));
    buttonTelaInicial.setAction(buttonCallback);

    buttonConfiguracao4.setXY(443, 102);
    buttonConfiguracao4.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE2_ID), touchgfx::Bitmap(BITMAP_AVANCE2_ID));
    buttonConfiguracao4.setAction(buttonCallback);

    buttonConfiguracao2.setXY(8, 102);
    buttonConfiguracao2.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));
    buttonConfiguracao2.setAction(buttonCallback);

    toggleButtonHSW4.setXY(66, 157);
    toggleButtonHSW4.setBitmaps(touchgfx::Bitmap(BITMAP_SETOFFS_ID), touchgfx::Bitmap(BITMAP_SETONS_ID));
    toggleButtonHSW4.setAction(buttonCallback);

    textArea1410275.setPosition(66, 192, 78, 29);
    textArea1410275.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1410275.setLinespacing(0);
    Unicode::snprintf(textArea1410275Buffer, TEXTAREA1410275_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3730).getText());
    textArea1410275.setWildcard(textArea1410275Buffer);
    textArea1410275.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3729));

    textArea1410250.setPosition(66, 117, 78, 29);
    textArea1410250.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410250.setLinespacing(0);
    Unicode::snprintf(textArea1410250Buffer, TEXTAREA1410250_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3720).getText());
    textArea1410250.setWildcard(textArea1410250Buffer);
    textArea1410250.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3719));

    textArea1410249.setPosition(66, 83, 78, 29);
    textArea1410249.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410249.setLinespacing(0);
    Unicode::snprintf(textArea1410249Buffer, TEXTAREA1410249_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3722).getText());
    textArea1410249.setWildcard(textArea1410249Buffer);
    textArea1410249.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3721));

    textArea1410248.setPosition(66, 49, 78, 29);
    textArea1410248.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410248.setLinespacing(0);
    Unicode::snprintf(textArea1410248Buffer, TEXTAREA1410248_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3724).getText());
    textArea1410248.setWildcard(textArea1410248Buffer);
    textArea1410248.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3723));

    textArea1410291.setPosition(66, 15, 78, 29);
    textArea1410291.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410291.setLinespacing(0);
    Unicode::snprintf(textArea1410291Buffer, TEXTAREA1410291_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3726).getText());
    textArea1410291.setWildcard(textArea1410291Buffer);
    textArea1410291.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3725));

    flexButton1410275.setBoxWithBorderPosition(0, 0, 78, 28);
    flexButton1410275.setBorderSize(5);
    flexButton1410275.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410275.setPosition(66, 192, 78, 28);
    flexButton1410275.setAlpha(0);
    flexButton1410275.setAction(flexButtonCallback);

    flexButton1410250.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButton1410250.setBorderSize(5);
    flexButton1410250.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410250.setPosition(66, 117, 78, 29);
    flexButton1410250.setAlpha(0);
    flexButton1410250.setAction(flexButtonCallback);

    flexButton1410249.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButton1410249.setBorderSize(5);
    flexButton1410249.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410249.setPosition(66, 83, 78, 29);
    flexButton1410249.setAlpha(0);
    flexButton1410249.setAction(flexButtonCallback);

    flexButton1410248.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButton1410248.setBorderSize(5);
    flexButton1410248.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410248.setPosition(66, 49, 78, 29);
    flexButton1410248.setAlpha(0);
    flexButton1410248.setAction(flexButtonCallback);

    flexButton1410291.setBoxWithBorderPosition(0, 0, 78, 28);
    flexButton1410291.setBorderSize(5);
    flexButton1410291.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410291.setPosition(66, 16, 78, 28);
    flexButton1410291.setAlpha(0);
    flexButton1410291.setAction(flexButtonCallback);

    numKeyboardContainer1.setXY(0, 0);
    numKeyboardContainer1.setVisible(false);
    numKeyboardContainer1.setOutOfRangeCallback(numKeyboardContainer1OutOfRangeCallback);
    numKeyboardContainer1.setValidRangeCallback(numKeyboardContainer1ValidRangeCallback);
    numKeyboardContainer1.setHideKeypadTriggerCallback(numKeyboardContainer1HideKeypadTriggerCallback);

    imageStatusPorta.setXY(200, 0);
    imageStatusPorta.setVisible(false);
    imageStatusPorta.setBitmap(touchgfx::Bitmap(BITMAP_PORTA_ID));

    textAreaStatusPorta.setXY(98, 13);
    textAreaStatusPorta.setVisible(false);
    textAreaStatusPorta.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaStatusPorta.setLinespacing(0);
    Unicode::snprintf(textAreaStatusPortaBuffer, TEXTAREASTATUSPORTA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4136).getText());
    textAreaStatusPorta.setWildcard(textAreaStatusPortaBuffer);
    textAreaStatusPorta.resizeToCurrentText();
    textAreaStatusPorta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4135));

    add(__background);
    add(boxFundo);
    add(boxWithBorderBranco);
    add(boxVerde4);
    add(boxVerde3);
    add(boxVerde2);
    add(boxVerde);
    add(textAreaLabel1);
    add(textAreaLabel2);
    add(textAreaLabel3);
    add(textAreaLabel4);
    add(textAreaLabel6);
    add(textAreaLabel7);
    add(buttonTelaInicial);
    add(buttonConfiguracao4);
    add(buttonConfiguracao2);
    add(toggleButtonHSW4);
    add(textArea1410275);
    add(textArea1410250);
    add(textArea1410249);
    add(textArea1410248);
    add(textArea1410291);
    add(flexButton1410275);
    add(flexButton1410250);
    add(flexButton1410249);
    add(flexButton1410248);
    add(flexButton1410291);
    add(numKeyboardContainer1);
    add(imageStatusPorta);
    add(textAreaStatusPorta);
}

void Configuracao_3ViewBase::setupScreen()
{
    numKeyboardContainer1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Clear();
    
    ReadWriteModbus485(&textAreaStatusPorta, textAreaStatusPortaBuffer, "553", 0, _INT_, REPEAT);
    
    Update(&textArea1410291, textArea1410291Buffer, 0.0, _FP_32BIT_, 1);
    Update(&textArea1410248, textArea1410248Buffer, 0.0, _FP_32BIT_, 1);
    Update(&textArea1410249, textArea1410249Buffer, 0.0, _FP_32BIT_, 1);
    Update(&textArea1410250, textArea1410250Buffer, 0.0, _FP_32BIT_, 1);
    Update(&textArea1410275, textArea1410275Buffer, 123, _INT_, 0);

}

//Called when the screen transition ends
void Configuracao_3ViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Configuracao_3ViewBase::numKeyboardContainer1OutOfRangeCallbackHandler()
{
    //OutOfRangeFIred
    //When numKeyboardContainer1 OutOfRange call OutOfRangeMsg on numKeyboardContainer1
    //Call OutOfRangeMsg
    numKeyboardContainer1.OutOfRangeMsg();
}

void Configuracao_3ViewBase::numKeyboardContainer1ValidRangeCallbackHandler()
{
    //InsideRangeFired
    //When numKeyboardContainer1 ValidRange call InputValidRange on numKeyboardContainer1
    //Call InputValidRange
    numKeyboardContainer1.InputValidRange();
}

void Configuracao_3ViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler()
{
    //HideNumKeyboard
    //When numKeyboardContainer1 HideKeypadTrigger execute C++ code
    //Execute C++ code
    ContainerVisibility(&numKeyboardContainer1, false);
    SoundBuzzerOn(25);
}

void Configuracao_3ViewBase::handleTickEvent()
{
    //HandleTickEvent
    //When handleTickEvent is called execute C++ code
    //Execute C++ code
    if ((touchgfx::Unicode::atoi(textAreaStatusPortaBuffer)) == 1){
    	imageStatusPorta.setVisible(true);
    }else{
    	imageStatusPorta.setVisible(false);
    }
    invalidate();
}

void Configuracao_3ViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ContainerClear(&numKeyboardContainer1);
}

void Configuracao_3ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonTelaInicial)
    {
        //TelaInicial
        //When buttonTelaInicial clicked change screen to Tela_Inicial
        //Go to Tela_Inicial with no screen transition
        application().gotoTela_InicialScreenNoTransition();
    }
    else if (&src == &buttonConfiguracao4)
    {
        //Configuracao4
        //When buttonConfiguracao4 clicked change screen to Configuracao_4
        //Go to Configuracao_4 with no screen transition
        application().gotoConfiguracao_4ScreenNoTransition();
    }
    else if (&src == &buttonConfiguracao2)
    {
        //Configuracao2
        //When buttonConfiguracao2 clicked change screen to Configuracao_2
        //Go to Configuracao_2 with no screen transition
        application().gotoConfiguracao_2ScreenNoTransition();
    }
    else if (&src == &toggleButtonHSW4)
    {
        //HSW4
        //When toggleButtonHSW4 clicked execute C++ code
        //Execute C++ code
        SoundBuzzerOn(25);
    }
}

void Configuracao_3ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButton1410275)
    {
        //ADDR1410275
        //When flexButton1410275 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textArea1410275, textArea1410275Buffer, 0.0, 65535.0, _INT_, 0, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410275Keyboard
        //When ADDR1410275 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButton1410250)
    {
        //ADDR1410250
        //When flexButton1410250 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textArea1410250, textArea1410250Buffer, -30.0, 30.0, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410250Keyboard
        //When ADDR1410250 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButton1410249)
    {
        //ADDR1410249
        //When flexButton1410249 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textArea1410249, textArea1410249Buffer, -30.0, 30.0, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410249Keyboard
        //When ADDR1410249 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButton1410248)
    {
        //ADDR1410248
        //When flexButton1410248 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textArea1410248, textArea1410248Buffer, -30.0, 30.0, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410248Keyboard
        //When ADDR1410248 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButton1410291)
    {
        //ADDR1410291
        //When flexButton1410291 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textArea1410291, textArea1410291Buffer, -3276.8, 3276.7, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410291Keyboard
        //When ADDR1410291 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
}
