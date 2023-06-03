#ifndef SUBMARINO_H_INCLUDED
#define SUBMARINO_H_INCLUDED
#include "Embarcaciones.h"

class Submarino : public Embarcacion{
private:
    int _Tamanio;

public:
    void setNombre();
    void setTamanio(int tamanio);

};

#endif // SUBMARINO_H_INCLUDED
