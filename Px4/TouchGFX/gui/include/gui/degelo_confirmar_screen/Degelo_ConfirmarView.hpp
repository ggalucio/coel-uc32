#ifndef DEGELO_CONFIRMARVIEW_HPP
#define DEGELO_CONFIRMARVIEW_HPP

#include <gui_generated/degelo_confirmar_screen/Degelo_ConfirmarViewBase.hpp>
#include <gui/degelo_confirmar_screen/Degelo_ConfirmarPresenter.hpp>

class Degelo_ConfirmarView : public Degelo_ConfirmarViewBase
{
public:
    Degelo_ConfirmarView();
    virtual ~Degelo_ConfirmarView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DEGELO_CONFIRMARVIEW_HPP
