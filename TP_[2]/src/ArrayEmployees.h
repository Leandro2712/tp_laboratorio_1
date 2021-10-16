/*
 * ArrayEmployees.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Leandro Sebastian Avalos
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

/**
 * @struct
 * @brief Estructura de empleado que guarda los valores del ID, Nombre, Apellido, Salario, Sector y si esta vacio o no el indice.
 *
 */
typedef struct
{
    int id;
    // Reduje los caracteres a 30 porque me parecio demasiado que sea de 50 y el encolumnado a la hora de mostrarlo me quedaba mal.
    char name[30];
    // Reduje los caracteres a 30 porque me parecio demasiado que sea de 50 y el encolumnado a la hora de mostrarlo me quedaba mal.
    char lastName[30];
    float salary;
    int sector;
    int isEmpty;

}Employee;

#endif /* ARRAYEMPLOYEES_H_ */

/**
 * @fn int menu()
 * @brief Imprime un menu de opciones para el usuario.
 *
 * @return Retorna la opcion elegida por el usuario.
 */
int menu();

/**
 * @fn int initEmployees(Employee*, int)
 * @brief Inicia los indices de los empleados en 1 para marcar que estan "vacios" esos indices.
 *
 * @param list Puntero array a la estructura de empleados.
 * @param len Tamaño del array de empleados.
 * @return Retorna -1 si hay error. Retorna 0 si esta todo OK.
 */
int initEmployees(Employee* list, int len);

/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief Agrega en una lista existente de empleados los valores recibidos como parametros en la primera posicion vacia.
 *
 * @param list Puntero array a la estructura de empleados.
 * @param len Tamaño del array de empleados.
 * @param id Id de la persona.
 * @param name Nombre de la persona.
 * @param lastName Apellido de la persona.
 * @param salary Salario de la persona.
 * @param sector Sector de la persona.
 * @return Retorna -1 si hay error. Retorna 0 si esta todo OK.
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * @fn int buscarLibre(Employee[], int)
 * @brief Busca un indice libre
 *
 * @param lista Puntero array a la estructura de empleados.
 * @param tam Tamaño del array de empleados.
 * @return Retorna un indice libre.
 */
int buscarLibre(Employee lista[], int tam);

/**
 * @fn int findEmployeeById(Employee*, int, int)
 * @brief Encuentra un empleado por ID y retorna el indice de la posicion en el array
 *
 * @param list Puntero array a la estructura de empleados.
 * @param len Tamaño del array de empleados.
 * @param id Id a chequear para ver si se encuentra en el array de empleados.
 * @return Retorna el indice de la posicion en el array.
 */
int findEmployeeById(Employee* list, int len,int id);

/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief Remueve un empleado por su ID (poniendo su isEmpty en 1).
 *
 * @param list Puntero array a la estructura de empleados.
 * @param len Tamaño del array de empleados.
 * @param id Id a chequear para ver si se encuentra en el array de empleados.
 * @return Retorna -1 si hay error. Retorna 0 si esta todo OK.
 */
int removeEmployee(Employee* list, int len, int id);
/**
 * @fn void mostrarPersona(Employee)
 * @brief Muestra los datos de un empleado.
 *
 * @param unEmpleado Valores array de empleados.
 */
void mostrarPersona(Employee unEmpleado);

/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief Ordena los elementos en el array de empleados.
 *
 * @param list Puntero array a la estructura de empleados.
 * @param len Tamaño del array de empleados.
 * @param order Es el criterio que indica si se va a ordenar Ascendente o Descendente.
 * @return Retorna -1 si hay error. Retorna 0 si esta todo OK.
 */
int sortEmployees(Employee* list, int len, int order);

/**
 * @fn int subMenuDeInformaciones(Employee[], int)
 * @brief Imprime un menu para mostrar los informes a los que puede acceder la persona.
 *
 * @param lista Puntero array a la estructura de empleados.
 * @param tam Tamaño del array de empleados.
 * @return Retorno 1 si esta todo OK. Retorna 0 si fallo.
 */
int subMenuDeInformaciones(Employee lista[], int tam);

/**
 * @fn int printEmployees(Employee*, int)
 * @brief Muestra los datos de los empleados que esten cargados en el array.
 *
 * @param list Puntero array a la estructura de empleados.
 * @param length Tamaño del array de empleados.
 * @return Retorno 1 si esta todo OK. Retorna 0 si fallo.
 */
int printEmployees(Employee* list, int length);

/**
 * @fn int modifyEmployees(Employee[], int)
 * @brief Pide que se ingrese el ID de la persona a modificar, se chequea si el ID es correcto y si es asi se accede a un submenu de modificaciones.
 *
 * @param list Puntero array a la estructura de empleados.
 * @param len Tamaño del array de empleados.
 * @return Retorno 1 si esta todo OK. Retorna 0 si fallo.
 */
int modifyEmployees(Employee list[], int len);

/**
 * @fn int subMenuDeModificaciones()
 * @brief Imprime un submenu de modificaciones que puede realizar el usuario.
 *
 * @return Retorna la opcion elegida por el usuario.
 */
int subMenuDeModificaciones();

/**
 * @fn int totalYPromedioSalarios(Employee[], int)
 * @brief Calcula el Total de los salarios, los promedia y muestra que personas superan el salario promedio.
 *
 * @param lista Puntero array a la estructura de empleados.
 * @param len Tamaño del array de empleados.
 * @return Retorno 1 si esta todo OK. Retorna 0 si fallo.
 */
int totalYPromedioSalarios(Employee lista[], int len);

/**
 * @fn int cambiarValorDeFlag(Employee[], int, int*)
 * @brief Recibe el valor de la flag, recorre el array de empleados y cuando encuentra indices en isEmpty 1 cambia el valor de la flag a 0 para que luego no se pueda acceder a los demas menu sin haber ingresado al menso un empleado. Pero si encuentra un indice en 0 deja el valor de la flag en 1 para poder seguir entrando a los menu.
 *
 * @param list Puntero array a la estructura de empleados.
 * @param tam Tamaño del array de empleados.
 * @param flag Recibe el valor de la flag.
 * @return Retorno 1 si esta todo OK. Retorna 0 si fallo.
 */
int cambiarValorDeFlag(Employee list[], int tam, int* flag);
