/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef HIGIENEVIEWBASE_HPP
#define HIGIENEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/higiene_screen/HIGIENEPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class HIGIENEViewBase : public touchgfx::View<HIGIENEPresenter>
{
public:
    HIGIENEViewBase();
    virtual ~HIGIENEViewBase() {}
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
    touchgfx::BoxWithBorder boxWithBorderBox3;
    touchgfx::TextArea textAreaUnidade2;
    touchgfx::TextArea textAreaTitle;
    touchgfx::Button buttonFinalizarHigiene;
    touchgfx::Image image3;
    touchgfx::TextArea textAreaLabel2;
    touchgfx::TextAreaWithOneWildcard textAreaTimerHigieneMin;
    touchgfx::TextArea textAreaStatusHigiene;
    touchgfx::TextAreaWithOneWildcard textAreaTimerCongelarDecorridoCount;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREATIMERHIGIENEMIN_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTimerHigieneMinBuffer[TEXTAREATIMERHIGIENEMIN_SIZE];
    static const uint16_t TEXTAREATIMERCONGELARDECORRIDOCOUNT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTimerCongelarDecorridoCountBuffer[TEXTAREATIMERCONGELARDECORRIDOCOUNT_SIZE];

private:

};

#endif // HIGIENEVIEWBASE_HPP