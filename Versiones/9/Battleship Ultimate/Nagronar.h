#ifndef NAGRONAR_H_INCLUDED
#define NAGRONAR_H_INCLUDED
#include <iostream>
#include <cstring>
#include "Boss.h"
#include "Tablero.h"
using namespace std;

class Nagronar: public Boss{
public:
    Nagronar();
    int destruirFila(Tablero miTablero);
    void setNombre();
    void setTamanio(int tamanio);
    int getTamanio();
    string getNombre();
};

#endif // NAGRONAR_H_INCLUDED
