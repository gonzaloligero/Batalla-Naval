#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tablero.h"
#include "Juego.h"
using namespace std;
using namespace sf;



int main() {
Juego ventana;


ventana.PantallaPrincipal();

    return 0;
}





/*


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(tableroEnemigo);
        window.draw(miGhost);

        window.draw(miTablero);
        miAcorazado.setPosicion(32,20);
        window.draw(miAcorazado);
        miDestructor.setPosicion(61,162);
        window.draw(miDestructor);
        miSubmarino.setPosicion(113,160);
        window.draw(miSubmarino);
        miPortaaviones.setRotacion(90);
        miPortaaviones.setPosicion(265,100);
        window.draw(miPortaaviones);
        miFragata.setPosicion(147,42);
        window.draw(miFragata);

        window.display();
    }*/




