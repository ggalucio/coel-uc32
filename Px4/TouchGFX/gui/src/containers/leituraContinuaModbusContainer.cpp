#include <gui/containers/leituraContinuaModbusContainer.hpp>

leituraContinuaModbusContainer::leituraContinuaModbusContainer()
{
	Application::getInstance()->registerTimerWidget(this);
}

void leituraContinuaModbusContainer::initialize()
{
    leituraContinuaModbusContainerBase::initialize();
    init();
}
