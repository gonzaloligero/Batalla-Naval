#include <iostream>
#include "Dron.h"
using namespace std;

Dron::Dron(){
_Nombre = "Dron";
_Tipo = 3;
_sprite.setScale(0.2f, 0.2f);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Aviones/Dron/Dron.png");
setSprite(texture);
_Usos = 3;
}

void Dron::setContadorAtaques(int contador = 3){
    _ContadorAtaques = contador;
}

int Dron::atacarColumna(){
int columna;

cout<<"Ingrese la columna a atacar: ";
cin>>columna;

while(columna < 1 || columna > 10){
cout<<"Ingrese una columna valida: "<<endl;
cin>>columna;
    }
return columna;

}

int Dron::atacarFila(){
int fila;

cout<<"Ingrese la fila a atacar: ";
cin>>fila;

while(fila < 1 || fila > 10){
cout<<"Ingrese una fila valida: "<<endl;
cin>>fila;
    }
return fila;
}

int Dron::getContador(){
    return _ContadorAtaques;
}
