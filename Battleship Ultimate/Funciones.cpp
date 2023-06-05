#include <iostream>
#include <cctype>
#include "Funciones.h"
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
    cout<<"Completar"<<endl;
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


void menuModoHistoria();
