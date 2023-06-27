#include <iostream>
#include "Bombardero.h"
#include <time.h>
using namespace std;

Bombardero::Bombardero(){
_Nombre = "Bombardero";
_Tipo = 1;
_sprite.setScale(0.2f, 0.2f);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Aviones/Bombardero/Bombardero.png");
setSprite(texture);
_Usos = 3;

}

int Bombardero::bombardear(){
int eleccion;

cout<<"Puedes utilizar tu "<<_Nombre<<endl;
system("PAUSE");
system("cls");

cout<<"Elija la fila que desea bombardear: ";
cin>>eleccion;
while(eleccion < 1 || eleccion > 10){
    system("cls");
    cout<<"Ingrese una fila valida por favor: ";
    cin>>eleccion;
}

return eleccion-1;

}

int Bombardero::bombardearIA(){
int eleccion;

eleccion = rand()%10+1;

return eleccion;

}

