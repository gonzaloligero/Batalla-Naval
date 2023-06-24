#include <iostream>
#include "Juego.h"
#include "Tablero.h"
#include "Agua.h"
#include "Caza.h"
#include "Nagronar.h"
#include "Ghost.h"
#include "Nautilus.h"
#include "Klosternator.h"
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace sf;

Juego::Juego() : _Ventana(sf::VideoMode(800, 600), "BATTLESHIP ULTIMATE"){
_Ventana.setFramerateLimit(30);
}

void Juego::Dibujar(){

    _Ventana.clear();

    _Ventana.display();

}

void Juego::GameLoop() {
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
int opcionSeleccionada = -1; // Inicialmente ninguna opción está seleccionada
bool mostrarPulsaEnter = true, modoClasico = false, modoHistoria = false, modoPersonalizado = false, modoKloster = false, modoKlosterVisible = false;
bool mostrarOpcionesPrincipales = false;
sf::Sprite recuadro;
sf::Texture textura;

recuadro.setPosition(30,400);

textura.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Recuadro.png");
//recuadro.setScale(0.2f, 0.2f);
recuadro.setTexture(textura);

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
    opcion1.setPosition(274, 427);

    sf::Text opcion2("Modo Clasico", font, 20);
    opcion2.setPosition(274, 455);

    sf::Text opcion3("Modo Personalizado", font, 20);
    opcion3.setPosition(274, 483);

    sf::Text opcion4("?", font, 20);
    opcion4.setPosition(274, 511);

    sf::Text opcion5("Puntajes", font, 20);
    opcion5.setPosition(274, 539);

    sf::Text opcion6("Salir", font, 20);
    opcion6.setPosition(274, 567);


    if (!_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Menu/Slow Ride.wav")) {
        // Manejar error si no se puede cargar la música
        // Por ejemplo, mostrar un mensaje de error y continuar sin música
    }
    //ACTIVAR MUSICA PANTALLA PRINCIPAL LUEGO
    //_Musica.play();

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

        if(Keyboard::isKeyPressed(Keyboard::G) && Keyboard::isKeyPressed(Keyboard::E) && Keyboard::isKeyPressed(Keyboard::N) && Keyboard::isKeyPressed(Keyboard::T) && Keyboard::isKeyPressed(Keyboard::E) && Keyboard::isKeyPressed(Keyboard::S)){
            modoKlosterVisible = true;
        }

        if(mostrarOpcionesPrincipales == true){
                _Ventana.draw(recuadro);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                opcionSeleccionada = (opcionSeleccionada - 1 + 6) % 6;
                sf::sleep(sf::milliseconds(150)); // Pausa de 150 milisegundos
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                opcionSeleccionada = (opcionSeleccionada + 1) % 6;
                sf::sleep(sf::milliseconds(150)); // Pausa de 150 milisegundos
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                if (opcionSeleccionada == 6) {
                    _Ventana.close(); // Cierra la ventana
                    return; // Salir de la función PantallaPrincipal()
                }

        if (mostrarOpcionesPrincipales == true) {
                    // Lógica para cada opción seleccionada
        switch (opcionSeleccionada) {
        case 0: _Ventana.clear();
                mostrarOpcionesPrincipales = false;
                modoHistoria = true;
                _Musica.stop();
                ModoHistoria(_Ventana);
                modoHistoria = false;
                mostrarOpcionesPrincipales = true;
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
        case 2: _Ventana.clear();
                mostrarOpcionesPrincipales = false;
                modoPersonalizado = true;
                _Musica.stop();
                ModoPersonalizado(_Ventana);
                modoPersonalizado = false;
                mostrarOpcionesPrincipales = true;

        break;
        case 3: _Ventana.clear();
                if(modoKlosterVisible == true){
                    mostrarOpcionesPrincipales = false;
                    modoKloster = true;
                    _Musica.stop();
                    ModoKloster(_Ventana);
                    modoKloster = false;
                    mostrarOpcionesPrincipales = true;
                }
                // Lógica para la opción 4 (Modo Kloster)
        break;
        case 4:
                // Lógica para la opción 5 (Puntajes)
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
        opcion5.setFillColor(opcionSeleccionada == 4 ? sf::Color::Red : sf::Color::White);
        opcion6.setFillColor(opcionSeleccionada == 5 ? sf::Color::Red : sf::Color::White);

        // Dibujar las opciones en la ventana
        if (!mostrarPulsaEnter) {
            _Ventana.draw(opcion1);
            _Ventana.draw(opcion2);
            _Ventana.draw(opcion3);
            if(modoKlosterVisible == true){
                 _Ventana.draw(opcion4);
            }
            _Ventana.draw(opcion5);
            _Ventana.draw(opcion6);
        }

        _Ventana.display();
    }
}



void Juego::ModoClasico(sf::RenderWindow &_Ventana){

Tablero tableroUno, tableroDos;
Destructor destructor, destructorEnemigo;
Acorazado acorazado, acorazadoEnemigo;
Portaaviones portaaviones, portaavionesEnemigo;
Submarino submarino,submarinoEnemigo;
Fragata fragata,fragataEnemigo;
bool destructorUbicado = false, acorazadoUbicado = false, portaavionesUbicado = false, submarinoUbicado = false, fragataUbicada = false, embarcacionesUbicadas = false;
bool embarcacionesEnemigasUbicadas = false;
int turno = 0, filaInt, columnaInt;
bool inputMode = false, partidaTerminada = false;
bool ganadorHumano = false, ganadorIA = false;
int filaIA,columnaIA;
Fuego miFuego;
Agua miAgua;
sf::Sprite recuadro;
sf::Texture texture;

recuadro.setPosition(30,311);

texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Recuadro.png");
//recuadro.setScale(0.2f, 0.2f);
recuadro.setTexture(texture);

//MUSICA DEL MODO CLASICO
if (!_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Menu/Daft Punk.wav")) {
        //SI HAY UN ERROR PARA ABRIR EL ARCHIVO DE MUSICA, SE SALE.
        return;}

//CREACION DE LA FUENTE Y EL TEXTO
sf::Font fuente;
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

Text Felicitaciones("Has ganado la partida",fuente, 15);
Felicitaciones.setPosition(50,500);
Felicitaciones.setFillColor(Color::White);

Text Impacto("Has impactado en un barco rival",fuente, 15);
Impacto.setPosition(50,500);
Impacto.setFillColor(Color::White);

//SETEO DEL TABLERO QUE PASAMOS POR REFERENCIA
tableroUno.setPosicion(50,0);
tableroDos.setPosicion(400,0);


//PARA QUE APAREZCAN LOS NOMBRES DE LOS BARCOS
Text nombreDestructor("1) Destructor",fuente,13);
nombreDestructor.setPosition(50, 328);
nombreDestructor.setFillColor(Color::White);

Text nombreSubmarino("2) Submarino",fuente,13);
nombreSubmarino.setPosition(50, 356);
nombreSubmarino.setFillColor(Color::White);

Text nombreAcorazado("3) Acorazado",fuente,13);
nombreAcorazado.setPosition(50, 384);
nombreAcorazado.setFillColor(Color::White);

Text nombrePortaaviones("4) Portaaviones",fuente,13);
nombrePortaaviones.setPosition(50, 412);
nombrePortaaviones.setFillColor(Color::White);

Text nombreFragata("5) Fragata",fuente,13);
nombreFragata.setPosition(50, 440);
nombreFragata.setFillColor(Color::White);

Text rivalUbicando("El rival está ubicando sus unidades",fuente,13);
rivalUbicando.setPosition(50,440);
rivalUbicando.setFillColor(Color::White);

Text preparateParaLaBatalla("Preparate para la batalla",fuente,13);
rivalUbicando.setPosition(50,468);
rivalUbicando.setFillColor(Color::White);


while(_Ventana.isOpen()){


    //RESPETAR EL ORDEN DE ESTOS DOS
    //PROCESAR EVENTO PERMITE APRETAR ESCAPE PARA RETORNAR A UN MENU ANTERIOR Y CIERRA LA VENTANA SI ES NECESARIO
    ProcesarEvento();
    if(Keyboard::isKeyPressed(Keyboard::Escape) == true){
        return;
    }
    //VENTANA CLEAR LIMPIA TODA LA IMAGEN DE LA VENTANA
    _Ventana.clear();
    //HASTA ACA
    _Ventana.draw(recuadro);
    //TODA LA LOGICA VA AHORA
    //FASE DE PREPARACIÓN
    //VENTANA DRAW DIBUJA LO QUE PASAMOS COMO PARÁMETRO
    _Ventana.draw(tableroUno);
    _Ventana.draw(tableroDos);
    if(embarcacionesUbicadas == false){

        //MOSTRAMOS LOS NOMBRES DE LOS BARCOS
        //ESTO IRA DESAPARECIENDO A MEDIDA QUE SE UBICA UN BARCO EN EL TABLERO
        if(destructorUbicado == false){
            _Ventana.draw(nombreDestructor);}
        if(submarinoUbicado == false){
            _Ventana.draw(nombreSubmarino);}
        if(acorazadoUbicado == false){
            _Ventana.draw(nombreAcorazado);}
        if(portaavionesUbicado == false){
            _Ventana.draw(nombrePortaaviones);}
        if(fragataUbicada == false){
            _Ventana.draw(nombreFragata);}


    //UBICAR BARCOS UTILIZANDO CONSOLA
    //1 UBICA DESTRUCTOR
    if(Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)){
        if(destructorUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarDestructor(destructor,tableroUno) == true){
            destructorUbicado = true;}
            inputMode = false;}
                }
            }
    //2 UBICA SUBMARINO
    if(Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)){
        if(submarinoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarSubmarino(submarino,tableroUno) == true){
            submarinoUbicado = true;}
            inputMode = false;}
                }
            }
    //3 UBICA ACORAZADO
    if(Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)){
        if(acorazadoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarAcorazado(acorazado,tableroUno) == true){
            acorazadoUbicado = true;}
            inputMode = false;}
                }
            }
    //4 UBICA PORTAAVIONES
    if(Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)){
        if(portaavionesUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarPortaaviones(portaaviones,tableroUno) == true){
            portaavionesUbicado = true;}
            inputMode = false;}
                }
            }
    //5 UBICA FRAGATA
    if(Keyboard::isKeyPressed(Keyboard::Num5) || Keyboard::isKeyPressed(Keyboard::Numpad5)){
        if(fragataUbicada == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarFragata(fragata,tableroUno) == true){
            fragataUbicada = true;
            }
            inputMode = false;}
                }
            }



    if(embarcacionesUbicadas == false){
        //SI LOS BARCOS SE UBICARON, NO SE MOSTRARÁ MÁS EL MENSAJE "UBICA TUS BARCOS"
        _Ventana.draw(Ubicacion);
        if(destructorUbicado == true){
        _Ventana.draw(destructor);}
        if(fragataUbicada == true){
        _Ventana.draw(fragata);}
        if(submarinoUbicado == true){
        _Ventana.draw(submarino);}
        if(portaavionesUbicado == true){
            _Ventana.draw(portaaviones);}
        if(acorazadoUbicado == true){
            _Ventana.draw(acorazado);}
        }

    //SALIMOS DEL WHILE SI SE UBICARON TODOS LOS BARCOS
    if(destructorUbicado == true && fragataUbicada == true && submarinoUbicado == true && portaavionesUbicado == true && acorazadoUbicado == true){
        embarcacionesUbicadas = true;}
    }

    //LIMPIAMOS EL NOMBRE DEL ULTIMO BARCO CON EL .CLEAR() Y MOSTRAMOS LOS SPRITES CON LOS .DRAW Y .DISPLAY
    if(embarcacionesUbicadas == true){
        _Ventana.clear();
        _Ventana.draw(tableroUno);
        _Ventana.draw(tableroDos);
        _Ventana.draw(destructor);
        _Ventana.draw(acorazado);
        _Ventana.draw(fragata);
        _Ventana.draw(portaaviones);
        _Ventana.draw(submarino);
        _Ventana.display();}

    //ACA PODEMOS AGREGAR UNA OPCION PARA CONSULTARLE QUE TIPO DE NIVEL DESEA ENFRENTAR
    //ESTE NIVEL ES EL NUMERO 1 DEL MODO HISTORIA
    if(embarcacionesUbicadas == true && embarcacionesEnemigasUbicadas == false){
        embarcacionesEnemigasUbicadas = tableroDos.completarTableroEnemigoNivel1(tableroDos);}


    //TODOS LOS BARCOS UBICADOS. EMPIEZA LA FASE DE ATAQUE

        if(embarcacionesUbicadas == true && embarcacionesEnemigasUbicadas == true){
         //_Musica.play();
        while(partidaTerminada == false){
            //INPUTMODE ES SIMPLEMENTE PARA DETECTAR SI SE NECESITA USAR LA CONSOLA
            inputMode = true;
            //SI EL TURNO ES PAR, ATACA EL HUMANO. SI ES IMPAR, ATACA LA IA
            turno++;

        if(turno % 2 == 0){
            //TURNO JUGADOR HUMANO
            miFuego.getSonido().play();
            cout<<"FILA: ";
            cin>>filaInt;
            cout<<"COLUMNA: ";
            cin>>columnaInt;
            if(tableroDos.atacar(filaInt,columnaInt,tableroDos) == true){
                miFuego._sound.play();
            }else{
                miAgua._sound.play();
            }
            system("PAUSE");
            system("cls");
            if(tableroDos.evaluarTablero(tableroDos) == true){
                cout<<"Has eliminado a tu rival. Partida terminada"<<endl;
                ganadorHumano = true;
                partidaTerminada = true;}
            //ESTO LUEGO HAY QUE SACAR
            cout<<"Tablero IA"<<endl;
            tableroDos.mostrarTablero(tableroDos);
            }else{
            //TURNO IA
            tableroUno.atacaIA(tableroUno, _Ventana);
            if(tableroUno.evaluarTablero(tableroUno) == true){
                cout<<"El enemigo nos ha derrotado. Partida terminada"<<endl;
                ganadorIA = true;
                partidaTerminada = true;
                ;
                }
            system("PAUSE");
            system("cls");
            //ESTO LUEGO HAY QUE SACAR
            cout<<"Tablero Humano"<<endl;
            tableroUno.mostrarTablero(tableroUno);}
                }
        }

    if(partidaTerminada == true){
        return;}
        _Ventana.display();
    }
}

void Juego::Nivel1(sf::RenderWindow &v){

Tablero tableroUno, tableroDos;
Destructor destructor, destructorEnemigo;
Acorazado acorazado, acorazadoEnemigo;
Portaaviones portaaviones, portaavionesEnemigo;
Submarino submarino,submarinoEnemigo;
Fragata fragata,fragataEnemigo;
bool destructorUbicado = false, acorazadoUbicado = false, portaavionesUbicado = false, submarinoUbicado = false, fragataUbicada = false, embarcacionesUbicadas = false;
bool embarcacionesEnemigasUbicadas = false;
int turno = 0, filaInt, columnaInt, nroAvion, nroAvionIA;
bool inputMode = false, partidaTerminada = false;
bool ganadorHumano = false, ganadorIA = false;
bool avionElegido = false, supremaciaHumano = false, apoyoUtilizado = false;
bool avionElegidoIA = false, supremaciaIA = false, apoyoUtilizadoIA = false;
Fuego miFuego;
Agua miAgua;
int filaSupremaciaHumano, filaSupremaciaIA, filaBombarderoHumano,filaBombarderoIA, fila1,fila2,fila3,columna1,columna2,columna3,reconHumano1,reconHumano2,reconHumano3;
int fila1IA,fila2IA,fila3IA,columna1IA,columna2IA,columna3IA, reconIA1,reconIA2,reconIA3;

if (!_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Enemigos menores/Digital Love.wav")) {
        // Manejar error si no se puede cargar la música
        // Por ejemplo, mostrar un mensaje de error y continuar sin música
    }
    //ACTIVAR MUSICA GHOST
    _Musica.setVolume(50);
    _Musica.play();

//RAND PARA ELECCION DEL AVION IA
srand(time(NULL));
int eleccionAvionIA;
int contadorImpactos = 0, filaIA, columnaIA;
sf::Sprite recuadro;
sf::Texture texture;
recuadro.setPosition(30,311);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Recuadro.png");
//recuadro.setScale(0.2f, 0.2f);
recuadro.setTexture(texture);

//CREACION DE LA FUENTE Y EL TEXTO
sf::Font fuente;
if (!fuente.loadFromFile("C:/Users/Gonzalo/Desktop/Database/PressStart2P.ttf")) {
    // SI NO CARGA LA FUENTE O HAY UN ERROR, SALE.
    return;
}

Text EleccionAvion("¿Que avion deseas utilizar?",fuente,15);
EleccionAvion.setPosition(50,300);
EleccionAvion.setFillColor(Color::White);

Text nombreBombardero("B) Bombardero",fuente,13);
nombreBombardero.setPosition(50, 328);
nombreBombardero.setFillColor(Color::White);

Text nombreCaza("C) Caza",fuente,13);
nombreCaza.setPosition(50, 356);
nombreCaza.setFillColor(Color::White);

Text nombreDron("D) Dron",fuente,13);
nombreDron.setPosition(50, 384);
nombreDron.setFillColor(Color::White);

Text nombreReconocimiento("R) Reconocimiento",fuente,13);
nombreReconocimiento.setPosition(50, 412);
nombreReconocimiento.setFillColor(Color::White);




//PARA QUE APAREZCA UN TEXTO SOLICITANDO ALGO AL USUARIO
Text Ubicacion("Ubica tus barcos", fuente, 15);
Ubicacion.setPosition(50, 300);
Ubicacion.setFillColor(Color::White);

Text descripcion1("Estás en el NIVEL 1", fuente, 15);
descripcion1.setPosition(50, 328);
descripcion1.setFillColor(Color::White);

Text descripcion2("Te enfrentas a 5 naves enemigas", fuente, 15);
descripcion2.setPosition(50, 356);
descripcion2.setFillColor(Color::White);

Text descripcion3("El enemigo ocupa sólo 1 casilla", fuente, 15);
descripcion3.setPosition(50, 384);
descripcion3.setFillColor(Color::White);

Text descripcion4("Derrotalo para mantener viva la esperanza", fuente, 15);
descripcion4.setPosition(50, 412);
descripcion4.setFillColor(Color::White);

//SETEO DEL TABLERO QUE PASAMOS POR REFERENCIA
tableroUno.setPosicion(50,0);
tableroDos.setPosicion(400,0);


//PARA QUE APAREZCAN LOS NOMBRES DE LOS BARCOS
Text nombreDestructor("1) Destructor",fuente,13);
nombreDestructor.setPosition(50, 328);
nombreDestructor.setFillColor(Color::White);

Text nombreSubmarino("2) Submarino",fuente,13);
nombreSubmarino.setPosition(50, 356);
nombreSubmarino.setFillColor(Color::White);

Text nombreAcorazado("3) Acorazado",fuente,13);
nombreAcorazado.setPosition(50, 384);
nombreAcorazado.setFillColor(Color::White);

Text nombrePortaaviones("4) Portaaviones",fuente,13);
nombrePortaaviones.setPosition(50, 412);
nombrePortaaviones.setFillColor(Color::White);

Text nombreFragata("5) Fragata",fuente,13);
nombreFragata.setPosition(50, 440);
nombreFragata.setFillColor(Color::White);

Text rivalUbicando("El rival está ubicando sus unidades",fuente,13);
rivalUbicando.setPosition(50,440);
rivalUbicando.setFillColor(Color::White);

Text preparateParaLaBatalla("Preparate para la batalla",fuente,13);
rivalUbicando.setPosition(50,468);
rivalUbicando.setFillColor(Color::White);


while(_Ventana.isOpen()){
    //VENTANA CLEAR LIMPIA TODA LA IMAGEN DE LA VENTANA
    _Ventana.clear();
    //RESPETAR EL ORDEN DE ESTOS DOS
    //PROCESAR EVENTO PERMITE APRETAR ESCAPE PARA RETORNAR A UN MENU ANTERIOR Y CIERRA LA VENTANA SI ES NECESARIO
    ProcesarEvento();
    if(Keyboard::isKeyPressed(Keyboard::Escape) == true){
        return;
    }

    //HASTA ACA
    _Ventana.draw(recuadro);
    _Ventana.draw(tableroUno);



    if(avionElegido == false){
        _Ventana.draw(EleccionAvion);
        _Ventana.draw(nombreBombardero);
        _Ventana.draw(nombreCaza);
        _Ventana.draw(nombreDron);
        _Ventana.draw(nombreReconocimiento);

        if(Keyboard::isKeyPressed(Keyboard::B)){
            cout<<"Has escogido el Bombardero como tu avion de apoyo"<<endl;
            cout<<"Este avion te permitira destruir una fila completa del enemigo una sola vez"<<endl;
            Bombardero bombardero;
            filaBombarderoHumano = bombardero.bombardear();
            system("cls");
            nroAvion = 1;
            _Ventana.clear();
            avionElegido = true;
        }

        if(Keyboard::isKeyPressed(Keyboard::C)){
            cout<<"Has escogido el Caza como tu avion de apoyo"<<endl;
            cout<<"Este avion te otorgará superioridad aerea en una fila especifica"<<endl;
            Caza caza;
            filaSupremaciaHumano = caza.otorgarSupremacia();
            system("cls");
            supremaciaHumano = true;
            nroAvion = 2;
            _Ventana.clear();
            avionElegido = true;
        }

        if(Keyboard::isKeyPressed(Keyboard::D)){
            cout<<"Has escogido el Dron como tu avion de apoyo"<<endl;
            cout<<"Este avion te permitira hacer tres ataques adicionales"<<endl;
            cout<<"Elige tus tres ataques"<<endl;
            Dron dron;
            cout<<"Primer ataque"<<endl;
            fila1 = dron.atacarFila();
            columna1 = dron.atacarColumna();
            cout<<endl;
            cout<<"Segundo ataque"<<endl;
            fila2 = dron.atacarFila();
            columna2 = dron.atacarColumna();
            cout<<endl;
            cout<<"Tercer ataque"<<endl;
            fila3 = dron.atacarFila();
            columna3 = dron.atacarColumna();
            system("cls");
            nroAvion = 3;
            _Ventana.clear();
            avionElegido = true;
        }

        if(Keyboard::isKeyPressed(Keyboard::R)){
            cout<<"Has escogido el Reconocimiento como tu avion de apoyo"<<endl;
            cout<<"Este avion te otorgara deteccion del rival en tres filas"<<endl;
            Reconocimiento reconocimiento;
            cout<<"Primera deteccion"<<endl;
            reconHumano1 = reconocimiento.detectar();
            cout<<"Segundo deteccion"<<endl;
            reconHumano2 = reconocimiento.detectar();
            cout<<"Tercera deteccion"<<endl;
            reconHumano3 = reconocimiento.detectar();
            system("cls");
            nroAvion = 4,
            _Ventana.clear();
            avionElegido = true;
        }
    }

    //IA ELIGE SU AVION

    if(avionElegidoIA == false && avionElegido == true){
        eleccionAvionIA = rand()%4+1;

        if(eleccionAvionIA == 1){
            cout<<"El rival ha elegido el Bombardero como avion de apoyo"<<endl;
            system("PAUSE");
            Bombardero bombarderoIA;
            filaBombarderoIA = bombarderoIA.bombardearIA();
            system("cls");
            nroAvionIA = 1;
            _Ventana.clear();
            avionElegidoIA = true;}

        if(eleccionAvionIA == 2){
            cout<<"El rival ha elegido el Caza como avion de apoyo"<<endl;
            system("PAUSE");
            Caza cazaIA;
            filaSupremaciaIA = cazaIA.otorgarSupremaciaIA();
            system("cls");
            supremaciaIA = true;
            nroAvionIA = 2;
            _Ventana.clear();
            avionElegidoIA = true;}

        if(eleccionAvionIA == 3){
            cout<<"El rival ha elegido el Dron como su avion de apoyo"<<endl;
            system("PAUSE");
            Dron dronIA;
            fila1IA = dronIA.atacarFilaIA();
            columna1IA = dronIA.atacarColumnaIA();
            fila2IA = dronIA.atacarFilaIA();
            columna2IA = dronIA.atacarColumnaIA();
            fila3IA = dronIA.atacarFilaIA();
            columna3IA = dronIA.atacarColumnaIA();
            system("cls");
            _Ventana.clear();
            nroAvionIA = 3;
            avionElegidoIA = true;}

        if(eleccionAvionIA == 4){
            cout<<"El rival ha elegido el Reconocimiento como su avion de apoyo"<<endl;
            system("PAUSE");
            Reconocimiento reconocimientoIA;
            reconIA1 = reconocimientoIA.detectarIA();
            reconIA2 = reconocimientoIA.detectarIA();
            reconIA3 = reconocimientoIA.detectarIA();
            system("cls");
            nroAvionIA = 4;
            avionElegidoIA = true;
            _Ventana.clear();}
            }



    //TODA LA LOGICA VA AHORA
    //FASE DE PREPARACIÓN
    //VENTANA DRAW DIBUJA LO QUE PASAMOS COMO PARÁMETRO
    //_Ventana.draw(tableroUno);
    if(embarcacionesUbicadas == false && avionElegido == true){

        //MOSTRAMOS LOS NOMBRES DE LOS BARCOS
        //ESTO IRA DESAPARECIENDO A MEDIDA QUE SE UBICA UN BARCO EN EL TABLERO
        if(destructorUbicado == false){
            _Ventana.draw(nombreDestructor);}
        if(submarinoUbicado == false){
            _Ventana.draw(nombreSubmarino);}
        if(acorazadoUbicado == false){
            _Ventana.draw(nombreAcorazado);}
        if(portaavionesUbicado == false){
            _Ventana.draw(nombrePortaaviones);}
        if(fragataUbicada == false){
            _Ventana.draw(nombreFragata);}


    //UBICAR BARCOS UTILIZANDO CONSOLA
    //1 UBICA DESTRUCTOR
    if(Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)){
        if(destructorUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarDestructor(destructor,tableroUno) == true){
            destructorUbicado = true;}
            inputMode = false;}
                }
            }
    //2 UBICA SUBMARINO
    if(Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)){
        if(submarinoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarSubmarino(submarino,tableroUno) == true){
            submarinoUbicado = true;}
            inputMode = false;}
                }
            }
    //3 UBICA ACORAZADO
    if(Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)){
        if(acorazadoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarAcorazado(acorazado,tableroUno) == true){
            acorazadoUbicado = true;}
            inputMode = false;}
                }
            }
    //4 UBICA PORTAAVIONES
    if(Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)){
        if(portaavionesUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarPortaaviones(portaaviones,tableroUno) == true){
            portaavionesUbicado = true;}
            inputMode = false;}
                }
            }
    //5 UBICA FRAGATA
    if(Keyboard::isKeyPressed(Keyboard::Num5) || Keyboard::isKeyPressed(Keyboard::Numpad5)){
        if(fragataUbicada == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarFragata(fragata,tableroUno) == true){
            fragataUbicada = true;}
            inputMode = false;}
                }
            }



    if(embarcacionesUbicadas == false){
        //SI LOS BARCOS SE UBICARON, NO SE MOSTRARÁ MÁS EL MENSAJE "UBICA TUS BARCOS"
        _Ventana.draw(Ubicacion);
        if(destructorUbicado == true){
        _Ventana.draw(destructor);}
        if(fragataUbicada == true){
        _Ventana.draw(fragata);}
        if(submarinoUbicado == true){
        _Ventana.draw(submarino);}
        if(portaavionesUbicado == true){
            _Ventana.draw(portaaviones);}
        if(acorazadoUbicado == true){
            _Ventana.draw(acorazado);}
        }

    //SALIMOS DEL WHILE SI SE UBICARON TODOS LOS BARCOS
    if(destructorUbicado == true && fragataUbicada == true && submarinoUbicado == true && portaavionesUbicado == true && acorazadoUbicado == true){
        embarcacionesUbicadas = true;}
        }

    //LIMPIAMOS EL NOMBRE DEL ULTIMO BARCO CON EL .CLEAR() Y MOSTRAMOS LOS SPRITES CON LOS .DRAW Y .DISPLAY
    if(embarcacionesUbicadas == true){
        _Ventana.draw(tableroUno);
        _Ventana.draw(destructor);
        _Ventana.draw(acorazado);
        _Ventana.draw(fragata);
        _Ventana.draw(portaaviones);
        _Ventana.draw(submarino);
        _Ventana.draw(recuadro);
        _Ventana.draw(descripcion1);
        _Ventana.draw(descripcion2);
        _Ventana.draw(descripcion3);
        _Ventana.draw(descripcion4);
        _Ventana.display();}

    //ACA PODEMOS AGREGAR UNA OPCION PARA CONSULTARLE QUE TIPO DE NIVEL DESEA ENFRENTAR
    //ESTE NIVEL ES EL NUMERO 1 DEL MODO HISTORIA
    if(embarcacionesUbicadas == true && embarcacionesEnemigasUbicadas == false){
        embarcacionesEnemigasUbicadas = tableroDos.completarTableroEnemigoNivel1(tableroDos);}


    //TODOS LOS BARCOS UBICADOS. EMPIEZA LA FASE DE ATAQUE

        if(embarcacionesUbicadas == true && embarcacionesEnemigasUbicadas == true){

        while(partidaTerminada == false){
        Dibujar();
        _Ventana.draw(tableroUno);
        _Ventana.draw(destructor);
        _Ventana.draw(acorazado);
        _Ventana.draw(fragata);
        _Ventana.draw(portaaviones);
        _Ventana.draw(submarino);
        _Ventana.draw(recuadro);
        _Ventana.draw(descripcion1);
        _Ventana.draw(descripcion2);
        _Ventana.draw(descripcion3);
        _Ventana.draw(descripcion4);
        miFuego._sprite.setPosition(85,15);
        _Ventana.draw(miFuego);
        _Ventana.display();
            //SI EL TURNO ES PAR, ATACA EL HUMANO. SI ES IMPAR, ATACA LA IA
            turno++;

        //TERMINAR PARA HUMANO. TENER EN CUENTA EL CAZA
        if(apoyoUtilizado == false){
        switch(nroAvion){
        case 1: tableroDos.getAtaqueBombardero(filaBombarderoHumano,supremaciaIA,filaSupremaciaIA);
                apoyoUtilizado = true;
        break;
        case 3: tableroDos.getAtaqueDron(fila1,columna1, supremaciaIA, filaSupremaciaIA);
                tableroDos.getAtaqueDron(fila2,columna2, supremaciaIA, filaSupremaciaIA);
                tableroDos.getAtaqueDron(fila3,columna3, supremaciaIA, filaSupremaciaIA);
                apoyoUtilizado = true;
        break;
        case 4: tableroDos.getReconocimiento(reconHumano1,tableroDos);
                tableroDos.getReconocimiento(reconHumano2,tableroDos);
                tableroDos.getReconocimiento(reconHumano3,tableroDos);
                apoyoUtilizado = true;
        break;
            }
        }
         //TERMINAR PARA EL RIVAL

        if(apoyoUtilizadoIA == false){
        switch(nroAvionIA){
        case 1: tableroUno.getAtaqueBombarderoIA(filaBombarderoIA,supremaciaHumano,filaSupremaciaHumano);
                apoyoUtilizadoIA = true;
        break;
        case 3:tableroUno.getAtaqueDron(fila1IA,columna1IA,supremaciaHumano,filaSupremaciaHumano);
                tableroUno.getAtaqueDron(fila2IA,columna2IA,supremaciaHumano,filaSupremaciaHumano);
                tableroUno.getAtaqueDron(fila3IA,columna3IA,supremaciaHumano,filaSupremaciaHumano);
                apoyoUtilizadoIA = true;
        break;
        //NO METI RECONOCIMIENTO PORQUE SE VA A USAR EN LA FASE DE ATAQUE
            }
        }


            if(turno % 2 == 0){
            //TURNO JUGADOR HUMANO
                cout<<"FILA: ";
                cin>>filaInt;
                cout<<"COLUMNA: ";
                cin>>columnaInt;
                 if(tableroDos.atacar(filaInt,columnaInt,tableroDos) == true){
                //miFuego._sound.play();
                }else{
                //miAgua._sound.play();
                }
                system("PAUSE");
                system("cls");
                if(tableroDos.evaluarTablero(tableroDos) == true){
                cout<<"Has eliminado a tu rival. Partida terminada"<<endl;
                _Musica.stop();
                ganadorHumano = true;
                partidaTerminada = true;}
                //ESTO LUEGO HAY QUE SACAR
                cout<<"Tablero IA"<<endl;
                tableroDos.mostrarTablero(tableroDos);}



            if(turno % 2 != 0){
                //TURNO IA
                if(apoyoUtilizadoIA == false && avionElegidoIA == 4){
                if(turno == 1){
                    tableroUno.getReconocimientoIA(reconIA1,tableroUno);}
                if(turno == 3){
                    tableroUno.getReconocimientoIA(reconIA2,tableroUno);}

                if(turno == 5){
                    tableroUno.getReconocimientoIA(reconIA3,tableroUno);
                    apoyoUtilizadoIA = true;}
            }
            tableroUno.atacaIA(tableroUno, _Ventana);
            system("PAUSE");
            system("cls");
            if(tableroUno.evaluarTablero(tableroUno) == true){
                cout<<"El enemigo nos ha derrotado. Partida terminada"<<endl;
                _Musica.stop();
                ganadorIA = true;
                partidaTerminada = true;}
            system("cls");
            //ESTO LUEGO HAY QUE SACAR
            cout<<"Tablero Humano"<<endl;
            tableroUno.mostrarTablero(tableroUno);
                }
            _Ventana.display();
            }//LLAVE WHILE
        }

    if(partidaTerminada == true){
        return;}
        _Ventana.display();}
}

void Juego::Nivel2(sf::RenderWindow &v){
Tablero tableroUno, tableroDos;
Destructor destructor, destructorEnemigo;
Acorazado acorazado, acorazadoEnemigo;
Portaaviones portaaviones, portaavionesEnemigo;
Submarino submarino,submarinoEnemigo;
Fragata fragata,fragataEnemigo;
bool destructorUbicado = false, acorazadoUbicado = false, portaavionesUbicado = false, submarinoUbicado = false, fragataUbicada = false, embarcacionesUbicadas = false;
bool ghostUbicado = false;
Ghost ghost;
Fuego miFuego;
Agua miAgua;
int turno = 0, filaInt, columnaInt, nroAvion;
bool partidaTerminada = false, inputMode = false;
bool ganadorHumano = false, ganadorIA = false;

if (!_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Jefes/Ghost.wav")) {
        // Manejar error si no se puede cargar la música
        // Por ejemplo, mostrar un mensaje de error y continuar sin música
    }
    //ACTIVAR MUSICA GHOST
    _Musica.setVolume(50);
    _Musica.play();


//RAND PARA ELECCION DEL AVION IA
srand(time(NULL));
sf::Sprite recuadro;
sf::Texture texture;
recuadro.setPosition(30,311);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Recuadro.png");
//recuadro.setScale(0.2f, 0.2f);
recuadro.setTexture(texture);

//CREACION DE LA FUENTE Y EL TEXTO
sf::Font fuente;
if (!fuente.loadFromFile("C:/Users/Gonzalo/Desktop/Database/PressStart2P.ttf")) {
    // SI NO CARGA LA FUENTE O HAY UN ERROR, SALE.
    return;
}



//PARA QUE APAREZCA UN TEXTO SOLICITANDO ALGO AL USUARIO
Text Ubicacion("Ubica tus barcos", fuente, 15);
Ubicacion.setPosition(50, 300);
Ubicacion.setFillColor(Color::White);

Text descripcion1("Estás en el NIVEL 2", fuente, 15);
descripcion1.setPosition(50, 328);
descripcion1.setFillColor(Color::White);

Text descripcion2("Te enfrentas a GHOST", fuente, 15);
descripcion2.setPosition(50, 356);
descripcion2.setFillColor(Color::White);

Text descripcion3("El enemigo ocupa sólo 1 casilla pero...", fuente, 15);
descripcion3.setPosition(50, 384);
descripcion3.setFillColor(Color::White);

Text descripcion4("Parece moverse constantemente", fuente, 15);
descripcion4.setPosition(50, 412);
descripcion4.setFillColor(Color::White);



//SETEO DEL TABLERO QUE PASAMOS POR REFERENCIA
tableroUno.setPosicion(50,0);
tableroDos.setPosicion(400,0);


//PARA QUE APAREZCAN LOS NOMBRES DE LOS BARCOS
Text nombreDestructor("1) Destructor",fuente,13);
nombreDestructor.setPosition(50, 328);
nombreDestructor.setFillColor(Color::White);

Text nombreSubmarino("2) Submarino",fuente,13);
nombreSubmarino.setPosition(50, 356);
nombreSubmarino.setFillColor(Color::White);

Text nombreAcorazado("3) Acorazado",fuente,13);
nombreAcorazado.setPosition(50, 384);
nombreAcorazado.setFillColor(Color::White);

Text nombrePortaaviones("4) Portaaviones",fuente,13);
nombrePortaaviones.setPosition(50, 412);
nombrePortaaviones.setFillColor(Color::White);

Text nombreFragata("5) Fragata",fuente,13);
nombreFragata.setPosition(50, 440);
nombreFragata.setFillColor(Color::White);




while(_Ventana.isOpen()){
    //RESPETAR EL ORDEN DE ESTOS DOS
    //PROCESAR EVENTO PERMITE APRETAR ESCAPE PARA RETORNAR A UN MENU ANTERIOR Y CIERRA LA VENTANA SI ES NECESARIO
    ProcesarEvento();
    if(Keyboard::isKeyPressed(Keyboard::Escape) == true){
        return;
    }
    //VENTANA CLEAR LIMPIA TODA LA IMAGEN DE LA VENTANA
    _Ventana.clear();
    //HASTA ACA
    _Ventana.draw(recuadro);
    _Ventana.draw(tableroUno);

    //TODA LA LOGICA VA AHORA
    //FASE DE PREPARACIÓN
    //VENTANA DRAW DIBUJA LO QUE PASAMOS COMO PARÁMETRO
    _Ventana.draw(tableroUno);
    if(embarcacionesUbicadas == false){

        //MOSTRAMOS LOS NOMBRES DE LOS BARCOS
        //ESTO IRA DESAPARECIENDO A MEDIDA QUE SE UBICA UN BARCO EN EL TABLERO
        if(destructorUbicado == false){
            _Ventana.draw(nombreDestructor);}
        if(submarinoUbicado == false){
            _Ventana.draw(nombreSubmarino);}
        if(acorazadoUbicado == false){
            _Ventana.draw(nombreAcorazado);}
        if(portaavionesUbicado == false){
            _Ventana.draw(nombrePortaaviones);}
        if(fragataUbicada == false){
            _Ventana.draw(nombreFragata);}


    //UBICAR BARCOS UTILIZANDO CONSOLA
    //1 UBICA DESTRUCTOR
    if(Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)){
        if(destructorUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarDestructor(destructor,tableroUno) == true){
            destructorUbicado = true;}
            inputMode = false;}
                }
            }
    //2 UBICA SUBMARINO
    if(Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)){
        if(submarinoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarSubmarino(submarino,tableroUno) == true){
            submarinoUbicado = true;}
            inputMode = false;}
                }
            }
    //3 UBICA ACORAZADO
    if(Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)){
        if(acorazadoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarAcorazado(acorazado,tableroUno) == true){
            acorazadoUbicado = true;}
            inputMode = false;}
                }
            }
    //4 UBICA PORTAAVIONES
    if(Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)){
        if(portaavionesUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarPortaaviones(portaaviones,tableroUno) == true){
            portaavionesUbicado = true;}
            inputMode = false;}
                }
            }
    //5 UBICA FRAGATA
    if(Keyboard::isKeyPressed(Keyboard::Num5) || Keyboard::isKeyPressed(Keyboard::Numpad5)){
        if(fragataUbicada == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarFragata(fragata,tableroUno) == true){
            fragataUbicada = true;}
            inputMode = false;}
                }
            }



    if(embarcacionesUbicadas == false){
        //SI LOS BARCOS SE UBICARON, NO SE MOSTRARÁ MÁS EL MENSAJE "UBICA TUS BARCOS"
        _Ventana.draw(Ubicacion);
        if(destructorUbicado == true){
        _Ventana.draw(destructor);}
        if(fragataUbicada == true){
        _Ventana.draw(fragata);}
        if(submarinoUbicado == true){
        _Ventana.draw(submarino);}
        if(portaavionesUbicado == true){
            _Ventana.draw(portaaviones);}
        if(acorazadoUbicado == true){
            _Ventana.draw(acorazado);}
        }

    //SALIMOS DEL WHILE SI SE UBICARON TODOS LOS BARCOS
    if(destructorUbicado == true && fragataUbicada == true && submarinoUbicado == true && portaavionesUbicado == true && acorazadoUbicado == true){
        embarcacionesUbicadas = true;}
    }

    //LIMPIAMOS EL NOMBRE DEL ULTIMO BARCO CON EL .CLEAR() Y MOSTRAMOS LOS SPRITES CON LOS .DRAW Y .DISPLAY
    if(embarcacionesUbicadas == true){
        _Ventana.clear();
        _Ventana.draw(tableroUno);
        _Ventana.draw(destructor);
        _Ventana.draw(acorazado);
        _Ventana.draw(fragata);
        _Ventana.draw(portaaviones);
        _Ventana.draw(submarino);
        _Ventana.draw(recuadro);
        _Ventana.draw(descripcion1);
        _Ventana.draw(descripcion2);
        _Ventana.draw(descripcion3);
        _Ventana.draw(descripcion4);
        ghost._sprite.setPosition(375,15);
        _Ventana.draw(ghost._sprite);
        _Ventana.display();}

    //ACA PODEMOS AGREGAR UNA OPCION PARA CONSULTARLE QUE TIPO DE NIVEL DESEA ENFRENTAR
    //ESTE NIVEL ES EL NUMERO 1 DEL MODO HISTORIA
    if(embarcacionesUbicadas == true && ghostUbicado == false){
        tableroDos.completarTableroNivelGhost(tableroDos);
        ghostUbicado = true;}


    //TODOS LOS BARCOS UBICADOS. EMPIEZA LA FASE DE ATAQUE
        if(embarcacionesUbicadas == true && ghostUbicado == true){
         //_Musica.play();
        while(partidaTerminada == false){
                _Ventana.clear();
            //SI EL TURNO ES PAR, ATACA EL HUMANO. SI ES IMPAR, ATACA LA IA
            turno++;

            if(turno % 2 == 0){
            //TURNO JUGADOR HUMANO
                cout<<"FILA: ";
                cin>>filaInt;
                cout<<"COLUMNA: ";
                cin>>columnaInt;
                 if(tableroDos.atacar(filaInt,columnaInt,tableroDos) == true){
                miFuego._sound.play();
                }else{
                miAgua._sound.play();
                }
                system("PAUSE");
                system("cls");
                if(tableroDos.evaluarTablero(tableroDos) == true){
                cout<<"Has derrotado a GHOST. Felicitaciones"<<endl;
                _Musica.stop();
                ganadorHumano = true;
                partidaTerminada = true;}
                //ESTO LUEGO HAY QUE SACAR
                cout<<"Tablero Humano"<<endl;
                tableroDos.mostrarTablero(tableroUno);}


            if(turno % 2 != 0){
                //TURNO IA
            tableroUno.atacaIA(tableroUno, _Ventana);
            //GHOST SE TELETRANSPORTA
            tableroDos.completarTableroNivelGhost(tableroDos);
            cout<<"Cuidado, "<<ghost.getNombre()<<" esta moviendo su ubicacion"<<endl;
            ghost._sound.play();
            system("PAUSE");
            system("cls");
            if(tableroUno.evaluarTablero(tableroUno) == true){
                cout<<"GHOST nos ha derrotado. Partida terminada"<<endl;
                _Musica.stop();
                ganadorIA = true;
                partidaTerminada = true;}
            system("cls");
            //ESTO LUEGO HAY QUE SACAR
            cout<<"Tablero IA"<<endl;
            tableroUno.mostrarTablero(tableroDos);}
            }//LLAVE WHILE
        }

    if(partidaTerminada == true){
        return;}
        _Ventana.display();}


}

void Juego::Nivel3(sf::RenderWindow &v){
Tablero tableroUno, tableroDos;
Destructor destructor, destructorEnemigo;
Acorazado acorazado, acorazadoEnemigo;
Portaaviones portaaviones, portaavionesEnemigo;
Submarino submarino,submarinoEnemigo;
Fragata fragata,fragataEnemigo;
bool destructorUbicado = false, acorazadoUbicado = false, portaavionesUbicado = false, submarinoUbicado = false, fragataUbicada = false, embarcacionesUbicadas = false;
bool embarcacionesEnemigasUbicadas = false;
int turno = 0, filaInt, columnaInt, nroAvion, nroAvionIA;
bool inputMode = false, partidaTerminada = false;
bool ganadorHumano = false, ganadorIA = false;
bool avionElegido = false, supremaciaHumano = false, apoyoUtilizado = false;
bool avionElegidoIA = false, supremaciaIA = false, apoyoUtilizadoIA = false;
Fuego miFuego;
Agua miAgua;
int filaSupremaciaHumano, filaSupremaciaIA, filaBombarderoHumano,filaBombarderoIA, fila1,fila2,fila3,columna1,columna2,columna3,reconHumano1,reconHumano2,reconHumano3;
int fila1IA,fila2IA,fila3IA,columna1IA,columna2IA,columna3IA, reconIA1,reconIA2,reconIA3;

if (!_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Enemigos menores/Digital Love.wav")) {
        // Manejar error si no se puede cargar la música
        // Por ejemplo, mostrar un mensaje de error y continuar sin música
    }
    //ACTIVAR MUSICA GHOST
    _Musica.setVolume(50);
    _Musica.play();

//RAND PARA ELECCION DEL AVION IA
srand(time(NULL));
int eleccionAvionIA;
int contadorImpactos = 0, filaIA, columnaIA;
sf::Sprite recuadro;
sf::Texture texture;
recuadro.setPosition(30,311);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Recuadro.png");
//recuadro.setScale(0.2f, 0.2f);
recuadro.setTexture(texture);

//CREACION DE LA FUENTE Y EL TEXTO
sf::Font fuente;
if (!fuente.loadFromFile("C:/Users/Gonzalo/Desktop/Database/PressStart2P.ttf")) {
    // SI NO CARGA LA FUENTE O HAY UN ERROR, SALE.
    return;
}

Text EleccionAvion("¿Que avion deseas utilizar?",fuente,15);
EleccionAvion.setPosition(50,300);
EleccionAvion.setFillColor(Color::White);

Text nombreBombardero("B) Bombardero",fuente,13);
nombreBombardero.setPosition(50, 328);
nombreBombardero.setFillColor(Color::White);

Text nombreCaza("C) Caza",fuente,13);
nombreCaza.setPosition(50, 356);
nombreCaza.setFillColor(Color::White);

Text nombreDron("D) Dron",fuente,13);
nombreDron.setPosition(50, 384);
nombreDron.setFillColor(Color::White);

Text nombreReconocimiento("R) Reconocimiento",fuente,13);
nombreReconocimiento.setPosition(50, 412);
nombreReconocimiento.setFillColor(Color::White);




//PARA QUE APAREZCA UN TEXTO SOLICITANDO ALGO AL USUARIO
Text Ubicacion("Ubica tus barcos", fuente, 15);
Ubicacion.setPosition(50, 300);
Ubicacion.setFillColor(Color::White);

Text descripcion1("Estás en el NIVEL 1", fuente, 15);
descripcion1.setPosition(50, 328);
descripcion1.setFillColor(Color::White);

Text descripcion2("Te enfrentas a 7 naves enemigas", fuente, 15);
descripcion2.setPosition(50, 356);
descripcion2.setFillColor(Color::White);

Text descripcion3("El enemigo ocupa sólo 1 casilla", fuente, 15);
descripcion3.setPosition(50, 384);
descripcion3.setFillColor(Color::White);

Text descripcion4("Derrotalo para mantener viva la esperanza", fuente, 15);
descripcion4.setPosition(50, 412);
descripcion4.setFillColor(Color::White);

//SETEO DEL TABLERO QUE PASAMOS POR REFERENCIA
tableroUno.setPosicion(50,0);
tableroDos.setPosicion(400,0);


//PARA QUE APAREZCAN LOS NOMBRES DE LOS BARCOS
Text nombreDestructor("1) Destructor",fuente,13);
nombreDestructor.setPosition(50, 328);
nombreDestructor.setFillColor(Color::White);

Text nombreSubmarino("2) Submarino",fuente,13);
nombreSubmarino.setPosition(50, 356);
nombreSubmarino.setFillColor(Color::White);

Text nombreAcorazado("3) Acorazado",fuente,13);
nombreAcorazado.setPosition(50, 384);
nombreAcorazado.setFillColor(Color::White);

Text nombrePortaaviones("4) Portaaviones",fuente,13);
nombrePortaaviones.setPosition(50, 412);
nombrePortaaviones.setFillColor(Color::White);

Text nombreFragata("5) Fragata",fuente,13);
nombreFragata.setPosition(50, 440);
nombreFragata.setFillColor(Color::White);

Text rivalUbicando("El rival está ubicando sus unidades",fuente,13);
rivalUbicando.setPosition(50,440);
rivalUbicando.setFillColor(Color::White);

Text preparateParaLaBatalla("Preparate para la batalla",fuente,13);
rivalUbicando.setPosition(50,468);
rivalUbicando.setFillColor(Color::White);


while(_Ventana.isOpen()){
    //RESPETAR EL ORDEN DE ESTOS DOS
    //PROCESAR EVENTO PERMITE APRETAR ESCAPE PARA RETORNAR A UN MENU ANTERIOR Y CIERRA LA VENTANA SI ES NECESARIO
    ProcesarEvento();
    if(Keyboard::isKeyPressed(Keyboard::Escape) == true){
        return;
    }
    //VENTANA CLEAR LIMPIA TODA LA IMAGEN DE LA VENTANA
    _Ventana.clear();
    //HASTA ACA
    _Ventana.draw(recuadro);
    _Ventana.draw(tableroUno);



    if(avionElegido == false){
        _Ventana.draw(EleccionAvion);
        _Ventana.draw(nombreBombardero);
        _Ventana.draw(nombreCaza);
        _Ventana.draw(nombreDron);
        _Ventana.draw(nombreReconocimiento);

        if(Keyboard::isKeyPressed(Keyboard::B)){
            cout<<"Has escogido el Bombardero como tu avion de apoyo"<<endl;
            cout<<"Este avion te permitira destruir una fila completa del enemigo una sola vez"<<endl;
            Bombardero bombardero;
            filaBombarderoHumano = bombardero.bombardear();
            system("cls");
            nroAvion = 1;
            _Ventana.clear();
            avionElegido = true;
        }

        if(Keyboard::isKeyPressed(Keyboard::C)){
            cout<<"Has escogido el Caza como tu avion de apoyo"<<endl;
            cout<<"Este avion te otorgará superioridad aerea en una fila especifica"<<endl;
            Caza caza;
            filaSupremaciaHumano = caza.otorgarSupremacia();
            system("cls");
            supremaciaHumano = true;
            nroAvion = 2;
            _Ventana.clear();
            avionElegido = true;
        }

        if(Keyboard::isKeyPressed(Keyboard::D)){
            cout<<"Has escogido el Dron como tu avion de apoyo"<<endl;
            cout<<"Este avion te permitira hacer tres ataques adicionales"<<endl;
            cout<<"Elige tus tres ataques"<<endl;
            Dron dron;
            cout<<"Primer ataque"<<endl;
            fila1 = dron.atacarFila();
            columna1 = dron.atacarColumna();
            cout<<endl;
            cout<<"Segundo ataque"<<endl;
            fila2 = dron.atacarFila();
            columna2 = dron.atacarColumna();
            cout<<endl;
            cout<<"Tercer ataque"<<endl;
            fila3 = dron.atacarFila();
            columna3 = dron.atacarColumna();
            system("cls");
            nroAvion = 3;
            _Ventana.clear();
            avionElegido = true;
        }

        if(Keyboard::isKeyPressed(Keyboard::R)){
            cout<<"Has escogido el Reconocimiento como tu avion de apoyo"<<endl;
            cout<<"Este avion te otorgara deteccion del rival en tres filas"<<endl;
            Reconocimiento reconocimiento;
            cout<<"Primera deteccion"<<endl;
            reconHumano1 = reconocimiento.detectar();
            cout<<"Segundo deteccion"<<endl;
            reconHumano2 = reconocimiento.detectar();
            cout<<"Tercera deteccion"<<endl;
            reconHumano3 = reconocimiento.detectar();
            system("cls");
            nroAvion = 4,
            _Ventana.clear();
            avionElegido = true;
        }
    }

    //IA ELIGE SU AVION

    if(avionElegidoIA == false && avionElegido == true){
        eleccionAvionIA = rand()%4+1;

        if(eleccionAvionIA == 1){
            cout<<"El rival ha elegido el Bombardero como avion de apoyo"<<endl;
            system("PAUSE");
            Bombardero bombarderoIA;
            filaBombarderoIA = bombarderoIA.bombardearIA();
            system("cls");
            nroAvionIA = 1;
            _Ventana.clear();
            avionElegidoIA = true;}

        if(eleccionAvionIA == 2){
            cout<<"El rival ha elegido el Caza como avion de apoyo"<<endl;
            system("PAUSE");
            Caza cazaIA;
            filaSupremaciaIA = cazaIA.otorgarSupremaciaIA();
            system("cls");
            supremaciaIA = true;
            nroAvionIA = 2;
            _Ventana.clear();
            avionElegidoIA = true;}

        if(eleccionAvionIA == 3){
            cout<<"El rival ha elegido el Dron como su avion de apoyo"<<endl;
            system("PAUSE");
            Dron dronIA;
            fila1IA = dronIA.atacarFilaIA();
            columna1IA = dronIA.atacarColumnaIA();
            fila2IA = dronIA.atacarFilaIA();
            columna2IA = dronIA.atacarColumnaIA();
            fila3IA = dronIA.atacarFilaIA();
            columna3IA = dronIA.atacarColumnaIA();
            system("cls");
            _Ventana.clear();
            nroAvionIA = 3;
            avionElegidoIA = true;}

        if(eleccionAvionIA == 4){
            cout<<"El rival ha elegido el Reconocimiento como su avion de apoyo"<<endl;
            system("PAUSE");
            Reconocimiento reconocimientoIA;
            reconIA1 = reconocimientoIA.detectarIA();
            reconIA2 = reconocimientoIA.detectarIA();
            reconIA3 = reconocimientoIA.detectarIA();
            system("cls");
            nroAvionIA = 4;
            avionElegidoIA = true;
            _Ventana.clear();
        }

    }



    //TODA LA LOGICA VA AHORA
    //FASE DE PREPARACIÓN
    //VENTANA DRAW DIBUJA LO QUE PASAMOS COMO PARÁMETRO
    //_Ventana.draw(tableroUno);
    if(embarcacionesUbicadas == false && avionElegido == true){

        //MOSTRAMOS LOS NOMBRES DE LOS BARCOS
        //ESTO IRA DESAPARECIENDO A MEDIDA QUE SE UBICA UN BARCO EN EL TABLERO
        if(destructorUbicado == false){
            _Ventana.draw(nombreDestructor);}
        if(submarinoUbicado == false){
            _Ventana.draw(nombreSubmarino);}
        if(acorazadoUbicado == false){
            _Ventana.draw(nombreAcorazado);}
        if(portaavionesUbicado == false){
            _Ventana.draw(nombrePortaaviones);}
        if(fragataUbicada == false){
            _Ventana.draw(nombreFragata);}


    //UBICAR BARCOS UTILIZANDO CONSOLA
    //1 UBICA DESTRUCTOR
    if(Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)){
        if(destructorUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarDestructor(destructor,tableroUno) == true){
            destructorUbicado = true;}
            inputMode = false;}
                }
            }
    //2 UBICA SUBMARINO
    if(Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)){
        if(submarinoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarSubmarino(submarino,tableroUno) == true){
            submarinoUbicado = true;}
            inputMode = false;}
                }
            }
    //3 UBICA ACORAZADO
    if(Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)){
        if(acorazadoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarAcorazado(acorazado,tableroUno) == true){
            acorazadoUbicado = true;}
            inputMode = false;}
                }
            }
    //4 UBICA PORTAAVIONES
    if(Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)){
        if(portaavionesUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarPortaaviones(portaaviones,tableroUno) == true){
            portaavionesUbicado = true;}
            inputMode = false;}
                }
            }
    //5 UBICA FRAGATA
    if(Keyboard::isKeyPressed(Keyboard::Num5) || Keyboard::isKeyPressed(Keyboard::Numpad5)){
        if(fragataUbicada == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarFragata(fragata,tableroUno) == true){
            fragataUbicada = true;}
            inputMode = false;}
                }
            }



    if(embarcacionesUbicadas == false){
        //SI LOS BARCOS SE UBICARON, NO SE MOSTRARÁ MÁS EL MENSAJE "UBICA TUS BARCOS"
        _Ventana.draw(Ubicacion);
        if(destructorUbicado == true){
        _Ventana.draw(destructor);}
        if(fragataUbicada == true){
        _Ventana.draw(fragata);}
        if(submarinoUbicado == true){
        _Ventana.draw(submarino);}
        if(portaavionesUbicado == true){
            _Ventana.draw(portaaviones);}
        if(acorazadoUbicado == true){
            _Ventana.draw(acorazado);}
        }

    //SALIMOS DEL WHILE SI SE UBICARON TODOS LOS BARCOS
    if(destructorUbicado == true && fragataUbicada == true && submarinoUbicado == true && portaavionesUbicado == true && acorazadoUbicado == true){
        embarcacionesUbicadas = true;}
    }

    //LIMPIAMOS EL NOMBRE DEL ULTIMO BARCO CON EL .CLEAR() Y MOSTRAMOS LOS SPRITES CON LOS .DRAW Y .DISPLAY
    if(embarcacionesUbicadas == true){
        _Ventana.clear();
        _Ventana.draw(tableroUno);
        _Ventana.draw(destructor);
        _Ventana.draw(acorazado);
        _Ventana.draw(fragata);
        _Ventana.draw(portaaviones);
        _Ventana.draw(submarino);
        _Ventana.draw(recuadro);
        _Ventana.draw(descripcion1);
        _Ventana.draw(descripcion2);
        _Ventana.draw(descripcion3);
        _Ventana.draw(descripcion4);
        _Ventana.display();}

    //ACA PODEMOS AGREGAR UNA OPCION PARA CONSULTARLE QUE TIPO DE NIVEL DESEA ENFRENTAR
    //ESTE NIVEL ES EL NUMERO 1 DEL MODO HISTORIA
    if(embarcacionesUbicadas == true && embarcacionesEnemigasUbicadas == false){
        embarcacionesEnemigasUbicadas = tableroDos.completarTableroEnemigoNivel2(tableroDos);}


    //TODOS LOS BARCOS UBICADOS. EMPIEZA LA FASE DE ATAQUE

        if(embarcacionesUbicadas == true && embarcacionesEnemigasUbicadas == true){
         //_Musica.play();
        while(partidaTerminada == false){
                _Ventana.clear();
            //SI EL TURNO ES PAR, ATACA EL HUMANO. SI ES IMPAR, ATACA LA IA
            turno++;

        //TERMINAR PARA HUMANO. TENER EN CUENTA EL CAZA
        if(apoyoUtilizado == false){
        switch(nroAvion){
        case 1: tableroDos.getAtaqueBombardero(filaBombarderoHumano,supremaciaIA,filaSupremaciaIA);
                apoyoUtilizado = true;
        break;
        case 3: tableroDos.getAtaqueDron(fila1,columna1, supremaciaIA, filaSupremaciaIA);
                tableroDos.getAtaqueDron(fila2,columna2, supremaciaIA, filaSupremaciaIA);
                tableroDos.getAtaqueDron(fila3,columna3, supremaciaIA, filaSupremaciaIA);
                apoyoUtilizado = true;
        break;
        case 4: tableroDos.getReconocimiento(reconHumano1,tableroDos);
                tableroDos.getReconocimiento(reconHumano2,tableroDos);
                tableroDos.getReconocimiento(reconHumano3,tableroDos);
                apoyoUtilizado = true;
        break;
            }
        }
         //TERMINAR PARA EL RIVAL

        if(apoyoUtilizadoIA == false){
        switch(nroAvionIA){
        case 1: tableroUno.getAtaqueBombarderoIA(filaBombarderoIA,supremaciaHumano,filaSupremaciaHumano);
                apoyoUtilizadoIA = true;
        break;
        case 3:tableroUno.getAtaqueDron(fila1IA,columna1IA,supremaciaHumano,filaSupremaciaHumano);
                tableroUno.getAtaqueDron(fila2IA,columna2IA,supremaciaHumano,filaSupremaciaHumano);
                tableroUno.getAtaqueDron(fila3IA,columna3IA,supremaciaHumano,filaSupremaciaHumano);
                apoyoUtilizadoIA = true;
        break;
        //NO METI RECONOCIMIENTO PORQUE SE VA A USAR EN LA FASE DE ATAQUE
            }
        }


            if(turno % 2 == 0){
            //TURNO JUGADOR HUMANO
                cout<<"FILA: ";
                cin>>filaInt;
                cout<<"COLUMNA: ";
                cin>>columnaInt;
                 if(tableroDos.atacar(filaInt,columnaInt,tableroDos) == true){
                miFuego._sound.play();
                }else{
                miAgua._sound.play();
                }
                system("PAUSE");
                system("cls");
                if(tableroDos.evaluarTablero(tableroDos) == true){
                cout<<"Has eliminado a tu rival. Partida terminada"<<endl;
                 _Musica.stop();
                ganadorHumano = true;
                partidaTerminada = true;}
                //ESTO LUEGO HAY QUE SACAR
                cout<<"Tablero IA"<<endl;
                tableroDos.mostrarTablero(tableroDos);}


            if(turno % 2 != 0){
                //TURNO IA
                if(apoyoUtilizadoIA == false && avionElegidoIA == 4){
                if(turno == 1){
                    tableroUno.getReconocimientoIA(reconIA1,tableroUno);}
                if(turno == 3){
                    tableroUno.getReconocimientoIA(reconIA2,tableroUno);}

                if(turno == 5){
                    tableroUno.getReconocimientoIA(reconIA3,tableroUno);
                    apoyoUtilizadoIA = true;}
            }
            tableroUno.atacaIA(tableroUno, _Ventana);
            system("PAUSE");
            system("cls");
            if(tableroUno.evaluarTablero(tableroUno) == true){
                cout<<"El enemigo nos ha derrotado. Partida terminada"<<endl;
                 _Musica.stop();
                ganadorIA = true;
                partidaTerminada = true;}
            system("cls");
            //ESTO LUEGO HAY QUE SACAR
            cout<<"Tablero Humano"<<endl;
            tableroUno.mostrarTablero(tableroUno);}
            }//LLAVE WHILE
        }

    if(partidaTerminada == true){
        return;}
        _Ventana.display();}
}

void Juego::Nivel4(sf::RenderWindow &v){
Tablero tableroUno, tableroDos;
Destructor destructor;
Acorazado acorazado;
Portaaviones portaaviones;
Submarino submarino;
Fragata fragata;
bool destructorUbicado = false, acorazadoUbicado = false, portaavionesUbicado = false, submarinoUbicado = false, fragataUbicada = false, embarcacionesUbicadas = false;
bool nautilusUbicado = false, nautilusSumergido = false;
int turno = 0, filaInt, columnaInt;
bool inputMode = false, partidaTerminada = false;
bool ganadorHumano = false, ganadorIA = false;
Fuego miFuego;
Agua miAgua;
Nautilus nautilus;

if (!_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Jefes/Nautilus.wav")) {
        // Manejar error si no se puede cargar la música
        // Por ejemplo, mostrar un mensaje de error y continuar sin música
    }
    //ACTIVAR MUSICA NAUTILUS
    _Musica.setVolume(25);
    _Musica.play();

sf::Sprite recuadro;
sf::Texture texture;
recuadro.setPosition(30,311);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Recuadro.png");
//recuadro.setScale(0.2f, 0.2f);
recuadro.setTexture(texture);

//CREACION DE LA FUENTE Y EL TEXTO
sf::Font fuente;
if (!fuente.loadFromFile("C:/Users/Gonzalo/Desktop/Database/PressStart2P.ttf")) {
    // SI NO CARGA LA FUENTE O HAY UN ERROR, SALE.
    return;
}


//PARA QUE APAREZCA UN TEXTO SOLICITANDO ALGO AL USUARIO
Text Ubicacion("Ubica tus barcos", fuente, 15);
Ubicacion.setPosition(50, 300);
Ubicacion.setFillColor(Color::White);

Text descripcion1("Estás en el NIVEL 4", fuente, 15);
descripcion1.setPosition(50, 328);
descripcion1.setFillColor(Color::White);

Text descripcion2("Te enfrentas a NAUTILUS", fuente, 15);
descripcion2.setPosition(50, 356);
descripcion2.setFillColor(Color::White);

Text descripcion3("El enemigo ocupa 4 casillas", fuente, 15);
descripcion3.setPosition(50, 384);
descripcion3.setFillColor(Color::White);

Text descripcion4("Cuidado, parece esconderse en cada turno", fuente, 15);
descripcion4.setPosition(50, 412);
descripcion4.setFillColor(Color::White);

//SETEO DEL TABLERO QUE PASAMOS POR REFERENCIA
tableroUno.setPosicion(50,0);


//PARA QUE APAREZCAN LOS NOMBRES DE LOS BARCOS
Text nombreDestructor("1) Destructor",fuente,13);
nombreDestructor.setPosition(50, 328);
nombreDestructor.setFillColor(Color::White);

Text nombreSubmarino("2) Submarino",fuente,13);
nombreSubmarino.setPosition(50, 356);
nombreSubmarino.setFillColor(Color::White);

Text nombreAcorazado("3) Acorazado",fuente,13);
nombreAcorazado.setPosition(50, 384);
nombreAcorazado.setFillColor(Color::White);

Text nombrePortaaviones("4) Portaaviones",fuente,13);
nombrePortaaviones.setPosition(50, 412);
nombrePortaaviones.setFillColor(Color::White);

Text nombreFragata("5) Fragata",fuente,13);
nombreFragata.setPosition(50, 440);
nombreFragata.setFillColor(Color::White);


while(_Ventana.isOpen()){
    //RESPETAR EL ORDEN DE ESTOS DOS
    //PROCESAR EVENTO PERMITE APRETAR ESCAPE PARA RETORNAR A UN MENU ANTERIOR Y CIERRA LA VENTANA SI ES NECESARIO
    ProcesarEvento();
    if(Keyboard::isKeyPressed(Keyboard::Escape) == true){
        return;
    }
    //VENTANA CLEAR LIMPIA TODA LA IMAGEN DE LA VENTANA
    _Ventana.clear();
    //HASTA ACA
    _Ventana.draw(recuadro);
    _Ventana.draw(tableroUno);


    //TODA LA LOGICA VA AHORA
    //FASE DE PREPARACIÓN
    //VENTANA DRAW DIBUJA LO QUE PASAMOS COMO PARÁMETRO
    //_Ventana.draw(tableroUno);
    if(embarcacionesUbicadas == false){

        //MOSTRAMOS LOS NOMBRES DE LOS BARCOS
        //ESTO IRA DESAPARECIENDO A MEDIDA QUE SE UBICA UN BARCO EN EL TABLERO
        if(destructorUbicado == false){
            _Ventana.draw(nombreDestructor);}
        if(submarinoUbicado == false){
            _Ventana.draw(nombreSubmarino);}
        if(acorazadoUbicado == false){
            _Ventana.draw(nombreAcorazado);}
        if(portaavionesUbicado == false){
            _Ventana.draw(nombrePortaaviones);}
        if(fragataUbicada == false){
            _Ventana.draw(nombreFragata);}


    //UBICAR BARCOS UTILIZANDO CONSOLA
    //1 UBICA DESTRUCTOR
    if(Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)){
        if(destructorUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarDestructor(destructor,tableroUno) == true){
            destructorUbicado = true;}
            inputMode = false;}
                }
            }
    //2 UBICA SUBMARINO
    if(Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)){
        if(submarinoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarSubmarino(submarino,tableroUno) == true){
            submarinoUbicado = true;}
            inputMode = false;}
                }
            }
    //3 UBICA ACORAZADO
    if(Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)){
        if(acorazadoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarAcorazado(acorazado,tableroUno) == true){
            acorazadoUbicado = true;}
            inputMode = false;}
                }
            }
    //4 UBICA PORTAAVIONES
    if(Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)){
        if(portaavionesUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarPortaaviones(portaaviones,tableroUno) == true){
            portaavionesUbicado = true;}
            inputMode = false;}
                }
            }
    //5 UBICA FRAGATA
    if(Keyboard::isKeyPressed(Keyboard::Num5) || Keyboard::isKeyPressed(Keyboard::Numpad5)){
        if(fragataUbicada == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarFragata(fragata,tableroUno) == true){
            fragataUbicada = true;}
            inputMode = false;}
                }
            }



    if(embarcacionesUbicadas == false){
        //SI LOS BARCOS SE UBICARON, NO SE MOSTRARÁ MÁS EL MENSAJE "UBICA TUS BARCOS"
        _Ventana.draw(Ubicacion);
        if(destructorUbicado == true){
        _Ventana.draw(destructor);}
        if(fragataUbicada == true){
        _Ventana.draw(fragata);}
        if(submarinoUbicado == true){
        _Ventana.draw(submarino);}
        if(portaavionesUbicado == true){
            _Ventana.draw(portaaviones);}
        if(acorazadoUbicado == true){
            _Ventana.draw(acorazado);}
        }

    //SALIMOS DEL WHILE SI SE UBICARON TODOS LOS BARCOS
    if(destructorUbicado == true && fragataUbicada == true && submarinoUbicado == true && portaavionesUbicado == true && acorazadoUbicado == true){
        embarcacionesUbicadas = true;}
    }

    //LIMPIAMOS EL NOMBRE DEL ULTIMO BARCO CON EL .CLEAR() Y MOSTRAMOS LOS SPRITES CON LOS .DRAW Y .DISPLAY
    if(embarcacionesUbicadas == true){
        _Ventana.clear();
        _Ventana.draw(tableroUno);
        _Ventana.draw(destructor);
        _Ventana.draw(acorazado);
        _Ventana.draw(fragata);
        _Ventana.draw(portaaviones);
        _Ventana.draw(submarino);
        _Ventana.draw(recuadro);
        _Ventana.draw(descripcion1);
        _Ventana.draw(descripcion2);
        _Ventana.draw(descripcion3);
        _Ventana.draw(descripcion4);
        nautilus._sprite.setPosition(375,15);
        _Ventana.draw(nautilus._sprite);
        _Ventana.display();}


    if(embarcacionesUbicadas == true){
        tableroDos.completarTableroNivelNautilus(tableroDos);
        nautilusUbicado = true;
        }


    //TODOS LOS BARCOS UBICADOS. EMPIEZA LA FASE DE ATAQUE

        if(embarcacionesUbicadas == true && nautilusUbicado == true){

        while(partidaTerminada == false){
                _Ventana.clear();
            //SI EL TURNO ES PAR, ATACA EL HUMANO. SI ES IMPAR, ATACA LA IA
            turno++;
            nautilusSumergido = nautilus.sumergirse();

            if(nautilusSumergido == false){
                if(turno % 2 == 0){
                //TURNO JUGADOR HUMANO
                cout<<"TURNO: "<<turno<<endl;
                cout<<"FILA: ";
                cin>>filaInt;
                cout<<"COLUMNA: ";
                cin>>columnaInt;
                 if(tableroDos.atacar(filaInt,columnaInt,tableroDos) == true){
                miFuego._sound.play();
                }else{
                miAgua._sound.play();
                }
                system("PAUSE");
                system("cls");
                if(tableroDos.evaluarTablero(tableroDos) == true){
                cout<<"Has eliminado a tu rival. Partida terminada"<<endl;
                 _Musica.stop();
                ganadorHumano = true;
                partidaTerminada = true;}
                //ESTO LUEGO HAY QUE SACAR
                cout<<"Tablero IA"<<endl;
                tableroDos.mostrarTablero(tableroDos);}
            }else{
            cout<<"Nuestros radares no logran detectar a "<<nautilus.getNombre()<<endl;
            nautilus._sound.play();
            }

            if(turno % 2 != 0){
                //TURNO IA
            cout<<"TURNO: "<<turno<<endl;
            tableroUno.atacaIA(tableroUno, _Ventana);
            system("PAUSE");
            system("cls");
            if(tableroUno.evaluarTablero(tableroUno) == true){
                cout<<"El enemigo nos ha derrotado. Partida terminada"<<endl;
                _Musica.stop();
                ganadorIA = true;
                partidaTerminada = true;}
            system("cls");
            //ESTO LUEGO HAY QUE SACAR
            cout<<"Tablero Humano"<<endl;
            tableroUno.mostrarTablero(tableroUno);}
            }//LLAVE WHILE
        }

    if(partidaTerminada == true){
        return;}
        _Ventana.display();}

}

void Juego::Nivel5(sf::RenderWindow &v){
Tablero tableroUno, tableroDos;
Destructor destructor, destructorEnemigo;
Acorazado acorazado, acorazadoEnemigo;
Portaaviones portaaviones, portaavionesEnemigo;
Submarino submarino,submarinoEnemigo;
Fragata fragata,fragataEnemigo;
bool destructorUbicado = false, acorazadoUbicado = false, portaavionesUbicado = false, submarinoUbicado = false, fragataUbicada = false, embarcacionesUbicadas = false;
bool embarcacionesEnemigasUbicadas = false;
int turno = 0, filaInt, columnaInt, nroAvion, nroAvionIA;
bool inputMode = false, partidaTerminada = false;
bool ganadorHumano = false, ganadorIA = false;
bool avionElegido = false, supremaciaHumano = false, apoyoUtilizado = false;
bool avionElegidoIA = false, supremaciaIA = false, apoyoUtilizadoIA = false;
Fuego miFuego;
Agua miAgua;
int filaSupremaciaHumano, filaSupremaciaIA, filaBombarderoHumano,filaBombarderoIA, fila1,fila2,fila3,columna1,columna2,columna3,reconHumano1,reconHumano2,reconHumano3;
int fila1IA,fila2IA,fila3IA,columna1IA,columna2IA,columna3IA, reconIA1,reconIA2,reconIA3;

if (!_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Enemigos menores/Digital Love.wav")) {
        // Manejar error si no se puede cargar la música
        // Por ejemplo, mostrar un mensaje de error y continuar sin música
    }
    //ACTIVAR MUSICA GHOST
    _Musica.setVolume(50);
    _Musica.play();

//RAND PARA ELECCION DEL AVION IA
srand(time(NULL));
int eleccionAvionIA;
int contadorImpactos = 0, filaIA, columnaIA;
sf::Sprite recuadro;
sf::Texture texture;
recuadro.setPosition(30,311);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Recuadro.png");
//recuadro.setScale(0.2f, 0.2f);
recuadro.setTexture(texture);

//CREACION DE LA FUENTE Y EL TEXTO
sf::Font fuente;
if (!fuente.loadFromFile("C:/Users/Gonzalo/Desktop/Database/PressStart2P.ttf")) {
    // SI NO CARGA LA FUENTE O HAY UN ERROR, SALE.
    return;
}

Text EleccionAvion("¿Que avion deseas utilizar?",fuente,15);
EleccionAvion.setPosition(50,300);
EleccionAvion.setFillColor(Color::White);

Text nombreBombardero("B) Bombardero",fuente,13);
nombreBombardero.setPosition(50, 328);
nombreBombardero.setFillColor(Color::White);

Text nombreCaza("C) Caza",fuente,13);
nombreCaza.setPosition(50, 356);
nombreCaza.setFillColor(Color::White);

Text nombreDron("D) Dron",fuente,13);
nombreDron.setPosition(50, 384);
nombreDron.setFillColor(Color::White);

Text nombreReconocimiento("R) Reconocimiento",fuente,13);
nombreReconocimiento.setPosition(50, 412);
nombreReconocimiento.setFillColor(Color::White);




//PARA QUE APAREZCA UN TEXTO SOLICITANDO ALGO AL USUARIO
Text Ubicacion("Ubica tus barcos", fuente, 15);
Ubicacion.setPosition(50, 300);
Ubicacion.setFillColor(Color::White);

Text descripcion1("Estás en el NIVEL 5", fuente, 15);
descripcion1.setPosition(50, 328);
descripcion1.setFillColor(Color::White);

Text descripcion2("Te enfrentas a 10 naves enemigas", fuente, 15);
descripcion2.setPosition(50, 356);
descripcion2.setFillColor(Color::White);

Text descripcion3("El enemigo ocupa sólo 1 casilla", fuente, 15);
descripcion3.setPosition(50, 384);
descripcion3.setFillColor(Color::White);

Text descripcion4("Parece que la nave nodriza está muy cerca", fuente, 15);
descripcion4.setPosition(50, 412);
descripcion4.setFillColor(Color::White);

//SETEO DEL TABLERO QUE PASAMOS POR REFERENCIA
tableroUno.setPosicion(50,0);
tableroDos.setPosicion(400,0);


//PARA QUE APAREZCAN LOS NOMBRES DE LOS BARCOS
Text nombreDestructor("1) Destructor",fuente,13);
nombreDestructor.setPosition(50, 328);
nombreDestructor.setFillColor(Color::White);

Text nombreSubmarino("2) Submarino",fuente,13);
nombreSubmarino.setPosition(50, 356);
nombreSubmarino.setFillColor(Color::White);

Text nombreAcorazado("3) Acorazado",fuente,13);
nombreAcorazado.setPosition(50, 384);
nombreAcorazado.setFillColor(Color::White);

Text nombrePortaaviones("4) Portaaviones",fuente,13);
nombrePortaaviones.setPosition(50, 412);
nombrePortaaviones.setFillColor(Color::White);

Text nombreFragata("5) Fragata",fuente,13);
nombreFragata.setPosition(50, 440);
nombreFragata.setFillColor(Color::White);


while(_Ventana.isOpen()){
    //RESPETAR EL ORDEN DE ESTOS DOS
    //PROCESAR EVENTO PERMITE APRETAR ESCAPE PARA RETORNAR A UN MENU ANTERIOR Y CIERRA LA VENTANA SI ES NECESARIO
    ProcesarEvento();
    if(Keyboard::isKeyPressed(Keyboard::Escape) == true){
        return;
    }
    //VENTANA CLEAR LIMPIA TODA LA IMAGEN DE LA VENTANA
    _Ventana.clear();
    //HASTA ACA
    _Ventana.draw(recuadro);
    _Ventana.draw(tableroUno);



    if(avionElegido == false){
        _Ventana.draw(EleccionAvion);
        _Ventana.draw(nombreBombardero);
        _Ventana.draw(nombreCaza);
        _Ventana.draw(nombreDron);
        _Ventana.draw(nombreReconocimiento);

        if(Keyboard::isKeyPressed(Keyboard::B)){
            cout<<"Has escogido el Bombardero como tu avion de apoyo"<<endl;
            cout<<"Este avion te permitira destruir una fila completa del enemigo una sola vez"<<endl;
            Bombardero bombardero;
            filaBombarderoHumano = bombardero.bombardear();
            system("cls");
            nroAvion = 1;
            _Ventana.clear();
            avionElegido = true;
        }

        if(Keyboard::isKeyPressed(Keyboard::C)){
            cout<<"Has escogido el Caza como tu avion de apoyo"<<endl;
            cout<<"Este avion te otorgará superioridad aerea en una fila especifica"<<endl;
            Caza caza;
            filaSupremaciaHumano = caza.otorgarSupremacia();
            system("cls");
            supremaciaHumano = true;
            nroAvion = 2;
            _Ventana.clear();
            avionElegido = true;
        }

        if(Keyboard::isKeyPressed(Keyboard::D)){
            cout<<"Has escogido el Dron como tu avion de apoyo"<<endl;
            cout<<"Este avion te permitira hacer tres ataques adicionales"<<endl;
            cout<<"Elige tus tres ataques"<<endl;
            Dron dron;
            cout<<"Primer ataque"<<endl;
            fila1 = dron.atacarFila();
            columna1 = dron.atacarColumna();
            cout<<endl;
            cout<<"Segundo ataque"<<endl;
            fila2 = dron.atacarFila();
            columna2 = dron.atacarColumna();
            cout<<endl;
            cout<<"Tercer ataque"<<endl;
            fila3 = dron.atacarFila();
            columna3 = dron.atacarColumna();
            system("cls");
            nroAvion = 3;
            _Ventana.clear();
            avionElegido = true;
        }

        if(Keyboard::isKeyPressed(Keyboard::R)){
            cout<<"Has escogido el Reconocimiento como tu avion de apoyo"<<endl;
            cout<<"Este avion te otorgara deteccion del rival en tres filas"<<endl;
            Reconocimiento reconocimiento;
            cout<<"Primera deteccion"<<endl;
            reconHumano1 = reconocimiento.detectar();
            cout<<"Segundo deteccion"<<endl;
            reconHumano2 = reconocimiento.detectar();
            cout<<"Tercera deteccion"<<endl;
            reconHumano3 = reconocimiento.detectar();
            system("cls");
            nroAvion = 4,
            _Ventana.clear();
            avionElegido = true;
        }
    }

    //IA ELIGE SU AVION

    if(avionElegidoIA == false && avionElegido == true){
        eleccionAvionIA = rand()%4+1;

        if(eleccionAvionIA == 1){
            cout<<"El rival ha elegido el Bombardero como avion de apoyo"<<endl;
            system("PAUSE");
            Bombardero bombarderoIA;
            filaBombarderoIA = bombarderoIA.bombardearIA();
            system("cls");
            nroAvionIA = 1;
            _Ventana.clear();
            avionElegidoIA = true;}

        if(eleccionAvionIA == 2){
            cout<<"El rival ha elegido el Caza como avion de apoyo"<<endl;
            system("PAUSE");
            Caza cazaIA;
            filaSupremaciaIA = cazaIA.otorgarSupremaciaIA();
            system("cls");
            supremaciaIA = true;
            nroAvionIA = 2;
            _Ventana.clear();
            avionElegidoIA = true;}

        if(eleccionAvionIA == 3){
            cout<<"El rival ha elegido el Dron como su avion de apoyo"<<endl;
            system("PAUSE");
            Dron dronIA;
            fila1IA = dronIA.atacarFilaIA();
            columna1IA = dronIA.atacarColumnaIA();
            fila2IA = dronIA.atacarFilaIA();
            columna2IA = dronIA.atacarColumnaIA();
            fila3IA = dronIA.atacarFilaIA();
            columna3IA = dronIA.atacarColumnaIA();
            system("cls");
            _Ventana.clear();
            nroAvionIA = 3;
            avionElegidoIA = true;}

        if(eleccionAvionIA == 4){
            cout<<"El rival ha elegido el Reconocimiento como su avion de apoyo"<<endl;
            system("PAUSE");
            Reconocimiento reconocimientoIA;
            reconIA1 = reconocimientoIA.detectarIA();
            reconIA2 = reconocimientoIA.detectarIA();
            reconIA3 = reconocimientoIA.detectarIA();
            system("cls");
            nroAvionIA = 4;
            avionElegidoIA = true;
            _Ventana.clear();
        }

    }



    //TODA LA LOGICA VA AHORA
    //FASE DE PREPARACIÓN
    //VENTANA DRAW DIBUJA LO QUE PASAMOS COMO PARÁMETRO
    //_Ventana.draw(tableroUno);
    if(embarcacionesUbicadas == false && avionElegido == true){

        //MOSTRAMOS LOS NOMBRES DE LOS BARCOS
        //ESTO IRA DESAPARECIENDO A MEDIDA QUE SE UBICA UN BARCO EN EL TABLERO
        if(destructorUbicado == false){
            _Ventana.draw(nombreDestructor);}
        if(submarinoUbicado == false){
            _Ventana.draw(nombreSubmarino);}
        if(acorazadoUbicado == false){
            _Ventana.draw(nombreAcorazado);}
        if(portaavionesUbicado == false){
            _Ventana.draw(nombrePortaaviones);}
        if(fragataUbicada == false){
            _Ventana.draw(nombreFragata);}


    //UBICAR BARCOS UTILIZANDO CONSOLA
    //1 UBICA DESTRUCTOR
    if(Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)){
        if(destructorUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarDestructor(destructor,tableroUno) == true){
            destructorUbicado = true;}
            inputMode = false;}
                }
            }
    //2 UBICA SUBMARINO
    if(Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)){
        if(submarinoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarSubmarino(submarino,tableroUno) == true){
            submarinoUbicado = true;}
            inputMode = false;}
                }
            }
    //3 UBICA ACORAZADO
    if(Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)){
        if(acorazadoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarAcorazado(acorazado,tableroUno) == true){
            acorazadoUbicado = true;}
            inputMode = false;}
                }
            }
    //4 UBICA PORTAAVIONES
    if(Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)){
        if(portaavionesUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarPortaaviones(portaaviones,tableroUno) == true){
            portaavionesUbicado = true;}
            inputMode = false;}
                }
            }
    //5 UBICA FRAGATA
    if(Keyboard::isKeyPressed(Keyboard::Num5) || Keyboard::isKeyPressed(Keyboard::Numpad5)){
        if(fragataUbicada == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarFragata(fragata,tableroUno) == true){
            fragataUbicada = true;}
            inputMode = false;}
                }
            }



    if(embarcacionesUbicadas == false){
        //SI LOS BARCOS SE UBICARON, NO SE MOSTRARÁ MÁS EL MENSAJE "UBICA TUS BARCOS"
        _Ventana.draw(Ubicacion);
        if(destructorUbicado == true){
        _Ventana.draw(destructor);}
        if(fragataUbicada == true){
        _Ventana.draw(fragata);}
        if(submarinoUbicado == true){
        _Ventana.draw(submarino);}
        if(portaavionesUbicado == true){
            _Ventana.draw(portaaviones);}
        if(acorazadoUbicado == true){
            _Ventana.draw(acorazado);}
        }

    //SALIMOS DEL WHILE SI SE UBICARON TODOS LOS BARCOS
    if(destructorUbicado == true && fragataUbicada == true && submarinoUbicado == true && portaavionesUbicado == true && acorazadoUbicado == true){
        embarcacionesUbicadas = true;}
    }

    //LIMPIAMOS EL NOMBRE DEL ULTIMO BARCO CON EL .CLEAR() Y MOSTRAMOS LOS SPRITES CON LOS .DRAW Y .DISPLAY
    if(embarcacionesUbicadas == true){
        _Ventana.clear();
        _Ventana.draw(tableroUno);
        _Ventana.draw(destructor);
        _Ventana.draw(acorazado);
        _Ventana.draw(fragata);
        _Ventana.draw(portaaviones);
        _Ventana.draw(submarino);
        _Ventana.draw(recuadro);
        _Ventana.draw(descripcion1);
        _Ventana.draw(descripcion2);
        _Ventana.draw(descripcion3);
        _Ventana.draw(descripcion4);
        _Ventana.display();}

    //ACA PODEMOS AGREGAR UNA OPCION PARA CONSULTARLE QUE TIPO DE NIVEL DESEA ENFRENTAR
    //ESTE NIVEL ES EL NUMERO 1 DEL MODO HISTORIA
    if(embarcacionesUbicadas == true && embarcacionesEnemigasUbicadas == false){
        embarcacionesEnemigasUbicadas = tableroDos.completarTableroEnemigoNivel3(tableroDos);}


    //TODOS LOS BARCOS UBICADOS. EMPIEZA LA FASE DE ATAQUE

        if(embarcacionesUbicadas == true && embarcacionesEnemigasUbicadas == true){
         //_Musica.play();
        while(partidaTerminada == false){
                _Ventana.clear();
            //SI EL TURNO ES PAR, ATACA EL HUMANO. SI ES IMPAR, ATACA LA IA
            turno++;

        //TERMINAR PARA HUMANO. TENER EN CUENTA EL CAZA
        if(apoyoUtilizado == false){
        switch(nroAvion){
        case 1: tableroDos.getAtaqueBombardero(filaBombarderoHumano,supremaciaIA,filaSupremaciaIA);
                apoyoUtilizado = true;
        break;
        case 3: tableroDos.getAtaqueDron(fila1,columna1, supremaciaIA, filaSupremaciaIA);
                tableroDos.getAtaqueDron(fila2,columna2, supremaciaIA, filaSupremaciaIA);
                tableroDos.getAtaqueDron(fila3,columna3, supremaciaIA, filaSupremaciaIA);
                apoyoUtilizado = true;
        break;
        case 4: tableroDos.getReconocimiento(reconHumano1,tableroDos);
                tableroDos.getReconocimiento(reconHumano2,tableroDos);
                tableroDos.getReconocimiento(reconHumano3,tableroDos);
                apoyoUtilizado = true;
        break;
            }
        }
         //TERMINAR PARA EL RIVAL

        if(apoyoUtilizadoIA == false){
        switch(nroAvionIA){
        case 1: tableroUno.getAtaqueBombarderoIA(filaBombarderoIA,supremaciaHumano,filaSupremaciaHumano);
                apoyoUtilizadoIA = true;
        break;
        case 3:tableroUno.getAtaqueDron(fila1IA,columna1IA,supremaciaHumano,filaSupremaciaHumano);
                tableroUno.getAtaqueDron(fila2IA,columna2IA,supremaciaHumano,filaSupremaciaHumano);
                tableroUno.getAtaqueDron(fila3IA,columna3IA,supremaciaHumano,filaSupremaciaHumano);
                apoyoUtilizadoIA = true;
        break;
        //NO METI RECONOCIMIENTO PORQUE SE VA A USAR EN LA FASE DE ATAQUE
            }
        }


            if(turno % 2 == 0){
            //TURNO JUGADOR HUMANO
                cout<<"FILA: ";
                cin>>filaInt;
                cout<<"COLUMNA: ";
                cin>>columnaInt;
                 if(tableroDos.atacar(filaInt,columnaInt,tableroDos) == true){
                miFuego._sound.play();
                }else{
                miAgua._sound.play();
                }
                system("PAUSE");
                system("cls");
                if(tableroDos.evaluarTablero(tableroDos) == true){
                cout<<"Has eliminado a tu rival. Partida terminada"<<endl;
                 _Musica.stop();
                ganadorHumano = true;
                partidaTerminada = true;}
                //ESTO LUEGO HAY QUE SACAR
                cout<<"Tablero IA"<<endl;
                tableroDos.mostrarTablero(tableroDos);}


            if(turno % 2 != 0){
                //TURNO IA
                if(apoyoUtilizadoIA == false && avionElegidoIA == 4){
                if(turno == 1){
                    tableroUno.getReconocimientoIA(reconIA1,tableroUno);}
                if(turno == 3){
                    tableroUno.getReconocimientoIA(reconIA2,tableroUno);}

                if(turno == 5){
                    tableroUno.getReconocimientoIA(reconIA3,tableroUno);
                    apoyoUtilizadoIA = true;}
            }
            tableroUno.atacaIA(tableroUno, _Ventana);
            system("PAUSE");
            system("cls");
            if(tableroUno.evaluarTablero(tableroUno) == true){
                cout<<"El enemigo nos ha derrotado. Partida terminada"<<endl;
                 _Musica.stop();
                ganadorIA = true;
                partidaTerminada = true;}
            system("cls");
            //ESTO LUEGO HAY QUE SACAR
            cout<<"Tablero Humano"<<endl;
            tableroUno.mostrarTablero(tableroUno);}
            }//LLAVE WHILE
        }

    if(partidaTerminada == true){
        return;}
        _Ventana.display();}
}

void Juego::Nivel6(sf::RenderWindow &v){
Tablero tableroUno, tableroDos;
Destructor destructor;
Acorazado acorazado;
Portaaviones portaaviones;
Submarino submarino;
Fragata fragata;
bool destructorUbicado = false, acorazadoUbicado = false, portaavionesUbicado = false, submarinoUbicado = false, fragataUbicada = false, embarcacionesUbicadas = false;
bool nagronarUbicado = false;
int turno = 0, filaInt, columnaInt;
bool inputMode = false, partidaTerminada = false;
bool ganadorHumano = false, ganadorIA = false;
Fuego miFuego;
Agua miAgua;
Nagronar nagronar;

if (!_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Jefes/Nagronar.wav")) {
        // Manejar error si no se puede cargar la música
        // Por ejemplo, mostrar un mensaje de error y continuar sin música
    }
    //ACTIVAR MUSICA NAUTILUS
    _Musica.setVolume(25);
    _Musica.play();

sf::Sprite recuadro;
sf::Texture texture;
recuadro.setPosition(30,311);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Recuadro.png");
//recuadro.setScale(0.2f, 0.2f);
recuadro.setTexture(texture);

//CREACION DE LA FUENTE Y EL TEXTO
sf::Font fuente;
if (!fuente.loadFromFile("C:/Users/Gonzalo/Desktop/Database/PressStart2P.ttf")) {
    // SI NO CARGA LA FUENTE O HAY UN ERROR, SALE.
    return;
}


//PARA QUE APAREZCA UN TEXTO SOLICITANDO ALGO AL USUARIO
Text Ubicacion("Ubica tus barcos", fuente, 15);
Ubicacion.setPosition(50, 300);
Ubicacion.setFillColor(Color::White);

Text descripcion1("ULTIMO NIVEL", fuente, 15);
descripcion1.setPosition(50, 328);
descripcion1.setFillColor(Color::White);

Text descripcion2("Te enfrentas a NAGRONAR", fuente, 15);
descripcion2.setPosition(50, 356);
descripcion2.setFillColor(Color::White);

Text descripcion3("El enemigo ocupa 6 casillas", fuente, 15);
descripcion3.setPosition(50, 384);
descripcion3.setFillColor(Color::White);

Text descripcion4("El enemigo destruye filas completas", fuente, 15);
descripcion4.setPosition(50, 412);
descripcion4.setFillColor(Color::White);

Text descripcion5("Tienes 4 fallos disponibles", fuente, 15);
descripcion5.setPosition(50, 440);
descripcion5.setFillColor(Color::White);

//SETEO DEL TABLERO QUE PASAMOS POR REFERENCIA
tableroUno.setPosicion(50,0);


//PARA QUE APAREZCAN LOS NOMBRES DE LOS BARCOS
Text nombreDestructor("1) Destructor",fuente,13);
nombreDestructor.setPosition(50, 328);
nombreDestructor.setFillColor(Color::White);

Text nombreSubmarino("2) Submarino",fuente,13);
nombreSubmarino.setPosition(50, 356);
nombreSubmarino.setFillColor(Color::White);

Text nombreAcorazado("3) Acorazado",fuente,13);
nombreAcorazado.setPosition(50, 384);
nombreAcorazado.setFillColor(Color::White);

Text nombrePortaaviones("4) Portaaviones",fuente,13);
nombrePortaaviones.setPosition(50, 412);
nombrePortaaviones.setFillColor(Color::White);

Text nombreFragata("5) Fragata",fuente,13);
nombreFragata.setPosition(50, 440);
nombreFragata.setFillColor(Color::White);


while(_Ventana.isOpen()){
    //RESPETAR EL ORDEN DE ESTOS DOS
    //PROCESAR EVENTO PERMITE APRETAR ESCAPE PARA RETORNAR A UN MENU ANTERIOR Y CIERRA LA VENTANA SI ES NECESARIO
    ProcesarEvento();
    if(Keyboard::isKeyPressed(Keyboard::Escape) == true){
        return;
    }
    //VENTANA CLEAR LIMPIA TODA LA IMAGEN DE LA VENTANA
    _Ventana.clear();
    //HASTA ACA
    _Ventana.draw(recuadro);
    _Ventana.draw(tableroUno);


    //TODA LA LOGICA VA AHORA
    //FASE DE PREPARACIÓN
    //VENTANA DRAW DIBUJA LO QUE PASAMOS COMO PARÁMETRO
    //_Ventana.draw(tableroUno);
    if(embarcacionesUbicadas == false){

        //MOSTRAMOS LOS NOMBRES DE LOS BARCOS
        //ESTO IRA DESAPARECIENDO A MEDIDA QUE SE UBICA UN BARCO EN EL TABLERO
        if(destructorUbicado == false){
            _Ventana.draw(nombreDestructor);}
        if(submarinoUbicado == false){
            _Ventana.draw(nombreSubmarino);}
        if(acorazadoUbicado == false){
            _Ventana.draw(nombreAcorazado);}
        if(portaavionesUbicado == false){
            _Ventana.draw(nombrePortaaviones);}
        if(fragataUbicada == false){
            _Ventana.draw(nombreFragata);}


    //UBICAR BARCOS UTILIZANDO CONSOLA
    //1 UBICA DESTRUCTOR
    if(Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)){
        if(destructorUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarDestructor(destructor,tableroUno) == true){
            destructorUbicado = true;}
            inputMode = false;}
                }
            }
    //2 UBICA SUBMARINO
    if(Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)){
        if(submarinoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarSubmarino(submarino,tableroUno) == true){
            submarinoUbicado = true;}
            inputMode = false;}
                }
            }
    //3 UBICA ACORAZADO
    if(Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)){
        if(acorazadoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarAcorazado(acorazado,tableroUno) == true){
            acorazadoUbicado = true;}
            inputMode = false;}
                }
            }
    //4 UBICA PORTAAVIONES
    if(Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)){
        if(portaavionesUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarPortaaviones(portaaviones,tableroUno) == true){
            portaavionesUbicado = true;}
            inputMode = false;}
                }
            }
    //5 UBICA FRAGATA
    if(Keyboard::isKeyPressed(Keyboard::Num5) || Keyboard::isKeyPressed(Keyboard::Numpad5)){
        if(fragataUbicada == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarFragata(fragata,tableroUno) == true){
            fragataUbicada = true;}
            inputMode = false;}
                }
            }



    if(embarcacionesUbicadas == false){
        //SI LOS BARCOS SE UBICARON, NO SE MOSTRARÁ MÁS EL MENSAJE "UBICA TUS BARCOS"
        _Ventana.draw(Ubicacion);
        if(destructorUbicado == true){
        _Ventana.draw(destructor);}
        if(fragataUbicada == true){
        _Ventana.draw(fragata);}
        if(submarinoUbicado == true){
        _Ventana.draw(submarino);}
        if(portaavionesUbicado == true){
            _Ventana.draw(portaaviones);}
        if(acorazadoUbicado == true){
            _Ventana.draw(acorazado);}
        }

    //SALIMOS DEL WHILE SI SE UBICARON TODOS LOS BARCOS
    if(destructorUbicado == true && fragataUbicada == true && submarinoUbicado == true && portaavionesUbicado == true && acorazadoUbicado == true){
        embarcacionesUbicadas = true;}
    }

    //LIMPIAMOS EL NOMBRE DEL ULTIMO BARCO CON EL .CLEAR() Y MOSTRAMOS LOS SPRITES CON LOS .DRAW Y .DISPLAY
    if(embarcacionesUbicadas == true){
        _Ventana.clear();
        _Ventana.draw(tableroUno);
        _Ventana.draw(destructor);
        _Ventana.draw(acorazado);
        _Ventana.draw(fragata);
        _Ventana.draw(portaaviones);
        _Ventana.draw(submarino);
        _Ventana.draw(recuadro);
        _Ventana.draw(descripcion1);
        _Ventana.draw(descripcion2);
        _Ventana.draw(descripcion3);
        _Ventana.draw(descripcion4);
        _Ventana.draw(descripcion5);
        nagronar._sprite.setPosition(375,15);
        _Ventana.draw(nagronar._sprite);
        _Ventana.display();}


    if(embarcacionesUbicadas == true){
        tableroDos.completarTableroNivelNagronar(tableroDos);
        nagronarUbicado = true;
        }


    //TODOS LOS BARCOS UBICADOS. EMPIEZA LA FASE DE ATAQUE

        if(embarcacionesUbicadas == true && nagronarUbicado == true){

        while(partidaTerminada == false){
                _Ventana.clear();
            //SI EL TURNO ES PAR, ATACA EL HUMANO. SI ES IMPAR, ATACA LA IA
            turno++;


                if(turno % 2 == 0){
                //TURNO JUGADOR HUMANO
                cout<<"TURNO: "<<turno<<endl;
                cout<<"FILA: ";
                cin>>filaInt;
                cout<<"COLUMNA: ";
                cin>>columnaInt;
                 if(tableroDos.atacar(filaInt,columnaInt,tableroDos) == true){
                miFuego._sound.play();
                }else{
                miAgua._sound.play();
                }
                system("PAUSE");
                system("cls");
                if(tableroDos.evaluarTablero(tableroDos) == true){
                cout<<"Has eliminado a tu rival. Partida terminada"<<endl;
                 _Musica.stop();
                ganadorHumano = true;
                partidaTerminada = true;}
                //ESTO LUEGO HAY QUE SACAR
                cout<<"Tablero IA"<<endl;
                tableroDos.mostrarTablero(tableroDos);}


            if(turno % 2 != 0){
                //TURNO IA
            cout<<"TURNO: "<<turno<<endl;
            tableroUno.getAtaqueNagronar(nagronar.destruirFila(tableroUno));
            nagronar._sound.play();
            system("PAUSE");
            system("cls");
            if(tableroUno.evaluarTablero(tableroUno) == true){
                cout<<"El enemigo nos ha derrotado. Partida terminada"<<endl;
                _Musica.stop();
                ganadorIA = true;
                partidaTerminada = true;}
            system("cls");
            //ESTO LUEGO HAY QUE SACAR
            cout<<"Tablero Humano"<<endl;
            tableroUno.mostrarTablero(tableroUno);}
            }//LLAVE WHILE
        }

    if(partidaTerminada == true){
        return;}
        _Ventana.display();}

}

void Juego::ModoHistoria(sf::RenderWindow &v){

    //VS 5 UFO
    Nivel1(_Ventana);

    //VS GHOST
    Nivel2(_Ventana);

    //VS 7 UFO
    Nivel3(_Ventana);

    //VS NAUTILUS
    Nivel4(_Ventana);

    //VS 10 UFO
    Nivel5(_Ventana);

    //VS NAGRONAR
    Nivel6(_Ventana);


}

void Juego::ModoPersonalizado(sf::RenderWindow &v){

//CREACION DE LA FUENTE Y EL TEXTO
sf::Font fuente;
if (!fuente.loadFromFile("C:/Users/Gonzalo/Desktop/Database/PressStart2P.ttf")) {
    // SI NO CARGA LA FUENTE O HAY UN ERROR, SALE.
    return;
}

Text eleccionRival("¿Que rival deseas enfrentar?",fuente,15);
eleccionRival.setPosition(50,300);
eleccionRival.setFillColor(Color::White);

Text cincoUFO("1) 5 UFO",fuente,13);
cincoUFO.setPosition(50, 328);
cincoUFO.setFillColor(Color::White);

Text sieteUFO("2) 7 UFO",fuente,13);
sieteUFO.setPosition(50, 356);
sieteUFO.setFillColor(Color::White);

Text diezUFO("3) 10 UFO",fuente,13);
diezUFO.setPosition(50, 384);
diezUFO.setFillColor(Color::White);

Text ghost("4) GHOST ",fuente,13);
ghost.setPosition(50, 412);
ghost.setFillColor(Color::White);

Text nautilus("5) NAUTILUS ",fuente,13);
nautilus.setPosition(50, 440);
nautilus.setFillColor(Color::White);

Text nagronar("6) NAGRONAR ",fuente,13);
nagronar.setPosition(50, 468);
nagronar.setFillColor(Color::White);

while(_Ventana.isOpen()){
    //RESPETAR EL ORDEN DE ESTOS DOS
    //PROCESAR EVENTO PERMITE APRETAR ESCAPE PARA RETORNAR A UN MENU ANTERIOR Y CIERRA LA VENTANA SI ES NECESARIO
    ProcesarEvento();
    if(Keyboard::isKeyPressed(Keyboard::Escape) == true){
        return;
    }
    //VENTANA CLEAR LIMPIA TODA LA IMAGEN DE LA VENTANA
    _Ventana.clear();

    _Ventana.draw(cincoUFO);
    _Ventana.draw(sieteUFO);
    _Ventana.draw(diezUFO);
    _Ventana.draw(ghost);
    _Ventana.draw(nautilus);
    _Ventana.draw(nagronar);

    if(Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)){
       Nivel1(_Ventana);
    }

    if(Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)){
       Nivel3(_Ventana);
    }

    if(Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)){
       Nivel5(_Ventana);
    }

    if(Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)){
       Nivel2(_Ventana);
    }

    if(Keyboard::isKeyPressed(Keyboard::Num5) || Keyboard::isKeyPressed(Keyboard::Numpad5)){
       Nivel4(_Ventana);
    }

    if(Keyboard::isKeyPressed(Keyboard::Num6) || Keyboard::isKeyPressed(Keyboard::Numpad6)){
       Nivel6(_Ventana);
    }

    _Ventana.display();
}


}

void Juego::ModoKloster(sf::RenderWindow &v){
Tablero tableroUno, tableroDos;
Destructor destructor;
Acorazado acorazado;
Portaaviones portaaviones;
Submarino submarino;
Fragata fragata;
bool destructorUbicado = false, acorazadoUbicado = false, portaavionesUbicado = false, submarinoUbicado = false, fragataUbicada = false, embarcacionesUbicadas = false;
bool klosternatorUbicado = false;
int turno = 0, filaInt, columnaInt, decideKloster;
bool inputMode = false, partidaTerminada = false;
bool ganadorHumano = false, ganadorIA = false;
bool hablaKloster;
Fuego miFuego;
Agua miAgua;
Klosternator klosternator;

if (!_Musica.openFromFile("C:/Users/Gonzalo/Desktop/Database/Musica/Jefes/Klosternator.wav")) {
        // Manejar error si no se puede cargar la música
        // Por ejemplo, mostrar un mensaje de error y continuar sin música
    }
    //ACTIVAR MUSICA NAUTILUS
    _Musica.setVolume(25);
    //_Musica.play();

sf::Sprite recuadro;
sf::Texture texture;
recuadro.setPosition(30,311);
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Recuadro.png");
//recuadro.setScale(0.2f, 0.2f);
recuadro.setTexture(texture);

//CREACION DE LA FUENTE Y EL TEXTO
sf::Font fuente;
if (!fuente.loadFromFile("C:/Users/Gonzalo/Desktop/Database/PressStart2P.ttf")) {
    // SI NO CARGA LA FUENTE O HAY UN ERROR, SALE.
    return;
}


//PARA QUE APAREZCA UN TEXTO SOLICITANDO ALGO AL USUARIO
Text Ubicacion("Ubica tus barcos", fuente, 15);
Ubicacion.setPosition(50, 300);
Ubicacion.setFillColor(Color::White);

Text descripcion1("ERROR 404", fuente, 15);
descripcion1.setPosition(50, 328);
descripcion1.setFillColor(Color::White);

Text descripcion2("Te enfrentas a KLOSTERNATOR", fuente, 15);
descripcion2.setPosition(50, 356);
descripcion2.setFillColor(Color::White);

Text descripcion3("El enemigo ocupa 10 casillas", fuente, 15);
descripcion3.setPosition(50, 384);
descripcion3.setFillColor(Color::White);

Text descripcion4("?????", fuente, 15);
descripcion4.setPosition(50, 412);
descripcion4.setFillColor(Color::White);

Text descripcion5("?????", fuente, 15);
descripcion5.setPosition(50, 440);
descripcion5.setFillColor(Color::White);

//SETEO DEL TABLERO QUE PASAMOS POR REFERENCIA
tableroUno.setPosicion(50,0);


//PARA QUE APAREZCAN LOS NOMBRES DE LOS BARCOS
Text nombreDestructor("1) Destructor",fuente,13);
nombreDestructor.setPosition(50, 328);
nombreDestructor.setFillColor(Color::White);

Text nombreSubmarino("2) Submarino",fuente,13);
nombreSubmarino.setPosition(50, 356);
nombreSubmarino.setFillColor(Color::White);

Text nombreAcorazado("3) Acorazado",fuente,13);
nombreAcorazado.setPosition(50, 384);
nombreAcorazado.setFillColor(Color::White);

Text nombrePortaaviones("4) Portaaviones",fuente,13);
nombrePortaaviones.setPosition(50, 412);
nombrePortaaviones.setFillColor(Color::White);

Text nombreFragata("5) Fragata",fuente,13);
nombreFragata.setPosition(50, 440);
nombreFragata.setFillColor(Color::White);


while(_Ventana.isOpen()){
    //RESPETAR EL ORDEN DE ESTOS DOS
    //PROCESAR EVENTO PERMITE APRETAR ESCAPE PARA RETORNAR A UN MENU ANTERIOR Y CIERRA LA VENTANA SI ES NECESARIO
    ProcesarEvento();
    if(Keyboard::isKeyPressed(Keyboard::Escape) == true){
        return;
    }
    //VENTANA CLEAR LIMPIA TODA LA IMAGEN DE LA VENTANA
    _Ventana.clear();
    //HASTA ACA
    _Ventana.draw(recuadro);
    _Ventana.draw(tableroUno);


    //TODA LA LOGICA VA AHORA
    //FASE DE PREPARACIÓN
    //VENTANA DRAW DIBUJA LO QUE PASAMOS COMO PARÁMETRO
    //_Ventana.draw(tableroUno);
    if(embarcacionesUbicadas == false){

        //MOSTRAMOS LOS NOMBRES DE LOS BARCOS
        //ESTO IRA DESAPARECIENDO A MEDIDA QUE SE UBICA UN BARCO EN EL TABLERO
        if(destructorUbicado == false){
            _Ventana.draw(nombreDestructor);}
        if(submarinoUbicado == false){
            _Ventana.draw(nombreSubmarino);}
        if(acorazadoUbicado == false){
            _Ventana.draw(nombreAcorazado);}
        if(portaavionesUbicado == false){
            _Ventana.draw(nombrePortaaviones);}
        if(fragataUbicada == false){
            _Ventana.draw(nombreFragata);}


    //UBICAR BARCOS UTILIZANDO CONSOLA
    //1 UBICA DESTRUCTOR
    if(Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)){
        if(destructorUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarDestructor(destructor,tableroUno) == true){
            destructorUbicado = true;}
            inputMode = false;}
                }
            }
    //2 UBICA SUBMARINO
    if(Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)){
        if(submarinoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarSubmarino(submarino,tableroUno) == true){
            submarinoUbicado = true;}
            inputMode = false;}
                }
            }
    //3 UBICA ACORAZADO
    if(Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)){
        if(acorazadoUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarAcorazado(acorazado,tableroUno) == true){
            acorazadoUbicado = true;}
            inputMode = false;}
                }
            }
    //4 UBICA PORTAAVIONES
    if(Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)){
        if(portaavionesUbicado == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarPortaaviones(portaaviones,tableroUno) == true){
            portaavionesUbicado = true;}
            inputMode = false;}
                }
            }
    //5 UBICA FRAGATA
    if(Keyboard::isKeyPressed(Keyboard::Num5) || Keyboard::isKeyPressed(Keyboard::Numpad5)){
        if(fragataUbicada == false){
            inputMode = true;
            if(inputMode == true){
            if(tableroUno.ubicarFragata(fragata,tableroUno) == true){
            fragataUbicada = true;}
            inputMode = false;}
                }
            }



    if(embarcacionesUbicadas == false){
        //SI LOS BARCOS SE UBICARON, NO SE MOSTRARÁ MÁS EL MENSAJE "UBICA TUS BARCOS"
        _Ventana.draw(Ubicacion);
        if(destructorUbicado == true){
        _Ventana.draw(destructor);}
        if(fragataUbicada == true){
        _Ventana.draw(fragata);}
        if(submarinoUbicado == true){
        _Ventana.draw(submarino);}
        if(portaavionesUbicado == true){
            _Ventana.draw(portaaviones);}
        if(acorazadoUbicado == true){
            _Ventana.draw(acorazado);}
        }

    //SALIMOS DEL WHILE SI SE UBICARON TODOS LOS BARCOS
    if(destructorUbicado == true && fragataUbicada == true && submarinoUbicado == true && portaavionesUbicado == true && acorazadoUbicado == true){
        embarcacionesUbicadas = true;}
    }

    //LIMPIAMOS EL NOMBRE DEL ULTIMO BARCO CON EL .CLEAR() Y MOSTRAMOS LOS SPRITES CON LOS .DRAW Y .DISPLAY
    if(embarcacionesUbicadas == true){
        _Ventana.clear();
        _Ventana.draw(tableroUno);
        _Ventana.draw(destructor);
        _Ventana.draw(acorazado);
        _Ventana.draw(fragata);
        _Ventana.draw(portaaviones);
        _Ventana.draw(submarino);
        _Ventana.draw(recuadro);
        _Ventana.draw(descripcion1);
        _Ventana.draw(descripcion2);
        _Ventana.draw(descripcion3);
        _Ventana.draw(descripcion4);
        _Ventana.draw(descripcion5);
        klosternator._sprite.setPosition(375,15);
        _Ventana.draw(klosternator._sprite);
        _Ventana.display();}


    if(embarcacionesUbicadas == true){
        tableroDos.completarTableroNivelKloster(tableroDos);
        klosternatorUbicado = true;
        }


    //TODOS LOS BARCOS UBICADOS. EMPIEZA LA FASE DE ATAQUE

        if(embarcacionesUbicadas == true && klosternatorUbicado == true){

        while(partidaTerminada == false){
                _Ventana.clear();
            //SI EL TURNO ES PAR, ATACA EL HUMANO. SI ES IMPAR, ATACA LA IA
            turno++;


                if(turno % 2 == 0){
                //TURNO JUGADOR HUMANO
                if(klosternator.estoEsBatata() == false){
                cout<<"TURNO: "<<turno<<endl;
                cout<<"FILA: ";
                cin>>filaInt;
                cout<<"COLUMNA: ";
                cin>>columnaInt;
                 if(tableroDos.atacar(filaInt,columnaInt,tableroDos) == true){
                miFuego._sound.play();
                }else{
                miAgua._sound.play();
                }
                system("PAUSE");
                system("cls");
                if(tableroDos.evaluarTablero(tableroDos) == true){
                cout<<"Has eliminado a tu rival. Partida terminada"<<endl;
                 _Musica.stop();
                ganadorHumano = true;
                partidaTerminada = true;}
                //ESTO LUEGO HAY QUE SACAR
                cout<<"Tablero IA"<<endl;
                tableroDos.mostrarTablero(tableroDos);}
                }

            if(turno % 2 != 0){
                //TURNO IA
            cout<<"TURNO: "<<turno<<endl;
            if(turno % 5 == 0){
                klosternator._sound.play();
                hablaKloster = klosternator.seEntiendeGentes();
                if(hablaKloster == false){
                    tableroUno.getAtaqueKloster(tableroUno);
                }
            }
            tableroUno.atacaIA(tableroUno,_Ventana);
            system("PAUSE");
            system("cls");
            if(tableroUno.evaluarTablero(tableroUno) == true){
                cout<<"El enemigo nos ha derrotado. Partida terminada"<<endl;
                _Musica.stop();
                ganadorIA = true;
                partidaTerminada = true;}
            system("cls");
            //ESTO LUEGO HAY QUE SACAR
            cout<<"Tablero Humano"<<endl;
            tableroUno.mostrarTablero(tableroUno);}
            }//LLAVE WHILE
        }

    if(partidaTerminada == true){
        return;}
        _Ventana.display();}

}



