#include <stdio.h>
#include "tdapila.h"
/*Dos textos se han almacenado en dos pilas de caracteres, que ingresaron en la pila respectiva de izquierda
a derecha, mostrar el más largo en su orden original. Se desconoce inicialmente la cantidad de caracteres. */
int main(){
    TPILA p1,p2,pAmostrar;
    TELEMENTOP e1,e2,e3;
    iniciap(&p1);
    iniciap(&p2);
    iniciap(&pAmostrar);
    printf("Ingrese la primer cadena");
    scanf("%c",&e1);
    while(!llenap(p1) && e1!='F'){
        ponep(&p1,e1);
        scanf("%c",&e1);
    }
    printf("Ingrese la segunda cadena");
    scanf("%c",&e2);
     while(!llenap(p2) && e2!='F'){
        ponep(&p2,e2);
        scanf("%c",&e2);
    }
   if (p1.tope>p2.tope){
        while(!vaciap(p1)){
            sacap(&p1,&e3);
            ponep(&pAmostrar,e3);
        }
   }
    else{
        while(!vaciap(p2)){
            sacap(&p2,&e3);
            ponep(&pAmostrar,e3);
    }
   }
   while(!vaciap(pAmostrar)){
    sacap(&pAmostrar,&e3);
    printf("%c",e3);
   }
}
