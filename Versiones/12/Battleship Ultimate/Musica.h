#ifndef MUSICA_H_INCLUDED
#define MUSICA_H_INCLUDED
#include <SFML/Audio.hpp>

class Musica{
private:
    sf::Music _Musica;

public:
    void Encendida();
    void Apagada();
    void PantallaPrincipal();
    void NivelEnemigoGeneral();
    void NivelGhost();
    void NivelNautilus();
    void NivelNagronar();
    void NivelKlosternator();


};

#endif // MUSICA_H_INCLUDED
