/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/higiene_confirmar_screen/HIGIENE_CONFIRMARViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

HIGIENE_CONFIRMARViewBase::HIGIENE_CONFIRMARViewBase() :
    buttonCallback(this, &HIGIENE_CONFIRMARViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxFundoAzul.setPosition(0, 0, 480, 53);
    boxFundoAzul.setColor(touchgfx::Color::getColorFromRGB(122, 117, 181));

    textAreaTitle.setXY(5, 8);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTitle.setLinespacing(0);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3960));

    textAreaStatusPorta.setXY(42, 110);
    textAreaStatusPorta.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaStatusPorta.setLinespacing(0);
    textAreaStatusPorta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3961));

    textAreaStatusPortaAberta.setXY(56, 90);
    textAreaStatusPortaAberta.setVisible(false);
    textAreaStatusPortaAberta.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    textAreaStatusPortaAberta.setLinespacing(0);
    textAreaStatusPortaAberta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4100));

    buttonStartHigiene.setXY(406, 208);
    buttonStartHigiene.setVisible(false);
    buttonStartHigiene.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE_ID), touchgfx::Bitmap(BITMAP_AVANCEON_ID));
    buttonStartHigiene.setAction(buttonCallback);

    buttonTelaInicial.setXY(406, 64);
    buttonTelaInicial.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR_ID), touchgfx::Bitmap(BITMAP_VOLTAR_ID));
    buttonTelaInicial.setAction(buttonCallback);

    status_porta.setXY(5, 64);
    status_porta.setVisible(false);
    status_porta.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    status_porta.setLinespacing(0);
    status_porta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4101));

    add(__background);
    add(boxFundo);
    add(boxFundoAzul);
    add(textAreaTitle);
    add(textAreaStatusPorta);
    add(textAreaStatusPortaAberta);
    add(buttonStartHigiene);
    add(buttonTelaInicial);
    add(status_porta);
}

void HIGIENE_CONFIRMARViewBase::setupScreen()
{

    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Clear();
    
    ReadWriteModbus485(&status_porta, status_portaBuffer, "553", 0, _INT_, REPEAT);

}

//Called when the screen transition ends
void HIGIENE_CONFIRMARViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void HIGIENE_CONFIRMARViewBase::handleTickEvent()
{
    //HandleTickEvent
    //When handleTickEvent is called execute C++ code
    //Execute C++ code
    
    if ((touchgfx::Unicode::atoi(status_portaBuffer)) == 1){
    	buttonStartHigiene.setVisible(true);
    	textAreaStatusPorta.setVisible(false);
    	textAreaStatusPortaAberta.setVisible(true); 
    }else{
    	buttonStartHigiene.setVisible(false);
    	textAreaStatusPorta.setVisible(true);
    	textAreaStatusPortaAberta.setVisible(false); 
    }
    invalidate();
}

void HIGIENE_CONFIRMARViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
}

void HIGIENE_CONFIRMARViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonStartHigiene)
    {
        //start_higiene
        //When buttonStartHigiene clicked change screen to HIGIENE
        //Go to HIGIENE with no screen transition
        application().gotoHIGIENEScreenNoTransition();
    }
    else if (&src == &buttonTelaInicial)
    {
        //TelaInicial
        //When buttonTelaInicial clicked change screen to Tela_Inicial
        //Go to Tela_Inicial with no screen transition
        application().gotoTela_InicialScreenNoTransition();
    }
}
