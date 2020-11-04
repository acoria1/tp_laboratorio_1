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
/** \brief Setea el campo de "id" de un empleado a un valor pasado por parametro. Verifica que el puntero a empleado no sea NULL y que el id sea mayor a 0.
 *
 * \param puntero a empleado
 * \param Id a setear.
 * \return Devuelve 1 si se pudo setear el id. Devuelve 0 si NO se pudo setear el ID.
 *
 */

int employee_getId(Employee* this,int* id);
/** \brief Consigue el id de un empleado y lo guarda en una variable pasada por referencia en parametro 2.
 *
 * \param puntero a empleado en memoria dinamica
 * \param variable en donde se guardara el id del empleado
 * \return Devuelve 1 si guardo algo en la variable (parametro 2). Devuelve 0 si el puntero a empleado es NULL o si el puntero de parametro 2 es NULL
 *
 */

int employee_setNombre(Employee* this,char* nombre);
/** \brief Setea el campo de "nombre" de un empleado a un valor pasado por parametro. Verifica que el puntero a empleado no sea NULL y que la cadena no tenga mas de 128 caracteres
 *
 * \param puntero a empleado
 * \param nombre a setear.
 * \return Devuelve 1 si se pudo setear el nombre. Devuelve 0 si NO se pudo setear el nombre.
 *
 */


int employee_getNombre(Employee* this,char* nombre);
/** \brief Consigue el nombre de un empleado y lo guarda en una variable pasada por referencia en parametro 2.
 *
 * \param puntero a empleado en memoria dinamica
 * \param variable en donde se guardara el nombre del empleado
 * \return Devuelve 1 si guardo algo en la variable (parametro 2). Devuelve 0 si el puntero a empleado es NULL o si el puntero de parametro 2 es NULL
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Setea el campo de "HorasTrabajadas" de un empleado a un valor pasado por parametro. Verifica que el puntero a empleado no sea NULL y que las horasTrabajadas ingresadas sean mayor o igual a  0.
 *
 * \param puntero a empleado
 * \param HorasTrabajadas a setear.
 * \return Devuelve 1 si se pudo setear las horas. Devuelve 0 si NO se pudo setear las horas.
 *
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Consigue horasTrabajadas de un empleado y lo guarda en una variable pasada por referencia en parametro 2.
 *
 * \param puntero a empleado en memoria dinamica
 * \param variable en donde se guardara HorasTrabajadas del empleado
 * \return Devuelve 1 si guardo algo en la variable (parametro 2). Devuelve 0 si el puntero a empleado es NULL o si el puntero de parametro 2 es NULL
 *
 */

int employee_setSueldo(Employee* this,int sueldo);
/** \brief Setea el campo de "Sueldo" de un empleado a un valor pasado por parametro. Verifica que el puntero a empleado no sea NULL y que el Sueldo sea mayor a 0.
 *
 * \param puntero a empleado
 * \param Sueldo a setear.
 * \return Devuelve 1 si se pudo setear el sueldo. Devuelve 0 si NO se pudo setear el sueldo.
 *
 */

int employee_getSueldo(Employee* this,int* sueldo);
/** \brief Consigue el sueldo de un empleado y lo guarda en una variable pasada por referencia en parametro 2.
 *
 * \param puntero a empleado en memoria dinamica
 * \param variable en donde se guardara el sueldo del empleado
 * \return Devuelve 1 si guardo algo en la variable (parametro 2). Devuelve 0 si el puntero a empleado es NULL o si el puntero de parametro 2 es NULL
 *
 */


int employee_CompareByName(void* e1, void* e2);
/** \brief Compara los nombres de dos empleados y nos devuelve cual es mayor
 *
 * \param Primer Empleado
 * \param Segundo Empleado
 * \return >0 si el nombre del primer empleado es mayor al nombre del segundo empleado ej(Ignacio,Berta)
           <0 si el nombre del primer empleado es menor al nombre del segundo empleado (Berta,Ignacio )
           =0 si ambos nombres son iguales
 *
 */

int employee_CompareById(void* e1, void* e2);
/** \brief Compara los ids de dos empleados y nos devuelve cual es mayor
 *
 * \param Primer Empleado
 * \param Segundo Empleado
 * \return 1 si el id del primer empleado es mayor al id del segundo empleado
           -1 si el id del primer empleado es menor al id del segundo empleado
           0 si los ids son iguales
 *
 */

int employee_CompareBySalary(void* e1, void* e2);
/** \brief Compara los salarios de dos empleados y nos devuelve cual es mayor
 *
 * \param Primer Empleado
 * \param Segundo Empleado
 * \return 1 si el salario del primer empleado es mayor al salario del segundo empleado
           -1 si el salario del primer empleado es menor al salario del segundo empleado
           0 si los salarios son iguales
 *
 */


int employee_CompareByHours(void* e1, void* e2);
/** \brief Compara las HorasTrabajadas de dos empleados y nos devuelve cual es mayor
 *
 * \param Primer Empleado
 * \param Segundo Empleado
 * \return 1 si HorasTrabajadas del primer empleado es mayor a HorasTrabajadas del segundo empleado
           -1 si HorasTrabajadas del primer empleado es menor a HorasTrabajadas del segundo empleado
           0 si las HorasTrabajadas son iguales
 *
 */


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
/** \brief Muestra los datos de un empleado
 *
 * \param Puntero a empleado a mostrar
 * \return  Devuelve 1 si se pudo mostrar el empleado. Devuelve 0 si no se pudo mostrar el empleado
 *
 */

int employee_GetEverything (Employee* p,int* id,int* horas, int* salario, char* nombre);
/** \brief Consigue todos los datos de un empleado en particular y los guarda en variables pasadas por referencia en parametros
 *
 * \param Empleado del cual se van a conseguir los datos
 * \param Aqui se guardara el id del empleado
 * \param Aqui se guardaran las horas trabajadas del empleado
 * \param Aqui se guardara el salario del empleado
 * \param Aqui se guardara el nombre del empleado
 * \return Devuelve 0 si hubo algun error al conseguir los datos.
 *
 */

