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

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxWithBorderBranco.setPosition(52, 231, 78, 29);
    boxWithBorderBranco.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorderBranco.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorderBranco.setBorderSize(1);

    boxVerde4.setPosition(52, 146, 78, 29);
    boxVerde4.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));

    boxVerde3.setPosition(52, 114, 78, 29);
    boxVerde3.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));

    boxVerde2.setPosition(52, 82, 78, 29);
    boxVerde2.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));

    boxVerde.setPosition(51, 26, 78, 29);
    boxVerde.setColor(touchgfx::Color::getColorFromRGB(125, 0, 255));

    textAreaSubTitulo.setXY(208, 177);
    textAreaSubTitulo.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    textAreaSubTitulo.setLinespacing(0);
    textAreaSubTitulo.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5452));

    line1.setPosition(46, 182, 162, 15);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    line1.setPainter(line1Painter);
    line1.setStart(5, 5);
    line1.setEnd(150, 5);
    line1.setLineWidth(4);
    line1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    line1_1.setPosition(276, 181, 159, 15);
    line1_1Painter.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    line1_1.setPainter(line1_1Painter);
    line1_1.setStart(5, 5);
    line1_1.setEnd(150, 5);
    line1_1.setLineWidth(4);
    line1_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    textAreaSubTitulo_1.setXY(201, 60);
    textAreaSubTitulo_1.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));
    textAreaSubTitulo_1.setLinespacing(0);
    textAreaSubTitulo_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5453));

    line1_2.setPosition(46, 64, 162, 15);
    line1_2Painter.setColor(touchgfx::Color::getColorFromRGB(130, 224, 130));
    line1_2.setPainter(line1_2Painter);
    line1_2.setStart(5, 5);
    line1_2.setEnd(142, 5);
    line1_2.setLineWidth(4);
    line1_2.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    line1_1_1.setPosition(286, 63, 149, 16);
    line1_1_1Painter.setColor(touchgfx::Color::getColorFromRGB(130, 224, 130));
    line1_1_1.setPainter(line1_1_1Painter);
    line1_1_1.setStart(6, 5);
    line1_1_1.setEnd(138, 5);
    line1_1_1.setLineWidth(4);
    line1_1_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    textAreaSubTitulo_2.setXY(201, 4);
    textAreaSubTitulo_2.setColor(touchgfx::Color::getColorFromRGB(125, 0, 255));
    textAreaSubTitulo_2.setLinespacing(0);
    textAreaSubTitulo_2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5454));

    line1_3.setPosition(45, 9, 162, 15);
    line1_3Painter.setColor(touchgfx::Color::getColorFromRGB(191, 157, 227));
    line1_3.setPainter(line1_3Painter);
    line1_3.setStart(5, 5);
    line1_3.setEnd(150, 5);
    line1_3.setLineWidth(4);
    line1_3.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    line1_1_2.setPosition(278, 8, 155, 15);
    line1_1_2Painter.setColor(touchgfx::Color::getColorFromRGB(191, 157, 227));
    line1_1_2.setPainter(line1_1_2Painter);
    line1_1_2.setStart(5, 5);
    line1_1_2.setEnd(147, 5);
    line1_1_2.setLineWidth(4);
    line1_1_2.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    textAreaLabel1.setXY(136, 31);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(125, 0, 255));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3712));

    textAreaLabel2.setXY(137, 87);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3713));

    textAreaLabel3.setXY(137, 119);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3714));

    textAreaLabel4.setXY(137, 151);
    textAreaLabel4.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));
    textAreaLabel4.setLinespacing(0);
    textAreaLabel4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3715));

    textAreaLabel6.setXY(137, 234);
    textAreaLabel6.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel6.setLinespacing(0);
    textAreaLabel6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3717));

    textAreaLabel7.setXY(136, 202);
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

    toggleButtonHSW4.setXY(51, 197);
    toggleButtonHSW4.setBitmaps(touchgfx::Bitmap(BITMAP_SETOFFS_ID), touchgfx::Bitmap(BITMAP_SETONS_ID));
    toggleButtonHSW4.setAction(buttonCallback);

    textAreaSenhaGravada.setPosition(52, 231, 78, 29);
    textAreaSenhaGravada.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSenhaGravada.setLinespacing(0);
    Unicode::snprintf(textAreaSenhaGravadaBuffer, TEXTAREASENHAGRAVADA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3730).getText());
    textAreaSenhaGravada.setWildcard(textAreaSenhaGravadaBuffer);
    textAreaSenhaGravada.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3729));

    textArea1410250.setPosition(52, 146, 78, 29);
    textArea1410250.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410250.setLinespacing(0);
    Unicode::snprintf(textArea1410250Buffer, TEXTAREA1410250_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3720).getText());
    textArea1410250.setWildcard(textArea1410250Buffer);
    textArea1410250.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3719));

    textArea1410249.setPosition(52, 114, 78, 29);
    textArea1410249.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410249.setLinespacing(0);
    Unicode::snprintf(textArea1410249Buffer, TEXTAREA1410249_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3722).getText());
    textArea1410249.setWildcard(textArea1410249Buffer);
    textArea1410249.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3721));

    textArea1410248.setPosition(52, 82, 78, 29);
    textArea1410248.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410248.setLinespacing(0);
    Unicode::snprintf(textArea1410248Buffer, TEXTAREA1410248_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3724).getText());
    textArea1410248.setWildcard(textArea1410248Buffer);
    textArea1410248.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3723));

    textArea1410291.setPosition(51, 25, 78, 29);
    textArea1410291.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410291.setLinespacing(0);
    Unicode::snprintf(textArea1410291Buffer, TEXTAREA1410291_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3726).getText());
    textArea1410291.setWildcard(textArea1410291Buffer);
    textArea1410291.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3725));

    flexButtonSenha.setBoxWithBorderPosition(0, 0, 78, 28);
    flexButtonSenha.setBorderSize(5);
    flexButtonSenha.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonSenha.setPosition(52, 232, 78, 28);
    flexButtonSenha.setAlpha(0);
    flexButtonSenha.setAction(flexButtonCallback);

    flexButton1410250.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButton1410250.setBorderSize(5);
    flexButton1410250.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410250.setPosition(52, 146, 78, 29);
    flexButton1410250.setAlpha(0);
    flexButton1410250.setAction(flexButtonCallback);

    flexButton1410249.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButton1410249.setBorderSize(5);
    flexButton1410249.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410249.setPosition(52, 114, 78, 29);
    flexButton1410249.setAlpha(0);
    flexButton1410249.setAction(flexButtonCallback);

    flexButton1410248.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButton1410248.setBorderSize(5);
    flexButton1410248.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410248.setPosition(52, 82, 78, 29);
    flexButton1410248.setAlpha(0);
    flexButton1410248.setAction(flexButtonCallback);

    flexButton1410291.setBoxWithBorderPosition(0, 0, 78, 28);
    flexButton1410291.setBorderSize(5);
    flexButton1410291.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1410291.setPosition(51, 26, 78, 28);
    flexButton1410291.setAlpha(0);
    flexButton1410291.setAction(flexButtonCallback);

    numKeyboardContainer1.setXY(0, 0);
    numKeyboardContainer1.setVisible(false);
    numKeyboardContainer1.setOutOfRangeCallback(numKeyboardContainer1OutOfRangeCallback);
    numKeyboardContainer1.setValidRangeCallback(numKeyboardContainer1ValidRangeCallback);
    numKeyboardContainer1.setHideKeypadTriggerCallback(numKeyboardContainer1HideKeypadTriggerCallback);

    background1.setXY(0, 0);

    add(__background);
    add(boxFundo);
    add(boxWithBorderBranco);
    add(boxVerde4);
    add(boxVerde3);
    add(boxVerde2);
    add(boxVerde);
    add(textAreaSubTitulo);
    add(line1);
    add(line1_1);
    add(textAreaSubTitulo_1);
    add(line1_2);
    add(line1_1_1);
    add(textAreaSubTitulo_2);
    add(line1_3);
    add(line1_1_2);
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
    add(textAreaSenhaGravada);
    add(textArea1410250);
    add(textArea1410249);
    add(textArea1410248);
    add(textArea1410291);
    add(flexButtonSenha);
    add(flexButton1410250);
    add(flexButton1410249);
    add(flexButton1410248);
    add(flexButton1410291);
    add(numKeyboardContainer1);
    add(background1);
}

void Configuracao_3ViewBase::setupScreen()
{
    numKeyboardContainer1.initialize();
    background1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Clear();
    
    ReadWriteModbus485(&textArea1410291, textArea1410291Buffer, 10291, 1, _DOUBLE_, REPEAT);
    ReadWriteModbus485(&textArea1410248, textArea1410248Buffer, 10248, 1, _DOUBLE_, REPEAT);
    ReadWriteModbus485(&textArea1410249, textArea1410249Buffer, 10249, 1, _DOUBLE_, REPEAT);
    ReadWriteModbus485(&textArea1410250, textArea1410250Buffer, 10250, 1, _DOUBLE_, REPEAT);
    
    Update(&toggleButtonHSW4, HSW4);
    Update(&textAreaSenhaGravada, textAreaSenhaGravadaBuffer, Senha_Gravada, _INT_, 0);

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

void Configuracao_3ViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Senha_Gravada = GetNumberTextArea(textAreaSenhaGravadaBuffer);
    
    SetKeyAccessPwdNumKeyboard((uint16_t)Senha_Gravada);
    
    Clear();
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
        HSW4 = toggleButtonHSW4.getState();
        EnableSoundBuzzer(HSW4);
        WriteMemory(50, HSW4);
        SoundBuzzerOn(25);
    }
}

void Configuracao_3ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButtonSenha)
    {
        //SenhaGravada
        //When flexButtonSenha clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaSenhaGravada, textAreaSenhaGravadaBuffer, 0.0, 65535.0, _INT_, 0, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410275Keyboard
        //When SenhaGravada completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButton1410250)
    {
        //ADDR1410250
        //When flexButton1410250 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReferenceRS485(&textArea1410250, textArea1410250Buffer, -30.0, 30.0, _DOUBLE_, 1, 1, 10250);
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
        AddNumKeyboardReferenceRS485(&textArea1410249, textArea1410249Buffer, -30.0, 30.0, _DOUBLE_, 1, 1, 10249);
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
        AddNumKeyboardReferenceRS485(&textArea1410248, textArea1410248Buffer, -30.0, 30.0, _DOUBLE_, 1, 1, 10248);
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
        AddNumKeyboardReferenceRS485(&textArea1410291, textArea1410291Buffer, -3276.8, 3276.7, _DOUBLE_, 1, 1, 10291);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchADDR1410291Keyboard
        //When ADDR1410291 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
}
