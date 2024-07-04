#ifndef RECEITA_CONFIRMVIEW_HPP
#define RECEITA_CONFIRMVIEW_HPP

#include <gui_generated/receita_confirm_screen/Receita_confirmViewBase.hpp>
#include <gui/receita_confirm_screen/Receita_confirmPresenter.hpp>

class Receita_confirmView : public Receita_confirmViewBase
{
public:
    Receita_confirmView();
    virtual ~Receita_confirmView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITA_CONFIRMVIEW_HPP
