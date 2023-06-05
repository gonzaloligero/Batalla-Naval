#include <iostream>
#include "Destructor.h"
#include "Embarcaciones.h"
using namespace std;

void Destructor::setNombre(){
    _Nombre = "Destructor";
}

void Destructor::setTamanio(int tamanio = 2){
    _Tamanio = tamanio;
}

string Destructor::getNombre(){
    return _Nombre;
}

int Destructor::getTamanio(){
    return _Tamanio;
}

Destructor::Destructor(){
_Nombre = "Destructor";
setTamanio(2);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Barcos/Destructor/ShipDestroyerHull.png");
setSprite(texture);
}

