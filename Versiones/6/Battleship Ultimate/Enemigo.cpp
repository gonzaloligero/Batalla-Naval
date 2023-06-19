#include <iostream>
#include "Enemigo.h"
#include <ctime>
#include <cstdlib>
using namespace std;

void Enemigo::setUbicaciones(){
srand(time(NULL));
int fila,columna;

fila = rand()%10;
columna = rand()%10;

_UbicacionFila = fila;
_UbicacionColumna = columna;

}

void Enemigo::setEstado(bool estado){
    _Estado = estado;
}
bool Enemigo::getEstado(){
    return _Estado;
}

int Enemigo::getUbicacionFila(){
    return _UbicacionFila;
}

int Enemigo::getUbicacionColumna(){
    return _UbicacionColumna;
}

int Enemigo::getTamanio(){
    return _Tamanio;
}

//TERMINAR METODO DE ABAJO. DEFINIR LOS VALORES DE X E Y SEGUN LOS PIXELES
/*
void Enemigo::setPosicionSprite(){
    _sprite.setPosition(x,y);
}
*/
