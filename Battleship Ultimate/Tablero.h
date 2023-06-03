#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include "Embarcaciones.h"
#include "Destructor.h"
#include "Acorazado.h"
#include "Submarino.h"
#include "Fragata.h"
#include "Portaaviones.h"

class Tablero{
private:
    int _Tamanio[10][10];

public:
    void tachar(int fila,int columna);
    void completarTableroNormal(Destructor destructor,Acorazado acorazado,Submarino submarino, Fragata fragata,Portaaviones portaaviones);
    void completarTableroBossFight();

};


#endif // TABLERO_H_INCLUDED
