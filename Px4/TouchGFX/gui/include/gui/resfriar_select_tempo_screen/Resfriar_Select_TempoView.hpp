#ifndef RESFRIAR_SELECT_TEMPOVIEW_HPP
#define RESFRIAR_SELECT_TEMPOVIEW_HPP

#include <gui_generated/resfriar_select_tempo_screen/Resfriar_Select_TempoViewBase.hpp>
#include <gui/resfriar_select_tempo_screen/Resfriar_Select_TempoPresenter.hpp>

class Resfriar_Select_TempoView : public Resfriar_Select_TempoViewBase
{
public:
    Resfriar_Select_TempoView();
    virtual ~Resfriar_Select_TempoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RESFRIAR_SELECT_TEMPOVIEW_HPP
