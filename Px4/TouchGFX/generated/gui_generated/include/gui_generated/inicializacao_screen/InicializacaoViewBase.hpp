/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef INICIALIZACAOVIEWBASE_HPP
#define INICIALIZACAOVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/inicializacao_screen/InicializacaoPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>

class InicializacaoViewBase : public touchgfx::View<InicializacaoPresenter>
{
public:
    InicializacaoViewBase();
    virtual ~InicializacaoViewBase() {}
    virtual void setupScreen();

    /*
     * Custom Actions
     */
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void afterTransition();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }
    touchgfx::Box __background;

private:

    /*
     * Delay Variable Declarations
     */
    static const uint16_t AGUARDAR_DURATION = 300;
    uint16_t aguardarCounter;

};

#endif // INICIALIZACAOVIEWBASE_HPP
