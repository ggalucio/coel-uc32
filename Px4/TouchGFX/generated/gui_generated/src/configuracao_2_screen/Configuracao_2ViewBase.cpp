/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/configuracao_2_screen/Configuracao_2ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Configuracao_2ViewBase::Configuracao_2ViewBase() :
    buttonCallback(this, &Configuracao_2ViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &Configuracao_2ViewBase::flexButtonCallbackHandler),
    numKeyboardContainer1OutOfRangeCallback(this, &Configuracao_2ViewBase::numKeyboardContainer1OutOfRangeCallbackHandler),
    numKeyboardContainer1ValidRangeCallback(this, &Configuracao_2ViewBase::numKeyboardContainer1ValidRangeCallbackHandler),
    numKeyboardContainer1HideKeypadTriggerCallback(this, &Configuracao_2ViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler),
    numKeyboardContainer1EnterCallback(this, &Configuracao_2ViewBase::numKeyboardContainer1EnterCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxVermelho3.setPosition(66, 226, 78, 29);
    boxVermelho3.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    boxVermelho2.setPosition(66, 192, 78, 29);
    boxVermelho2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    boxVermelho.setPosition(66, 158, 78, 29);
    boxVermelho.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    boxVerde4.setPosition(66, 117, 78, 29);
    boxVerde4.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));

    boxVerde3.setPosition(66, 83, 78, 29);
    boxVerde3.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));

    boxVerde2.setPosition(66, 49, 78, 29);
    boxVerde2.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));

    boxVerde.setPosition(66, 15, 78, 29);
    boxVerde.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));

    textAreaLabel1.setXY(151, 23);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(0, 184, 0));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3690));

    textAreaLabel2.setXY(151, 57);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(0, 184, 0));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3691));

    textAreaLabel3.setXY(151, 91);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(0, 184, 0));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3692));

    textAreaLabel4.setXY(151, 125);
    textAreaLabel4.setColor(touchgfx::Color::getColorFromRGB(0, 184, 0));
    textAreaLabel4.setLinespacing(0);
    textAreaLabel4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3693));

    textAreaLabel5.setXY(151, 159);
    textAreaLabel5.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaLabel5.setLinespacing(0);
    textAreaLabel5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3703));

    textAreaLabel6.setXY(151, 193);
    textAreaLabel6.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaLabel6.setLinespacing(0);
    textAreaLabel6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3704));

    textAreaLabel7.setXY(151, 234);
    textAreaLabel7.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaLabel7.setLinespacing(0);
    textAreaLabel7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3705));

    buttonTelaInicial.setXY(433, 220);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR3_ID), touchgfx::Bitmap(BITMAP_VOLTAR3_ID));
    buttonTelaInicial.setAction(buttonCallback);

    buttonConfiguracao3.setXY(443, 102);
    buttonConfiguracao3.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE2_ID), touchgfx::Bitmap(BITMAP_AVANCE2_ID));
    buttonConfiguracao3.setAction(buttonCallback);

    buttonConfiguracao.setXY(8, 102);
    buttonConfiguracao.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));
    buttonConfiguracao.setAction(buttonCallback);

    textArea1410270.setPosition(66, 226, 78, 29);
    textArea1410270.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410270.setLinespacing(0);
    Unicode::snprintf(textArea1410270Buffer, TEXTAREA1410270_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3707).getText());
    textArea1410270.setWildcard(textArea1410270Buffer);
    textArea1410270.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3706));

    textArea1410275.setPosition(66, 192, 78, 29);
    textArea1410275.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410275.setLinespacing(0);
    Unicode::snprintf(textArea1410275Buffer, TEXTAREA1410275_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3709).getText());
    textArea1410275.setWildcard(textArea1410275Buffer);
    textArea1410275.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3708));

    textArea1410272.setPosition(66, 158, 78, 29);
    textArea1410272.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410272.setLinespacing(0);
    Unicode::snprintf(textArea1410272Buffer, TEXTAREA1410272_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3711).getText());
    textArea1410272.setWildcard(textArea1410272Buffer);
    textArea1410272.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3710));

    textAreaDiferencialConservarResfriar.setPosition(66, 117, 78, 29);
    textAreaDiferencialConservarResfriar.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaDiferencialConservarResfriar.setLinespacing(0);
    Unicode::snprintf(textAreaDiferencialConservarResfriarBuffer, TEXTAREADIFERENCIALCONSERVARRESFRIAR_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3696).getText());
    textAreaDiferencialConservarResfriar.setWildcard(textAreaDiferencialConservarResfriarBuffer);
    textAreaDiferencialConservarResfriar.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3695));

    textAreaSpConservarResfriar.setPosition(66, 83, 78, 29);
    textAreaSpConservarResfriar.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpConservarResfriar.setLinespacing(0);
    Unicode::snprintf(textAreaSpConservarResfriarBuffer, TEXTAREASPCONSERVARRESFRIAR_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3698).getText());
    textAreaSpConservarResfriar.setWildcard(textAreaSpConservarResfriarBuffer);
    textAreaSpConservarResfriar.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3697));

    textAreaDiferencialConservarCongelar.setPosition(66, 49, 78, 29);
    textAreaDiferencialConservarCongelar.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaDiferencialConservarCongelar.setLinespacing(0);
    Unicode::snprintf(textAreaDiferencialConservarCongelarBuffer, TEXTAREADIFERENCIALCONSERVARCONGELAR_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3700).getText());
    textAreaDiferencialConservarCongelar.setWildcard(textAreaDiferencialConservarCongelarBuffer);
    textAreaDiferencialConservarCongelar.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3699));

    textAreaSpConservarCongelar.setPosition(66, 15, 78, 29);
    textAreaSpConservarCongelar.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpConservarCongelar.setLinespacing(0);
    Unicode::snprintf(textAreaSpConservarCongelarBuffer, TEXTAREASPCONSERVARCONGELAR_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3702).getText());
    textAreaSpConservarCongelar.setWildcard(textAreaSpConservarCongelarBuffer);
    textAreaSpConservarCongelar.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3701));

    flexButton1410270.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButton1410270.setBorderSize(5);
    flexButton1410270.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410270.setPosition(66, 226, 78, 29);
    flexButton1410270.setAlpha(0);
    flexButton1410270.setAction(flexButtonCallback);

    flexButton1410275.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButton1410275.setBorderSize(5);
    flexButton1410275.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410275.setPosition(66, 192, 78, 29);
    flexButton1410275.setAlpha(0);
    flexButton1410275.setAction(flexButtonCallback);

    flexButton1410272.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButton1410272.setBorderSize(5);
    flexButton1410272.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410272.setPosition(66, 158, 78, 29);
    flexButton1410272.setAlpha(0);
    flexButton1410272.setAction(flexButtonCallback);

    flexButtonDiferencialConservarResfriar.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButtonDiferencialConservarResfriar.setBorderSize(5);
    flexButtonDiferencialConservarResfriar.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonDiferencialConservarResfriar.setPosition(66, 117, 78, 29);
    flexButtonDiferencialConservarResfriar.setAlpha(0);
    flexButtonDiferencialConservarResfriar.setAction(flexButtonCallback);

    flexButtonSpConservarResfriar.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButtonSpConservarResfriar.setBorderSize(5);
    flexButtonSpConservarResfriar.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonSpConservarResfriar.setPosition(66, 83, 78, 29);
    flexButtonSpConservarResfriar.setAlpha(0);
    flexButtonSpConservarResfriar.setAction(flexButtonCallback);

    flexButtonDiferencialConservarCongelar.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButtonDiferencialConservarCongelar.setBorderSize(5);
    flexButtonDiferencialConservarCongelar.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonDiferencialConservarCongelar.setPosition(66, 49, 78, 29);
    flexButtonDiferencialConservarCongelar.setAlpha(0);
    flexButtonDiferencialConservarCongelar.setAction(flexButtonCallback);

    flexButtonSpConservarCongelar.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButtonSpConservarCongelar.setBorderSize(5);
    flexButtonSpConservarCongelar.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonSpConservarCongelar.setPosition(66, 15, 78, 29);
    flexButtonSpConservarCongelar.setAlpha(0);
    flexButtonSpConservarCongelar.setAction(flexButtonCallback);

    numKeyboardContainer1.setXY(0, 0);
    numKeyboardContainer1.setVisible(false);
    numKeyboardContainer1.setOutOfRangeCallback(numKeyboardContainer1OutOfRangeCallback);
    numKeyboardContainer1.setValidRangeCallback(numKeyboardContainer1ValidRangeCallback);
    numKeyboardContainer1.setHideKeypadTriggerCallback(numKeyboardContainer1HideKeypadTriggerCallback);
    numKeyboardContainer1.setEnterCallback(numKeyboardContainer1EnterCallback);

    imageStatusPorta.setXY(200, 0);
    imageStatusPorta.setVisible(false);
    imageStatusPorta.setBitmap(touchgfx::Bitmap(BITMAP_PORTA_ID));

    textAreaStatusPorta.setXY(98, 13);
    textAreaStatusPorta.setVisible(false);
    textAreaStatusPorta.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaStatusPorta.setLinespacing(0);
    Unicode::snprintf(textAreaStatusPortaBuffer, TEXTAREASTATUSPORTA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4134).getText());
    textAreaStatusPorta.setWildcard(textAreaStatusPortaBuffer);
    textAreaStatusPorta.resizeToCurrentText();
    textAreaStatusPorta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4133));

    add(__background);
    add(boxFundo);
    add(boxVermelho3);
    add(boxVermelho2);
    add(boxVermelho);
    add(boxVerde4);
    add(boxVerde3);
    add(boxVerde2);
    add(boxVerde);
    add(textAreaLabel1);
    add(textAreaLabel2);
    add(textAreaLabel3);
    add(textAreaLabel4);
    add(textAreaLabel5);
    add(textAreaLabel6);
    add(textAreaLabel7);
    add(buttonTelaInicial);
    add(buttonConfiguracao3);
    add(buttonConfiguracao);
    add(textArea1410270);
    add(textArea1410275);
    add(textArea1410272);
    add(textAreaDiferencialConservarResfriar);
    add(textAreaSpConservarResfriar);
    add(textAreaDiferencialConservarCongelar);
    add(textAreaSpConservarCongelar);
    add(flexButton1410270);
    add(flexButton1410275);
    add(flexButton1410272);
    add(flexButtonDiferencialConservarResfriar);
    add(flexButtonSpConservarResfriar);
    add(flexButtonDiferencialConservarCongelar);
    add(flexButtonSpConservarCongelar);
    add(numKeyboardContainer1);
    add(imageStatusPorta);
    add(textAreaStatusPorta);
}

void Configuracao_2ViewBase::setupScreen()
{
    numKeyboardContainer1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    W_HDW5000 = 17;
    
    Clear();
    ReadWriteModbus485(&textAreaStatusPorta, textAreaStatusPortaBuffer, "553", 0, _INT_, REPEAT);
    
    Update(&textAreaSpConservarCongelar, textAreaSpConservarCongelarBuffer, SP_Conservar_Congelar / 10, _FP_32BIT_, 1);
    Update(&textAreaDiferencialConservarCongelar, textAreaDiferencialConservarCongelarBuffer, Diferencial_Conservar_COngelar / 10, _FP_32BIT_, 1);
    Update(&textAreaSpConservarResfriar, textAreaSpConservarResfriarBuffer, SP_Conservar_Resfriar / 10, _FP_32BIT_, 1);
    Update(&textAreaDiferencialConservarResfriar, textAreaDiferencialConservarResfriarBuffer, Diferencial_Conservar_Resfriar / 10, _FP_32BIT_, 1);
    ReadWriteModbus485(&textArea1410272, textArea1410272Buffer, "10272", 1, _DOUBLE_, ONCE);
    ReadWriteModbus485(&textArea1410275, textArea1410275Buffer, "10275", 1, _DOUBLE_, ONCE);
    ReadWriteModbus485(&textArea1410270, textArea1410270Buffer, "10270", 2, _DOUBLE_, ONCE);

}

//Called when the screen transition ends
void Configuracao_2ViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Configuracao_2ViewBase::numKeyboardContainer1OutOfRangeCallbackHandler()
{
    //OutOfRangeFIred
    //When numKeyboardContainer1 OutOfRange call OutOfRangeMsg on numKeyboardContainer1
    //Call OutOfRangeMsg
    numKeyboardContainer1.OutOfRangeMsg();
}

void Configuracao_2ViewBase::numKeyboardContainer1ValidRangeCallbackHandler()
{
    //InsideRangeFired
    //When numKeyboardContainer1 ValidRange call InputValidRange on numKeyboardContainer1
    //Call InputValidRange
    numKeyboardContainer1.InputValidRange();
}

void Configuracao_2ViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler()
{
    //HideNumKeyboard
    //When numKeyboardContainer1 HideKeypadTrigger execute C++ code
    //Execute C++ code
    ContainerVisibility(&numKeyboardContainer1, false);
    SoundBuzzerOn(25);
}

void Configuracao_2ViewBase::numKeyboardContainer1EnterCallbackHandler()
{
    //Enterkeyboard
    //When numKeyboardContainer1 Enter execute C++ code
    //Execute C++ code
    double value = 0;
    
    if (addressModbusRS458 == 10272)
    {
    	//UpdateModbus485("10272", (value = GetNumberTextArea(textArea1410272Buffer)) < 0.0 ? value + 65536.0 : value, _DOUBLE_);
    	//WriteModbus485("10272", 2);
    
    	WriteModbus485(&textArea1410272, textArea1410272Buffer, "10272", 1);
    	WriteModbus485("10272", 2);
    	Wait(100);
    }
    
    if (addressModbusRS458 == 10275)
    {
    	UpdateModbus485("10275", (value = GetNumberTextArea(textArea1410275Buffer)) < 0.0 ? value + 65536.0 : value, _DOUBLE_);
    	WriteModbus485("10275", 2);
    	Wait(100);
    }
}

void Configuracao_2ViewBase::handleTickEvent()
{
    //HandleTickEvent
    //When handleTickEvent is called execute C++ code
    //Execute C++ code
    double value = 0.0;
    if ((value = GetNumberTextArea(textArea1410272Buffer)) > 3276.7) Update(&textArea1410272, textArea1410272Buffer, GetFormatToNegative(value, 16), _DOUBLE_, 1);
    if ((value = GetNumberTextArea(textArea1410275Buffer)) > 3276.7) Update(&textArea1410275, textArea1410275Buffer, GetFormatToNegative(value, 16), _DOUBLE_, 1);
    
    imageStatusPorta.setVisible(touchgfx::Unicode::atoi(textAreaStatusPortaBuffer) == 1 ? true : false);
    invalidate();
}

void Configuracao_2ViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    SP_Conservar_Congelar = 10 * GetNumberTextArea(textAreaSpConservarCongelarBuffer);
    Diferencial_Conservar_COngelar = 10 * GetNumberTextArea(textAreaDiferencialConservarCongelarBuffer);
    SP_Conservar_Resfriar = 10 * GetNumberTextArea(textAreaSpConservarResfriarBuffer);
    Diferencial_Conservar_Resfriar = 10 * GetNumberTextArea(textAreaDiferencialConservarResfriarBuffer);
    
    Clear();
    ClearOthers();
    ContainerClear(&numKeyboardContainer1);
}

void Configuracao_2ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonTelaInicial)
    {
        //TelaInicial
        //When buttonTelaInicial clicked change screen to Tela_Inicial
        //Go to Tela_Inicial with no screen transition
        application().gotoTela_InicialScreenNoTransition();
    }
    else if (&src == &buttonConfiguracao3)
    {
        //Configuracao3
        //When buttonConfiguracao3 clicked change screen to Configuracao_3
        //Go to Configuracao_3 with no screen transition
        application().gotoConfiguracao_3ScreenNoTransition();
    }
    else if (&src == &buttonConfiguracao)
    {
        //Configuracao
        //When buttonConfiguracao clicked change screen to Configuracao
        //Go to Configuracao with no screen transition
        application().gotoConfiguracaoScreenNoTransition();
    }
}

void Configuracao_2ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButton1410270)
    {
        //ADDR1410270
        //When flexButton1410270 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReferenceRS485(&textArea1410270, textArea1410270Buffer, 0.0, 655.35, _DOUBLE_, 2, 1);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410270Keyboard
        //When ADDR1410270 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButton1410275)
    {
        //ADDR1410275
        //When flexButton1410275 clicked execute C++ code
        //Execute C++ code
        addressModbusRS458 = 10275;
        AddNumKeyboardReference(&textArea1410275, textArea1410275Buffer, -3276.8, 3276.7, _DOUBLE_, 1, 1);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410275Keyboard
        //When ADDR1410275 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButton1410272)
    {
        //ADDR1410272
        //When flexButton1410272 clicked execute C++ code
        //Execute C++ code
        addressModbusRS458 = 10272;
        AddNumKeyboardReference(&textArea1410272, textArea1410272Buffer, -3276.8, 3276.7, _DOUBLE_, 1, 1);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410272Keyboard
        //When ADDR1410272 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonDiferencialConservarResfriar)
    {
        //DiferencialConservarResfriar
        //When flexButtonDiferencialConservarResfriar clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaDiferencialConservarResfriar, textAreaDiferencialConservarResfriarBuffer, -3276.8, 3276.7, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchDiferencialConservarResfriarKeyboard
        //When DiferencialConservarResfriar completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonSpConservarResfriar)
    {
        //SpConservarResfriar
        //When flexButtonSpConservarResfriar clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaSpConservarResfriar, textAreaSpConservarResfriarBuffer, -3276.8, 3276.7, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchSpConservarResfriarKeyboard
        //When SpConservarResfriar completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonDiferencialConservarCongelar)
    {
        //DiferencialConservarCongelar
        //When flexButtonDiferencialConservarCongelar clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaDiferencialConservarCongelar, textAreaDiferencialConservarCongelarBuffer, -3276.8, 3276.7, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchDiferencialConservarCongelarKeyboard
        //When DiferencialConservarCongelar completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonSpConservarCongelar)
    {
        //SpConservarCongelar
        //When flexButtonSpConservarCongelar clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaSpConservarCongelar, textAreaSpConservarCongelarBuffer, -3276.8, 3276.7, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchSpConservarCongelarKeyboard
        //When SpConservarCongelar completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
}
