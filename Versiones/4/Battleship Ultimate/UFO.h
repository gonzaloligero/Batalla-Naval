#ifndef UFO_H_INCLUDED
#define UFO_H_INCLUDED
#include "Enemigo.h"

class UFO : public Enemigo{
private:
    sf::Sprite _sprite;
    sf::Texture texture;
    int _Tamanio;

public:
    UFO();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
    void setSprite(const sf::Texture& texture) {
        _sprite.setTexture(texture);
    }
    void setTamanio(int tamanio);
    void setNombre();
    void setPosicion(int x,int y);

};


#endif // UFO_H_INCLUDED
