#ifndef SUBMARINO_H_INCLUDED
#define SUBMARINO_H_INCLUDED
#include "Embarcaciones.h"

class Submarino : public Embarcacion{
private:
    int _Tamanio;

public:
    Submarino();
    void setPosicion(int x,int y);
    void setNombre();
    void setTamanio(int tamanio);
    int getTamanio();
    string getNombre();
    void setRotacion(int x);

};

#endif // SUBMARINO_H_INCLUDED
