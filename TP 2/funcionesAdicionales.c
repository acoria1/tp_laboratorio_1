#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funcionesAdicionales.h"

int menu()
{
    int opcion = 5;

    system("cls");
    printf("****Gestion de empleados****\n\n");
    printf("1- Nuevo empleado \n");
    printf("2- Modificar empleado \n");
    printf("3- Baja empleado \n");
    printf("4- Informes \n");
    printf("5- Salir \n");

    ac_getInt(&opcion,1,5,"Ingrese opcion: ",3);
    return opcion;
}

void normalizeString (char a[])
{
    strlwr(a);
    a[0] = toupper(a[0]);
    for (int j=0; a[j]!= '\0'; j++)
    {
        if (a[j]== ' ')
        {
            a[j+1] = toupper(a[j + 1]);
        }
    }

}

