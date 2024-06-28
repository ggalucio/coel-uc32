#ifndef CONFIGURACAO_6VIEW_HPP
#define CONFIGURACAO_6VIEW_HPP

#include <gui_generated/configuracao_6_screen/Configuracao_6ViewBase.hpp>
#include <gui/configuracao_6_screen/Configuracao_6Presenter.hpp>

class Configuracao_6View : public Configuracao_6ViewBase
{
public:
    Configuracao_6View();
    virtual ~Configuracao_6View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONFIGURACAO_6VIEW_HPP
