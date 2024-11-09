#ifndef MONITORMODBUSSCREENPRESENTER_HPP
#define MONITORMODBUSSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MonitorModbusScreenView;

class MonitorModbusScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MonitorModbusScreenPresenter(MonitorModbusScreenView& v);

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

    virtual ~MonitorModbusScreenPresenter() {};

private:
    MonitorModbusScreenPresenter();

    MonitorModbusScreenView& view;
};

#endif // MONITORMODBUSSCREENPRESENTER_HPP
