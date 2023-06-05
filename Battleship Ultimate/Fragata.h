#ifndef FRAGATA_H_INCLUDED
#define FRAGATA_H_INCLUDED
#include "Embarcaciones.h"

class Fragata : public Embarcacion{
private:
    int _Tamanio;
    sf::Sprite _sprite;
    sf::Texture texture;

public:
    Fragata();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
    void setSprite(const sf::Texture& texture) {
        _sprite.setTexture(texture);
    }
    void setNombre();
    void setTamanio(int tamanio);
    string getNombre();
    int getTamanio();

};


#endif // FRAGATA_H_INCLUDED
