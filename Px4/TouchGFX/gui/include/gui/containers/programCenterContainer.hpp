#ifndef PROGRAMCENTERCONTAINER_HPP
#define PROGRAMCENTERCONTAINER_HPP

#include <gui_generated/containers/programCenterContainerBase.hpp>

class programCenterContainer : public programCenterContainerBase
{
public:
    programCenterContainer();
    virtual ~programCenterContainer() {}

    virtual void initialize();
    virtual void update(int idx);
protected:
};

#endif // PROGRAMCENTERCONTAINER_HPP
