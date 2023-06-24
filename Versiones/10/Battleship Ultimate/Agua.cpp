#include <iostream>
#include "Agua.h"
#include "Efecto.h"
#include <SFML/Audio.hpp>

using namespace std;

Agua::Agua(){
/*_sprite.setScale(0.03f, 0.03f);
_sprite.setPosition(0,0);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Efectos/Agua.png");
setSprite(texture);*/
_sound.setVolume(75);
_soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/Agua.wav");
_sound.setBuffer(_soundBuffer);

}

void Agua::setSonido(){
    _soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/Agua.wav");
    _sound.setBuffer(_soundBuffer);
}

sf::Sound Agua::getSonido(){
    return _sound;
}

sf::Sprite Agua::getSprite(){
    return _sprite;
}
