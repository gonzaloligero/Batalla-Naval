#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
using namespace std;

class Enemigo{
protected:
    string _Nombre;
    int _Tamanio;
    int _UbicacionEnTablero;

public:
    void setUbicacionEnTablero(int fila,int columna);
};

#endif // ENEMIGO_H_INCLUDED
