#ifndef NAUTILUS_H_INCLUDED
#define NAUTILUS_H_INCLUDED
#include <iostream>
#include <cstring>
#include "Boss.h"
#include "Tablero.h"
using namespace std;

class Nautilus: public Boss{
public:
    Nautilus();
    bool sumergirse();
    void setNombre();
    void setTamanio(int tamanio);
    int getTamanio();
    string getNombre();
};

#endif // NAUTILUS_H_INCLUDED
