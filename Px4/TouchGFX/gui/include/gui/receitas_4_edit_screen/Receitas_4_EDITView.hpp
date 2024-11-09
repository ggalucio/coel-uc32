#ifndef RECEITAS_4_EDITVIEW_HPP
#define RECEITAS_4_EDITVIEW_HPP

#include <gui_generated/receitas_4_edit_screen/Receitas_4_EDITViewBase.hpp>
#include <gui/receitas_4_edit_screen/Receitas_4_EDITPresenter.hpp>

class Receitas_4_EDITView : public Receitas_4_EDITViewBase
{
public:
    Receitas_4_EDITView();
    virtual ~Receitas_4_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_4_EDITVIEW_HPP
