#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Nautilus.h"
#include "Tablero.h"
using namespace std;


Nautilus::Nautilus(){
_Nombre = "Nautilus";
setTamanio(4);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Jefes/Nautilus/Nautilus.png");
_sprite.setScale(0.6f, 0.6f);
setSprite(texture);
_sound.setVolume(75);
_soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/Nautilus.wav");
_sound.setBuffer(_soundBuffer);
}

void Nautilus::setNombre(){
    _Nombre = "Nautilus";
}

void Nautilus::setTamanio(int tamanio){
    _Tamanio = 4;
}

int Nautilus::getTamanio(){
    return Enemigo::_Tamanio;
}

string Nautilus::getNombre(){
    return "Nautilus";
}


bool Nautilus::sumergirse(){
srand(time(NULL));
int deteccion;

deteccion = rand()% 4 + 1;
cout<<"Deteccion: "<<deteccion<<endl;

if(deteccion == 1 || deteccion == 2){
    return  true;
}else{
    return false;
}



}
