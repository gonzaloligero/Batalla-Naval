#ifndef CAZA_H_INCLUDED
#define CAZA_H_INCLUDED
#include "Avion.h"

class Caza:public Avion{
public:
    Caza();
    int otorgarSupremacia();
    int otorgarSupremaciaIA();

};


#endif // CAZA_H_INCLUDED
