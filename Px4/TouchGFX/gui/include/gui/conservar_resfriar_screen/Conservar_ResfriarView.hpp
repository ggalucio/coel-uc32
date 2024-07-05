#ifndef CONSERVAR_RESFRIARVIEW_HPP
#define CONSERVAR_RESFRIARVIEW_HPP

#include <gui_generated/conservar_resfriar_screen/Conservar_ResfriarViewBase.hpp>
#include <gui/conservar_resfriar_screen/Conservar_ResfriarPresenter.hpp>

class Conservar_ResfriarView : public Conservar_ResfriarViewBase
{
public:
    Conservar_ResfriarView();
    virtual ~Conservar_ResfriarView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONSERVAR_RESFRIARVIEW_HPP
