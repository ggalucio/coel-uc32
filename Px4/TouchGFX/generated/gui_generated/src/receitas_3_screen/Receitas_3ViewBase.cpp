/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/receitas_3_screen/Receitas_3ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Receitas_3ViewBase::Receitas_3ViewBase() :
    buttonCallback(this, &Receitas_3ViewBase::buttonCallbackHandler),
    radioButtonSelectedCallback(this, &Receitas_3ViewBase::radioButtonSelectedCallbackHandler)
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
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3901));

    image1.setXY(8, 4);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_CHAPEU_ID));

    boxWithBorder1.setPosition(69, 75, 329, 41);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder1.setBorderSize(2);

    boxWithBorder2.setPosition(69, 122, 329, 41);
    boxWithBorder2.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder2.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder2.setBorderSize(2);

    boxWithBorder3.setPosition(69, 169, 329, 41);
    boxWithBorder3.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder3.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder3.setBorderSize(2);

    boxWithBorder4.setPosition(69, 216, 329, 41);
    boxWithBorder4.setColor(touchgfx::Color::getColorFromRGB(192, 192, 192));
    boxWithBorder4.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder4.setBorderSize(2);

    radioButtonMuneroReceita9.setXY(12, 75);
    radioButtonMuneroReceita9.setBitmaps(touchgfx::Bitmap(BITMAP_PATH184_ID), touchgfx::Bitmap(BITMAP_PATH250_ID), touchgfx::Bitmap(BITMAP_PATH250_ID), touchgfx::Bitmap(BITMAP_PATH250_ID));
    radioButtonMuneroReceita9.setSelected(false);
    radioButtonMuneroReceita9.setDeselectionEnabled(false);

    radioButtonMuneroReceita10.setXY(12, 122);
    radioButtonMuneroReceita10.setBitmaps(touchgfx::Bitmap(BITMAP_PATH192_ID), touchgfx::Bitmap(BITMAP_PATH258_ID), touchgfx::Bitmap(BITMAP_PATH258_ID), touchgfx::Bitmap(BITMAP_PATH258_ID));
    radioButtonMuneroReceita10.setSelected(false);
    radioButtonMuneroReceita10.setDeselectionEnabled(false);

    radioButtonMuneroReceita11.setXY(12, 169);
    radioButtonMuneroReceita11.setBitmaps(touchgfx::Bitmap(BITMAP_PATH264_ID), touchgfx::Bitmap(BITMAP_PATH278_ID), touchgfx::Bitmap(BITMAP_PATH278_ID), touchgfx::Bitmap(BITMAP_PATH278_ID));
    radioButtonMuneroReceita11.setSelected(false);
    radioButtonMuneroReceita11.setDeselectionEnabled(false);

    radioButtonMuneroReceita12.setXY(12, 216);
    radioButtonMuneroReceita12.setBitmaps(touchgfx::Bitmap(BITMAP_PATH272_ID), touchgfx::Bitmap(BITMAP_PATH286_ID), touchgfx::Bitmap(BITMAP_PATH286_ID), touchgfx::Bitmap(BITMAP_PATH286_ID));
    radioButtonMuneroReceita12.setSelected(false);
    radioButtonMuneroReceita12.setDeselectionEnabled(false);

    buttonFlagReceita1Interm.setXY(406, 208);
    buttonFlagReceita1Interm.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE_ID), touchgfx::Bitmap(BITMAP_AVANCEON_ID));

    buttonTelaInicial.setXY(406, 64);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR_ID), touchgfx::Bitmap(BITMAP_VOLTAR_ID));
    buttonTelaInicial.setAction(buttonCallback);

    buttonFlagEditReceita.setXY(406, 136);
    buttonFlagEditReceita.setBitmaps(touchgfx::Bitmap(BITMAP_RECIPE_ID), touchgfx::Bitmap(BITMAP_RECIPE_ID));
    buttonFlagEditReceita.setAction(buttonCallback);

    buttonReceita2.setXY(194, 37);
    buttonReceita2.setBitmaps(touchgfx::Bitmap(BITMAP_SETACIMA_ID), touchgfx::Bitmap(BITMAP_SETACIMA_ID));
    buttonReceita2.setAction(buttonCallback);

    textAreaReceita9Desc.setPosition(69, 75, 329, 41);
    textAreaReceita9Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita9Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita9DescBuffer, TEXTAREARECEITA9DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3903).getText());
    textAreaReceita9Desc.setWildcard(textAreaReceita9DescBuffer);
    textAreaReceita9Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3902));

    textAreaReceita10Desc.setPosition(69, 122, 329, 41);
    textAreaReceita10Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita10Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita10DescBuffer, TEXTAREARECEITA10DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3905).getText());
    textAreaReceita10Desc.setWildcard(textAreaReceita10DescBuffer);
    textAreaReceita10Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3904));

    textAreaReceita11Desc.setPosition(69, 169, 329, 41);
    textAreaReceita11Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita11Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita11DescBuffer, TEXTAREARECEITA11DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3907).getText());
    textAreaReceita11Desc.setWildcard(textAreaReceita11DescBuffer);
    textAreaReceita11Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3906));

    textAreaReceita12Desc.setPosition(69, 216, 329, 41);
    textAreaReceita12Desc.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaReceita12Desc.setLinespacing(0);
    Unicode::snprintf(textAreaReceita12DescBuffer, TEXTAREARECEITA12DESC_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3909).getText());
    textAreaReceita12Desc.setWildcard(textAreaReceita12DescBuffer);
    textAreaReceita12Desc.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3908));

    add(__background);
    add(boxFundo);
    add(boxFundoAzul);
    add(textAreaTitle);
    add(image1);
    add(boxWithBorder1);
    add(boxWithBorder2);
    add(boxWithBorder3);
    add(boxWithBorder4);
    add(radioButtonMuneroReceita9);
    add(radioButtonMuneroReceita10);
    add(radioButtonMuneroReceita11);
    add(radioButtonMuneroReceita12);
    add(buttonFlagReceita1Interm);
    add(buttonTelaInicial);
    add(buttonFlagEditReceita);
    add(buttonReceita2);
    add(textAreaReceita9Desc);
    add(textAreaReceita10Desc);
    add(textAreaReceita11Desc);
    add(textAreaReceita12Desc);
    radioButtonGroup1.add(radioButtonMuneroReceita9);
    radioButtonGroup1.add(radioButtonMuneroReceita10);
    radioButtonGroup1.add(radioButtonMuneroReceita11);
    radioButtonGroup1.add(radioButtonMuneroReceita12);
    radioButtonGroup1.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
}

void Receitas_3ViewBase::setupScreen()
{

    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    SelectJob(9);
    ReadJobName(&textAreaReceita9Desc, textAreaReceita9DescBuffer, 20);
    
    SelectJob(10);
    ReadJobName(&textAreaReceita10Desc, textAreaReceita10DescBuffer, 20);
    
    SelectJob(11);
    ReadJobName(&textAreaReceita11Desc, textAreaReceita11DescBuffer, 20);
    
    SelectJob(12);
    ReadJobName(&textAreaReceita12Desc, textAreaReceita12DescBuffer, 20);

}

//Called when the screen transition ends
void Receitas_3ViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Receitas_3ViewBase::handleTickEvent()
{

}

void Receitas_3ViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
}

void Receitas_3ViewBase::Receita_X_EDIT()
{
    //ReceitaXEDIT
    //When Receita_X_EDIT is called change screen to Receitas_X_EDIT
    //Go to Receitas_X_EDIT with no screen transition
    application().gotoReceitas_X_EDITScreenNoTransition();
}

void Receitas_3ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonTelaInicial)
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
        if (	radioButtonMuneroReceita9.getSelected() || 
        	radioButtonMuneroReceita10.getSelected() || 
        	radioButtonMuneroReceita11.getSelected() || 
        	radioButtonMuneroReceita12.getSelected())
        	Receita_X_EDIT();
        else
        	SoundBuzzerOn(25);
        
        selectedRecipeListPage = 3;
    }
    else if (&src == &buttonReceita2)
    {
        //Receita2
        //When buttonReceita2 clicked change screen to Receitas_2
        //Go to Receitas_2 with no screen transition
        application().gotoReceitas_2ScreenNoTransition();
    }
}

void Receitas_3ViewBase::radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &radioButtonMuneroReceita9)
    {
        //R9
        //When radioButtonMuneroReceita9 selected execute C++ code
        //Execute C++ code
        SelectJob(9);
        SoundBuzzerOn(25);
    }
    else if (&src == &radioButtonMuneroReceita10)
    {
        //R10
        //When radioButtonMuneroReceita10 selected execute C++ code
        //Execute C++ code
        SelectJob(10);
        SoundBuzzerOn(25);
    }
    else if (&src == &radioButtonMuneroReceita11)
    {
        //R11
        //When radioButtonMuneroReceita11 selected execute C++ code
        //Execute C++ code
        SelectJob(11);
        SoundBuzzerOn(25);
    }
    else if (&src == &radioButtonMuneroReceita12)
    {
        //R12
        //When radioButtonMuneroReceita12 selected execute C++ code
        //Execute C++ code
        SelectJob(12);
        SoundBuzzerOn(25);
    }
}
