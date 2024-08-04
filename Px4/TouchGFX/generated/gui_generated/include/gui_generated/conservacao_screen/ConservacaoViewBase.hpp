/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CONSERVACAOVIEWBASE_HPP
#define CONSERVACAOVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/conservacao_screen/ConservacaoPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>

class ConservacaoViewBase : public touchgfx::View<ConservacaoPresenter>
{
public:
    ConservacaoViewBase();
    virtual ~ConservacaoViewBase() {}
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void handleTickEvent();
    virtual void tearDownScreen();
    virtual void Conservar_Congelar();
    virtual void Conservar_Resfriar();
    virtual void afterTransition();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box boxFundo;
    touchgfx::Box boxFundoAzul;
    touchgfx::TextArea textAreaTitle;
    touchgfx::Image imageLogo;
    touchgfx::RadioButton radioButtonStatusConservar0;
    touchgfx::RadioButton radioButtonStatusConservar1;
    touchgfx::Button buttonFlagConservarCongResf;
    touchgfx::Button buttonTelaInicial;
    touchgfx::RadioButtonGroup<2> radioButtonGroup1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<ConservacaoViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<ConservacaoViewBase, const touchgfx::AbstractButton&> radioButtonSelectedCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // CONSERVACAOVIEWBASE_HPP
