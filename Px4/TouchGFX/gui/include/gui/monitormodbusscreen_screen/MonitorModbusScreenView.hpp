#ifndef MONITORMODBUSSCREENVIEW_HPP
#define MONITORMODBUSSCREENVIEW_HPP

#include <gui_generated/monitormodbusscreen_screen/MonitorModbusScreenViewBase.hpp>
#include <gui/monitormodbusscreen_screen/MonitorModbusScreenPresenter.hpp>

class MonitorModbusScreenView : public MonitorModbusScreenViewBase
{
public:
    MonitorModbusScreenView();
    virtual ~MonitorModbusScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MONITORMODBUSSCREENVIEW_HPP
