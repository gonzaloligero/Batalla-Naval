#ifndef DESTRUCTOR_H_INCLUDED
#define DESTRUCTOR_H_INCLUDED
#include "Embarcaciones.h"


class Destructor : public Embarcacion{
private:
    int _Tamanio;
    sf::Sprite _sprite;
    sf::Texture texture;

public:
    Destructor();
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


#endif // DESTRUCTOR_H_INCLUDED
