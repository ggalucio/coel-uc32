#ifndef HIGIENEPRESENTER_HPP
#define HIGIENEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class HIGIENEView;

class HIGIENEPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    HIGIENEPresenter(HIGIENEView& v);

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

    virtual ~HIGIENEPresenter() {};

private:
    HIGIENEPresenter();

    HIGIENEView& view;
};

#endif // HIGIENEPRESENTER_HPP
