#include <iostream>
#include "Juego.h"
#include "Tablero.h"
#include "Nagronar.h"
#include "Ghost.h"
#include "Nautilus.h"
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;
using namespace sf;

Juego::Juego() : _Ventana(sf::VideoMode(800, 600), "BATTLESHIP ULTIMATE"){}

void Juego::Dibujar(){

    _Ventana.clear();

    _Ventana.display();

}

void Juego::GameLoop() {
bool mostrarPantallaPrincipal = true;
    while (_Ventana.isOpen()) {
        ProcesarEvento();
        Dibujar();
    }
}

void Juego::ProcesarEvento(){

    while(_Ventana.pollEvent(_Evento)){
        switch(_Evento.type){
        case Event::Closed:
                _Ventana.close();
                exit(1);
        break;
        case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                return;

            }
        }
    }

}

void Juego::ProcesarMouse(){

    _PosicionMouse = Vector2f(Mouse::getPosition(_Ventana));
    _PosicionMouse = _Ventana.mapPixelToCoords(static_cast<Vector2i>(_PosicionMouse));

}

void Juego::PantallaPrincipal() {
int opcionSeleccionada = 0; // Inicialmente ninguna opción está seleccionada
bool mostrarPulsaEnter = true, modoClasico = false;
bool mostrarOpcionesPrincipales = false;

    sf::Texture texture;
    if (!texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Pantallas/Pantalla principal.png")) {
        // Manejar error si no se puede cargar la imagen
        return;
    }

    sf::Sprite image(texture);

    sf::Font font;
    if (!font.loadFromFile("C:/Users/Gonzalo/Desktop/Database/PressStart2P.ttf")) {
        // Manejar error si no se puede cargar la fuente
        return;
    }

    sf::Text text("Pulsa ENTER para continuar", font, 15);
    text.setFillColor(sf::Color::White);
    text.setPosition(190, 450);

    sf::Text opcion1("Modo Historia", font, 20);
    opcion1.setPosition(274, 460);

    sf::Text opcion2("Modo Clasico", font, 20);
    opcion2.setPosition(274, 488);

    sf::Text opcion3("Puntajes", font, 20);
    opcion3.setPosition(274, 516);

    sf::Text opcion4("Salir", font, 20);
    opcion4.setPosition(274, 544);


    if (!_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Menu/Slow Ride.wav")) {
        // Manejar error si no se puede cargar la música
        // Por ejemplo, mostrar un mensaje de error y continuar sin música
    }
    _Musica.play();

    while (_Ventana.isOpen()) {
        ProcesarEvento();

        _Ventana.clear();
        _Ventana.draw(image);

        if (mostrarPulsaEnter) {
            _Ventana.draw(text);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                mostrarPulsaEnter = false;
                mostrarOpcionesPrincipales = true;
            }
        }

        if(mostrarOpcionesPrincipales == true){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                opcionSeleccionada = (opcionSeleccionada - 1 + 4) % 4;
                sf::sleep(sf::milliseconds(150)); // Pausa de 150 milisegundos
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                opcionSeleccionada = (opcionSeleccionada + 1) % 4;
                sf::sleep(sf::milliseconds(150)); // Pausa de 150 milisegundos
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                if (opcionSeleccionada == 3) {
                    _Ventana.close(); // Cierra la ventana
                    return; // Salir de la función PantallaPrincipal()
                }

        if (mostrarOpcionesPrincipales == true) {
                    // Lógica para cada opción seleccionada
        switch (opcionSeleccionada) {
        case 0:
                // Lógica para la opción 1 (Modo Historia)
        break;
        case 1:
                _Ventana.clear();
                mostrarOpcionesPrincipales = false;
                modoClasico = true;
                _Musica.stop();
                ModoClasico(_Ventana);
                modoClasico = false;
                mostrarOpcionesPrincipales = true;
                // Lógica para la opción 2 (Modo Clásico)
        break;
        case 2:
                // Lógica para la opción 3 (Puntajes)
        break;
            }
        }
            }
        }

        // Establecer el color de las opciones según la selección
        opcion1.setFillColor(opcionSeleccionada == 0 ? sf::Color::Red : sf::Color::White);
        opcion2.setFillColor(opcionSeleccionada == 1 ? sf::Color::Red : sf::Color::White);
        opcion3.setFillColor(opcionSeleccionada == 2 ? sf::Color::Red : sf::Color::White);
        opcion4.setFillColor(opcionSeleccionada == 3 ? sf::Color::Red : sf::Color::White);

        // Dibujar las opciones en la ventana
        if (!mostrarPulsaEnter) {
            _Ventana.draw(opcion1);
            _Ventana.draw(opcion2);
            _Ventana.draw(opcion3);
            _Ventana.draw(opcion4);
        }

        _Ventana.display();
    }
}



void Juego::ModoClasico(sf::RenderWindow &_Ventana){

Tablero tableroUno, tableroDos;
Destructor destructor;
Acorazado acorazado;
Portaaviones portaaviones;
Submarino submarino;
Fragata fragata;
bool destructorUbicado = false, acorazadoUbicado = false, portaavionesUbicado = false, submarinoUbicado = false, fragataUbicada = false, embarcacionesUbicadas = false;
bool barcoEscogido = false;
bool destructorSeleccionado = true, acorazadoSeleccionado = false, portaavionesSeleccionado = false, submarinoSeleccionado = false, fragataSeleccionada = false;
bool seleccionActiva = false;
bool filaElegida = false, columnaElegida = false;
int filaInt, columnaInt;
bool inputMode = false;


//CREACION DE LA FUENTE Y EL TEXTO
sf::Text fila, columna;
sf::Font fuente;
std::string ingresoPorTeclado;
if (!fuente.loadFromFile("C:/Users/Gonzalo/Desktop/Database/PressStart2P.ttf")) {
    // SI NO CARGA LA FUENTE O HAY UN ERROR, SALE.
    return;
}

//PARA QUE APAREZCA UN TEXTO SOLICITANDO ALGO AL USUARIO
Text Ubicacion("Ubica tus barcos", fuente, 15);
Ubicacion.setPosition(50, 300);
Ubicacion.setFillColor(Color::White);

Text Situar("Donde deseas situar este barco",fuente,15);
Situar.setPosition(50,500);
Ubicacion.setFillColor(Color::White);

Text Fila("Fila: ",fuente,15);
Fila.setPosition(50,328);
Fila.setFillColor(Color::White);

Text Columna("Columna: ",fuente,15);
Columna.setPosition(50,356);
Fila.setFillColor(Color::White);

Text textoIngresadoPorUsuario("",fuente,15);
Columna.setPosition(50,384);
Fila.setFillColor(Color::White);


//SETEO DEL TABLERO QUE PASAMOS POR REFERENCIA
tableroUno.setPosicion(50,0);
tableroDos.setPosicion(400,0);


//PARA QUE APAREZCAN LOS NOMBRES DE LOS BARCOS
Text nombreDestructor(destructor.getNombre(),fuente,13);
nombreDestructor.setPosition(50, 328);
nombreDestructor.setFillColor(Color::Red);

Text nombreSubmarino(submarino.getNombre(),fuente,13);
nombreSubmarino.setPosition(50, 356);
nombreSubmarino.setFillColor(Color::White);

Text nombreAcorazado(acorazado.getNombre(),fuente,13);
nombreAcorazado.setPosition(50, 384);
nombreAcorazado.setFillColor(Color::White);

Text nombrePortaaviones(portaaviones.getNombre(),fuente,13);
nombrePortaaviones.setPosition(50, 412);
nombrePortaaviones.setFillColor(Color::White);

Text nombreFragata(fragata.getNombre(),fuente,13);
nombreFragata.setPosition(50, 440);
nombreFragata.setFillColor(Color::White);


while(_Ventana.isOpen()){
    Event ingresoPorTeclado;
    //RESPETAR EL ORDEN DE ESTOS DOS
    ProcesarEvento();
    _Ventana.clear();
    //HASTA ACA

    //TODA LA LOGICA VA AHORA
    if(embarcacionesUbicadas == false){

        if(destructorUbicado == false){

            if(destructorSeleccionado == true){
                nombreDestructor.setFillColor(Color::Red);
            }else{
                nombreDestructor.setFillColor(Color::White);
            }

            if(Keyboard::isKeyPressed(Keyboard::Down)){
                nombreDestructor.setFillColor(Color::White);
            }
            _Ventana.draw(nombreDestructor);
        }


        if(submarinoUbicado == false){
            _Ventana.draw(nombreSubmarino);
        if(submarinoSeleccionado == true){
                nombreSubmarino.setFillColor(Color::Red);
            }else{
                nombreSubmarino.setFillColor(Color::White);
            }

            if(Keyboard::isKeyPressed(Keyboard::Down)){
                nombreSubmarino.setFillColor(Color::White);
            }

        }

        if(acorazadoUbicado == false){
            if(acorazadoSeleccionado == true){
                nombreAcorazado.setFillColor(Color::Red);
            }else{
                nombreAcorazado.setFillColor(Color::White);
            }

            if(Keyboard::isKeyPressed(Keyboard::Down)){
                nombreAcorazado.setFillColor(Color::White);
            }
            _Ventana.draw(nombreAcorazado);
        }


        if(portaavionesUbicado == false){
                if(portaavionesSeleccionado == true){
                nombrePortaaviones.setFillColor(Color::Red);
            }else{
                nombrePortaaviones.setFillColor(Color::White);
            }

            if(Keyboard::isKeyPressed(Keyboard::Down)){
                nombrePortaaviones.setFillColor(Color::White);
            }
            _Ventana.draw(nombrePortaaviones);
        }

        if(fragataUbicada == false){
                 if(fragataSeleccionada == true){
                nombreFragata.setFillColor(Color::Red);
            }else{
                nombreFragata.setFillColor(Color::White);
            }

            if(Keyboard::isKeyPressed(Keyboard::Down)){
                nombreFragata.setFillColor(Color::White);
            }
             _Ventana.draw(nombreFragata);
        }

        if(Keyboard::isKeyPressed(Keyboard::Up)){
            if (destructorSeleccionado) {
            destructorSeleccionado = false;
            fragataSeleccionada = true;
            } else if (submarinoSeleccionado) {
            submarinoSeleccionado = false;
            destructorSeleccionado = true;
            } else if (acorazadoSeleccionado) {
            acorazadoSeleccionado = false;
            submarinoSeleccionado = true;
            } else if (portaavionesSeleccionado) {
            portaavionesSeleccionado = false;
            acorazadoSeleccionado = true;
            } else if (fragataSeleccionada) {
            fragataSeleccionada = false;
            portaavionesSeleccionado = true;}
            sf::sleep(sf::milliseconds(150));
            }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (destructorSeleccionado) {
            destructorSeleccionado = false;
            submarinoSeleccionado = true;
            } else if (submarinoSeleccionado) {
            submarinoSeleccionado = false;
            acorazadoSeleccionado = true;
            } else if (acorazadoSeleccionado) {
            acorazadoSeleccionado = false;
            portaavionesSeleccionado = true;
            } else if (portaavionesSeleccionado) {
            portaavionesSeleccionado = false;
            fragataSeleccionada = true;
            } else if (fragataSeleccionada) {
            fragataSeleccionada = false;
            destructorSeleccionado = true;
            }
            sf::sleep(sf::milliseconds(150));
            }



    //HASTA ACA LA LOGICA
    //RESPETAR EL ORDEN DE ESTOS DOS
    //UBICAR DESTRUCTOR
    if(Keyboard::isKeyPressed(Keyboard::Space) || destructorSeleccionado == true && seleccionActiva == true){
        inputMode = true;
        _Ventana.clear();
        if(inputMode == true){
        if(tableroUno.ubicarDestructor(destructor,tableroUno) == true){
            destructorUbicado = true;
        }
        inputMode = false;

        }
    }


    _Ventana.draw(tableroUno);
    _Ventana.draw(tableroDos);
    if(Keyboard::isKeyPressed(Keyboard::Space) == false && seleccionActiva == false){
        _Ventana.draw(Ubicacion);
    }
    if(destructorUbicado == true){
        _Ventana.draw(destructor);
    }
    _Ventana.display();
    }
}

}




