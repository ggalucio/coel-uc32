#ifndef KEYBOARDCONTAINER2_HPP
#define KEYBOARDCONTAINER2_HPP

#include <gui_generated/containers/keyboardContainer2Base.hpp>

class keyboardContainer2 : public keyboardContainer2Base
{
public:
    keyboardContainer2();
    virtual ~keyboardContainer2() {}
    virtual void initialize();
    void restore();

    virtual void shiftPressed();
    virtual void numPressed();
protected:
    bool uppercaseKeys;
    bool numcaseKeys;

    void InvalidateAll();
};

#endif // KEYBOARDCONTAINER2_HPP
