#ifndef CONSERVAR_RESFRIARPRESENTER_HPP
#define CONSERVAR_RESFRIARPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Conservar_ResfriarView;

class Conservar_ResfriarPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Conservar_ResfriarPresenter(Conservar_ResfriarView& v);

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

    virtual ~Conservar_ResfriarPresenter() {};

private:
    Conservar_ResfriarPresenter();

    Conservar_ResfriarView& view;
};

#endif // CONSERVAR_RESFRIARPRESENTER_HPP
