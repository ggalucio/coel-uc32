#ifndef RESFRIAR_TEMPOVIEW_HPP
#define RESFRIAR_TEMPOVIEW_HPP

#include <gui_generated/resfriar_tempo_screen/Resfriar_TEMPOViewBase.hpp>
#include <gui/resfriar_tempo_screen/Resfriar_TEMPOPresenter.hpp>

class Resfriar_TEMPOView : public Resfriar_TEMPOViewBase
{
public:
    Resfriar_TEMPOView();
    virtual ~Resfriar_TEMPOView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RESFRIAR_TEMPOVIEW_HPP
