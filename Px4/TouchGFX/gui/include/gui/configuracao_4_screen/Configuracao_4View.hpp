#ifndef CONFIGURACAO_4VIEW_HPP
#define CONFIGURACAO_4VIEW_HPP

#include <gui_generated/configuracao_4_screen/Configuracao_4ViewBase.hpp>
#include <gui/configuracao_4_screen/Configuracao_4Presenter.hpp>

class Configuracao_4View : public Configuracao_4ViewBase
{
public:
    Configuracao_4View();
    virtual ~Configuracao_4View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONFIGURACAO_4VIEW_HPP
