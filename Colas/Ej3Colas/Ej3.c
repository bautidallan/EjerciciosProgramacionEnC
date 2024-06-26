#include <stdio.h>
#include <string.h>
#include "tdacola.h"
#include "tdapila.h"

/*
Ejercicio 3
Dada una pila que contiene caracteres y una cola que contiene números naturales, procesar cada elemento
de la cola sacando de la pila tantos caracteres como el número indique. En caso de que la pila se vacíe
antes de sacar la cantidad que el número determina, poner en ésta tantos * como caracteres faltantes
resulten en la misma y almacenar en la misma cola esa diferencia negativa. El proceso termina cuando se
hayan sacado todos los elementos originales de la cola.
 */

int main(){
    TCOLA cola;
    TPILA pila;
    TELEMENTOP elemen;
    TELEMENTOC elemenCola;
    int i;
    char caracter;
    iniciac(&cola);
    iniciap(&pila);
    printf("Cargue la pila, F es fin de datos \n");
    scanf("%c",&elemen);
    while(!llenap(pila)&& elemen!="F"){

        ponep(&pila,elemen);
        scanf("%c",&elemen);
    }
    printf("Cargue la cola 0 es fin de datos \n");
    scanf("%d",&elemenCola);
    while(!llenac(cola)&& elemenCola!=0){
        ponec(&cola,elemenCola);
        scanf("%d",&elemenCola);
        }
    while(!vaciac(cola))
        {
         i=0;
         sacac(&cola,&elemenCola);
         while(!vaciap(pila) && i<elemenCola)
            {
                sacap(&pila,&elemen);
                printf("%c \n",elemen);
                i++;
            }
        if (vaciap(pila)){
            while(i<elemen){
                ponep(&pila,"*");
                i++;
            }
        }
        }

    return 0;
    }

