#ifndef RECEITAS_1PRESENTER_HPP
#define RECEITAS_1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receitas_1View;

class Receitas_1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receitas_1Presenter(Receitas_1View& v);

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

    virtual ~Receitas_1Presenter() {};

private:
    Receitas_1Presenter();

    Receitas_1View& view;
};

#endif // RECEITAS_1PRESENTER_HPP
