#ifndef TIMING_HPP
#define TIMING_HPP

#include <gui_generated/containers/TimingBase.hpp>

class Timing : public TimingBase
{
public:
    Timing();
    virtual ~Timing() {}
    virtual void initialize();

protected:
};

#endif // TIMING_HPP
