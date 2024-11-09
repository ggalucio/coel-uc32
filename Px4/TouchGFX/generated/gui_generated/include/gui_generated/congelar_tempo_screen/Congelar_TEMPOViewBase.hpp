/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CONGELAR_TEMPOVIEWBASE_HPP
#define CONGELAR_TEMPOVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/congelar_tempo_screen/Congelar_TEMPOPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/containers/progress_indicators/LineProgress.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <gui/containers/CANCELAR_PROCESSO.hpp>
#include <gui/containers/Background.hpp>
#include <gui/containers/Timer.hpp>

class Congelar_TEMPOViewBase : public touchgfx::View<Congelar_TEMPOPresenter>
{
public:
    Congelar_TEMPOViewBase();
    virtual ~Congelar_TEMPOViewBase() {}
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
    touchgfx::Box boxFundoAzul;
    touchgfx::Box boxFlagProcessoAndamento;
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
    touchgfx::LineProgress lineProgressTimerCongelar;
    touchgfx::PainterRGB565 lineProgressTimerCongelarPainter;
    touchgfx::Image imageVazio;
    touchgfx::Image image1;
    touchgfx::Image image2;
    touchgfx::Image image3;
    touchgfx::TextArea textAreaLabel1;
    touchgfx::TextArea textAreaLabel2;
    touchgfx::TextArea textAreaLabel3;
    touchgfx::TextAreaWithOneWildcard textAreaFlagProcessoAndamento;
    touchgfx::TextAreaWithOneWildcard textAreaTimerCountMinutos;
    touchgfx::TextAreaWithOneWildcard textAreaTimerSpMinutos;
    touchgfx::TextAreaWithOneWildcard textAreaTimerCongelarDecorridoCount;
    touchgfx::TextAreaWithOneWildcard textArea14512;
    touchgfx::TextAreaWithOneWildcard textArea1410242;
    CANCELAR_PROCESSO cANCELAR_PROCESSO1;
    Background background1;
    Timer timerCycle1s;
    Timer timerCycle10;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREAFLAGPROCESSOANDAMENTO_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textAreaFlagProcessoAndamentoBuffer[TEXTAREAFLAGPROCESSOANDAMENTO_SIZE];
    static const uint16_t TEXTAREATIMERCOUNTMINUTOS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTimerCountMinutosBuffer[TEXTAREATIMERCOUNTMINUTOS_SIZE];
    static const uint16_t TEXTAREATIMERSPMINUTOS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTimerSpMinutosBuffer[TEXTAREATIMERSPMINUTOS_SIZE];
    static const uint16_t TEXTAREATIMERCONGELARDECORRIDOCOUNT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTimerCongelarDecorridoCountBuffer[TEXTAREATIMERCONGELARDECORRIDOCOUNT_SIZE];
    static const uint16_t TEXTAREA14512_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea14512Buffer[TEXTAREA14512_SIZE];
    static const uint16_t TEXTAREA1410242_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1410242Buffer[TEXTAREA1410242_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Congelar_TEMPOViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<Congelar_TEMPOViewBase> cANCELAR_PROCESSO1CancelarProcessoCallback;
    touchgfx::Callback<Congelar_TEMPOViewBase> cANCELAR_PROCESSO1NaoCallback;
    touchgfx::Callback<Congelar_TEMPOViewBase> timerCycle1sTickCallback;
    touchgfx::Callback<Congelar_TEMPOViewBase> timerCycle10TickCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void cANCELAR_PROCESSO1CancelarProcessoCallbackHandler();
    void cANCELAR_PROCESSO1NaoCallbackHandler();
    void timerCycle1sTickCallbackHandler();
    void timerCycle10TickCallbackHandler();

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // CONGELAR_TEMPOVIEWBASE_HPP
