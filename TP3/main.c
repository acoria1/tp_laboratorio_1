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
    int control2 = 0;
    int ID = 0;
    char confirmar = 'n';

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            if (control == 0)
            {
                control += controller_loadFromText("data.csv",myList,&ID);
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
            }
            else
            {
                printf("\nYa hay empleados cargados en el sistema!\n");
            }
            break;
        case 3:
            control += controller_addEmployee(myList,&ID);
            break;
        case 4:
            controller_editEmployee(myList);
            break;
        case 5:
            controller_removeEmployee(myList);
            break;
        case 6:
            controller_ListEmployee(myList);
            break;
        case 7:
            controller_sortEmployee(myList);
            break;
        case 8:
            if (controller_saveAsText("data.csv",myList)==1){
            control2 = 1;
            }
            break;
        case 9:
            if (controller_saveAsBinary("data.bin",myList)==1){
            control2 = 1;
            }
            break;
        }
        if (opcion != 10 && opcion != 0)
        {
            system("pause");
        }
        else if (control2 == 0 && control > 0)
        {
            ac_getChar(&confirmar,"\nAun no se han guardado los cambios efectuados. \nSeguro que desea salir? (y/n): ",'y','Y','n','N','N',1);
            if (confirmar == 'n' || confirmar == 'N')
            {
                opcion = 0;
            }
        }
        system("cls");
    }
    while (opcion != 10 && opcion != 0);

    ll_deleteLinkedList(myList);

    return 0;
}



