#ifndef ACORAZADO_H_INCLUDED
#define ACORAZADO_H_INCLUDED
#include "Embarcaciones.h"

class Acorazado : public Embarcacion{
private:
    int _Tamanio;

public:
    void setNombre();
    void setTamanio(int tamanio);

};

#endif // ACORAZADO_H_INCLUDED
