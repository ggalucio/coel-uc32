/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef RECEITAS_3VIEWBASE_HPP
#define RECEITAS_3VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/receitas_3_screen/Receitas_3Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <gui/containers/Background.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>

class Receitas_3ViewBase : public touchgfx::View<Receitas_3Presenter>
{
public:
    Receitas_3ViewBase();
    virtual ~Receitas_3ViewBase() {}
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
    touchgfx::Box boxFundoAzul;
    touchgfx::TextArea textAreaTitle;
    touchgfx::Image image1;
    touchgfx::BoxWithBorder boxWithBorder1;
    touchgfx::BoxWithBorder boxWithBorder2;
    touchgfx::BoxWithBorder boxWithBorder3;
    touchgfx::BoxWithBorder boxWithBorder4;
    touchgfx::RadioButton radioButtonMuneroReceita9;
    touchgfx::RadioButton radioButtonMuneroReceita10;
    touchgfx::RadioButton radioButtonMuneroReceita11;
    touchgfx::RadioButton radioButtonMuneroReceita12;
    touchgfx::Button buttonFlagReceita1Interm;
    touchgfx::Button buttonTelaInicial;
    touchgfx::Button buttonFlagEditReceita;
    touchgfx::Button buttonReceita2;
    touchgfx::TextAreaWithOneWildcard textAreaReceita9Desc;
    touchgfx::TextAreaWithOneWildcard textAreaReceita10Desc;
    touchgfx::TextAreaWithOneWildcard textAreaReceita11Desc;
    touchgfx::TextAreaWithOneWildcard textAreaReceita12Desc;
    Background background1;
    touchgfx::RadioButtonGroup<4> radioButtonGroup1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREARECEITA9DESC_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textAreaReceita9DescBuffer[TEXTAREARECEITA9DESC_SIZE];
    static const uint16_t TEXTAREARECEITA10DESC_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textAreaReceita10DescBuffer[TEXTAREARECEITA10DESC_SIZE];
    static const uint16_t TEXTAREARECEITA11DESC_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textAreaReceita11DescBuffer[TEXTAREARECEITA11DESC_SIZE];
    static const uint16_t TEXTAREARECEITA12DESC_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textAreaReceita12DescBuffer[TEXTAREARECEITA12DESC_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Receitas_3ViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<Receitas_3ViewBase, const touchgfx::AbstractButton&> radioButtonSelectedCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void radioButtonSelectedCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // RECEITAS_3VIEWBASE_HPP
