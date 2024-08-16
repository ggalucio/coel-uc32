#ifndef TIMINGAPPLICATION_HPP
#define TIMINGAPPLICATION_HPP

#include <gui_generated/containers/TimingApplicationBase.hpp>

class TimingApplication : public TimingApplicationBase
{
public:
    TimingApplication();
    virtual ~TimingApplication() {}

    virtual void initialize();
protected:
};

#endif // TIMINGAPPLICATION_HPP
