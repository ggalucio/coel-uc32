#ifndef RECEITAS_1VIEW_HPP
#define RECEITAS_1VIEW_HPP

#include <gui_generated/receitas_1_screen/Receitas_1ViewBase.hpp>
#include <gui/receitas_1_screen/Receitas_1Presenter.hpp>

class Receitas_1View : public Receitas_1ViewBase
{
public:
    Receitas_1View();
    virtual ~Receitas_1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_1VIEW_HPP
