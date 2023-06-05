#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include "Funciones.h"
#include "Tablero.h"
#include "Jugador.h"
using namespace std;


int main(){
srand(time(NULL));
Jugador player;
Tablero miTablero;

miTablero.completarTableroNormal();

//menuPrincipal(player);

/*
sf::RenderWindow window(sf::VideoMode(800, 600), "BATTLESHIP ULTIMATE");
Destructor miDestructor;
Fragata miFragata;
Acorazado miAcorazado;
Portaaviones miPortaaviones;
Submarino miSubmarino;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        //window.draw(miTablero);
        //window.draw(miSubmarino);
        //window.draw(miPortaaviones);
        window.draw(miAcorazado);
        window.draw(miFragata);
        window.draw(miDestructor);
        window.display();
    }
*/

    return 0;
}


