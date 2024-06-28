#ifndef CONFIGURACAO_7PRESENTER_HPP
#define CONFIGURACAO_7PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Configuracao_7View;

class Configuracao_7Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Configuracao_7Presenter(Configuracao_7View& v);

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

    virtual ~Configuracao_7Presenter() {};

private:
    Configuracao_7Presenter();

    Configuracao_7View& view;
};

#endif // CONFIGURACAO_7PRESENTER_HPP
