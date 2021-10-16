/*
 * ArrayEmployees.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Leandro Sebastian Avalos
 */

#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include <ctype.h>
#include <string.h>
#include "inputs.h"

int menu()
{
    int opcion;

    system("cls");
    printf("--------------------------------------------------\n");
    printf("                *** Employees ***          \n");
    printf("--------------------------------------------------\n");
    printf("   1- Altas\n");
    printf("   2- Modificar\n");
    printf("   3- Baja\n");
    printf("   4- Informar\n");
    printf("   5- Salir\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int subMenuDeInformaciones(Employee lista[], int tam)
{
    int opcion;
    int orden;
    int todoOk = 0;

    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("--------------------------------------------------\n");
        printf("                *** Informes ***          \n");
        printf("--------------------------------------------------\n");
        printf("   1- Ordenar por Apellido y sector\n");
        printf("   2- Total y promedio de los salarios y cuantos empleados superan el salario promedio\n");
        printf("   3- Salir\n");

        printf("Ingrese opcion: \n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el criterio de ordenamiento.\n 1 - Ascendente.\n 0 - Descendente\n");
                scanf("%d", &orden);
                sortEmployees(lista, tam, orden);
                printEmployees(lista, tam);
                break;
            case 2:
                totalYPromedioSalarios(lista, tam);
                break;
            case 3:
                printf("\nSalio del menu de informar.\n");
                break;
            default:
                printf("Opcion invalida!!!\n");
                break;
        }
        todoOk = 1;
    }
    return todoOk;
}

int subMenuDeModificaciones()
{
    int opcion;

    system("cls");
    printf("--------------------------------------------------------\n");
    printf("                *** Que desea modificar? ***         \n");
    printf("--------------------------------------------------------\n");
    printf("   1- Nombre\n");
    printf("   2- Apellido\n");
    printf("   3- Salario\n");
    printf("   4- Sector\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(Employee* list, int len)
{
    int todoOk = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 0;
    }

    return todoOk;
}

int buscarLibre(Employee lista[], int tam)
{
    int indice = -1;

    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int todoOk = -1;
    int indice;
    char seguir;

    if(list != NULL && len > 0 && name != NULL && lastName != NULL)
    {
        system("cls");
        printf("----------------------------------------------------------\n");
        printf("                   *** Alta Persona ***\n");
        printf("----------------------------------------------------------\n");
        indice = buscarLibre(list, len);
        printEmployees(list, len);
        printf("\n\n");
        if(indice == - 1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            do
            {
                list[indice].id = id;

                // Reduje los caracteres a 30 porque me parecio demasiado que sea de 50 y el encolumnado a la hora de mostrarlo me quedaba mal.
                pedirCadena(name, "Ingrese su nombre, no mas de 30 caracteres.\n", "Error. Ingrese su nombre nuevamente, no mas de 30 caracteres.\n", 30);
                strcpy(list[indice].name, name);

                // Reduje los caracteres a 30 porque me parecio demasiado que sea de 50 y el encolumnado a la hora de mostrarlo me quedaba mal.
                pedirCadena(lastName, "Ingrese su apellido, no mas de 30 caracteres.\n", "Error. Ingrese su apellido nuevamente, no mas de 30 caracteres.\n", 30);
                strcpy(list[indice].lastName, lastName);

                pedirFlotante(&salary, "Ingrese su salario entre 30000 y 150000.\n", "Error. Ingrese su salario nuevamente entre 30000 y 150000.\n", 30000, 150000);
                list[indice].salary = salary;

                pedirEntero(&sector, "Ingrese su sector entre 1 y 10.\n", "Error. Ingrese su sector nuevamente entre 1 y 10.\n", 1 , 10);
                list[indice].sector = sector;

                list[indice].isEmpty = 0;

                printf("-----------------------------------------------------------------------------------------\n");
                printf("ID    |Nombre                        |Apellido                      |Salario    |Sector  \n");
                printf("-----------------------------------------------------------------------------------------\n\n");
                mostrarPersona(list[indice]);

                printf("\nEsta seguro que desea cargar estos datos al sistema? s/n\n");
                fflush(stdin);
                scanf("%c", &seguir);
                seguir = tolower(seguir);
                todoOk = 0;

            }while(seguir == 'n');
        }

    }
    return todoOk;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int seEncontro = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                seEncontro = i;
            }
        }
    }
    return seEncontro;
}

int removeEmployee(Employee* list, int len, int id)
{
    int todoOk = -1;
    int indicePersona;
    char respuestaBorrar;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("----------------------------------------------------------\n");
        printf("                 *** Baja de Persona ***\n");
        printf("----------------------------------------------------------\n");
        printEmployees(list, len);
        printf("\nIngrese su ID: \n");
        scanf("%d", &id);

        indicePersona = findEmployeeById(list, len, id);

        if(indicePersona == - 1)
        {
            printf("No se encontro una persona con ese ID\n");
        }
        else
        {
            printf("\n");
            printf("-----------------------------------------------------------------------------------------\n");
            printf("ID    |Nombre                        |Apellido                      |Salario    |Sector  \n");
            printf("-----------------------------------------------------------------------------------------\n\n");
            mostrarPersona(list[indicePersona]);
            printf("\n");

            printf("Esta seguro que desea borrar a esta persona del sistema? s/n\n");
            fflush(stdin);
            scanf("%c", &respuestaBorrar);
            respuestaBorrar = tolower(respuestaBorrar);

            if(respuestaBorrar == 's')
            {
                list[indicePersona].isEmpty = 1;
                todoOk = 0;
            }
            else
            {
                printf("Se ha cancelado la baja.\n");
            }
        }
    }
    return todoOk;
}

void mostrarPersona(Employee unEmpleado)
{
    printf("%-6d %-30s %-30s %-11.2f %-8d\n",
           unEmpleado.id,
           unEmpleado.name,
           unEmpleado.lastName,
           unEmpleado.salary,
           unEmpleado.sector);
}

int sortEmployees(Employee* list, int len, int order)
{
    int todoOk = -1;
    Employee auxEmpleado;

    if(list != NULL && len > 0 && order >= 0 && order <= 1)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(order == 1)
                {
                    if((strcmp(list[i].lastName, list[j].lastName)>0) || ((strcmp(list[i].lastName, list[j].lastName)==0) && list[i].sector > list[j].sector))
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                }
                else if(order == 0)
                {
                    if((strcmp(list[i].lastName, list[j].lastName)< 0) || ((strcmp(list[i].lastName, list[j].lastName)==0) && list[i].sector < list[j].sector))
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                }
            }
        }
        todoOk = 0;
    }
    return todoOk;
}

int printEmployees(Employee* list, int length)
{
    int todoOk = 0;
    int flag = 1;

    if(list != NULL && length > 0)
    {
        //system("cls");
        printf("               *** Listado de Personas ***\n\n");
        printf("-----------------------------------------------------------------------------------------\n");
        printf("ID    |Nombre                        |Apellido                      |Salario    |Sector  \n");
        printf("-----------------------------------------------------------------------------------------\n\n");
        for(int i = 0; i < length; i++)
        {
            if(list[i].isEmpty == 0)
            {
                mostrarPersona(list[i]);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("                  No hay personas para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int modifyEmployees(Employee list[], int len)
{
	int todoOk = 0;
	int idPersona;
	int indicePersona;
	char confirmacion;
	char continuar;
	int opcion;
	Employee auxEmpleado;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("-------------------------------------------------------------------\n");
		printf("                *** Modificar Persona ***                      \n");
		printf("-------------------------------------------------------------------\n");
		printEmployees(list, len);
		printf("\n\n");
		printf("Ingrese su ID: \n");
		scanf("%d", &idPersona);

		indicePersona = findEmployeeById(list, len, idPersona);

		if(indicePersona == -1)
		{
			printf("El ID ingresado no existe. Por favor ingrese un ID valido\n");
		}
		else
		{
			printf("-----------------------------------------------------------------------------------------\n");
			printf("ID    |Nombre                        |Apellido                      |Salario    |Sector  \n");
			printf("-----------------------------------------------------------------------------------------\n\n");
			mostrarPersona(list[indicePersona]);

			printf("\nEsta es la persona que desea modificar? s/n\n");
			fflush(stdin);
			scanf("%c", &confirmacion);
			if(confirmacion == 's')
			{
				do
				{
					opcion = subMenuDeModificaciones();
					switch(opcion)
					{
						case 1:
							// Reduje los caracteres a 30 porque me parecio demasiado que sea de 50 y el encolumnado a la hora de mostrarlo me quedaba mal.
							pedirCadena(auxEmpleado.name, "Ingrese su nombre, no mas de 30 caracteres.\n", "Error. Ingrese su nombre nuevamente, no mas de 30 caracteres.\n", 30);
							strcpy(list[indicePersona].name, auxEmpleado.name);
							printf("Modificacion exitosa!!!\n");
							break;
						case 2:
							// Reduje los caracteres a 30 porque me parecio demasiado que sea de 50 y el encolumnado a la hora de mostrarlo me quedaba mal.
							pedirCadena(auxEmpleado.lastName, "Ingrese su apellido, no mas de 30 caracteres.\n", "Error. Ingrese su apellido nuevamente, no mas de 30 caracteres.\n", 30);
							strcpy(list[indicePersona].lastName, auxEmpleado.lastName);
							printf("Modificacion exitosa!!!\n");
							break;
						case 3:
							pedirFlotante(&auxEmpleado.salary, "Ingrese su salario entre 30000 y 150000.\n", "Error. Ingrese su salario nuevamente entre 30000 y 150000.\n", 30000, 150000);
							list[indicePersona].salary = auxEmpleado.salary;
							printf("Modificacion exitosa!!!\n");
							break;
						case 4:
							pedirEntero(&auxEmpleado.sector, "Ingrese su sector entre 1 y 10.\n", "Error. Ingrese su sector nuevamente entre 1 y 10.\n", 1 , 10);
							list[indicePersona].sector = auxEmpleado.sector;
							printf("Modificacion exitosa!!!\n");
							break;
						default:
							printf("Opcion Invalida!!!\n");
							break;
					}
					if(opcion > 0 && opcion < 5)
					{
						printf("-----------------------------------------------------------------------------------------\n");
						printf("ID    |Nombre                        |Apellido                      |Salario    |Sector  \n");
						printf("-----------------------------------------------------------------------------------------\n\n");
						mostrarPersona(list[indicePersona]);
						printf("\nDesea modificar algun dato mas? s/n\n");
						fflush(stdin);
						scanf("%c", &continuar);
					}
				}while(continuar == 's');
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int totalYPromedioSalarios(Employee list[], int len)
{
    int todoOk = 0;
    float acumSalario = 0;
    float promedioSalario;
    int contadorPersonas = 0;
    int contadorSalarioPromedioMayor = 0;


    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len ; i++)
        {
            if(list[i].isEmpty == 0)
            {
                acumSalario += list[i].salary;
                contadorPersonas++;
            }
        }
        if(contadorPersonas != 0)
        {
            promedioSalario = acumSalario / contadorPersonas;
        }

        for(int i = 0; i < len ; i++)
        {
            if(list[i].isEmpty == 0 && list[i].salary > promedioSalario)
            {
                contadorSalarioPromedioMayor++;
            }
        }
        printf("El total de los salarios es: %.2f\n\n", acumSalario);
        printf("El promedio de los salarios es: %.2f\n\n", promedioSalario);
        printf("La cantidad de personas que superan el salario promedio es: %d\n\n",contadorSalarioPromedioMayor);

        printf("-----------------------------------------------------------------------------------------\n");
        printf("ID    |Nombre                        |Apellido                      |Salario    |Sector  \n");
        printf("-----------------------------------------------------------------------------------------\n\n");

        for(int i = 0; i < len ; i++)
        {
            if(list[i].isEmpty == 0 && list[i].salary > promedioSalario)
            {
                mostrarPersona(list[i]);
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int cambiarValorDeFlag(Employee list[], int tam, int* flag)
{
    int todoOk = 0;

    if(list != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            if(list[i].isEmpty == 1)
            {
                *flag = 0;
            }
            else
            {
                *flag = 1;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
