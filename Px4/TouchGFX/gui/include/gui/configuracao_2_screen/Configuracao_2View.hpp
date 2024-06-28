#ifndef CONFIGURACAO_2VIEW_HPP
#define CONFIGURACAO_2VIEW_HPP

#include <gui_generated/configuracao_2_screen/Configuracao_2ViewBase.hpp>
#include <gui/configuracao_2_screen/Configuracao_2Presenter.hpp>

class Configuracao_2View : public Configuracao_2ViewBase
{
public:
    Configuracao_2View();
    virtual ~Configuracao_2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONFIGURACAO_2VIEW_HPP
