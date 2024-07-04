#ifndef RECEITAS_2PRESENTER_HPP
#define RECEITAS_2PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receitas_2View;

class Receitas_2Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receitas_2Presenter(Receitas_2View& v);

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

    virtual ~Receitas_2Presenter() {};

private:
    Receitas_2Presenter();

    Receitas_2View& view;
};

#endif // RECEITAS_2PRESENTER_HPP
