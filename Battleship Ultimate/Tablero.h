#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Embarcaciones.h"
#include "Destructor.h"
#include "Acorazado.h"
#include "Submarino.h"
#include "Fragata.h"
#include "Portaaviones.h"
#include "UFO.h"

class Tablero: public sf::Drawable{
private:
    int _Tamanio[10][10];
    sf::Sprite _sprite;
    sf::Texture texture;

public:
    Tablero();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
    void setSprite(const sf::Texture& texture) {
        _sprite.setTexture(texture);
    }
    void ubicarDestructor(Destructor miDestructor, Tablero miTablero);
    void ubicarAcorazado(Acorazado miAcorazado, Tablero miTablero);
    void ubicarFragata(Fragata miFragata, Tablero miTablero);
    void ubicarSubmarino(Submarino miSubmarino, Tablero miTablero);
    void ubicarPortaaviones (Portaaviones miPortaaviones, Tablero miTablero);
    void vaciarTablero();
    void mostrarTableroHumano(Tablero &miTablero);
    void mostrarTableroCPU();
    void atacar(int fila,int columna, Tablero &miTablero);
    bool evaluarTablero(Tablero &miTablero);
    void completarTableroNormal(Tablero &miTablero);
    void completarTableroBossFight();

};


#endif // TABLERO_H_INCLUDED
