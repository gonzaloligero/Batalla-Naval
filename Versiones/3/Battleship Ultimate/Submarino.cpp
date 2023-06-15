#include <iostream>
#include "Submarino.h"
#include "Embarcaciones.h"
using namespace std;

void Submarino::setNombre(){
    _Nombre = "Submarino";

}
void Submarino::setTamanio(int tamanio = 3){
    _Tamanio = tamanio;
}
int Submarino::getTamanio(){
    return _Tamanio;
}

string Submarino::getNombre(){
    return _Nombre;
}

Submarino::Submarino(){
_Nombre = "Submarino";
setTamanio(3);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Barcos/Submarino/ShipSubMarineHull.png");
setSprite(texture);
}
