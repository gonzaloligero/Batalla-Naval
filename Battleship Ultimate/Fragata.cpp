#include <iostream>
#include "Fragata.h"
#include "Embarcaciones.h"
using namespace std;

void Fragata::setNombre(){
    _Nombre = "Fragata";
}

void Fragata::setTamanio(int tamanio = 1){
    _Tamanio = tamanio;
}

int Fragata::getTamanio(){
    return _Tamanio;
}

string Fragata::getNombre(){
    return _Nombre;
}

Fragata::Fragata(){
_Nombre = "Fragata";
setTamanio(1);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Barcos/Fragata/ShipPatrolHull.png");
setSprite(texture);

}
