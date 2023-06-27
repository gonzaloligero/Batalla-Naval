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
int decidirPuntaje(float copia);
int seleccionarBarco(bool &destructorUbicado, bool &fragataUbicada, bool &submarinoUbicado, bool &portaavionesUbicado, bool &acorazadoUbicado);



#endif // FUNCIONES_H_INCLUDED
