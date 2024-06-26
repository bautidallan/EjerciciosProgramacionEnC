#include <stdio.h>
#include <string.h>
#define MAX 20
struct records{
    char cod[6];
    char nombreDep[10];
    int tiempo;
};
typedef struct{
    char codigoDep[6];
    int tiempo;
}resultados;

void cargaTabla(struct records v[],int *i);
int buscaIndice(struct records vector[],char codBuscado[6]);
void cargarRecords();
void cargarCompetencias();

int main(){
    FILE *COMPETICION;
    struct records vec[MAX];
    resultados r;
    char codActual[6],nombreMayor[10];
    int i,cantCompetidores,superaRecord,mayorDep,pos,totalCompet;
    float promedio;

    cargarRecords();
    cargarCompetencias();

    COMPETICION=fopen("competicion.dat","rb");
    cargaTabla(vec,&i);
    if (COMPETICION!=NULL){
        printf("Entro \n");
        fread(&r,sizeof(resultados),1,COMPETICION);
        mayorDep=0;
        printf("\t \t Resultados de la competencia \n");
        printf("Deporte \t Cant.Competidores \t Cant.SuperoRecord \t TiempoPromedio \n");
        while(!feof(COMPETICION)){
            cantCompetidores=0; superaRecord=0;
            promedio=0;
            strcpy(codActual,r.codigoDep);
            while(!feof(COMPETICION) && !strcmp(codActual,r.codigoDep)){
                    cantCompetidores++;
                    pos=buscaIndice(vec,r.codigoDep);
                    if (pos!=-1){
                        if(r.tiempo>vec[pos].tiempo){
                            superaRecord++;
                        }
                    }
                    promedio=r.tiempo+promedio;
                    fread(&r,sizeof(resultados),1,COMPETICION);
            }
                if (cantCompetidores>mayorDep){
                    mayorDep=cantCompetidores;
                    strcpy(nombreMayor,vec[pos].nombreDep);
                }
                promedio=(float)promedio/cantCompetidores;
                printf("%s \t %d \t %d \t %f\n",codActual,cantCompetidores,superaRecord,promedio);
                totalCompet=totalCompet+cantCompetidores;
        }
        printf("Deporte con mayor cantidad de competidores %s",nombreMayor);
    }

    return 0;
}
int buscaIndice(struct records vector[],char codBuscado[6]){
    int n=0;
    while (n<MAX && strcmp(codBuscado,vector[n].cod)!=0){
        n++;
    }
    if (n<MAX){
        return n;
    }
    else
        return -1;
}
void cargaTabla(struct records v[],int *i){
    *i=0;
    FILE *arch;
    arch=fopen("records.dat","rb");
    if (arch!=NULL){
        fread(&v[*i],sizeof(struct records),1,arch);
        while(!feof(arch) && (*i)<MAX){
            (*i)++;
            fread(&v[*i],sizeof(struct records),1,arch);
        }
    }
    fclose(arch);
}

void cargarCompetencias() {
    resultados r;
    FILE *archPagos, *lote;

    archPagos = fopen("competicion.dat","wb");
    lote = fopen("competicion.txt","rt");
    if(lote != NULL) {
	    while(fscanf(lote, "%s %d", r.codigoDep,&r.tiempo) == 2){
	       fwrite(&r, sizeof(resultados), 1, archPagos);
	    }
		fclose(lote);
		fclose(archPagos);
    } else
        printf("archivo lote.txt no existe! \n");
}

void cargarRecords() {
    struct records r;
    FILE *archPagos, *lote;

    archPagos = fopen("records.dat","wb");
    lote = fopen("records.txt","rt");
    if(lote != NULL) {
	    while(fscanf(lote, "%s %s %d", r.cod, r.nombreDep,&r.tiempo) == 3){
	       fwrite(&r, sizeof(struct records), 1, archPagos);
	       printf("%d \n",r.tiempo);
	    }
		fclose(lote);
		fclose(archPagos);
    } else
        printf("archivo lote.txt no existe! \n");
}

