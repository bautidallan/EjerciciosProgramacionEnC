#include <stdio.h>
#include <string.h>
#define MAX 20
typedef struct{
    char proyecto[5];
    int horasEstimadas;
}estimacion;

typedef struct{
    char proyecto[5];
    int empleado,semana;
    int horas;
}personal;

void cargarHorasProyectos();
void cargaProyectos();
int buscaProyect(estimacion vec[5], char proyecBuscado[5]);

int main(){
    FILE *horasSemanales,*horasEstimadas;
    estimacion data;
    personal r;
    char proyectoAc[5];
    float desvio;
    int i,horasProyectoAc,empleadoMayor,horasMasTrabajo,empleadoAc,horasEmpleadoAc,pos;
    cargarHorasProyectos();
    cargaProyectos();
    i=0;
    horasSemanales=fopen("archSemanales.dat","rb");
    horasEstimadas=fopen("horasEstimadas.dat","rb");
    estimacion vecProyec[MAX];
    fread(&data,sizeof(estimacion),1,horasEstimadas);
    while(!feof(horasEstimadas)){
        strcpy(vecProyec[i].proyecto,data.proyecto);
        vecProyec[i].horasEstimadas=data.horasEstimadas;
        i++;
        fread(&data,sizeof(estimacion),1,horasEstimadas);
    }
    fclose(horasEstimadas);
    if (horasSemanales!=NULL){
        fread(&r,sizeof(personal),1,horasSemanales);
        strcpy(proyectoAc,r.proyecto);
        horasMasTrabajo=0;
        while(!feof(horasSemanales)){
            printf("Proyecto :%s \n",proyectoAc);
            empleadoMayor=0;
            horasProyectoAc=0;
            horasMasTrabajo=0;
            while(!feof(horasSemanales)&& strcmp(proyectoAc,r.proyecto)==0){
                horasEmpleadoAc=0;
                empleadoAc=r.empleado;
                while(!feof(horasSemanales)&& strcmp(proyectoAc,r.proyecto)==0 && empleadoAc==r.empleado){
                    horasEmpleadoAc+=r.horas;
                    fread(&r,sizeof(personal),1,horasSemanales);
                }
                horasProyectoAc+=horasEmpleadoAc;
                if (horasEmpleadoAc>horasMasTrabajo){
                    horasMasTrabajo=horasEmpleadoAc;
                    empleadoMayor=empleadoAc;
                }
               printf("Empleado \t Horas Trabajadas \n");
               printf("%d \t\t\t %d \n",empleadoAc,horasEmpleadoAc);
            }
            pos=buscaProyect(vecProyec,proyectoAc);
            if (pos!=1){
                if (horasProyectoAc!=vecProyec[pos].horasEstimadas){
                        desvio=horasProyectoAc-vecProyec[pos].horasEstimadas;
                        printf("El desvio fue de %f \n",desvio);
                }
            else
                printf("No hubo desvio");
            }
            printf("Empleado con mas horas trabajadas en el proyecto: %d con %d \n",empleadoMayor,horasMasTrabajo);
            strcpy(proyectoAc,r.proyecto);
        }
    }
    return 0;
}

void cargarHorasProyectos() {
    personal p;
    FILE *archHorasSemanales, *lote;

    archHorasSemanales = fopen("archSemanales.dat","wb");
    lote = fopen("lote.txt","rt");
    if(lote != NULL) {
	    while(fscanf(lote, "%s %d %d %d", p.proyecto, &p.empleado, &p.semana, &p.horas) == 4){
	       fwrite(&p, sizeof(personal), 1, archHorasSemanales);
	       printf("%s %d %d %d \n", p.proyecto, p.empleado, p.semana, p.horas);
	    }
		fclose(lote);
		fclose(archHorasSemanales);
    } else
        printf("archivo lote.txt no existe!");
}

void cargaProyectos() {
    estimacion r;
    FILE *horasEstimadas, *lote;

    horasEstimadas= fopen("horasEstimadas.dat","wb");
    lote = fopen("proyec.txt","rt");
    if(lote != NULL) {
	    while(fscanf(lote, "%s %d", r.proyecto, &r.horasEstimadas) == 2){
	       fwrite(&r, sizeof(estimacion), 1, horasEstimadas);
	       printf("%s %d  \n",r.proyecto,r.horasEstimadas);
	    }
		fclose(lote);
		fclose(horasEstimadas);
    } else
        printf("archivo lote.txt no existe!");
}

int buscaProyect(estimacion vec[5], char proyecBuscado[5]){
    int i=0;
    while(i<MAX && strcmp(proyecBuscado,vec[i].proyecto)!=0){
        i++;
    }
    if (i<MAX){
        return i;
    }
    else
        return -1;
}
