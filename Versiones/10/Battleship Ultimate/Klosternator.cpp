#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Klosternator.h"
#include "Tablero.h"
using namespace std;

Klosternator::Klosternator(){
_Nombre = "Klosternator";
setTamanio(10);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Jefes/Klosternator.png");
_sprite.setScale(0.6f, 0.6f);
setSprite(texture);
_sound.setVolume(75);
_soundBuffer.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sonidos/Combate/Gentes.wav");
_sound.setBuffer(_soundBuffer);

}

bool Klosternator::seEntiendeGentes(){
int eleccion;

cout<<getNombre()<<" te ha consulta si se entiende"<<endl;
cout<<"1 - Entiendo / 2 - No entiendo"<<endl;
cin>>eleccion;

if(eleccion == 1){
    cout<<"Mejor. Sigamos"<<endl;
    return true;
}else if(eleccion == 2){
cout<<"A ponerse a estudiar"<<endl;}else{
cout<<"Es evidente que no entendiste, ¡esa opcion no es valida!"<<endl;
}

return false;

}

bool Klosternator::estoEsBatata(){
int batata;

batata = rand()%2+1;

if(batata == 1){
    cout<<"Para "<<getNombre()<<" tu tablero es una batata"<<endl;
    cout<<"Dale un turno a ver si lo arregla"<<endl;
    return true;
}else if(batata == 2){
    cout<<"Para "<<getNombre()<<" tu tablero esta bien organizado"<<endl;
    cout<<"Puedes seguir"<<endl;
    return false;
}

}

bool Klosternator::noCompila(){

cout<<getNombre()<<" dice que esto no compila"<<endl;
cout<<"Perdes un turno"<<endl;
return true;

}

bool Klosternator::profePuedeGrabar(){

cout<<getNombre()<<" no ha grabado la batalla"<<endl;
cout<<"Perdes un turno"<<endl;

}

void Klosternator::setTamanio(int tamanio){
    _Tamanio = 10;
}

int Klosternator::getTamanio(){
    return _Tamanio;
}

string Klosternator::getNombre(){

    return _Nombre;
}
