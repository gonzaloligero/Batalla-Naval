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
_sprite.setScale(1.3f, 1.3f);
setSprite(texture);
_sound.setVolume(75);
_soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/Ghost.wav");
_sound.setBuffer(_soundBuffer);
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
