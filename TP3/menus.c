#include <stdio.h>
#include <stdlib.h>
#include "ac_getFunciones.h"
#include <string.h>
#include "menus.h"


int menuSort ()
{
    int opcion = 0;

    printf("1. ID\n");
    printf("2. Nombre\n");
    printf("3. Horas Trabajadas\n");
    printf("4. Sueldo\n");
    printf("5. Cancelar\n");

    ac_getInt(&opcion,1,5,"\nOrdenar por:",2);

    return opcion;
}

int menu()
{
    int a = 0;

    menu_EncabezadoDeMenu("MENU PRINCIPAL");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n");

    ac_getInt(&a,1,10,"Ingrese opcion: ",2);

    return a;
}

int menuEditEmployee ()
{
    int opcion = 0;

    printf("\n\nQue desea modificar?\n");
    printf("1. Nombre\n");
    printf("2. Salario\n");
    printf("3. Horas Trabajadas\n");
    printf("4. Salir\n\n");

    ac_getInt(&opcion,1,4,"Ingrese opcion: ",2);
    return opcion;
}

void menu_EncabezadoDeMenu (const char*  mensaje)
{
    printf("----------------------------------------    %s   -------------------------------------------\n\n",mensaje);
}


void normalizeString (char* a)
{
    strlwr(a);
    *(a+0) = toupper(*(a+0));

    for (int j=0; *(a+j)!= '\0'; j++)
    {
        if (*(a+j)== ' ')
        {
            *(a+j+1) = toupper(*(a+j+1));
        }
    }
}
