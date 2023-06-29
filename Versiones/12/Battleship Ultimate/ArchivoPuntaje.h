#ifndef ARCHIVOPUNTAJE_H_INCLUDED
#define ARCHIVOPUNTAJE_H_INCLUDED
#include <cstring>
#include "Jugador.h"

class ArchivoPuntaje{
private:
    char _nombre[30];

public:
    ArchivoPuntaje();
    Jugador leerRegistro(int pos);
    int contarRegistros();
    void MostrarArchivoPuntaje();
    void VaciarArchivoPuntaje();
    int ModificarRegistro(Jugador juga);
    void AgregarRegistro(Jugador juga);

};

#endif // ARCHIVOPUNTAJE_H_INCLUDED
