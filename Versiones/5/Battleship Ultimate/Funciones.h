#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Jugador.h"
#include "Tablero.h"

void menuPrincipal(Jugador player1);
void pedirNombre();
void menuModoHistoria();
void mensajeDeSalida();
int confirmarSalida();
void modoDosJugadores();
void atacar(int fila,int columna, Tablero &miTablero);
void evaluarTablero(Tablero &miTablero);

#endif // FUNCIONES_H_INCLUDED
