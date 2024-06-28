#include <gui/congelar_screen/CongelarView.hpp>

CongelarView::CongelarView()
{

}

void CongelarView::setupScreen()
{
    CongelarViewBase::setupScreen();
}

void CongelarView::tearDownScreen()
{
    CongelarViewBase::tearDownScreen();
}

int CongelarView::getModeValue()
{
	return radioButtonGroup1.getSelectedRadioButtonIndex();
}

void CongelarView::setModeValue(int index)
{
	Update(radioButtonGroup1.getRadioButton(index), true);
}
