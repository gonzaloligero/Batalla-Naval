#include <iostream>
#include "Portaaviones.h"
#include "Embarcaciones.h"
using namespace std;

void Portaaviones::setNombre(){
    _Nombre = "Portaaviones";

}
void Portaaviones::setTamanio(int tamanio = 4){
    _Tamanio = tamanio;
}
