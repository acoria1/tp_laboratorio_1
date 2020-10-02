#ifndef FUNCIONESADICIONALES_H_INCLUDED
#define FUNCIONESADICIONALES_H_INCLUDED


#endif // FUNCIONESADICIONALES_H_INCLUDED

/** \brief Despliega el menu principal de opciones del ABM, devuelve la opcion elejida por el usuario
 *
 * \return devuelve una opcion como integro entre 1 y 5 (si se ingresa algo distinto devuelve 5 como opcion default que es para salir del programa)
 *
 */

int menu();

/** \brief Edita un vector de caracteres para que cada palabra empiece con mayuscula y el resto este en minuscula.
 *
 * \param Puntero a primer elemento del vector a modificar
 *
 */
void normalizeString (char a[]);
