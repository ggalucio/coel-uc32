/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CONGELAR_SELECT_TEMPOVIEWBASE_HPP
#define CONGELAR_SELECT_TEMPOVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/congelar_select_tempo_screen/Congelar_select_TEMPOPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/Button.hpp>

class Congelar_select_TEMPOViewBase : public touchgfx::View<Congelar_select_TEMPOPresenter>
{
public:
    Congelar_select_TEMPOViewBase();
    virtual ~Congelar_select_TEMPOViewBase() {}
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void handleTickEvent();
    virtual void tearDownScreen();
    virtual void Congelar_TEMPO();
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
    touchgfx::Box boxFundoMinutos;
    touchgfx::TextArea textAreaTitle;
    touchgfx::TextArea textAreaUnidade;
    touchgfx::TextAreaWithOneWildcard textAreaTimerSpMinutos;
    touchgfx::ButtonWithLabel buttonWithLabelIncrementar;
    touchgfx::ButtonWithLabel buttonWithLabelDecrementar;
    touchgfx::TextArea textAreaTempoZero;
    touchgfx::Button buttonAvancar;
    touchgfx::Button buttonVoltar;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREATIMERSPMINUTOS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTimerSpMinutosBuffer[TEXTAREATIMERSPMINUTOS_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Congelar_select_TEMPOViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // CONGELAR_SELECT_TEMPOVIEWBASE_HPP
