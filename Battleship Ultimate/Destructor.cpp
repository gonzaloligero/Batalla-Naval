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
    return Embarcacion::_Nombre;
}
