/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Leandro Sebastian Avalos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "inputs.h"
#include <ctype.h>
#include <string.h>

#define TAM 1000

int main(void) {
	setbuf(stdout,NULL);
	char seguir = 's';
	Employee lista[TAM];
	Employee employeesAux;
	int nextId = 1;
	int flagIngreso = 0;

	if(initEmployees(lista, TAM)== - 1)
	{
		printf("Hubo un error al inicializar los empleados");
	}

	do
	{
		switch(menu())
		{
			case 1:
				if(addEmployee(lista, TAM, nextId, employeesAux.name, employeesAux.lastName, employeesAux.salary, employeesAux.sector) == -1)
				{
					printf("Hubo un problema al cargar el empleado.\n");
				}
				else
				{
					printf("Alta exitosa!!!\n");
				}
				nextId++;
				flagIngreso = 1;
				break;
			case 2:
				if(flagIngreso == 1)
				{
					modifyEmployees(lista,TAM);
					printf("Modificacion exitosa!!!\n");
				}
				else
				{
					printf("Debe al menos ingresar un empleado para poder modificarlo.\n");
				}
				break;
			case 3:
				if(flagIngreso == 1)
				{
					removeEmployee(lista, TAM, employeesAux.id);
					cambiarValorDeFlag(lista, TAM, &flagIngreso);
					printf("Baja Exitosa!!!\n");
				}
				else
				{
					printf("Por favor ingrese al menos un empleado para poder darlo de baja.\n");
				}
				break;
			case 4:
				if(flagIngreso == 1)
				{
					subMenuDeInformaciones(lista, TAM);
				}
				else
				{
					printf("Al menos ingrese un empleado para poder dar informes.\n");
				}
				break;
			case 5:
				seguir = 'n';
				printf("Salida exitosa!!! Mucha suerte!!!\n");
				break;
			default:
				printf("Ingrese una opcion valida!!");
				break;
		}
		system("pause");
	}while(seguir == 's');

	return EXIT_SUCCESS;
}
