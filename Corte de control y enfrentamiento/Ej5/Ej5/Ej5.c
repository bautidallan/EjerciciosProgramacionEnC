#include <stdio.h>
#include <string.h>
#define MAX 20
typedef struct {
   char codEspecie[5];
   float toneladas;
}cupos;
typedef struct {
    char empresa[5];
    cupos vec[3];
}empresas;

typedef struct{
    char codEmpresa[5];
    char codBarco[5];
    cupos capturas[2];
}pescas;

typedef struct{
    char codEmpresa[5];
    cupos datos;
}multas;

int main(){
    FILE *secretariaPesca,*capturas,*Multas;
    empresas reg;
    pescas dataPesc;
    multas multa;
    int i;
    secretariaPesca=fopen("cupos.dat","rb");
    capturas=fopen("capturas.dat","rb");
    Multas=fopen("multas.dat","wb");
    if (secretariaPesca!=NULL && capturas!=NULL){
        fread(&reg,sizeof(empresas),1,secretariaPesca);
        fread(&dataPesc,sizeof(pescas),1,capturas);
        while(!feof(secretariaPesca)&& !feof(capturas)){
            while(!feof(secretariaPesca)&& !feof(capturas) && strcmp(reg.empresa,dataPesc.codEmpresa)){
                for(i=0;i<3;i++){
                    if(strcmp(reg.vec[i].codEspecie,dataPesc.capturas[i].codEspecie)==0){
                            if(dataPesc.capturas[i].toneladas>reg.vec[i].toneladas){
                                strcpy(multa.codEmpresa,dataPesc.codEmpresa);
                                strcpy(multa.datos.codEspecie,dataPesc.capturas[i].codEspecie);
                                multa.datos.toneladas=dataPesc.capturas[i].toneladas;
                            }

                    }
                }
            }
        }
    }
    return 0;
}
