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

sf::Sprite Destructor::getSprite(){
    return _sprite;
}

Destructor::Destructor(){
_Nombre = "Destructor";
setTamanio(2);
_sprite.setScale(0.5f, 0.5f);
_sprite.setPosition(0,0);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Barcos/Destructor/ShipDestroyerHull.png");
setSprite(texture);
}

void Destructor::setPosicion(int x,int y){
    _sprite.setPosition(x,y);
}

void Destructor::setRotacion(int x){
    _sprite.setRotation(x);
}


