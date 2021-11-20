#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"
#include "../inc/Controller.h"

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
