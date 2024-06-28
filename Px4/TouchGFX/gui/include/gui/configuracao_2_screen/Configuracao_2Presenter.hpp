#ifndef CONFIGURACAO_2PRESENTER_HPP
#define CONFIGURACAO_2PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Configuracao_2View;

class Configuracao_2Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Configuracao_2Presenter(Configuracao_2View& v);

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

    virtual ~Configuracao_2Presenter() {};

private:
    Configuracao_2Presenter();

    Configuracao_2View& view;
};

#endif // CONFIGURACAO_2PRESENTER_HPP
