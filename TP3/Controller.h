
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee,int* ID);
/** \brief Controlador que se encarga de cargar los empleados desde un archivo de texto .csv los carga en la linked list de empleados.
 *
 * \param nombre del archivo que abre
 * \param puntero a linkedList de empleados en donde cargar los datos del archivo
 * \param Puntero a variable en el main que guarda el ultimo ID guardado.
 * \return Devuelve 1 si se pudieron cargar los empleados. Devuelve 0 si NO se pudieron cargar los empleados correctamente
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee,int* ID);
/** \brief Controlador que se encarga de cargar los empleados desde un archivo binario .bin y los carga en la linked list de empleados.
 *
 * \param nombre del archivo que abre
 * \param puntero a linkedList de empleados en donde cargar los datos del archivo
 * \param Puntero a variable en el main que guarda el ultimo ID guardado.
 * \return Devuelve 1 si se pudieron cargar los empleados. Devuelve 0 si NO se pudieron cargar los empleados correctamente
 *
 */


int controller_addEmployee(LinkedList* pArrayListEmployee,int* IdUnico);
/** \brief Controlador que se encarga de realizar nuevo alta de empleado pidiendo todos los datos al usuario por consola
 *
 * \param puntero a linkedList de empleados en donde se cargara el nuevo empleado
 * \param Puntero a variable en el main que guarda el ultimo ID guardado. Se usa para otorgar un ID unico al nuevo empleado y luego se le suma 1 (al ID)
 * \return Devuelve 1 si se pudo crear un nuevo empleado. Devuelve 0 si hubo algun error al cargar el empleado.
 *
 */


int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Controlador que se encarga de modificar un empleado pidiendo nuevos datos al usuario por consola
 *
 * \param puntero a linkedList de empleados en donde se encuentra el empleado a modificar
 * \return Devuelve 1 si se pudo modificar un  empleado. Devuelve 0 si no se modifico nada.
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Controlador que se encarga de realizar una baja de empleado pidiendo su ID al usuario por consola
 *
 * \param puntero a linkedList de empleados en donde se encuentra el empleado a remover
 * \return Devuelve 1 si se pudo elminar un  empleado. Devuelve 0 si no se elmino a ningun empleado.
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Muestra un listado completo de todos los empleados contenidos en una LinkedList de empleados. (Incluye encabezados)
 *
 * \param puntero a linkedList de empleados a mostrar.
 * \return Devuelve 1 si se pudieron mostrar todos los empleados. Devuelve 0 si hubo algún error al mostrar los empleados
 *
 */


int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Pide criterio de ordenamiento al usuario por consola. Luego ordena linkedList de empleados segun ID,Nombre,Horas Trabajadas o Salario. Ascendiente o Descendiente
 *
 * \param puntero a linkedList de empleados a ordenar.
 * \return Devuelve 1 si se pudieron ordenar los empleados. Devuelve 0 si hubo algún error al ordenar los empleados
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los empleados de una LinkedList de empleados en un archivo de texto.csv) a pasar por parametro.
 *
 * \param Nombre del archivo en el cual se guardaran los empleados.
 * \param puntero a linkedList de empleados a guardar.
 * \return Devuelve 1 si se pudieron guardar los empleados. Devuelve 0 si hubo algún error al guardar los empleados o al abrir algun archivo
 *
 */


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los empleados de una LinkedList de empleados en un archivo binario (.bin) a pasar por parametro.
 *
 * \param Nombre del archivo en el cual se guardaran los empleados.
 * \param puntero a linkedList de empleados a guardar.
 * \return Devuelve 1 si se pudieron guardar los empleados. Devuelve 0 si hubo algún error al guardar los empleados o al abrir algun archivo
 *
 */

