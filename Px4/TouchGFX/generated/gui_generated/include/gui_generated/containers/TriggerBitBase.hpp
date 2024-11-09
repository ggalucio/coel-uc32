/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TRIGGERBITBASE_HPP
#define TRIGGERBITBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <gui/containers/ScreenManagement.hpp>
#include <gui/containers/Timer.hpp>
#include <AT_module.hpp>
#include <AT_module_ext.hpp>
#include <gui/global/var.hpp>
#include <string.h>

class TriggerBitBase : public touchgfx::Container
{
public:
    TriggerBitBase();
    virtual ~TriggerBitBase() {}
    virtual void initialize();

    /*
     * Custom Actions
     */
    virtual void flagCongelarSonda();
    virtual void timerCongelarDecorridoOut();
    virtual void timerBuzzerOut();
    virtual void flagCongelarTempo();
    virtual void cancelarProcessoSim();
    virtual void timerBuzzerOn();
    virtual void flagConcervarCongResf();
    virtual void flagResfriarSondaTempo();
    virtual void flagInicioDegelo();
    virtual void flagCancelarDegeloSim();
    virtual void flagEditReceita();
    virtual void flagReceita1Interm();
    virtual void flagReceita2Interm();
    virtual void flagReceita3Interm();
    virtual void flagStartReceita();
    virtual void flagRedefineSenha();
    virtual void flagAlarmeExterno();
    virtual void timerAlarmeExternoOut();
    virtual void entradaDigital3();
    virtual void confereSenha();
    virtual void resetFabrica();
    virtual void startHigiene();
    virtual void cancelaHigiene();
    virtual void changeScreen(uint16_t value);
    virtual void flagInicilizarAplicacao();
    virtual void timerBuzzerDegOut();
    virtual void timerBuzzerDegOn();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    ScreenManagement hScreen;
    Timer timerTriggerBit;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<TriggerBitBase> timerTriggerBitTickCallback;
    touchgfx::Callback<TriggerBitBase> timerTriggerBitBeginCallback;

    /*
     * Callback Handler Declarations
     */
    void timerTriggerBitTickCallbackHandler();
    void timerTriggerBitBeginCallbackHandler();

};

#endif // TRIGGERBITBASE_HPP