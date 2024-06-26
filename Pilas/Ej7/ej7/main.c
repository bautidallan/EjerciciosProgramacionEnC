#include <stdio.h>
#include "tdapila.h"


    int main(){
  TPILA p1,pInvertida,pilaAux;
  TELEMENTOP e1,e2,e3;
  int esPalindromo=1;

  //Inicializo la pilas
  iniciap(&p1);
  iniciap(&pInvertida);
  iniciap(&pilaAux);

  scanf("%c",&e1);
  //Leo la pila hasta que se llene o sea fin de datos y a la vez cargo pilaAux
  while (!llenap(p1)&& !llenap(pilaAux)&& e1!='F'){
    ponep(&p1,e1);
    ponep(&pilaAux,e1);
    scanf("%c",&e1);
  }
  //Lleno pila 2 invertida
  while (!llenap(pInvertida)&& !vaciap(p1)){
    sacap(&p1,&e1);
    ponep(&pInvertida,e1);
  }
  while(!vaciap(pInvertida)&&!vaciap(pilaAux) || esPalindromo!=0){
    sacap(&pilaAux,&e2);
    sacap(&pInvertida,&e3);
    printf("%c %c",e2,e3);
    if (e2!=e3){
       esPalindromo=0;
    }
  }

  if(esPalindromo==1){
    printf("Es capicua");
  }
  else
    printf("No es capicua");

  return 0;
}


