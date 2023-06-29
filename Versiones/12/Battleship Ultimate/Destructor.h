#ifndef DESTRUCTOR_H_INCLUDED
#define DESTRUCTOR_H_INCLUDED
#include "Embarcaciones.h"


class Destructor : public Embarcacion{
private:
    int _Tamanio;

public:
    Destructor();
    void setPosicion(int x,int y);
    void setRotacion(int x);
    void setNombre();
    void setTamanio(int tamanio);
    int getTamanio();
    sf::Sprite getSprite();
    string getNombre();
};


#endif // DESTRUCTOR_H_INCLUDED
