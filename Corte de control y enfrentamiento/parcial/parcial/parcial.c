#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct{
    unsigned int codProducto;
    char descripcion[30];
    char rubro;
    float precio;
}tipoProducto;

typedef struct{
    char periodo[7];
    unsigned int dia;
    unsigned int codigo;
    float cantidad;
}tipoVentas;

int devuelvePos(tipoProducto vec[],unsigned int codBuscado);

int main(){
    FILE *archVentas,*archProductos;
    tipoProducto p;
    tipoVentas v;
    int i,mayorDia,pos,ventasP,ventasO,ventasM;
    unsigned int codActual,codMenor;
    tipoProducto vecProductos[MAX];
    float totalProducto,precio,productoMenorVenta,ventaMayor;
    char periodoAc[7];
    archVentas=fopen("ventas.dat","rb");
    archProductos=fopen("productos.dat","rb");
    if(archProductos!=NULL){
        i=0;
        fread(&p,sizeof(tipoProducto),1,archProductos);
        while(!feof(archProductos)){
            vecProductos[i].codProducto=p.codProducto;
            strcpy(vecProductos[i].descripcion,p.descripcion);
            vecProductos[i].rubro=p.rubro;vecProductos[i].precio=p.precio;
            i++;
            fread(&p,sizeof(tipoProducto),1,archProductos);
        }
        fclose(archProductos);
    }
    if(archVentas!=NULL){
            fread(&v,sizeof(tipoVentas),1,archVentas);
            while(!feof(archVentas)){
                strcpy(periodoAc,v.periodo);
                printf("Periodo : %s",periodoAc);
                productoMenorVenta=0;
                ventasP=0;
                ventasM=0;
                ventasO=0;
                while(!feof(archVentas)&& strcmp(periodoAc,v.periodo)==0){
                    totalProducto=0;
                    ventaMayor=0;
                    mayorDia=0;
                    codActual=v.codigo;
                    while(!feof(archVentas)&& strcmp(periodoAc,v.periodo)==0 && codActual==v.codigo){
                            pos=devuelvePos(vecProductos,v.codigo);
                            precio=v.cantidad*vecProductos[i].precio;
                            totalProducto+=precio;
                            if (precio>ventaMayor){
                                ventaMayor=precio;
                                mayorDia=v.dia;
                            }
                            if(vecProductos[pos].rubro=='P'){
                                ventasP++;
                            }
                            else if(vecProductos[pos].rubro=='M'){
                                ventasM++;
                            }
                            else{
                                ventasO++;
                            }
                            fread(&v,sizeof(tipoVentas),1,archVentas);
                    }
                    if(totalProducto<productoMenorVenta){
                        productoMenorVenta=totalProducto;
                        codMenor=codActual;

                    }
                    printf("Desc.Producto \t Total Vendido \t Venta Mayor cantidad \n");
                    printf("%s \t %f \t %f (Dia: %d)\n",vecProductos[pos].descripcion,totalProducto,ventaMayor,mayorDia);
                }
                pos=devuelvePos(vecProductos,codMenor);
                printf("Producto con menor venta total: %s " vecProductos[pos].descripcion);
                if (ventasM>ventasO){
                    if(ventasM>ventasP){
                        printf("El rubro mas vendido es Mariscos");
                    }
                }
                else if(ventasO>ventasP){
                    printf("El rubro mas vendido es Otros");
                }

            }

    }


    return 0;
}

int devuelvePos(tipoProducto vec[],unsigned int codBuscado){
    int i=0;
    while (i<MAX && codBuscado!=vec[i].codProducto){
        i++;
    }
    return i;

}
