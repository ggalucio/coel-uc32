/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/configuracao_4_screen/Configuracao_4ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Configuracao_4ViewBase::Configuracao_4ViewBase()
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxWithBorder1.setPosition(99, 106, 52, 33);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder1.setBorderSize(1);

    boxWithBorder2.setPosition(99, 31, 52, 33);
    boxWithBorder2.setColor(touchgfx::Color::getColorFromRGB(0, 255, 255));
    boxWithBorder2.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder2.setBorderSize(1);

    textAreaLabel2.setXY(99, 70);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(3, 129, 255));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3738));

    textAreaLabel1.setXY(99, 214);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3737));

    buttonTelaInicial.setXY(433, 220);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR3_ID), touchgfx::Bitmap(BITMAP_VOLTAR3_ID));

    buttonConfiguracao5.setXY(443, 102);
    buttonConfiguracao5.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE2_ID), touchgfx::Bitmap(BITMAP_AVANCE2_ID));

    buttonConfiguracao3.setXY(8, 102);
    buttonConfiguracao3.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));

    buttonWithLabelLogicaEntradaDigita2_2.setXY(168, 178);
    buttonWithLabelLogicaEntradaDigita2_2.setBitmaps(touchgfx::Bitmap(BITMAP_SETOFF2_ID), touchgfx::Bitmap(BITMAP_SETON2_ID));
    buttonWithLabelLogicaEntradaDigita2_2.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3736));
    buttonWithLabelLogicaEntradaDigita2_2.setLabelColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    buttonWithLabelLogicaEntradaDigita2_2.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 0, 0));

    buttonWithLabelLogicaEntradaDigita2_1.setXY(168, 142);
    buttonWithLabelLogicaEntradaDigita2_1.setBitmaps(touchgfx::Bitmap(BITMAP_SETOFF2_ID), touchgfx::Bitmap(BITMAP_SETON2_ID));
    buttonWithLabelLogicaEntradaDigita2_1.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3735));
    buttonWithLabelLogicaEntradaDigita2_1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    buttonWithLabelLogicaEntradaDigita2_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 255));

    buttonWithLabelLogicaEntradaDigita2_0.setXY(168, 106);
    buttonWithLabelLogicaEntradaDigita2_0.setBitmaps(touchgfx::Bitmap(BITMAP_SETOFF2_ID), touchgfx::Bitmap(BITMAP_SETON2_ID));
    buttonWithLabelLogicaEntradaDigita2_0.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3734));
    buttonWithLabelLogicaEntradaDigita2_0.setLabelColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    buttonWithLabelLogicaEntradaDigita2_0.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 0, 0));

    buttonWithLabelLogicaEntradaDigita1_1.setXY(274, 31);
    buttonWithLabelLogicaEntradaDigita1_1.setBitmaps(touchgfx::Bitmap(BITMAP_SETOFF2_ID), touchgfx::Bitmap(BITMAP_SETON2_ID));
    buttonWithLabelLogicaEntradaDigita1_1.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3733));
    buttonWithLabelLogicaEntradaDigita1_1.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 255));
    buttonWithLabelLogicaEntradaDigita1_1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 255));

    buttonWithLabelLogicaEntradaDigita1_0.setXY(168, 31);
    buttonWithLabelLogicaEntradaDigita1_0.setBitmaps(touchgfx::Bitmap(BITMAP_SETOFF2_ID), touchgfx::Bitmap(BITMAP_SETON2_ID));
    buttonWithLabelLogicaEntradaDigita1_0.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3732));
    buttonWithLabelLogicaEntradaDigita1_0.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 255));
    buttonWithLabelLogicaEntradaDigita1_0.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 255));

    textAreaLogicaEntradaDigital2.setPosition(99, 106, 52, 33);
    textAreaLogicaEntradaDigital2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaLogicaEntradaDigital2.setLinespacing(0);
    Unicode::snprintf(textAreaLogicaEntradaDigital2Buffer, TEXTAREALOGICAENTRADADIGITAL2_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3740).getText());
    textAreaLogicaEntradaDigital2.setWildcard(textAreaLogicaEntradaDigital2Buffer);
    textAreaLogicaEntradaDigital2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3739));

    textAreaLogicaEntradaDigital1.setPosition(99, 31, 52, 33);
    textAreaLogicaEntradaDigital1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 255));
    textAreaLogicaEntradaDigital1.setLinespacing(0);
    Unicode::snprintf(textAreaLogicaEntradaDigital1Buffer, TEXTAREALOGICAENTRADADIGITAL1_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3742).getText());
    textAreaLogicaEntradaDigital1.setWildcard(textAreaLogicaEntradaDigital1Buffer);
    textAreaLogicaEntradaDigital1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3741));

    add(__background);
    add(boxFundo);
    add(boxWithBorder1);
    add(boxWithBorder2);
    add(textAreaLabel2);
    add(textAreaLabel1);
    add(buttonTelaInicial);
    add(buttonConfiguracao5);
    add(buttonConfiguracao3);
    add(buttonWithLabelLogicaEntradaDigita2_2);
    add(buttonWithLabelLogicaEntradaDigita2_1);
    add(buttonWithLabelLogicaEntradaDigita2_0);
    add(buttonWithLabelLogicaEntradaDigita1_1);
    add(buttonWithLabelLogicaEntradaDigita1_0);
    add(textAreaLogicaEntradaDigital2);
    add(textAreaLogicaEntradaDigital1);
}

void Configuracao_4ViewBase::setupScreen()
{

}

void Configuracao_4ViewBase::handleTickEvent()
{

}

void Configuracao_4ViewBase::tearDownScreen()
{

}
