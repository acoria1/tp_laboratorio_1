#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ac_getFunciones.h"
#include "sector.h"
#include "empleado.h"
#include "funcionesAdicionales.h"


#define TAMSEC 5
#define TAM 1000


int main()
{
    e_Empleado listaDeEmpleados[TAM];
    e_Sector sectores [TAMSEC] = {{1,"Sistemas"},{2,"RRHH"},{3,"Ventas"},{4,"Compras"},{5,"Contabilidad"}};

    int opcion;
    int idOrigen = 1000;
    int opcionInformes;

    inicializarEmpleados(listaDeEmpleados,TAM);

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            idOrigen += getEmpleado(listaDeEmpleados,TAM,idOrigen,sectores,TAMSEC);
            break;
        case 2:
            if (hayEmpleados(listaDeEmpleados,TAM)> 0){
            modificarEmpleado(listaDeEmpleados,TAM,sectores,TAMSEC);
        } else {
            printf("\nNo hay empleados cargados en el sistema.\n");
            system ("pause");
        }
            break;
        case 3:
            if (hayEmpleados(listaDeEmpleados,TAM)> 0){
            eliminarEmpleado(listaDeEmpleados,TAM,sectores,TAMSEC);
            } else {
            printf("\nNo hay empleados cargados en el sistema.\n");
            system ("pause");
        }
            break;
        case 4:
            if (hayEmpleados(listaDeEmpleados,TAM)> 0){
            ordenarListadoSAN(listaDeEmpleados,TAM);
            do
            {
                system("cls");
                printf("*** INFORMES ***\n\n");
                printf("1- Listado de empleados \n");
                printf("2- Salarios \n");
                printf("3- Volver a menu principal\n\n");
                if (ac_getInt(&opcionInformes,1,3,"Ingrese opcion: ",3) == -1)
                {
                    break;
                }
                if (opcionInformes  == 1)
                {
                    system("cls");
                    mostrarEmpleados(listaDeEmpleados,TAM,sectores,TAMSEC);
                }
                if (opcionInformes == 2)
                {
                    system("cls");
                    informarSueldos(listaDeEmpleados,TAM);
                }
            } while (opcionInformes != 3);
        }  else {
            printf("\nNo hay empleados cargados en el sistema.\n");
            system ("pause");
        }
        }
    }
    while (opcion != 5);
    return 0;
}

