#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace std;

class Enemigo: public sf::Drawable{
protected:
    string _Nombre;
    int _UbicacionFila;
    int _UbicacionColumna;
    int _Tamanio;
    bool _Estado;


public:
    sf::Sprite _sprite;
    sf::Texture texture;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
    void setSprite(const sf::Texture& texture) {
        _sprite.setTexture(texture);
    }
    void setUbicaciones();
    void setEstado(bool estado);
    bool getEstado();
    int getTamanio();
    int getUbicacionFila();
    int getUbicacionColumna();
    void setPosicionSprite();

};

#endif // ENEMIGO_H_INCLUDED
