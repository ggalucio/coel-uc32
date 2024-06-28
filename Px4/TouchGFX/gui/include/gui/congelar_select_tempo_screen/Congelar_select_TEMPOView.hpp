#ifndef CONGELAR_SELECT_TEMPOVIEW_HPP
#define CONGELAR_SELECT_TEMPOVIEW_HPP

#include <gui_generated/congelar_select_tempo_screen/Congelar_select_TEMPOViewBase.hpp>
#include <gui/congelar_select_tempo_screen/Congelar_select_TEMPOPresenter.hpp>

class Congelar_select_TEMPOView : public Congelar_select_TEMPOViewBase
{
public:
    Congelar_select_TEMPOView();
    virtual ~Congelar_select_TEMPOView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONGELAR_SELECT_TEMPOVIEW_HPP
