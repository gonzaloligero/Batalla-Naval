#include <iostream>
#include "Bombardero.h"
using namespace std;

Bombardero::Bombardero(){
_Nombre = "Bombardero";
_Tipo = 1;
_sprite.setScale(0.2f, 0.2f);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Aviones/Bombardero/Bombardero.png");
setSprite(texture);

}

int Bombardero::bombardear(){
int eleccion;

cout<<"Elija la fila que desea bombardear: ";
cin>>eleccion;
while(eleccion < 1 || eleccion > 10){
    system("cls");
    cout<<"Ingrese una fila valida por favor: ";
    cin>>eleccion;
}

return eleccion-1;

}
