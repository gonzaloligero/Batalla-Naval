#include <iostream>
#include <cctype>
#include "Funciones.h"
#include "Tablero.h"
#include "Acorazado.h"
#include "Jugador.h"
#include <SFML/Audio.hpp>
using namespace std;

int decidirPuntaje(float copia){

    if(copia > 80){
        return 1000;
    }else if(copia > 68){
        return 900;
    }else if(copia > 58){
        return 800;
    }else if(copia > 52){
        return 750;
    }else if(copia > 48){
        return 700;
    }else if(copia > 42){
        return 650;
    }else if (copia > 38){
        return 600;
    }else if(copia > 32){
        return 550;
    }else if(copia > 27){
        return 500;
    }else if(copia > 24){
        return 400;
    }else if(copia > 19){
        return 300;
    }else if(copia > 17){
        return 200;
    }else{
        return 100;
    }

}

int seleccionarBarco(bool &destructorUbicado, bool &fragataUbicada, bool &submarinoUbicado, bool &portaavionesUbicado, bool&acorazadoUbicado){

        Destructor miDestructor; // <<--  CREAMOS NUESTROS OBJETOS BARCOS
        Fragata miFragata;
        Portaaviones miPortaaviones;
        Submarino miSubmarino;
        Acorazado miAcorazado;

                    bool cumpla=false;
                    int opcion;
                    while(!cumpla){
                    cout<<endl;
                    cout<<"QUE EMBARCACION DESEA UBICAR"<<endl;
                    cout<<endl;
                    if(destructorUbicado == false){ // 2
                        cout<<"1) "<<miDestructor.getNombre()<<endl;
                    }
                    if(fragataUbicada == false){ // 1
                        cout<<"2) "<<miFragata.getNombre()<<endl;
                    }
                    if(submarinoUbicado == false){ // 3
                        cout<<"3) "<<miSubmarino.getNombre()<<endl;
                    }
                    if(portaavionesUbicado == false){ // 4
                        cout<<"4) "<<miPortaaviones.getNombre()<<endl;
                    }
                    if(acorazadoUbicado == false){// 3
                        cout<<"5) "<<miAcorazado.getNombre()<<endl;
                    }

                    cout<<"Opcion: ";
                    cin>>opcion;
                    system("cls");

                   if(opcion==1){
                         if(destructorUbicado==true){

                           cumpla=false;

                          } else{
                               destructorUbicado=true;
                               return  miDestructor.getTamanio();
                            }

                   }
                    else if(opcion==2){
                       if(fragataUbicada==true){
                       cumpla=false;
                       }else{
                            fragataUbicada=true;
                            return miFragata.getTamanio();
                       }
                   }
                     else if(opcion==3){
                         if(submarinoUbicado==true){
                            cumpla=false;
                         }
                          else{
                            submarinoUbicado=true;
                            return miSubmarino.getTamanio();
                          }

                     }
                        else if(opcion==4){
                            if(portaavionesUbicado==true){
                                cumpla=false;
                            }
                              else{
                                 portaavionesUbicado=true;
                                 return miPortaaviones.getTamanio();
                              }
                        }
                           else if(opcion==5){
                             if(acorazadoUbicado==true){
                                cumpla=false;
                             } else{
                                  acorazadoUbicado=true;
                                  return miAcorazado.getTamanio();
                               }


                           }

                    }

}














