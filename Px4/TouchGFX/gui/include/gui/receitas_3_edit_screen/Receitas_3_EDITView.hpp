#ifndef RECEITAS_3_EDITVIEW_HPP
#define RECEITAS_3_EDITVIEW_HPP

#include <gui_generated/receitas_3_edit_screen/Receitas_3_EDITViewBase.hpp>
#include <gui/receitas_3_edit_screen/Receitas_3_EDITPresenter.hpp>

class Receitas_3_EDITView : public Receitas_3_EDITViewBase
{
public:
    Receitas_3_EDITView();
    virtual ~Receitas_3_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_3_EDITVIEW_HPP
