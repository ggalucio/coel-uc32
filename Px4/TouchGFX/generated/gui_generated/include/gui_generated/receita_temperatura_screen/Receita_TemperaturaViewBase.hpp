/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef RECEITA_TEMPERATURAVIEWBASE_HPP
#define RECEITA_TEMPERATURAVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/receita_temperatura_screen/Receita_TemperaturaPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <gui/containers/CANCELAR_PROCESSO.hpp>
#include <gui/containers/Background.hpp>
#include <gui/containers/Timer.hpp>

class Receita_TemperaturaViewBase : public touchgfx::View<Receita_TemperaturaPresenter>
{
public:
    Receita_TemperaturaViewBase();
    virtual ~Receita_TemperaturaViewBase() {}
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void tearDownScreen();
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
    touchgfx::Box boxProcessOff;
    touchgfx::Box boxFlagProcessoAndamento;
    touchgfx::Box boxFundoAzul;
    touchgfx::BoxWithBorder boxWithBorderBox3;
    touchgfx::BoxWithBorder boxWithBorderBox2;
    touchgfx::BoxWithBorder boxWithBorderBox1;
    touchgfx::Box boxFundoAzul2;
    touchgfx::TextArea textAreaUnidade2;
    touchgfx::TextArea textAreaUnidade3;
    touchgfx::TextArea textAreaUnidade1;
    touchgfx::TextArea textAreaTitle;
    touchgfx::Button buttonCancelarProcesso;
    touchgfx::ToggleButton toggleButtonFlagConservarSN;
    touchgfx::Image imageVazio;
    touchgfx::Image image1;
    touchgfx::Image image2;
    touchgfx::Image image3;
    touchgfx::TextArea textAreaLabel1;
    touchgfx::TextArea textAreaLabel2;
    touchgfx::TextArea textAreaLabel3;
    touchgfx::TextAreaWithOneWildcard textAreaTimerCountMinutos;
    touchgfx::TextAreaWithOneWildcard textAreaTempoEstimadoReceitaTemprat;
    touchgfx::TextAreaWithOneWildcard textAreaFlagProcessoAndamento;
    touchgfx::TextAreaWithOneWildcard textAreaTimerCongelarDecorridoCount;
    touchgfx::TextAreaWithOneWildcard textArea14515;
    touchgfx::TextAreaWithOneWildcard textAreaTemperaturaReceitaAtual;
    touchgfx::TextAreaWithOneWildcard textArea14512;
    CANCELAR_PROCESSO cANCELAR_PROCESSO1;
    Background background1;
    Timer timerCycle1s;
    Timer timerCycle10;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREATIMERCOUNTMINUTOS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTimerCountMinutosBuffer[TEXTAREATIMERCOUNTMINUTOS_SIZE];
    static const uint16_t TEXTAREATEMPOESTIMADORECEITATEMPRAT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTempoEstimadoReceitaTempratBuffer[TEXTAREATEMPOESTIMADORECEITATEMPRAT_SIZE];
    static const uint16_t TEXTAREAFLAGPROCESSOANDAMENTO_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textAreaFlagProcessoAndamentoBuffer[TEXTAREAFLAGPROCESSOANDAMENTO_SIZE];
    static const uint16_t TEXTAREATIMERCONGELARDECORRIDOCOUNT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTimerCongelarDecorridoCountBuffer[TEXTAREATIMERCONGELARDECORRIDOCOUNT_SIZE];
    static const uint16_t TEXTAREA14515_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea14515Buffer[TEXTAREA14515_SIZE];
    static const uint16_t TEXTAREATEMPERATURARECEITAATUAL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTemperaturaReceitaAtualBuffer[TEXTAREATEMPERATURARECEITAATUAL_SIZE];
    static const uint16_t TEXTAREA14512_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea14512Buffer[TEXTAREA14512_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Receita_TemperaturaViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<Receita_TemperaturaViewBase> cANCELAR_PROCESSO1CancelarProcessoCallback;
    touchgfx::Callback<Receita_TemperaturaViewBase> cANCELAR_PROCESSO1NaoCallback;
    touchgfx::Callback<Receita_TemperaturaViewBase> timerCycle1sTickCallback;
    touchgfx::Callback<Receita_TemperaturaViewBase> timerCycle10TickCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void cANCELAR_PROCESSO1CancelarProcessoCallbackHandler();
    void cANCELAR_PROCESSO1NaoCallbackHandler();
    void timerCycle1sTickCallbackHandler();
    void timerCycle10TickCallbackHandler();

};

#endif // RECEITA_TEMPERATURAVIEWBASE_HPP
