#ifndef RECEITAS_6_EDITVIEW_HPP
#define RECEITAS_6_EDITVIEW_HPP

#include <gui_generated/receitas_6_edit_screen/Receitas_6_EDITViewBase.hpp>
#include <gui/receitas_6_edit_screen/Receitas_6_EDITPresenter.hpp>

class Receitas_6_EDITView : public Receitas_6_EDITViewBase
{
public:
    Receitas_6_EDITView();
    virtual ~Receitas_6_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_6_EDITVIEW_HPP
