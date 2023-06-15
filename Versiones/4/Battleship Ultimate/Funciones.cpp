#include <iostream>
#include <cctype>
#include "Funciones.h"
#include "Tablero.h"
#include "Jugador.h"
using namespace std;

void menuPrincipal(Jugador player1){
int opcion = 0,salir = 0;

while(opcion!=4){

    cout<<"BATTLESHIP ULTIMATE: PIPOL EDITION";
    cout<<endl;
    cout<<"1)MODO HISTORIA"<<endl;
    cout<<"2)MODO CLASICO"<<endl;
    cout<<"3)PUNTAJES"<<endl;
    cout<<"4)SALIR"<<endl;
    cout<<endl;
    cout<<"OPCION: ";
    cin>>opcion;

switch(opcion){
case 1:
    player1.setNombre();
    system("PAUSE");
    system("cls");
break;
case 2:
    system("cls");
    modoDosJugadores();
    system("PAUSE");
    system("cls");

break;
case 3:
    system("cls");
    cout<<"Completar"<<endl;
    system("PAUSE");
    system("cls");
break;
case 4:
    salir = confirmarSalida();
    if(salir==0){
    opcion = 0;
    system("cls");
    }else if(salir==1){

    opcion = 4;}


break;

        }
    }

mensajeDeSalida();

}


int confirmarSalida(){
int opcion;

system("cls");

cout<<"Deseas salir del juego? (0 No - 1 Confirmar salida)"<<endl;
cout<<"Opcion: ";
cin>>opcion;

    if(opcion==1){
        return 1;
    }else if(opcion==0){
        return 0;
    }
}

void mensajeDeSalida(){
    cout<<"Gracias por jugar a BATTLESHIP ULTIMATE:PIPOL EDITION"<<endl;

}

void modoDosJugadores(){
bool ganador = false;
int fila,columna;
Jugador player1, player2;
Tablero tablero1, tablero2;

cin.ignore();
cout<<"Nombre jugador 1"<<endl;
player1.setNombre();
cout<<"Nombre jugador 2"<<endl;
player2.setNombre();

system("cls");

cout<<player1.getNombre()<<" completa tu tablero"<<endl;
tablero1.completarTableroNormal(tablero1);

system("cls");

cout<<player2.getNombre()<<" completa tu tablero"<<endl;
tablero2.completarTableroNormal(tablero2);

system("cls");

cout<<"Tablero "<<player1.getNombre()<<endl;
tablero1.mostrarTableroHumano(tablero1);
cout<<endl;
system("PAUSE");
system("cls");

cout<<"Tablero "<<player2.getNombre()<<endl;
tablero2.mostrarTableroHumano(tablero2);
cout<<endl;
system("PAUSE");
system("cls");
cout<<"Preparense para la batalla"<<endl;

while(ganador == false){

cout<<"Turno "<<player1.getNombre()<<endl;
cout<<"Fila: ";
cin>>fila;
cout<<"Columna: ";
cin>>columna;
tablero2.atacar(fila,columna, tablero2);
if(tablero2.evaluarTablero(tablero2) == true){
    cout<<"Ganador "<<player1.getNombre()<<endl;
    ganador = true;
}

system("PAUSE");
system("cls");

cout<<"Tablero "<<player1.getNombre()<<endl;
tablero1.mostrarTableroHumano(tablero1);

system("PAUSE");
system("cls");

cout<<"Tablero "<<player2.getNombre()<<endl;
tablero2.mostrarTableroHumano(tablero2);

if(ganador != true){
    cout<<"Turno"<<player2.getNombre()<<endl;
cout<<"Fila: ";
cin>>fila;
cout<<"Columna: ";
cin>>columna;

tablero1.atacar(fila,columna,tablero1);
if(tablero2.evaluarTablero(tablero1) == true){
    cout<<"Ganador "<<player2.getNombre()<<endl;
    ganador = true;
}

system("PAUSE");
system("cls");

cout<<"Tablero "<<player2.getNombre()<<endl;
tablero2.mostrarTableroHumano(tablero2);
}


}


}
