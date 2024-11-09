#ifndef PORTAABERTASINALIZADOR_HPP
#define PORTAABERTASINALIZADOR_HPP

#include <gui_generated/containers/portaAbertaSinalizadorBase.hpp>

class portaAbertaSinalizador : public portaAbertaSinalizadorBase
{
public:
    portaAbertaSinalizador();
    virtual ~portaAbertaSinalizador() {}

    virtual void initialize();
protected:
};

#endif // PORTAABERTASINALIZADOR_HPP
