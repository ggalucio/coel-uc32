#ifndef CONSERVAR_CONGELARVIEW_HPP
#define CONSERVAR_CONGELARVIEW_HPP

#include <gui_generated/conservar_congelar_screen/Conservar_CongelarViewBase.hpp>
#include <gui/conservar_congelar_screen/Conservar_CongelarPresenter.hpp>

class Conservar_CongelarView : public Conservar_CongelarViewBase
{
public:
    Conservar_CongelarView();
    virtual ~Conservar_CongelarView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONSERVAR_CONGELARVIEW_HPP
