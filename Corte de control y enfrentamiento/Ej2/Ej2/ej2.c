#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct{
    char fecha[7];
    int legajo;
    char hora[6];
}entradas;

typedef struct{
    char fecha[7];
    int legajo;
    char horaT[6],horaR[6];
    char estado;
}personal;

void cargarEntradasT();
void cargarEntradas();
void muestraArch();

int main(){
    FILE *horaEnt,*relojEntradas,*archFinal;
    entradas datos;
    personal reg;
    cargarEntradasT();
    cargarEntradas();
    archFinal=fopen("final.dat","wb");
    horaEnt=fopen("entradasT.dat","rb");
    relojEntradas=fopen("RelojEntradas.dat","rb");
    int total,totalFaltas,totalDemoras,erroneas;
    float ausentismo;
    if (horaEnt!=NULL && relojEntradas!=NULL){
        fread(&datos,sizeof(entradas),1,relojEntradas);
        fread(&reg,sizeof(personal),1,horaEnt);
        total=0;totalFaltas=0;totalDemoras=0;erroneas=0;
        while(!feof(relojEntradas) && !feof(horaEnt)){
        while(strcmp(reg.fecha,datos.fecha)==0){
            if(reg.legajo!=datos.legajo){
                        reg.estado='A';
                        totalFaltas++;
                        total++;
                        fwrite(&reg,sizeof(personal),1,archFinal);
                        fread(&reg,sizeof(personal),1,horaEnt);
                }
            else{
               if(strcmp(datos.hora,reg.horaT)<0){
                    reg.estado='P';
                    strcpy(reg.horaR,datos.hora);
                    total++;
                    fwrite(&reg,sizeof(personal),1,archFinal);
                    fread(&reg,sizeof(personal),1,horaEnt);
                    fread(&datos,sizeof(entradas),1,relojEntradas);

               }else{
                    reg.estado='T';
                    strcpy(reg.horaR,datos.hora);
                    total++;
                    totalDemoras++;
                    fwrite(&reg,sizeof(personal),1,archFinal);
                    fread(&reg,sizeof(personal),1,horaEnt);
                    fread(&datos,sizeof(entradas),1,relojEntradas);
                    }
                }
            }
            total++;
            erroneas++;
            fread(&datos,sizeof(entradas),1,relojEntradas);
        }
    }
    else{
        printf("Error en el archivo");
    }
    fclose(horaEnt);
    fclose(relojEntradas);
    fclose(archFinal);
    muestraArch();
    ausentismo=(float)(totalFaltas*100)/total;
    printf("%d \n",total);
    printf("Total faltas %d \n",totalFaltas);
    printf("%f  %d entradas demoradas \n",ausentismo,totalDemoras);
    printf("%d \n",erroneas);
    return 0;
}


void cargarEntradasT() {
    personal r;
    FILE *archEntradasT, *lote;

    archEntradasT = fopen("entradasT.dat","wb");
    lote = fopen("entradasT.txt","rt");
    if(lote != NULL) {
	    while(fscanf(lote, "%s %d %s",r.fecha,&r.legajo,r.horaT) == 3){
           strcpy(r.horaR,"0");
           r.estado='N';
	       fwrite(&r, sizeof(personal),1, archEntradasT);
	    }
		fclose(lote);
		fclose(archEntradasT);
    } else
        printf("archivo lote.txt no existe! \n");
}


void cargarEntradas() {
    entradas r;
    FILE *archEntradas, *lote;
    archEntradas = fopen("RelojEntradas.dat","wb");
    lote = fopen("RelojEntradas.txt","rt");
    if(lote != NULL) {
	    while(fscanf(lote, "%s %d %s", r.fecha,&r.legajo,r.hora) == 3){
	       fwrite(&r, sizeof(entradas), 1, archEntradas);
	    }
		fclose(lote);
		fclose(archEntradas);
    } else
        printf("archivo lote.txt no existe! \n");
}

void muestraArch(){
    FILE *archFinal;
    personal r;
    archFinal=fopen("final.dat","rb");
    if(archFinal!=NULL){
    fread(&r,sizeof(personal),1,archFinal);
    printf("%s %d %s %s %c \n",r.fecha,r.legajo,r.horaT,r.horaR,r.estado);
    while(!feof(archFinal)){
        fread(&r,sizeof(personal),1,archFinal);
        printf("%s %d %s %s %c \n",r.fecha,r.legajo,r.horaT,r.horaR,r.estado);
        }
    }
    else
        printf("Error en mostrar ");
}

