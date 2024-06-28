#ifndef CONGELAR_SELECT_TEMPOPRESENTER_HPP
#define CONGELAR_SELECT_TEMPOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Congelar_select_TEMPOView;

class Congelar_select_TEMPOPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Congelar_select_TEMPOPresenter(Congelar_select_TEMPOView& v);

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

    virtual ~Congelar_select_TEMPOPresenter() {};

private:
    Congelar_select_TEMPOPresenter();

    Congelar_select_TEMPOView& view;
};

#endif // CONGELAR_SELECT_TEMPOPRESENTER_HPP
