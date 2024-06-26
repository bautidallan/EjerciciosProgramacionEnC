#include <stdio.h>
#include <string.h>

typedef struct{
    char nroInsc[5];
    char apellido[10];
}asistencia;

typedef struct{
    char nroInsc[5];
    char apellido[10];
    int inasistencias;
}inscriptos;

//Falta armar los cargadores binarios pero esta listo ;

int main(){
    FILE *archInscriptos,*archAsistencia,*actualizado;
    asistencia dia;
    inscriptos reg;
    int cantMaterias,i=0;;
    float ausentismo;
    char vecErroneos[30][10];
    archInscriptos=fopen("archivoInscriptos.dat","rb");
    archAsistencia=fopen("archivoAsistencia.dat","rb");
    actualizado=fopen("actualizado.dat","wb");
    if (archInscriptos!=NULL && archAsistencia!=NULL){
        printf("Ingrese cant materias");
        scanf("%d",cantMaterias);
        ausentismo=(cantMaterias*30)/100;
        fread(&reg,sizeof(inscriptos),1,archInscriptos);
        fread(&dia, sizeof(asistencia),1,archAsistencia);
        while(!feof(archAsistencia)&&!feof(archInscriptos)){

        if(strcmp(reg.apellido,dia.apellido)<0){
            reg.inasistencias+=1;
            if(reg.inasistencias<ausentismo){
                fwrite(&reg,sizeof(inscriptos),1,actualizado);
            }
           fread(&reg,sizeof(inscriptos),1,archInscriptos);
        }
            else if(strcmp(reg.apellido,dia.apellido)>0){
                strcpy(vecErroneos[i],dia.apellido);
                i++;
                fread(&dia,sizeof(asistencia),1,archAsistencia);
        }
        else{
             if (reg.inasistencias<ausentismo){
                fwrite(&reg,sizeof(inscriptos),1,actualizado);
             }
             fread(&reg,sizeof(inscriptos),1,archInscriptos);
             fread(&dia,sizeof(asistencia),1,archAsistencia);
        }

    }
    }
    else{
        printf("Error al abrir archivos binarios");
    }
    return 0;
}
