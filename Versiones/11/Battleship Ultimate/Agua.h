#ifndef AGUA_H_INCLUDED
#define AGUA_H_INCLUDED
#include "Efecto.h"

class Agua:public Efecto{
public:
    Agua();
    sf::Sprite _sprite;
    sf::Texture texture;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
    void setSprite(const sf::Texture& texture) {
        _sprite.setTexture(texture);
    }
    sf::Sprite getSprite();
    void setSonido();
    void sonidoAgua();

};

#endif // AGUA_H_INCLUDED
