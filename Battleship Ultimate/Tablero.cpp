#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tablero.h"
#include <time.h>
using namespace std;

Tablero::Tablero(){
texture.loadFromFile("C:/Users/Gonzalo/Desktop/Database/Sprites/Tablero/Tablero.png");
setSprite(texture);

}

void Tablero::completarTableroNormal(){
Tablero tableroNormal;
int opcion;
int x,y;
int coordenadaX,coordenadaY;
Destructor miDestructor;
Fragata miFragata;
Portaaviones miPortaaviones;
Submarino miSubmarino;
Acorazado miAcorazado;
bool embarcacionesUbicadas = false;
bool destructorUbicado = false, fragataUbicada = false, portaavionesUbicado = false, submarinoUbicado = false, acorazadoUbicado = false;

tableroNormal.vaciarTablero();

while(embarcacionesUbicadas == false){

    tableroNormal.mostrarTableroHumano();
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
    tableroNormal.mostrarTableroHumano();
    destructorUbicado = true;
break;
case 2:
    system("cls");
    tableroNormal.ubicarFragata(miFragata, tableroNormal);
    system("cls"),
    tableroNormal.mostrarTableroHumano();
    fragataUbicada = true;
break;
case 3:
    system("cls");
    tableroNormal.ubicarSubmarino(miSubmarino, tableroNormal);
    system("cls");
    tableroNormal.mostrarTableroHumano();
    submarinoUbicado = true;
break;
case 4:
    system("cls");
    tableroNormal.ubicarPortaaviones(miPortaaviones, tableroNormal);
    system("cls");
    tableroNormal.mostrarTableroHumano();
    portaavionesUbicado = true;
break;
case 5:
    system("cls");
    tableroNormal.ubicarAcorazado(miAcorazado,tableroNormal);
    system("cls");
    tableroNormal.mostrarTableroHumano();
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

void Tablero::mostrarTableroHumano(){
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
            cout<<_Tamanio[x][y]<<"  ";
        }else{
            cout<<" "<<_Tamanio[x][y]<<" ";
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

void Tablero::vaciarTablero(){
int x,y;

for(x=0;x<10;x++){
    for(y=0;y<10;y++){
        _Tamanio[x][y] = 0;
        }
    }
}

void Tablero::ubicarDestructor(Destructor miDestructor, Tablero miTablero){
int coordenadaX = 0,coordenadaY = 0, x, y, direccion;
bool destructorUbicado = false, ubicacionValida = false;
int limite;

mostrarTableroHumano();

cout<<"De que forma desea ubicar su "<<miDestructor.getNombre()<<endl;
cout<<"1) Vertical"<<endl;
cout<<"2) Horizontal"<<endl;
cout<<"Opcion: ";
cin>>direccion;

while(direccion!=1 && direccion != 2){
    cout<<"Error al cargar la direccion de su "<<miDestructor.getNombre()<<endl;
    cout<<"Por favor, ingrese una direccion valida"<<endl;
    cout<<"1)Vertical"<<endl;
    cout<<"2)Horizontal"<<endl;
    cout<<"Opcion: ";
    cin>>direccion;
}

    while(destructorUbicado == false){
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
        if(_Tamanio[coordenadaX-1][coordenadaY-1] == 1 || _Tamanio[coordenadaX][coordenadaY-1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[coordenadaX-1][coordenadaY-1] = 1;
                _Tamanio[coordenadaX][coordenadaY-1] = 1;
                cout<<"Destructor ubicado";
                cout<<endl;
                system("PAUSE");
                destructorUbicado = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[coordenadaX-1][coordenadaY-1] == 1 || _Tamanio[coordenadaX-1][coordenadaY] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[coordenadaX-1][coordenadaY-1] = 1;
                _Tamanio[coordenadaX-1][coordenadaY] = 1;
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

mostrarTableroHumano();

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

mostrarTableroHumano();

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

mostrarTableroHumano();

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

mostrarTableroHumano();

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








