#ifndef EMBARCACIONES_H_INCLUDED
#define EMBARCACIONES_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;

class Embarcacion{
protected:
    string _Nombre;
    int _UbicacionEnTablero;

public:
    void setUbicacionEnTablero(int x,int y);

};

#endif // EMBARCACIONES_H_INCLUDED
