#ifndef RESFRIAR_TEMPOPRESENTER_HPP
#define RESFRIAR_TEMPOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Resfriar_TEMPOView;

class Resfriar_TEMPOPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Resfriar_TEMPOPresenter(Resfriar_TEMPOView& v);

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

    virtual ~Resfriar_TEMPOPresenter() {};

private:
    Resfriar_TEMPOPresenter();

    Resfriar_TEMPOView& view;
};

#endif // RESFRIAR_TEMPOPRESENTER_HPP
