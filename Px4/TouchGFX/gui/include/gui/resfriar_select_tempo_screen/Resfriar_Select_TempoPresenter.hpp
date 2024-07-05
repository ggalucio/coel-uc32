#ifndef RESFRIAR_SELECT_TEMPOPRESENTER_HPP
#define RESFRIAR_SELECT_TEMPOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Resfriar_Select_TempoView;

class Resfriar_Select_TempoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Resfriar_Select_TempoPresenter(Resfriar_Select_TempoView& v);

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

    virtual ~Resfriar_Select_TempoPresenter() {};

private:
    Resfriar_Select_TempoPresenter();

    Resfriar_Select_TempoView& view;
};

#endif // RESFRIAR_SELECT_TEMPOPRESENTER_HPP
