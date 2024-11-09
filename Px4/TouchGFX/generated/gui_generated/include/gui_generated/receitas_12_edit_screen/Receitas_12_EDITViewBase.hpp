/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef RECEITAS_12_EDITVIEWBASE_HPP
#define RECEITAS_12_EDITVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/receitas_12_edit_screen/Receitas_12_EDITPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/containers/Container.hpp>
#include <gui/containers/keyboardContainer2.hpp>
#include <gui/containers/numKeyboardContainer.hpp>
#include <gui/containers/Background.hpp>

class Receitas_12_EDITViewBase : public touchgfx::View<Receitas_12_EDITPresenter>
{
public:
    Receitas_12_EDITViewBase();
    virtual ~Receitas_12_EDITViewBase() {}
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void handleTickEvent();
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
    touchgfx::Box boxFundoAzul;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::Line line1_1;
    touchgfx::PainterRGB565 line1_1Painter;
    touchgfx::TextArea textArea1_3;
    touchgfx::TextArea textArea1;
    touchgfx::TextArea textArea1_1;
    touchgfx::TextArea textArea1_2;
    touchgfx::TextAreaWithOneWildcard textAreaTitle;
    touchgfx::Image image1;
    touchgfx::Box box1;
    touchgfx::ToggleButton toggleButtonRXCongResf;
    touchgfx::ToggleButton toggleButtonRXhardSoft;
    touchgfx::ToggleButton toggleButtonRXConservYn;
    touchgfx::ToggleButton toggleButtonRXTimeTemp;
    touchgfx::TextAreaWithOneWildcard textAreaReceitaXDesc;
    touchgfx::TextArea textArea2;
    touchgfx::Button buttonSalvar;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButtonReceitaXDesc;
    touchgfx::Container containerTemperatura;
    touchgfx::Box box3;
    touchgfx::TextArea textArea1_2_1_C;
    touchgfx::TextAreaWithOneWildcard textAreaTemperaturaReceita;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButtonTemperaturaReceita;
    touchgfx::Container containerTempo;
    touchgfx::Box box2;
    touchgfx::TextArea textArea1_2_1;
    touchgfx::TextAreaWithOneWildcard textAreaTempoReceitaX;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > flexButtonTempoReceitaX;
    keyboardContainer2 keyboardContainer21;
    numKeyboardContainer numKeyboardContainer1;
    Background background1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREATITLE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTitleBuffer[TEXTAREATITLE_SIZE];
    static const uint16_t TEXTAREARECEITAXDESC_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textAreaReceitaXDescBuffer[TEXTAREARECEITAXDESC_SIZE];
    static const uint16_t TEXTAREATEMPERATURARECEITA_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTemperaturaReceitaBuffer[TEXTAREATEMPERATURARECEITA_SIZE];
    static const uint16_t TEXTAREATEMPORECEITAX_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTempoReceitaXBuffer[TEXTAREATEMPORECEITAX_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Receitas_12_EDITViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<Receitas_12_EDITViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;
    touchgfx::Callback<Receitas_12_EDITViewBase> keyboardContainer21HideKeyboardCallback;
    touchgfx::Callback<Receitas_12_EDITViewBase> numKeyboardContainer1HideKeypadTriggerCallback;
    touchgfx::Callback<Receitas_12_EDITViewBase> numKeyboardContainer1OutOfRangeCallback;
    touchgfx::Callback<Receitas_12_EDITViewBase> numKeyboardContainer1ValidRangeCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);
    void keyboardContainer21HideKeyboardCallbackHandler();
    void numKeyboardContainer1HideKeypadTriggerCallbackHandler();
    void numKeyboardContainer1OutOfRangeCallbackHandler();
    void numKeyboardContainer1ValidRangeCallbackHandler();

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // RECEITAS_12_EDITVIEWBASE_HPP
