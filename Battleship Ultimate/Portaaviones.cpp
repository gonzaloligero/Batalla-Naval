#include <iostream>
#include "Portaaviones.h"
#include "Embarcaciones.h"
using namespace std;

void Portaaviones::setNombre(){
    _Nombre = "Portaaviones";

}
void Portaaviones::setTamanio(int tamanio = 4){
    _Tamanio = tamanio;
}

int Portaaviones::getTamanio(){
    return _Tamanio;
}

string Portaaviones::getNombre(){
    return _Nombre;
}
Portaaviones::Portaaviones(){
_Nombre = "Portaaviones";
setTamanio(4);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Barcos/Portaaviones/ShipCarrierHull.png");
setSprite(texture);
}
