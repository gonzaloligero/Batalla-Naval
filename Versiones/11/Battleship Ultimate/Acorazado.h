#ifndef ACORAZADO_H_INCLUDED
#define ACORAZADO_H_INCLUDED
#include "Embarcaciones.h"

class Acorazado : public Embarcacion{
private:
    int _Tamanio;

public:
    Acorazado();
    void setPosicion(int x,int y);
    void setNombre();
    void setTamanio(int tamanio);
    int getTamanio();
    string getNombre();
    sf::Sprite getSprite();
    void setRotacion(int x);
};

#endif // ACORAZADO_H_INCLUDED
