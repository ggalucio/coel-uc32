#ifndef RESET_FABRICAPRESENTER_HPP
#define RESET_FABRICAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class RESET_FABRICAView;

class RESET_FABRICAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    RESET_FABRICAPresenter(RESET_FABRICAView& v);

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

    virtual ~RESET_FABRICAPresenter() {};

private:
    RESET_FABRICAPresenter();

    RESET_FABRICAView& view;
};

#endif // RESET_FABRICAPRESENTER_HPP
