#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Embarcaciones.h"
#include "Fuego.h"
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
    void reiniciarTablero();
    void setPosicion(int x,int y);
    bool atacarModoClasico(int fila,int columna, Tablero &miTablero, Tablero &aux);
    void completarTableroModoClasico(Tablero &miTablero);
    void mostrarTableroModoClasico(Tablero &miTablero, Tablero &aux);
    bool localizacionDisparo(Tablero &aux, int f, int c);
    void mostrarTableroHumanoCarga(Tablero &miTablero);
    bool ubicarDestructor(Destructor &miDestructor, Tablero &miTablero);
    bool ubicarAcorazado(Acorazado &miAcorazado, Tablero &miTablero);
    bool ubicarFragata(Fragata &miFragata, Tablero &miTablero);
    bool ubicarSubmarino(Submarino &miSubmarino, Tablero &miTablero);
    bool ubicarPortaaviones (Portaaviones &miPortaaviones, Tablero &miTablero);
    void mostrarTablero(Tablero &miTablero);
    bool atacar(int fila,int columna, Tablero &subTablero);
    bool atacaIA(Tablero &miTablero, sf::RenderWindow &_Ventana);
    bool evaluarTablero(Tablero &miTablero);
    void completarTableroNormal(Tablero &miTablero);
    bool completarTableroEnemigoNivel1(Tablero &suTablero);
    void completarTableroNivelNautilus(Tablero &suTablero);
    bool completarTableroEnemigoNivel2(Tablero &suTablero);
    void completarTableroNivelGhost(Tablero &suTablero);
    bool completarTableroEnemigoNivel3(Tablero &suTablero);
    void completarTableroNivelNagronar(Tablero &suTablero);
    void completarTableroNivelKloster(Tablero &suTablero);
    void getAtaqueNagronar(int fila);
    void getAtaqueBombardero(int fila, bool &supremacia, int &filaSupremacia);
    void getAtaqueBombarderoIA(int fila, bool &supremacia, int &filaSupremacia);
    void getAtaqueDron(int fila, int columna, bool &supremacia, int &filaSupremacia);
    void getAtaqueDronIA(int fila, int columna, bool &supremacia, int &filaSupremacia);
    void getReconocimiento(int recon, Tablero &tablero);
    void getReconocimientoIA(int recon, Tablero &tablero);
    void getAtaqueKloster(Tablero &miTablero);
};


#endif // TABLERO_H_INCLUDED
