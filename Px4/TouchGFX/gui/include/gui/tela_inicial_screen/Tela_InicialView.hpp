#ifndef TELA_INICIALVIEW_HPP
#define TELA_INICIALVIEW_HPP

#include <gui_generated/tela_inicial_screen/Tela_InicialViewBase.hpp>
#include <gui/tela_inicial_screen/Tela_InicialPresenter.hpp>

class Tela_InicialView : public Tela_InicialViewBase
{
public:
    Tela_InicialView();
    virtual ~Tela_InicialView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TELA_INICIALVIEW_HPP
