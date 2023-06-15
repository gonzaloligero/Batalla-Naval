#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED
#include "Enemigo.h"

class Boss : public Enemigo{
protected:
    int _Habilidad;
    bool _Estado;
    int _Atacar;

public:
    void setEstado();
    int getAtacar();

};

#endif // BOSS_H_INCLUDED
