#ifndef TP1_FUNC_H_INCLUDED
#define TP1_FUNC_H_INCLUDED

/** \brief suma dos integros y devuelve la suma como integro
 *
 * \param primer integro a sumar
 * \param segundo integro a sumar
 * \return suma de los integros
 *
 */
int sumar (int,int);

/** \brief resta el segundo integro al primer integro ingresado
 *
 * \param minuendo
 * \param sustraendo
 * \return diferencia entre (minuendo - sustraendo)
 *
 */
int restar (int,int);

/** \brief multiplica dos integros, devuelve su producto
 *
 * \param primer integro
 * \param segundo integro
 * \return producto de la multiplicacion
 *
 */
int multiplicar (int,int);

/** \brief realiza una division entre dos integros y la devuelve como flotante
 *
 * \param integro a dividir
 * \param integro divisor
 * \return resultado de la division como numero flotante
 *
 */
float dividir (int,int);

/** \brief Calcula el factorial de un numero ingresado. Lo multiplica por su anterior acumulativamente hasta llegar al 1. Si se ingresa numero negativo no calcula y devuelve -1. Si se ingresa numero mayor a 20 devuelve un factorial incorrecto (no alcanza con 8 bytes para para mostrarlo).
 *
 * \param numero entero del cual sacar el factorial
 * \return factorial de numero si esta entre 1 y 20. devuelve 0 si se ingresa el 0. devuelve -1 si se ingresa un numero negativo. Devuelve factorial incorrecto si se ingresa numero mayor a 20.
 *
 */
long long int sacarFactorial(int);

#endif // TP1_FUNC_H_INCLUDED
