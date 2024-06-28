#ifndef INICIALIZACAOVIEW_HPP
#define INICIALIZACAOVIEW_HPP

#include <gui_generated/inicializacao_screen/InicializacaoViewBase.hpp>
#include <gui/inicializacao_screen/InicializacaoPresenter.hpp>

class InicializacaoView : public InicializacaoViewBase
{
public:
    InicializacaoView();
    virtual ~InicializacaoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INICIALIZACAOVIEW_HPP
