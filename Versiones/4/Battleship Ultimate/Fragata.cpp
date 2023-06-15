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

void Fragata::setPosicion(int x,int y){
    _sprite.setPosition(x,y);
}

Fragata::Fragata(){
_Nombre = "Fragata";
setTamanio(1);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Barcos/Fragata/ShipPatrolHull.png");
_sprite.setScale(0.6f, 0.6f);
setSprite(texture);

}

void Fragata::setRotacion(int x){
    _sprite.setRotation(x);
}

