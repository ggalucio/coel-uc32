#ifndef CONGELAR_SONDAVIEW_HPP
#define CONGELAR_SONDAVIEW_HPP

#include <gui_generated/congelar_sonda_screen/Congelar_SONDAViewBase.hpp>
#include <gui/congelar_sonda_screen/Congelar_SONDAPresenter.hpp>

class Congelar_SONDAView : public Congelar_SONDAViewBase
{
public:
    Congelar_SONDAView();
    virtual ~Congelar_SONDAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONGELAR_SONDAVIEW_HPP
