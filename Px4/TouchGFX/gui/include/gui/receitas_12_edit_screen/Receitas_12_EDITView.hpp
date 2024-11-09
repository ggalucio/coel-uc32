#ifndef RECEITAS_12_EDITVIEW_HPP
#define RECEITAS_12_EDITVIEW_HPP

#include <gui_generated/receitas_12_edit_screen/Receitas_12_EDITViewBase.hpp>
#include <gui/receitas_12_edit_screen/Receitas_12_EDITPresenter.hpp>

class Receitas_12_EDITView : public Receitas_12_EDITViewBase
{
public:
    Receitas_12_EDITView();
    virtual ~Receitas_12_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_12_EDITVIEW_HPP
