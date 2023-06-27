#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

class Jugador{
private:
        char _Nombre[20];
        int _Puntaje;
        int _cantDisparos;
        float _efectividad;

public:
        Jugador();
        void setNombre();
        void setPuntaje(int puntaje);
        void setCantDisparos(int cant);
        void setEfectividad(float efec);
        const char* getNombre();
        int getPuntaje();
        int getCantDisparos();
        float getEfectividad();
        void mostrarRegisttro();

};

#endif // JUGADOR_H_INCLUDED
