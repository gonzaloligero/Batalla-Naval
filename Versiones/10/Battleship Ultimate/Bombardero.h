#ifndef BOMBARDERO_H_INCLUDED
#define BOMBARDERO_H_INCLUDED
#include "Avion.h"

class Bombardero:public Avion{
public:
    Bombardero();
    int bombardear();
    int bombardearIA();

};

#endif // BOMBARDERO_H_INCLUDED
