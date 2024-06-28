#ifndef INICIALIZACAOPRESENTER_HPP
#define INICIALIZACAOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

extern double countTicksEventInicializacao;

class InicializacaoView;

class InicializacaoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    InicializacaoPresenter(InicializacaoView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~InicializacaoPresenter() {};

private:
    InicializacaoPresenter();

    InicializacaoView& view;
};

#endif // INICIALIZACAOPRESENTER_HPP
