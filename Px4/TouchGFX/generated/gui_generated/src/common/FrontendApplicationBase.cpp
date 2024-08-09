/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <new>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>
#include <gui/inicializacao_screen/InicializacaoView.hpp>
#include <gui/inicializacao_screen/InicializacaoPresenter.hpp>
#include <gui/tela_inicial_screen/Tela_InicialView.hpp>
#include <gui/tela_inicial_screen/Tela_InicialPresenter.hpp>
#include <gui/congelar_screen/CongelarView.hpp>
#include <gui/congelar_screen/CongelarPresenter.hpp>
#include <gui/congelar_sonda_screen/Congelar_SONDAView.hpp>
#include <gui/congelar_sonda_screen/Congelar_SONDAPresenter.hpp>
#include <gui/congelar_tempo_screen/Congelar_TEMPOView.hpp>
#include <gui/congelar_tempo_screen/Congelar_TEMPOPresenter.hpp>
#include <gui/congelar_select_tempo_screen/Congelar_select_TEMPOView.hpp>
#include <gui/congelar_select_tempo_screen/Congelar_select_TEMPOPresenter.hpp>
#include <gui/configuracao_screen/ConfiguracaoView.hpp>
#include <gui/configuracao_screen/ConfiguracaoPresenter.hpp>
#include <gui/conservacao_screen/ConservacaoView.hpp>
#include <gui/conservacao_screen/ConservacaoPresenter.hpp>
#include <gui/conservar_congelar_screen/Conservar_CongelarView.hpp>
#include <gui/conservar_congelar_screen/Conservar_CongelarPresenter.hpp>
#include <gui/conservar_resfriar_screen/Conservar_ResfriarView.hpp>
#include <gui/conservar_resfriar_screen/Conservar_ResfriarPresenter.hpp>
#include <gui/resfriar_screen/ResfriarView.hpp>
#include <gui/resfriar_screen/ResfriarPresenter.hpp>
#include <gui/resfriar_sonda_screen/Resfriar_SONDAView.hpp>
#include <gui/resfriar_sonda_screen/Resfriar_SONDAPresenter.hpp>
#include <gui/resfriar_select_tempo_screen/Resfriar_Select_TempoView.hpp>
#include <gui/resfriar_select_tempo_screen/Resfriar_Select_TempoPresenter.hpp>
#include <gui/resfriar_tempo_screen/Resfriar_TEMPOView.hpp>
#include <gui/resfriar_tempo_screen/Resfriar_TEMPOPresenter.hpp>
#include <gui/degelo_screen/DegeloView.hpp>
#include <gui/degelo_screen/DegeloPresenter.hpp>
#include <gui/degelo_confirmar_screen/Degelo_ConfirmarView.hpp>
#include <gui/degelo_confirmar_screen/Degelo_ConfirmarPresenter.hpp>
#include <gui/configuracao_2_screen/Configuracao_2View.hpp>
#include <gui/configuracao_2_screen/Configuracao_2Presenter.hpp>
#include <gui/configuracao_3_screen/Configuracao_3View.hpp>
#include <gui/configuracao_3_screen/Configuracao_3Presenter.hpp>
#include <gui/receitas_1_screen/Receitas_1View.hpp>
#include <gui/receitas_1_screen/Receitas_1Presenter.hpp>
#include <gui/receitas_2_screen/Receitas_2View.hpp>
#include <gui/receitas_2_screen/Receitas_2Presenter.hpp>
#include <gui/receitas_3_screen/Receitas_3View.hpp>
#include <gui/receitas_3_screen/Receitas_3Presenter.hpp>
#include <gui/receitas_x_edit_screen/Receitas_X_EDITView.hpp>
#include <gui/receitas_x_edit_screen/Receitas_X_EDITPresenter.hpp>
#include <gui/receita_confirm_screen/Receita_confirmView.hpp>
#include <gui/receita_confirm_screen/Receita_confirmPresenter.hpp>
#include <gui/configuracao_4_screen/Configuracao_4View.hpp>
#include <gui/configuracao_4_screen/Configuracao_4Presenter.hpp>
#include <gui/refine_senha_secreto_screen/refine_senha_secretoView.hpp>
#include <gui/refine_senha_secreto_screen/refine_senha_secretoPresenter.hpp>
#include <gui/alarme_externo_screen/Alarme_externoView.hpp>
#include <gui/alarme_externo_screen/Alarme_externoPresenter.hpp>
#include <gui/configuracao_5_screen/Configuracao_5View.hpp>
#include <gui/configuracao_5_screen/Configuracao_5Presenter.hpp>
#include <gui/receita_temperatura_screen/Receita_TemperaturaView.hpp>
#include <gui/receita_temperatura_screen/Receita_TemperaturaPresenter.hpp>
#include <gui/configuracao_6_screen/Configuracao_6View.hpp>
#include <gui/configuracao_6_screen/Configuracao_6Presenter.hpp>
#include <gui/reset_fabrica_screen/RESET_FABRICAView.hpp>
#include <gui/reset_fabrica_screen/RESET_FABRICAPresenter.hpp>
#include <gui/higiene_confirmar_screen/HIGIENE_CONFIRMARView.hpp>
#include <gui/higiene_confirmar_screen/HIGIENE_CONFIRMARPresenter.hpp>
#include <gui/higiene_screen/HIGIENEView.hpp>
#include <gui/higiene_screen/HIGIENEPresenter.hpp>
#include <gui/configuracao_7_screen/Configuracao_7View.hpp>
#include <gui/configuracao_7_screen/Configuracao_7Presenter.hpp>
#include <gui/tela_preta_screen/TELA_PRETAView.hpp>
#include <gui/tela_preta_screen/TELA_PRETAPresenter.hpp>

using namespace touchgfx;

FrontendApplicationBase::FrontendApplicationBase(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_LANDSCAPE);
    touchgfx::Texts::setLanguage(GB);
    reinterpret_cast<touchgfx::LCD16bpp&>(touchgfx::HAL::lcd()).enableTextureMapperAll();
}

/*
 * Screen Transition Declarations
 */

// Inicializacao

void FrontendApplicationBase::gotoInicializacaoScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoInicializacaoScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoInicializacaoScreenNoTransitionImpl()
{
    touchgfx::makeTransition<InicializacaoView, InicializacaoPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Tela_Inicial

void FrontendApplicationBase::gotoTela_InicialScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoTela_InicialScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoTela_InicialScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Tela_InicialView, Tela_InicialPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Congelar

void FrontendApplicationBase::gotoCongelarScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoCongelarScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoCongelarScreenNoTransitionImpl()
{
    touchgfx::makeTransition<CongelarView, CongelarPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Congelar_SONDA

void FrontendApplicationBase::gotoCongelar_SONDAScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoCongelar_SONDAScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoCongelar_SONDAScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Congelar_SONDAView, Congelar_SONDAPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Congelar_TEMPO

void FrontendApplicationBase::gotoCongelar_TEMPOScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoCongelar_TEMPOScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoCongelar_TEMPOScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Congelar_TEMPOView, Congelar_TEMPOPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Congelar_select_TEMPO

void FrontendApplicationBase::gotoCongelar_select_TEMPOScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoCongelar_select_TEMPOScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoCongelar_select_TEMPOScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Congelar_select_TEMPOView, Congelar_select_TEMPOPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Configuracao

void FrontendApplicationBase::gotoConfiguracaoScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoConfiguracaoScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoConfiguracaoScreenNoTransitionImpl()
{
    touchgfx::makeTransition<ConfiguracaoView, ConfiguracaoPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Conservacao

void FrontendApplicationBase::gotoConservacaoScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoConservacaoScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoConservacaoScreenNoTransitionImpl()
{
    touchgfx::makeTransition<ConservacaoView, ConservacaoPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Conservar_Congelar

void FrontendApplicationBase::gotoConservar_CongelarScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoConservar_CongelarScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoConservar_CongelarScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Conservar_CongelarView, Conservar_CongelarPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Conservar_Resfriar

void FrontendApplicationBase::gotoConservar_ResfriarScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoConservar_ResfriarScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoConservar_ResfriarScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Conservar_ResfriarView, Conservar_ResfriarPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Resfriar

void FrontendApplicationBase::gotoResfriarScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoResfriarScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoResfriarScreenNoTransitionImpl()
{
    touchgfx::makeTransition<ResfriarView, ResfriarPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Resfriar_SONDA

void FrontendApplicationBase::gotoResfriar_SONDAScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoResfriar_SONDAScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoResfriar_SONDAScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Resfriar_SONDAView, Resfriar_SONDAPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Resfriar_Select_Tempo

void FrontendApplicationBase::gotoResfriar_Select_TempoScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoResfriar_Select_TempoScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoResfriar_Select_TempoScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Resfriar_Select_TempoView, Resfriar_Select_TempoPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Resfriar_TEMPO

void FrontendApplicationBase::gotoResfriar_TEMPOScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoResfriar_TEMPOScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoResfriar_TEMPOScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Resfriar_TEMPOView, Resfriar_TEMPOPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Degelo

void FrontendApplicationBase::gotoDegeloScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoDegeloScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoDegeloScreenNoTransitionImpl()
{
    touchgfx::makeTransition<DegeloView, DegeloPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Degelo_Confirmar

void FrontendApplicationBase::gotoDegelo_ConfirmarScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoDegelo_ConfirmarScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoDegelo_ConfirmarScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Degelo_ConfirmarView, Degelo_ConfirmarPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Configuracao_2

void FrontendApplicationBase::gotoConfiguracao_2ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoConfiguracao_2ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoConfiguracao_2ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Configuracao_2View, Configuracao_2Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Configuracao_3

void FrontendApplicationBase::gotoConfiguracao_3ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoConfiguracao_3ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoConfiguracao_3ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Configuracao_3View, Configuracao_3Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Receitas_1

void FrontendApplicationBase::gotoReceitas_1ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoReceitas_1ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoReceitas_1ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Receitas_1View, Receitas_1Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Receitas_2

void FrontendApplicationBase::gotoReceitas_2ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoReceitas_2ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoReceitas_2ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Receitas_2View, Receitas_2Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Receitas_3

void FrontendApplicationBase::gotoReceitas_3ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoReceitas_3ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoReceitas_3ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Receitas_3View, Receitas_3Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Receitas_X_EDIT

void FrontendApplicationBase::gotoReceitas_X_EDITScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoReceitas_X_EDITScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoReceitas_X_EDITScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Receitas_X_EDITView, Receitas_X_EDITPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Receita_confirm

void FrontendApplicationBase::gotoReceita_confirmScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoReceita_confirmScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoReceita_confirmScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Receita_confirmView, Receita_confirmPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Configuracao_4

void FrontendApplicationBase::gotoConfiguracao_4ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoConfiguracao_4ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoConfiguracao_4ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Configuracao_4View, Configuracao_4Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Configuracao_5

void FrontendApplicationBase::gotoConfiguracao_5ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoConfiguracao_5ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoConfiguracao_5ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Configuracao_5View, Configuracao_5Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Configuracao_6

void FrontendApplicationBase::gotoConfiguracao_6ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoConfiguracao_6ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoConfiguracao_6ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Configuracao_6View, Configuracao_6Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// HIGIENE_CONFIRMAR

void FrontendApplicationBase::gotoHIGIENE_CONFIRMARScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoHIGIENE_CONFIRMARScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoHIGIENE_CONFIRMARScreenNoTransitionImpl()
{
    touchgfx::makeTransition<HIGIENE_CONFIRMARView, HIGIENE_CONFIRMARPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// HIGIENE

void FrontendApplicationBase::gotoHIGIENEScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoHIGIENEScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoHIGIENEScreenNoTransitionImpl()
{
    touchgfx::makeTransition<HIGIENEView, HIGIENEPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Configuracao_7

void FrontendApplicationBase::gotoConfiguracao_7ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoConfiguracao_7ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoConfiguracao_7ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Configuracao_7View, Configuracao_7Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
