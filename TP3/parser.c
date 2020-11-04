#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int status = 0;
    int r = 0;
    char datos[4][100];
    char encabezados[4][50];
    Employee* auxEmpleado;

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",encabezados[0],encabezados[1],encabezados[2],encabezados[3]);

    if(r==4)
    {
        do
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",datos[0],datos[1],datos[2],datos[3]);
            if(r==4)
            {
                auxEmpleado = employee_newParametros(datos[0],datos[1],datos[2],datos[3]);
                if (auxEmpleado !=NULL )
                {
                    ll_add(pArrayListEmployee,auxEmpleado);
                }
            }
            else
            {
                status = -1;
                break;
            }
        }
        while(!feof(pFile));
        status = 1;
    }

    return status;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int stat = 1;
    Employee* auxEmpleado;

    do
    {
        auxEmpleado =  employee_new();

        if (auxEmpleado !=NULL )
        {
            fread(auxEmpleado,sizeof(Employee),1,pFile);
            if (feof(pFile))
            {
                break;
            }
            ll_add(pArrayListEmployee,auxEmpleado);
        }
        else
        {
            stat = -1;
            break;
        }
    }
    while(!feof(pFile));

    return stat;
}
