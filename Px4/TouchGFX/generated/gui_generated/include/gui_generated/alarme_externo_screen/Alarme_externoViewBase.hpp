/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef ALARME_EXTERNOVIEWBASE_HPP
#define ALARME_EXTERNOVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/alarme_externo_screen/Alarme_externoPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/AnimatedImage.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Alarme_externoViewBase : public touchgfx::View<Alarme_externoPresenter>
{
public:
    Alarme_externoViewBase();
    virtual ~Alarme_externoViewBase() {}
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
    touchgfx::AnimatedImage animatedImageFlagAlarmeExternoAndamento;
    touchgfx::TextAreaWithOneWildcard textAreaDescricaoAlarmeExterno;
    touchgfx::TextAreaWithOneWildcard textAreaHAW8235;
    touchgfx::TextAreaWithOneWildcard textAreaTimerAlarmeExternoCount;
    touchgfx::TextArea textAreaFlagAlarmeExternoAndamento;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREADESCRICAOALARMEEXTERNO_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textAreaDescricaoAlarmeExternoBuffer[TEXTAREADESCRICAOALARMEEXTERNO_SIZE];
    static const uint16_t TEXTAREAHAW8235_SIZE = 20;
    touchgfx::Unicode::UnicodeChar textAreaHAW8235Buffer[TEXTAREAHAW8235_SIZE];
    static const uint16_t TEXTAREATIMERALARMEEXTERNOCOUNT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textAreaTimerAlarmeExternoCountBuffer[TEXTAREATIMERALARMEEXTERNOCOUNT_SIZE];

private:

};

#endif // ALARME_EXTERNOVIEWBASE_HPP
