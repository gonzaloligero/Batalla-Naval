#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

class Juego{
private:
    sf::RenderWindow _Ventana;
    sf::Event _Evento;
    Vector2f _PosicionMouse;
    sf::Music _Musica;

public:
    Juego();
    void GameLoop();
    void Dibujar();
    void ProcesarEvento();
    void ProcesarMouse();
    void PantallaPrincipal();
    void ModoClasico(sf::RenderWindow &v);



};


#endif // JUEGO_H_INCLUDED
