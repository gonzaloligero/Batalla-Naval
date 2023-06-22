#include <iostream>
#include "UFO.h"
using namespace std;


void UFO::setTamanio(int tamanio = 1){
    _Tamanio = tamanio;
}

UFO::UFO(){
_Nombre = "UFO";
setTamanio(1);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Enemigos/UFO.png");
_sprite.setScale(0.2f, 0.2f);
setSprite(texture);
}

void UFO::setNombre(){
    _Nombre = "UFO";
}
