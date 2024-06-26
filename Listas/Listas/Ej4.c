/*
Ejercicio 1
Se tiene una lista cuyos nodos almacenan:
 Nombre de Ciudad
 Cantidad de mujeres
 Cantidad de varones
Se pide recorrer la lista y calcular e informar:
a. Cuántas ciudades tienen mayor porcentaje de hombres
b. Nombre de la ciudad con mayor población
c. Porcentaje de ciudades donde la cantidad de mujeres supera el promedio de mujeres de todas las
ciudades
d. Indicar si la lista está ordenada alfabéticamente
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
typedef struct {
    char ciudad[MAX];
    int mujeres,varones;
}TELEMENTOL;

typedef struct nodo {
    TELEMENTOL dato;
    struct nodo *sig;
}NODO;

typedef NODO *TLISTA;

void cargaLista(TLISTA *lista,TELEMENTOL elem);
void inicializaLista(TLISTA *lista);
void calcula(TLISTA lista,int *mayor);
void mayorCiudad(TLISTA lista);


int main(){
    TLISTA lista;
    TELEMENTOL elem;
    int mayor;
    char city[MAX];
    inicializaLista(&lista);
    scanf("%s",city);
    while(strcmp(city,"F")!=0){
        strcpy(elem.ciudad,city);
        printf("Ingrese cantidad de hombres y mujeres \n");
        scanf("%d",&elem.varones);
        scanf("%d",&elem.mujeres);
        cargaLista(&lista,elem);
        printf("Ingrese otra ciudad \n");
        scanf("%s",city);
    }
    calcula(lista,&mayor);
    printf("Las cantidades de ciudades en las cuales el porcentaje de hombres es mayor es %d \n",mayor);
    mayorCiudad(lista);
    return 0;
}

void cargaLista(TLISTA *lista,TELEMENTOL elem){
    TLISTA ant,act,nuevo;
    nuevo=(TLISTA)malloc(sizeof(NODO));
    nuevo->dato=elem;
    printf("TOY");
    if (*lista==NULL || strcmp(elem.ciudad,(*lista)->dato.ciudad)<0){
        nuevo->sig=*lista;
        *lista=nuevo;
    }
    else{
        act=*lista;
        while(act!=NULL && strcmp(elem.ciudad,act->dato.ciudad)>0){
            ant=act;
            act=act->sig;
        }
        nuevo->sig=act;
        ant->sig=nuevo;
    }

}

void inicializaLista(TLISTA *lista){
    *lista=NULL;
}

void calcula(TLISTA lista,int *mayor){
    *mayor=0;
    TELEMENTOL ele;
    while(lista!=NULL){
       ele=lista->dato;
       if (ele.varones>ele.mujeres){
            (*mayor)++;
       }
       lista=lista->sig;
    }
}

void mayorCiudad(TLISTA lista){
    TELEMENTOL dato;
    char ciudad[MAX];
    int mayorPoblacion=0,pob=0;
    while(lista!=NULL){
        pob=0;
        dato=lista->dato;
        pob=dato.mujeres+dato.varones;
        if (pob>mayorPoblacion){
            strcpy(ciudad,dato.ciudad);
        }
        lista=lista->sig;
    }
    printf("%s \n",ciudad);
}
