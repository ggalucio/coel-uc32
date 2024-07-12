#ifndef CANCELAR_PROCESSO_HPP
#define CANCELAR_PROCESSO_HPP

#include <gui_generated/containers/CANCELAR_PROCESSOBase.hpp>

class CANCELAR_PROCESSO : public CANCELAR_PROCESSOBase
{
public:
    CANCELAR_PROCESSO();
    virtual ~CANCELAR_PROCESSO() {}

    virtual void initialize();
protected:
};

#endif // CANCELAR_PROCESSO_HPP
