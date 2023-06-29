#include <iostream>
#include "Embarcaciones.h"
#include "Tablero.h"
using namespace std;


void Embarcacion::TransformarCoordenadas(int fila, int columna, int direccion, sf::Sprite &sprite){


if(direccion == 1){
switch(fila){
case 1:
    switch(columna){
    case 1: sprite.setPosition(85,15);
    break;

    case 2: sprite.setPosition(113,15);
    break;

    case 3: sprite.setPosition(141,15);
    break;

    case 4: sprite.setPosition(169,15);
    break;

    case 5: sprite.setPosition(197,15);
    break;

    case 6: sprite.setPosition(225,15);
    break;

    case 7: sprite.setPosition(253,15);
    break;

    case 8: sprite.setPosition(281,15);
    break;

    case 9: sprite.setPosition(309,15);
    break;

    case 10: sprite.setPosition(337,15);
    break;
    }
break;
case 2:
    switch(columna){
    case 1: sprite.setPosition(85,43);
    break;

    case 2: sprite.setPosition(113,43);
    break;

    case 3: sprite.setPosition(141,43);
    break;

    case 4: sprite.setPosition(169,43);
    break;

    case 5: sprite.setPosition(197,43);
    break;

    case 6: sprite.setPosition(225,43);
    break;

    case 7: sprite.setPosition(253,43);
    break;

    case 8: sprite.setPosition(281,43);
    break;

    case 9: sprite.setPosition(309,43);
    break;

    case 10: sprite.setPosition(337,43);
    break;
    }
break;
case 3:
   switch(columna){
    case 1: sprite.setPosition(85,71);
    break;

    case 2: sprite.setPosition(113,71);
    break;

    case 3: sprite.setPosition(141,71);
    break;

    case 4: sprite.setPosition(169,71);
    break;

    case 5: sprite.setPosition(197,71);
    break;

    case 6: sprite.setPosition(225,71);
    break;

    case 7: sprite.setPosition(253,71);
    break;

    case 8: sprite.setPosition(281,71);
    break;

    case 9: sprite.setPosition(309,71);
    break;

    case 10: sprite.setPosition(337,71);
    break;
    }
break;

case 4:
    switch(columna){
    case 1: sprite.setPosition(85,99);
    break;

    case 2: sprite.setPosition(113,99);
    break;

    case 3: sprite.setPosition(141,99);
    break;

    case 4: sprite.setPosition(169,99);
    break;

    case 5: sprite.setPosition(197,99);
    break;

    case 6: sprite.setPosition(225,99);
    break;

    case 7: sprite.setPosition(253,99);
    break;

    case 8: sprite.setPosition(281,99);
    break;

    case 9: sprite.setPosition(309,99);
    break;

    case 10: sprite.setPosition(337,99);
    break;
    }
break;

case 5:
    switch(columna){
    case 1: sprite.setPosition(85,127);
    break;

    case 2: sprite.setPosition(113,127);
    break;

    case 3: sprite.setPosition(141,127);
    break;

    case 4: sprite.setPosition(169,127);
    break;

    case 5: sprite.setPosition(197,127);
    break;

    case 6: sprite.setPosition(225,127);
    break;

    case 7: sprite.setPosition(253,127);
    break;

    case 8: sprite.setPosition(281,127);
    break;

    case 9: sprite.setPosition(309,127);
    break;

    case 10: sprite.setPosition(337,127);
    break;
    }
break;

case 6:
     switch(columna){
    case 1: sprite.setPosition(85,155);
    break;

    case 2: sprite.setPosition(113,155);
    break;

    case 3: sprite.setPosition(141,155);
    break;

    case 4: sprite.setPosition(169,155);
    break;

    case 5: sprite.setPosition(197,155);
    break;

    case 6: sprite.setPosition(225,155);
    break;

    case 7: sprite.setPosition(253,155);
    break;

    case 8: sprite.setPosition(281,155);
    break;

    case 9: sprite.setPosition(309,155);
    break;

    case 10: sprite.setPosition(337,155);
    break;
    }
break;

case 7:
     switch(columna){
    case 1: sprite.setPosition(85,183);
    break;

    case 2: sprite.setPosition(113,183);
    break;

    case 3: sprite.setPosition(141,183);
    break;

    case 4: sprite.setPosition(169,183);
    break;

    case 5: sprite.setPosition(197,183);
    break;

    case 6: sprite.setPosition(225,183);
    break;

    case 7: sprite.setPosition(253,183);
    break;

    case 8: sprite.setPosition(281,183);
    break;

    case 9: sprite.setPosition(309,183);
    break;

    case 10: sprite.setPosition(337,183);
    break;
    }
break;
case 8:
      switch(columna){
    case 1: sprite.setPosition(85,211);
    break;

    case 2: sprite.setPosition(113,211);
    break;

    case 3: sprite.setPosition(141,211);
    break;

    case 4: sprite.setPosition(169,211);
    break;

    case 5: sprite.setPosition(197,211);
    break;

    case 6: sprite.setPosition(225,211);
    break;

    case 7: sprite.setPosition(253,211);
    break;

    case 8: sprite.setPosition(281,211);
    break;

    case 9: sprite.setPosition(309,211);
    break;

    case 10: sprite.setPosition(337,211);
    break;
    }
break;

case 9:
     switch(columna){
    case 1: sprite.setPosition(85,239);
    break;

    case 2: sprite.setPosition(113,239);
    break;

    case 3: sprite.setPosition(141,239);
    break;

    case 4: sprite.setPosition(169,239);
    break;

    case 5: sprite.setPosition(197,239);
    break;

    case 6: sprite.setPosition(225,239);
    break;

    case 7: sprite.setPosition(253,239);
    break;

    case 8: sprite.setPosition(281,239);
    break;

    case 9: sprite.setPosition(309,239);
    break;

    case 10: sprite.setPosition(337,239);
    break;
    }
break;

case 10:
     switch(columna){
    case 1: sprite.setPosition(85,267);
    break;

    case 2: sprite.setPosition(113,267);
    break;

    case 3: sprite.setPosition(141,267);
    break;

    case 4: sprite.setPosition(169,267);
    break;

    case 5: sprite.setPosition(197,267);
    break;

    case 6: sprite.setPosition(225,267);
    break;

    case 7: sprite.setPosition(253,267);
    break;

    case 8: sprite.setPosition(281,267);
    break;

    case 9: sprite.setPosition(309,267);
    break;

    case 10: sprite.setPosition(337,267);
    break;
    }
break;
    }
}

if(direccion == 2){
    sprite.setRotation(270);
switch(fila){
case 1:
    switch(columna){
    case 1: sprite.setPosition(80,38);
    break;

    case 2: sprite.setPosition(108,38);
    break;

    case 3: sprite.setPosition(136,38);
    break;

    case 4: sprite.setPosition(164,38);
    break;

    case 5: sprite.setPosition(192,38);
    break;

    case 6: sprite.setPosition(220,38);
    break;

    case 7: sprite.setPosition(248,38);
    break;

    case 8: sprite.setPosition(276,38);
    break;

    case 9: sprite.setPosition(304,38);
    break;

    case 10: sprite.setPosition(332,38);
    break;
    }
break;
case 2:
     switch(columna){
    case 1: sprite.setPosition(80,66);
    break;

    case 2: sprite.setPosition(108,66);
    break;

    case 3: sprite.setPosition(136,66);
    break;

    case 4: sprite.setPosition(164,66);
    break;

    case 5: sprite.setPosition(192,66);
    break;

    case 6: sprite.setPosition(220,66);
    break;

    case 7: sprite.setPosition(248,66);
    break;

    case 8: sprite.setPosition(276,66);
    break;

    case 9: sprite.setPosition(304,66);
    break;

    case 10: sprite.setPosition(332,66);
    break;
    }
break;
case 3:
   switch(columna){
    case 1: sprite.setPosition(80,94);
    break;

    case 2: sprite.setPosition(108,94);
    break;

    case 3: sprite.setPosition(136,94);
    break;

    case 4: sprite.setPosition(164,94);
    break;

    case 5: sprite.setPosition(192,94);
    break;

    case 6: sprite.setPosition(220,94);
    break;

    case 7: sprite.setPosition(248,94);
    break;

    case 8: sprite.setPosition(276,94);
    break;

    case 9: sprite.setPosition(304,94);
    break;

    case 10: sprite.setPosition(332,94);
    break;
    }
break;

case 4:
    switch(columna){
    case 1: sprite.setPosition(80,122);
    break;

    case 2: sprite.setPosition(108,122);
    break;

    case 3: sprite.setPosition(136,122);
    break;

    case 4: sprite.setPosition(164,122);
    break;

    case 5: sprite.setPosition(192,122);
    break;

    case 6: sprite.setPosition(220,122);
    break;

    case 7: sprite.setPosition(248,122);
    break;

    case 8: sprite.setPosition(276,122);
    break;

    case 9: sprite.setPosition(304,122);
    break;

    case 10: sprite.setPosition(332,122);
    break;
    }
break;

case 5:
    switch(columna){
    case 1: sprite.setPosition(80,150);
    break;

    case 2: sprite.setPosition(108,150);
    break;

    case 3: sprite.setPosition(136,150);
    break;

    case 4: sprite.setPosition(164,150);
    break;

    case 5: sprite.setPosition(192,150);
    break;

    case 6: sprite.setPosition(220,150);
    break;

    case 7: sprite.setPosition(248,150);
    break;

    case 8: sprite.setPosition(276,150);
    break;

    case 9: sprite.setPosition(304,150);
    break;

    case 10: sprite.setPosition(332,150);
    break;
    }
break;

case 6:
     switch(columna){
    case 1: sprite.setPosition(80,178);
    break;

    case 2: sprite.setPosition(108,178);
    break;

    case 3: sprite.setPosition(136,178);
    break;

    case 4: sprite.setPosition(164,178);
    break;

    case 5: sprite.setPosition(192,178);
    break;

    case 6: sprite.setPosition(220,178);
    break;

    case 7: sprite.setPosition(248,178);
    break;

    case 8: sprite.setPosition(276,178);
    break;

    case 9: sprite.setPosition(304,178);
    break;

    case 10: sprite.setPosition(332,178);
    break;
    }
break;

case 7:
     switch(columna){
    case 1: sprite.setPosition(80,206);
    break;

    case 2: sprite.setPosition(108,206);
    break;

    case 3: sprite.setPosition(136,206);
    break;

    case 4: sprite.setPosition(164,206);
    break;

    case 5: sprite.setPosition(192,206);
    break;

    case 6: sprite.setPosition(220,206);
    break;

    case 7: sprite.setPosition(248,206);
    break;

    case 8: sprite.setPosition(276,206);
    break;

    case 9: sprite.setPosition(304,206);
    break;

    case 10: sprite.setPosition(332,206);
    break;
    }
break;
case 8:
    switch(columna){
    case 1: sprite.setPosition(80,234);
    break;

    case 2: sprite.setPosition(108,234);
    break;

    case 3: sprite.setPosition(136,234);
    break;

    case 4: sprite.setPosition(164,234);
    break;

    case 5: sprite.setPosition(192,234);
    break;

    case 6: sprite.setPosition(220,234);
    break;

    case 7: sprite.setPosition(248,234);
    break;

    case 8: sprite.setPosition(276,234);
    break;

    case 9: sprite.setPosition(304,234);
    break;

    case 10: sprite.setPosition(332,234);
    break;
    }
break;

case 9:
    switch(columna){
    case 1: sprite.setPosition(80,262);
    break;

    case 2: sprite.setPosition(108,262);
    break;

    case 3: sprite.setPosition(136,262);
    break;

    case 4: sprite.setPosition(164,262);
    break;

    case 5: sprite.setPosition(192,262);
    break;

    case 6: sprite.setPosition(220,262);
    break;

    case 7: sprite.setPosition(248,262);
    break;

    case 8: sprite.setPosition(276,262);
    break;

    case 9: sprite.setPosition(304,262);
    break;

    case 10: sprite.setPosition(332,262);
    break;
    }
break;

case 10:
   switch(columna){
    case 1: sprite.setPosition(80,290);
    break;

    case 2: sprite.setPosition(108,290);
    break;

    case 3: sprite.setPosition(136,290);
    break;

    case 4: sprite.setPosition(164,290);
    break;

    case 5: sprite.setPosition(192,290);
    break;

    case 6: sprite.setPosition(220,290);
    break;

    case 7: sprite.setPosition(248,290);
    break;

    case 8: sprite.setPosition(276,290);
    break;

    case 9: sprite.setPosition(304,290);
    break;

    case 10: sprite.setPosition(332,290);
    break;
    }
break;
        }
    }
}



void Embarcacion::setUbicacionEnTablero(){
int fila,columna;

cout<<"Fila: ";
cin>>fila;

while(fila < 1 || fila > 10){
    system("cls");
    cout<<"No existe esta fila. Ingrese un valor valido"<<endl;
    cout<<"Fila: ";
    cin>>fila;
}

_UbicacionFila = fila;

cout<<"Columna: ";
cin>>columna;

while(columna < 1 || columna > 10){
    system("cls");
    cout<<"No existe esta columna. Ingrese un valor valido"<<endl;
    cin>>columna;
}

_UbicacionColumna = columna;

}

int Embarcacion::getUbicacionFila(){
    return _UbicacionFila;
}

int Embarcacion::getUbicacionColumna(){
    return _UbicacionColumna;
}

