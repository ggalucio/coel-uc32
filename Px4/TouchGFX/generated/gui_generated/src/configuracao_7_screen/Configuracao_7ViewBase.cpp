/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/configuracao_7_screen/Configuracao_7ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Configuracao_7ViewBase::Configuracao_7ViewBase()
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxVermelho2.setPosition(66, 192, 78, 29);
    boxVermelho2.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    boxVermelho.setPosition(66, 158, 78, 29);
    boxVermelho.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    boxVerde4.setPosition(66, 117, 78, 29);
    boxVerde4.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    boxVerde3.setPosition(66, 83, 78, 29);
    boxVerde3.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    boxVerde2.setPosition(66, 49, 78, 29);
    boxVerde2.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    boxVerde.setPosition(66, 15, 78, 29);
    boxVerde.setColor(touchgfx::Color::getColorFromRGB(125, 190, 255));

    textAreaLabel1.setXY(151, 16);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3767));

    textAreaLabel2.setXY(151, 50);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3768));

    textAreaLabel3.setXY(151, 84);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3769));

    textAreaLabel4.setXY(151, 118);
    textAreaLabel4.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel4.setLinespacing(0);
    textAreaLabel4.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3770));

    textAreaLabel5.setXY(151, 165);
    textAreaLabel5.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel5.setLinespacing(0);
    textAreaLabel5.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3771));

    textAreaLabel6.setXY(151, 192);
    textAreaLabel6.setColor(touchgfx::Color::getColorFromRGB(38, 147, 255));
    textAreaLabel6.setLinespacing(0);
    textAreaLabel6.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3772));

    buttonTelaInicial.setXY(433, 220);

    buttonConfiguracao6.setXY(8, 102);
    buttonConfiguracao6.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR2_ID), touchgfx::Bitmap(BITMAP_VOLTAR2_ID));

    textAreaSpSondaResfCamara.setPosition(66, 117, 78, 29);
    textAreaSpSondaResfCamara.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpSondaResfCamara.setLinespacing(0);
    Unicode::snprintf(textAreaSpSondaResfCamaraBuffer, TEXTAREASPSONDARESFCAMARA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3775).getText());
    textAreaSpSondaResfCamara.setWildcard(textAreaSpSondaResfCamaraBuffer);
    textAreaSpSondaResfCamara.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3774));

    textAreaSpResfriarSonda.setPosition(66, 83, 78, 29);
    textAreaSpResfriarSonda.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpResfriarSonda.setLinespacing(0);
    Unicode::snprintf(textAreaSpResfriarSondaBuffer, TEXTAREASPRESFRIARSONDA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3777).getText());
    textAreaSpResfriarSonda.setWildcard(textAreaSpResfriarSondaBuffer);
    textAreaSpResfriarSonda.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3776));

    textAreaSpResfInternoF1.setPosition(66, 49, 78, 29);
    textAreaSpResfInternoF1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpResfInternoF1.setLinespacing(0);
    Unicode::snprintf(textAreaSpResfInternoF1Buffer, TEXTAREASPRESFINTERNOF1_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3779).getText());
    textAreaSpResfInternoF1.setWildcard(textAreaSpResfInternoF1Buffer);
    textAreaSpResfInternoF1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3778));

    textAreaSpResfEspetoF1.setPosition(66, 15, 78, 29);
    textAreaSpResfEspetoF1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaSpResfEspetoF1.setLinespacing(0);
    Unicode::snprintf(textAreaSpResfEspetoF1Buffer, TEXTAREASPRESFESPETOF1_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3781).getText());
    textAreaSpResfEspetoF1.setWildcard(textAreaSpResfEspetoF1Buffer);
    textAreaSpResfEspetoF1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3780));

    textAreaPorcResfPresetTempoF1F2.setPosition(66, 192, 78, 29);
    textAreaPorcResfPresetTempoF1F2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaPorcResfPresetTempoF1F2.setLinespacing(0);
    Unicode::snprintf(textAreaPorcResfPresetTempoF1F2Buffer, TEXTAREAPORCRESFPRESETTEMPOF1F2_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3785).getText());
    textAreaPorcResfPresetTempoF1F2.setWildcard(textAreaPorcResfPresetTempoF1F2Buffer);
    textAreaPorcResfPresetTempoF1F2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3784));

    textAreaDiferencialResfriarTempo.setPosition(66, 158, 78, 29);
    textAreaDiferencialResfriarTempo.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaDiferencialResfriarTempo.setLinespacing(0);
    Unicode::snprintf(textAreaDiferencialResfriarTempoBuffer, TEXTAREADIFERENCIALRESFRIARTEMPO_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3787).getText());
    textAreaDiferencialResfriarTempo.setWildcard(textAreaDiferencialResfriarTempoBuffer);
    textAreaDiferencialResfriarTempo.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3786));

    add(__background);
    add(boxFundo);
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
    add(buttonTelaInicial);
    add(buttonConfiguracao6);
    add(textAreaSpSondaResfCamara);
    add(textAreaSpResfriarSonda);
    add(textAreaSpResfInternoF1);
    add(textAreaSpResfEspetoF1);
    add(textAreaPorcResfPresetTempoF1F2);
    add(textAreaDiferencialResfriarTempo);
}

void Configuracao_7ViewBase::setupScreen()
{

}

void Configuracao_7ViewBase::handleTickEvent()
{

}

void Configuracao_7ViewBase::tearDownScreen()
{

}