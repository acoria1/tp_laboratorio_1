#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED


#endif // MENUS_H_INCLUDED

void normalizeString (char* a);
/** \brief Recibe una cadena de caracteres y pasa las primeras letras de cada palabra a mayuscula y el resto a minuscula
 *
 * \param Cadena a modificar
 *
 */

int menuSort (void);
/** \brief Muestra Menu de ordenamientos de lista de empleados
 *
 * \return Devuelve 0 si no se eljio una opcion valida // o devuelve del 1 al 5
 */

int menu(void);
/** \brief  Muestra Menu principal del sistema
 *
 * \return Devuelve un integro del 0 al 10. Si devuelve 0 no se elijio ninguna opcion valida.
 */

int menuEditEmployee (void);
/** \brief Muestra Menu de modificacion de un empleado
 *
 * \return Devuelve 0 si no se eljio una opcion valida // o devuelve del 1 al 4
 */


void menu_EncabezadoDeMenu (const char*  mensaje);
/** \brief Muestra un encabezado personalizado
 *
 * \param Titulo del encabezado
 *
 */



