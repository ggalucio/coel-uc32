#ifndef KEYBOARDCONTAINER_HPP
#define KEYBOARDCONTAINER_HPP

#include <gui_generated/containers/keyboardContainerBase.hpp>

class keyboardContainer : public keyboardContainerBase
{
public:
    keyboardContainer();
    virtual ~keyboardContainer() {}
    virtual void initialize();

    virtual void shiftPressed();
    virtual void numPressed();
protected:
    bool uppercaseKeys;
    bool numcaseKeys;

    void InvalidateAll();
};

#endif // KEYBOARDCONTAINER_HPP
