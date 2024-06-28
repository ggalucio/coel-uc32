#ifndef CONFIGURACAO_4PRESENTER_HPP
#define CONFIGURACAO_4PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Configuracao_4View;

class Configuracao_4Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Configuracao_4Presenter(Configuracao_4View& v);

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

    virtual ~Configuracao_4Presenter() {};

private:
    Configuracao_4Presenter();

    Configuracao_4View& view;
};

#endif // CONFIGURACAO_4PRESENTER_HPP
