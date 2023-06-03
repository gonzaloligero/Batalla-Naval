#ifndef FRAGATA_H_INCLUDED
#define FRAGATA_H_INCLUDED
#include "Embarcaciones.h"

class Fragata : public Embarcacion{
private:
    int _Tamanio;

public:
    void setNombre();
    void setTamanio(int tamanio);

};


#endif // FRAGATA_H_INCLUDED
