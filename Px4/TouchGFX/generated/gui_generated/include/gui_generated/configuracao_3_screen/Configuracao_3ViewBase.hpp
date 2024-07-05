/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CONFIGURACAO_3VIEWBASE_HPP
#define CONFIGURACAO_3VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/configuracao_3_screen/Configuracao_3Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class Configuracao_3ViewBase : public touchgfx::View<Configuracao_3Presenter>
{
public:
    Configuracao_3ViewBase();
    virtual ~Configuracao_3ViewBase() {}
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
    touchgfx::BoxWithBorder boxWithBorderBranco;
    touchgfx::Box boxVerde4;
    touchgfx::Box boxVerde3;
    touchgfx::Box boxVerde2;
    touchgfx::Box boxVerde;
    touchgfx::TextArea textAreaLabel1;
    touchgfx::TextArea textAreaLabel2;
    touchgfx::TextArea textAreaLabel3;
    touchgfx::TextArea textAreaLabel4;
    touchgfx::TextArea textAreaLabel6;
    touchgfx::TextArea textAreaLabel7;
    touchgfx::Button buttonTelaInicial;
    touchgfx::Button buttonConfiguracao4;
    touchgfx::Button buttonConfiguracao2;
    touchgfx::ToggleButton toggleButtonHSW4;
    touchgfx::TextAreaWithOneWildcard textArea1410250;
    touchgfx::TextAreaWithOneWildcard textArea1410249;
    touchgfx::TextAreaWithOneWildcard textArea1410248;
    touchgfx::TextAreaWithOneWildcard textArea1410291;
    touchgfx::TextAreaWithOneWildcard textArea1410275;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREA1410250_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1410250Buffer[TEXTAREA1410250_SIZE];
    static const uint16_t TEXTAREA1410249_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1410249Buffer[TEXTAREA1410249_SIZE];
    static const uint16_t TEXTAREA1410248_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1410248Buffer[TEXTAREA1410248_SIZE];
    static const uint16_t TEXTAREA1410291_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1410291Buffer[TEXTAREA1410291_SIZE];
    static const uint16_t TEXTAREA1410275_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1410275Buffer[TEXTAREA1410275_SIZE];

private:

};

#endif // CONFIGURACAO_3VIEWBASE_HPP