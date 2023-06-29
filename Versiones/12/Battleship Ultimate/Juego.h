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
    void ModoClasico();
    void ModoHistoria(sf::RenderWindow &v);
    void ModoPersonalizado(sf::RenderWindow &v);
    void ModoKloster(sf::RenderWindow &v);
    void Nivel1(sf::RenderWindow &v);
    void Nivel2(sf::RenderWindow &v);
    void Nivel3(sf::RenderWindow &v);
    void Nivel4(sf::RenderWindow &v);
    void Nivel5(sf::RenderWindow &v);
    void Nivel6(sf::RenderWindow &v);




};


#endif // JUEGO_H_INCLUDED
