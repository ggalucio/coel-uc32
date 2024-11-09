#include <gui/degelo_screen/DegeloView.hpp>
#include <gui/degelo_screen/DegeloPresenter.hpp>

int tickCountCycle100 = 0;

DegeloPresenter::DegeloPresenter(DegeloView& v)
    : view(v)
{

}

void DegeloPresenter::activate()
{

}

void DegeloPresenter::deactivate()
{
	tickCountCycle100 = 0;
}
