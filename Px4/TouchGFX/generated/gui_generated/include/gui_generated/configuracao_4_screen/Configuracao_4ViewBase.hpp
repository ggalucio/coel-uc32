/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CONFIGURACAO_4VIEWBASE_HPP
#define CONFIGURACAO_4VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/configuracao_4_screen/Configuracao_4Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class Configuracao_4ViewBase : public touchgfx::View<Configuracao_4Presenter>
{
public:
    Configuracao_4ViewBase();
    virtual ~Configuracao_4ViewBase() {}
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void handleTickEvent();
    virtual void tearDownScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box boxFundo;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::BoxWithBorder boxWithBorder2;
    touchgfx::TextArea textAreaLabel2;
    touchgfx::TextArea textAreaLabel1;
    touchgfx::Button buttonTelaInicial;
    touchgfx::Button buttonConfiguracao5;
    touchgfx::Button buttonConfiguracao3;
    touchgfx::ButtonWithLabel buttonWithLabelLogicaEntradaDigita2_2;
    touchgfx::ButtonWithLabel buttonWithLabelLogicaEntradaDigita2_1;
    touchgfx::ButtonWithLabel buttonWithLabelLogicaEntradaDigita2_0;
    touchgfx::ButtonWithLabel buttonWithLabelLogicaEntradaDigita1_1;
    touchgfx::ButtonWithLabel buttonWithLabelLogicaEntradaDigita1_0;
    touchgfx::TextAreaWithOneWildcard textAreaLogicaEntradaDigital2;
    touchgfx::TextAreaWithOneWildcard textAreaLogicaEntradaDigital1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREALOGICAENTRADADIGITAL2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaLogicaEntradaDigital2Buffer[TEXTAREALOGICAENTRADADIGITAL2_SIZE];
    static const uint16_t TEXTAREALOGICAENTRADADIGITAL1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaLogicaEntradaDigital1Buffer[TEXTAREALOGICAENTRADADIGITAL1_SIZE];

private:

};

#endif // CONFIGURACAO_4VIEWBASE_HPP
