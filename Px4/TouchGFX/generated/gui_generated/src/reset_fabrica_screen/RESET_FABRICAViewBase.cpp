/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/reset_fabrica_screen/RESET_FABRICAViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

RESET_FABRICAViewBase::RESET_FABRICAViewBase()
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    textAreaLabel.setXY(86, 30);
    textAreaLabel.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel.setLinespacing(0);
    textAreaLabel.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3791));

    buttonConfiguracao.setXY(8, 102);
    buttonConfiguracao.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));

    buttonWithLabelResetFabrica.setXY(177, 196);
    buttonWithLabelResetFabrica.setBitmaps(touchgfx::Bitmap(BITMAP_SETOFF2S_ID), touchgfx::Bitmap(BITMAP_SETON2S_ID));
    buttonWithLabelResetFabrica.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3790));
    buttonWithLabelResetFabrica.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonWithLabelResetFabrica.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));

    add(__background);
    add(boxFundo);
    add(textAreaLabel);
    add(buttonConfiguracao);
    add(buttonWithLabelResetFabrica);
}

void RESET_FABRICAViewBase::setupScreen()
{

}

void RESET_FABRICAViewBase::handleTickEvent()
{

}

void RESET_FABRICAViewBase::tearDownScreen()
{

}
