#ifndef EFECTO_H_INCLUDED
#define EFECTO_H_INCLUDED
#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Efecto:public sf::Drawable{


public:
    sf::SoundBuffer _soundBuffer;
    sf::Sound _sound;
    sf::Sprite _sprite;
    sf::Texture texture;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
    void setSprite(const sf::Texture& texture) {
        _sprite.setTexture(texture);
    }
    void MarcarCasilla(int fila, int columna, sf::Sprite &sprite);

};

#endif // EFECTO_H_INCLUDED
