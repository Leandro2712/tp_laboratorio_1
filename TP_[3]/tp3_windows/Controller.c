#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"
#include "controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* f;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path, "r");
		parser_EmployeeFromText(f, pArrayListEmployee);
		printf("Lista cargada exitosamente!!\n");
		todoOk = 1;
	}
	fclose(f);
    return todoOk;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* f;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path, "rb");
		if(f != NULL)
		{
			parser_EmployeeFromBinary(f, pArrayListEmployee);
			printf("Lista cargada exitosamente!!\n");
			todoOk = 1;
		}
		else
		{
			printf("No hay ningun archivo de tipo binario para cargar.\n");
		}
	}
	fclose(f);
	return todoOk;
}

int controller_validarId(LinkedList* pArrayListEmployee, int idEmp)
{
	int idEncontrada;
	int idValidada=-1;
	int tam;
	Employee* empleado;

	if(pArrayListEmployee != NULL && idEmp >= 0)
	{
		tam = ll_len(pArrayListEmployee);

		for (int i = 0; i < tam; ++i) {

			empleado = ll_get(pArrayListEmployee, i);

			if(empleado != NULL)
			{
				employee_getId(empleado, &idEncontrada);

				if(idEmp==idEncontrada)
				{
					idValidada= 1;
					break;
				}
			}
		}
	}
	return idValidada;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	char respuesta;
	Employee* empleado;

	system("cls");
	printf("              *** Alta Empleado ***                  \n");
	printf("-----------------------------------------------------\n");

	if(pArrayListEmployee != NULL)
	{
		empleado = employee_new();
		if(empleado != NULL)
		{
			id = controller_siguienteId();
			employee_setId(empleado, id);

			pedirCadena(nombre, "Ingrese su nombre(Caracteres maximos: 128)\n", "Error.Ingrese su nombre nuevamente(Caracteres maximos: 128)\n", 128);
			fflush(stdin);
			employee_setNombre(empleado, nombre);

			pedirEntero(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas(min: 50, max: 350)\n", "Error.Ingrese la cantidad de horas trabajadas nuevamente(min: 50, max: 350)\n", 50, 350);
			employee_setHorasTrabajadas(empleado, horasTrabajadas);

			pedirEntero(&sueldo, "Ingrese su sueldo(min: 1 max:(100.000)\n", "Error. Ingrese su sueldo nuevamente(min: 1 max:(100.000)", 1, 100000);
			employee_setSueldo(empleado, sueldo);

			printf("Id     |Nombre            |HorasTrabajadas             |sueldo    \n");
			printf("------------------------------------------------------------------\n");
			employee_mostrarEmpleado(empleado);

			pedirCaracter(&respuesta, "Desea dar de alta a esta persona? s(si) o n(no)\n", "Error.Ingrese la letra nuevamente. Desea dar de alta a esta persona? s(si) o n(no)\n", 's', 'n');
			if(respuesta == 's')
			{
				ll_add(pArrayListEmployee, empleado);
				controller_guardarIdSiguiente(id);
				todoOk = 1;
				printf("Empleado dado de alta con exito!!!\n");
			}
			else
			{
				printf("Se ah cancelado el alta.\n");
			}
		}
	}
    return todoOk;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	char respuesta;
	int indiceEmpleado;
	Employee* empleado;

	system("cls");
	printf("              *** Modificar Empleado ***                           \n");
	printf("-------------------------------------------------------------------\n");

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		printf("Ingrese ID de la persona a remover.\n");
		scanf("%d", &id);
		while(controller_validarId(pArrayListEmployee, id) == -1)
		{
			printf("Error. ID invalido. Ingrese ID de la persona a remover.\n");
			scanf("%d", &id);
		}
		indiceEmpleado = buscarEmpleadoId(pArrayListEmployee, id);
		empleado = ll_get(pArrayListEmployee, indiceEmpleado);

		if(indiceEmpleado == -1)
		{
			printf("El id ingresado no existe\n");
		}
		else
		{
			printf("------------------------------------------------------------------\n");
			printf("Id     |Nombre            |HorasTrabajadas             |sueldo    \n");
			printf("------------------------------------------------------------------\n");
			employee_mostrarEmpleado(empleado);

			pedirCaracter(&respuesta, "Esta seguro que desea modificar a esta persona del sistema? (s: SI y n: NO)\n", "Error.Ingrese opcion nuevamente. Esta seguro que desea modificar a esta persona del sistema? (s: SI y n: NO)\n", 's', 'n');
			fflush(stdin);

			if(respuesta == 's')
			{
				switch(menuDeModificaciones())
				{
					case 1:
						pedirCadena(nombre, "Ingrese su nombre(Caracteres maximos: 128)\n", "Error.Ingrese su nombre nuevamente(Caracteres maximos: 128)\n", 128);
						fflush(stdin);
						employee_setNombre(empleado, nombre);
						printf("Modificacion Exitosa!!!\n");
						break;
					case 2:
						pedirEntero(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas(min: 50, max: 350)\n", "Error.Ingrese la cantidad de horas trabajadas nuevamente(min: 50, max: 350)\n", 50, 350);
						employee_setHorasTrabajadas(empleado, horasTrabajadas);
						printf("Modificacion Exitosa!!!\n");
						break;
					case 3:
						pedirEntero(&sueldo, "Ingrese su sueldo(min: 1 max:(100.000)\n", "Error. Ingrese su sueldo nuevamente(min: 1 max:(100.000)", 1, 100000);
						employee_setSueldo(empleado, sueldo);
						printf("Modificacion Exitosa!!!\n");
						break;
					case 4:
						printf("Se ah cancelado la modificacion.\n");
						break;
					default:
						printf("Opcion invalida!!!\n");
						break;
				}
			}
			else
			{
				printf("Se ah cancelado la modificacion.\n");
			}
		}
		todoOk = 1;
	}
    return todoOk;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int id;
	char respuesta;
	int indiceEmpleado;
	Employee* empleado;


	system("cls");
	printf("              *** Baja de Empleado ***                           \n");
	printf("------------------------------------------------------------------\n");
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		printf("Ingrese ID de la persona a remover.\n");
		scanf("%d", &id);
		while(controller_validarId(pArrayListEmployee, id) == -1)
		{
			printf("Error. ID invalido. Ingrese ID de la persona a remover.\n");
			scanf("%d", &id);
		}
		indiceEmpleado = buscarEmpleadoId(pArrayListEmployee, id);
		empleado = ll_get(pArrayListEmployee, indiceEmpleado);

		if(indiceEmpleado == -1)
		{
			printf("El id ingresado no existe\n");
		}
		else
		{
			printf("------------------------------------------------------------------\n");
			printf("Id     |Nombre            |HorasTrabajadas             |sueldo    \n");
			printf("------------------------------------------------------------------\n");
			employee_mostrarEmpleado(empleado);

			pedirCaracter(&respuesta, "Esta seguro que desea borrar a esta persona del sistema? (s: SI y n: NO)\n", "Error.Ingrese opcion nuevamente. Esta seguro que desea borrar a esta persona del sistema? (s: SI y n: NO)\n", 's', 'n');
			fflush(stdin);

			if(respuesta == 's')
			{
				ll_remove(pArrayListEmployee, indiceEmpleado);
				employee_delete(empleado);
				todoOk = 1;
				printf("Baja Exitosa!!!\n");
			}
			else
			{
				printf("Se ah cancelado la baja.\n");
			}
		}
	}
    return todoOk;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	Employee* empleado = NULL;
	if(pArrayListEmployee != NULL)
	{
		printf("            *** Listado de Empleados ***\n");
		printf("------------------------------------------------------------------\n");
		printf("Id     |Nombre            |HorasTrabajadas             |sueldo    \n");
		printf("------------------------------------------------------------------\n");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			empleado = ll_get(pArrayListEmployee, i);
			if(empleado != NULL)
			{
				employee_mostrarEmpleado(empleado);
				todoOk = 1;
			}
		}
	}
    return todoOk;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int criterio;
	LinkedList* clon;

	if(pArrayListEmployee != NULL)
	{
		clon = ll_clone(pArrayListEmployee);
		criterio = menuDeCriterio();

		switch(menuDeOrdenamiento())
		{
			case 1:
				ll_sort(clon, employee_CriterioId, criterio);
				printf("Un momento, la lista se esta procesando.\n");
				controller_ListEmployee(clon);
				printf("Ordenamiento exitoso!!!\n");
				break;
			case 2:
				ll_sort(clon, employee_CriterioNombre, criterio);
				printf("Un momento, la lista se esta procesando.\n");
				controller_ListEmployee(clon);
				printf("Ordenamiento exitoso!!!\n");
				break;
			case 3:
				ll_sort(clon, employee_CriterioHorasTrabajadas, criterio);
				printf("Un momento, la lista se esta procesando.\n");
				controller_ListEmployee(clon);
				printf("Ordenamiento exitoso!!!\n");
				break;
			case 4:
				ll_sort(clon, employee_CriterioSueldo, criterio);
				printf("Un momento, la lista se esta procesando.\n");
				controller_ListEmployee(clon);
				printf("Ordenamiento exitoso!!!\n");
				break;
			case 5:
				printf("Ordenamiento cancelado.\n");
				break;
			default:
				printf("Opcion invalida!!!\n");
				break;
		}
		ll_deleteLinkedList(clon);
		todoOk = 1;
	}

    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk;
	FILE* f;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	Employee* nuevoEmpleado;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path, "w");

		nuevoEmpleado = employee_new();

		fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			nuevoEmpleado = ll_get(pArrayListEmployee, i);
			if(nuevoEmpleado != NULL)
			{
				employee_getId(nuevoEmpleado, &id);
				employee_getNombre(nuevoEmpleado, nombre);
				employee_getHorasTrabajadas(nuevoEmpleado, &horasTrabajadas);
				employee_getSueldo(nuevoEmpleado, &sueldo);

				fprintf(f, "%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
				todoOk = 1;
			}
			else
			{
				todoOk = 0;
				break;
			}
		}
		fclose(f);
	}
    return todoOk;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* f;
	Employee* nuevoEmpleado;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path, "wb");

		nuevoEmpleado = employee_new();

		if(nuevoEmpleado != NULL)
		{
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				nuevoEmpleado = ll_get(pArrayListEmployee, i);
				fwrite(nuevoEmpleado, sizeof(Employee), 1, f);
			}
			todoOk = 1;
		}
		fclose(f);
	}
    return todoOk;
}

int controller_siguienteId()
{
	FILE* f=fopen("ultimoID.txt", "r");
	int* idActual=(int*) malloc(sizeof(int));
    int siguienteId;

    if(f==NULL)
    {
    	siguienteId=1001;
    }
    else
    {
        fscanf(f, "%d", idActual);
        siguienteId=*idActual+1;
    }
    fclose(f);

    return siguienteId;
}

void controller_guardarIdSiguiente(int idActual)
{
    FILE* f=fopen("ultimoID.txt", "r+");

    if(f==NULL)
    {
        f=fopen("ultimoID.txt", "w");
    }

    fprintf(f,"%d", idActual);
    fclose(f);
}


