#include <iostream>
#include "Reconocimiento.h"
using namespace std;

Reconocimiento::Reconocimiento(){
_Nombre = "Reconocimiento";
_Tipo = 4;
_sprite.setScale(0.2f, 0.2f);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Aviones/Reconocimiento/Reconocimiento.png");
setSprite(texture);
_Usos = 3;
}

void Reconocimiento::setCargas(){
    _Cargas = 3;
}

int Reconocimiento::getCargas(){
    return _Cargas;
}

void Reconocimiento::descontarCarga(){
    _Cargas = _Cargas-1;
}
