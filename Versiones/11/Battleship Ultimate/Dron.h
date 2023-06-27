#ifndef DRON_H_INCLUDED
#define DRON_H_INCLUDED
#include "Avion.h"

class Dron:public Avion{
private:
    int _ContadorAtaques;

public:
    Dron();
    void setContadorAtaques(int contador);
    int getContador();
    int atacarColumna();
    int atacarFila();
    int atacarColumnaIA();
    int atacarFilaIA();

};

#endif // DRON_H_INCLUDED
