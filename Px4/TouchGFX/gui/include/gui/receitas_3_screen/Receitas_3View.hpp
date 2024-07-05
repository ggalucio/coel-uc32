#ifndef RECEITAS_3VIEW_HPP
#define RECEITAS_3VIEW_HPP

#include <gui_generated/receitas_3_screen/Receitas_3ViewBase.hpp>
#include <gui/receitas_3_screen/Receitas_3Presenter.hpp>

class Receitas_3View : public Receitas_3ViewBase
{
public:
    Receitas_3View();
    virtual ~Receitas_3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITAS_3VIEW_HPP
