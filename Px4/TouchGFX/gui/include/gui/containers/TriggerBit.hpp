#ifndef TRIGGERBIT_HPP
#define TRIGGERBIT_HPP

#include <gui_generated/containers/TriggerBitBase.hpp>

class TriggerBit : public TriggerBitBase
{
public:
    TriggerBit();
    virtual ~TriggerBit() {}

    virtual void initialize();
protected:
};

#endif // TRIGGERBIT_HPP
