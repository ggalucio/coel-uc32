#ifndef CONGELAR_TEMPOVIEW_HPP
#define CONGELAR_TEMPOVIEW_HPP

#include <gui_generated/congelar_tempo_screen/Congelar_TEMPOViewBase.hpp>
#include <gui/congelar_tempo_screen/Congelar_TEMPOPresenter.hpp>

class Congelar_TEMPOView : public Congelar_TEMPOViewBase
{
public:
    Congelar_TEMPOView();
    virtual ~Congelar_TEMPOView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONGELAR_TEMPOVIEW_HPP
