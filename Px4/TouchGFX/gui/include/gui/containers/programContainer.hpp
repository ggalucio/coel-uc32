#ifndef PROGRAMCONTAINER_HPP
#define PROGRAMCONTAINER_HPP

#include <gui_generated/containers/programContainerBase.hpp>

class programContainer : public programContainerBase
{
public:
    programContainer();
    virtual ~programContainer() {}

    virtual void initialize();
    virtual void update(int idx);
protected:
};

#endif // PROGRAMCONTAINER_HPP
