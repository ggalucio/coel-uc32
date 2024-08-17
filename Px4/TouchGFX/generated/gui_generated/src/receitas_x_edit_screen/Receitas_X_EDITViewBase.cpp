/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/receitas_x_edit_screen/Receitas_X_EDITViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Receitas_X_EDITViewBase::Receitas_X_EDITViewBase() :
    buttonCallback(this, &Receitas_X_EDITViewBase::buttonCallbackHandler),
    flexButtonCallback(this, &Receitas_X_EDITViewBase::flexButtonCallbackHandler),
    keyboardContainer21HideKeyboardCallback(this, &Receitas_X_EDITViewBase::keyboardContainer21HideKeyboardCallbackHandler),
    numKeyboardContainer1HideKeypadTriggerCallback(this, &Receitas_X_EDITViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler),
    numKeyboardContainer1OutOfRangeCallback(this, &Receitas_X_EDITViewBase::numKeyboardContainer1OutOfRangeCallbackHandler),
    numKeyboardContainer1ValidRangeCallback(this, &Receitas_X_EDITViewBase::numKeyboardContainer1ValidRangeCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxFundoAzul.setPosition(0, 0, 480, 35);
    boxFundoAzul.setColor(touchgfx::Color::getColorFromRGB(255, 128, 64));

    textAreaTitle.setPosition(48, 4, 287, 25);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTitle.setLinespacing(0);
    Unicode::snprintf(textAreaTitleBuffer, TEXTAREATITLE_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4018).getText());
    textAreaTitle.setWildcard(textAreaTitleBuffer);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3910));

    image1.setXY(8, 4);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_CHAPEU_ID));

    textArea1.setXY(8, 58);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3911));

    box1.setPosition(75, 52, 262, 31);
    box1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 191));

    toggleButtonRXCongResf.setXY(75, 174);
    toggleButtonRXCongResf.setBitmaps(touchgfx::Bitmap(BITMAP_CONGELARAA_ID), touchgfx::Bitmap(BITMAP_REFRIARAA_ID));
    toggleButtonRXCongResf.setAction(buttonCallback);

    toggleButtonRXhardSoft.setXY(207, 174);
    toggleButtonRXhardSoft.setBitmaps(touchgfx::Bitmap(BITMAP_SOFTS_ID), touchgfx::Bitmap(BITMAP_HARDS_ID));
    toggleButtonRXhardSoft.setAction(buttonCallback);

    toggleButtonRXConservYn.setXY(152, 220);
    toggleButtonRXConservYn.setBitmaps(touchgfx::Bitmap(BITMAP_COFF_ID), touchgfx::Bitmap(BITMAP_BUTTONON_ID));
    toggleButtonRXConservYn.setAction(buttonCallback);

    toggleButtonRXTimeTemp.setXY(76, 90);
    toggleButtonRXTimeTemp.setBitmaps(touchgfx::Bitmap(BITMAP_TEMPO_ID), touchgfx::Bitmap(BITMAP_TEMPERATURA_ID));
    toggleButtonRXTimeTemp.setAction(buttonCallback);

    textArea1_1.setXY(8, 88);
    textArea1_1.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_1.setLinespacing(0);
    textArea1_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3914));

    textArea1_2.setXY(8, 138);
    textArea1_2.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_2.setLinespacing(0);
    textArea1_2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3915));

    textArea1_3.setXY(8, 172);
    textArea1_3.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_3.setLinespacing(0);
    textArea1_3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3916));

    textArea1_4.setXY(8, 223);
    textArea1_4.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_4.setLinespacing(0);
    textArea1_4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3917));

    textAreaReceitaXDesc.setPosition(75, 52, 262, 31);
    textAreaReceitaXDesc.setColor(touchgfx::Color::getColorFromRGB(48, 72, 167));
    textAreaReceitaXDesc.setLinespacing(0);
    Unicode::snprintf(textAreaReceitaXDescBuffer, TEXTAREARECEITAXDESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3913).getText());
    textAreaReceitaXDesc.setWildcard(textAreaReceitaXDescBuffer);
    textAreaReceitaXDesc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3912));

    textArea2.setXY(422, 204);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3919));

    buttonSalvar.setXY(427, 222);
    buttonSalvar.setBitmaps(touchgfx::Bitmap(BITMAP_SALVAR_ID), touchgfx::Bitmap(BITMAP_SALVAR_ID));
    buttonSalvar.setAction(buttonCallback);

    flexButtonReceitaXDesc.setBoxWithBorderPosition(0, 0, 259, 31);
    flexButtonReceitaXDesc.setBorderSize(5);
    flexButtonReceitaXDesc.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonReceitaXDesc.setPosition(76, 52, 259, 31);
    flexButtonReceitaXDesc.setAlpha(0);
    flexButtonReceitaXDesc.setAction(flexButtonCallback);

    containerTemperatura.setPosition(243, 126, 124, 46);

    box3.setPosition(0, 4, 94, 34);
    box3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 0));
    containerTemperatura.add(box3);

    textArea1_2_1_C.setXY(104, 10);
    textArea1_2_1_C.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_2_1_C.setLinespacing(0);
    textArea1_2_1_C.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4098));
    containerTemperatura.add(textArea1_2_1_C);

    textAreaTemperaturaReceita.setPosition(1, 4, 91, 34);
    textAreaTemperaturaReceita.setColor(touchgfx::Color::getColorFromRGB(0, 0, 128));
    textAreaTemperaturaReceita.setLinespacing(0);
    Unicode::snprintf(textAreaTemperaturaReceitaBuffer, TEXTAREATEMPERATURARECEITA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3923).getText());
    textAreaTemperaturaReceita.setWildcard(textAreaTemperaturaReceitaBuffer);
    textAreaTemperaturaReceita.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3922));
    containerTemperatura.add(textAreaTemperaturaReceita);

    flexButtonTemperaturaReceita.setBoxWithBorderPosition(0, 0, 91, 34);
    flexButtonTemperaturaReceita.setBorderSize(5);
    flexButtonTemperaturaReceita.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButtonTemperaturaReceita.setPosition(1, 4, 91, 34);
    flexButtonTemperaturaReceita.setAlpha(0);
    flexButtonTemperaturaReceita.setAction(flexButtonCallback);
    containerTemperatura.add(flexButtonTemperaturaReceita);

    containerTempo.setPosition(70, 126, 137, 46);

    box2.setPosition(5, 4, 92, 34);
    box2.setColor(touchgfx::Color::getColorFromRGB(128, 255, 255));
    containerTempo.add(box2);

    textArea1_2_1.setXY(102, 12);
    textArea1_2_1.setColor(touchgfx::Color::getColorFromRGB(128, 128, 128));
    textArea1_2_1.setLinespacing(0);
    textArea1_2_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3918));
    containerTempo.add(textArea1_2_1);

    textAreaTempoReceitaX.setPosition(6, 4, 91, 34);
    textAreaTempoReceitaX.setColor(touchgfx::Color::getColorFromRGB(0, 0, 128));
    textAreaTempoReceitaX.setLinespacing(0);
    Unicode::snprintf(textAreaTempoReceitaXBuffer, TEXTAREATEMPORECEITAX_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3921).getText());
    textAreaTempoReceitaX.setWildcard(textAreaTempoReceitaXBuffer);
    textAreaTempoReceitaX.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3920));
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

    imageStatusPorta.setXY(200, 0);
    imageStatusPorta.setVisible(false);
    imageStatusPorta.setBitmap(touchgfx::Bitmap(BITMAP_PORTA_ID));

    textAreaStatusPorta.setXY(98, 13);
    textAreaStatusPorta.setVisible(false);
    textAreaStatusPorta.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaStatusPorta.setLinespacing(0);
    Unicode::snprintf(textAreaStatusPortaBuffer, TEXTAREASTATUSPORTA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4144).getText());
    textAreaStatusPorta.setWildcard(textAreaStatusPortaBuffer);
    textAreaStatusPorta.resizeToCurrentText();
    textAreaStatusPorta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4143));

    add(__background);
    add(boxFundo);
    add(boxFundoAzul);
    add(textAreaTitle);
    add(image1);
    add(textArea1);
    add(box1);
    add(toggleButtonRXCongResf);
    add(toggleButtonRXhardSoft);
    add(toggleButtonRXConservYn);
    add(toggleButtonRXTimeTemp);
    add(textArea1_1);
    add(textArea1_2);
    add(textArea1_3);
    add(textArea1_4);
    add(textAreaReceitaXDesc);
    add(textArea2);
    add(buttonSalvar);
    add(flexButtonReceitaXDesc);
    add(containerTemperatura);
    add(containerTempo);
    add(keyboardContainer21);
    add(numKeyboardContainer1);
    add(imageStatusPorta);
    add(textAreaStatusPorta);
}

void Receitas_X_EDITViewBase::setupScreen()
{
    keyboardContainer21.initialize();
    numKeyboardContainer1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    AddbackgroundContainer(this);
    // Clear();
    
    ReadWriteModbus485(&textAreaStatusPorta, textAreaStatusPortaBuffer, "553", 0, _INT_, REPEAT);
    
    AddJob(&textAreaTempoReceitaX, textAreaTempoReceitaXBuffer, 1, _INT_, 0);
    AddJob(&textAreaTemperaturaReceita, textAreaTemperaturaReceitaBuffer, 2, _FP_32BIT_, 1);
    AddJob(&toggleButtonRXTimeTemp, 3);
    AddJob(&toggleButtonRXCongResf, 4);
    AddJob(&textAreaReceitaXDesc, textAreaReceitaXDescBuffer, 5, _STRING_, 0);
    AddJob(&toggleButtonRXhardSoft, 6);
    AddJob(&toggleButtonRXConservYn, 7);
    AddJob(&textAreaTitle, textAreaTitleBuffer, 255, _INT_, 0);
    
    ContainerVisibility(&containerTempo, !toggleButtonRXTimeTemp.getState());
    ContainerVisibility(&containerTemperatura, toggleButtonRXTimeTemp.getState());
    ButtonVisibility(&toggleButtonRXhardSoft, toggleButtonRXCongResf.getState());

}

//Called when the screen transition ends
void Receitas_X_EDITViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Receitas_X_EDITViewBase::keyboardContainer21HideKeyboardCallbackHandler()
{
    //HideNameKeyboard
    //When keyboardContainer21 HideKeyboard execute C++ code
    //Execute C++ code
    ContainerVisibility(&keyboardContainer21, false);
    SoundBuzzerOn(25);
}

void Receitas_X_EDITViewBase::numKeyboardContainer1HideKeypadTriggerCallbackHandler()
{
    //HideNumKeyboard
    //When numKeyboardContainer1 HideKeypadTrigger execute C++ code
    //Execute C++ code
    ContainerVisibility(&numKeyboardContainer1, false);
    SoundBuzzerOn(25);
}

void Receitas_X_EDITViewBase::numKeyboardContainer1OutOfRangeCallbackHandler()
{
    //OutOfRangeFIred
    //When numKeyboardContainer1 OutOfRange call OutOfRangeMsg on numKeyboardContainer1
    //Call OutOfRangeMsg
    numKeyboardContainer1.OutOfRangeMsg();
}

void Receitas_X_EDITViewBase::numKeyboardContainer1ValidRangeCallbackHandler()
{
    //InsideRangeFired
    //When numKeyboardContainer1 ValidRange call InputValidRange on numKeyboardContainer1
    //Call InputValidRange
    numKeyboardContainer1.InputValidRange();
}

void Receitas_X_EDITViewBase::handleTickEvent()
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
    W_1_4553 = imageStatusPorta.isVisible();
}

void Receitas_X_EDITViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
    ContainerClear(&numKeyboardContainer1);
    ContainerClear(&keyboardContainer21);
}

void Receitas_X_EDITViewBase::Receitas_1()
{
    //Receita1
    //When Receitas_1 is called change screen to Receitas_1
    //Go to Receitas_1 with no screen transition
    application().gotoReceitas_1ScreenNoTransition();
}

void Receitas_X_EDITViewBase::Receitas_2()
{
    //Receita2
    //When Receitas_2 is called change screen to Receitas_2
    //Go to Receitas_2 with no screen transition
    application().gotoReceitas_2ScreenNoTransition();
}

void Receitas_X_EDITViewBase::Receitas_3()
{
    //Receita3
    //When Receitas_3 is called change screen to Receitas_3
    //Go to Receitas_3 with no screen transition
    application().gotoReceitas_3ScreenNoTransition();
}

void Receitas_X_EDITViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &toggleButtonRXCongResf)
    {
        //RXCongResf
        //When toggleButtonRXCongResf clicked execute C++ code
        //Execute C++ code
        ButtonVisibility(&toggleButtonRXhardSoft, toggleButtonRXCongResf.getState());
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButtonRXhardSoft)
    {
        //RXhardSoft
        //When toggleButtonRXhardSoft clicked execute C++ code
        //Execute C++ code
        //Update(&textAreaRXhardSoft, textAreaRXhardSoftBuffer, toggleButtonRXhardSoft.getState() != 0 ? 255 : 0, _INT_, 0);
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButtonRXConservYn)
    {
        //RXConservYn
        //When toggleButtonRXConservYn clicked execute C++ code
        //Execute C++ code
        //Update(&textAreaRXConservYn, textAreaRXConservYnBuffer, toggleButtonRXConservYn.getState() != 0 ? 255 : 0, _INT_, 0);
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButtonRXTimeTemp)
    {
        //RXTimeTemp
        //When toggleButtonRXTimeTemp clicked execute C++ code
        //Execute C++ code
        ContainerVisibility(&containerTempo, !toggleButtonRXTimeTemp.getState());
        ContainerVisibility(&containerTemperatura, toggleButtonRXTimeTemp.getState());
        SoundBuzzerOn(25);
    }
    else if (&src == &buttonSalvar)
    {
        //Salvar
        //When buttonSalvar clicked execute C++ code
        //Execute C++ code
        UpdateJobs();
        Wait(50);
        
        UpdateJobsOthers();
        Wait(50);
        
        if (selectedRecipeListPage == 2)
        	Receitas_2();
        else if (selectedRecipeListPage == 3)
        	Receitas_3();
        else
        	Receitas_1();
    }
}

void Receitas_X_EDITViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
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
