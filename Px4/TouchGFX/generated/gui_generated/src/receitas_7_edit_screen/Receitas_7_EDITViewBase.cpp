/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/receitas_7_edit_screen/Receitas_7_EDITViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Receitas_7_EDITViewBase::Receitas_7_EDITViewBase() :
    buttonCallback(this, &Receitas_7_EDITViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &Receitas_7_EDITViewBase::flexButtonCallbackHandler),
    keyboardContainer21HideKeyboardCallback(this, &Receitas_7_EDITViewBase::keyboardContainer21HideKeyboardCallbackHandler),
    numKeyboardContainer1HideKeypadTriggerCallback(this, &Receitas_7_EDITViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler),
    numKeyboardContainer1OutOfRangeCallback(this, &Receitas_7_EDITViewBase::numKeyboardContainer1OutOfRangeCallbackHandler),
    numKeyboardContainer1ValidRangeCallback(this, &Receitas_7_EDITViewBase::numKeyboardContainer1ValidRangeCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxFundoAzul.setPosition(0, 0, 480, 35);
    boxFundoAzul.setColor(touchgfx::Color::getColorFromRGB(255, 128, 64));

    line1.setPosition(0, 182, 162, 15);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 128, 64));
    line1.setPainter(line1Painter);
    line1.setStart(5, 5);
    line1.setEnd(150, 5);
    line1.setLineWidth(2);
    line1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    line1_1.setPosition(318, 182, 162, 15);
    line1_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 128, 64));
    line1_1.setPainter(line1_1Painter);
    line1_1.setStart(5, 5);
    line1_1.setEnd(150, 5);
    line1_1.setLineWidth(2);
    line1_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);

    textArea1_3.setXY(159, 178);
    textArea1_3.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_3.setLinespacing(0);
    textArea1_3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5479));

    textArea1.setXY(8, 58);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5501));

    textArea1_1.setXY(8, 93);
    textArea1_1.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_1.setLinespacing(0);
    textArea1_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5502));

    textArea1_2.setXY(8, 138);
    textArea1_2.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_2.setLinespacing(0);
    textArea1_2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5503));

    textAreaTitle.setPosition(48, 4, 287, 25);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTitle.setLinespacing(0);
    Unicode::snprintf(textAreaTitleBuffer, TEXTAREATITLE_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4752).getText());
    textAreaTitle.setWildcard(textAreaTitleBuffer);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4751));

    image1.setXY(8, 4);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_CHAPEU_ID));

    box1.setPosition(108, 49, 262, 31);
    box1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 191));

    toggleButtonRXCongResf.setXY(58, 226);
    toggleButtonRXCongResf.setBitmaps(touchgfx::Bitmap(BITMAP_CONGELARAA_ID), touchgfx::Bitmap(BITMAP_REFRIARAA_ID));
    toggleButtonRXCongResf.setAction(buttonCallback);

    toggleButtonRXhardSoft.setXY(213, 226);
    toggleButtonRXhardSoft.setBitmaps(touchgfx::Bitmap(BITMAP_SOFTS_ID), touchgfx::Bitmap(BITMAP_HARDS_ID));
    toggleButtonRXhardSoft.setAction(buttonCallback);

    toggleButtonRXConservYn.setXY(333, 221);
    toggleButtonRXConservYn.setBitmaps(touchgfx::Bitmap(BITMAP_COFF_ID), touchgfx::Bitmap(BITMAP_BUTTONON_ID));
    toggleButtonRXConservYn.setAction(buttonCallback);

    toggleButtonRXTimeTemp.setXY(108, 85);
    toggleButtonRXTimeTemp.setBitmaps(touchgfx::Bitmap(BITMAP_TEMPO_ID), touchgfx::Bitmap(BITMAP_TEMPERATURA_ID));
    toggleButtonRXTimeTemp.setAction(buttonCallback);

    textAreaReceitaXDesc.setPosition(108, 49, 262, 31);
    textAreaReceitaXDesc.setColor(touchgfx::Color::getColorFromRGB(48, 72, 167));
    textAreaReceitaXDesc.setLinespacing(0);
    Unicode::snprintf(textAreaReceitaXDescBuffer, TEXTAREARECEITAXDESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4759).getText());
    textAreaReceitaXDesc.setWildcard(textAreaReceitaXDescBuffer);
    textAreaReceitaXDesc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4758));

    textArea2.setXY(424, 62);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5469));

    buttonSalvar.setXY(429, 80);
    buttonSalvar.setBitmaps(touchgfx::Bitmap(BITMAP_SALVAR_ID), touchgfx::Bitmap(BITMAP_SALVAR_ID));
    buttonSalvar.setAction(buttonCallback);

    flexButtonReceitaXDesc.setBoxWithBorderPosition(0, 0, 259, 31);
    flexButtonReceitaXDesc.setBorderSize(5);
    flexButtonReceitaXDesc.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonReceitaXDesc.setPosition(109, 49, 259, 31);
    flexButtonReceitaXDesc.setAlpha(0);
    flexButtonReceitaXDesc.setAction(flexButtonCallback);

    containerTemperatura.setPosition(275, 121, 124, 46);

    box3.setPosition(0, 4, 94, 34);
    box3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
    containerTemperatura.add(box3);

    textArea1_2_1_C.setXY(104, 10);
    textArea1_2_1_C.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_2_1_C.setLinespacing(0);
    textArea1_2_1_C.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4761));
    containerTemperatura.add(textArea1_2_1_C);

    textAreaTemperaturaReceita.setPosition(1, 4, 91, 34);
    textAreaTemperaturaReceita.setColor(touchgfx::Color::getColorFromRGB(0, 0, 128));
    textAreaTemperaturaReceita.setLinespacing(0);
    Unicode::snprintf(textAreaTemperaturaReceitaBuffer, TEXTAREATEMPERATURARECEITA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4763).getText());
    textAreaTemperaturaReceita.setWildcard(textAreaTemperaturaReceitaBuffer);
    textAreaTemperaturaReceita.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4762));
    containerTemperatura.add(textAreaTemperaturaReceita);

    flexButtonTemperaturaReceita.setBoxWithBorderPosition(0, 0, 91, 34);
    flexButtonTemperaturaReceita.setBorderSize(5);
    flexButtonTemperaturaReceita.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonTemperaturaReceita.setPosition(1, 4, 91, 34);
    flexButtonTemperaturaReceita.setAlpha(0);
    flexButtonTemperaturaReceita.setAction(flexButtonCallback);
    containerTemperatura.add(flexButtonTemperaturaReceita);

    containerTempo.setPosition(102, 121, 137, 46);

    box2.setPosition(5, 4, 92, 34);
    box2.setColor(touchgfx::Color::getColorFromRGB(128, 255, 255));
    containerTempo.add(box2);

    textArea1_2_1.setXY(102, 12);
    textArea1_2_1.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_2_1.setLinespacing(0);
    textArea1_2_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4764));
    containerTempo.add(textArea1_2_1);

    textAreaTempoReceitaX.setPosition(6, 4, 91, 34);
    textAreaTempoReceitaX.setColor(touchgfx::Color::getColorFromRGB(0, 0, 128));
    textAreaTempoReceitaX.setLinespacing(0);
    Unicode::snprintf(textAreaTempoReceitaXBuffer, TEXTAREATEMPORECEITAX_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4766).getText());
    textAreaTempoReceitaX.setWildcard(textAreaTempoReceitaXBuffer);
    textAreaTempoReceitaX.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4765));
    containerTempo.add(textAreaTempoReceitaX);

    flexButtonTempoReceitaX.setBoxWithBorderPosition(0, 0, 91, 34);
    flexButtonTempoReceitaX.setBorderSize(5);
    flexButtonTempoReceitaX.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonTempoReceitaX.setPosition(6, 4, 91, 34);
    flexButtonTempoReceitaX.setAlpha(0);
    flexButtonTempoReceitaX.setAction(flexButtonCallback);
    containerTempo.add(flexButtonTempoReceitaX);

    keyboardContainer21.setXY(0, 0);
    keyboardContainer21.setVisible(false);
    keyboardContainer21.setHideKeyboardCallback(keyboardContainer21HideKeyboardCallback);

    numKeyboardContainer1.setXY(0, 0);
    numKeyboardContainer1.setVisible(false);
    numKeyboardContainer1.setHideKeypadTriggerCallback(numKeyboardContainer1HideKeypadTriggerCallback);
    numKeyboardContainer1.setOutOfRangeCallback(numKeyboardContainer1OutOfRangeCallback);
    numKeyboardContainer1.setValidRangeCallback(numKeyboardContainer1ValidRangeCallback);

    background1.setXY(0, 0);

    add(__background);
    add(boxFundo);
    add(boxFundoAzul);
    add(line1);
    add(line1_1);
    add(textArea1_3);
    add(textArea1);
    add(textArea1_1);
    add(textArea1_2);
    add(textAreaTitle);
    add(image1);
    add(box1);
    add(toggleButtonRXCongResf);
    add(toggleButtonRXhardSoft);
    add(toggleButtonRXConservYn);
    add(toggleButtonRXTimeTemp);
    add(textAreaReceitaXDesc);
    add(textArea2);
    add(buttonSalvar);
    add(flexButtonReceitaXDesc);
    add(containerTemperatura);
    add(containerTempo);
    add(keyboardContainer21);
    add(numKeyboardContainer1);
    add(background1);
}

void Receitas_7_EDITViewBase::setupScreen()
{
    keyboardContainer21.initialize();
    numKeyboardContainer1.initialize();
    background1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Update(&textAreaReceitaXDesc, textAreaReceitaXDescBuffer, Receita_7_desc, 20);
    Update(&toggleButtonRXTimeTemp, R7_time_temp);
    Update(&textAreaTempoReceitaX, textAreaTempoReceitaXBuffer, Tempo_receita_7, _DOUBLE_, 0);
    Update(&textAreaTemperaturaReceita, textAreaTemperaturaReceitaBuffer, Temperatura_receita_07 / 10.0, _DOUBLE_, 1);
    Update(&toggleButtonRXCongResf, R7_cong_resf);
    Update(&toggleButtonRXhardSoft, R7_Hard_Soft);
    Update(&toggleButtonRXConservYn, R7_Conserv_yn);

}

//Called when the screen transition ends
void Receitas_7_EDITViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    AddJob(&textAreaReceitaXDesc, textAreaReceitaXDescBuffer, 5, _STRING_, 0);
    AddJob(&toggleButtonRXTimeTemp, 3);
    AddJob(&textAreaTempoReceitaX, textAreaTempoReceitaXBuffer, 1, _INT_, 0);
    AddJob(&textAreaTemperaturaReceita, textAreaTemperaturaReceitaBuffer, 2, _FP_32BIT_, 1);
    AddJob(&toggleButtonRXCongResf, 4);
    AddJob(&toggleButtonRXhardSoft, 6);
    AddJob(&toggleButtonRXConservYn, 7);
    
    SoundBuzzerOn(25);
}

void Receitas_7_EDITViewBase::keyboardContainer21HideKeyboardCallbackHandler()
{
    //HideNameKeyboard
    //When keyboardContainer21 HideKeyboard execute C++ code
    //Execute C++ code
    ContainerVisibility(&keyboardContainer21, false);
    SoundBuzzerOn(25);
}

void Receitas_7_EDITViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler()
{
    //HideNumKeyboard
    //When numKeyboardContainer1 HideKeypadTrigger execute C++ code
    //Execute C++ code
    ContainerVisibility(&numKeyboardContainer1, false);
    SoundBuzzerOn(25);
}

void Receitas_7_EDITViewBase::numKeyboardContainer1OutOfRangeCallbackHandler()
{
    //OutOfRangeFIred
    //When numKeyboardContainer1 OutOfRange call OutOfRangeMsg on numKeyboardContainer1
    //Call OutOfRangeMsg
    numKeyboardContainer1.OutOfRangeMsg();
}

void Receitas_7_EDITViewBase::numKeyboardContainer1ValidRangeCallbackHandler()
{
    //InsideRangeFired
    //When numKeyboardContainer1 ValidRange call InputValidRange on numKeyboardContainer1
    //Call InputValidRange
    numKeyboardContainer1.InputValidRange();
}

void Receitas_7_EDITViewBase::handleTickEvent()
{
    //HandleTickEvent
    //When handleTickEvent is called execute C++ code
    //Execute C++ code
    ContainerVisibility(&containerTempo, !toggleButtonRXTimeTemp.getState());
    ContainerVisibility(&containerTemperatura, toggleButtonRXTimeTemp.getState());
    
    if (toggleButtonRXTimeTemp.getState() == false && toggleButtonRXCongResf.getState() == true)
    	ButtonVisibility(&toggleButtonRXhardSoft, true);
    else
    	ButtonVisibility(&toggleButtonRXhardSoft, false);
}

void Receitas_7_EDITViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    CopyTextArea(Receita_7_desc, textAreaReceitaXDescBuffer, 20);
    
    R7_time_temp           = toggleButtonRXTimeTemp.getState();
    Tempo_receita_7        = GetNumberTextArea(textAreaTempoReceitaXBuffer);
    Temperatura_receita_07 = GetNumberTextArea(textAreaTemperaturaReceitaBuffer) * 10.0;
    R7_cong_resf           = toggleButtonRXCongResf.getState();
    R7_Hard_Soft           = toggleButtonRXhardSoft.getState();
    R7_Conserv_yn          = toggleButtonRXConservYn.getState();
    
    UpdateJobs();
    Wait(50);
    
    Clear();
}

void Receitas_7_EDITViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &toggleButtonRXCongResf)
    {
        //RXCongResf
        //When toggleButtonRXCongResf clicked execute C++ code
        //Execute C++ code
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButtonRXhardSoft)
    {
        //RXhardSoft
        //When toggleButtonRXhardSoft clicked execute C++ code
        //Execute C++ code
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButtonRXConservYn)
    {
        //RXConservYn
        //When toggleButtonRXConservYn clicked execute C++ code
        //Execute C++ code
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButtonRXTimeTemp)
    {
        //RXTimeTemp
        //When toggleButtonRXTimeTemp clicked execute C++ code
        //Execute C++ code
        SoundBuzzerOn(25);
    }
    else if (&src == &buttonSalvar)
    {
        //Salvar
        //When buttonSalvar clicked execute C++ code
        //Execute C++ code
        UpdateJobs();
        Wait(50);
        

        //Exit
        //When Salvar completed change screen to Receitas_2
        //Go to Receitas_2 with no screen transition
        application().gotoReceitas_2ScreenNoTransition();
    }
}

void Receitas_7_EDITViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButtonReceitaXDesc)
    {
        //ReceitaDescricao
        //When flexButtonReceitaXDesc clicked execute C++ code
        //Execute C++ code
        AddKeyboardReference(&textAreaReceitaXDesc, textAreaReceitaXDescBuffer);
        keyboardContainer21.restore();
        ContainerVisibility(&keyboardContainer21, true);
        SoundBuzzerOn(25);

        //LaunchNameKeyboard
        //When ReceitaDescricao completed call LaunchKeyboard on keyboardContainer21
        //Call LaunchKeyboard
        keyboardContainer21.LaunchKeyboard();
    }
    else if (&src == &flexButtonTemperaturaReceita)
    {
        //TemperaturaReceita
        //When flexButtonTemperaturaReceita clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaTemperaturaReceita, textAreaTemperaturaReceitaBuffer, -40.0, 10.0, _DOUBLE_, 1, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchTemperaturaReceitaKeyboard
        //When TemperaturaReceita completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
    else if (&src == &flexButtonTempoReceitaX)
    {
        //TempoReceita
        //When flexButtonTempoReceitaX clicked execute C++ code
        //Execute C++ code
        AddNumKeyboardReference(&textAreaTempoReceitaX, textAreaTempoReceitaXBuffer, 0, 9999, _INT_, 0, 0);
        ContainerVisibility(&numKeyboardContainer1, true);
        SoundBuzzerOn(25);

        //LaunchTempoReceitaKeyboard
        //When TempoReceita completed call LaunchNumericalKeyboard on numKeyboardContainer1
        //Call LaunchNumericalKeyboard
        numKeyboardContainer1.LaunchNumericalKeyboard();
    }
}
