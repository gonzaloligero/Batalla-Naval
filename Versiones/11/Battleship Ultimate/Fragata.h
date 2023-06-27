#ifndef FRAGATA_H_INCLUDED
#define FRAGATA_H_INCLUDED
#include "Embarcaciones.h"

class Fragata : public Embarcacion{
private:
    int _Tamanio;

public:
    Fragata();
    void setNombre();
    void setPosicion(int x,int y);
    void setRotacion(int x);
    void setTamanio(int tamanio);
    string getNombre();
    int getTamanio();

};


#endif // FRAGATA_H_INCLUDED
