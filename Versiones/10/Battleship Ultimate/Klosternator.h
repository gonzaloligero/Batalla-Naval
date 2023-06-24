#ifndef KLOSTERNATOR_H_INCLUDED
#define KLOSTERNATOR_H_INCLUDED
#include <iostream>
#include <cstring>
#include "Boss.h"
#include "Tablero.h"
using namespace std;

class Klosternator: public Boss{
public:
    Klosternator();
    bool seEntiendeGentes();
    bool estoEsBatata();
    void setNombre();
    void setTamanio(int tamanio);
    int getTamanio();
    string getNombre();
};

#endif // KLOSTERNATOR_H_INCLUDED
