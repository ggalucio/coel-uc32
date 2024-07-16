/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/Finalizar_DegeloBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

Finalizar_DegeloBase::Finalizar_DegeloBase()
{
    setWidth(480);
    setHeight(272);
    box1.setPosition(0, 0, 480, 272);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    box1.setAlpha(128);

    box2.setPosition(77, 14, 326, 244);
    box2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 128));

    buttonWithLabelNao.setXY(250, 184);
    buttonWithLabelNao.setBitmaps(touchgfx::Bitmap(BITMAP_R1_ID), touchgfx::Bitmap(BITMAP_R2_ID));
    buttonWithLabelNao.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3979));
    buttonWithLabelNao.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonWithLabelNao.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));

    buttonWithLabelCancelarDegeloSim.setXY(86, 184);
    buttonWithLabelCancelarDegeloSim.setBitmaps(touchgfx::Bitmap(BITMAP_R3_ID), touchgfx::Bitmap(BITMAP_R4_ID));
    buttonWithLabelCancelarDegeloSim.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3980));
    buttonWithLabelCancelarDegeloSim.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonWithLabelCancelarDegeloSim.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));

    textAreaMensagem.setXY(140, 62);
    textAreaMensagem.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaMensagem.setLinespacing(0);
    textAreaMensagem.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3981));

    add(box1);
    add(box2);
    add(buttonWithLabelNao);
    add(buttonWithLabelCancelarDegeloSim);
    add(textAreaMensagem);
}

void Finalizar_DegeloBase::initialize()
{

}

void Finalizar_DegeloBase::init()
{

}
