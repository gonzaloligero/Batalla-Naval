#ifndef GAMEOVER_H_INCLUDED
#define GAMEOVER_H_INCLUDED
#include "Efecto.h"

class GameOver: public Efecto{
public:
    GameOver();
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
    void sonidoGameOver();

};



#endif // GAMEOVER_H_INCLUDED
