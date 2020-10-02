#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "empleado.h"
#include "ac_getFunciones.h"
#include "funcionesAdicionales.h"

void inicializarEmpleados (e_Empleado list[],int size)
{
    for (int i = 0; i<size; i++)
    {
        list[i].isFull = 0;
    }
}


int getEmptySlot (e_Empleado listita[],int size)
{
    int lugar = -1;
    int flag = 0;
    for (int i = 0; i<size && flag == 0; i++)
    {
        if (listita[i].isFull == 0)
        {
            lugar = i;
            flag = 1;
        }
    }
    return lugar;
}

int getEmpleado (e_Empleado x[],int size,int idOrigen,e_Sector sectores[],int sizeSect)
{
    system("cls");
    int i = getEmptySlot(x,size);
    int todoBien = 0;
    if (i != -1)
    {
        printf("****ALTA DE EMPLEADO****\n");
//
        x[i].id = idOrigen;
        do
        {
            if (ac_getString(x[i].nombre,51,5,"\nIngrese nombre de empleado: ") == -1)
            {
                break;
            }
            if (ac_getString(x[i].apellido,51,5,"\nIngrese apellido de empleado: ") == -1)
            {
                break;
            }
            normalizeString( x[i].apellido);
            normalizeString( x[i].nombre);

            if (ac_getFloat(&x[i].sueldo,1000,10000000,"\nIngrese sueldo del empleado: ($1.000 - $10.000.000)",3) == -1)
            {
                break;
            }

            printf("\nIngrese sector del empleado (1-%d)\n",sizeSect);
            for (int j = 0; j<sizeSect; j++)
            {
                printf("%d-%s\n",j+1,sectores[j].descripcion);
            } // mostrar sectores
            if(ac_getInt(&x[i].idSector,1,sizeSect,"\n",3)== -1)
            {
                break;
            }
            x[i].isFull = 1;
            printf("\nAlta de empleado realizada con exito. ID del empleado: %d \n\n",x[i].id);
            todoBien = 1;
            system("pause");
        }
        while (todoBien == 0);
    }
    else
    {
        printf("\nNo hay lugar disponible.\n");
        system("pause");
    }
    return todoBien;
}

int buscarEmpleado (int id,e_Empleado listita[],int size)
{
    int lugar = -1;
    for (int i= 0; i<size; i++)
    {
        if (listita[i].id == id && listita[i].isFull == 1)
        {
            lugar = i;
            break;
        }
    }
    return lugar;
}

void mostrarEmpleados(e_Empleado list[],int size,e_Sector sectores[],int sizeSect)
{
    int flag = 0;
    printf("****LISTA DE EMPLEADOS****\n\n");
    printf("  Sector            ID              Apellido             Nombre          Salario \n");

    for (int i = 0; i<size; i++)
    {
        if (list[i].isFull == 1)
        {
            flag = 1;
            printf("%15s     %4d  %20s %20s     %10.2f \n",sectores[list[i].idSector-1].descripcion,list[i].id,list[i].apellido,list[i].nombre,list[i].sueldo);
        }
    }
    printf("\n");
    if (flag == 0)
    {
        printf("No hay empleados que mostrar\n");
    }
    system("pause");
}
void mostrarPrimerEmpleado (e_Empleado x,e_Sector sectores[],int sizeSect)
{
    printf("ID                  Apellido       Nombre    Salario               Sector \n");
    printf("%4d  %20s %20s  %10.2f     %15s \n",x.id,x.apellido,x.nombre,x.sueldo,sectores[x.idSector-1].descripcion);
}
void mostrarEmpleado (e_Empleado x,e_Sector sectores[],int sizeSect)
{
    printf("%4d  %20s %20s  %10.2f     %15s \n",x.id,x.apellido,x.nombre,x.sueldo,sectores[x.idSector-1].descripcion);
}

void modificarEmpleado (e_Empleado vec[],int size,e_Sector sectores[],int sizeSect)
{
    int aux;
    int indiceEmpBaja;
    int opcion;
    system("cls");
    printf("****MODIFICACION DE EMPLEADO****\n");
    ac_getInt(&aux,0,9999,"\nIngrese ID del empleado a modificar (xxxx)",5);
    indiceEmpBaja = buscarEmpleado(aux,vec,size);
    if ( indiceEmpBaja == -1)
    {
        printf("\nEl empleado que desea modificar no existe.\n");
        system("pause");
    }
    else
    {
        do
        {
            system("cls");
            printf("Datos de empleado\n");
            mostrarEmpleado(vec[indiceEmpBaja],sectores,sizeSect);
            printf("\nDato a modificar:\n");
            printf("1-Nombre\n");
            printf("2-Apellido\n");
            printf("3-Sueldo\n");
            printf("4-Sector\n");
            printf("5-Volver a menu principal\n");

            if (ac_getInt(&opcion,1,5,"\nOpcion: ",3)==-1)
            {
                break;
            }

            switch (opcion)
            {
            case 1:
                if (ac_getString(vec[indiceEmpBaja].nombre,20,3,"\nIngrese nuevo nombre del empleado: ") == -1)
                {
                    break;
                }
                normalizeString(vec[indiceEmpBaja].nombre);
                printf("\nModificacion realizada con exito\n\n");
                break;
            case 2:
                if (ac_getString(vec[indiceEmpBaja].apellido,20,3,"\nIngrese nuevo apellido del empleado: ") == -1)
                {
                    break;
                }
                normalizeString(vec[indiceEmpBaja].apellido);
                printf("\nModificacion realizada con exito\n\n");
                break;
            case 3:
                if (ac_getFloat(&vec[indiceEmpBaja].sueldo,1000,10000000,"\nIngrese nuevo sueldo del empleado: ",3)==-1)
                {
                    break;
                }
                printf("\nModificacion realizada con exito\n\n");
                break;

            case 4:
                printf("\nIngrese nuevo sector del empleado (1-%d)\n",sizeSect);
                for (int j = 0; j<sizeSect; j++)
                {
                    printf("%d-%s\n",j+1,sectores[j].descripcion);
                } // mostrar sectores
                if(ac_getInt(&vec[indiceEmpBaja].idSector,1,sizeSect,"\n",3)== -1)
                {
                    break;
                }
                printf("\nModificacion realizada con exito\n\n");
                break;
            }
            if (opcion != 5){
            system("pause");
            }
        }
        while (opcion != 5);
    }

}

void eliminarEmpleado (e_Empleado vec[],int size,e_Sector sectores[],int sizeSect)
{
    int aux;
    int indiceEmpBaja;
    char confirmar;
    system("cls");
    printf("****BAJA DE EMPLEADO****\n");
    ac_getInt(&aux,0,9999,"Ingrese ID del empleado a dar de baja (xxxx)",5);
    indiceEmpBaja = buscarEmpleado(aux,vec,size);
    if ( indiceEmpBaja == -1)
    {
        printf("\nEl empleado que desea dar de baja no existe.\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("Datos de empleado\n");
        mostrarEmpleado(vec[indiceEmpBaja],sectores,sizeSect);
        printf("\nSeguro que desea continuar? Se perderan todos los datos del empleado. (y/n)\n");
        fflush(stdin);
        scanf("%c",&confirmar);
        if (confirmar == 'y')
        {
            vec[indiceEmpBaja].isFull = 0;
            printf("\nBaja de empleado realizada con exito. \n\n");
            system("pause");
        }
        else
        {
            printf("\nBaja cancelada\n\n");
            system("pause");
        }
    }

}

void ordenarListadoSAN (e_Empleado vec[],int size)
{
    e_Empleado aux;

    for (int i= 0; i<size-1; i++)
    {
        for (int j = i+1; j<size; j++)
        {
            if (vec[i].idSector>vec[j].idSector)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
            else if (vec[i].idSector == vec[j].idSector && strcmp(vec[i].apellido,vec[j].apellido)>0)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
            else if (vec[i].idSector == vec[j].idSector && strcmp(vec[i].apellido,vec[j].apellido) == 0 &&strcmp(vec[i].nombre,vec[j].nombre)>0)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }

    }
}

void informarSueldos (e_Empleado vec[],int size)
{
    float total;
    float promedio;
    int contador = 0;
    for (int i = 0; i<size; i++)
    {
        if (vec[i].isFull == 1)
        {
            total += vec[i].sueldo;
            contador++;
        }
    }
    promedio = total / contador;
    contador = 0;
    for (int i = 0; i<size; i++)
    {
        if (vec[i].sueldo>promedio && vec[i].isFull == 1)
        {
            contador++;
        }
    }
    printf("***SALARIOS***\n");
    printf("\nTotal de salarios de la empresa: $ %.2f\n",total);
    printf("\nSalario promedio: $ %10.2f\n",promedio);
    printf("\nCantidad de empleados cuyo salario es mayor al promedio: %d\n\n\n",contador);
    system("pause");
}

int hayEmpleados (e_Empleado vec[],int size){
int a = -1;
for (int i = 0;i<size;i++){
    if (vec[i].isFull == 1){
    a = 1;
    break;
    }
}
return a;
}


