#include <stdio.h>
#include <string.h>
#include "tdacola.h"
#include "tddapila.h"

/*Desarrolle un procedimiento que, dada una cola de enteros, genere una estructura adecuada(A que se refiere ) para generar
tantas colas de salida como cambios hay en la secuencia ascendente de la cola original (cada cola debe
contener un grupo ordenado a la inversa de elementos de la cola de entrada). Ejemplo
Cola original = (1, 2, 4, 5, 3, 8, 9, 1, 20, 4)
Cola1 = 5, 4, 2, 1
Cola2 = 9, 8, 3
Cola3 = 20, 1
Cola4 = 4

*/
void generaNuevaCola(TCOLA *nuevaCola,TCOLA *colaoriginal);
void muestraCola(TCOLA *cola);
int main(){
    TCOLA cola,cola1,cola2;
    TELEMENTOC elemen;
    TPILA pilaAux;
    TELEMENTOP ePila;
    iniciac(&cola);iniciac(&cola1);iniciac(&cola2);
    iniciap(&pilaAux);
    printf("Cargue la cola 0 es fin de datos \n");
    scanf("%d",&elemen);
    while(!llenac(cola) && elemen!=0){
        ponec(&cola,elemen);
        scanf("%d",&elemen);
    }
    generaNuevaCola(&cola1,&cola);
    muestraCola(&cola1);
    return 0;
}

void generaNuevaCola(TCOLA *nuevaCola,TCOLA *colaoriginal){

        TELEMENTOC elemen;
        TELEMENTOP ePila;
        TPILA pilaAux;
        iniciac(nuevaCola);
        iniciap(&pilaAux);
        if(!vaciac(*colaoriginal)){
            sacac(colaoriginal,&elemen);
            ePila=elemen;
            ponep((&pilaAux),ePila);
        }
        sacac(colaoriginal,&elemen);
        while(elemen>ePila && !vaciac(*colaoriginal)){
            ePila=elemen;
            ponep(&pilaAux,ePila);
            sacac(colaoriginal,&elemen);
        }
        while(!vaciap(pilaAux) && !llenac(*nuevaCola)){
            sacap(&pilaAux,&ePila);
            elemen=ePila;
            ponec(nuevaCola,elemen);
        }
    }
void muestraCola(TCOLA *cola){
    TELEMENTOC e;
    while(!vaciac(*cola)){
        sacac(cola,&e);
        printf("%d \n",e);
    }
}

