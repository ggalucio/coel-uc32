/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/receita_confirm_screen/Receita_confirmViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Receita_confirmViewBase::Receita_confirmViewBase() :
    buttonCallback(this, &Receita_confirmViewBase::buttonCallbackHandler),
    receita_Info_resumo1FecharCallback(this, &Receita_confirmViewBase::receita_Info_resumo1FecharCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    boxFundo.setPosition(0, 0, 480, 272);
    boxFundo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));

    textAreaTitle.setXY(133, 0);
    textAreaTitle.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaTitle.setLinespacing(0);
    textAreaTitle.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3924));

    textAreaNumeroReceita.setXY(133, 76);
    textAreaNumeroReceita.setColor(touchgfx::Color::getColorFromRGB(1, 1, 255));
    textAreaNumeroReceita.setLinespacing(0);
    Unicode::snprintf(textAreaNumeroReceitaBuffer, TEXTAREANUMERORECEITA_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID3926).getText());
    textAreaNumeroReceita.setWildcard(textAreaNumeroReceitaBuffer);
    textAreaNumeroReceita.resizeToCurrentText();
    textAreaNumeroReceita.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3925));

    buttonReceitaInfoResumo.setXY(310, 76);
    buttonReceitaInfoResumo.setBitmaps(touchgfx::Bitmap(BITMAP_INFO_ID), touchgfx::Bitmap(BITMAP_INFO_ID));
    buttonReceitaInfoResumo.setAction(buttonCallback);

    buttonWithLabelFlagStartReceita.setXY(257, 191);
    buttonWithLabelFlagStartReceita.setBitmaps(touchgfx::Bitmap(BITMAP_R3_ID), touchgfx::Bitmap(BITMAP_R4_ID));
    buttonWithLabelFlagStartReceita.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3927));
    buttonWithLabelFlagStartReceita.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonWithLabelFlagStartReceita.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonWithLabelFlagStartReceita.setAction(buttonCallback);

    buttonWithLabelRecitas1.setXY(77, 191);
    buttonWithLabelRecitas1.setBitmaps(touchgfx::Bitmap(BITMAP_R1_ID), touchgfx::Bitmap(BITMAP_R2_ID));
    buttonWithLabelRecitas1.setLabelText(touchgfx::TypedText(T_SINGLEUSEID3928));
    buttonWithLabelRecitas1.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonWithLabelRecitas1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonWithLabelRecitas1.setAction(buttonCallback);

    textAreaFlagAlarmReceitaVazia.setXY(38, 129);
    textAreaFlagAlarmReceitaVazia.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    textAreaFlagAlarmReceitaVazia.setLinespacing(0);
    textAreaFlagAlarmReceitaVazia.setTypedText(touchgfx::TypedText(T_SINGLEUSEID3929));

    receita_Info_resumo1.setXY(0, 0);
    receita_Info_resumo1.setVisible(false);
    receita_Info_resumo1.setFecharCallback(receita_Info_resumo1FecharCallback);

    add(__background);
    add(boxFundo);
    add(textAreaTitle);
    add(textAreaNumeroReceita);
    add(buttonReceitaInfoResumo);
    add(buttonWithLabelFlagStartReceita);
    add(buttonWithLabelRecitas1);
    add(textAreaFlagAlarmReceitaVazia);
    add(receita_Info_resumo1);
}

void Receita_confirmViewBase::setupScreen()
{
    receita_Info_resumo1.initialize();
    //ScreenTransitionBegins
    //When screen transition begins execute C++ code
    //Execute C++ code
    Update(&textAreaNumeroReceita, textAreaNumeroReceitaBuffer,  ReadJobData(255, _INT_), _INT_, 0);
    VisibilityTextArea(&textAreaFlagAlarmReceitaVazia, false);
    countCycleBlink = 0;
    isZeroValue = false;

}

//Called when the screen transition ends
void Receita_confirmViewBase::afterTransition()
{
    //ScreenTransitionEnds
    //When screen transition ends execute C++ code
    //Execute C++ code
    SoundBuzzerOn(25);
}

void Receita_confirmViewBase::receita_Info_resumo1FecharCallbackHandler()
{
    //Fechar
    //When receita_Info_resumo1 fechar execute C++ code
    //Execute C++ code
    ContainerVisibility(&receita_Info_resumo1, false);
    SoundBuzzerOn(25);
}

void Receita_confirmViewBase::handleTickEvent()
{
    //HandleTickEvent
    //When handleTickEvent is called execute C++ code
    //Execute C++ code
    if (countCycleBlink > 1000)
    {
    	countCycleBlink = 0;
    	if (isZeroValue)
    		VisibilityTextArea(&textAreaFlagAlarmReceitaVazia, !textAreaFlagAlarmReceitaVazia.isVisible());
    }
    
    countCycleBlink += 16;
}

void Receita_confirmViewBase::tearDownScreen()
{
    //TearDownScreen
    //When tearDownScreen is called execute C++ code
    //Execute C++ code
    Clear();
    ClearOthers();
}

void Receita_confirmViewBase::Congelar_TEMPO()
{
    //CongelarTEMPO
    //When Congelar_TEMPO is called change screen to Congelar_TEMPO
    //Go to Congelar_TEMPO with no screen transition
    application().gotoCongelar_TEMPOScreenNoTransition();
}

void Receita_confirmViewBase::Resfriar_TEMPO()
{
    //ResfriarTEMPO
    //When Resfriar_TEMPO is called change screen to Resfriar_TEMPO
    //Go to Resfriar_TEMPO with no screen transition
    application().gotoResfriar_TEMPOScreenNoTransition();
}

void Receita_confirmViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonReceitaInfoResumo)
    {
        //ReceitaInfoResumo
        //When buttonReceitaInfoResumo clicked execute C++ code
        //Execute C++ code
        ContainerVisibility(&receita_Info_resumo1, true);
        SoundBuzzerOn(25);
    }
    else if (&src == &buttonWithLabelFlagStartReceita)
    {
        //Sim
        //When buttonWithLabelFlagStartReceita clicked execute C++ code
        //Execute C++ code
        double tempoReceita = ReadJobData(1, _INT_);
        double valueCongResf = ReadJobData(4, _INT_);
        
        if (tempoReceita == 0.0)
        {
        	isZeroValue = true;
        	SoundBuzzerOn(25);
        }
        else
        {
        	if (valueCongResf == 0)
        		Congelar_TEMPO();
        	else
        		Resfriar_TEMPO();
        }
    }
    else if (&src == &buttonWithLabelRecitas1)
    {
        //Nao
        //When buttonWithLabelRecitas1 clicked change screen to Receitas_1
        //Go to Receitas_1 with no screen transition
        application().gotoReceitas_1ScreenNoTransition();
    }
}
