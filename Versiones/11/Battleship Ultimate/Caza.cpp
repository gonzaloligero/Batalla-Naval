#include <iostream>
#include "Caza.h"
#include <time.h>
using namespace std;

Caza::Caza(){
_Nombre = "Caza";
_Tipo = 2;
_sprite.setScale(0.2f, 0.2f);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Aviones/Caza/Caza.png");
setSprite(texture);
_Usos = 1;

}

int Caza::otorgarSupremacia(){
int eleccion;

cout<<"Puedes utilizar tu "<<_Nombre<<endl;
system("PAUSE");
system("cls");

cout<<"Elige la fila donde deseas que tu caza te otorgue supremacia aerea: ";
cin>>eleccion;
if(eleccion < 1 || eleccion > 10){
cout<<"Elige una fila valida: ";
cin>>eleccion;
system("cls");
}

return eleccion;

}

int Caza::otorgarSupremaciaIA(){
int eleccion;

eleccion = rand()%10+1;

return eleccion;

}