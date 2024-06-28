#ifndef DEGELO_CONFIRMARPRESENTER_HPP
#define DEGELO_CONFIRMARPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Degelo_ConfirmarView;

class Degelo_ConfirmarPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Degelo_ConfirmarPresenter(Degelo_ConfirmarView& v);

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

    virtual ~Degelo_ConfirmarPresenter() {};

private:
    Degelo_ConfirmarPresenter();

    Degelo_ConfirmarView& view;
};

#endif // DEGELO_CONFIRMARPRESENTER_HPP
