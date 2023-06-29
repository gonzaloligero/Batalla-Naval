#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tablero.h"
#include "Funciones.h"
#include "Nagronar.h"
#include "Ghost.h"
#include "Nautilus.h"
#include "Klosternator.h"
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
        _Tamanio[x][y] = 0;}
    }
}

void Tablero::setPosicion(int x,int y){
    _sprite.setPosition(x,y);
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

    tableroNormal.mostrarTablero(tableroNormal);
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
    tableroNormal.mostrarTablero(tableroNormal);
    destructorUbicado = true;
break;
case 2:
    system("cls");
    tableroNormal.ubicarFragata(miFragata, tableroNormal);
    system("cls"),
    tableroNormal.mostrarTablero(tableroNormal);
    fragataUbicada = true;
break;
case 3:
    system("cls");
    tableroNormal.ubicarSubmarino(miSubmarino, tableroNormal);
    system("cls");
    tableroNormal.mostrarTablero(tableroNormal);
    submarinoUbicado = true;
break;
case 4:
    system("cls");
    tableroNormal.ubicarPortaaviones(miPortaaviones, tableroNormal);
    system("cls");
    tableroNormal.mostrarTablero(tableroNormal);
    portaavionesUbicado = true;
break;
case 5:
    system("cls");
    tableroNormal.ubicarAcorazado(miAcorazado,tableroNormal);
    system("cls");
    tableroNormal.mostrarTablero(tableroNormal);
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

bool Tablero::completarTableroEnemigoNivel1(Tablero &suTablero){
UFO vectorUFOS[5];
bool enemigosUbicados = false, vectorUbicados[5]={false};
int x;



while(enemigosUbicados == false){

    //EL PRIMER ENEMIGO NO TIENE VALIDACION PORQUE EL TABLERO ESTA VACIO
    if(vectorUbicados[0] == false){
        vectorUFOS[0].setUbicaciones();
        suTablero._Tamanio[vectorUFOS[0].getUbicacionFila()][vectorUFOS[0].getUbicacionColumna()] = vectorUFOS[0].getTamanio();
        vectorUbicados[0] = true;
    }

    //A PARTIR DE ACÁ, SE HACEN VALIDACIONES PARA IDENTIFICAR SI LAS COORDENADAS ELEGIDAS POR EL RAND ESTÁN OCUPADAS
    if(vectorUbicados[1] == false){
        vectorUFOS[1].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[1].getUbicacionFila()][vectorUFOS[1].getUbicacionColumna()] == 1){
            vectorUFOS[1].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[1].getUbicacionFila()][vectorUFOS[1].getUbicacionColumna()] = vectorUFOS[1].getTamanio();
        vectorUbicados[1] = true;
    }

    if(vectorUbicados[2] == false){
        vectorUFOS[2].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[2].getUbicacionFila()][vectorUFOS[2].getUbicacionColumna()] == 1){
            vectorUFOS[2].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[2].getUbicacionFila()][vectorUFOS[2].getUbicacionColumna()] = vectorUFOS[2].getTamanio();
        vectorUbicados[2] = true;
    }

    if(vectorUbicados[3] == false){
        vectorUFOS[3].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[3].getUbicacionFila()][vectorUFOS[3].getUbicacionColumna()] == 1){
            vectorUFOS[3].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[3].getUbicacionFila()][vectorUFOS[3].getUbicacionColumna()] = vectorUFOS[3].getTamanio();
        vectorUbicados[3] = true;
    }

    if(vectorUbicados[4] == false){
        vectorUFOS[4].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[4].getUbicacionFila()][vectorUFOS[4].getUbicacionColumna()] == 1){
            vectorUFOS[4].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[4].getUbicacionFila()][vectorUFOS[4].getUbicacionColumna()] = vectorUFOS[4].getTamanio();
        vectorUbicados[4] = true;
    }

    if(vectorUbicados[0] == true && vectorUbicados[1] == true && vectorUbicados[2] == true && vectorUbicados[3] == true && vectorUbicados[4] == true)
        enemigosUbicados = true;
    }

suTablero.mostrarTablero(suTablero);

if(enemigosUbicados == true){
    return true;
}else{return false;}

}

bool Tablero::completarTableroEnemigoNivel2(Tablero &suTablero){
UFO vectorUFOS[7];
bool enemigosUbicados = false, vectorUbicados[7]={false};
int x;



while(enemigosUbicados == false){

    //EL PRIMER ENEMIGO NO TIENE VALIDACION PORQUE EL TABLERO ESTA VACIO
    if(vectorUbicados[0] == false){
        vectorUFOS[0].setUbicaciones();
        suTablero._Tamanio[vectorUFOS[0].getUbicacionFila()][vectorUFOS[0].getUbicacionColumna()] = vectorUFOS[0].getTamanio();
        vectorUbicados[0] = true;
    }

    //A PARTIR DE ACÁ, SE HACEN VALIDACIONES PARA IDENTIFICAR SI LAS COORDENADAS ELEGIDAS POR EL RAND ESTÁN OCUPADAS
    if(vectorUbicados[1] == false){
        vectorUFOS[1].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[1].getUbicacionFila()][vectorUFOS[1].getUbicacionColumna()] == 1){
            vectorUFOS[1].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[1].getUbicacionFila()][vectorUFOS[1].getUbicacionColumna()] = vectorUFOS[1].getTamanio();
        vectorUbicados[1] = true;
    }

    if(vectorUbicados[2] == false){
        vectorUFOS[2].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[2].getUbicacionFila()][vectorUFOS[2].getUbicacionColumna()] == 1){
            vectorUFOS[2].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[2].getUbicacionFila()][vectorUFOS[2].getUbicacionColumna()] = vectorUFOS[2].getTamanio();
        vectorUbicados[2] = true;
    }

    if(vectorUbicados[3] == false){
        vectorUFOS[3].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[3].getUbicacionFila()][vectorUFOS[3].getUbicacionColumna()] == 1){
            vectorUFOS[3].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[3].getUbicacionFila()][vectorUFOS[3].getUbicacionColumna()] = vectorUFOS[3].getTamanio();
        vectorUbicados[3] = true;
    }

    if(vectorUbicados[4] == false){
        vectorUFOS[4].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[4].getUbicacionFila()][vectorUFOS[4].getUbicacionColumna()] == 1){
            vectorUFOS[4].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[4].getUbicacionFila()][vectorUFOS[4].getUbicacionColumna()] = vectorUFOS[4].getTamanio();
        vectorUbicados[4] = true;
    }

    if(vectorUbicados[5] == false){
        vectorUFOS[5].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[5].getUbicacionFila()][vectorUFOS[5].getUbicacionColumna()] == 1){
            vectorUFOS[5].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[5].getUbicacionFila()][vectorUFOS[5].getUbicacionColumna()] = vectorUFOS[5].getTamanio();
        vectorUbicados[5] = true;
    }

    if(vectorUbicados[6] == false){
        vectorUFOS[6].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[6].getUbicacionFila()][vectorUFOS[6].getUbicacionColumna()] == 1){
            vectorUFOS[6].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[6].getUbicacionFila()][vectorUFOS[6].getUbicacionColumna()] = vectorUFOS[6].getTamanio();
        vectorUbicados[6] = true;
    }

    if(vectorUbicados[0] == true && vectorUbicados[1] == true && vectorUbicados[2] == true && vectorUbicados[3] == true && vectorUbicados[4] == true && vectorUbicados[5] == true && vectorUbicados[6] == true)
        enemigosUbicados = true;
    }

    if(enemigosUbicados == true){
    return true;
}else{return false;}

}

bool Tablero::completarTableroEnemigoNivel3(Tablero &suTablero){
UFO vectorUFOS[10];
bool enemigosUbicados = false, vectorUbicados[10]={false};
int x;



while(enemigosUbicados == false){

    //EL PRIMER ENEMIGO NO TIENE VALIDACION PORQUE EL TABLERO ESTA VACIO
    if(vectorUbicados[0] == false){
        vectorUFOS[0].setUbicaciones();
        suTablero._Tamanio[vectorUFOS[0].getUbicacionFila()][vectorUFOS[0].getUbicacionColumna()] = vectorUFOS[0].getTamanio();
        vectorUbicados[0] = true;
    }

    //A PARTIR DE ACÁ, SE HACEN VALIDACIONES PARA IDENTIFICAR SI LAS COORDENADAS ELEGIDAS POR EL RAND ESTÁN OCUPADAS
    if(vectorUbicados[1] == false){
        vectorUFOS[1].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[1].getUbicacionFila()][vectorUFOS[1].getUbicacionColumna()] == 1){
            vectorUFOS[1].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[1].getUbicacionFila()][vectorUFOS[1].getUbicacionColumna()] = vectorUFOS[1].getTamanio();
        vectorUbicados[1] = true;
    }

    if(vectorUbicados[2] == false){
        vectorUFOS[2].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[2].getUbicacionFila()][vectorUFOS[2].getUbicacionColumna()] == 1){
            vectorUFOS[2].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[2].getUbicacionFila()][vectorUFOS[2].getUbicacionColumna()] = vectorUFOS[2].getTamanio();
        vectorUbicados[2] = true;
    }

    if(vectorUbicados[3] == false){
        vectorUFOS[3].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[3].getUbicacionFila()][vectorUFOS[3].getUbicacionColumna()] == 1){
            vectorUFOS[3].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[3].getUbicacionFila()][vectorUFOS[3].getUbicacionColumna()] = vectorUFOS[3].getTamanio();
        vectorUbicados[3] = true;
    }

    if(vectorUbicados[4] == false){
        vectorUFOS[4].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[4].getUbicacionFila()][vectorUFOS[4].getUbicacionColumna()] == 1){
            vectorUFOS[4].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[4].getUbicacionFila()][vectorUFOS[4].getUbicacionColumna()] = vectorUFOS[4].getTamanio();
        vectorUbicados[4] = true;
    }

    if(vectorUbicados[5] == false){
        vectorUFOS[5].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[5].getUbicacionFila()][vectorUFOS[5].getUbicacionColumna()] == 1){
            vectorUFOS[5].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[5].getUbicacionFila()][vectorUFOS[5].getUbicacionColumna()] = vectorUFOS[5].getTamanio();
        vectorUbicados[5] = true;
    }

    if(vectorUbicados[6] == false){
        vectorUFOS[6].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[6].getUbicacionFila()][vectorUFOS[6].getUbicacionColumna()] == 1){
            vectorUFOS[6].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[6].getUbicacionFila()][vectorUFOS[6].getUbicacionColumna()] = vectorUFOS[6].getTamanio();
        vectorUbicados[6] = true;
    }

    if(vectorUbicados[7] == false){
        vectorUFOS[7].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[7].getUbicacionFila()][vectorUFOS[7].getUbicacionColumna()] == 1){
            vectorUFOS[7].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[7].getUbicacionFila()][vectorUFOS[7].getUbicacionColumna()] = vectorUFOS[7].getTamanio();
        vectorUbicados[7] = true;
        }

        if(vectorUbicados[8] == false){
        vectorUFOS[8].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[8].getUbicacionFila()][vectorUFOS[8].getUbicacionColumna()] == 1){
            vectorUFOS[8].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[8].getUbicacionFila()][vectorUFOS[8].getUbicacionColumna()] = vectorUFOS[8].getTamanio();
        vectorUbicados[8] = true;
        }

        if(vectorUbicados[9] == false){
        vectorUFOS[9].setUbicaciones();
        while(suTablero._Tamanio[vectorUFOS[9].getUbicacionFila()][vectorUFOS[9].getUbicacionColumna()] == 1){
            vectorUFOS[9].setUbicaciones();
        }
        suTablero._Tamanio[vectorUFOS[9].getUbicacionFila()][vectorUFOS[9].getUbicacionColumna()] = vectorUFOS[9].getTamanio();
        vectorUbicados[9] = true;
    }


    if(vectorUbicados[0] == true && vectorUbicados[1] == true && vectorUbicados[2] == true && vectorUbicados[3] == true && vectorUbicados[4] == true && vectorUbicados[5] == true && vectorUbicados[6] == true && vectorUbicados[7] == true && vectorUbicados[8] == true && vectorUbicados[9] == true)
        enemigosUbicados = true;
    }

    if(enemigosUbicados == true){
    return true;
}else{return false;}

}

void Tablero::reiniciarTablero(){
int x,y;

for(x=0;x<10;x++){
    for(y=0;y<10;y++){
        _Tamanio[x][y] = 0;
    }
}

}

void Tablero::completarTableroNivelGhost(Tablero &suTablero){
Ghost ghost;

suTablero.reiniciarTablero();

ghost.teletransportarse();
while(ghost.getUbicacionColumna() > 10 || ghost.getUbicacionColumna() < 1 || ghost.getUbicacionFila() < 1 || ghost.getUbicacionFila() > 10){
    ghost.teletransportarse();
}

suTablero._Tamanio[ghost.getUbicacionFila()][ghost.getUbicacionColumna()] = ghost.getTamanio();

}

void Tablero::completarTableroNivelNautilus(Tablero &tableroNautilus){
Nautilus nautilus;
bool nautilusUbicado = false;
int direccionNautilus;

nautilus.setDireccion();
direccionNautilus = nautilus.getDireccion();


while(nautilusUbicado == false){
    nautilus.setUbicaciones();
    if(nautilus.getUbicacionFila() >= 7 && direccionNautilus == 1){
        nautilus.setUbicaciones();
    }

    if(nautilus.getUbicacionColumna() >= 7 && direccionNautilus == 2){
        nautilus.setUbicaciones();
    }

    if(nautilus.getUbicacionFila() <= 6 && direccionNautilus == 1){
        tableroNautilus._Tamanio[nautilus.getUbicacionFila()][nautilus.getUbicacionColumna()] = nautilus.getTamanio();
        tableroNautilus._Tamanio[nautilus.getUbicacionFila()+1][nautilus.getUbicacionColumna()] = nautilus.getTamanio();
        tableroNautilus._Tamanio[nautilus.getUbicacionFila()+2][nautilus.getUbicacionColumna()] = nautilus.getTamanio();
        tableroNautilus._Tamanio[nautilus.getUbicacionFila()+3][nautilus.getUbicacionColumna()] = nautilus.getTamanio();
        nautilusUbicado = true;
    }

    if(nautilus.getUbicacionColumna() <= 6 && direccionNautilus == 2){
        tableroNautilus._Tamanio[nautilus.getUbicacionFila()][nautilus.getUbicacionColumna()] = nautilus.getTamanio();
        tableroNautilus._Tamanio[nautilus.getUbicacionFila()][nautilus.getUbicacionColumna()+1] = nautilus.getTamanio();
        tableroNautilus._Tamanio[nautilus.getUbicacionFila()][nautilus.getUbicacionColumna()+2] = nautilus.getTamanio();
        tableroNautilus._Tamanio[nautilus.getUbicacionFila()][nautilus.getUbicacionColumna()+3] = nautilus.getTamanio();
        nautilusUbicado = true;
        }
    }
}


void Tablero::completarTableroNivelNagronar(Tablero &tableroFinal){
Nagronar nagronar;
bool nagronarUbicado = false;
int direccionNagronar, fila, columna;

nagronar.setDireccion();
direccionNagronar = nagronar.getDireccion();


while(nagronarUbicado == false){
    nagronar.setUbicaciones();
    if(nagronar.getUbicacionFila() >= 5 && direccionNagronar == 1){
        nagronar.setUbicaciones();
    }

    if(nagronar.getUbicacionColumna() >= 5 && direccionNagronar == 2){
        nagronar.setUbicaciones();
    }

    if(nagronar.getUbicacionFila() <= 4 && direccionNagronar == 1){
        tableroFinal._Tamanio[nagronar.getUbicacionFila()][nagronar.getUbicacionColumna()] = nagronar.getTamanio();
        tableroFinal._Tamanio[nagronar.getUbicacionFila()+1][nagronar.getUbicacionColumna()] = nagronar.getTamanio();
        tableroFinal._Tamanio[nagronar.getUbicacionFila()+2][nagronar.getUbicacionColumna()] = nagronar.getTamanio();
        tableroFinal._Tamanio[nagronar.getUbicacionFila()+3][nagronar.getUbicacionColumna()] = nagronar.getTamanio();
        tableroFinal._Tamanio[nagronar.getUbicacionFila()+4][nagronar.getUbicacionColumna()] = nagronar.getTamanio();
        tableroFinal._Tamanio[nagronar.getUbicacionFila()+5][nagronar.getUbicacionColumna()] = nagronar.getTamanio();
        nagronarUbicado = true;
    }

    if(nagronar.getUbicacionColumna() <= 4 && direccionNagronar == 2){
        tableroFinal._Tamanio[nagronar.getUbicacionFila()][nagronar.getUbicacionColumna()] = nagronar.getTamanio();
        tableroFinal._Tamanio[nagronar.getUbicacionFila()][nagronar.getUbicacionColumna()+1] = nagronar.getTamanio();
        tableroFinal._Tamanio[nagronar.getUbicacionFila()][nagronar.getUbicacionColumna()+2] = nagronar.getTamanio();
        tableroFinal._Tamanio[nagronar.getUbicacionFila()][nagronar.getUbicacionColumna()+3] = nagronar.getTamanio();
        tableroFinal._Tamanio[nagronar.getUbicacionFila()][nagronar.getUbicacionColumna()+4] = nagronar.getTamanio();
        tableroFinal._Tamanio[nagronar.getUbicacionFila()][nagronar.getUbicacionColumna()+5] = nagronar.getTamanio();
        nagronarUbicado = true;
    }
}


}

void Tablero::mostrarTablero(Tablero &miTablero){
int x,y;
int fila = 1;
char columna;


cout<<"    1  2  3  4  5  6  7  8  9  10"<<endl;
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

bool Tablero::ubicarDestructor(Destructor &miDestructor, Tablero &miTablero){
int fila = 0,columna = 0, x, y, direccion;
bool destructorUbicado = false, ubicacionValida = false;
int limite;

cout<<"Ubica tu "<<miDestructor.getNombre()<<endl;
system("PAUSE");
system("cls");
mostrarTablero(miTablero);


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
    cin>>fila;
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
        cout<<endl;
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
            cout<<endl;
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
            while(_Tamanio[fila-1][columna-1] != 0 || _Tamanio[fila][columna-1] != 0){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            cout<<"Fila: ";
            cin>>fila;
            cout<<"Columna: ";
            cin>>columna;}
            }else{
                miTablero._Tamanio[fila-1][columna-1] = 1;
                miTablero._Tamanio[fila][columna-1] = 1;
                cout<<"Destructor ubicado";
                cout<<endl;
                system("cls");
                destructorUbicado = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[fila-1][columna-1] == 1 || _Tamanio[fila-1][columna] == 1){
            while(_Tamanio[fila-1][columna-1] != 0 || _Tamanio[fila-1][columna] != 0){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            cout<<"Fila: ";
            cin>>fila;
            cout<<"Columna: ";
            cin>>columna;}
            }else{
                miTablero._Tamanio[fila-1][columna-1] = 1;
                miTablero._Tamanio[fila-1][columna] = 1;
                cout<<"Destructor ubicado"<<endl;
                cout<<endl;
                system("cls");
                destructorUbicado = true;
            }
        }
    }


if(destructorUbicado == true){
    miDestructor.TransformarCoordenadas(fila,columna,direccion,miDestructor._sprite);
    return true;}else{return false;}
}

bool Tablero::ubicarAcorazado(Acorazado &miAcorazado, Tablero &miTablero){
int fila = 0,columna = 0, x, y, direccion;
bool acorazadoUbicado = false;

cout<<"Ubica tu "<<miAcorazado.getNombre()<<endl;
system("PAUSE");
system("cls");
mostrarTablero(miTablero);

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
    cin>>fila;
    cout<<"Columna: ";
    cin>>columna;

    if(fila > 8 && direccion == 1){
        cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
        while(fila > 8){
            cout<<"Fila: ";
            cin>>fila;
            cout<<"Columna: ";
            cin>>columna;
        }
    }

    if(columna > 8 && direccion == 2){
        while(columna > 8){
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
        if(_Tamanio[fila-1][columna-1] == 1 || _Tamanio[fila][columna-1] == 1 || _Tamanio[fila+1][columna-1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[fila-1][columna-1] = 1;
                _Tamanio[fila][columna-1] = 1;
                _Tamanio[fila+1][columna-1] = 1;
                cout<<"Acorazado ubicado";
                cout<<endl;
                system("cls");
                acorazadoUbicado = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[fila-1][columna-1] == 1 || _Tamanio[fila-1][columna] == 1 || _Tamanio[fila-1][columna+1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[fila-1][columna-1] = 1;
                _Tamanio[fila-1][columna] = 1;
                _Tamanio[fila-1][columna+1] = 1;
                cout<<"Acorazado ubicado"<<endl;
                cout<<endl;
                system("cls");
                acorazadoUbicado = true;
            }
        }
    }
    if(acorazadoUbicado == true){
        miAcorazado.TransformarCoordenadas(fila,columna,direccion,miAcorazado._sprite);
                return true;
}else{return false;
}


}

bool Tablero::ubicarFragata(Fragata &miFragata, Tablero &miTablero){
int fila = 0,columna = 0, x, y, direccion;
bool fragataUbicada = false;

cout<<"Ubica tu "<<miFragata.getNombre()<<endl;
system("PAUSE");
system("cls");
mostrarTablero(miTablero);

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
    cin>>fila;
    cout<<"Columna: ";
    cin>>columna;

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
        if(_Tamanio[fila-1][columna-1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[fila-1][columna-1] = 1;
                cout<<"Fragata ubicada";
                cout<<endl;
                system("cls");
                fragataUbicada = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[fila-1][columna-1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[fila-1][columna-1] = 1;
                cout<<"Fragata ubicada"<<endl;
                cout<<endl;
                system("cls");
                fragataUbicada = true;
                }
            }
        }
        if(fragataUbicada == true){
        miFragata.TransformarCoordenadas(fila,columna,direccion,miFragata._sprite);
                return true;
    }else{return false;
    }
}

bool Tablero::ubicarSubmarino(Submarino &miSubmarino, Tablero &miTablero){
int fila = 0,columna = 0, x, y, direccion;
bool submarinoUbicado = false;

cout<<"Ubica tu "<<miSubmarino.getNombre()<<endl;
system("PAUSE");
system("cls");
mostrarTablero(miTablero);

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
    cin>>fila;
    cout<<"Columna: ";
    cin>>columna;

    if(fila > 8 && direccion == 1){
        cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
        while(fila > 8){
            cout<<"Fila: ";
            cin>>fila;
            cout<<"Columna: ";
            cin>>columna;
        }
    }

    if(columna > 8 && direccion == 2){
        while(columna > 8){
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
        if(_Tamanio[fila-1][columna-1] == 1 || _Tamanio[fila][columna-1] == 1 || _Tamanio[fila+1][columna-1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[fila-1][columna-1] = 1;
                _Tamanio[fila][columna-1] = 1;
                _Tamanio[fila+1][columna-1] = 1;
                cout<<"Submarino ubicado";
                cout<<endl;
                system("cls");
                submarinoUbicado = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[fila-1][columna-1] == 1 || _Tamanio[fila-1][columna] == 1 || _Tamanio[fila-1][columna+1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[fila-1][columna-1] = 1;
                _Tamanio[fila-1][columna] = 1;
                _Tamanio[fila-1][columna+1] = 1;
                cout<<"Submarino ubicado"<<endl;
                cout<<endl;
                system("cls");
                submarinoUbicado = true;
            }
        }
    }

    if(submarinoUbicado == true){
        miSubmarino.TransformarCoordenadas(fila,columna,direccion,miSubmarino._sprite);
                return true;
}else{return false;
    }
}

bool Tablero::ubicarPortaaviones (Portaaviones &miPortaaviones, Tablero &miTablero){
int fila = 0,columna = 0, x, y, direccion;
bool portaavionesUbicado = false;

cout<<"Ubica tu "<<miPortaaviones.getNombre()<<endl;
system("PAUSE");
system("cls");
mostrarTablero(miTablero);

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
    cin>>fila;
    cout<<"Columna: ";
    cin>>columna;

    if(fila > 7 && direccion == 1){
        cout<<"Supera el limite del tablero. Ingrese nuevas coordenadas"<<endl;
        while(fila > 7){
            cout<<"Fila: ";
            cin>>fila;
            cout<<"Columna: ";
            cin>>columna;
        }
    }

    if(columna > 7 && direccion == 2){
        while(columna > 7){
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
        if(_Tamanio[fila-1][columna-1] == 1 || _Tamanio[fila][columna-1] == 1 || _Tamanio[fila+1][columna-1] == 1 || _Tamanio[fila+2][columna-1] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[fila-1][columna-1] = 1;
                _Tamanio[fila][columna-1] = 1;
                _Tamanio[fila+1][columna-1] = 1;
                _Tamanio[fila+2][columna-1] = 1;
                cout<<"Portaaviones ubicado";
                cout<<endl;
                system("cls");
                portaavionesUbicado = true;
            }
        }
    if(direccion == 2){
        if(_Tamanio[fila-1][columna-1] == 1 || _Tamanio[fila-1][columna] == 1 || _Tamanio[fila-1][columna+1] == 1 || _Tamanio [fila-1][columna+2] == 1){
            cout<<"Se detecto una embarcacion en ese lugar. Elija otro"<<endl;
            }else{
                _Tamanio[fila-1][columna-1] = 1;
                _Tamanio[fila-1][columna] = 1;
                _Tamanio[fila-1][columna+1] = 1;
                _Tamanio[fila-1][columna+2] = 1;
                cout<<"Portaaviones ubicado"<<endl;
                cout<<endl;
                system("cls");
                portaavionesUbicado = true;
            }
        }
    }
    if(portaavionesUbicado == true){
        miPortaaviones.TransformarCoordenadas(fila,columna,direccion,miPortaaviones._sprite);
                return true;
        }else{return false;
    }
}

bool Tablero::atacar(int fila,int columna, Tablero &suTablero){
int correccionFila = 0, correccionColumna = 0;

    if(fila < 1 || fila > 10){
        cout<<"No existe esa fila. Ingrese una valida: ";
        while(correccionFila < 1 || correccionFila > 10){
            cin>>correccionFila;
        }
    fila = correccionFila;
    }

    if(columna < 1 || columna > 10){
        cout<<"No existe esa columna. Ingrese una valida: ";
        while(correccionColumna < 1 || correccionColumna > 10){
            cin>>correccionColumna;
        }
    columna = correccionColumna;
    }

if(suTablero._Tamanio[fila-1][columna-1] != 0){
    cout<<"Enemigo detectado"<<endl;
    suTablero._Tamanio[fila-1][columna-1] = 0;
    return true;
    }else if(suTablero._Tamanio[fila-1][columna-1] == 0){
    cout<<"No se detectaron enemigos"<<endl;
    return false;
    }
}

bool Tablero::atacaIA(Tablero &miTablero, sf::RenderWindow &_Ventana){
srand(time(NULL));
int fila,columna;
fila = rand()%10+1;
columna = rand()%10+1;

cout<<"El enemigo ataco: fila "<<fila<<" columna "<<columna<<endl;

if(miTablero._Tamanio[fila-1][columna-1] != 0){
    cout<<"El enemigo detecto una embarcacion nuestra"<<endl;
    miTablero._Tamanio[fila-1][columna-1] = 0;
    return true;
    }else if(miTablero._Tamanio[fila-1][columna-1] == 0){
    cout<<"El enemigo fallo su disparo"<<endl;
    return false;
    }


}

bool Tablero::evaluarTablero(Tablero &miTablero){
int x,y;
bool tableroVacio = true;

for(x=0;x<10;x++){
    for(y=0;y<10;y++){
        if(miTablero._Tamanio[x][y] != 0){
            tableroVacio = false;
            return false;
        }
    }
}

if(tableroVacio == true){
    cout<<"No quedan embarcaciones en el tablero"<<endl;
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
bool ataqueExitoso = false;

if(supremacia == false || supremacia == true && filaSupremacia != fila){
    for(x=0;x<10;x++){
    if(_Tamanio[fila][x] != 0){
        ataqueExitoso = true;
    }
    _Tamanio[fila][x] = 0;}
    }else if(supremacia == true && filaSupremacia == fila){
        cout<<"La supremacia aerea otorgada por el caza evito el ataque"<<endl;
    }

    if(ataqueExitoso == true){
        cout<<"Se logro bombardear una unidad rival"<<endl;
    }else{
    cout<<"El ataque del bombardero no tuvo exito"<<endl;}

}

void Tablero::getAtaqueBombarderoIA(int fila, bool &supremacia, int &filaSupremacia){
int x;
bool ataqueExitoso = false;

if(supremacia == false || supremacia == true && filaSupremacia != fila){
    for(x=0;x<10;x++){
    if(_Tamanio[fila-1][x] != 0){
        ataqueExitoso = true;
    }
    _Tamanio[fila-1][x] = 0;}
    }else if(supremacia == true && filaSupremacia == fila){
        cout<<"La supremacia aerea otorgada por el caza evito el ataque"<<endl;
    }

    if(ataqueExitoso == true){
        cout<<"El rival bombardeo la fila "<<fila<<" y su impacto llego a nuestras unidades"<<endl;
    }else{cout<<"El ataque del bombardero rival no tuvo exito. El rival bombardeo la fila "<<fila<<endl;}
}

void Tablero::getAtaqueDron(int fila, int columna, bool &supremacia, int &filaSupremacia){
bool ataqueExitoso = false;

    if(supremacia == false || supremacia == true && filaSupremacia != fila){
        if(_Tamanio[fila-1][columna-1] != 0){
        ataqueExitoso = true;
        cout<<"Ataque de Dron exitoso en la fila "<<fila<<"columna "<<columna<<endl;
        }
        _Tamanio[fila-1][columna-1] = 0;
    }

    if(ataqueExitoso == true){
        cout<<"Ataque de dron exitoso"<<endl;
    }else{
        cout<<"Fallo el ataque del dron"<<endl;
        cout<<"Se ataco la fila "<<fila<<" columna "<<columna<<endl;
    }
}

void Tablero::getAtaqueDronIA(int fila, int columna, bool &supremacia, int &filaSupremacia){
bool ataqueExitoso = false;

    if(supremacia == false || supremacia == true && filaSupremacia != fila){
        if(_Tamanio[fila-1][columna-1] != 0){
        ataqueExitoso = true;
        }
        _Tamanio[fila-1][columna-1] = 0;
    }

    if(ataqueExitoso == true){
        cout<<"Ataque de dron rival exitoso"<<endl;
    }else{
        cout<<"Fallo el ataque del dron del rival"<<endl;
    }

}


void Tablero::getReconocimiento(int recon, Tablero &tablero){
int x;

for(x=0;x<10;x++){
    if(tablero._Tamanio[recon][x] != 0){
        cout<<"Deteccion afirmativa en fila "<<recon+1<<" columna "<<x+1<<endl;
            }
    }
}

void Tablero::getReconocimientoIA(int recon, Tablero &tablero){
int x;

for(x=0;x<10;x++){
    if(tablero._Tamanio[recon][x] != 0){
        tablero._Tamanio[recon][x] = 0;
        cout<<"El rival a detectado y eliminado nuestra unidad en la fila "<<recon<<" columna "<<x+1<<endl;
        return;
        }
    }
}

void Tablero::completarTableroNivelKloster(Tablero &suTablero){
Klosternator klosternator;
bool klosternatorUbicado = false;
int direccionKlosternator, fila, columna;
int x;

direccionKlosternator = rand()%2+1;
cout<<"DIRECCION KLOSTER: "<<direccionKlosternator<<endl;
fila = rand()%10;
cout<<"FILA KLOSTER: "<<fila+1<<endl;
columna = rand()%10+1;
cout<<"COLUMNA KLOSTER: "<<columna<<endl;

    if(direccionKlosternator == 1){

        for(x=0;x<10;x++){
            suTablero._Tamanio[fila][x] = klosternator.getTamanio();
        }

        }else if(direccionKlosternator == 2){

            for(x=0;x<10;x++){
                suTablero._Tamanio[x][columna] = klosternator.getTamanio();
            }
    }
}

void Tablero::getAtaqueKloster(Tablero &miTablero){
int decideKloster, x;

decideKloster = rand()%10+1;
cout<<"Klosternator ha decidido penalizarte por no entender"<<endl;
cout<<"Ataque en: "<<decideKloster<<endl;
    for(x=0;x<10;x++){
        miTablero._Tamanio[decideKloster-1][x] = 0;
        miTablero._Tamanio[x][decideKloster-1] = 0;
    }


}


void Tablero::completarTableroModoClasico(Tablero &miTablero){

            int inicio,fin,tam,casillasLibres,resultado,posicion;
            bool bandera=false, ubicacion=false, cumpla=false,b=false,aviso=true;
            bool destructorUbicado=false, fragataUbicada=false, submarinoUbicado=false, portaavionesUbicado=false, acorazadoUbicado=false;
            for(int j=0;j<5;j++){ // REPRESENTA LA CANTIDAD DE BARCOS A CARGAR EN ESTE CASO 5. PERO SO PODRIA MODIFICAR SEGUN CANTIDAD DE EMBARCACION
            ubicacion=false;

                miTablero.mostrarTableroHumanoCarga(miTablero);

                while(!ubicacion){
                    cout<<endl;
                    cout<< " ELIJA POSICION DEL BARCO: "<<endl;
                    cout<<" 1 - Horizontal : "<<endl;
                    cout<<" 2 - Vertical : "<<endl;
                    cin>>posicion;
                    cout<<endl;
                    system("cls");
                    if(posicion==1){

                         tam = seleccionarBarco(destructorUbicado, fragataUbicada, submarinoUbicado,portaavionesUbicado,acorazadoUbicado);
                        miTablero.mostrarTableroHumanoCarga(miTablero);
                        cumpla=false;

                        while(!cumpla){
                            b=false;
                            while(b==false){
                            cout<<" Fila: ";
                            cin>>inicio;
                            cout<<" Columna: ";
                            cin>>fin;
                            cout<<endl;
                            if(inicio>0&&inicio<11 && fin>0&&fin<11){
                                b=true;
                            }
                              else{
                                 cout<<endl;
                                 cout<<" ERROR DE COORDENADAS"<<endl;
                                 system("pause");
                                 system("cls");
                              }
                            }

                            // ANALIZO POSIBLE ERROR DE UBICACION
                            casillasLibres  = 1 + (10 - fin);
                            resultado = casillasLibres - tam;
                            if( resultado < 0){
                                cout<<endl;
                                cout<< " EMBARCACION FUERA DE LIMITES "<<endl;
                                cumpla=false;
                                system("pause");
                                system("cls");
                            }
                             else{

                                for( int x=0; x<tam; x++){
                                    if(miTablero._Tamanio[inicio-1][fin-1]==0){
                                        miTablero._Tamanio[inicio-1][fin-1]=1;
                                        fin++; // if(posicion==1){fin++}else{inicio++}
                                        cumpla=true;
                                    }
                                     else{
                                         cout<<endl;
                                         cout<< " NO DISPONIBLE !! ENCONTRAMOS UN BARCO EN ESA RUTA !! ELIJA NUEVA UBICACION ... "<<endl;
                                         if(x==0){
                                             cumpla=false;
                                             x=tam;
                                         }
                                           else{
                                         for( int v=0 ; v<x ; v++){
                                             fin--;
                                             miTablero._Tamanio[inicio-1][fin-1]=0;
                                             cumpla=false;
                                         }
                                          x=tam;
                                         }
                                         system("pause");

                                     }


                                }
                                ubicacion = true;
                                system("cls");
                            }


                        }// while cumpla

                        cout<<endl;

                    }

                    else if(posicion==2){

                        tam = seleccionarBarco(destructorUbicado, fragataUbicada, submarinoUbicado,portaavionesUbicado,acorazadoUbicado);
                        miTablero.mostrarTableroHumanoCarga(miTablero);
                        cumpla=false;

                        while(!cumpla){
                            b=false;
                            while(b==false){
                            cout<<" Fila: ";
                            cin>>inicio;
                            cout<< " Columna: ";
                            cin>>fin;
                            cout<<endl;
                            if(inicio>0&&inicio<11 && fin>0&&fin<11){
                                b=true;
                            }
                              else{
                                 cout<<endl;
                                 cout<<" ERROR DE COORDENADAS"<<endl;
                                 system("pause");
                                 system("cls");
                              }
                            }

                            // ANALIZO POSIBLE ERROR DE UBICACION
                            casillasLibres  = 1 + (10 - inicio);
                            resultado = casillasLibres - tam;
                            if( resultado < 0){
                                cout<< " EMBARCACION FUERA DE LIMITES "<<endl;
                                cumpla=false;
                                system("pause");
                                system("cls");
                            }
                             else{

                                for( int x=0; x<tam; x++){
                                    if(miTablero._Tamanio[inicio-1][fin-1]==0){
                                        miTablero._Tamanio[inicio-1][fin-1]=1;
                                        inicio++; // if(posicion==1){fin++}else{inicio++}
                                        cumpla=true;
                                    }
                                     else{
                                         cout<< " NO DISPONIBLE !! ENCONTRAMOS UN BARCO EN ESA RUTA !! ELIJA NUEVA UBICACION ... "<<endl;
                                         if(x==0){
                                             cumpla=false;
                                             x=tam;
                                         }
                                           else{
                                         for( int v=0 ; v<x ; v++){
                                             inicio--;
                                             miTablero._Tamanio[inicio-1][fin-1]=0;
                                             cumpla=false;

                                         }
                                          x=tam;
                                         }
                                          system("pause");

                                    }
                                }
                                ubicacion = true;
                                system("cls");
                            }


                        }// while cumpla

                        cout<<endl;

                    }else {
                        cout<< " ERROR - INGRESE NUEVAMENTE LA POSICION "<<endl;
                    }

               }// while de limites

            } // LLAVE FOR DE CANTIDAD DE BARCOS

}

void Tablero::mostrarTableroModoClasico(Tablero &miTablero, Tablero &aux){
cout<<endl;
            cout<<"   ";
            for(int x=0;x<10;x++){
                cout<<" "<<x+1;
            }
             cout<<"        ";
            for(int x=0;x<10;x++){
                cout<<" "<<x+1;
            }
            cout<<endl;
            cout<<"    ________"<<endl;
            for(int x=0;x<10;x++){
                    if(x<9){
                    cout<<x+1<<" )";
                    }else{
                    cout<<x+1<<")";
                    }
                for(int i=0;i<10;i++){
                    if( miTablero._Tamanio[x][i]==0){
                    //setColor(LIGHTBLUE);
                    cout<<" "<<miTablero._Tamanio[x][i]; // matriz 1
                    //setColor(WHITE);
                    }else{
                    // setColor(LIGHTRED);
                    cout<<" "<<miTablero._Tamanio[x][i];
                    //setColor(WHITE);

                    }
                }
                if(x<9){
                cout<<"      "<<x+1<<" )";
                }else{
                    cout<<"      "<<x+1<<")";
                    }
                for(int i=0;i<10;i++){
                    if(aux._Tamanio[x][i]==0){
                    // setColor(LIGHTBLUE);
                    cout<<" "<<aux._Tamanio[x][i];   // matriz 2
                    //setColor(WHITE);
                    }else{
                    // setColor(LIGHTRED);
                     cout<<" "<<aux._Tamanio[x][i];
                     //setColor(WHITE);
                    }
                }
                cout<<endl;
            }

}

void Tablero::mostrarTableroHumanoCarga(Tablero &miTablero){
//setColor(LIGHTBLUE);
            cout<<endl;
            cout<<"   ";
            for(int x=0;x<10;x++){
                cout<<" "<<x+1;
            }
            cout<<endl;
            cout<<"    ________"<<endl;
            for(int x=0;x<10;x++){
                    if(x<9){
                    cout<<x+1<<" )";
                    }else{
                    cout<<x+1<<")";
                    }
                for(int i=0;i<10;i++){

                    cout<<" "<<miTablero._Tamanio[x][i]; // matriz 1
                }


                cout<<endl;
            }

            //setColor(WHITE);

}

bool Tablero::localizacionDisparo(Tablero &aux, int f, int c){

   if( aux._Tamanio[f-1][c-1]==1 ){
    return true;
   }else{return false;}
}

bool Tablero::atacarModoClasico(int fila,int columna, Tablero &miTablero, Tablero &aux){
 if(miTablero._Tamanio[fila-1][columna-1] == 1){
        cout<<endl;
        cout<<"Barco detectado"<<endl<<endl;
        miTablero._Tamanio[fila-1][columna-1] = 0;
        aux._Tamanio[fila-1][columna-1] = 1;
        return true;
        }else if(miTablero._Tamanio[fila-1][columna-1] == 0){
        cout<<endl;
        cout<<"No se detectaron barcos"<<endl<<endl;
        aux._Tamanio[fila-1][columna-1] = 1;
        return false;
        }
}











