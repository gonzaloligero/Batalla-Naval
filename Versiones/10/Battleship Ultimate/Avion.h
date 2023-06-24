#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>
using namespace std;

class Avion: public sf::Drawable{
protected:
    string _Nombre;
    int _Tipo;
    int _Usos;
    sf::Sprite _sprite;
    sf::Texture texture;

public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
    void setSprite(const sf::Texture& texture) {
        _sprite.setTexture(texture);
    }
    void setUsos(int usos);
    int getUsos();
};

#endif // AVION_H_INCLUDED
