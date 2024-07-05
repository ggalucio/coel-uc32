/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/configuracao_5_screen/Configuracao_5ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Configuracao_5ViewBase::Configuracao_5ViewBase()
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxWithBorder1.setPosition(138, 144, 204, 27);
    boxWithBorder1.setColor(touchgfx::Color::getColorFromRGB(255, 128, 128));
    boxWithBorder1.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder1.setBorderSize(1);

    boxWithBorder4.setPosition(87, 227, 64, 33);
    boxWithBorder4.setColor(touchgfx::Color::getColorFromRGB(0, 128, 0));
    boxWithBorder4.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder4.setBorderSize(1);

    boxWithBorder3.setPosition(138, 109, 204, 27);
    boxWithBorder3.setColor(touchgfx::Color::getColorFromRGB(255, 128, 128));
    boxWithBorder3.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder3.setBorderSize(1);

    boxWithBorder2.setPosition(87, 31, 64, 33);
    boxWithBorder2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    boxWithBorder2.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxWithBorder2.setBorderSize(1);

    textAreaLabel1_1.setXY(175, 89);
    textAreaLabel1_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel1_1.setLinespacing(0);
    textAreaLabel1_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3746));

    textAreaLabel1.setXY(160, 34);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3745));

    textAreaLabel1_2.setXY(160, 190);
    textAreaLabel1_2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel1_2.setLinespacing(0);
    textAreaLabel1_2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3753));

    textAreaLabel1_2_1.setXY(160, 230);
    textAreaLabel1_2_1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaLabel1_2_1.setLinespacing(0);
    textAreaLabel1_2_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3754));

    buttonTelaInicial.setXY(433, 220);

    buttonConfiguracao6.setXY(443, 102);
    buttonConfiguracao6.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE2_ID), touchgfx::Bitmap(BITMAP_AVANCE2_ID));

    buttonConfiguracao4.setXY(8, 102);
    buttonConfiguracao4.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));

    toggleButtonFlagHabDesabTeclaRedial.setXY(87, 187);
    toggleButtonFlagHabDesabTeclaRedial.setBitmaps(touchgfx::Bitmap(BITMAP_S1S_ID), touchgfx::Bitmap(BITMAP_S2S_ID));

    textAreaTimerAlarmeExternoSpMinutos.setPosition(87, 31, 64, 33);
    textAreaTimerAlarmeExternoSpMinutos.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTimerAlarmeExternoSpMinutos.setLinespacing(0);
    Unicode::snprintf(textAreaTimerAlarmeExternoSpMinutosBuffer, TEXTAREATIMERALARMEEXTERNOSPMINUTOS_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3744).getText());
    textAreaTimerAlarmeExternoSpMinutos.setWildcard(textAreaTimerAlarmeExternoSpMinutosBuffer);
    textAreaTimerAlarmeExternoSpMinutos.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3743));

    textAreaHAW8214.setPosition(138, 109, 204, 27);
    textAreaHAW8214.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaHAW8214.setLinespacing(0);
    Unicode::snprintf(textAreaHAW8214Buffer, TEXTAREAHAW8214_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3748).getText());
    textAreaHAW8214.setWildcard(textAreaHAW8214Buffer);
    textAreaHAW8214.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3747));

    textAreaHAW8235.setPosition(138, 144, 204, 27);
    textAreaHAW8235.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaHAW8235.setLinespacing(0);
    Unicode::snprintf(textAreaHAW8235Buffer, TEXTAREAHAW8235_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3750).getText());
    textAreaHAW8235.setWildcard(textAreaHAW8235Buffer);
    textAreaHAW8235.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3749));

    textArea1410299.setPosition(87, 227, 64, 33);
    textArea1410299.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410299.setLinespacing(0);
    Unicode::snprintf(textArea1410299Buffer, TEXTAREA1410299_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3752).getText());
    textArea1410299.setWildcard(textArea1410299Buffer);
    textArea1410299.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3751));

    add(__background);
    add(boxFundo);
    add(boxWithBorder1);
    add(boxWithBorder4);
    add(boxWithBorder3);
    add(boxWithBorder2);
    add(textAreaLabel1_1);
    add(textAreaLabel1);
    add(textAreaLabel1_2);
    add(textAreaLabel1_2_1);
    add(buttonTelaInicial);
    add(buttonConfiguracao6);
    add(buttonConfiguracao4);
    add(toggleButtonFlagHabDesabTeclaRedial);
    add(textAreaTimerAlarmeExternoSpMinutos);
    add(textAreaHAW8214);
    add(textAreaHAW8235);
    add(textArea1410299);
}

void Configuracao_5ViewBase::setupScreen()
{

}

void Configuracao_5ViewBase::handleTickEvent()
{

}

void Configuracao_5ViewBase::tearDownScreen()
{

}