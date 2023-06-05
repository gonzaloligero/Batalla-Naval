#ifndef EMBARCACIONES_H_INCLUDED
#define EMBARCACIONES_H_INCLUDED
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>
using namespace std;

class Embarcacion : public sf::Drawable{
protected:
    string _Nombre;
    int _UbicacionEnTablero;

public:
    void setUbicacionEnTablero(int x,int y);

};

#endif // EMBARCACIONES_H_INCLUDED
