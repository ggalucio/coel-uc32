#ifndef ALARMCONTAINER_HPP
#define ALARMCONTAINER_HPP

#include <gui_generated/containers/alarmContainerBase.hpp>

class alarmContainer : public alarmContainerBase
{
public:
    alarmContainer();
    virtual ~alarmContainer() {}

    virtual void initialize();
    virtual void update(int idx);
    virtual touchgfx::TextAreaWithOneWildcard * getTxtAlarm();
    virtual touchgfx::Unicode::UnicodeChar* getTxtAlarmBuff();
    virtual int* getIndex();
    virtual void setIndex(int idx);
protected:
    int index = 0;
};

#endif // ALARMCONTAINER_HPP
