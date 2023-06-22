#include <iostream>
#include "Fuego.h"
#include "Efecto.h"
#include <SFML/Audio.hpp>

using namespace std;

Fuego::Fuego(){
_sprite.setScale(0.03f, 0.03f);
_sprite.setPosition(0,0);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Efectos/Fuego.png");
setSprite(texture);

}

sf::Sprite Fuego::getSprite(){
    return _sprite;
}

void Fuego::setFila(int fila){
    _Fila = fila;
}

void Fuego::setColumna(int columna){
    _Columna = columna;
}

int Fuego::getFila(){
    return _Fila;
}

int Fuego::getColumna(){
    return _Columna;
}

int Fuego::TransformarFila(int fila){

switch(fila){
case 1: return 15;
break;
case 2: return 43;
break;
case 3: return 71;
break;
case 4: return 99;
break;
case 5: return 127;
break;
case 6: return 155;
break;
case 7: return 183;
break;
case 8: return 211;
break;
case 9: return 239;
break;
case 10: return 267;
break;
    }
}

int Fuego::TransformarColumna(int columna){

switch(columna){
case 1: return 85;
break;
case 2: return 113;
break;
case 3: return 141;
break;
case 4: return 169;
break;
case 5: return 197;
break;
case 6: return 225;
break;
case 7: return 253;
break;
case 8: return 281;
break;
case 9: return 309;
break;
case 10: return 337;
break;
    }

}
