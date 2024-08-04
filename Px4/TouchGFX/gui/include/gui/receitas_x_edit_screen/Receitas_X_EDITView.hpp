#ifndef RECEITAS_X_EDITVIEW_HPP
#define RECEITAS_X_EDITVIEW_HPP

#include <gui_generated/receitas_x_edit_screen/Receitas_X_EDITViewBase.hpp>
#include <gui/receitas_x_edit_screen/Receitas_X_EDITPresenter.hpp>

class Receitas_X_EDITView : public Receitas_X_EDITViewBase
{
public:
    Receitas_X_EDITView();
    virtual ~Receitas_X_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_X_EDITVIEW_HPP
