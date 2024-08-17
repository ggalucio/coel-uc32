/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/resfriar_select_tempo_screen/Resfriar_Select_TempoViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Resfriar_Select_TempoViewBase::Resfriar_Select_TempoViewBase() :
    buttonCallback(this, &Resfriar_Select_TempoViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    boxFundoAzul.setPosition(0, 0, 480, 53);
    boxFundoAzul.setColor(touchgfx::Color::getColorFromRGB(0, 175, 239));

    boxFundoMinutos.setPosition(123, 128, 166, 54);
    boxFundoMinutos.setColor(touchgfx::Color::getColorFromRGB(0, 175, 239));

    textAreaTitle.setXY(5, 8);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaTitle.setLinespacing(0);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3858));

    textAreaUnidade.setXY(302, 137);
    textAreaUnidade.setColor(touchgfx::Color::getColorFromRGB(0, 175, 239));
    textAreaUnidade.setLinespacing(0);
    textAreaUnidade.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3859));

    textAreaTimerSpMinutosResfriar.setPosition(123, 128, 166, 54);
    textAreaTimerSpMinutosResfriar.setColor(touchgfx::Color::getColorFromRGB(240, 240, 240));
    textAreaTimerSpMinutosResfriar.setLinespacing(0);
    Unicode::snprintf(textAreaTimerSpMinutosResfriarBuffer, TEXTAREATIMERSPMINUTOSRESFRIAR_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3861).getText());
    textAreaTimerSpMinutosResfriar.setWildcard(textAreaTimerSpMinutosResfriarBuffer);
    textAreaTimerSpMinutosResfriar.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3860));

    buttonWithLabelIncrementar.setXY(173, 70);
    buttonWithLabelIncrementar.setBitmaps(touchgfx::Bitmap(BITMAP_VAZIO_ID), touchgfx::Bitmap(BITMAP_VAZIO_ID));
    buttonWithLabelIncrementar.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3862));
    buttonWithLabelIncrementar.setLabelColor(touchgfx::Color::getColorFromRGB(42, 106, 162));
    buttonWithLabelIncrementar.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabelIncrementar.setAction(buttonCallback);

    buttonWithLabelDecrementar.setXY(173, 188);
    buttonWithLabelDecrementar.setBitmaps(touchgfx::Bitmap(BITMAP_VAZIO_ID), touchgfx::Bitmap(BITMAP_VAZIO_ID));
    buttonWithLabelDecrementar.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3863));
    buttonWithLabelDecrementar.setLabelColor(touchgfx::Color::getColorFromRGB(42, 106, 162));
    buttonWithLabelDecrementar.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabelDecrementar.setAction(buttonCallback);

    toggleButtonFlagResfriarHardSoft.setXY(406, 136);
    toggleButtonFlagResfriarHardSoft.setBitmaps(touchgfx::Bitmap(BITMAP_SOFT_ID), touchgfx::Bitmap(BITMAP_HARD_ID));
    toggleButtonFlagResfriarHardSoft.setAction(buttonCallback);

    textAreaTempoZero.setXY(15, 65);
    textAreaTempoZero.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaTempoZero.setLinespacing(0);
    textAreaTempoZero.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4023));

    buttonFlagCongelarTempo.setXY(406, 208);
    buttonFlagCongelarTempo.setBitmaps(touchgfx::Bitmap(BITMAP_AVANCE_ID), touchgfx::Bitmap(BITMAP_AVANCEON_ID));
    buttonFlagCongelarTempo.setAction(buttonCallback);

    buttonResfriar.setXY(406, 64);
    buttonResfriar.setBitmaps(touchgfx::Bitmap(BITMAP_VOLTAR_ID), touchgfx::Bitmap(BITMAP_VOLTAR_ID));
    buttonResfriar.setAction(buttonCallback);

    imageStatusPorta.setXY(200, 0);
    imageStatusPorta.setVisible(false);
    imageStatusPorta.setBitmap(touchgfx::Bitmap(BITMAP_PORTA_ID));

    textAreaStatusPorta.setXY(98, 13);
    textAreaStatusPorta.setVisible(false);
    textAreaStatusPorta.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaStatusPorta.setLinespacing(0);
    Unicode::snprintf(textAreaStatusPortaBuffer, TEXTAREASTATUSPORTA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID4126).getText());
    textAreaStatusPorta.setWildcard(textAreaStatusPortaBuffer);
    textAreaStatusPorta.resizeToCurrentText();
    textAreaStatusPorta.setTypedText(touchgfx::TypedText(T_SINGLEUSEID4125));

    add(__background);
    add(boxFundo);
    add(boxFundoAzul);
    add(boxFundoMinutos);
    add(textAreaTitle);
    add(textAreaUnidade);
    add(textAreaTimerSpMinutosResfriar);
    add(buttonWithLabelIncrementar);
    add(buttonWithLabelDecrementar);
    add(toggleButtonFlagResfriarHardSoft);
    add(textAreaTempoZero);
    add(buttonFlagCongelarTempo);
    add(buttonResfriar);
    add(imageStatusPorta);
    add(textAreaStatusPorta);
}

void Resfriar_Select_TempoViewBase::setupScreen()
{

    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    AddbackgroundContainer(this);
    W_HDW5000 = 12;
    
    // Clear();
    
    ReadWriteModbus485(&textAreaStatusPorta, textAreaStatusPortaBuffer, "553", 0, _INT_, REPEAT);
    
    Update(&textAreaTimerSpMinutosResfriar, textAreaTimerSpMinutosResfriarBuffer, Timer_SP_MINUTOS_Resfriar, _INT_, 0);
    Update(&toggleButtonFlagResfriarHardSoft, flag_Resfriar_HARD_SOFT);
    
    VisibilityTextArea(&textAreaTempoZero, false);
    countCycleBlink = 0;

}

//Called when the screen transition ends
void Resfriar_Select_TempoViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Resfriar_Select_TempoViewBase::handleTickEvent()
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
    
    	if (flag_alarm_receita_vazia)
    		VisibilityTextArea(&textAreaTempoZero, !textAreaTempoZero.isVisible());
    }
    
    countCycleBlink += 16;
}

void Resfriar_Select_TempoViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
}

void Resfriar_Select_TempoViewBase::Resfriar_TEMPO()
{
    //ResfriarTEMPO
    //When Resfriar_TEMPO is called change screen to Resfriar_TEMPO
    //Go to Resfriar_TEMPO with no screen transition
    application().gotoResfriar_TEMPOScreenNoTransition();
}

void Resfriar_Select_TempoViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabelIncrementar)
    {
        //Incrementar
        //When buttonWithLabelIncrementar clicked execute C++ code
        //Execute C++ code
        Increase(&textAreaTimerSpMinutosResfriar, textAreaTimerSpMinutosResfriarBuffer, 1, 0, 9999, _INT_, 0);
        Timer_SP_MINUTOS_Resfriar = GetNumberTextArea(textAreaTimerSpMinutosResfriarBuffer);
        SoundBuzzerOn(25);
    }
    else if (&src == &buttonWithLabelDecrementar)
    {
        //Decrementar
        //When buttonWithLabelDecrementar clicked execute C++ code
        //Execute C++ code
        Decrease(&textAreaTimerSpMinutosResfriar, textAreaTimerSpMinutosResfriarBuffer, 1, 0, 9999, _INT_, 0);
        Timer_SP_MINUTOS_Resfriar = GetNumberTextArea(textAreaTimerSpMinutosResfriarBuffer);
        SoundBuzzerOn(25);
    }
    else if (&src == &toggleButtonFlagResfriarHardSoft)
    {
        //SoftHard
        //When toggleButtonFlagResfriarHardSoft clicked execute C++ code
        //Execute C++ code
        flag_Resfriar_HARD_SOFT = toggleButtonFlagResfriarHardSoft.getState();
        SoundBuzzerOn(25);
    }
    else if (&src == &buttonFlagCongelarTempo)
    {
        //Avancar
        //When buttonFlagCongelarTempo clicked execute C++ code
        //Execute C++ code
        if (Timer_SP_MINUTOS_Resfriar == 0)
        {
        	flag_alarm_receita_vazia = 1;						// flag alarm de timer em valor 0
        
        	isZeroValue = true;
        	SoundBuzzerOn(25);
        }
        else
        {
        	if (flag_Resfriar_HARD_SOFT == 0)		// if SOFT
        	{
        		UpdateModbus485("10242", SP_SONDA_RESF_CAMARA, _INT_);
        		WriteModbus485("10242", 1);
        		Wait(50);
        		
        		SP_Resf_Hard_Interno_display = SP_Resfriar_Tempo_SOFT;
        
        		UpdateModbus485("10282", Diferencial_Resfriar_Tempo, _INT_);	// Diferencial rd
        		WriteModbus485("10282", 1);
        		Wait(50);
        	}
        	else	// if HARD
        	{
        		Hard_Resf_fase_numero = 1;						// Resfriamento por etapas - Etapa = 1
        
        		Dif_Resf_Hard_F1 = Diferencial_Resfriar_Tempo;
        		Dif_Resf_Hard_F2 = Dif_Resf_Hard_F1;
        
        		UpdateModbus485("242", SP_Resf_Interno_F1, _INT_);
        		WriteModbus485("242", 1);
        		Wait(50);
        
        		UpdateModbus485("10282", Dif_Resf_Hard_F1, _INT_);		// Diferencial de controle para modo Delicado Sonda
        		WriteModbus485("10282", 1);
        		Wait(50);
        
        		SP_Resf_Hard_Interno_display = SP_Resf_Interno_F1;
        						
        		Preset_Resf_Tempo_F1 = Timer_SP_MINUTOS_Resfriar * 6;		// transforma Sp minutos em seg*10
        		Preset_Resf_Tempo_F1 = Preset_Resf_Tempo_F1 * Porc_Resf_preset_tempo_F1F2;
        		Preset_Resf_Tempo_F1 = Preset_Resf_Tempo_F1 / 10;
        
        		Preset_Resf_Tempo_F2 = Timer_SP_MINUTOS_Resfriar * 6 - Preset_Resf_Tempo_F1;
        
        		SP_Resf_Interno_F2 = SP_SONDA_RESF_CAMARA;
        		xBeep_once = false;
        	}
        
        	Timer_Congelar_DECORRIDO_SP = Timer_SP_MINUTOS_Resfriar * 6;	// TRansforma SP minutos em seg10
        	UpdateModbus485("645", 1, _INT_);						//  Controlador em modo COntrole
        	WriteModbus485("645", 1);
        	Wait(50);
        
        	Timer_Congelar_DECORRIDO_ON = 1;						// START Timer TEmpo_COngelar_DECORRIDO_ON
        	flag_Processo_ANDAMENTO = 1;						// Flag PRocesso_ANDAMENTO = TRUE
        	
        	Resfriar_TEMPO();								// tela de Resfriar TEMPO
        }
    }
    else if (&src == &buttonResfriar)
    {
        //Voltar
        //When buttonResfriar clicked change screen to Resfriar
        //Go to Resfriar with no screen transition
        application().gotoResfriarScreenNoTransition();
    }
}
