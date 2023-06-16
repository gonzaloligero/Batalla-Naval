#ifndef EMBARCACIONES_H_INCLUDED
#define EMBARCACIONES_H_INCLUDED
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>
using namespace std;

class Embarcacion : public sf::Drawable{
protected:
    string _Nombre;
    int _UbicacionFila;
    int _UbicacionColumna;
sf::Sprite _sprite;
    sf::Texture texture;

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
    void setSprite(const sf::Texture& texture) {
        _sprite.setTexture(texture);
    }
    void setUbicacionEnTablero();
    int getUbicacionFila();
    int getUbicacionColumna();
};

#endif // EMBARCACIONES_H_INCLUDED
