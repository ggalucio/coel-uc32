#ifndef RECEITAS_7_EDITVIEW_HPP
#define RECEITAS_7_EDITVIEW_HPP

#include <gui_generated/receitas_7_edit_screen/Receitas_7_EDITViewBase.hpp>
#include <gui/receitas_7_edit_screen/Receitas_7_EDITPresenter.hpp>

class Receitas_7_EDITView : public Receitas_7_EDITViewBase
{
public:
    Receitas_7_EDITView();
    virtual ~Receitas_7_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_7_EDITVIEW_HPP
