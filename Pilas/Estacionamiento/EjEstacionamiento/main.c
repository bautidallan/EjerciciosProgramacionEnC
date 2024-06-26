#include <stdio.h>
#include "tdapila.h"
#include <string.h>

typedef struct{
    int cantidadSalidas;
    char pat[4];
}SALIDAS;

int buscaAuto(SALIDAS v[], char patenteBuscada[4],int cantAutos);

int main(){

    TPILA pilaAutos,pilaAux;
    TELEMENTOP autos;
    SALIDAS vecSalidas[20];
    char patente[4],patenteAux[4];
    int opcion,pos,cantAutos=0;
    iniciap(&pilaAutos);
    iniciap(&pilaAux);

    do
    {
        printf("\n1. Agregar auto al estacionamiento \n");
        printf("2. Sacar auto del estacionamiento \n");
        printf("3 Salir\n");
        printf("Ingrese su opcion: \n");
        scanf("%d", &opcion);

        switch(opcion){

            case 1:
                printf("Ingrese la patente del auto que entra al estacionamiento F es fin de carga \n");
                scanf("%s",patente);
                strcpy(autos.patente,patente);
                ponep(&pilaAutos,autos);
                break;

            case 2:
             printf("Ingrese la patente del auto que quiere sacar \n");
             scanf("%s",patente);
             consultap(pilaAutos,&autos);
             while(!vaciap(pilaAutos)&& strcmp(patente,autos.patente)!=0 ){//Busco el auto a sacar
                    sacap(&pilaAutos,&autos);
                    ponep(&pilaAux,autos);
                    strcpy(patenteAux,autos.patente);
                    pos=buscaAuto(vecSalidas,patenteAux,cantAutos);
                    if(pos==-1){
                        cantAutos++;
                        vecSalidas[cantAutos].cantidadSalidas++;
                        strcpy(vecSalidas[cantAutos].pat,patenteAux);
                        printf("Agregue uno nuevo \n");
                    }
                    else{
                        vecSalidas[pos].cantidadSalidas++;
                        strcpy(vecSalidas[pos].pat,patenteAux);
                    }
                    consultap(pilaAutos,&autos);
                    }

                //Verifico si encontre el auto o sali xq se vacio la pila
                if (vaciap(pilaAutos))
                    printf("El auto no fue encontrado \n");
                else
                {
                    sacap(&pilaAutos,&autos);
                    pos=buscaAuto(vecSalidas,patente,cantAutos);
                    if(pos==-1)
                        printf("El auto %s nunca fue movido \n",patente);
                    else
                        printf("El auto %s se movio %d",patente,vecSalidas[pos].cantidadSalidas);
                    while(!vaciap(pilaAux))
                    {
                        sacap(&pilaAux,&autos);
                        ponep(&pilaAutos,autos);
                    }
                }
                break;

                }

             } while (opcion!=3);

    return 0;
}

int buscaAuto(SALIDAS v[],char patenteBuscada[4],int cantAutos){
        int i=0;
        while (i<cantAutos && strcmp(patenteBuscada,v[i].pat)!=0){
            i++;
        }
        if (i==cantAutos){
            return -1;
        }
        else
            return i;
    }

