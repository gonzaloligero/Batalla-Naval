#ifndef PORTAAVIONES_H_INCLUDED
#define PORTAAVIONES_H_INCLUDED
#include "Embarcaciones.h"

class Portaaviones : public Embarcacion{
private:
    int _Tamanio;
    sf::Sprite _sprite;
    sf::Texture texture;

public:
    Portaaviones();
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

#endif // PORTAAVIONES_H_INCLUDED
