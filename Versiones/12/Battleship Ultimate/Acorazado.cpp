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

sf::Sprite Acorazado::getSprite(){
    return _sprite;
}

string Acorazado::getNombre(){
    return _Nombre;
}

void Acorazado::setPosicion(int x,int y){
    _sprite.setPosition(x,y);
}

Acorazado::Acorazado(){
_Nombre = "Acorazado";
setTamanio(3);
_sprite.setScale(0.6f, 0.6f);
_sprite.setPosition(0,0);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Barcos/Acorazado/ShipCruiserHull.png");
setSprite(texture);
}

void Acorazado::setRotacion(int x){
    _sprite.setRotation(x);
}

