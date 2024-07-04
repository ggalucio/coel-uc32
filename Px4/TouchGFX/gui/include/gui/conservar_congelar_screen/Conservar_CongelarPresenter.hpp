#ifndef CONSERVAR_CONGELARPRESENTER_HPP
#define CONSERVAR_CONGELARPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Conservar_CongelarView;

class Conservar_CongelarPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Conservar_CongelarPresenter(Conservar_CongelarView& v);

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

    virtual ~Conservar_CongelarPresenter() {};

private:
    Conservar_CongelarPresenter();

    Conservar_CongelarView& view;
};

#endif // CONSERVAR_CONGELARPRESENTER_HPP
