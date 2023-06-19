#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Jugador.h"
#include "Tablero.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void pantallaPrincipal();
void pantallaModoClasico(sf::RenderWindow& window);
void pedirNombreJugador();
void pedirNombre();
void menuModoHistoria();
void TransformarCoordenadas(int fila, int columna, int direccion, sf::Sprite &sprite);


#endif // FUNCIONES_H_INCLUDED
