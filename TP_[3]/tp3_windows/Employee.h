#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/**
 * @fn Employee employee_new*()
 * @brief Funcion constructora para crear un nuevo empleado.
 *
 * @return Retorna el empleado creado si tuvo exito.
 */
Employee* employee_new();

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief Funcion constructora para crear un nuevo empleado a partir de parametros establecidos.
 *
 * @param idStr ID a cargar en el usuario pasado como cadena de caracteres.
 * @param nombreStr Nombre a cargar en el usuario pasado como cadena de caracteres.
 * @param horasTrabajadasStr Horas trabajadas a cargar en el usuario pasado como cadena de caracteres.
 * @param sueldoStr Sueldo a cargar en el usuario pasado como cadena de caracteres.
 * @return Retorna el empleado creado si tuvo exito.
 */
Employee* employee_newParametros(char* idStr ,char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);

/**
 * @fn void employee_delete()
 * @brief Libera la memoria ocupada por un empleado.
 *
 */
void employee_delete();

/**
 * @fn void employee_mostrarEmpleado(Employee*)
 * @brief Funcion que sirve para mostrar un solo empleado.
 *
 * @param unEmpleado puntero a la lista de empleados.
 */
void employee_mostrarEmpleado(Employee* unEmpleado);

/**
 * @fn int buscarEmpleadoId(LinkedList*, int)
 * @brief Funcion que sirve para buscar el ID de un empleado.
 *
 * @param this Puntero a la lista de empleados.
 * @param id ID a comparar.
 * @return Retorna el indice del empleado si tuvo exito.
 */
int buscarEmpleadoId(LinkedList* this, int id);

/**
 * @fn int employee_CriterioSueldo(void*, void*)
 * @brief Funcion que compara los sueldos de 2 empleados para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer empleado.
 * @param item2 variable para referirse al segundo empleado.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int employee_CriterioSueldo(void* item1, void* item2);

/**
 * @fn int employee_CriterioId(void*, void*)
 * @brief Funcion que compara los ids de 2 empleados para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer empleado.
 * @param item2 variable para referirse al segundo empleado.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int employee_CriterioId(void* item1, void* item2);

/**
 * @fn int employee_CriterioHorasTrabajadas(void*, void*)
 * @brief Funcion que compara las horas trabajadas de 2 empleados para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer empleado.
 * @param item2 variable para referirse al segundo empleado.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int employee_CriterioHorasTrabajadas(void* item1, void* item2);

/**
 * @fn int employee_CriterioNombre(void*, void*)
 * @brief Funcion que compara los sueldos de 2 empleados para poder ordenarlos luego.
 *
 * @param item1 variable para referirse al primer empleado.
 * @param item2 variable para referirse al segundo empleado.
 * @return Retorna 1 para que luego se ordene de forma ascendente o -1 para que se ordene de forma descendente.
 */
int employee_CriterioNombre(void* item1, void* item2);

/**
 * @fn int employee_setId(Employee*, int)
 * @brief Carga el id del empleado.
 *
 * @param this Puntero a la lista de empleados.
 * @param id id a cargar en el empleado.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int employee_setId(Employee* this,int id);

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief Busca el id del empleado.
 *
 * @param this Puntero a la lista de empleados.
 * @param id id a buscar en el empleado.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int employee_getId(Employee* this,int* id);

/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief Carga el nombre del empleado.
 *
 * @param this Puntero a la lista de empleados.
 * @param nombre Nombre a cargar en el empleado.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief Busca el nombre del empleado.
 *
 * @param this Puntero a la lista de empleados.
 * @param nombre Nombre a buscar en el empleado.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief Carga las horas trabajadas del empleado.
 *
 * @param this Puntero a la lista de empleados.
 * @param horasTrabajadas horas trabajadas a cargar en el empleado.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief Busca las horas trabajadas del empleado.
 *
 * @param this Puntero a la lista de empleados.
 * @param horasTrabajadas horas trabajadas a buscar en el empleado.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief Carga el sueldo del empleado.
 *
 * @param this Puntero a la lista de empleados.
 * @param sueldo sueldo a cargar en el empleado.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int employee_setSueldo(Employee* this,int sueldo);

/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief Busca el sueldo del empleado.
 *
 * @param this Puntero a la lista de empleados.
 * @param sueldo Sueldo a buscar en el empleado.
 * @return Retorna 1 si esta todoOK y 0 si fallo.
 */
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
