/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/conservacao_screen/ConservacaoViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

ConservacaoViewBase::ConservacaoViewBase() :
    buttonCallback(this, &ConservacaoViewBase::buttonCallbackHandler),
    radioButtonSelectedCallback(this, &ConservacaoViewBase::radioButtonSelectedCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(240, 240, 240));

    boxFundoAzul.setPosition(0, 0, 480, 53);
    boxFundoAzul.setColor(touchgfx::Color::getColorFromRGB(44, 182, 115));

    textAreaTitle.setXY(52, 8);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTitle.setLinespacing(0);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3788));

    imageLogo.setXY(5, 8);
    imageLogo.setBitmap(touchgfx::Bitmap(BITMAP_CONSERVLOGO_ID));

    radioButtonStatusConservar0.setXY(14, 64);
    radioButtonStatusConservar0.setBitmaps(touchgfx::Bitmap(BITMAP_CONSERVCONGOFF_ID), touchgfx::Bitmap(BITMAP_CONSERVCONGON_ID), touchgfx::Bitmap(BITMAP_CONSERVCONGON_ID), touchgfx::Bitmap(BITMAP_CONSERVCONGON_ID));
    radioButtonStatusConservar0.setSelected(false);
    radioButtonStatusConservar0.setDeselectionEnabled(false);

    radioButtonStatusConservar1.setXY(140, 64);
    radioButtonStatusConservar1.setBitmaps(touchgfx::Bitmap(BITMAP_CONSERVRESFOFF_ID), touchgfx::Bitmap(BITMAP_CONSERVRESFON_ID), touchgfx::Bitmap(BITMAP_CONSERVRESFON_ID), touchgfx::Bitmap(BITMAP_CONSERVRESFON_ID));
    radioButtonStatusConservar1.setSelected(false);
    radioButtonStatusConservar1.setDeselectionEnabled(false);

    buttonFlagConservarCongResf.setXY(406, 208);
    buttonFlagConservarCongResf.setVisible(false);
    buttonFlagConservarCongResf.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE_ID), touchgfx::Bitmap(BITMAP_AVANCEON_ID));
    buttonFlagConservarCongResf.setAction(buttonCallback);

    buttonTelaInicial.setXY(406, 64);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR_ID), touchgfx::Bitmap(BITMAP_VOLTAR_ID));
    buttonTelaInicial.setAction(buttonCallback);

    background1.setXY(0, 0);

    add(__background);
    add(boxFundo);
    add(boxFundoAzul);
    add(textAreaTitle);
    add(imageLogo);
    add(radioButtonStatusConservar0);
    add(radioButtonStatusConservar1);
    add(buttonFlagConservarCongResf);
    add(buttonTelaInicial);
    add(background1);
    radioButtonGroup1.add(radioButtonStatusConservar0);
    radioButtonGroup1.add(radioButtonStatusConservar1);
    radioButtonGroup1.setRadioButtonSelectedHandler(radioButtonSelectedCallback);
}

void ConservacaoViewBase::setupScreen()
{
    background1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    WriteModbus485(10282, 1);
    WriteModbus485(10242, 1);
    WriteModbus485(645, 1);
    
    if (Status_Conservar == 1) Update(&radioButtonStatusConservar0, true);
    if (Status_Conservar == 2) Update(&radioButtonStatusConservar1, true);

}

//Called when the screen transition ends
void ConservacaoViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    if (Status_Conservar != 1 && Status_Conservar != 2)
    {
    	ButtonVisibility(&buttonFlagConservarCongResf, false);
    	SoundBuzzerOn(25);
    }
}

void ConservacaoViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
}

void ConservacaoViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonFlagConservarCongResf)
    {
        //Avancar
        //When buttonFlagConservarCongResf clicked execute C++ code
        //Execute C++ code
        flag_Conservar_Cong_Resf = true;
    }
    else if (&src == &buttonTelaInicial)
    {
        //TelaInicial
        //When buttonTelaInicial clicked change screen to Tela_Inicial
        //Go to Tela_Inicial with no screen transition
        application().gotoTela_InicialScreenNoTransition();
    }
}

void ConservacaoViewBase::radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &radioButtonStatusConservar0)
    {
        //Congelar
        //When radioButtonStatusConservar0 selected execute C++ code
        //Execute C++ code
        ButtonVisibility(&buttonFlagConservarCongResf, true);
        Status_Conservar = 1;
        SoundBuzzerOn(25);
    }
    else if (&src == &radioButtonStatusConservar1)
    {
        //Resfriar
        //When radioButtonStatusConservar1 selected execute C++ code
        //Execute C++ code
        ButtonVisibility(&buttonFlagConservarCongResf, true);
        Status_Conservar = 2;
        SoundBuzzerOn(25);
    }
}
