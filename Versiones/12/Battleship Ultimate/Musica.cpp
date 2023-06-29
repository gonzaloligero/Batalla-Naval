#include <iostream>
#include "Musica.h"
using namespace std;

void Musica::Encendida(){
    _Musica.play();
}
void Musica::Apagada(){
    _Musica.stop();
}

void Musica::PantallaPrincipal(){
 _Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Menu/Owner.wav");
 _Musica.setVolume(10);
}

void Musica::NivelEnemigoGeneral(){
_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Enemigos menores/Digital Love.wav");
 _Musica.setVolume(10);
}

void Musica::NivelGhost(){
_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Jefes/Ghost.wav");
 _Musica.setVolume(10);
}

void Musica::NivelNautilus(){
_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Jefes/Nautilus.wav");
 _Musica.setVolume(10);
}

void Musica::NivelNagronar(){
_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Jefes/Nagronar.wav");
 _Musica.setVolume(10);
}

void Musica::NivelKlosternator(){
_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Jefes/Klosternator.wav");
_Musica.setVolume(2);
}

