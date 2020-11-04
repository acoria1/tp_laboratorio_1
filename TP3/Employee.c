#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include <string.h>
#include "LinkedList.h"
#include "ac_getFunciones.h"

Employee* employee_new()
{
    Employee* p;

    p = (Employee*) malloc (sizeof(Employee));

    return p;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* p = employee_new();
    int auxId,auxSueldo,auxHoras;
    int todoOk = 0;

    auxId = atoi(idStr);
    auxSueldo = atoi(sueldoStr);
    auxHoras = atoi(horasTrabajadasStr);

    if (p != NULL)
    {
        if (auxHoras == 0 && strcmp(horasTrabajadasStr,"0")!= 0)
        {
            auxHoras = -1;
        }
        if (auxSueldo == 0 && strcmp(sueldoStr,"0")!= 0)
        {
            auxSueldo = -1;
        }
        if (employee_setId(p,auxId)== 1)
        {
            if (employee_setHorasTrabajadas(p,auxHoras)== 1)
            {
                if (employee_setSueldo(p,auxSueldo)== 1)
                {
                    if (employee_setNombre(p,nombreStr)== 1)
                    {
                        todoOk = 1;
                    }
                }
            }
        }
    }

    if (todoOk == 0)
    {
        p = NULL;
    }
    return p;
}


void employee_delete(Employee* e)
{
    if (e != NULL)
    {
        free(e);
    }
}

int employee_setId(Employee* this,int id)
{
    int status= 0;

    if (this!= NULL)
    {
        if (id > 0)
        {
            this->id = id;
            status  = 1;
        }
    }
    return status;
}

int employee_getId(Employee* this,int* id)
{
    int status = 0;

    if (this!= NULL && id != NULL)
    {
        *id = this->id;
        status = 1;
    }
    return status;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int status= 0;

    if (this!= NULL)
    {
        if (strlen(nombre)<128)
        {
            strcpy(this->nombre,nombre);
            status  = 1;
        }
    }
    return status;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int status = 0;

    if (this!= NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        status = 1;
    }
    return status;


}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int status= 0;

    if (this!= NULL)
    {
        if (horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            status  = 1;
        }
    }
    return status;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int status = 0;

    if (this!= NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        status = 1;
    }
    return status;

}

int employee_setSueldo(Employee* this,int sueldo)
{
    int status= 0;

    if (this!= NULL)
    {
        if (sueldo >= 0)
        {
            this->sueldo = sueldo;
            status  = 1;
        }
    }
    return status;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int status = 0;

    if (this!= NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        status = 1;
    }
    return status;
}


int employee_CompareByName(void* e1, void* e2)
{
    Employee* emp1 = (Employee*) e1;
    Employee* emp2 = (Employee*) e2;
    char nom1[50];
    char nom2[50];

    employee_getNombre(emp1,nom1);
    employee_getNombre(emp2,nom2);

    return strcmp(nom1,nom2);
}

int employee_CompareById(void* e1, void* e2)
{
    int status = 0;
    int first;
    int second;

    Employee* emp1 = (Employee*) e1;
    Employee* emp2 = (Employee*) e2;

    employee_getId(emp1,&first);
    employee_getId(emp2,&second);

    if (first > second)
    {
        status = 1;
    }
    else if (first < second)
    {
        status = -1;
    }
    return status;
}

int employee_CompareByHours(void* e1, void* e2)
{
    int status = 0;
    int first;
    int second;

    Employee* emp1 = (Employee*) e1;
    Employee* emp2 = (Employee*) e2;

    employee_getHorasTrabajadas(emp1,&first);
    employee_getHorasTrabajadas(emp2,&second);

    if (first > second)
    {
        status = 1;
    }
    else if (first < second)
    {
        status = -1;
    }
    return status;
}

int employee_CompareBySalary(void* e1, void* e2)
{
    int status = 0;
    int first;
    int second;

    Employee* emp1 = (Employee*) e1;
    Employee* emp2 = (Employee*) e2;

    employee_getSueldo(emp1,&first);
    employee_getSueldo(emp2,&second);

    if (first > second)
    {
        status = 1;
    }
    else if (first < second)
    {
        status = -1;
    }
    return status;
}

Employee* employee_GetEmployeeByID (int id,LinkedList* pArrayLinkedList)
{
    Employee* p = NULL;

    if (pArrayLinkedList != NULL)
    {
        int len = ll_len(pArrayLinkedList);
        Employee* aux;
        int auxId;

        for (int i= 0; i<len; i++)
        {
            aux = (Employee*)ll_get(pArrayLinkedList,i);
            employee_getId(aux,&auxId);
            if (auxId == id)
            {
                p = aux;
                break;
            }
        }
    }
    return p;
}

void employee_MostrarEncabezados ()
{
    printf("ID                      NOMBRE        HORAS TRABAJADAS    SUELDO\n");
}

int employee_MostrarSolo (Employee* p)
{
    int  stat = 0;

    if (p != NULL)
    {
        int id;
        int horas;
        int salario;
        char nombre[50];
        if (employee_GetEverything(p,&id,&horas,&salario,nombre))
        {
            printf("%5d  %25s     %10d   %13d\n",id,nombre,horas,salario);
            stat = 1;
        }
    }
    return stat;
}


int employee_MostrarTodos (int len,LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int stat = 0;
    if (pArrayListEmployee != NULL)
    {
        for (int i= 0; i<len; i++)
        {
            aux= (Employee*)ll_get(pArrayListEmployee,i);
            employee_MostrarSolo(aux);
        }
        stat = 1;
    }
    return stat;
}

int employee_GetEverything (Employee* p,int* id,int* horas, int* salario, char* nombre)
{
    int isOkay = 0;

    if (p!= NULL)
    {
        if (employee_getId(p,id))
        {
            if (employee_getHorasTrabajadas(p,horas))
            {
                if (employee_getSueldo(p,salario))
                {
                    if (employee_getNombre(p,nombre))
                    {
                        isOkay = 1;
                    }
                }
            }
        }
    }
    return isOkay;
}

