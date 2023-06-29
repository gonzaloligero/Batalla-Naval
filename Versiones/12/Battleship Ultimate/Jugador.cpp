#include <iostream>
#include <cstring>
#include "Jugador.h"
using namespace std;

Jugador::Jugador(){
    char nombre[20]=" xx ";
    strcpy(_Nombre,nombre);
    _Puntaje=0;
    _cantDisparos=0;
    _efectividad=0;
}

void Jugador::setNombre(){
 char nombre[20];
cout<<"Ingrese su nombre: ";
cin.getline(nombre,19);
strcpy(_Nombre,nombre);
}

void Jugador::setPuntaje(int punt){
_Puntaje=punt;
}

void Jugador::setCantDisparos(int cant){
_cantDisparos=cant;
}

void Jugador::setEfectividad(float efec){
_efectividad=efec;
}

const char* Jugador::getNombre(){
    return _Nombre;
}

int Jugador::getPuntaje(){
    return _Puntaje;
}

int Jugador::getCantDisparos(){
return _cantDisparos;
}

float Jugador::getEfectividad(){
return _efectividad;
}

void Jugador::mostrarRegisttro(){

    cout<<" NOMBRE:  "<<_Nombre<<endl;
    cout<<" EFECTIVIDAD: "<<_efectividad<<endl;
    cout<<" CANTIDAD DE DISPAROS: "<<_cantDisparos<<endl;
    cout<<" PUNTAJE: "<< _Puntaje<<endl;
    cout<<"_____________"<<endl;
}
