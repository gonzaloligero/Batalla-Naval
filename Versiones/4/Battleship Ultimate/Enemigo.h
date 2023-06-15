#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace std;

class Enemigo: public sf::Drawable{
protected:
    string _Nombre;
    int _UbicacionEnTablero;
    int _Tamanio;
    sf::Sprite _sprite;
    sf::Texture texture;

public:
    void setUbicacionEnTablero(int fila,int columna);
};

#endif // ENEMIGO_H_INCLUDED
