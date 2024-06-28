#ifndef ALARMCENTERCONTAINER_HPP
#define ALARMCENTERCONTAINER_HPP

#include <gui_generated/containers/alarmCenterContainerBase.hpp>

class alarmCenterContainer : public alarmCenterContainerBase
{
public:
    alarmCenterContainer();
    virtual ~alarmCenterContainer() {}

    virtual void initialize();
    virtual void update();
protected:
};

#endif // ALARMCENTERCONTAINER_HPP
