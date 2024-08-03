/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/configuracao_7_screen/Configuracao_7ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Configuracao_7ViewBase::Configuracao_7ViewBase() :
    buttonCallback(this, &Configuracao_7ViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &Configuracao_7ViewBase::flexButtonCallbackHandler),
    numKeyboardContainer1OutOfRangeCallback(this, &Configuracao_7ViewBase::numKeyboardContainer1OutOfRangeCallbackHandler),
    numKeyboardContainer1ValidRangeCallback(this, &Configuracao_7ViewBase::numKeyboardContainer1ValidRangeCallbackHandler),
    numKeyboardContainer1HideKeypadTriggerCallback(this, &Configuracao_7ViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxVermelho2.setPosition(66, 192, 78, 29);
    boxVermelho2.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    boxVermelho.setPosition(66, 158, 78, 29);
    boxVermelho.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    boxVerde4.setPosition(66, 117, 78, 29);
    boxVerde4.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    boxVerde3.setPosition(66, 83, 78, 29);
    boxVerde3.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    boxVerde2.setPosition(66, 49, 78, 29);
    boxVerde2.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    boxVerde.setPosition(66, 15, 78, 29);
    boxVerde.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    textAreaLabel1.setXY(151, 16);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3767));

    textAreaLabel2.setXY(151, 50);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3768));

    textAreaLabel3.setXY(151, 84);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3769));

    textAreaLabel4.setXY(151, 118);
    textAreaLabel4.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel4.setLinespacing(0);
    textAreaLabel4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3770));

    textAreaLabel5.setXY(151, 165);
    textAreaLabel5.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel5.setLinespacing(0);
    textAreaLabel5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3771));

    textAreaLabel6.setXY(151, 192);
    textAreaLabel6.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel6.setLinespacing(0);
    textAreaLabel6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3772));

    buttonTelaInicial.setXY(433, 220);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR3_ID), touchgfx::Bitmap(BITMAP_VOLTAR3_ID));
    buttonTelaInicial.setAction(buttonCallback);

    buttonConfiguracao6.setXY(8, 102);
    buttonConfiguracao6.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));
    buttonConfiguracao6.setAction(buttonCallback);

    textAreaPorcResfPresetTempoF1F2.setPosition(66, 192, 78, 29);
    textAreaPorcResfPresetTempoF1F2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaPorcResfPresetTempoF1F2.setLinespacing(0);
    Unicode::snprintf(textAreaPorcResfPresetTempoF1F2Buffer, TEXTAREAPORCRESFPRESETTEMPOF1F2_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3785).getText());
    textAreaPorcResfPresetTempoF1F2.setWildcard(textAreaPorcResfPresetTempoF1F2Buffer);
    textAreaPorcResfPresetTempoF1F2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3784));

    textAreaDiferencialResfriarTempo.setPosition(66, 158, 78, 29);
    textAreaDiferencialResfriarTempo.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaDiferencialResfriarTempo.setLinespacing(0);
    Unicode::snprintf(textAreaDiferencialResfriarTempoBuffer, TEXTAREADIFERENCIALRESFRIARTEMPO_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3787).getText());
    textAreaDiferencialResfriarTempo.setWildcard(textAreaDiferencialResfriarTempoBuffer);
    textAreaDiferencialResfriarTempo.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3786));

    textAreaSpSondaResfCamara.setPosition(66, 117, 78, 29);
    textAreaSpSondaResfCamara.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpSondaResfCamara.setLinespacing(0);
    Unicode::snprintf(textAreaSpSondaResfCamaraBuffer, TEXTAREASPSONDARESFCAMARA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3775).getText());
    textAreaSpSondaResfCamara.setWildcard(textAreaSpSondaResfCamaraBuffer);
    textAreaSpSondaResfCamara.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3774));

    textAreaSpResfriarSonda.setPosition(66, 83, 78, 29);
    textAreaSpResfriarSonda.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpResfriarSonda.setLinespacing(0);
    Unicode::snprintf(textAreaSpResfriarSondaBuffer, TEXTAREASPRESFRIARSONDA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3777).getText());
    textAreaSpResfriarSonda.setWildcard(textAreaSpResfriarSondaBuffer);
    textAreaSpResfriarSonda.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3776));

    textAreaSpResfInternoF1.setPosition(66, 49, 78, 29);
    textAreaSpResfInternoF1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpResfInternoF1.setLinespacing(0);
    Unicode::snprintf(textAreaSpResfInternoF1Buffer, TEXTAREASPRESFINTERNOF1_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3779).getText());
    textAreaSpResfInternoF1.setWildcard(textAreaSpResfInternoF1Buffer);
    textAreaSpResfInternoF1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3778));

    textAreaSpResfEspetoF1.setPosition(66, 15, 78, 29);
    textAreaSpResfEspetoF1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpResfEspetoF1.setLinespacing(0);
    Unicode::snprintf(textAreaSpResfEspetoF1Buffer, TEXTAREASPRESFESPETOF1_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3781).getText());
    textAreaSpResfEspetoF1.setWildcard(textAreaSpResfEspetoF1Buffer);
    textAreaSpResfEspetoF1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3780));

    flexButtonPorcResfPresetTempoF1F2.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButtonPorcResfPresetTempoF1F2.setBorderSize(5);
    flexButtonPorcResfPresetTempoF1F2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonPorcResfPresetTempoF1F2.setPosition(66, 192, 78, 29);
    flexButtonPorcResfPresetTempoF1F2.setAlpha(0);
    flexButtonPorcResfPresetTempoF1F2.setAction(flexButtonCallback);

    flexButtonDiferencialResfriarTempo.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButtonDiferencialResfriarTempo.setBorderSize(5);
    flexButtonDiferencialResfriarTempo.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonDiferencialResfriarTempo.setPosition(66, 158, 78, 29);
    flexButtonDiferencialResfriarTempo.setAlpha(0);
    flexButtonDiferencialResfriarTempo.setAction(flexButtonCallback);

    flexButtonSpSondaResfCamara.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButtonSpSondaResfCamara.setBorderSize(5);
    flexButtonSpSondaResfCamara.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonSpSondaResfCamara.setPosition(66, 117, 78, 29);
    flexButtonSpSondaResfCamara.setAlpha(0);
    flexButtonSpSondaResfCamara.setAction(flexButtonCallback);

    flexButtonSpResfriarSonda.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButtonSpResfriarSonda.setBorderSize(5);
    flexButtonSpResfriarSonda.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonSpResfriarSonda.setPosition(66, 83, 78, 29);
    flexButtonSpResfriarSonda.setAlpha(0);
    flexButtonSpResfriarSonda.setAction(flexButtonCallback);

    flexButtonSpResfInternoF1.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButtonSpResfInternoF1.setBorderSize(5);
    flexButtonSpResfInternoF1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonSpResfInternoF1.setPosition(66, 49, 78, 29);
    flexButtonSpResfInternoF1.setAlpha(0);
    flexButtonSpResfInternoF1.setAction(flexButtonCallback);

    flexButtonSpResfEspetoF1.setBoxWithBorderPosition(0, 0, 78, 29);
    flexButtonSpResfEspetoF1.setBorderSize(5);
    flexButtonSpResfEspetoF1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonSpResfEspetoF1.setPosition(66, 15, 78, 29);
    flexButtonSpResfEspetoF1.setAlpha(0);
    flexButtonSpResfEspetoF1.setAction(flexButtonCallback);

    numKeyboardContainer1.setXY(0, 0);
    numKeyboardContainer1.setVisible(false);
    numKeyboardContainer1.setOutOfRangeCallback(numKeyboardContainer1OutOfRangeCallback);
    numKeyboardContainer1.setValidRangeCallback(numKeyboardContainer1ValidRangeCallback);
    numKeyboardContainer1.setHideKeypadTriggerCallback(numKeyboardContainer1HideKeypadTriggerCallback);

    add(__background);
    add(boxFundo);
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
    add(buttonTelaInicial);
    add(buttonConfiguracao6);
    add(textAreaPorcResfPresetTempoF1F2);
    add(textAreaDiferencialResfriarTempo);
    add(textAreaSpSondaResfCamara);
    add(textAreaSpResfriarSonda);
    add(textAreaSpResfInternoF1);
    add(textAreaSpResfEspetoF1);
    add(flexButtonPorcResfPresetTempoF1F2);
    add(flexButtonDiferencialResfriarTempo);
    add(flexButtonSpSondaResfCamara);
    add(flexButtonSpResfriarSonda);
    add(flexButtonSpResfInternoF1);
    add(flexButtonSpResfEspetoF1);
    add(numKeyboardContainer1);
}

void Configuracao_7ViewBase::setupScreen()
{
    numKeyboardContainer1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Update(&textAreaSpResfEspetoF1, textAreaSpResfEspetoF1Buffer, 15.0, _FP_32BIT_, 1);
    Update(&textAreaSpResfInternoF1, textAreaSpResfInternoF1Buffer, -25.0, _FP_32BIT_, 1);
    Update(&textAreaSpResfriarSonda, textAreaSpResfriarSondaBuffer, 2.0, _FP_32BIT_, 1);
    Update(&textAreaSpSondaResfCamara, textAreaSpSondaResfCamaraBuffer, 0.0, _FP_32BIT_, 1);
    Update(&textAreaDiferencialResfriarTempo, textAreaDiferencialResfriarTempoBuffer, 3.0, _FP_32BIT_, 1);
    Update(&textAreaPorcResfPresetTempoF1F2, textAreaPorcResfPresetTempoF1F2Buffer, 6, _FP_32BIT_, 0);

}

//Called when the screen transition ends
void Configuracao_7ViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Configuracao_7ViewBase::numKeyboardContainer1OutOfRangeCallbackHandler()
{
    //OutOfRangeFIred
    //When numKeyboardContainer1 OutOfRange call OutOfRangeMsg on numKeyboardContainer1
    //Call OutOfRangeMsg
    numKeyboardContainer1.OutOfRangeMsg();
}

void Configuracao_7ViewBase::numKeyboardContainer1ValidRangeCallbackHandler()
{
    //InsideRangeFired
    //When numKeyboardContainer1 ValidRange call InputValidRange on numKeyboardContainer1
    //Call InputValidRange
    numKeyboardContainer1.InputValidRange();
}

void Configuracao_7ViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler()
{
    //HideNumKeyboard
    //When numKeyboardContainer1 HideKeypadTrigger execute C++ code
    //Execute C++ code
    ContainerVisibility(&numKeyboardContainer1, false);
    SoundBuzzerOn(25);
}

void Configuracao_7ViewBase::handleTickEvent()
{

}

void Configuracao_7ViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ContainerClear(&numKeyboardContainer1);
}

void Configuracao_7ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
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
}

void Configuracao_7ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButtonPorcResfPresetTempoF1F2)
    {
        //PorcResfPresetTempoF1F2
        //When flexButtonPorcResfPresetTempoF1F2 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaPorcResfPresetTempoF1F2, textAreaPorcResfPresetTempoF1F2Buffer, 0.0, 10.0, _INT_, 0, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchPorcResfPresetTempoF1F2Keyboard
        //When PorcResfPresetTempoF1F2 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonDiferencialResfriarTempo)
    {
        //DiferencialResfriarTempo
        //When flexButtonDiferencialResfriarTempo clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaDiferencialResfriarTempo, textAreaDiferencialResfriarTempoBuffer, -3276.8, 3276.7, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchDiferencialResfriarTempoKeyboard
        //When DiferencialResfriarTempo completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonSpSondaResfCamara)
    {
        //SpSondaResfCamara
        //When flexButtonSpSondaResfCamara clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaSpSondaResfCamara, textAreaSpSondaResfCamaraBuffer, -99.9, 99.9, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchSpSondaResfCamaraKeyboard
        //When SpSondaResfCamara completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonSpResfriarSonda)
    {
        //SpResfriarSonda
        //When flexButtonSpResfriarSonda clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaSpResfriarSonda, textAreaSpResfriarSondaBuffer, -3276.8, 3276.7, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchSpResfriarSondaKeyboard
        //When SpResfriarSonda completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonSpResfInternoF1)
    {
        //SpResfInternoF1
        //When flexButtonSpResfInternoF1 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaSpResfInternoF1, textAreaSpResfInternoF1Buffer, -99.9, 99.9, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchSpResfInternoF1Keyboard
        //When SpResfInternoF1 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonSpResfEspetoF1)
    {
        //SpResfEspetoF1
        //When flexButtonSpResfEspetoF1 clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaSpResfEspetoF1, textAreaSpResfEspetoF1Buffer, -3276.8, 3276.7, _FP_32BIT_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchSpResfEspetoF1Keyboard
        //When SpResfEspetoF1 completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
}
