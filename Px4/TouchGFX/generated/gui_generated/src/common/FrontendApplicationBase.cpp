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
#include <gui/receitas_1_edit_screen/Receitas_1_EDITView.hpp>
#include <gui/receitas_1_edit_screen/Receitas_1_EDITPresenter.hpp>
#include <gui/configuracao_4_screen/Configuracao_4View.hpp>
#include <gui/configuracao_4_screen/Configuracao_4Presenter.hpp>
#include <gui/configuracao_5_screen/Configuracao_5View.hpp>
#include <gui/configuracao_5_screen/Configuracao_5Presenter.hpp>
#include <gui/configuracao_6_screen/Configuracao_6View.hpp>
#include <gui/configuracao_6_screen/Configuracao_6Presenter.hpp>
#include <gui/configuracao_7_screen/Configuracao_7View.hpp>
#include <gui/configuracao_7_screen/Configuracao_7Presenter.hpp>
#include <gui/reset_fabrica_screen/RESET_FABRICAView.hpp>
#include <gui/reset_fabrica_screen/RESET_FABRICAPresenter.hpp>
#include <gui/receita_confirm_screen/Receita_confirmView.hpp>
#include <gui/receita_confirm_screen/Receita_confirmPresenter.hpp>
#include <gui/refine_senha_secreto_screen/refine_senha_secretoView.hpp>
#include <gui/refine_senha_secreto_screen/refine_senha_secretoPresenter.hpp>
#include <gui/alarme_externo_screen/Alarme_externoView.hpp>
#include <gui/alarme_externo_screen/Alarme_externoPresenter.hpp>

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
