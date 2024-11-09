#ifndef RECEITAS_10_EDITVIEW_HPP
#define RECEITAS_10_EDITVIEW_HPP

#include <gui_generated/receitas_10_edit_screen/Receitas_10_EDITViewBase.hpp>
#include <gui/receitas_10_edit_screen/Receitas_10_EDITPresenter.hpp>

class Receitas_10_EDITView : public Receitas_10_EDITViewBase
{
public:
    Receitas_10_EDITView();
    virtual ~Receitas_10_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_10_EDITVIEW_HPP
