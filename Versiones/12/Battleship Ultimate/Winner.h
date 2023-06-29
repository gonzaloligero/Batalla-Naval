#ifndef WINNER_H_INCLUDED
#define WINNER_H_INCLUDED
#include "Efecto.h"

class Winner: public Efecto{
public:
    Winner();
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
    void sonidoWinner();
    void modoSecreto();

};



#endif // WINNER_H_INCLUDED
