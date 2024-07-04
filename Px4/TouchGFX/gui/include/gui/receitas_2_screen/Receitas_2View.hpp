#ifndef RECEITAS_2VIEW_HPP
#define RECEITAS_2VIEW_HPP

#include <gui_generated/receitas_2_screen/Receitas_2ViewBase.hpp>
#include <gui/receitas_2_screen/Receitas_2Presenter.hpp>

class Receitas_2View : public Receitas_2ViewBase
{
public:
    Receitas_2View();
    virtual ~Receitas_2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_2VIEW_HPP
