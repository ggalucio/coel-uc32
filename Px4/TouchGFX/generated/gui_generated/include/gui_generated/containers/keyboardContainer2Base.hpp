/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef KEYBOARDCONTAINER2BASE_HPP
#define KEYBOARDCONTAINER2BASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <AT_module.hpp>

class keyboardContainer2Base : public touchgfx::Container
{
public:
    keyboardContainer2Base();
    virtual ~keyboardContainer2Base() {}
    virtual void initialize();

    /*
     * Custom Trigger Callback Setters
     */
    void setHideKeyboardCallback(touchgfx::GenericCallback<>& callback)
    {
        this->HideKeyboardCallback = &callback;
    }
    void setEnterCallback(touchgfx::GenericCallback<>& callback)
    {
        this->EnterCallback = &callback;
    }

    /*
     * Custom Actions
     */
    virtual void LaunchKeyboard();

    /*
     * Virtual Action Handlers
     */
    virtual void shiftPressed()
    {
        // Override and implement this function in keyboardContainer2
    }

    virtual void numPressed()
    {
        // Override and implement this function in keyboardContainer2
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Custom Trigger Emitters
     */
    virtual void emitHideKeyboardCallback()
    {
        if (HideKeyboardCallback && HideKeyboardCallback->isValid())
        {
            this->HideKeyboardCallback->execute();
        }
    }
    virtual void emitEnterCallback()
    {
        if (EnterCallback && EnterCallback->isValid())
        {
            this->EnterCallback->execute();
        }
    }

    /*
     * Member Declarations
     */
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > backgroundFlexButton;
    touchgfx::Box backgroundBox;
    touchgfx::Box keyboardBox;
    touchgfx::BoxWithBorder textBox;
    touchgfx::TextAreaWithOneWildcard valTxt;
    touchgfx::ButtonWithLabel qTxt;
    touchgfx::ButtonWithLabel wTxt;
    touchgfx::ButtonWithLabel eTxt;
    touchgfx::ButtonWithLabel rTxt;
    touchgfx::ButtonWithLabel tTxt;
    touchgfx::ButtonWithLabel yTxt;
    touchgfx::ButtonWithLabel uTxt;
    touchgfx::ButtonWithLabel iTxt;
    touchgfx::ButtonWithLabel oTxt;
    touchgfx::ButtonWithLabel pTxt;
    touchgfx::ButtonWithLabel slashTxt;
    touchgfx::ButtonWithLabel aTxt;
    touchgfx::ButtonWithLabel sTxt;
    touchgfx::ButtonWithLabel dTxt;
    touchgfx::ButtonWithLabel fTxt;
    touchgfx::ButtonWithLabel gTxt;
    touchgfx::ButtonWithLabel hTxt;
    touchgfx::ButtonWithLabel jTxt;
    touchgfx::ButtonWithLabel kTxt;
    touchgfx::ButtonWithLabel lTxt;
    touchgfx::ButtonWithLabel dotsTxt;
    touchgfx::ButtonWithLabel dotcommaTxt;
    touchgfx::ButtonWithLabel zTxt;
    touchgfx::ButtonWithLabel xTxt;
    touchgfx::ButtonWithLabel cTxt;
    touchgfx::ButtonWithLabel vTxt;
    touchgfx::ButtonWithLabel bTxt;
    touchgfx::ButtonWithLabel nTxt;
    touchgfx::ButtonWithLabel mTxt;
    touchgfx::Button keyShiftBtn;
    touchgfx::Button deleteKeyBtn;
    touchgfx::Button spaceKeyBtn;
    touchgfx::ButtonWithLabel okBtn;
    touchgfx::ButtonWithLabel cancelBtn;
    touchgfx::ButtonWithLabel keyNumBtn;

    /*
     * Wildcard Buffers
     */
    static const uint16_t VALTXT_SIZE = 20;
    touchgfx::Unicode::UnicodeChar valTxtBuffer[VALTXT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<keyboardContainer2Base, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<keyboardContainer2Base, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Custom Trigger Callback Declarations
     */
    touchgfx::GenericCallback<>* HideKeyboardCallback;
    touchgfx::GenericCallback<>* EnterCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // KEYBOARDCONTAINER2BASE_HPP
