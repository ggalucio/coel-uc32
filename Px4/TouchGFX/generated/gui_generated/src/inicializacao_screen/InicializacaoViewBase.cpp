/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/inicializacao_screen/InicializacaoViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"

InicializacaoViewBase::InicializacaoViewBase()
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    scalableImageLogo.setBitmap(touchgfx::Bitmap(BITMAP_TELA_INICIAL_COEL_ID));
    scalableImageLogo.setPosition(80, 16, 321, 241);
    scalableImageLogo.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    add(__background);
    add(boxFundo);
    add(scalableImageLogo);
}

void InicializacaoViewBase::setupScreen()
{

    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    SetModbus485As(0, 9600);

}

//Called when the screen transition ends
void InicializacaoViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void InicializacaoViewBase::handleTickEvent()
{
    //HandleTickEvent
    //When handleTickEvent is called execute C++ code
    //Execute C++ code
    
    if (countTicksEventInicializacao < 3000)
    	countTicksEventInicializacao += 16;
    else
    	inicialScreen();
}

void InicializacaoViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
}

void InicializacaoViewBase::inicialScreen()
{
    //InicialScreen
    //When inicialScreen is called change screen to Tela_Inicial
    //Go to Tela_Inicial with no screen transition
    application().gotoTela_InicialScreenNoTransition();
}
