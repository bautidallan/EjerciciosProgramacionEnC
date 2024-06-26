#include <stdio.h>
#include "tdapila.h"
/*Leer una cadena de texto e informar si es o no un palíndroma ("capicúa").
 Por ejemplo: abggba, ABBA son palíndromas
 abddbb no es palíndroma
*/

int main(){
  TPILA p1;
  TELEMENTOP e1;
  char palAux[20];
  int indice,bandera=1;
  iniciap(&p1);
  indice=0;
  scanf("%c",&e1);
  while (!llenap(p1) && e1!='F'){
    palAux[p1.tope]=e1;
    ponep(&p1,e1);
    scanf("%c",&e1);
  }
  while(!vaciap(p1) && bandera!=0){
        sacap(&p1,&e1);
        if (palAux[p1.tope]!=e1){
            bandera=0;
        }
  }
  if(bandera==1){
    printf("Son capicua");
  }
  return 0;
}
