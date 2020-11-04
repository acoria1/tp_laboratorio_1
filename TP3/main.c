#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menus.h"
#include "ac_getFunciones.h"

/****************************************************
    CORIA AGUSTIN, 1C

    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* myList;
    myList = ll_newLinkedList();

    int opcion;
    int control = 0;
    int salir = 0;
    int ID = 0;
    char confirmar = 'y';

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            if (control == 0)
            {
                control += controller_loadFromText("data.csv",myList,&ID);
                salir = 1;
            }
            else
            {
                printf("\nYa hay empleados cargados en el sistema!\n");
            }
            break;
        case 2:
            if (control == 0)
            {
                control += controller_loadFromBinary("data.bin",myList,&ID);
                salir = 1;
            }
            else
            {
                printf("\nYa hay empleados cargados en el sistema!\n");
            }
            break;
        case 3:
            if (controller_addEmployee(myList,&ID)==1){
                salir = 1;
            }
            break;
        case 4:
            if (control +=controller_editEmployee(myList)==1){
            salir = 1;
            }
            break;
        case 5:
            if (control+=controller_removeEmployee(myList)==1){
            salir = 1;
            }
            break;
        case 6:
            controller_ListEmployee(myList);
            break;
        case 7:
            controller_sortEmployee(myList);
            break;
        case 8:
            if (controller_saveAsText("data.csv",myList)==1){
            salir = 0;
            }
            break;
        case 9:
            if (controller_saveAsBinary("data.bin",myList)==1){
            salir = 0;
            }
            break;
        }
        if (opcion != 10 && opcion != 0)
        {
            system("pause");
        }

        system("cls");
    }
    while (opcion != 10 && opcion != 0);

    ll_deleteLinkedList(myList);

    return 0;
}



