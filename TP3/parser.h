int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);
/** \brief Lee  datos desde un archivo de texto y los guarda en una lista de empleados en el sistema. Cada linea del archivo guarda 1 empleado
 *
 * \param puntero a archivo de texto desde donde leer los datos
 * \param puntero a linkedList de empleados en donde se guardaran todos los datos.
 * \return Devuelve 0 si hubo un error al cargar empleados. Devuelve 1 si se guardaron todos los empleados con exito.
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Lee  datos desde un archivo binario y los guarda en una lista de empleados en el sistema.
 *
 * \param puntero a archivo binario desde donde leer los datos
 * \param puntero a linkedList de empleados en donde se guardaran todos los datos.
 * \return Devuelve 0 si hubo un error al cargar empleados. Devuelve 1 si se guardaron todos los empleados con exito.
 *
 */
