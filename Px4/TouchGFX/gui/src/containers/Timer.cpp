#include <gui/containers/Timer.hpp>

Timer* timer[20];
int nTimers = 0;

/*
 * Adicionar uma nova intância Timer na lista.
 * */
void addTimerContainer(Timer* t){
	if (nTimers == 20)
		return;

	timer[nTimers] = t;
	nTimers ++;
}

/*
 * Remover todos os Timer da lista.
 * */
void clearTimerContainer(){
	nTimers = 0;
}

/*
 * Atualizar lista de Timer.
 * */
void RefreshTimers(){
	if (nTimers == 0)
		return;

	int i;
	for (i=0; i<nTimers; i++)
		timer[i]->refresh();
}

void TickRefreshTimers(){
	RefreshTimers();
}

Timer::Timer()
{

}

void Timer::initialize()
{
    TimerBase::initialize();
    addTimerContainer(this);
    begin();
}

void Timer::finalize()
{
	clearTimerContainer();
}

void Timer::setWaitTime(uint32_t value)
{
	DELTA = value;
}

void Timer::start()
{
	enable = true;
}

void Timer::stop()
{
	enable = false;
}
