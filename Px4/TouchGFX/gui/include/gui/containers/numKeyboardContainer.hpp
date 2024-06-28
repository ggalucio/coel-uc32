#ifndef NUMKEYBOARDCONTAINER_HPP
#define NUMKEYBOARDCONTAINER_HPP

#include <gui_generated/containers/numKeyboardContainerBase.hpp>

class numKeyboardContainer : public numKeyboardContainerBase
{
public:
    numKeyboardContainer();
    virtual ~numKeyboardContainer() {}

    virtual void initialize();
protected:
};

#endif // NUMKEYBOARDCONTAINER_HPP
