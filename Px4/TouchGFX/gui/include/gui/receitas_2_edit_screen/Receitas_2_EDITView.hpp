#ifndef RECEITAS_2_EDITVIEW_HPP
#define RECEITAS_2_EDITVIEW_HPP

#include <gui_generated/receitas_2_edit_screen/Receitas_2_EDITViewBase.hpp>
#include <gui/receitas_2_edit_screen/Receitas_2_EDITPresenter.hpp>

class Receitas_2_EDITView : public Receitas_2_EDITViewBase
{
public:
    Receitas_2_EDITView();
    virtual ~Receitas_2_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_2_EDITVIEW_HPP
