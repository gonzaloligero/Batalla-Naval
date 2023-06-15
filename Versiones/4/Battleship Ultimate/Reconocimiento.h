#ifndef RECONOCIMIENTO_H_INCLUDED
#define RECONOCIMIENTO_H_INCLUDED
#include "Avion.h"

class Reconocimiento:public Avion{
private:
    int _Cargas;

public:
    Reconocimiento();
    void setCargas();
    int getCargas();
    void descontarCarga();

};


#endif // RECONOCIMIENTO_H_INCLUDED
