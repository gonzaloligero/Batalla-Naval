#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Embarcaciones.h"
#include "Bombardero.h"
#include "Destructor.h"
#include "Dron.h"
#include "Acorazado.h"
#include "Submarino.h"
#include "Fragata.h"
#include "Portaaviones.h"
#include "Reconocimiento.h"
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
    void completarTableroNormal(Tablero& tableroNormal, sf::RenderWindow& window);
    void reiniciarTablero();
    void setPosicion(int x,int y);
    bool ubicarDestructor(Destructor &miDestructor, Tablero miTablero);
    void ubicarAcorazado(Acorazado miAcorazado, Tablero miTablero);
    void ubicarFragata(Fragata miFragata, Tablero miTablero);
    void ubicarSubmarino(Submarino miSubmarino, Tablero miTablero);
    void ubicarPortaaviones (Portaaviones miPortaaviones, Tablero miTablero);
    void mostrarTablero(Tablero &miTablero);
    void atacar(int fila,int columna, Tablero &miTablero);
    bool evaluarTablero(Tablero &miTablero);
    void completarTableroNormal(Tablero &miTablero);
    void completarTableroEnemigoNivel1(Tablero &suTablero);
    void completarTableroNivelNautilus(Tablero &suTablero);
    void completarTableroEnemigoNivel2(Tablero &suTablero);
    void completarTableroNivelGhost(Tablero &suTablero);
    void completarTableroEnemigoNivel3(Tablero &suTablero);
    void completarTableroNivelNagronar(Tablero &suTablero);
    void getAtaqueNagronar(int fila);
    void getAtaqueBombardero(int fila, bool &supremacia, int &filaSupremacia);
    void getAtaqueDron(int fila, int columna, int &contadorAtaques);
    void detectarEmbarcaciones(Reconocimiento &miReconocimiento);
};


#endif // TABLERO_H_INCLUDED
