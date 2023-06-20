#ifndef RECONOCIMIENTO_H_INCLUDED
#define RECONOCIMIENTO_H_INCLUDED
#include "Tablero.h"
#include "Avion.h"


class Reconocimiento:public Avion{
private:
    int _Cargas;

public:
    Reconocimiento();
    int detectar();
    void setCargas();
    int getCargas();
    void descontarCarga();

};


#endif // RECONOCIMIENTO_H_INCLUDED
