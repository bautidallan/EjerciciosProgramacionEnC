#include <stdio.h>
#include "tdapilad.h"
#include <stdlib.h>
#include <string.h>



int main(){
    TELEMENTOP e;
    TPILA Pila;
    char palabra[20];
    int largo,contErrores=0;
    iniciap(&Pila);
    fgets(palabra,20,stdin); //Leer strings de forma correcta stdin es standard input
    largo=strlen(palabra);
    for (int i=0; i<largo;i++){
        if (palabra[i]=='(')
            {
                ponep(&Pila,'(');
            }
        else
        {
        if(palabra[i]==')')
            {
            if (!vaciap(Pila))
                {
                sacap(&Pila,&e);
                }
            else{
                contErrores++;
            }
            }
        }
    }
    if(!vaciap(Pila) || contErrores>0){
        if (vaciap(Pila))
            printf("Falto abrir parentesis");
        else
            printf("Falto cerrar parentesis");
    }
    else
        printf("Bien redactado");

   return 0;
}
