#ifndef NAGRONAR_H_INCLUDED
#define NAGRONAR_H_INCLUDED
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>
#include "Boss.h"
#include "Tablero.h"
using namespace std;

class Nagronar: public Boss{
private:
    int _Tamanio;
    sf::Sprite _sprite;
    sf::Texture texture;

public:
    Nagronar();
    int usarHabilidad(Tablero miTablero);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
    void setSprite(const sf::Texture& texture) {
        _sprite.setTexture(texture);
    }
    void setNombre();
    void setTamanio(int tamanio);
    int getTamanio();
    string getNombre();
};

#endif // NAGRONAR_H_INCLUDED
