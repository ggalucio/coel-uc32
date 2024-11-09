#ifndef SCREENMANAGEMENT_HPP
#define SCREENMANAGEMENT_HPP

#include <gui_generated/containers/ScreenManagementBase.hpp>

class ScreenManagement : public ScreenManagementBase
{
public:
    ScreenManagement();
    virtual ~ScreenManagement() {}

    virtual void initialize();
protected:
};

#endif // SCREENMANAGEMENT_HPP
