#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "controller.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	Employee* nuevoEmpleado;
	char buffer[4][128];
	int aux;
	char* id = "1";

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			aux = fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
			if(aux == 4)
			{
				id = buffer[0];
				nuevoEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

				if(nuevoEmpleado != NULL)
				{
					aux = ll_add(pArrayListEmployee, nuevoEmpleado);
					if(aux != 0)
					{
						employee_delete(nuevoEmpleado);
						break;
					}
					else
					{
						todoOk = 1;
					}
				}
			}
			else
			{
				break;
			}
		}
		controller_guardarIdSiguiente(atoi(id));
	}
    return todoOk;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk;
	Employee* nuevoEmpleado;
	int aux;
	int id;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(feof(pFile) == 0)
		{
			nuevoEmpleado = employee_new();
			fread(nuevoEmpleado, sizeof(Employee), 1, pFile);

			if(!feof(pFile))
			{
				aux = ll_add(pArrayListEmployee, nuevoEmpleado);
				if(aux != 0)
				{
					employee_delete(nuevoEmpleado);
					todoOk = 0;
					break;
				}
				else
				{
					id = nuevoEmpleado->id;
					todoOk = 1;
				}
			}
			else
			{
				break;
			}
		}
		controller_guardarIdSiguiente(id);
	}
    return todoOk;
}
