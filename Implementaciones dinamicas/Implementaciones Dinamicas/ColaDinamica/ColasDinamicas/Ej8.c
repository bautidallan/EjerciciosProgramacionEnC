/*
Ejercicio 4
A partir de dos colas que almacenan letras, ingresadas en orden ascendente. Generar una secuencia de
salida ordenada en forma descendente que contenga los elementos de la primera que no se encuentran
en la segunda. Se sugiere el uso de una estructura auxiliar para la resolucion.
*/
#include <stdio.h>
#include "tdacolad.h"

int main(){
    TCOLA cola1,cola2,colaAux;
    TELEMENTOC e1,e2;
    //Inicializo colas
    iniciac(&colaAux);
    iniciac(&cola1);
    iniciac(&cola2);
    //Cargo la primer cola
    scanf("%c",&e1);
    while (e1!="F"){
       ponec(&cola1,e1);
       scanf("%c",&e1);
    }
    //Cargo la segunda cola
    scanf("%c",&e2);
    while (e2!="F"){
       ponec(&cola2,e2);
       scanf("%c",&e2);
    }
    //Algoritmo para generar la nueva estructura auxiliar
    while(!vaciac(cola1))
    {
        sacac(&cola1,&e1);
        consultac(cola2,&e2);
        while(e1<e2 && !vaciac(cola2)){//Busco hasta que el que el elemento sea menor
            ponec(&colaAux,e1); //Deberia poner en una pila, pero eso no rompe con el ENCAPSULAMIENTO  del tda ?
            sacac(&cola1,&e1);
        }
       sacac(&cola2,&e2);
    }

    return 0;
    }


