#ifndef PORTAAVIONES_H_INCLUDED
#define PORTAAVIONES_H_INCLUDED
#include "Embarcaciones.h"

class Portaaviones : public Embarcacion{
private:
    int _Tamanio;

public:
    Portaaviones();
    void setPosicion(int x,int y);
    void setNombre();
    void setTamanio(int tamanio);
    int getTamanio();
    string getNombre();
    void setRotacion(int x);

};

#endif // PORTAAVIONES_H_INCLUDED
