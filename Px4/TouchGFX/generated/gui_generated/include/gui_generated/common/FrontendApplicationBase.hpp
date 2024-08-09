/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    // Inicializacao
    void gotoInicializacaoScreenNoTransition();

    // Tela_Inicial
    void gotoTela_InicialScreenNoTransition();

    // Congelar
    void gotoCongelarScreenNoTransition();

    // Congelar_SONDA
    void gotoCongelar_SONDAScreenNoTransition();

    // Congelar_TEMPO
    void gotoCongelar_TEMPOScreenNoTransition();

    // Congelar_select_TEMPO
    void gotoCongelar_select_TEMPOScreenNoTransition();

    // Configuracao
    void gotoConfiguracaoScreenNoTransition();

    // Conservacao
    void gotoConservacaoScreenNoTransition();

    // Conservar_Congelar
    void gotoConservar_CongelarScreenNoTransition();

    // Conservar_Resfriar
    void gotoConservar_ResfriarScreenNoTransition();

    // Resfriar
    void gotoResfriarScreenNoTransition();

    // Resfriar_SONDA
    void gotoResfriar_SONDAScreenNoTransition();

    // Resfriar_Select_Tempo
    void gotoResfriar_Select_TempoScreenNoTransition();

    // Resfriar_TEMPO
    void gotoResfriar_TEMPOScreenNoTransition();

    // Degelo
    void gotoDegeloScreenNoTransition();

    // Degelo_Confirmar
    void gotoDegelo_ConfirmarScreenNoTransition();

    // Configuracao_2
    void gotoConfiguracao_2ScreenNoTransition();

    // Configuracao_3
    void gotoConfiguracao_3ScreenNoTransition();

    // Receitas_1
    void gotoReceitas_1ScreenNoTransition();

    // Receitas_2
    void gotoReceitas_2ScreenNoTransition();

    // Receitas_3
    void gotoReceitas_3ScreenNoTransition();

    // Receitas_X_EDIT
    void gotoReceitas_X_EDITScreenNoTransition();

    // Receita_confirm
    void gotoReceita_confirmScreenNoTransition();

    // Configuracao_4
    void gotoConfiguracao_4ScreenNoTransition();

    // Configuracao_5
    void gotoConfiguracao_5ScreenNoTransition();

    // Configuracao_6
    void gotoConfiguracao_6ScreenNoTransition();

    // HIGIENE_CONFIRMAR
    void gotoHIGIENE_CONFIRMARScreenNoTransition();

    // HIGIENE
    void gotoHIGIENEScreenNoTransition();

    // Configuracao_7
    void gotoConfiguracao_7ScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Inicializacao
    void gotoInicializacaoScreenNoTransitionImpl();

    // Tela_Inicial
    void gotoTela_InicialScreenNoTransitionImpl();

    // Congelar
    void gotoCongelarScreenNoTransitionImpl();

    // Congelar_SONDA
    void gotoCongelar_SONDAScreenNoTransitionImpl();

    // Congelar_TEMPO
    void gotoCongelar_TEMPOScreenNoTransitionImpl();

    // Congelar_select_TEMPO
    void gotoCongelar_select_TEMPOScreenNoTransitionImpl();

    // Configuracao
    void gotoConfiguracaoScreenNoTransitionImpl();

    // Conservacao
    void gotoConservacaoScreenNoTransitionImpl();

    // Conservar_Congelar
    void gotoConservar_CongelarScreenNoTransitionImpl();

    // Conservar_Resfriar
    void gotoConservar_ResfriarScreenNoTransitionImpl();

    // Resfriar
    void gotoResfriarScreenNoTransitionImpl();

    // Resfriar_SONDA
    void gotoResfriar_SONDAScreenNoTransitionImpl();

    // Resfriar_Select_Tempo
    void gotoResfriar_Select_TempoScreenNoTransitionImpl();

    // Resfriar_TEMPO
    void gotoResfriar_TEMPOScreenNoTransitionImpl();

    // Degelo
    void gotoDegeloScreenNoTransitionImpl();

    // Degelo_Confirmar
    void gotoDegelo_ConfirmarScreenNoTransitionImpl();

    // Configuracao_2
    void gotoConfiguracao_2ScreenNoTransitionImpl();

    // Configuracao_3
    void gotoConfiguracao_3ScreenNoTransitionImpl();

    // Receitas_1
    void gotoReceitas_1ScreenNoTransitionImpl();

    // Receitas_2
    void gotoReceitas_2ScreenNoTransitionImpl();

    // Receitas_3
    void gotoReceitas_3ScreenNoTransitionImpl();

    // Receitas_X_EDIT
    void gotoReceitas_X_EDITScreenNoTransitionImpl();

    // Receita_confirm
    void gotoReceita_confirmScreenNoTransitionImpl();

    // Configuracao_4
    void gotoConfiguracao_4ScreenNoTransitionImpl();

    // Configuracao_5
    void gotoConfiguracao_5ScreenNoTransitionImpl();

    // Configuracao_6
    void gotoConfiguracao_6ScreenNoTransitionImpl();

    // HIGIENE_CONFIRMAR
    void gotoHIGIENE_CONFIRMARScreenNoTransitionImpl();

    // HIGIENE
    void gotoHIGIENEScreenNoTransitionImpl();

    // Configuracao_7
    void gotoConfiguracao_7ScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
