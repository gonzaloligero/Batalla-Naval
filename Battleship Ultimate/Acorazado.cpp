#include <iostream>
#include "Acorazado.h"
#include "Embarcaciones.h"
using namespace std;

void Acorazado::setNombre(){
    _Nombre = "Acorazado";

}
void Acorazado::setTamanio(int tamanio = 3){
    _Tamanio = tamanio;
}

int Acorazado::getTamanio(){
    return _Tamanio;
}

string Acorazado::getNombre(){
    return _Nombre;
}

Acorazado::Acorazado(){
_Nombre = "Acorazado";
setTamanio(3);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Barcos/Acorazado/ShipCruiserHull.png");
setSprite(texture);
}
