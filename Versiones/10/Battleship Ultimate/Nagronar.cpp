#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Nagronar.h"
#include "Tablero.h"
using namespace std;

Nagronar::Nagronar(){
_Nombre = "Nagronar";
setTamanio(6);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Jefes/Nagronar/Nagronar.png");
_sprite.setScale(0.6f, 0.6f);
setSprite(texture);
_sound.setVolume(75);
_soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/Nagronar.wav");
_sound.setBuffer(_soundBuffer);
}

void Nagronar::setNombre(){
    _Nombre = "Nagronar";
}

void Nagronar::setTamanio(int tamanio){
    _Tamanio = 6;
}

int Nagronar::getTamanio(){
    return Enemigo::_Tamanio;
}

string Nagronar::getNombre(){
    return "Nagronar";
}

int Nagronar::destruirFila(Tablero miTablero){
srand(time(NULL));
int fila;

fila = rand()%10;

cout<<getNombre()<<" ataco la fila "<<fila+1<<endl;

return fila-1;

}

