#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED
#include "Enemigo.h"

class Boss : public Enemigo{
protected:
    int _Atacar;
    int _Direccion;

public:
    void setEstado();
    void setDireccion();
    int getDireccion();
    int getAtacar();

};

#endif // BOSS_H_INCLUDED
