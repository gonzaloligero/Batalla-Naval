#include <iostream>
#include "Embarcaciones.h"
#include "Tablero.h"
using namespace std;

void Embarcacion::setUbicacionEnTablero(){
int fila,columna;

cout<<"Fila: ";
cin>>fila;

while(fila < 1 || fila > 10){
    system("cls");
    cout<<"No existe esta fila. Ingrese un valor valido"<<endl;
    cout<<"Fila: ";
    cin>>fila;
}

_UbicacionFila = fila;

cout<<"Columna: ";
cin>>columna;

while(columna < 1 || columna > 10){
    system("cls");
    cout<<"No existe esta columna. Ingrese un valor valido"<<endl;
    cin>>columna;
}

_UbicacionColumna = columna;

}

int Embarcacion::getUbicacionFila(){
    return _UbicacionFila;
}

int Embarcacion::getUbicacionColumna(){
    return _UbicacionColumna;
}

