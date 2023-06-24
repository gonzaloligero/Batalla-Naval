#include <iostream>
#include <cstring>
#include "Jugador.h"
using namespace std;

void Jugador::setNombre(const char* nombre){
strcpy(_Nombre,nombre);
}


const char* Jugador::getNombre(){
    return _Nombre;
}

int Jugador::getPuntaje(){
    return _Puntaje;
}

void Jugador::setPuntaje(int puntaje){
    _Puntaje+=puntaje;
}


