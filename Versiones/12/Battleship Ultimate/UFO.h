#ifndef UFO_H_INCLUDED
#define UFO_H_INCLUDED
#include "Enemigo.h"

class UFO : public Enemigo{
public:
    UFO();
    void setTamanio(int tamanio);
    void setNombre();
};


#endif // UFO_H_INCLUDED
