/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CONSERVAR_RESFRIARVIEWBASE_HPP
#define CONSERVAR_RESFRIARVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/conservar_resfriar_screen/Conservar_ResfriarPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class Conservar_ResfriarViewBase : public touchgfx::View<Conservar_ResfriarPresenter>
{
public:
    Conservar_ResfriarViewBase();
    virtual ~Conservar_ResfriarViewBase() {}
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
    touchgfx::TextArea textAreaTitle;
    touchgfx::Image imageVazio;
    touchgfx::Image imageVazio_1;
    touchgfx::Image imageLogo;
    touchgfx::Box boxProcessOff;
    touchgfx::BoxWithBorder boxWithBorderBox3;
    touchgfx::BoxWithBorder boxWithBorderBox1;
    touchgfx::Box boxFundoAzul2;
    touchgfx::Image image1;
    touchgfx::Image image3;
    touchgfx::TextArea textAreaUnidade1;
    touchgfx::TextArea textAreaUnidade1_1;
    touchgfx::TextArea textAreaLabel1;
    touchgfx::TextArea textAreaLabel1_1;
    touchgfx::Button buttonCancelarProcesso;
    touchgfx::TextArea textAreaFlagConservarAndamento;
    touchgfx::TextAreaWithOneWildcard textArea14515;
    touchgfx::TextAreaWithOneWildcard textArea14512;
    touchgfx::TextAreaWithOneWildcard textArea1410242;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREA14515_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea14515Buffer[TEXTAREA14515_SIZE];
    static const uint16_t TEXTAREA14512_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea14512Buffer[TEXTAREA14512_SIZE];
    static const uint16_t TEXTAREA1410242_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea1410242Buffer[TEXTAREA1410242_SIZE];

private:

};

#endif // CONSERVAR_RESFRIARVIEWBASE_HPP