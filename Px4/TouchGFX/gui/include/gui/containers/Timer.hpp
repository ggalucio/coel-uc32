#ifndef TIMER_HPP
#define TIMER_HPP

#include <gui_generated/containers/TimerBase.hpp>

void TickRefreshTimers(void);

/*
 * Temporizador.
 * */
class Timer : public TimerBase
{
public:
    Timer();
    virtual ~Timer() { finalize(); }
    virtual void initialize();
    virtual void finalize();

    /*
     * Definir o tempo de espera a cada evento de Tick.
     *
     * */
    virtual void setWaitTime(uint32_t value);

    /*
     * Inicializar o temporizdor.
     * */
    virtual void start();

    /*
     * Finalizar o temporizador.
     * */
    virtual void stop();

protected:

    friend void RefreshTimers();

    uint32_t DELTA = 100;
    uint32_t countTickModel = 0;

    bool enable = false;

    /*
     * Atualizar o temporizador.
     * */
    void refresh()
    {
    	if (enable)
    	{
    		if (countTickModel >= DELTA)
    		{
    			countTickModel = 0;
    			emitTickCallback();
    		}
    		else
    			countTickModel += 16;
    	}
    	else
    		countTickModel = 0;
    }

    /*
     * Inicialização de container.
     * */
    void begin()
    {
    	emitBeginCallback();
    }
};

#endif // TIMER_HPP
