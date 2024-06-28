#ifndef CONFIGURACAO_3VIEW_HPP
#define CONFIGURACAO_3VIEW_HPP

#include <gui_generated/configuracao_3_screen/Configuracao_3ViewBase.hpp>
#include <gui/configuracao_3_screen/Configuracao_3Presenter.hpp>

class Configuracao_3View : public Configuracao_3ViewBase
{
public:
    Configuracao_3View();
    virtual ~Configuracao_3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONFIGURACAO_3VIEW_HPP
