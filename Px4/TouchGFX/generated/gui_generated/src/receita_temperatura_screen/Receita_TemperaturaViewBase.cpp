/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/receita_temperatura_screen/Receita_TemperaturaViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Receita_TemperaturaViewBase::Receita_TemperaturaViewBase()
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxProcessOff.setPosition(5, 64, 392, 196);
    boxProcessOff.setColor(touchgfx::Color::getColorFromRGB(241, 241, 242));

    boxFundoAzul.setPosition(0, 0, 480, 53);
    boxFundoAzul.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));

    boxWithBorderBox3.setPosition(66, 133, 324, 57);
    boxWithBorderBox3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorderBox3.setBorderColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    boxWithBorderBox3.setBorderSize(1);

    boxWithBorderBox2.setPosition(66, 197, 324, 57);
    boxWithBorderBox2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorderBox2.setBorderColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    boxWithBorderBox2.setBorderSize(1);

    boxWithBorderBox1.setPosition(66, 70, 324, 57);
    boxWithBorderBox1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorderBox1.setBorderColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    boxWithBorderBox1.setBorderSize(1);

    boxFundoAzul2.setPosition(181, 105, 105, 19);
    boxFundoAzul2.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));

    textAreaUnidade2.setXY(337, 134);
    textAreaUnidade2.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textAreaUnidade2.setLinespacing(0);
    textAreaUnidade2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3940));

    textAreaUnidade3.setXY(337, 199);
    textAreaUnidade3.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textAreaUnidade3.setLinespacing(0);
    textAreaUnidade3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3941));

    textAreaUnidade1.setXY(353, 71);
    textAreaUnidade1.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textAreaUnidade1.setLinespacing(0);
    textAreaUnidade1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3942));

    textAreaTitle.setXY(5, 8);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTitle.setLinespacing(0);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3943));

    buttonCancelarProcesso.setXY(406, 64);
    buttonCancelarProcesso.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR_ID), touchgfx::Bitmap(BITMAP_VOLTAR_ID));

    toggleButtonFlagConservarSN.setXY(405, 208);
    toggleButtonFlagConservarSN.setBitmaps(touchgfx::Bitmap(BITMAP_CSVOFF_ID), touchgfx::Bitmap(BITMAP_CSVON_ID));

    imageVazio.setXY(406, 136);
    imageVazio.setBitmap(touchgfx::Bitmap(BITMAP_VAZIO_ID));

    image1.setXY(25, 79);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_THERMOM_ID));

    image2.setXY(18, 209);
    image2.setBitmap(touchgfx::Bitmap(BITMAP_AMPULHETA_ID));

    image3.setXY(18, 146);
    image3.setBitmap(touchgfx::Bitmap(BITMAP_AMPULHETA_ID));

    textAreaLabel1.setXY(73, 71);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3944));

    textAreaLabel2.setXY(73, 136);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3945));

    textAreaLabel3.setXY(73, 199);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3946));

    textAreaTimerCountMinutos.setPosition(172, 134, 121, 56);
    textAreaTimerCountMinutos.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textAreaTimerCountMinutos.setLinespacing(0);
    Unicode::snprintf(textAreaTimerCountMinutosBuffer, TEXTAREATIMERCOUNTMINUTOS_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3948).getText());
    textAreaTimerCountMinutos.setWildcard(textAreaTimerCountMinutosBuffer);
    textAreaTimerCountMinutos.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3947));

    textAreaTempoEstimadoReceitaTemprat.setPosition(172, 199, 121, 55);
    textAreaTempoEstimadoReceitaTemprat.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textAreaTempoEstimadoReceitaTemprat.setLinespacing(0);
    Unicode::snprintf(textAreaTempoEstimadoReceitaTempratBuffer, TEXTAREATEMPOESTIMADORECEITATEMPRAT_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3950).getText());
    textAreaTempoEstimadoReceitaTemprat.setWildcard(textAreaTempoEstimadoReceitaTempratBuffer);
    textAreaTempoEstimadoReceitaTemprat.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3949));

    textAreaFlagProcessoAndamento.setXY(360, 14);
    textAreaFlagProcessoAndamento.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaFlagProcessoAndamento.setLinespacing(0);
    textAreaFlagProcessoAndamento.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3951));

    textAreaTimerCongelarDecorridoCount.setPosition(328, 165, 56, 18);
    textAreaTimerCongelarDecorridoCount.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textAreaTimerCongelarDecorridoCount.setLinespacing(0);
    Unicode::snprintf(textAreaTimerCongelarDecorridoCountBuffer, TEXTAREATIMERCONGELARDECORRIDOCOUNT_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3953).getText());
    textAreaTimerCongelarDecorridoCount.setWildcard(textAreaTimerCongelarDecorridoCountBuffer);
    textAreaTimerCongelarDecorridoCount.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3952));

    textArea14515.setPosition(172, 69, 121, 56);
    textArea14515.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textArea14515.setLinespacing(0);
    Unicode::snprintf(textArea14515Buffer, TEXTAREA14515_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3955).getText());
    textArea14515.setWildcard(textArea14515Buffer);
    textArea14515.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3954));

    textAreaTemperaturaReceitaAtual.setPosition(181, 105, 105, 18);
    textAreaTemperaturaReceitaAtual.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTemperaturaReceitaAtual.setLinespacing(0);
    Unicode::snprintf(textAreaTemperaturaReceitaAtualBuffer, TEXTAREATEMPERATURARECEITAATUAL_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3957).getText());
    textAreaTemperaturaReceitaAtual.setWildcard(textAreaTemperaturaReceitaAtualBuffer);
    textAreaTemperaturaReceitaAtual.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3956));

    textArea14512.setPosition(328, 102, 56, 18);
    textArea14512.setColor(touchgfx::Color::getColorFromRGB(243, 120, 54));
    textArea14512.setLinespacing(0);
    Unicode::snprintf(textArea14512Buffer, TEXTAREA14512_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3959).getText());
    textArea14512.setWildcard(textArea14512Buffer);
    textArea14512.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3958));

    imageStatusPorta.setXY(200, 0);
    imageStatusPorta.setVisible(false);
    imageStatusPorta.setBitmap(touchgfx::Bitmap(BITMAP_PORTA_ID));

    textAreaStatusPorta.setXY(98, 13);
    textAreaStatusPorta.setVisible(false);
    textAreaStatusPorta.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaStatusPorta.setLinespacing(0);
    Unicode::snprintf(textAreaStatusPortaBuffer, TEXTAREASTATUSPORTA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4156).getText());
    textAreaStatusPorta.setWildcard(textAreaStatusPortaBuffer);
    textAreaStatusPorta.resizeToCurrentText();
    textAreaStatusPorta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4155));

    add(__background);
    add(boxFundo);
    add(boxProcessOff);
    add(boxFundoAzul);
    add(boxWithBorderBox3);
    add(boxWithBorderBox2);
    add(boxWithBorderBox1);
    add(boxFundoAzul2);
    add(textAreaUnidade2);
    add(textAreaUnidade3);
    add(textAreaUnidade1);
    add(textAreaTitle);
    add(buttonCancelarProcesso);
    add(toggleButtonFlagConservarSN);
    add(imageVazio);
    add(image1);
    add(image2);
    add(image3);
    add(textAreaLabel1);
    add(textAreaLabel2);
    add(textAreaLabel3);
    add(textAreaTimerCountMinutos);
    add(textAreaTempoEstimadoReceitaTemprat);
    add(textAreaFlagProcessoAndamento);
    add(textAreaTimerCongelarDecorridoCount);
    add(textArea14515);
    add(textAreaTemperaturaReceitaAtual);
    add(textArea14512);
    add(imageStatusPorta);
    add(textAreaStatusPorta);
}

void Receita_TemperaturaViewBase::setupScreen()
{

    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    AddbackgroundContainer(this);
    W_HDW5000 = 40;
    
    // Clear();
    
    ReadWriteModbus485(&textAreaStatusPorta, textAreaStatusPortaBuffer, "553", 0, _INT_, REPEAT);

}

//Called when the screen transition ends
void Receita_TemperaturaViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Receita_TemperaturaViewBase::handleTickEvent()
{
    //HandleTickEvent
    //When handleTickEvent is called execute C++ code
    //Execute C++ code
    if ((touchgfx::Unicode::atoi(textAreaStatusPortaBuffer)) == 1){
    	imageStatusPorta.setVisible(true);
    }else{
    	imageStatusPorta.setVisible(false);
    }
    invalidate();
    W_1_4553 = imageStatusPorta.isVisible();
}

void Receita_TemperaturaViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
}
