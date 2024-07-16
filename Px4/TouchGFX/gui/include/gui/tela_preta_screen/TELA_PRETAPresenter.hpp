#ifndef TELA_PRETAPRESENTER_HPP
#define TELA_PRETAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TELA_PRETAView;

class TELA_PRETAPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TELA_PRETAPresenter(TELA_PRETAView& v);

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

    virtual ~TELA_PRETAPresenter() {};

private:
    TELA_PRETAPresenter();

    TELA_PRETAView& view;
};

#endif // TELA_PRETAPRESENTER_HPP
