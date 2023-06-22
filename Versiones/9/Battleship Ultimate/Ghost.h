#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED
#include <iostream>
#include <cstring>
#include "Boss.h"
#include "Tablero.h"
using namespace std;

class Ghost: public Boss{
public:
    Ghost();
    void teletransportarse();
    void setNombre();
    void setTamanio(int tamanio);
    int getTamanio();
    string getNombre();
};

#endif // GHOST_H_INCLUDED
