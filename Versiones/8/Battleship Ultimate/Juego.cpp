#include <iostream>
#include "Juego.h"
#include "Tablero.h"
#include "Caza.h"
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
int opcionSeleccionada = -1; // Inicialmente ninguna opción está seleccionada
bool mostrarPulsaEnter = true, modoClasico = false, modoHistoria = false;
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
                _Ventana.draw(recuadro);
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
            cout<<"FILA: ";
            cin>>filaInt;
            cout<<"COLUMNA: ";
            cin>>columnaInt;
            tableroDos.atacar(filaInt,columnaInt,tableroDos);
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
            tableroUno.atacaIA(tableroUno);
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
int turno = 0, filaInt, columnaInt, nroAvion;
bool inputMode = false, partidaTerminada = false;
bool ganadorHumano = false, ganadorIA = false;
bool avionElegido = false, supremaciaHumano = false, supremaciaIA = false, apoyoUtilizado = false;
int filaSupremaciaHumano, filaSupremaciaIA, filaBombarderoHumano,filaBombarderoIA, fila1,fila2,fila3,columna1,columna2,columna3,reconHumano1,reconHumano2,reconHumano3;
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
            avionElegido = true;
        }

    }



    //TODA LA LOGICA VA AHORA
    //FASE DE PREPARACIÓN
    //VENTANA DRAW DIBUJA LO QUE PASAMOS COMO PARÁMETRO
    _Ventana.draw(tableroUno);
    _Ventana.draw(tableroDos);
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

        //TERMINAR PARA HUMANO. TENER EN CUENTA EL CAZA
        if(apoyoUtilizado == false){
        switch(nroAvion){
        case 1: tableroDos.getAtaqueBombardero(filaBombarderoHumano,supremaciaIA,filaSupremaciaIA);
                apoyoUtilizado = true;
        break;
        case 3: tableroDos.getAtaqueDron(fila1,columna1, supremaciaHumano, filaSupremaciaHumano);
                tableroDos.getAtaqueDron(fila2,columna2, supremaciaHumano, filaSupremaciaHumano);
                tableroDos.getAtaqueDron(fila3,columna3, supremaciaHumano, filaSupremaciaHumano);
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
        /*
        if(apoyoUtilizado == false){
        switch(nroAvion){
        case 1:
        break;
        case 3:
        break;
        case 4:
        break;
            }
        }*/


        if(turno % 2 == 0){
            //TURNO JUGADOR HUMANO
            cout<<"FILA: ";
            cin>>filaInt;
            cout<<"COLUMNA: ";
            cin>>columnaInt;
            tableroDos.atacar(filaInt,columnaInt,tableroDos);
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
            tableroUno.atacaIA(tableroUno);
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

void Juego::ModoHistoria(sf::RenderWindow &v){

    Nivel1(_Ventana);
}




