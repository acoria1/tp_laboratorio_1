#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "ac_getFunciones.h"
#include "menus.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee,int* ID)
{
    int status = 0;
    FILE* pArchivo;
    FILE* pUltimoID;
    int auxID,n;

    if ((pArchivo = fopen(path,"r")) == NULL)
    {
        printf("\nEl archivo no puede abrirse");
    }
    else
    {
        int stat = parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        if( stat ==0)
        {
            printf("\nError al leer encabezados...\n");
        }
        else if (stat == -1)
        {
            printf("\nError al guardar empleados en memoria...\n");
        }
        else
        {
            pUltimoID = fopen("ultimoID.csv","r");
            if (pUltimoID != NULL)
            {
                n = fscanf(pUltimoID,"%d",&auxID);
                if (n == 1)
                {
                    *ID = auxID;
                    printf("\nEmpleados cargados con exito\n");
                    status++;
                }
            }
        }
    }
    fclose(pArchivo);
    fclose(pUltimoID);

    return status;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee,int* ID)
{
    int status = 0;
    FILE* pArchivo;
    FILE* pUltimoID;
    int auxID,n;

    if ((pArchivo = fopen(path,"rb")) == NULL)
    {
        printf("\nEl archivo no puede abrirse");
    }
    else
    {
        int stat = parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);

        if( stat ==-1)
        {
            printf("\nError al guardar empleados en memoria...\n");
        }
        else
        {
            pUltimoID = fopen("ultimoID.csv","r");
            if (pUltimoID != NULL)
            {
                n = fscanf(pUltimoID,"%d",&auxID);
                if (n == 1)
                {
                    *ID = auxID;
                    printf("\nEmpleados cargados con exito\n");
                    status++;
                }
            }
        }
    }
    fclose(pArchivo);
    fclose(pUltimoID);

    return status;
}

int controller_addEmployee(LinkedList* pArrayListEmployee,int* IdUnico)
{
    char auxNom[50];
    char auxId[10];
    char auxHoras [5];
    char auxSueldo[10];
    int auxS,auxH,id;
    int stat = 0;

    system("cls");
    menu_EncabezadoDeMenu("ALTA DE EMPLEADO");
    if (ac_getString(auxNom,49,2,"Ingrese nombre del empleado: ")==1)
    {
        if (ac_getInt(&auxS,0,1000000,"Ingrese salario: ",2)== 1)
        {
            if (ac_getInt(&auxH,0,10000,"Ingrese horas trabajadas: ",2)== 1)
            {
                normalizeString(auxNom);
                stat = 1;
                *IdUnico = *IdUnico +1;
                id = *IdUnico;

                sprintf(auxId,"%d",id);
                sprintf(auxHoras,"%d",auxH);
                sprintf(auxSueldo,"%d",auxS);
                ll_add(pArrayListEmployee,employee_newParametros(auxId,auxNom,auxHoras,auxSueldo));

                printf("\nEmpleado guardado con exito. ID del empleado: %d\n",id);
                stat = 1;
            }
        }
    }
    if (stat == 0)
    {
        printf("\nError al cargar empleado...\n");
    }

    return stat;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int auxID,auxS,auxH;
    int opcion = 0;
    Employee* p;
    char auxNom[50];
    int status = 0;

    system("cls");
    menu_EncabezadoDeMenu("MODIFICACION DE EMPLEADO");

    ac_getInt(&auxID,0,100000,"Ingrese ID de empleado a modificar: ",2);
    p = employee_GetEmployeeByID(auxID,pArrayListEmployee);

    if (p == NULL)
    {
        printf("\nEl ID ingresado no corresponde a un empleado en nuestro sistema.\n");
    }
    else
    {
        do
        {
            system("cls");
            menu_EncabezadoDeMenu("MODIFICACION DE EMPLEADO");

            employee_MostrarEncabezados();
            employee_MostrarSolo(p);

            opcion = menuEditEmployee();

            switch (opcion)
            {
            case 1:
                if (ac_getString(auxNom,49,2,"Ingrese nuevo nombre del empleado: ")==1)
                {
                    normalizeString(auxNom);
                    employee_setNombre(p,auxNom);
                    status = 1;
                }
                break;
            case 2:
                if (ac_getInt(&auxS,0,1000000,"Ingrese nuevo salario: ",2)== 1)
                {
                    employee_setSueldo(p,auxS);
                    status = 1;
                }
                break;
            case 3:
                if (ac_getInt(&auxH,0,10000,"Ingrese horas trabajadas: ",2)== 1)
                {
                    employee_setHorasTrabajadas(p,auxH);
                    status = 1;
                }
                break;
            }
        }
        while (opcion < 4 && opcion>0 );
    }

    return status;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxID,aux;
    char confirmar = 'n';
    Employee* p;
    int status = 0;

    system("cls");
    menu_EncabezadoDeMenu("BAJA DE EMPLEADO");

    ac_getInt(&auxID,0,100000,"Ingrese ID de empleado a eliminar: ",2);
    p = employee_GetEmployeeByID(auxID,pArrayListEmployee);

    if (p == NULL)
    {
        printf("\nEl ID ingresado no corresponde a un empleado en nuestro sistema.\n\n");
    }
    else
    {
        printf("\n");
        employee_MostrarEncabezados();
        employee_MostrarSolo(p);

        ac_getChar(&confirmar,"\nConfirmar baja del empleado (y/n):",'y','Y','n','N','n',1);
        if (confirmar != 'y' && confirmar != 'Y')
        {
            printf("\nBaja cancelada...\n\n");
        }
        else
        {
            aux = ll_indexOf(pArrayListEmployee,p);
            ll_remove(pArrayListEmployee,aux);
            printf("\nEmpleado eliminado con exito.\n\n");
            status = 1;
        }
    }

    return status;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int len;

    if (pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        if (len == 0)
        {
            printf("\nNo hay empleados que mostrar\n");
        }
        else
        {
            system("cls");
            employee_MostrarEncabezados();
            printf("\n");
            employee_MostrarTodos(len,pArrayListEmployee);
            status = 1;
        }
    }
    else
    {
        printf("\nError al mostrar empleados...\n");
    }
    return status;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    menu_EncabezadoDeMenu("ORDENAMIENTOS");
    int opcion = menuSort();
    int opcion2;
    int status = 0;
    if (opcion > 0 && opcion <5)
    {
        printf("\n\nCriterio:\n1. Descendiente\n2. Ascendiente\n");
        if(ac_getInt(&opcion2,1,2,"Ingrese opcion:",2)==1)
        {
            opcion2--;
            switch (opcion)
            {
            case 1:
                if(ll_sort(pArrayListEmployee,employee_CompareById,opcion2)== 0)
                {
                    status = 1;
                    printf("\nEmpleados ordenados con exito\n");
                }
                else
                {
                    printf("\nError al ordenar empleados\n");
                }
                break;
            case 2:
                if(ll_sort(pArrayListEmployee,employee_CompareByName,opcion2)== 0)
                {
                    status = 1;
                    printf("\nEmpleados ordenados con exito\n");
                }
                else
                {
                    printf("\nError al ordenar empleados\n");
                }
                break;
            case 3:
                if(ll_sort(pArrayListEmployee,employee_CompareByHours,opcion2)== 0)
                {
                    status = 1;
                    printf("\nEmpleados ordenados con exito\n");
                }
                else
                {
                    printf("\nError al ordenar empleados\n");
                }
                break;
            case 4:
                if(ll_sort(pArrayListEmployee,employee_CompareBySalary,opcion2)== 0)
                {
                    status = 1;
                    printf("\nEmpleados ordenados con exito\n");
                }
                else
                {
                    printf("\nError al ordenar empleados\n");
                }
                break;
            }
        }
    }
    else if (opcion == 0)
    {
        printf("\nModificacion cancelada...\n");
    }
    return status;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee,int* ID)
{
    FILE* pVec;
    FILE* pArchivoID;
    Employee* pEmp;
    int id,horas,salario;
    char nombre[50];
    int len = ll_len(pArrayListEmployee);
    int status = 0;

    pVec = fopen(path,"w");
    pArchivoID = fopen("ultimoID.csv","w");
    printf("1");
    if (pVec != NULL && pArchivoID != NULL)
    {
         printf("2");
        fprintf(pVec,"ID,Nombre,HorasTrabajadas,Sueldo\n");
        for (int i = 0; i< len; i++)
        {
            pEmp = ll_get(pArrayListEmployee,i);
            employee_GetEverything(pEmp,&id,&horas,&salario,nombre);
            printf("3");
            if (i != len-1)
            {
                fprintf(pVec,"%d,%s,%d,%d\n",id,nombre,horas,salario);
                printf("4");
            }
            else
            {
                fprintf(pVec,"%d,%s,%d,%d",id,nombre,horas,salario);
                printf("5");
            }
        }
        printf("ID: %d",*ID);
        fprintf(pArchivoID,"%d",*ID);
        printf("\nEmpleados guardados con exito en %s\n\n",path);
        status = 1;
    }
    fclose(pVec);
    fclose(pArchivoID);
    return status;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee,int *ID)
{
    FILE* pVec;
    FILE* pArchivoID;
    Employee* pEmp;
    int status = 0;

    int len = ll_len(pArrayListEmployee);
    pVec = fopen(path,"wb");
    pArchivoID = fopen("ultimoID.csv","w");

    if (pVec != NULL && pArchivoID != NULL)
    {
        for (int i = 0; i< len; i++)
        {
            pEmp = ll_get(pArrayListEmployee,i);
            fwrite(pEmp,sizeof(Employee),1,pVec);

        }
        printf("ID: %d",*ID);
        fprintf(pArchivoID,"%d",*ID);
        printf("\nEmpleados guardados con exito en %s\n\n",path);
        status = 1;

    }
    fclose(pVec);
    fclose(pArchivoID);
    return status;
}





