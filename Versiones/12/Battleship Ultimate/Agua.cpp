#include <iostream>
#include "Agua.h"
#include "Efecto.h"
#include <SFML/Audio.hpp>

using namespace std;

Agua::Agua(){
_sound.setVolume(25);
_soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/Agua.wav");
_sound.setBuffer(_soundBuffer);

}

void Agua::setSonido(){
    _soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/Agua.wav");
    _sound.setBuffer(_soundBuffer);
}

void Agua::sonidoAgua(){
    _sound.play();
}

sf::Sprite Agua::getSprite(){
    return _sprite;
}
