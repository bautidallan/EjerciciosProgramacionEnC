#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct nodo{
    int numero;
    struct nodo *sig;
}NODO;
typedef NODO *TLISTA;
void inicial(TLISTA *lista);
void cargaOrdenado(TLISTA *lista,int elemento);
void consultaLista(TLISTA lista,int *nro);
void muestraLista(TLISTA lista);
int main(){
    TLISTA L1,L2,lFinal;
    int dato,x,y;
    inicial(&L1);inicial(&L2);inicial(&lFinal);
    printf("Cargue 1er lista \n");
    scanf("%d",&dato);
    while(dato!=0){
        cargaOrdenado(&L1,dato);
        scanf("%d",&dato);
    }
    printf("Cargue la 2da lista \n");
    scanf("%d",&dato);
    while(dato!=0){
        cargaOrdenado(&L2,dato);
        scanf("%d",&dato);
    }
    while(L1!=NULL && L2!=NULL){
        consultaLista(L1,&x);
        consultaLista(L2,&y);
        if(x<y){
            lFinal=L1;
            L1=L1->sig;
        }
        else{
            lFinal=L2;
            L2=L2->sig;
        }
    }
    muestraLista(lFinal);
    return 0;
}


void inicial(TLISTA *lista){
    *lista=NULL;
}

void cargaOrdenado(TLISTA *lista,int elemento){
    TLISTA ant,act,nuevo;
    nuevo=(TLISTA)malloc(sizeof(NODO));
    nuevo->numero=elemento;
    if (*lista==NULL || elemento<(*lista)->numero){
        nuevo->sig=*lista;
        *lista=nuevo;
    }
    else{
        act=*lista;
        while(act!=NULL && elemento>act->numero){
            ant=act;
            act=act->sig;
        }
        ant->sig=nuevo;
        nuevo->sig=act;
    }
}

void consultaLista(TLISTA lista,int *nro){
    *nro=lista->numero;
}
void muestraLista(TLISTA lista){
    int dato;
    dato=lista->numero;
    while(lista!=NULL){
        printf("%d",dato);
        lista=lista->sig;
        dato=lista->numero;
    }
}
