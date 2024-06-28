#ifndef CONFIGURACAO_5PRESENTER_HPP
#define CONFIGURACAO_5PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Configuracao_5View;

class Configuracao_5Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Configuracao_5Presenter(Configuracao_5View& v);

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

    virtual ~Configuracao_5Presenter() {};

private:
    Configuracao_5Presenter();

    Configuracao_5View& view;
};

#endif // CONFIGURACAO_5PRESENTER_HPP
