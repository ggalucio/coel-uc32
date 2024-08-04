#ifndef CONGELARVIEW_HPP
#define CONGELARVIEW_HPP

#include <gui_generated/congelar_screen/CongelarViewBase.hpp>
#include <gui/congelar_screen/CongelarPresenter.hpp>

class CongelarView : public CongelarViewBase
{
public:
    CongelarView();
    virtual ~CongelarView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONGELARVIEW_HPP
