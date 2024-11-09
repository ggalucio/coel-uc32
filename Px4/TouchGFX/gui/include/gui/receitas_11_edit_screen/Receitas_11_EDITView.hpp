#ifndef RECEITAS_11_EDITVIEW_HPP
#define RECEITAS_11_EDITVIEW_HPP

#include <gui_generated/receitas_11_edit_screen/Receitas_11_EDITViewBase.hpp>
#include <gui/receitas_11_edit_screen/Receitas_11_EDITPresenter.hpp>

class Receitas_11_EDITView : public Receitas_11_EDITViewBase
{
public:
    Receitas_11_EDITView();
    virtual ~Receitas_11_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_11_EDITVIEW_HPP
