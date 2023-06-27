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

void Submarino::setPosicion(int x,int y){
    _sprite.setPosition(x,y);
}

Submarino::Submarino(){
_Nombre = "Submarino";
setTamanio(3);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Barcos/Submarino/ShipSubMarineHull.png");
_sprite.setPosition(0,0);
_sprite.setScale(0.6f, 0.6f);
setSprite(texture);
}

void Submarino::setRotacion(int x){
    _sprite.setRotation(x);
}
