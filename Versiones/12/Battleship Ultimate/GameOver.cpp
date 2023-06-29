#include <iostream>
#include "GameOver.h"
using namespace std;

GameOver::GameOver(){
_sprite.setScale(0.08f, 0.08f);
_sprite.setPosition(400,300);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Pantallas/GameOver.png");
setSprite(texture);
_sound.setVolume(50);
_soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/GameOver.wav");
_sound.setBuffer(_soundBuffer);

}

void GameOver::setSonido(){
_soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/GameOver.wav");
_sound.setBuffer(_soundBuffer);

}

void GameOver::sonidoGameOver(){
    _sound.play();
}

