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
