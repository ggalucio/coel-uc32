#include <gui/congelar_screen/CongelarView.hpp>
#include <gui/congelar_screen/CongelarPresenter.hpp>

int selectModeCongelar = 0;

CongelarPresenter::CongelarPresenter(CongelarView& v)
    : view(v)
{

}

void CongelarPresenter::activate()
{
	view.setModeValue(selectModeCongelar);
}

void CongelarPresenter::deactivate()
{
	selectModeCongelar = view.getModeValue();
}
