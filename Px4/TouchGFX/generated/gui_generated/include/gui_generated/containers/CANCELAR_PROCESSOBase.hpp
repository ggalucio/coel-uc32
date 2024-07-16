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
     * Custom Actions
     */
    virtual void init();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
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

};

#endif // CANCELAR_PROCESSOBASE_HPP