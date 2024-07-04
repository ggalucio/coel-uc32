/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/congelar_tempo_screen/Congelar_TEMPOViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Congelar_TEMPOViewBase::Congelar_TEMPOViewBase()
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxProcessOff.setPosition(5, 64, 392, 196);
    boxProcessOff.setColor(touchgfx::Color::getColorFromRGB(241, 241, 242));

    boxFundoAzul.setPosition(0, 0, 480, 53);
    boxFundoAzul.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));

    boxWithBorderBox3.setPosition(66, 133, 324, 57);
    boxWithBorderBox3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorderBox3.setBorderColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    boxWithBorderBox3.setBorderSize(1);

    boxWithBorderBox2.setPosition(66, 197, 324, 57);
    boxWithBorderBox2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorderBox2.setBorderColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    boxWithBorderBox2.setBorderSize(1);

    boxWithBorderBox1.setPosition(66, 70, 324, 57);
    boxWithBorderBox1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    boxWithBorderBox1.setBorderColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    boxWithBorderBox1.setBorderSize(1);

    boxFundoAzul2.setPosition(181, 105, 105, 19);
    boxFundoAzul2.setColor(touchgfx::Color::getColorFromRGB(42, 106, 162));

    textAreaUnidade2.setXY(337, 134);
    textAreaUnidade2.setColor(touchgfx::Color::getColorFromRGB(42, 106, 162));
    textAreaUnidade2.setLinespacing(0);
    textAreaUnidade2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3649));

    textAreaUnidade3.setXY(337, 199);
    textAreaUnidade3.setColor(touchgfx::Color::getColorFromRGB(42, 106, 162));
    textAreaUnidade3.setLinespacing(0);
    textAreaUnidade3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3650));

    textAreaUnidade1.setXY(353, 71);
    textAreaUnidade1.setColor(touchgfx::Color::getColorFromRGB(42, 106, 162));
    textAreaUnidade1.setLinespacing(0);
    textAreaUnidade1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3651));

    textAreaTitle.setXY(5, 8);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTitle.setLinespacing(0);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3639));

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
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3640));

    textAreaLabel2.setXY(73, 136);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3641));

    textAreaLabel3.setXY(73, 199);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3642));

    textAreaTimerCountMinutos.setPosition(172, 134, 121, 56);
    textAreaTimerCountMinutos.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaTimerCountMinutos.setLinespacing(0);
    Unicode::snprintf(textAreaTimerCountMinutosBuffer, TEXTAREATIMERCOUNTMINUTOS_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3657).getText());
    textAreaTimerCountMinutos.setWildcard(textAreaTimerCountMinutosBuffer);
    textAreaTimerCountMinutos.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3645));

    textAreaTimerSpMinutos.setPosition(172, 199, 121, 55);
    textAreaTimerSpMinutos.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaTimerSpMinutos.setLinespacing(0);
    Unicode::snprintf(textAreaTimerSpMinutosBuffer, TEXTAREATIMERSPMINUTOS_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3656).getText());
    textAreaTimerSpMinutos.setWildcard(textAreaTimerSpMinutosBuffer);
    textAreaTimerSpMinutos.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3647));

    textAreaFlagProcessoAndamento.setXY(360, 14);
    textAreaFlagProcessoAndamento.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaFlagProcessoAndamento.setLinespacing(0);
    textAreaFlagProcessoAndamento.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3814));

    textAreaTimerCongelarDecorridoCount.setPosition(328, 165, 56, 18);
    textAreaTimerCongelarDecorridoCount.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaTimerCongelarDecorridoCount.setLinespacing(0);
    Unicode::snprintf(textAreaTimerCongelarDecorridoCountBuffer, TEXTAREATIMERCONGELARDECORRIDOCOUNT_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3655).getText());
    textAreaTimerCongelarDecorridoCount.setWildcard(textAreaTimerCongelarDecorridoCountBuffer);
    textAreaTimerCongelarDecorridoCount.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3654));

    textArea14512.setPosition(172, 69, 121, 56);
    textArea14512.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textArea14512.setLinespacing(0);
    Unicode::snprintf(textArea14512Buffer, TEXTAREA14512_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3644).getText());
    textArea14512.setWildcard(textArea14512Buffer);
    textArea14512.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3643));

    textArea1410242.setPosition(181, 105, 105, 18);
    textArea1410242.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1410242.setLinespacing(0);
    Unicode::snprintf(textArea1410242Buffer, TEXTAREA1410242_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3653).getText());
    textArea1410242.setWildcard(textArea1410242Buffer);
    textArea1410242.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3652));

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
    add(textAreaTimerSpMinutos);
    add(textAreaFlagProcessoAndamento);
    add(textAreaTimerCongelarDecorridoCount);
    add(textArea14512);
    add(textArea1410242);
}

void Congelar_TEMPOViewBase::setupScreen()
{

}

//Called when the screen transition ends
void Congelar_TEMPOViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Congelar_TEMPOViewBase::handleTickEvent()
{

}

void Congelar_TEMPOViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
}
