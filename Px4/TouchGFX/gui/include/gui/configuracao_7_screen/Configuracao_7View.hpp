#ifndef CONFIGURACAO_7VIEW_HPP
#define CONFIGURACAO_7VIEW_HPP

#include <gui_generated/configuracao_7_screen/Configuracao_7ViewBase.hpp>
#include <gui/configuracao_7_screen/Configuracao_7Presenter.hpp>

class Configuracao_7View : public Configuracao_7ViewBase
{
public:
    Configuracao_7View();
    virtual ~Configuracao_7View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONFIGURACAO_7VIEW_HPP
