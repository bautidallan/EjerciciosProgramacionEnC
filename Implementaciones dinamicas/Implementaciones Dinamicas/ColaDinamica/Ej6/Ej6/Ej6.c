#include <stdio.h>
#include "tdacolad.h"

void cargarColaDesdeArchivo(TCOLA *cola);

int main(){
	int acumuDemoras=0,demora=0,cantSolicitudes=0,tiempoInicial;
	TCOLA cola;
	TELEMENTOC elem;
	iniciac(&cola);
	cargarColaDesdeArchivo(&cola);
	consultac(cola,&elem);
	printf("%d",elem.solicitado);
	tiempoInicial=elem.solicitado+elem.duracion ;
	while(!vaciac(cola))
    {
        printf("Final a los %d \n",tiempoInicial);
        if (demora>0){
            printf("La demora fue de %d \n",demora);
        }
        sacac(&cola,&elem);
        consultac(cola,&elem);
        demora=tiempoInicial-elem.solicitado;
        acumuDemoras=demora+acumuDemoras;
        cantSolicitudes++;
        tiempoInicial=tiempoInicial+elem.duracion;
    }
    printf("El tiempo de espera promedio fue de %f \n",(acumuDemoras/cantSolicitudes));
	return 0;
}

void cargarColaDesdeArchivo(TCOLA *cola)
    {
    FILE *archivo = fopen("solicitudes.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        }
    else
    {
    TELEMENTOC registro;
    while (fscanf(archivo,"% d% d% d", &registro.id, &registro.solicitado, &registro.duracion) == 3)
        {
        ponec(cola,registro);
        }
    }
    fclose(archivo);
    }
