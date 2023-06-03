#ifndef DESTRUCTOR_H_INCLUDED
#define DESTRUCTOR_H_INCLUDED
#include "Embarcaciones.h"

class Destructor : public Embarcacion{
private:
    int _Tamanio;

public:
    void setNombre();
    void setTamanio(int tamanio);
    string getNombre();
};


#endif // DESTRUCTOR_H_INCLUDED
