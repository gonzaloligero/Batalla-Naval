#include <iostream>
#include "ArchivoPuntaje.h"
using namespace std;

ArchivoPuntaje::ArchivoPuntaje(){
    char nombre[30]="puntajes.dat";
    strcpy(_nombre,nombre);
}

Jugador ArchivoPuntaje::leerRegistro(int pos) {

        FILE* p;
        Jugador reg;
        p = fopen(_nombre, "rb");
        if (p == NULL) {
            cout << "Error en la apertura del archivo" << endl;
            return reg;
        }

        fseek(p, pos * sizeof reg, SEEK_SET);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);

        return reg;
}

int ArchivoPuntaje::contarRegistros() {

        FILE* p;
        int tam;
        p=fopen(_nombre, "rb");
        if (p==NULL) {
            return -1;
        }

        fseek(p, 0, SEEK_END);
        tam = ftell(p);
        fclose(p);

        return tam / sizeof(Jugador);
}



void ArchivoPuntaje::MostrarArchivoPuntaje() {

        FILE* p;
        p=fopen(_nombre,"rb");
        if (p == NULL) {
            cout << "Error al abrir archivo";
            return;
        }

        Jugador juga;
        while (fread(&juga, sizeof(juga), 1, p) == 1) {
           juga.mostrarRegisttro();
           cout<<endl;
        }

        fclose(p);
}

void ArchivoPuntaje::VaciarArchivoPuntaje() {

        FILE* p;
        p = fopen(_nombre, "wb");
        if (p == NULL) {
            cout << "Error en archivo";
            return;
        }

        fclose(p);
}

void ArchivoPuntaje::AgregarRegistro(Jugador juga){

    FILE* p=fopen(_nombre,"ab");
    if(p==NULL){
        cout<<"Error al abrir el archivo";
        return;
    }
    fwrite(&juga, sizeof juga,1,p);
    fclose(p);
}


int ArchivoPuntaje::ModificarRegistro(Jugador juga){  // RECORDEMOS QUE RECIBIMOS UN REGISTRO

            ArchivoPuntaje objP;
            Jugador aux, vec[10]={};
            bool flag=false;

            int cantReg=objP.contarRegistros();
            if(cantReg==0){                         // SI ES EL PRIMER REGISTRO QUE SE INGRESA LO GUARDO Y NO EVALUO NADA
             objP.AgregarRegistro(juga);
             return 1;
            } else{                                 // SI NO ES EL PRIMER REGISTRO ORDENO DE MAYOR A MENOR LOS PUNTAJES
                     for(int i=0; i<cantReg; i++){
                        vec[i]=objP.leerRegistro(i);  // TODO LO QUE ESTA EN ARCHIVO LO PASO A MEMORIA.

                    }

                    objP.VaciarArchivoPuntaje();      // VACIO EL ARCHIVO PARA LUEGO VOLVER A ESCRIBIR YA ORDENADO

                     for(int i=0; i<cantReg; i++){
                        if(juga.getPuntaje()> vec[i].getPuntaje()){  // PREGUNTO SI EL NUEVO REG SUPERA AL REG YA ARCHIVADO
                            flag=true;
                            i=cantReg;
                        }else if(juga.getPuntaje()== vec[i].getPuntaje()){ // PREGUNTO SI ES QUE IGUALA
                              if(juga.getEfectividad()>vec[i].getEfectividad()){ // SE DEFINE POR PORCENTAJE
                                flag=true;
                                i=cantReg;
                              }else{
                                  if(i<10){
                                    flag=true;
                                    i=cantReg;
                                   }
                              }
                            }else{   // SI NO FUE MAYOR O IGUAL PREGUNTO SI HAY MENOS DE 10 REGISTROS
                              if(cantReg<10){ // PORQUE SI HUBIENSE 10, ESTE NO CLASIFICA AL PODIO DE 10 MEJORES PUNTOS
                                flag=true;    // YA QUE EN LA EVALUACION ANTERIOR NO SUPERO A NINGUNO DE LOS 10 MEJORES
                              }
                            }
                        }

                     if(flag==true){ // TANTO EN EL CASO DE QUE SEA MAYOR , IGUAL O XQ HUBO MENOS DE 10 REGISTROS
                        vec[9]=juga; // EL REGISTRO NUEVO ES APTO PARA UNA UBICACION ENTRE LOS 10 MEJORES

                          for(int i=0; i<10; i++){ // YA CON LOS REGISTROS EN MEMORIA ORDENAMOS MEDIANTE BURBUJEO DE > A <
                            for(int j=0; j<9; j++){
                             if(vec[j].getPuntaje()<vec[j+1].getPuntaje()){
                                aux=vec[j];
                                vec[j]=vec[j+1];
                                vec[j+1]=aux;
                             }else if(vec[j].getPuntaje()==vec[j+1].getPuntaje()){
                                     if(vec[j].getEfectividad()<vec[j+1].getEfectividad()){
                                      aux=vec[j];
                                      vec[j]=vec[j+1];
                                      vec[j+1]=aux;
                                     }
                                  }
                              }
                           }

                           if(cantReg<10){// SI EN PRINCIPIO DIGAMOS QUE SE CONTARON DOS REGISTROS, CUMPLIRIA ESTA CONDICIÓN
                               for(int x=0;x<cantReg+1;x++){ //DEBEMOS AGREGAR UNA VUELTA MAS PARA EL REGISTRO NUEVO PODER ARCHIVARLO
                                    aux=vec[x];
                                    objP.AgregarRegistro(aux);

                               }
                           }else { // SI YA HAY 10 REGISTROS NO SE SUMA NADA A LA CANTIDAD DE REGISTRO Y SE ARCHIVAN LOS 10 QUE CORRESPONDEN
                            for(int x=0;x<cantReg;x++){
                                    aux=vec[x];
                                    objP.AgregarRegistro(aux);

                               }

                           }
                    }

            }

}
