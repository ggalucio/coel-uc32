/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef NUMKEYBOARDCONTAINERPWDBASE_HPP
#define NUMKEYBOARDCONTAINERPWDBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <AT_module.hpp>

class numKeyboardContainerPwdBase : public touchgfx::Container
{
public:
    numKeyboardContainerPwdBase();
    virtual ~numKeyboardContainerPwdBase() {}
    virtual void initialize();

    /*
     * Custom Trigger Callback Setters
     */
    void setCancelTriggerCallback(touchgfx::GenericCallback<>& callback)
    {
        this->CancelTriggerCallback = &callback;
    }
    void setCredentialSuccessCallback(touchgfx::GenericCallback<>& callback)
    {
        this->CredentialSuccessCallback = &callback;
    }
    void setCredentialFailedCallback(touchgfx::GenericCallback<>& callback)
    {
        this->CredentialFailedCallback = &callback;
    }

    /*
     * Custom Actions
     */
    virtual void LaunchNumericalKeyboard();
    virtual void ViewErrorMsg();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Custom Trigger Emitters
     */
    virtual void emitCancelTriggerCallback()
    {
        if (CancelTriggerCallback && CancelTriggerCallback->isValid())
        {
            this->CancelTriggerCallback->execute();
        }
    }
    virtual void emitCredentialSuccessCallback()
    {
        if (CredentialSuccessCallback && CredentialSuccessCallback->isValid())
        {
            this->CredentialSuccessCallback->execute();
        }
    }
    virtual void emitCredentialFailedCallback()
    {
        if (CredentialFailedCallback && CredentialFailedCallback->isValid())
        {
            this->CredentialFailedCallback->execute();
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
    touchgfx::Button dotBtn;
    touchgfx::Button delBtn;
    touchgfx::ButtonWithLabel zeroBtn;
    touchgfx::ButtonWithLabel oneBtn;
    touchgfx::ButtonWithLabel twoBtn;
    touchgfx::ButtonWithLabel threeBtn;
    touchgfx::ButtonWithLabel fourBtn;
    touchgfx::ButtonWithLabel fiveBtn;
    touchgfx::ButtonWithLabel sixBtn;
    touchgfx::ButtonWithLabel sevenBtn;
    touchgfx::ButtonWithLabel eightBtn;
    touchgfx::ButtonWithLabel nineBtn;
    touchgfx::ButtonWithLabel cancelBtn;
    touchgfx::ButtonWithLabel okBtn;
    touchgfx::ButtonWithLabel signBtn;
    touchgfx::ButtonWithLabel clearBtn;
    touchgfx::TextAreaWithOneWildcard hideValTxt;
    touchgfx::TextArea errTxt;

    /*
     * Wildcard Buffers
     */
    static const uint16_t VALTXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar valTxtBuffer[VALTXT_SIZE];
    static const uint16_t HIDEVALTXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar hideValTxtBuffer[HIDEVALTXT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<numKeyboardContainerPwdBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<numKeyboardContainerPwdBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Custom Trigger Callback Declarations
     */
    touchgfx::GenericCallback<>* CancelTriggerCallback;
    touchgfx::GenericCallback<>* CredentialSuccessCallback;
    touchgfx::GenericCallback<>* CredentialFailedCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // NUMKEYBOARDCONTAINERPWDBASE_HPP
