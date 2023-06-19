#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Ghost.h"
#include "Tablero.h"
using namespace std;

Ghost::Ghost(){
_Nombre = "Ghost";
setTamanio(1);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Jefes/Ghost/Ghost.png");
_sprite.setScale(0.2f, 0.2f);
setSprite(texture);
}

void Ghost::setNombre(){
    _Nombre = "Ghost";
}

void Ghost::setTamanio(int tamanio){
    _Tamanio = 1;
}

int Ghost::getTamanio(){
    return Enemigo::_Tamanio;
}

string Ghost::getNombre(){
    return "Ghost";
}

void Ghost::teletransportarse(){
srand(time(NULL));
int fila, columna;

fila = rand()%10;
columna = rand()%10;

_UbicacionFila = fila;
_UbicacionColumna = columna;

}
