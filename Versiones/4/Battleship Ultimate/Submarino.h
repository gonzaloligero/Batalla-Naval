#ifndef SUBMARINO_H_INCLUDED
#define SUBMARINO_H_INCLUDED
#include "Embarcaciones.h"

class Submarino : public Embarcacion{
private:
    int _Tamanio;
    sf::Sprite _sprite;
    sf::Texture texture;

public:
    Submarino();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
    void setSprite(const sf::Texture& texture) {
        _sprite.setTexture(texture);
    }
    void setPosicion(int x,int y);
    void setNombre();
    void setTamanio(int tamanio);
    int getTamanio();
    string getNombre();
    void setRotacion(int x);

};

#endif // SUBMARINO_H_INCLUDED
