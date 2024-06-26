/*
Escribir un programa que utilice las siguientes funciones a desarrollar:
a) Una función que reciba un puntero a entero por referencia, le reserve memoria para un int y cargue
allí un número ingresado por teclado.
b) Una función que reciba un entero y devuelva un puntero a un entero con el doble del valor recibido.
c) Una función que reciba dos punteros a entero e intercambie sus respectivas direcciones de memoria
apuntadas.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargaEntero(int *pentero);
void devuelvePuntero(int valor,int **puntero);

int main(){
    int *ppen,*nuevo;
    int entero;
    cargaEntero(ppen);
    entero=8;
    devuelvePuntero(entero,&nuevo);
    printf("%d \n",*nuevo);
    return 0;
}


void cargaEntero(int *pentero){
    pentero=(int*)malloc(sizeof(int));
    scanf("%d",pentero);
    printf("%d \n",*pentero);
}
void devuelvePuntero(int valor,int **puntero){
    *puntero=(int*)malloc(sizeof(int));
    **puntero=valor*2;
}

void intercambia(int **p1,int **p2)
{
    int *aux;
    aux=p1;
    *p1=p2;
    *p2=aux;
}
