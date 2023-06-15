#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tablero.h"
#include "Nagronar.h"
#include "Enemigo.h"
#include "Bombardero.h"
#include "Caza.h"
#include "Reconocimiento.h"
#include <conio.h>


int main() {
Bombardero miBombardero;
Caza miCaza;
Destructor miDestructor;
Acorazado miAcorazado;
Tablero miTablero;
Submarino miSubmarino;
Portaaviones miPortaaviones;
Fragata miFragata;
int ataqueBombardero,supremaciaCaza = 0,fila,columna,contRecon;
bool supremacia = true;
Dron miDron;
Reconocimiento miReconocimiento;

miTablero.mostrarTableroHumano(miTablero);
system("PAUSE");
miTablero.detectarEmbarcaciones(miReconocimiento);
miTablero.detectarEmbarcaciones(miReconocimiento);
miTablero.detectarEmbarcaciones(miReconocimiento);
miTablero.detectarEmbarcaciones(miReconocimiento);



/*
sf::RenderWindow window(sf::VideoMode(800, 600), "BATTLESHIP ULTIMATE");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
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



    return 0;
}
