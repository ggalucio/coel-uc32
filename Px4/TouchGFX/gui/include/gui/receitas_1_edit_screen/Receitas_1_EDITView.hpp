#ifndef RECEITAS_1_EDITVIEW_HPP
#define RECEITAS_1_EDITVIEW_HPP

#include <gui_generated/receitas_1_edit_screen/Receitas_1_EDITViewBase.hpp>
#include <gui/receitas_1_edit_screen/Receitas_1_EDITPresenter.hpp>

class Receitas_1_EDITView : public Receitas_1_EDITViewBase
{
public:
    Receitas_1_EDITView();
    virtual ~Receitas_1_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_1_EDITVIEW_HPP
