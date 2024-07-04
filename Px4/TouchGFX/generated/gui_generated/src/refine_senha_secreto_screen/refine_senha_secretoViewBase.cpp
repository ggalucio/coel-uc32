/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/refine_senha_secreto_screen/refine_senha_secretoViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

refine_senha_secretoViewBase::refine_senha_secretoViewBase()
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    textAreaTitle.setXY(135, 29);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaTitle.setLinespacing(0);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3930));

    boxWithBorder1.setPosition(180, 80, 120, 40);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(186, 206, 232));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(127, 157, 183));
    boxWithBorder1.setBorderSize(1);

    buttonTelaInicial.setXY(433, 220);

    textAreaSenhaGravada.setPosition(180, 80, 120, 40);
    textAreaSenhaGravada.setColor(touchgfx::Color::getColorFromRGB(0, 0, 255));
    textAreaSenhaGravada.setLinespacing(0);
    Unicode::snprintf(textAreaSenhaGravadaBuffer, TEXTAREASENHAGRAVADA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3932).getText());
    textAreaSenhaGravada.setWildcard(textAreaSenhaGravadaBuffer);
    textAreaSenhaGravada.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3931));

    add(__background);
    add(boxFundo);
    add(textAreaTitle);
    add(boxWithBorder1);
    add(buttonTelaInicial);
    add(textAreaSenhaGravada);
}

void refine_senha_secretoViewBase::setupScreen()
{

}

//Called when the screen transition ends
void refine_senha_secretoViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void refine_senha_secretoViewBase::handleTickEvent()
{

}

void refine_senha_secretoViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
}
