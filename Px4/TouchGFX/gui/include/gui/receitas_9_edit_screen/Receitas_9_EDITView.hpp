#ifndef RECEITAS_9_EDITVIEW_HPP
#define RECEITAS_9_EDITVIEW_HPP

#include <gui_generated/receitas_9_edit_screen/Receitas_9_EDITViewBase.hpp>
#include <gui/receitas_9_edit_screen/Receitas_9_EDITPresenter.hpp>

class Receitas_9_EDITView : public Receitas_9_EDITViewBase
{
public:
    Receitas_9_EDITView();
    virtual ~Receitas_9_EDITView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_9_EDITVIEW_HPP
