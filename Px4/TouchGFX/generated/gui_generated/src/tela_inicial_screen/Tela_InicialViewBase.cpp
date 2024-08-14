/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/tela_inicial_screen/Tela_InicialViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

Tela_InicialViewBase::Tela_InicialViewBase() :
    buttonCallback(this, &Tela_InicialViewBase::buttonCallbackHandler),
    solicitar_senha1CancelarCallback(this, &Tela_InicialViewBase::solicitar_senha1CancelarCallbackHandler),
    solicitar_senha1DigitarCallback(this, &Tela_InicialViewBase::solicitar_senha1DigitarCallbackHandler),
    numKeyboardContainerPwd1CredentialSuccessCallback(this, &Tela_InicialViewBase::numKeyboardContainerPwd1CredentialSuccessCallbackHandler),
    numKeyboardContainerPwd1CredentialFailedCallback(this, &Tela_InicialViewBase::numKeyboardContainerPwd1CredentialFailedCallbackHandler),
    numKeyboardContainerPwd1CancelTriggerCallback(this, &Tela_InicialViewBase::numKeyboardContainerPwd1CancelTriggerCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(235, 237, 239));

    imageLogo.setXY(28, 13);
    imageLogo.setBitmap(touchgfx::Bitmap(BITMAP_LOGOCOEL_ID));

    buttonCongelar.setXY(28, 63);
    buttonCongelar.setBitmaps(touchgfx::Bitmap(BITMAP_CONGELAR_ID), touchgfx::Bitmap(BITMAP_CONGELAR_ID));
    buttonCongelar.setAction(buttonCallback);

    buttonConcervar.setXY(28, 133);
    buttonConcervar.setBitmaps(touchgfx::Bitmap(BITMAP_CONSERVAR_ID), touchgfx::Bitmap(BITMAP_CONSERVAR_ID));
    buttonConcervar.setAction(buttonCallback);

    buttonReceitas.setXY(28, 204);
    buttonReceitas.setBitmaps(touchgfx::Bitmap(BITMAP_RECEITAS_ID), touchgfx::Bitmap(BITMAP_RECEITAS_ID));
    buttonReceitas.setAction(buttonCallback);

    buttonResfriar.setXY(177, 63);
    buttonResfriar.setBitmaps(touchgfx::Bitmap(BITMAP_RESFRIAR_ID), touchgfx::Bitmap(BITMAP_RESFRIAR_ID));
    buttonResfriar.setAction(buttonCallback);

    buttonDegelo.setXY(177, 133);
    buttonDegelo.setBitmaps(touchgfx::Bitmap(BITMAP_DEGELO_ID), touchgfx::Bitmap(BITMAP_DEGELO_ID));
    buttonDegelo.setAction(buttonCallback);

    buttonHigiene.setXY(179, 204);
    buttonHigiene.setBitmaps(touchgfx::Bitmap(BITMAP_HIGIENE_ID), touchgfx::Bitmap(BITMAP_HIGIENE_ID));
    buttonHigiene.setAction(buttonCallback);

    buttonSolicitacaoSenah.setXY(418, 15);
    buttonSolicitacaoSenah.setBitmaps(touchgfx::Bitmap(BITMAP_ENGREN_ID), touchgfx::Bitmap(BITMAP_ENGREN_ID));
    buttonSolicitacaoSenah.setAction(buttonCallback);

    solicitar_senha1.setXY(0, 0);
    solicitar_senha1.setVisible(false);
    solicitar_senha1.setCancelarCallback(solicitar_senha1CancelarCallback);
    solicitar_senha1.setDigitarCallback(solicitar_senha1DigitarCallback);

    numKeyboardContainerPwd1.setXY(0, 0);
    numKeyboardContainerPwd1.setVisible(false);
    numKeyboardContainerPwd1.setCredentialSuccessCallback(numKeyboardContainerPwd1CredentialSuccessCallback);
    numKeyboardContainerPwd1.setCredentialFailedCallback(numKeyboardContainerPwd1CredentialFailedCallback);
    numKeyboardContainerPwd1.setCancelTriggerCallback(numKeyboardContainerPwd1CancelTriggerCallback);

    imageStatusPorta.setXY(200, 0);
    imageStatusPorta.setVisible(false);
    imageStatusPorta.setBitmap(touchgfx::Bitmap(BITMAP_PORTA_ID));

    textAreaStatusPorta.setXY(98, 13);
    textAreaStatusPorta.setVisible(false);
    textAreaStatusPorta.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaStatusPorta.setLinespacing(0);
    Unicode::snprintf(textAreaStatusPortaBuffer, TEXTAREASTATUSPORTA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4104).getText());
    textAreaStatusPorta.setWildcard(textAreaStatusPortaBuffer);
    textAreaStatusPorta.resizeToCurrentText();
    textAreaStatusPorta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4103));

    add(__background);
    add(boxFundo);
    add(imageLogo);
    add(buttonCongelar);
    add(buttonConcervar);
    add(buttonReceitas);
    add(buttonResfriar);
    add(buttonDegelo);
    add(buttonHigiene);
    add(buttonSolicitacaoSenah);
    add(solicitar_senha1);
    add(numKeyboardContainerPwd1);
    add(imageStatusPorta);
    add(textAreaStatusPorta);
}

void Tela_InicialViewBase::setupScreen()
{
    solicitar_senha1.initialize();
    numKeyboardContainerPwd1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Clear();
    
    ReadWriteModbus485(&textAreaStatusPorta, textAreaStatusPortaBuffer, "553", 0, _INT_, REPEAT);

}

//Called when the screen transition ends
void Tela_InicialViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);

    //LaunchPasswordKeyboard
    //When screen transition ends call LaunchNumericalKeyboard on numKeyboardContainerPwd1
    //Call LaunchNumericalKeyboard
    numKeyboardContainerPwd1.LaunchNumericalKeyboard();
}

void Tela_InicialViewBase::solicitar_senha1CancelarCallbackHandler()
{
    //CancelarAcesso
    //When solicitar_senha1 cancelar execute C++ code
    //Execute C++ code
    ContainerVisibility(&solicitar_senha1, false);
    LogoutUser();
    SoundBuzzerOn(25);
}

void Tela_InicialViewBase::solicitar_senha1DigitarCallbackHandler()
{
    //DigitarSenha
    //When solicitar_senha1 digitar execute C++ code
    //Execute C++ code
    ContainerVisibility(&numKeyboardContainerPwd1, !UserIsLogged());
    SoundBuzzerOn(25);
}

void Tela_InicialViewBase::numKeyboardContainerPwd1CredentialSuccessCallbackHandler()
{
    //CredentialSuccess
    //When numKeyboardContainerPwd1 CredentialSuccess change screen to Configuracao
    //Go to Configuracao with no screen transition
    application().gotoConfiguracaoScreenNoTransition();
}

void Tela_InicialViewBase::numKeyboardContainerPwd1CredentialFailedCallbackHandler()
{
    //CredentialFailed
    //When numKeyboardContainerPwd1 CredentialFailed call ViewErrorMsg on numKeyboardContainerPwd1
    //Call ViewErrorMsg
    numKeyboardContainerPwd1.ViewErrorMsg();
}

void Tela_InicialViewBase::numKeyboardContainerPwd1CancelTriggerCallbackHandler()
{
    //HideNumKeyboardPwd
    //When numKeyboardContainerPwd1 CancelTrigger execute C++ code
    //Execute C++ code
    ContainerVisibility(&numKeyboardContainerPwd1, false);
    SoundBuzzerOn(25);
}

void Tela_InicialViewBase::handleTickEvent()
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
}

void Tela_InicialViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    LogoutUser();
    
    Clear();
    ClearOthers();
    ContainerClear(&numKeyboardContainerPwd1);
}

void Tela_InicialViewBase::launchPasswordKeyboard()
{

}

void Tela_InicialViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonCongelar)
    {
        //Congelar
        //When buttonCongelar clicked change screen to Congelar
        //Go to Congelar with no screen transition
        application().gotoCongelarScreenNoTransition();
    }
    else if (&src == &buttonConcervar)
    {
        //Conservar
        //When buttonConcervar clicked change screen to Conservacao
        //Go to Conservacao with no screen transition
        application().gotoConservacaoScreenNoTransition();
    }
    else if (&src == &buttonReceitas)
    {
        //Receitas
        //When buttonReceitas clicked change screen to Receitas_1
        //Go to Receitas_1 with no screen transition
        application().gotoReceitas_1ScreenNoTransition();
    }
    else if (&src == &buttonResfriar)
    {
        //Resfriar
        //When buttonResfriar clicked change screen to Resfriar
        //Go to Resfriar with no screen transition
        application().gotoResfriarScreenNoTransition();
    }
    else if (&src == &buttonDegelo)
    {
        //Degelo
        //When buttonDegelo clicked change screen to Degelo_Confirmar
        //Go to Degelo_Confirmar with no screen transition
        application().gotoDegelo_ConfirmarScreenNoTransition();
    }
    else if (&src == &buttonHigiene)
    {
        //Higienizacao
        //When buttonHigiene clicked change screen to HIGIENE_CONFIRMAR
        //Go to HIGIENE_CONFIRMAR with no screen transition
        application().gotoHIGIENE_CONFIRMARScreenNoTransition();
    }
    else if (&src == &buttonSolicitacaoSenah)
    {
        //SolicitacaoSenha
        //When buttonSolicitacaoSenah clicked execute C++ code
        //Execute C++ code
        ContainerVisibility(&numKeyboardContainerPwd1, !UserIsLogged());
        SoundBuzzerOn(25);
    }
}
