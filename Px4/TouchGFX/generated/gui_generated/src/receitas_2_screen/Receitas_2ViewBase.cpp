/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/receitas_2_screen/Receitas_2ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Receitas_2ViewBase::Receitas_2ViewBase() :
    buttonCallback(this, &Receitas_2ViewBase::buttonCallbackHandler),
    radioButtonSelectedCallback(this, &Receitas_2ViewBase::radioButtonSelectedCallbackHandler)
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
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3892));

    image1.setXY(8, 4);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_CHAPEU_ID));

    boxWithBorder1.setPosition(69, 71, 329, 41);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder1.setBorderSize(2);

    boxWithBorder2.setPosition(69, 113, 329, 41);
    boxWithBorder2.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder2.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder2.setBorderSize(2);

    boxWithBorder3.setPosition(69, 155, 329, 41);
    boxWithBorder3.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder3.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder3.setBorderSize(2);

    boxWithBorder4.setPosition(69, 197, 329, 41);
    boxWithBorder4.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder4.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder4.setBorderSize(2);

    radioButtonMuneroReceita5.setXY(12, 71);
    radioButtonMuneroReceita5.setBitmaps(touchgfx::Bitmap(BITMAP_PATH158_ID), touchgfx::Bitmap(BITMAP_PATH224_ID), touchgfx::Bitmap(BITMAP_PATH224_ID), touchgfx::Bitmap(BITMAP_PATH224_ID));
    radioButtonMuneroReceita5.setSelected(false);
    radioButtonMuneroReceita5.setDeselectionEnabled(false);

    radioButtonMuneroReceita6.setXY(12, 113);
    radioButtonMuneroReceita6.setBitmaps(touchgfx::Bitmap(BITMAP_PATH164_ID), touchgfx::Bitmap(BITMAP_PATH230_ID), touchgfx::Bitmap(BITMAP_PATH230_ID), touchgfx::Bitmap(BITMAP_PATH230_ID));
    radioButtonMuneroReceita6.setSelected(false);
    radioButtonMuneroReceita6.setDeselectionEnabled(false);

    radioButtonMuneroReceita7.setXY(12, 155);
    radioButtonMuneroReceita7.setBitmaps(touchgfx::Bitmap(BITMAP_PATH170_ID), touchgfx::Bitmap(BITMAP_PATH236_ID), touchgfx::Bitmap(BITMAP_PATH236_ID), touchgfx::Bitmap(BITMAP_PATH236_ID));
    radioButtonMuneroReceita7.setSelected(false);
    radioButtonMuneroReceita7.setDeselectionEnabled(false);

    radioButtonMuneroReceita8.setXY(12, 197);
    radioButtonMuneroReceita8.setBitmaps(touchgfx::Bitmap(BITMAP_PATH176_ID), touchgfx::Bitmap(BITMAP_PATH242_ID), touchgfx::Bitmap(BITMAP_PATH242_ID), touchgfx::Bitmap(BITMAP_PATH242_ID));
    radioButtonMuneroReceita8.setSelected(false);
    radioButtonMuneroReceita8.setDeselectionEnabled(false);

    buttonFlagReceita1Interm.setXY(406, 208);
    buttonFlagReceita1Interm.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE_ID), touchgfx::Bitmap(BITMAP_AVANCEON_ID));
    buttonFlagReceita1Interm.setAction(buttonCallback);

    buttonTelaInicial.setXY(406, 64);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR_ID), touchgfx::Bitmap(BITMAP_VOLTAR_ID));
    buttonTelaInicial.setAction(buttonCallback);

    buttonFlagEditReceita.setXY(406, 136);
    buttonFlagEditReceita.setBitmaps(touchgfx::Bitmap(BITMAP_RECIPE_ID), touchgfx::Bitmap(BITMAP_RECIPE_ID));
    buttonFlagEditReceita.setAction(buttonCallback);

    buttonReceita3.setXY(194, 239);
    buttonReceita3.setBitmaps(touchgfx::Bitmap(BITMAP_SETABAIXO_ID), touchgfx::Bitmap(BITMAP_SETABAIXO_ID));
    buttonReceita3.setAction(buttonCallback);

    buttonReceita1.setXY(194, 37);
    buttonReceita1.setBitmaps(touchgfx::Bitmap(BITMAP_SETACIMA_ID), touchgfx::Bitmap(BITMAP_SETACIMA_ID));
    buttonReceita1.setAction(buttonCallback);

    textAreaReceita5Desc.setPosition(69, 71, 329, 41);
    textAreaReceita5Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita5Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita5DescBuffer, TEXTAREARECEITA5DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3894).getText());
    textAreaReceita5Desc.setWildcard(textAreaReceita5DescBuffer);
    textAreaReceita5Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3893));

    textAreaReceita6Desc.setPosition(69, 113, 329, 41);
    textAreaReceita6Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita6Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita6DescBuffer, TEXTAREARECEITA6DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3896).getText());
    textAreaReceita6Desc.setWildcard(textAreaReceita6DescBuffer);
    textAreaReceita6Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3895));

    textAreaReceita7Desc.setPosition(69, 155, 329, 41);
    textAreaReceita7Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita7Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita7DescBuffer, TEXTAREARECEITA7DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3898).getText());
    textAreaReceita7Desc.setWildcard(textAreaReceita7DescBuffer);
    textAreaReceita7Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3897));

    textAreaReceita8Desc.setPosition(69, 197, 329, 41);
    textAreaReceita8Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita8Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita8DescBuffer, TEXTAREARECEITA8DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3900).getText());
    textAreaReceita8Desc.setWildcard(textAreaReceita8DescBuffer);
    textAreaReceita8Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3899));

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
    add(radioButtonMuneroReceita5);
    add(radioButtonMuneroReceita6);
    add(radioButtonMuneroReceita7);
    add(radioButtonMuneroReceita8);
    add(buttonFlagReceita1Interm);
    add(buttonTelaInicial);
    add(buttonFlagEditReceita);
    add(buttonReceita3);
    add(buttonReceita1);
    add(textAreaReceita5Desc);
    add(textAreaReceita6Desc);
    add(textAreaReceita7Desc);
    add(textAreaReceita8Desc);
    add(background1);
    radioButtonGroup1.add(radioButtonMuneroReceita5);
    radioButtonGroup1.add(radioButtonMuneroReceita6);
    radioButtonGroup1.add(radioButtonMuneroReceita7);
    radioButtonGroup1.add(radioButtonMuneroReceita8);
    radioButtonGroup1.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
}

void Receitas_2ViewBase::setupScreen()
{
    background1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Update(&textAreaReceita5Desc, textAreaReceita5DescBuffer, Receita_5_desc, 20);
    Update(&textAreaReceita6Desc, textAreaReceita6DescBuffer, Receita_6_desc, 20);
    Update(&textAreaReceita7Desc, textAreaReceita7DescBuffer, Receita_7_desc, 20);
    Update(&textAreaReceita8Desc, textAreaReceita8DescBuffer, Receita_8_desc, 20);
    
    if (numero_receita == 5) Update(&radioButtonMuneroReceita5, true);
    if (numero_receita == 6) Update(&radioButtonMuneroReceita6, true);
    if (numero_receita == 7) Update(&radioButtonMuneroReceita7, true);
    if (numero_receita == 8) Update(&radioButtonMuneroReceita8, true);

}

//Called when the screen transition ends
void Receitas_2ViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    if (numero_receita < 5 || numero_receita > 8) SoundBuzzerOn(25);
}

void Receitas_2ViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
}

void Receitas_2ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonFlagReceita1Interm)
    {
        //Avancar
        //When buttonFlagReceita1Interm clicked execute C++ code
        //Execute C++ code
        flag_Receita2_interm = true;
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
    else if (&src == &buttonReceita3)
    {
        //Receita3
        //When buttonReceita3 clicked change screen to Receitas_3
        //Go to Receitas_3 with no screen transition
        application().gotoReceitas_3ScreenNoTransition();
    }
    else if (&src == &buttonReceita1)
    {
        //Receita1
        //When buttonReceita1 clicked change screen to Receitas_1
        //Go to Receitas_1 with no screen transition
        application().gotoReceitas_1ScreenNoTransition();
    }
}

void Receitas_2ViewBase::radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &radioButtonMuneroReceita5)
    {
        //R5
        //When radioButtonMuneroReceita5 selected execute C++ code
        //Execute C++ code
        numero_receita = 5;
        
        SelectJob(4);
        SoundBuzzerOn(25);
    }
    else if (&src == &radioButtonMuneroReceita6)
    {
        //R6
        //When radioButtonMuneroReceita6 selected execute C++ code
        //Execute C++ code
        numero_receita = 6;
        
        SelectJob(5);
        SoundBuzzerOn(25);
    }
    else if (&src == &radioButtonMuneroReceita7)
    {
        //R7
        //When radioButtonMuneroReceita7 selected execute C++ code
        //Execute C++ code
        numero_receita = 7;
        
        SelectJob(6);
        SoundBuzzerOn(25);
    }
    else if (&src == &radioButtonMuneroReceita8)
    {
        //R8
        //When radioButtonMuneroReceita8 selected execute C++ code
        //Execute C++ code
        numero_receita = 8;
        
        SelectJob(7);
        SoundBuzzerOn(25);
    }
}
