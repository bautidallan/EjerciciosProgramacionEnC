#include <string.h>
#include <stdio.h>
#include "tdapila.h"

void iniciap(TPILA *p) {
   p->tope = 0;
}

int vaciap(TPILA pila) {
    return pila.tope == 0;
}

int llenap(TPILA pila) {
    return pila.tope == MAXPILA;
}

void ponep(TPILA *p, TELEMENTOP elem) {
    if (p->tope != MAXPILA){
        strcpy(p->vp[(p->tope)].patente,elem.patente);
        p->tope++;
    }
}

void sacap(TPILA *p, TELEMENTOP *pelem) {
    if  (p->tope != 0)
        {
            p->tope--;
            strcpy(pelem->patente,p->vp[p->tope].patente);
        }

}

void consultap(TPILA pila, TELEMENTOP *pelem) {
    if (pila.tope != 0){
        printf("%s",pila.vp[pila.tope].patente);
        strcpy(pelem->patente,pila.vp[pila.tope].patente);
    }
}

