#ifndef RESFRIARVIEW_HPP
#define RESFRIARVIEW_HPP

#include <gui_generated/resfriar_screen/ResfriarViewBase.hpp>
#include <gui/resfriar_screen/ResfriarPresenter.hpp>

class ResfriarView : public ResfriarViewBase
{
public:
    ResfriarView();
    virtual ~ResfriarView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RESFRIARVIEW_HPP
