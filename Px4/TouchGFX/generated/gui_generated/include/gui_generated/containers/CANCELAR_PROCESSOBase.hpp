/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CANCELAR_PROCESSOBASE_HPP
#define CANCELAR_PROCESSOBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class CANCELAR_PROCESSOBase : public touchgfx::Container
{
public:
    CANCELAR_PROCESSOBase();
    virtual ~CANCELAR_PROCESSOBase() {}
    virtual void initialize();

    /*
     * Custom Trigger Callback Setters
     */
    void setCancelarProcessoCallback(touchgfx::GenericCallback<>& callback)
    {
        this->cancelarProcessoCallback = &callback;
    }
    void setNaoCallback(touchgfx::GenericCallback<>& callback)
    {
        this->naoCallback = &callback;
    }

    /*
     * Custom Actions
     */
    virtual void init();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Custom Trigger Emitters
     */
    virtual void emitCancelarProcessoCallback()
    {
        if (cancelarProcessoCallback && cancelarProcessoCallback->isValid())
        {
            this->cancelarProcessoCallback->execute();
        }
    }
    virtual void emitNaoCallback()
    {
        if (naoCallback && naoCallback->isValid())
        {
            this->naoCallback->execute();
        }
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::Box box2;
    touchgfx::ButtonWithLabel buttonWithLabelNao;
    touchgfx::ButtonWithLabel buttonWithLabelCancelarProcessoSim;
    touchgfx::TextArea textAreaMensagem;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<CANCELAR_PROCESSOBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Custom Trigger Callback Declarations
     */
    touchgfx::GenericCallback<>* cancelarProcessoCallback;
    touchgfx::GenericCallback<>* naoCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // CANCELAR_PROCESSOBASE_HPP
