/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/configuracao_2_screen/Configuracao_2ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Configuracao_2ViewBase::Configuracao_2ViewBase()
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxVermelho3.setPosition(66, 226, 78, 29);
    boxVermelho3.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    boxVermelho2.setPosition(66, 192, 78, 29);
    boxVermelho2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    boxVermelho.setPosition(66, 158, 78, 29);
    boxVermelho.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));

    boxVerde4.setPosition(66, 117, 78, 29);
    boxVerde4.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));

    boxVerde3.setPosition(66, 83, 78, 29);
    boxVerde3.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));

    boxVerde2.setPosition(66, 49, 78, 29);
    boxVerde2.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));

    boxVerde.setPosition(66, 15, 78, 29);
    boxVerde.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));

    textAreaLabel1.setXY(151, 23);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(0, 184, 0));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3690));

    textAreaLabel2.setXY(151, 57);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(0, 184, 0));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3691));

    textAreaLabel3.setXY(151, 91);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(0, 184, 0));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3692));

    textAreaLabel4.setXY(151, 125);
    textAreaLabel4.setColor(touchgfx::Color::getColorFromRGB(0, 184, 0));
    textAreaLabel4.setLinespacing(0);
    textAreaLabel4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3693));

    textAreaLabel5.setXY(151, 159);
    textAreaLabel5.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaLabel5.setLinespacing(0);
    textAreaLabel5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3703));

    textAreaLabel6.setXY(151, 193);
    textAreaLabel6.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaLabel6.setLinespacing(0);
    textAreaLabel6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3704));

    textAreaLabel7.setXY(151, 234);
    textAreaLabel7.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaLabel7.setLinespacing(0);
    textAreaLabel7.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3705));

    buttonTelaInicial.setXY(433, 220);

    buttonConfiguracao3.setXY(443, 102);
    buttonConfiguracao3.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE2_ID), touchgfx::Bitmap(BITMAP_AVANCE2_ID));

    buttonConfiguracao.setXY(8, 102);
    buttonConfiguracao.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));

    textAreaDiferencialConservarResfriar.setPosition(66, 117, 78, 29);
    textAreaDiferencialConservarResfriar.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaDiferencialConservarResfriar.setLinespacing(0);
    Unicode::snprintf(textAreaDiferencialConservarResfriarBuffer, TEXTAREADIFERENCIALCONSERVARRESFRIAR_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3696).getText());
    textAreaDiferencialConservarResfriar.setWildcard(textAreaDiferencialConservarResfriarBuffer);
    textAreaDiferencialConservarResfriar.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3695));

    textAreaSpConservarResfriar.setPosition(66, 83, 78, 29);
    textAreaSpConservarResfriar.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpConservarResfriar.setLinespacing(0);
    Unicode::snprintf(textAreaSpConservarResfriarBuffer, TEXTAREASPCONSERVARRESFRIAR_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3698).getText());
    textAreaSpConservarResfriar.setWildcard(textAreaSpConservarResfriarBuffer);
    textAreaSpConservarResfriar.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3697));

    textAreaDiferencialConservarCongelar.setPosition(66, 49, 78, 29);
    textAreaDiferencialConservarCongelar.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaDiferencialConservarCongelar.setLinespacing(0);
    Unicode::snprintf(textAreaDiferencialConservarCongelarBuffer, TEXTAREADIFERENCIALCONSERVARCONGELAR_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3700).getText());
    textAreaDiferencialConservarCongelar.setWildcard(textAreaDiferencialConservarCongelarBuffer);
    textAreaDiferencialConservarCongelar.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3699));

    textAreaSpConservarCongelar.setPosition(66, 15, 78, 29);
    textAreaSpConservarCongelar.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpConservarCongelar.setLinespacing(0);
    Unicode::snprintf(textAreaSpConservarCongelarBuffer, TEXTAREASPCONSERVARCONGELAR_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3702).getText());
    textAreaSpConservarCongelar.setWildcard(textAreaSpConservarCongelarBuffer);
    textAreaSpConservarCongelar.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3701));

    textArea1410270.setPosition(66, 226, 78, 29);
    textArea1410270.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410270.setLinespacing(0);
    Unicode::snprintf(textArea1410270Buffer, TEXTAREA1410270_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3707).getText());
    textArea1410270.setWildcard(textArea1410270Buffer);
    textArea1410270.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3706));

    textArea1410275.setPosition(66, 192, 78, 29);
    textArea1410275.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410275.setLinespacing(0);
    Unicode::snprintf(textArea1410275Buffer, TEXTAREA1410275_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3709).getText());
    textArea1410275.setWildcard(textArea1410275Buffer);
    textArea1410275.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3708));

    textArea1410272.setPosition(66, 158, 78, 29);
    textArea1410272.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410272.setLinespacing(0);
    Unicode::snprintf(textArea1410272Buffer, TEXTAREA1410272_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3711).getText());
    textArea1410272.setWildcard(textArea1410272Buffer);
    textArea1410272.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3710));

    add(__background);
    add(boxFundo);
    add(boxVermelho3);
    add(boxVermelho2);
    add(boxVermelho);
    add(boxVerde4);
    add(boxVerde3);
    add(boxVerde2);
    add(boxVerde);
    add(textAreaLabel1);
    add(textAreaLabel2);
    add(textAreaLabel3);
    add(textAreaLabel4);
    add(textAreaLabel5);
    add(textAreaLabel6);
    add(textAreaLabel7);
    add(buttonTelaInicial);
    add(buttonConfiguracao3);
    add(buttonConfiguracao);
    add(textAreaDiferencialConservarResfriar);
    add(textAreaSpConservarResfriar);
    add(textAreaDiferencialConservarCongelar);
    add(textAreaSpConservarCongelar);
    add(textArea1410270);
    add(textArea1410275);
    add(textArea1410272);
}

void Configuracao_2ViewBase::setupScreen()
{

}

void Configuracao_2ViewBase::handleTickEvent()
{

}

void Configuracao_2ViewBase::tearDownScreen()
{

}