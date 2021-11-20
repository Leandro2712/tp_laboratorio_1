/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param path Nombre del archivo a cargar.
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/**
 * @fn int controller_addEmployee(LinkedList*)
 * @brief Alta de empleados
 *
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_editEmployee(LinkedList*)
 * @brief Modificar datos de empleado
 *
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_removeEmployee(LinkedList*)
 * @brief Baja de empleado
 *
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_ListEmployee(LinkedList*)
 * @brief Listar empleados
 *
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_sortEmployee(LinkedList*)
 * @brief Ordenar empleados.
 *
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * @param path Nombre del archivo a guardar.
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/**
 * @fn int controller_validarId(LinkedList*, int)
 * @brief Funcion que validad que el id ingresado sea uno existente.
 *
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @param idEmp id ingresado a comparar si es uno valido o no.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_validarId(LinkedList* pArrayListEmployee, int idEmp);

/**
 * @fn int controller_siguienteId()
 * @brief Funcion que sirve para calcular el siguiente ID a utilizar teniendo en cuenta el ultimo ID utilizado.
 *
 * @return Retorna el siguiente ID a utilizar.
 */
int controller_siguienteId();

/**
 * @fn void controller_guardarIdSiguiente(int)
 * @brief Guarda el ultimo ID utilizado en un archivo de texto, para utilizarlo la siguiente vez que el programa se inicie.
 *
 * @param idActual Es el ultimo ID que fue utilizado para guardar.
 */
void controller_guardarIdSiguiente(int idActual);

/**
 * @fn int controller_eliminarEmpleadoConMasHoras(LinkedList*)
 * @brief Funcion que elimina al empleado con mas horas
 *
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_eliminarEmpleadoConMasHoras(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_crearSublista(LinkedList*)
 * @brief Funcion que crea una sublista
 *
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_crearSublista(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_altaEmpleadoConReemplazo(LinkedList*)
 * @brief Funcion que da de alta un empleado y lo reemplaza por otro
 *
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_altaEmpleadoConReemplazo(LinkedList* pArrayListEmployee);

/**
 * @fn int controller_altaEligiendoPosicion(LinkedList*)
 * @brief Funcion que da de alta un empleado eligiendo la posicion donde estara.
 *
 * @param pArrayListEmployee Puntero a la lista de empleados.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_altaEligiendoPosicion(LinkedList* pArrayListEmployee);


