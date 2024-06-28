#ifndef CONFIGURACAO_5VIEW_HPP
#define CONFIGURACAO_5VIEW_HPP

#include <gui_generated/configuracao_5_screen/Configuracao_5ViewBase.hpp>
#include <gui/configuracao_5_screen/Configuracao_5Presenter.hpp>

class Configuracao_5View : public Configuracao_5ViewBase
{
public:
    Configuracao_5View();
    virtual ~Configuracao_5View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONFIGURACAO_5VIEW_HPP
