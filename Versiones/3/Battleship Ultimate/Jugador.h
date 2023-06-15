#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class Jugador{
private:
    char _Nombre[20];
    int _Puntaje;

public:
    void setNombre();
    const char* getNombre();
    int getPuntaje();
    void setPuntaje(int puntaje);
};




#endif // JUGADOR_H_INCLUDED
