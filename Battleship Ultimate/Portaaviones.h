#ifndef PORTAAVIONES_H_INCLUDED
#define PORTAAVIONES_H_INCLUDED
#include "Embarcaciones.h"

class Portaaviones : public Embarcacion{
private:
    int _Tamanio;

public:
    void setNombre();
    void setTamanio(int tamanio);

};

#endif // PORTAAVIONES_H_INCLUDED
