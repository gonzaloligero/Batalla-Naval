#include <iostream>
#include "Winner.h"
using namespace std;

Winner::Winner(){
_sprite.setScale(0.08f, 0.08f);
_sprite.setPosition(400,300);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Pantallas/Winner.png");
setSprite(texture);
_sound.setVolume(10);
_soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/Winner.wav");
_sound.setBuffer(_soundBuffer);

}

void Winner::modoSecreto(){
_sound.setVolume(50);
_soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Menú/Toasty.wav");
_sound.setBuffer(_soundBuffer);
_sound.play();

}

void Winner::sonidoWinner(){
    _sound.play();
}
