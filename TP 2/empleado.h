#include "sector.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int idSector;
    int isFull;
} e_Empleado;

#endif // EMPLEADO_H_INCLUDED

/** \brief Muestra por consola un header con los encabezados de columna de los empleados y luego los datos de un unico empleado
 *
 * \param variable escalar tipo e_Empleado
 * \param vector de variables tipo e_Sector
 * \param tamaño del vector de variables e_Sector
 *
 */
void mostrarPrimerEmpleado (e_Empleado x,e_Sector sectores[],int sizeSect);

/** \brief Muestra los datos de un unico empleado
 *
 * \param variable escalar tipo e_Empleado
 * \param vector de variables tipo e_Sector
 * \param tamaño del vector de variables e_Sector
 *
 */
void mostrarEmpleado (e_Empleado x,e_Sector sectores[],int sizeSect);

/** \brief Muestra los datos de todos los empleados dados de alta en el vector list[].
 *
 * \param Vector de variables tipo e_Empleado
 * \param Tamaño del vector de variables e_Empleado
 * \param vector de variables tipo e_Sector
 * \param tamaño del vector de variables e_Sector
 */
void mostrarEmpleados(e_Empleado list[],int size,e_Sector sectores[],int sizeSect);

/** \brief Informa el total de sueldos de todos los empleados del vector de variables tipo e_Empleado, el salario promedio y la cantidad de empleados cuyo salario es mayor al promedio.
 *
 * \param vector de variables tipo e_Empleado
 * \param tamaño del vector de variables e_Empleado
 *
 */
void informarSueldos (e_Empleado vec[],int size);

/** \brief Ordena listado de empleados por Sector y luego por Apellido y Nombre. Recorre todo el vector en su totalidad.
 *
 * \param vector de variables tipo e_Empleado
 * \param tamaño del vector de variables e_Empleado
 *
 */
void ordenarListadoSAN (e_Empleado vec[],int size);

/** \brief Setea el campo .isFull a 0 en todos los empleados del vector. Se utiliza 1 vez sola al comienzo del programa.
 *
 * \param vector de variables tipo e_Empleado
 * \param tamaño del vector de variables e_Empleado
 *
 */
void inicializarEmpleados (e_Empleado list[],int size);

/** \brief Recorre el vector de empleados en su totalidad y revisa si hay lugar disponible para guardar un nuevo empleado.
Si encuentra un lugar, devuelve el indice del vector e_Empleado[] donde se pueden guardar datos. De lo contrario devuelve -1
 *
 * \param vector de variables tipo e_Empleado
 * \param tamaño del vector de variables e_Empleado
 * \return Indice del vector e_Empleado[] donde se pueden guardar datos (>=0). Devuelve -1 si el vector se encuentra lleno de empleados cuyo campo .isFull esta en 1
 *
 */
int getEmptySlot (e_Empleado listita[],int size);

/** \brief Realiza la carga de un nuevo empleado en el vector correspondiente. Toma los datos: Nombre, Apellido, Sueldo y Sector y los guarda en un indice del vector obtenido mediante la funcion getEmptySlot .
Otorga un ID unico al empleado y se lo muestra al usuario al finalizar el alta.
Formatea nombre y apellido mediante funcion normalizeString .
Devuelve 1 si se pudo realizar el alta o 0 si no se pudo realizar el alta
 *
 * \param vector de variables tipo e_Empleado
 * \param tamaño del vector de variables e_Empleado
 * \param ID unico que va a identificar al nuevo empleado
 * \param vector de variables tipo e_Sector
 * \param tamaño del vector de variables e_Sector
 * \return 1 si se pudo realizar el alta
           0 si no se pudo realizar el alta
 *
 */
int getEmpleado (e_Empleado x[],int size,int idOrigen,e_Sector sectores[],int sizeSect);

/** \brief Busca un empleado por ID y devuelve el indice del vector e_empleado [] donde se encuentra. Devuelve -1 si el ID ingresado no corresponde a ningun empleado.
 *
 * \param ID del empleado a buscar
 * \param vector de variables tipo e_Empleado
 * \param tamaño del vector de variables e_Empleado
 * \return  Devuelve el indice del vector e_empleado [] donde se encuentra.
            Devuelve -1 si el ID ingresado no corresponde a ningun empleado.
 *
 */
int buscarEmpleado (int id,e_Empleado listita[],int size);

/** \brief Pide ID de empleado al usuario por consola, muestra al empleado (si lo encontro), pregunta al usuario cual de sus datos quiere modificar (nombre, apellido, sueldo o sector), lo modifica, lo vuelve a mostrar y se repite el menu de opciones hasta que el usuario decida salir.
 *
 * \param vector de variables tipo e_Empleado
 * \param tamaño del vector de variables e_Empleado
 * \param vector de variables tipo e_Sector
 * \param tamaño del vector de variables e_Sector
 *
 */
void modificarEmpleado (e_Empleado vec[],int size,e_Sector sectores[],int sizeSect);

/** \brief Pide ID de empleado al usuario por consola, muestra al empleado (si lo encontro) y pide confirmacion para darlo de baja. Si se confirma la baja setea el campo del empleado isFull a 0.
 *
 * \param vector de variables tipo e_Empleado
 * \param tamaño del vector de variables e_Empleado
 * \param vector de variables tipo e_Sector
 * \param tamaño del vector de variables e_Sector
 *
 */
void eliminarEmpleado (e_Empleado vec[],int size,e_Sector sectores[],int sizeSect);

/** \brief recorre todo el vector de empleados y nos dice si hay algun empleado cargado o no.
 *
 * \param vector de variables tipo e_Empleado
 * \param tamaño del vector de variables e_Empleado
 * \return 1 si hay empleados cargados en el vector
 *         -1 si no hay empleados cargados en el vector
 */
int hayEmpleados (e_Empleado vec[],int size);
