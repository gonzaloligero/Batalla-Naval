#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Nagronar.h"
#include "Tablero.h"
using namespace std;

Nagronar::Nagronar(){
_Nombre = "Nagronar";
setTamanio(6);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Jefes/Nagronar/Nagronar.png");
_sprite.setScale(0.2f, 0.2f);
setSprite(texture);
}

void Nagronar::setNombre(){
    _Nombre = "Nagronar";
}

void Nagronar::setTamanio(int tamanio){
    _Tamanio = 6;
}

int Nagronar::getTamanio(){
    return Enemigo::_Tamanio;
}

string Nagronar::getNombre(){
    return "Nagronar";
}

int Nagronar::usarHabilidad(Tablero miTablero){
srand(time(NULL));
int fila;

fila = rand()%10+1;

return fila;

}

