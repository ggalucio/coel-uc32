/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/receitas_1_screen/Receitas_1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Receitas_1ViewBase::Receitas_1ViewBase() :
    buttonCallback(this, &Receitas_1ViewBase::buttonCallbackHandler),
    radioButtonSelectedCallback(this, &Receitas_1ViewBase::radioButtonSelectedCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxFundoAzul.setPosition(0, 0, 480, 35);
    boxFundoAzul.setColor(touchgfx::Color::getColorFromRGB(255, 128, 64));

    textAreaTitle.setXY(48, 4);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTitle.setLinespacing(0);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3883));

    image1.setXY(8, 4);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_CHAPEU_ID));

    boxWithBorder1.setPosition(69, 43, 329, 41);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder1.setBorderSize(2);

    boxWithBorder2.setPosition(69, 90, 329, 41);
    boxWithBorder2.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder2.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder2.setBorderSize(2);

    boxWithBorder3.setPosition(69, 137, 329, 41);
    boxWithBorder3.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder3.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder3.setBorderSize(2);

    boxWithBorder4.setPosition(69, 184, 329, 41);
    boxWithBorder4.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder4.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder4.setBorderSize(2);

    radioButtonMuneroReceita1.setXY(12, 43);
    radioButtonMuneroReceita1.setBitmaps(touchgfx::Bitmap(BITMAP_OFR1_ID), touchgfx::Bitmap(BITMAP_PATH198_ID), touchgfx::Bitmap(BITMAP_PATH198_ID), touchgfx::Bitmap(BITMAP_PATH198_ID));
    radioButtonMuneroReceita1.setSelected(false);
    radioButtonMuneroReceita1.setDeselectionEnabled(false);

    radioButtonMuneroReceita2.setXY(12, 90);
    radioButtonMuneroReceita2.setBitmaps(touchgfx::Bitmap(BITMAP_PATH138_ID), touchgfx::Bitmap(BITMAP_PATH204_ID), touchgfx::Bitmap(BITMAP_PATH204_ID), touchgfx::Bitmap(BITMAP_PATH204_ID));
    radioButtonMuneroReceita2.setSelected(false);
    radioButtonMuneroReceita2.setDeselectionEnabled(false);

    radioButtonMuneroReceita3.setXY(12, 137);
    radioButtonMuneroReceita3.setBitmaps(touchgfx::Bitmap(BITMAP_PATH144_ID), touchgfx::Bitmap(BITMAP_PATH210_ID), touchgfx::Bitmap(BITMAP_PATH210_ID), touchgfx::Bitmap(BITMAP_PATH210_ID));
    radioButtonMuneroReceita3.setSelected(false);
    radioButtonMuneroReceita3.setDeselectionEnabled(false);

    radioButtonMuneroReceita4.setXY(12, 184);
    radioButtonMuneroReceita4.setBitmaps(touchgfx::Bitmap(BITMAP_PATH152_ID), touchgfx::Bitmap(BITMAP_PATH218_ID), touchgfx::Bitmap(BITMAP_PATH218_ID), touchgfx::Bitmap(BITMAP_PATH218_ID));
    radioButtonMuneroReceita4.setSelected(false);
    radioButtonMuneroReceita4.setDeselectionEnabled(false);

    buttonFlagReceita1Interm.setXY(406, 208);
    buttonFlagReceita1Interm.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE_ID), touchgfx::Bitmap(BITMAP_AVANCEON_ID));
    buttonFlagReceita1Interm.setAction(buttonCallback);

    buttonTelaInicial.setXY(406, 64);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR_ID), touchgfx::Bitmap(BITMAP_VOLTAR_ID));
    buttonTelaInicial.setAction(buttonCallback);

    buttonFlagEditReceita.setXY(406, 136);
    buttonFlagEditReceita.setBitmaps(touchgfx::Bitmap(BITMAP_RECIPE_ID), touchgfx::Bitmap(BITMAP_RECIPE_ID));
    buttonFlagEditReceita.setAction(buttonCallback);

    buttonReceita2.setXY(194, 234);
    buttonReceita2.setBitmaps(touchgfx::Bitmap(BITMAP_SETABAIXO_ID), touchgfx::Bitmap(BITMAP_SETABAIXO_ID));
    buttonReceita2.setAction(buttonCallback);

    textAreaReceita1Desc.setPosition(69, 43, 329, 41);
    textAreaReceita1Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita1Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita1DescBuffer, TEXTAREARECEITA1DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3885).getText());
    textAreaReceita1Desc.setWildcard(textAreaReceita1DescBuffer);
    textAreaReceita1Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3884));

    textAreaReceita2Desc.setPosition(69, 90, 329, 41);
    textAreaReceita2Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita2Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita2DescBuffer, TEXTAREARECEITA2DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3887).getText());
    textAreaReceita2Desc.setWildcard(textAreaReceita2DescBuffer);
    textAreaReceita2Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3886));

    textAreaReceita3Desc.setPosition(69, 137, 329, 41);
    textAreaReceita3Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita3Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita3DescBuffer, TEXTAREARECEITA3DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3889).getText());
    textAreaReceita3Desc.setWildcard(textAreaReceita3DescBuffer);
    textAreaReceita3Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3888));

    textAreaReceita4Desc.setPosition(69, 184, 329, 41);
    textAreaReceita4Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita4Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita4DescBuffer, TEXTAREARECEITA4DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3891).getText());
    textAreaReceita4Desc.setWildcard(textAreaReceita4DescBuffer);
    textAreaReceita4Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3890));

    background1.setXY(0, 0);

    add(__background);
    add(boxFundo);
    add(boxFundoAzul);
    add(textAreaTitle);
    add(image1);
    add(boxWithBorder1);
    add(boxWithBorder2);
    add(boxWithBorder3);
    add(boxWithBorder4);
    add(radioButtonMuneroReceita1);
    add(radioButtonMuneroReceita2);
    add(radioButtonMuneroReceita3);
    add(radioButtonMuneroReceita4);
    add(buttonFlagReceita1Interm);
    add(buttonTelaInicial);
    add(buttonFlagEditReceita);
    add(buttonReceita2);
    add(textAreaReceita1Desc);
    add(textAreaReceita2Desc);
    add(textAreaReceita3Desc);
    add(textAreaReceita4Desc);
    add(background1);
    radioButtonGroup1.add(radioButtonMuneroReceita1);
    radioButtonGroup1.add(radioButtonMuneroReceita2);
    radioButtonGroup1.add(radioButtonMuneroReceita3);
    radioButtonGroup1.add(radioButtonMuneroReceita4);
    radioButtonGroup1.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
}

void Receitas_1ViewBase::setupScreen()
{
    background1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Update(&textAreaReceita1Desc, textAreaReceita1DescBuffer, Receita_1_desc, 20);
    Update(&textAreaReceita2Desc, textAreaReceita2DescBuffer, Receita_2_desc, 20);
    Update(&textAreaReceita3Desc, textAreaReceita3DescBuffer, Receita_3_desc, 20);
    Update(&textAreaReceita4Desc, textAreaReceita4DescBuffer, Receita_4_desc, 20);
    
    if (numero_receita == 1) Update(&radioButtonMuneroReceita1, true);
    if (numero_receita == 2) Update(&radioButtonMuneroReceita2, true);
    if (numero_receita == 3) Update(&radioButtonMuneroReceita3, true);
    if (numero_receita == 4) Update(&radioButtonMuneroReceita4, true);

}

//Called when the screen transition ends
void Receitas_1ViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    if (numero_receita < 1 || numero_receita > 4) SoundBuzzerOn(25);
}

void Receitas_1ViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
}

void Receitas_1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonFlagReceita1Interm)
    {
        //Avancar
        //When buttonFlagReceita1Interm clicked execute C++ code
        //Execute C++ code
        flag_Receita1_interm = true;
    }
    else if (&src == &buttonTelaInicial)
    {
        //TelaInicial
        //When buttonTelaInicial clicked change screen to Tela_Inicial
        //Go to Tela_Inicial with no screen transition
        application().gotoTela_InicialScreenNoTransition();
    }
    else if (&src == &buttonFlagEditReceita)
    {
        //FlagEditReceita
        //When buttonFlagEditReceita clicked execute C++ code
        //Execute C++ code
        flag_edit_receita = true;
        SoundBuzzerOn(25);
    }
    else if (&src == &buttonReceita2)
    {
        //Receita2
        //When buttonReceita2 clicked change screen to Receitas_2
        //Go to Receitas_2 with no screen transition
        application().gotoReceitas_2ScreenNoTransition();
    }
}

void Receitas_1ViewBase::radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &radioButtonMuneroReceita1)
    {
        //R1
        //When radioButtonMuneroReceita1 selected execute C++ code
        //Execute C++ code
        numero_receita = 1;
        
        SelectJob(0);
        SoundBuzzerOn(25);
    }
    else if (&src == &radioButtonMuneroReceita2)
    {
        //R2
        //When radioButtonMuneroReceita2 selected execute C++ code
        //Execute C++ code
        numero_receita = 2;
        
        SelectJob(1);
        SoundBuzzerOn(25);
    }
    else if (&src == &radioButtonMuneroReceita3)
    {
        //R3
        //When radioButtonMuneroReceita3 selected execute C++ code
        //Execute C++ code
        numero_receita = 3;
        
        SelectJob(2);
        SoundBuzzerOn(25);
    }
    else if (&src == &radioButtonMuneroReceita4)
    {
        //R4
        //When radioButtonMuneroReceita4 selected execute C++ code
        //Execute C++ code
        numero_receita = 4;
        
        SelectJob(3);
        SoundBuzzerOn(25);
    }
}
