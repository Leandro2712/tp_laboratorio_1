#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"
#include "../inc/inputs.h"
#include <ctype.h>

Employee* employee_new()
{
	Employee* nuevoEmpleado;

	nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
	if(nuevoEmpleado != NULL)
	{
		nuevoEmpleado->id = 0;
		strcpy(nuevoEmpleado->nombre, "-");
		nuevoEmpleado->horasTrabajadas = 0;
		nuevoEmpleado->sueldo = 0;
	}

	return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr ,char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* nuevoEmpleado;

	nuevoEmpleado = employee_new();
	if(nuevoEmpleado != NULL)
	{
		if(!(employee_setId(nuevoEmpleado, atoi(idStr))
		   && employee_setNombre(nuevoEmpleado, nombreStr)
		   && employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr))
		   && employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
		   {
				employee_delete(nuevoEmpleado);
				nuevoEmpleado = NULL;
		   }
	}
	return nuevoEmpleado;
}

void employee_delete(Employee* this)
{
	free(this);
}

int employee_setId(Employee* this, int id)
{
	int todoOk = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		todoOk = 1;
	}
	else
	{
		printf("Id Invalido\n");
	}
	return todoOk;
}

int employee_getId(Employee* this,int* id)
{
	int todoOk = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		if(strlen(nombre) < 40 && strlen(nombre) > 1)
		{
			strcpy(this->nombre, nombre);
			strlwr(this->nombre);
			this->nombre[0] = toupper(this->nombre[0]);
			todoOk = 1;
		}
	}
	else
	{
		printf("Nombre Invalido\n");
	}
	return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk = 1;
	}
	return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int todoOk = 0;
	if(this != NULL && horasTrabajadas >= 50 && horasTrabajadas <= 350)
	{
		this->horasTrabajadas = horasTrabajadas;
		todoOk = 1;
	}
	else
	{
		printf("Horas trabajadas invalidas.\n");
	}
	return todoOk;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int todoOk = 0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		todoOk = 1;
	}
	return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int todoOk = 0;
	if(this != NULL && sueldo > 0 && sueldo <= 100000)
	{
		this->sueldo = sueldo;
		todoOk = 1;
	}
	else
	{
		printf("Sueldo Invalido\n");
	}
	return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int todoOk = 0;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		todoOk = 1;
	}
	return todoOk;
}

void employee_mostrarEmpleado(Employee* unEmpleado)
{
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	if(unEmpleado != NULL)
	{
		employee_getId(unEmpleado, &id);
		employee_getNombre(unEmpleado, nombre);
		employee_getHorasTrabajadas(unEmpleado, &horasTrabajadas);
		employee_getSueldo(unEmpleado, &sueldo);

		printf("%-8d%-19s%-29d%-9d\n",id, nombre, horasTrabajadas, sueldo);
	}
}

int buscarEmpleadoId(LinkedList* this, int id)
{
	int seEncontro = - 1;
	int idComparar;
	Employee* empleado;
	if(this != NULL && id > 0)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			empleado = ll_get(this, i);
			if(empleado != NULL)
			{
				employee_getId(empleado, &idComparar);
				if(idComparar == id)
				{
					seEncontro = i;
					break;
				}
			}
		}
	}
	return seEncontro;
}

int employee_CriterioSueldo(void* item1, void* item2)
{
	int todoOk = 0;
	Employee* empleado1 = NULL;
	Employee* empleado2 = NULL;
	int sueldo1;
	int sueldo2;

	empleado1 = (Employee*) item1;
	empleado2 = (Employee*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(employee_getSueldo(empleado1, &sueldo1) == 1 && employee_getSueldo(empleado2, &sueldo2) == 1)
		{
			if(sueldo1 > sueldo2)
			{
				todoOk = 1;
			}
			else if(sueldo1 < sueldo2)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}

int employee_CriterioId(void* item1, void* item2)
{
	int todoOk = 0;
	Employee* empleado1 = NULL;
	Employee* empleado2 = NULL;
	int id1;
	int id2;

	empleado1 = (Employee*) item1;
	empleado2 = (Employee*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(employee_getId(empleado1, &id1) == 1 && employee_getId(empleado2, &id2) == 1)
		{
			if(id1 > id2)
			{
				todoOk = 1;
			}
			else if(id1 < id2)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}

int employee_CriterioHorasTrabajadas(void* item1, void* item2)
{
	int todoOk = 0;
	Employee* empleado1 = NULL;
	Employee* empleado2 = NULL;
	int horasTrabajadas1;
	int horasTrabajadas2;

	empleado1 = (Employee*) item1;
	empleado2 = (Employee*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(employee_getHorasTrabajadas(empleado1, &horasTrabajadas1) == 1 && employee_getHorasTrabajadas(empleado2, &horasTrabajadas2) == 1)
		{
			if(horasTrabajadas1 > horasTrabajadas2)
			{
				todoOk = 1;
			}
			else if(horasTrabajadas1 < horasTrabajadas2)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}

int employee_CriterioNombre(void* item1, void* item2)
{
	int todoOk = 0;
	Employee* empleado1 = NULL;
	Employee* empleado2 = NULL;
	char nombre1[128];
	char nombre2[128];

	empleado1 = (Employee*) item1;
	empleado2 = (Employee*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(employee_getNombre(empleado1, nombre1) == 1 && employee_getNombre(empleado2, nombre2) == 1)
		{
			if(strcmp(nombre1, nombre2) > 0)
			{
				todoOk = 1;
			}
			else if(strcmp(nombre1, nombre2) < 0)
			{
				todoOk = -1;
			}
		}
	}
	return todoOk;
}
