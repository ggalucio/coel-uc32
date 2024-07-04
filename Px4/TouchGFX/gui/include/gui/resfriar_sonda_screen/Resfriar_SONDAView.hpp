#ifndef RESFRIAR_SONDAVIEW_HPP
#define RESFRIAR_SONDAVIEW_HPP

#include <gui_generated/resfriar_sonda_screen/Resfriar_SONDAViewBase.hpp>
#include <gui/resfriar_sonda_screen/Resfriar_SONDAPresenter.hpp>

class Resfriar_SONDAView : public Resfriar_SONDAViewBase
{
public:
    Resfriar_SONDAView();
    virtual ~Resfriar_SONDAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RESFRIAR_SONDAVIEW_HPP
