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
/** \brief Aloca espacio en memoria dinamica y devuelve puntero a un empleado (struct employee)
 *
 * \return Devuelve direccion de memoria de nuevo empleado creado
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/** \brief Aloca espacio en memoria dinamica, carga sus campos con datos pasados por parametros y devuelve puntero a ese empleado (struct employee)
 *
 * \param ID del empleado
 * \param Nombre del empleado
 * \param Horas Trabajadas del empleado
 * \param Sueldo del empleado
 * \return Devuelve direccion de memoria de nuevo empleado creado
 *
 */

void employee_delete(Employee* e);
/** \brief  Hace un free() de un empleado. Libera el espacio en memoria
 *
 * \param Empleado a eliminar
 *
 */


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
/** \brief Busca un empleado por su id y lo devuelve
 *
 * \param ID de empleado a buscar
 * \param Lista de empleados en donde buscar el empleado deseado.
 * \return Devuelve puntero a un empleado si se lo pudo encontrar. Si el id no coincide con ningun empleado en la lista devuelve NULL;
 *
 */

void employee_MostrarEncabezados ();
/** \brief Muestra encabezados de lista de empleados
 *
 *
 */

int employee_MostrarTodos (int len,LinkedList* pArrayListEmployee);
/** \brief Muestra todos los empleados por consola
 *
 * \param cantidad de empleados en una linkedList
 * \param puntero a linkedList en donde estan guardados los empleados
 * \return  Devuelve 1 si se pudieron mostrar todos los empleados. Devuelve 0 si hubo algun problema al mostrar los empleados
 *
 */


int employee_MostrarSolo (Employee* p);
int employee_GetEverything (Employee* p,int* id,int* horas, int* salario, char* nombre);
