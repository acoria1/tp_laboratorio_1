#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

#endif // employee_H_INCLUDED

Employee* employee_new();
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

void employee_delete(Employee* e);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(void* e1, void* e2);
int employee_CompareBySalary(void* e1, void* e2);
int employee_CompareByHours(void* e1, void* e2);

Employee* employee_GetEmployeeByID (int id,LinkedList* pArrayLinkedList);
void employee_MostrarEncabezados ();
int employee_MostrarTodos (int len,LinkedList* pArrayListEmployee);
int employee_MostrarSolo (Employee* p);
int employee_GetEverything (Employee* p,int* id,int* horas, int* salario, char* nombre);
