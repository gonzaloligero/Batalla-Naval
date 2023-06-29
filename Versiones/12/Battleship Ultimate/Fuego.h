#ifndef FUEGO_H_INCLUDED
#define FUEGO_H_INCLUDED
#include "Efecto.h"

class Fuego:public Efecto{
private:
    int _Fila;
    int _Columna;
public:
    Fuego();
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
    void sonidoFuego();
    int TransformarFila(int fila);
    int TransformarColumna(int columna);
    void setFila(int fila);
    void setColumna(int columna);
    int getFila();
    int getColumna();

};

#endif // FUEGO_H_INCLUDED
