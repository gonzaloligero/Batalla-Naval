#include <iostream>
#include <cstring>
#include "Jugador.h"
using namespace std;

void Jugador::setNombre(){
char nombre[20];
cout<<"Ingrese su nombre: ";
cin.ignore();
cin.getline(nombre,20);
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


