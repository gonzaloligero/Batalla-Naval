#include <iostream>
#include "Boss.h"
#include <ctime>
#include <cstdlib>
using namespace std;

void Boss::setDireccion(){
srand(time(NULL));
int direccion;

_Direccion = rand()%2+1;

}

int Boss::getDireccion(){
    return _Direccion;
}
