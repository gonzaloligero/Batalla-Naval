#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tablero.h"
#include <Windows.h>
#include <time.h>
#include <conio.h>
using namespace std;

Tablero::Tablero(){
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Tablero/Tablero.png");
_sprite.setScale(0.5f, 0.5f);
setSprite(texture);
int x,y;

for(x=0;x<10;x++){
    for(y=0;y<10;y++){
        _Tamanio[x][y] = 1;
    }
}


}

void Tablero::completarTableroNormal(Tablero &tableroNormal){
int opcion;
Destructor miDestructor;
Fragata miFragata;
Portaaviones miPortaaviones;
Submarino miSubmarino;
Acorazado miAcorazado;
bool embarcacionesUbicadas = false;
bool destructorUbicado = false, fragataUbicada = false, portaavionesUbicado = false, submarinoUbicado = false, acorazadoUbicado = false;



while(embarcacionesUbicadas == false){

    tableroNormal.mostrarTableroHumano(tableroNormal);
    cout<<endl;
    cout<<"Que embarcacion desea ubicar"<<endl;
    cout<<endl;
    if(destructorUbicado == false){
        cout<<"1) "<<miDestructor.getNombre()<<endl;;
    }
    if(fragataUbicada == false){
        cout<<"2) "<<miFragata.getNombre()<<endl;;
    }
    if(submarinoUbicado == false){
        cout<<"3) "<<miSubmarino.getNombre()<<endl;
    }
    if(portaavionesUbicado == false){
        cout<<"4) "<<miPortaaviones.getNombre()<<endl;;
    }
    if(acorazadoUbicado == false){
        cout<<"5) "<<miAcorazado.getNombre()<<endl;;
    }

cout<<"Opcion: ";
cin>>opcion;

switch(opcion){
case 1:
    system("cls");
    tableroNormal.ubicarDestructor(miDestructor, tableroNormal);
    system("cls");
    tableroNormal.mostrarTableroHumano(tableroNormal);
    destructorUbicado = true;
break;
case 2:
    system("cls");
    tableroNormal.ubicarFragata(miFragata, tableroNormal);
    system("cls"),
    tableroNormal.mostrarTableroHumano(tableroNormal);
    fragataUbicada = true;
break;
case 3:
    system("cls");
    tableroNormal.ubicarSubmarino(miSubmarino, tableroNormal);
    system("cls");
    tableroNormal.mostrarTableroHumano(tableroNormal);
    submarinoUbicado = true;
break;
case 4:
    system("cls");
    tableroNormal.ubicarPortaaviones(miPortaaviones, tableroNormal);
    system("cls");
    tableroNormal.mostrarTableroHumano(tableroNormal);
    portaavionesUbicado = true;
break;
case 5:
    system("cls");
    tableroNormal.ubicarAcorazado(miAcorazado,tableroNormal);
    system("cls");
    tableroNormal.mostrarTableroHumano(tableroNormal);
    acorazadoUbicado = true;
break;

        }
system("cls");

if(portaavionesUbicado == true && submarinoUbicado == true && acorazadoUbicado == true && destructorUbicado == true && fragataUbicada == true){
    cout<<"Todos los barcos fueron ubicados"<<endl;
    cout<<"Preparate para la batalla"<<endl;
    embarcacionesUbicadas = true;
        }
    }
}

void Tablero::mostrarTableroHumano(Tablero &miTablero){
int x,y;
int fila = 1;
char columna;


cout<<"    A  B  C  D  E  F  G  H  I  J"<<endl;
cout<<"    -  -  -  -  -  -  -  -  -  -";
for(x=0;x<10;x++){
        cout<<endl;
        if(fila!=10){
        cout<<fila;
        cout<<" | ";
        }else{
        cout<<fila;
        cout<<"|";
        }

    for(y=0;y<10;y++){
        if(fila!=10){
            cout<<miTablero._Tamanio[x][y]<<"  ";
        }else{
            cout<<" "<<miTablero._Tamanio[x][y]<<" ";
        }

    }
    if(fila!=10){
        cout<<"|"<<endl;
    }else{
        cout<<" |"<<endl;
    }

    fila++;
}

}

void Tablero::ubicarDestructor(Destructor miDestructor, Tablero miTablero){
int fila = 0,columna = 0, x, y, direccion;
char filaChar;
bool destructorUbicado = false, ubicacionValida = false;
int limite;

mostrarTableroHumano(miTablero);

cout<<"De que forma desea ubicar su "<<miDestructor.getNombre()<<endl;
cout<<"1) Vertical"<<endl;
cout<<"2) Horizontal"<<endl;
cout<<"Opcion: ";
cin>>direccion;

while(direccion!=1 && direccion != 2){
    system("cls");
    cout<<"Error al cargar la direccion de su "<<miDestructor.getNombre()<<endl;
    cout<<"Por favor, ingrese una direccion valida"<<endl;
    cout<<"1)Vertical"<<endl;
    cout<<"2)Horizontal"<<endl;
    cout<<"Opcion: ";
    cin>>direccion;
}

    while(destructorUbicado == false){

    while(fila < 1 || fila > 10){
    cout<<"Fila: ";
    cin>>filaChar;
    switch(filaChar){
    case 'A': fila = 1;
    break;
    case 'a': fila = 1;
    break;
    case 'B': fila = 2;
    break;
    case 'b': fila = 2;
    break;
    case 'C': fila = 3;
    break;
    case 'c': fila = 3;
    break;
    case 'D': fila = 4;
    break;
    case 'd': fila = 4;
    break;
    case 'E': fila = 5;
    break;
    case 'e': fila = 5;
    break;
    case 'F': fila = 6;
    break;
    case 'f': fila = 6;
    break;
    case 'G': fila = 7;
    break;
    case 'g': fila = 7;
    break;
    case 'H': fila = 8;
    break;
    case 'h': fila = 8;
    break;
    case 'I': fila = 9;
    break;
    case 'i': fila = 9;
    break;
    case 'J': fila = 10;
    break;
    case 'j': fila = 10;
    break;
        }
    if(fila < 1 || columna > 10){
        cout<<"Ingrese un numero de fila valido"<<endl;
        }
    }

    while(columna < 1 || columna > 10){
    cout<<"Columna: ";
    cin>>columna;
    if(columna < 1 || columna > 10){
        cout<<"Ingrese un numero de columna valido"<<endl;
        }
    }

    //REVISAR ESTO PORQUE QUIZA NO HACE FALTA CHEQUEAR LA FILA SINO SOLO LA COLUMNA
    if(fila == 10 && direccion == 1){
        cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
        while(fila == 10){
            cout<<"Fila: ";
            cin>>fila;
            cout<<"Columna: ";
            cin>>columna;
        }
    }

    if(columna == 10 && direccion == 2 || columna == 1 && direccion == 2){
        while(columna == 10){
            cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
            cout<<"Fila: ";
            cin>>fila;
            cout<<"Columna: ";
            cin>>columna;
        }
    }

    if(fila>10 || fila < 1 || columna >10 || columna < 1){
        cout<<"No existe ese lugar en el tablero. Ingrese uno valido";

        while(fila>10 || fila < 1 || columna >10 || columna < 1){
            cout<<"Fila: ";
            cin>>fila;
            cout<<"Columna: ";
            cin>>columna;
            }
        }

    if(direccion == 1){
        if(_Tamanio[fila-1][columna-1] == 1 || _Tamanio[fila][columna-1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[fila-1][columna-1] = 1;
                _Tamanio[fila][columna-1] = 1;
                cout<<"Destructor ubicado";
                cout<<endl;
                system("PAUSE");
                destructorUbicado = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[fila-1][columna-1] == 1 || _Tamanio[fila-1][columna] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[fila-1][columna-1] = 1;
                _Tamanio[fila-1][columna] = 1;
                cout<<"Destructor ubicado"<<endl;
                cout<<endl;
                system("PAUSE");
                destructorUbicado = true;
            }
        }
    }




}



void Tablero::ubicarAcorazado(Acorazado miAcorazado, Tablero miTablero){
int coordenadaX = 0,coordenadaY = 0, x, y, direccion;
bool acorazadoUbicado = false;

mostrarTableroHumano(miTablero);

cout<<"De que forma desea ubicar su "<<miAcorazado.getNombre()<<endl;
cout<<"1) Vertical"<<endl;
cout<<"2) Horizontal"<<endl;
cout<<"Opcion: ";
cin>>direccion;

while(direccion!=1 && direccion != 2){
    cout<<"Error al cargar la direccion de su "<<miAcorazado.getNombre()<<endl;
    cout<<"Por favor, ingrese una direccion valida"<<endl;
    cout<<"1)Vertical"<<endl;
    cout<<"2)Horizontal"<<endl;
    cout<<"Opcion: ";
    cin>>direccion;
}

while(acorazadoUbicado == false){
    cout<<"Fila: ";
    cin>>coordenadaX;
    cout<<"Columna: ";
    cin>>coordenadaY;

    if(coordenadaX == 10 && direccion == 1){
        cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
        while(coordenadaX == 10){
            cout<<"Fila: ";
            cin>>coordenadaX;
            cout<<"Columna: ";
            cin>>coordenadaY;
        }
    }

    if(coordenadaY == 10 && direccion == 2){
        while(coordenadaY == 10){
            cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
            cout<<"Fila: ";
            cin>>coordenadaX;
            cout<<"Columna: ";
            cin>>coordenadaY;
        }
    }

    if(coordenadaX>10 || coordenadaX < 1 || coordenadaY >10 || coordenadaY < 1){
        cout<<"No existe ese lugar en el tablero. Ingrese uno valido";

        while(coordenadaX>10 || coordenadaX < 1 || coordenadaY >10 || coordenadaY < 1){
            cout<<"Fila: ";
            cin>>coordenadaX;
            cout<<"Columna: ";
            cin>>coordenadaY;
            }
        }

    if(direccion == 1){
        if(_Tamanio[coordenadaX-1][coordenadaY-1] == 1 || _Tamanio[coordenadaX][coordenadaY-1] == 1 || _Tamanio[coordenadaX][coordenadaY-2] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[coordenadaX-1][coordenadaY-1] = 1;
                _Tamanio[coordenadaX][coordenadaY-1] = 1;
                _Tamanio[coordenadaX+1][coordenadaY-1] = 1;
                cout<<"Acorazado ubicado";
                cout<<endl;
                system("PAUSE");
                acorazadoUbicado = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[coordenadaX-1][coordenadaY-1] == 1 || _Tamanio[coordenadaX-1][coordenadaY] == 1 || _Tamanio[coordenadaX][coordenadaY-2] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[coordenadaX-1][coordenadaY-1] = 1;
                _Tamanio[coordenadaX-1][coordenadaY] = 1;
                _Tamanio[coordenadaX-1][coordenadaY+1] = 1;
                cout<<"Acorazado ubicado"<<endl;
                cout<<endl;
                system("PAUSE");
                acorazadoUbicado = true;
            }
        }
    }
}

void Tablero::ubicarFragata(Fragata miFragata, Tablero miTablero){
int coordenadaX = 0,coordenadaY = 0, x, y, direccion;
bool fragataUbicada = false;

mostrarTableroHumano(miTablero);

cout<<"De que forma desea ubicar su "<<miFragata.getNombre()<<endl;
cout<<"1) Vertical"<<endl;
cout<<"2) Horizontal"<<endl;
cout<<"Opcion: ";
cin>>direccion;

while(direccion!=1 && direccion != 2){
    cout<<"Error al cargar la direccion de su "<<miFragata.getNombre()<<endl;
    cout<<"Por favor, ingrese una direccion valida"<<endl;
    cout<<"1)Vertical"<<endl;
    cout<<"2)Horizontal"<<endl;
    cout<<"Opcion: ";
    cin>>direccion;
}

while(fragataUbicada == false){
    cout<<"Fila: ";
    cin>>coordenadaX;
    cout<<"Columna: ";
    cin>>coordenadaY;

    if(coordenadaX>10 || coordenadaX < 1 || coordenadaY >10 || coordenadaY < 1){
        cout<<"No existe ese lugar en el tablero. Ingrese uno valido";

        while(coordenadaX>10 || coordenadaX < 1 || coordenadaY >10 || coordenadaY < 1){
            cout<<"Fila: ";
            cin>>coordenadaX;
            cout<<"Columna: ";
            cin>>coordenadaY;
            }
        }

    if(direccion == 1){
        if(_Tamanio[coordenadaX-1][coordenadaY-1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[coordenadaX-1][coordenadaY-1] = 1;
                cout<<"Fragata ubicada";
                cout<<endl;
                system("PAUSE");
                fragataUbicada = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[coordenadaX-1][coordenadaY-1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[coordenadaX-1][coordenadaY-1] = 1;
                cout<<"Fragata ubicada"<<endl;
                cout<<endl;
                system("PAUSE");
                fragataUbicada = true;
                }
            }
        }
    }

void Tablero::ubicarSubmarino(Submarino miSubmarino, Tablero miTablero){
int coordenadaX = 0,coordenadaY = 0, x, y, direccion;
bool submarinoUbicado = false;

mostrarTableroHumano(miTablero);

cout<<"De que forma desea ubicar su "<<miSubmarino.getNombre()<<endl;
cout<<"1) Vertical"<<endl;
cout<<"2) Horizontal"<<endl;
cout<<"Opcion: ";
cin>>direccion;

while(direccion!=1 && direccion != 2){
    cout<<"Error al cargar la direccion de su "<<miSubmarino.getNombre()<<endl;
    cout<<"Por favor, ingrese una direccion valida"<<endl;
    cout<<"1)Vertical"<<endl;
    cout<<"2)Horizontal"<<endl;
    cout<<"Opcion: ";
    cin>>direccion;
}

while(submarinoUbicado == false){
    cout<<"Fila: ";
    cin>>coordenadaX;
    cout<<"Columna: ";
    cin>>coordenadaY;

    if(coordenadaX == 10 && direccion == 1){
        cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
        while(coordenadaX == 10){
            cout<<"Fila: ";
            cin>>coordenadaX;
            cout<<"Columna: ";
            cin>>coordenadaY;
        }
    }

    if(coordenadaY == 10 && direccion == 2){
        while(coordenadaY == 10){
            cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
            cout<<"Fila: ";
            cin>>coordenadaX;
            cout<<"Columna: ";
            cin>>coordenadaY;
        }
    }

    if(coordenadaX>10 || coordenadaX < 1 || coordenadaY >10 || coordenadaY < 1){
        cout<<"No existe ese lugar en el tablero. Ingrese uno valido";

        while(coordenadaX>10 || coordenadaX < 1 || coordenadaY >10 || coordenadaY < 1){
            cout<<"Fila: ";
            cin>>coordenadaX;
            cout<<"Columna: ";
            cin>>coordenadaY;
            }
        }

    if(direccion == 1){
        if(_Tamanio[coordenadaX-1][coordenadaY-1] == 1 || _Tamanio[coordenadaX][coordenadaY-1] == 1 || _Tamanio[coordenadaX][coordenadaY-2] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[coordenadaX-1][coordenadaY-1] = 1;
                _Tamanio[coordenadaX][coordenadaY-1] = 1;
                _Tamanio[coordenadaX+1][coordenadaY-1] = 1;
                cout<<"Submarino ubicado";
                cout<<endl;
                system("PAUSE");
                submarinoUbicado = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[coordenadaX-1][coordenadaY-1] == 1 || _Tamanio[coordenadaX-1][coordenadaY] == 1 || _Tamanio[coordenadaX][coordenadaY-2] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[coordenadaX-1][coordenadaY-1] = 1;
                _Tamanio[coordenadaX-1][coordenadaY] = 1;
                _Tamanio[coordenadaX-1][coordenadaY+1] = 1;
                cout<<"Submarino ubicado"<<endl;
                cout<<endl;
                system("PAUSE");
                submarinoUbicado = true;
            }
        }
    }
}

void Tablero::ubicarPortaaviones (Portaaviones miPortaaviones, Tablero miTablero){
int coordenadaX = 0,coordenadaY = 0, x, y, direccion;
bool portaavionesUbicado = false;

mostrarTableroHumano(miTablero);

cout<<"De que forma desea ubicar su "<<miPortaaviones.getNombre()<<endl;
cout<<"1) Vertical"<<endl;
cout<<"2) Horizontal"<<endl;
cout<<"Opcion: ";
cin>>direccion;

while(direccion!=1 && direccion != 2){
    cout<<"Error al cargar la direccion de su "<<miPortaaviones.getNombre()<<endl;
    cout<<"Por favor, ingrese una direccion valida"<<endl;
    cout<<"1)Vertical"<<endl;
    cout<<"2)Horizontal"<<endl;
    cout<<"Opcion: ";
    cin>>direccion;
}

while(portaavionesUbicado == false){
    cout<<"Fila: ";
    cin>>coordenadaX;
    cout<<"Columna: ";
    cin>>coordenadaY;

    if(coordenadaX == 10 && direccion == 1){
        cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
        while(coordenadaX == 10){
            cout<<"Fila: ";
            cin>>coordenadaX;
            cout<<"Columna: ";
            cin>>coordenadaY;
        }
    }

    if(coordenadaY == 10 && direccion == 2){
        while(coordenadaY == 10){
            cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
            cout<<"Fila: ";
            cin>>coordenadaX;
            cout<<"Columna: ";
            cin>>coordenadaY;
        }
    }

    if(coordenadaX>10 || coordenadaX < 1 || coordenadaY >10 || coordenadaY < 1){
        cout<<"No existe ese lugar en el tablero. Ingrese uno valido";

        while(coordenadaX>10 || coordenadaX < 1 || coordenadaY >10 || coordenadaY < 1){
            cout<<"Fila: ";
            cin>>coordenadaX;
            cout<<"Columna: ";
            cin>>coordenadaY;
            }
        }

    if(direccion == 1){
        if(_Tamanio[coordenadaX-1][coordenadaY-1] == 1 || _Tamanio[coordenadaX][coordenadaY] == 1 || _Tamanio[coordenadaX][coordenadaY-1] == 1 || _Tamanio[coordenadaX][coordenadaY-2] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[coordenadaX-1][coordenadaY-1] = 1;
                _Tamanio[coordenadaX][coordenadaY-1] = 1;
                _Tamanio[coordenadaX+1][coordenadaY-1] = 1;
                _Tamanio[coordenadaX+2][coordenadaY-1] = 1;
                cout<<"Portaaviones ubicado";
                cout<<endl;
                system("PAUSE");
                portaavionesUbicado = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[coordenadaX-1][coordenadaY-1] == 1 || _Tamanio[coordenadaX-1][coordenadaY] == 1 || _Tamanio[coordenadaX][coordenadaY-2] == 1 || _Tamanio [coordenadaX][coordenadaY-3] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[coordenadaX-1][coordenadaY-1] = 1;
                _Tamanio[coordenadaX-1][coordenadaY] = 1;
                _Tamanio[coordenadaX-1][coordenadaY+1] = 1;
                _Tamanio[coordenadaX-1][coordenadaY+2] = 1;
                cout<<"Portaaviones ubicado"<<endl;
                cout<<endl;
                system("PAUSE");
                portaavionesUbicado = true;
            }
        }
    }

}

void Tablero::atacar(int fila,int columna, Tablero &miTablero){

if(miTablero._Tamanio[fila-1][columna-1] == 1){
    cout<<"Barco detectado"<<endl;
    miTablero._Tamanio[fila-1][columna-1] = 0;
    }else if(miTablero._Tamanio[fila-1][columna-1] == 0){
    cout<<"No se detectaron barcos";}
}

bool Tablero::evaluarTablero(Tablero &miTablero){
int x,y;
bool tableroVacio = true;

for(x=0;x<10;x++){
    for(y=0;y<10;y++){
        if(miTablero._Tamanio[x][y] == 1){
            tableroVacio = false;
            return false;
        }
    }
}

if(tableroVacio == true){
    cout<<"No quedan embarcaciones en el tablero"<<endl;
    cout<<"Partida terminada"<<endl;
    return true;
        }
    }

void Tablero::getAtaqueNagronar(int fila){
int x;

for(x=0;x<10;x++){
    _Tamanio[fila][x] = 0;
    }
}

void Tablero::getAtaqueBombardero(int fila, bool &supremacia, int &filaSupremacia){
int x;

if(supremacia == false || supremacia == true && filaSupremacia != fila){
    for(x=0;x<10;x++){
    _Tamanio[fila][x] = 0;}
    }else if(supremacia == true && filaSupremacia == fila){
        cout<<"La supremacia aerea otorgada por el caza evito el ataque"<<endl;
    }

}

void Tablero::getAtaqueDron(int fila, int columna, int &contadorAtaques){

    if(contadorAtaques == 0){
        cout<<"Se utilizaron las tres cargas del dron"<<endl;
        return;
    }else{
        _Tamanio[fila-1][columna-1] = 0;
        contadorAtaques--;
    }
}

void Tablero::detectarEmbarcaciones(Reconocimiento &miReconocimiento){
int fila,columna;
bool deteccion = false;

if(miReconocimiento.getCargas() == 0){
    cout<<"No quedan cargas del avion para utilizar"<<endl;
    return;
}

cout<<"Fila: ";
cin>>fila;
cout<<"Columna: ";
cin>>columna;

if(_Tamanio[fila-1][columna-1] == 1){
    deteccion = true;;;
}

if(deteccion == true && miReconocimiento.getCargas() > 0){
    cout<<miReconocimiento.getCargas()<<endl;
    cout<<"Se detecto un objeto en esas coordenadas"<<endl;
    miReconocimiento.descontarCarga();
}else{
    cout<<"No se detectaron objetos en esas coordenadas"<<endl;
    miReconocimiento.descontarCarga();
    }
}










