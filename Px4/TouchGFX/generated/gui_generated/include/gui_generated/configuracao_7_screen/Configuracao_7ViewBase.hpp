/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CONFIGURACAO_7VIEWBASE_HPP
#define CONFIGURACAO_7VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/configuracao_7_screen/Configuracao_7Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <gui/containers/numKeyboardContainer.hpp>
#include <gui/containers/Background.hpp>

class Configuracao_7ViewBase : public touchgfx::View<Configuracao_7Presenter>
{
public:
    Configuracao_7ViewBase();
    virtual ~Configuracao_7ViewBase() {}
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
    touchgfx::Box boxVermelho2;
    touchgfx::Box boxVermelho;
    touchgfx::Box boxVerde4;
    touchgfx::Box boxVerde3;
    touchgfx::Box boxVerde2;
    touchgfx::Box boxVerde;
    touchgfx::TextArea textAreaLabel1;
    touchgfx::TextArea textAreaLabel2;
    touchgfx::TextArea textAreaLabel3;
    touchgfx::TextArea textAreaLabel4;
    touchgfx::TextArea textAreaLabel5;
    touchgfx::TextArea textAreaLabel6;
    touchgfx::Button buttonTelaInicial;
    touchgfx::Button buttonConfiguracao6;
    touchgfx::TextAreaWithOneWildcard textAreaPorcResfPresetTempoF1F2;
    touchgfx::TextAreaWithOneWildcard textAreaDiferencialResfriarTempo;
    touchgfx::TextAreaWithOneWildcard textAreaSpSondaResfCamara;
    touchgfx::TextAreaWithOneWildcard textAreaSpResfriarSonda;
    touchgfx::TextAreaWithOneWildcard textAreaSpResfInternoF1;
    touchgfx::TextAreaWithOneWildcard textAreaSpResfEspetoF1;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButtonPorcResfPresetTempoF1F2;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButtonDiferencialResfriarTempo;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButtonSpSondaResfCamara;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButtonSpResfriarSonda;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButtonSpResfInternoF1;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButtonSpResfEspetoF1;
    numKeyboardContainer numKeyboardContainer1;
    Background background1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREAPORCRESFPRESETTEMPOF1F2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaPorcResfPresetTempoF1F2Buffer[TEXTAREAPORCRESFPRESETTEMPOF1F2_SIZE];
    static const uint16_t TEXTAREADIFERENCIALRESFRIARTEMPO_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaDiferencialResfriarTempoBuffer[TEXTAREADIFERENCIALRESFRIARTEMPO_SIZE];
    static const uint16_t TEXTAREASPSONDARESFCAMARA_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaSpSondaResfCamaraBuffer[TEXTAREASPSONDARESFCAMARA_SIZE];
    static const uint16_t TEXTAREASPRESFRIARSONDA_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaSpResfriarSondaBuffer[TEXTAREASPRESFRIARSONDA_SIZE];
    static const uint16_t TEXTAREASPRESFINTERNOF1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaSpResfInternoF1Buffer[TEXTAREASPRESFINTERNOF1_SIZE];
    static const uint16_t TEXTAREASPRESFESPETOF1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaSpResfEspetoF1Buffer[TEXTAREASPRESFESPETOF1_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Configuracao_7ViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<Configuracao_7ViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<Configuracao_7ViewBase> numKeyboardContainer1OutOfRangeCallback;
    touchgfx::Callback<Configuracao_7ViewBase> numKeyboardContainer1ValidRangeCallback;
    touchgfx::Callback<Configuracao_7ViewBase> numKeyboardContainer1HideKeypadTriggerCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
    void numKeyboardContainer1OutOfRangeCallbackHandler();
    void numKeyboardContainer1ValidRangeCallbackHandler();
    void numKeyboardContainer1HideKeypadTriggerCallbackHandler();

};

#endif // CONFIGURACAO_7VIEWBASE_HPP
