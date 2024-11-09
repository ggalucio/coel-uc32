#ifndef RECEITAS_5_EDITVIEW_HPP
#define RECEITAS_5_EDITVIEW_HPP

#include <gui_generated/receitas_5_edit_screen/Receitas_5_EDITViewBase.hpp>
#include <gui/receitas_5_edit_screen/Receitas_5_EDITPresenter.hpp>

class Receitas_5_EDITView : public Receitas_5_EDITViewBase
{
public:
    Receitas_5_EDITView();
    virtual ~Receitas_5_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_5_EDITVIEW_HPP
