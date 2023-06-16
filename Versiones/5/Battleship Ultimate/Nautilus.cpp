#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Nautilus.h"
#include "Tablero.h"
using namespace std;


Nautilus::Nautilus(){
_Nombre = "Nautilus";
setTamanio(6);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Jefes/Nautilus/Nautilus.png");
_sprite.setScale(0.5f, 0.5f);
setSprite(texture);
}

void Nautilus::setNombre(){
    _Nombre = "Nautilus";
}

void Nautilus::setTamanio(int tamanio){
    _Tamanio = 4;
}

int Nautilus::getTamanio(){
    return Enemigo::_Tamanio;
}

string Nautilus::getNombre(){
    return "Nautilus";
}


bool Nautilus::sumergirse(int turno){
bool nautilusSumergido;

if(turno % 2 == 0){
    nautilusSumergido = true;
}else{
    nautilusSumergido = false;
}

return nautilusSumergido;

}
