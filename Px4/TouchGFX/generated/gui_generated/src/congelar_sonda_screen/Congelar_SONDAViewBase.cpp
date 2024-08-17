/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/congelar_sonda_screen/Congelar_SONDAViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Congelar_SONDAViewBase::Congelar_SONDAViewBase() :
    buttonCallback(this, &Congelar_SONDAViewBase::buttonCallbackHandler),
    cANCELAR_PROCESSO1CancelarProcessoCallback(this, &Congelar_SONDAViewBase::cANCELAR_PROCESSO1CancelarProcessoCallbackHandler),
    cANCELAR_PROCESSO1NaoCallback(this, &Congelar_SONDAViewBase::cANCELAR_PROCESSO1NaoCallbackHandler)
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
    textAreaUnidade2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3658));

    textAreaUnidade3.setXY(337, 199);
    textAreaUnidade3.setColor(touchgfx::Color::getColorFromRGB(42, 106, 162));
    textAreaUnidade3.setLinespacing(0);
    textAreaUnidade3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3659));

    textAreaUnidade1.setXY(353, 71);
    textAreaUnidade1.setColor(touchgfx::Color::getColorFromRGB(42, 106, 162));
    textAreaUnidade1.setLinespacing(0);
    textAreaUnidade1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3660));

    textAreaTitle.setXY(5, 8);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTitle.setLinespacing(0);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3661));

    buttonCancelarProcesso.setXY(406, 64);
    buttonCancelarProcesso.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR_ID), touchgfx::Bitmap(BITMAP_VOLTAR_ID));
    buttonCancelarProcesso.setAction(buttonCallback);

    toggleButtonFlagConservarSN.setXY(405, 208);
    toggleButtonFlagConservarSN.setBitmaps(touchgfx::Bitmap(BITMAP_CSVOFF_ID), touchgfx::Bitmap(BITMAP_CSVON_ID));
    toggleButtonFlagConservarSN.setAction(buttonCallback);

    imageVazio.setXY(406, 136);
    imageVazio.setBitmap(touchgfx::Bitmap(BITMAP_VAZIO_ID));

    image1.setXY(25, 79);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_PAO_ID));

    image2.setXY(18, 209);
    image2.setBitmap(touchgfx::Bitmap(BITMAP_AMPULHETA_ID));

    image3.setXY(18, 146);
    image3.setBitmap(touchgfx::Bitmap(BITMAP_AMPULHETA_ID));

    textAreaLabel1.setXY(73, 71);
    textAreaLabel1.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaLabel1.setLinespacing(0);
    textAreaLabel1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3662));

    textAreaLabel2.setXY(73, 136);
    textAreaLabel2.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaLabel2.setLinespacing(0);
    textAreaLabel2.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3663));

    textAreaLabel3.setXY(73, 199);
    textAreaLabel3.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaLabel3.setLinespacing(0);
    textAreaLabel3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3664));

    textArea14515.setPosition(172, 69, 121, 56);
    textArea14515.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textArea14515.setLinespacing(0);
    Unicode::snprintf(textArea14515Buffer, TEXTAREA14515_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3666).getText());
    textArea14515.setWildcard(textArea14515Buffer);
    textArea14515.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3665));

    textAreaTimerCountMinutos.setPosition(172, 134, 121, 56);
    textAreaTimerCountMinutos.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaTimerCountMinutos.setLinespacing(0);
    Unicode::snprintf(textAreaTimerCountMinutosBuffer, TEXTAREATIMERCOUNTMINUTOS_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3668).getText());
    textAreaTimerCountMinutos.setWildcard(textAreaTimerCountMinutosBuffer);
    textAreaTimerCountMinutos.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3667));

    textAreaFlagProcessoAndamento.setPosition(308, 14, 160, 25);
    textAreaFlagProcessoAndamento.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaFlagProcessoAndamento.setLinespacing(0);
    Unicode::snprintf(textAreaFlagProcessoAndamentoBuffer, TEXTAREAFLAGPROCESSOANDAMENTO_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4019).getText());
    textAreaFlagProcessoAndamento.setWildcard(textAreaFlagProcessoAndamentoBuffer);
    textAreaFlagProcessoAndamento.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3813));

    textAreaTempoEstimadoCongelarSonda.setPosition(172, 199, 121, 55);
    textAreaTempoEstimadoCongelarSonda.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaTempoEstimadoCongelarSonda.setLinespacing(0);
    Unicode::snprintf(textAreaTempoEstimadoCongelarSondaBuffer, TEXTAREATEMPOESTIMADOCONGELARSONDA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3670).getText());
    textAreaTempoEstimadoCongelarSonda.setWildcard(textAreaTempoEstimadoCongelarSondaBuffer);
    textAreaTempoEstimadoCongelarSonda.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3669));

    textArea14512.setPosition(328, 102, 56, 18);
    textArea14512.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textArea14512.setLinespacing(0);
    Unicode::snprintf(textArea14512Buffer, TEXTAREA14512_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3676).getText());
    textArea14512.setWildcard(textArea14512Buffer);
    textArea14512.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3675));

    textAreaTimerCongelarDecorridoCount.setPosition(328, 165, 56, 18);
    textAreaTimerCongelarDecorridoCount.setColor(touchgfx::Color::getColorFromRGB(26, 100, 160));
    textAreaTimerCongelarDecorridoCount.setLinespacing(0);
    Unicode::snprintf(textAreaTimerCongelarDecorridoCountBuffer, TEXTAREATIMERCONGELARDECORRIDOCOUNT_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3672).getText());
    textAreaTimerCongelarDecorridoCount.setWildcard(textAreaTimerCongelarDecorridoCountBuffer);
    textAreaTimerCongelarDecorridoCount.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3671));

    textAreaCongelarSondaSp.setPosition(181, 105, 105, 18);
    textAreaCongelarSondaSp.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaCongelarSondaSp.setLinespacing(0);
    Unicode::snprintf(textAreaCongelarSondaSpBuffer, TEXTAREACONGELARSONDASP_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3674).getText());
    textAreaCongelarSondaSp.setWildcard(textAreaCongelarSondaSpBuffer);
    textAreaCongelarSondaSp.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3673));

    cANCELAR_PROCESSO1.setXY(0, 0);
    cANCELAR_PROCESSO1.setVisible(false);
    cANCELAR_PROCESSO1.setCancelarProcessoCallback(cANCELAR_PROCESSO1CancelarProcessoCallback);
    cANCELAR_PROCESSO1.setNaoCallback(cANCELAR_PROCESSO1NaoCallback);

    imageStatusPorta.setXY(200, 0);
    imageStatusPorta.setVisible(false);
    imageStatusPorta.setBitmap(touchgfx::Bitmap(BITMAP_PORTA_ID));

    textAreaStatusPorta.setXY(98, 13);
    textAreaStatusPorta.setVisible(false);
    textAreaStatusPorta.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaStatusPorta.setLinespacing(0);
    Unicode::snprintf(textAreaStatusPortaBuffer, TEXTAREASTATUSPORTA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4108).getText());
    textAreaStatusPorta.setWildcard(textAreaStatusPortaBuffer);
    textAreaStatusPorta.resizeToCurrentText();
    textAreaStatusPorta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4107));

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
    add(textArea14515);
    add(textAreaTimerCountMinutos);
    add(textAreaFlagProcessoAndamento);
    add(textAreaTempoEstimadoCongelarSonda);
    add(textArea14512);
    add(textAreaTimerCongelarDecorridoCount);
    add(textAreaCongelarSondaSp);
    add(cANCELAR_PROCESSO1);
    add(imageStatusPorta);
    add(textAreaStatusPorta);
}

void Congelar_SONDAViewBase::setupScreen()
{
    cANCELAR_PROCESSO1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    AddbackgroundContainer(this);
    W_HDW5000 = 2; 
    
    // Clear();
    
    ReadWriteModbus485(&textAreaStatusPorta, textAreaStatusPortaBuffer, "553", 0, _INT_, REPEAT);
    
    ReadWriteModbus485(&textArea14515, textArea14515Buffer, "515", 1, _DOUBLE_, REPEAT);
    ReadWriteModbus485(&textArea14512, textArea14512Buffer, "512", 1, _DOUBLE_, REPEAT);
    
    // Update(&textArea14515, textArea14515Buffer, 0, _DOUBLE_, 1);
    Update(&textAreaCongelarSondaSp, textAreaCongelarSondaSpBuffer, 0, _DOUBLE_, 1);
    // Update(&textArea14512, textArea14512Buffer, 0, _DOUBLE_, 1);
    
    Update(&textAreaTimerCountMinutos, textAreaTimerCountMinutosBuffer, 0, _INT_, 0);
    Update(&textAreaTimerCongelarDecorridoCount, textAreaTimerCongelarDecorridoCountBuffer, 0, _INT_, 0);
    
    Update(&textAreaTempoEstimadoCongelarSonda, textAreaTempoEstimadoCongelarSondaBuffer, 0, _INT_, 0);
    
    Update(&textAreaFlagProcessoAndamento, textAreaFlagProcessoAndamentoBuffer, "OPERANDO...", 20);
    countCycleBlink = 0;

}

//Called when the screen transition ends
void Congelar_SONDAViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Congelar_SONDAViewBase::cANCELAR_PROCESSO1CancelarProcessoCallbackHandler()
{
    //CancelarProcesso
    //When cANCELAR_PROCESSO1 cancelarProcesso change screen to Congelar
    //Go to Congelar with no screen transition
    application().gotoCongelarScreenNoTransition();
}

void Congelar_SONDAViewBase::cANCELAR_PROCESSO1NaoCallbackHandler()
{
    //Nao
    //When cANCELAR_PROCESSO1 nao execute C++ code
    //Execute C++ code
    ContainerVisibility(&cANCELAR_PROCESSO1, false);
    SoundBuzzerOn(25);
}

void Congelar_SONDAViewBase::handleTickEvent()
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
    
    if (countCycleBlink > 1000)
    {
    	countCycleBlink = 0;
    	VisibilityTextArea(&textAreaFlagProcessoAndamento, !textAreaFlagProcessoAndamento.isVisible());
    }
    
    countCycleBlink += 16;
}

void Congelar_SONDAViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
    ContainerClear(&cANCELAR_PROCESSO1);
}

void Congelar_SONDAViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonCancelarProcesso)
    {
        //Voltar
        //When buttonCancelarProcesso clicked execute C++ code
        //Execute C++ code
        ContainerVisibility(&cANCELAR_PROCESSO1, true);
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButtonFlagConservarSN)
    {
        //CSV
        //When toggleButtonFlagConservarSN clicked execute C++ code
        //Execute C++ code
        SoundBuzzerOn(25);
    }
}
