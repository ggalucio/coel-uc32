#ifndef RECEITAS_8_EDITVIEW_HPP
#define RECEITAS_8_EDITVIEW_HPP

#include <gui_generated/receitas_8_edit_screen/Receitas_8_EDITViewBase.hpp>
#include <gui/receitas_8_edit_screen/Receitas_8_EDITPresenter.hpp>

class Receitas_8_EDITView : public Receitas_8_EDITViewBase
{
public:
    Receitas_8_EDITView();
    virtual ~Receitas_8_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_8_EDITVIEW_HPP
