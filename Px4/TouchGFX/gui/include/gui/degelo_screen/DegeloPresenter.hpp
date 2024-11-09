#ifndef DEGELOPRESENTER_HPP
#define DEGELOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

extern int tickCountCycle100;

class DegeloView;

class DegeloPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DegeloPresenter(DegeloView& v);

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

    virtual ~DegeloPresenter() {};

private:
    DegeloPresenter();

    DegeloView& view;
};

#endif // DEGELOPRESENTER_HPP
