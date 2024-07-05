#ifndef RESFRIAR_SONDAPRESENTER_HPP
#define RESFRIAR_SONDAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Resfriar_SONDAView;

class Resfriar_SONDAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Resfriar_SONDAPresenter(Resfriar_SONDAView& v);

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

    virtual ~Resfriar_SONDAPresenter() {};

private:
    Resfriar_SONDAPresenter();

    Resfriar_SONDAView& view;
};

#endif // RESFRIAR_SONDAPRESENTER_HPP
