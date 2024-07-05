#ifndef RECEITAS_3PRESENTER_HPP
#define RECEITAS_3PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receitas_3View;

class Receitas_3Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receitas_3Presenter(Receitas_3View& v);

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

    virtual ~Receitas_3Presenter() {};

private:
    Receitas_3Presenter();

    Receitas_3View& view;
};

#endif // RECEITAS_3PRESENTER_HPP
