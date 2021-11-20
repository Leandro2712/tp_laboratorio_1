#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/inputs.h"

int menu()
{
    int opcion;

    system("cls");
    printf("                *** Menu de Empleados ***                     \n");
    printf("-------------------------------------------------\n");
    printf("   1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("   2. Limpiar lista de empleados\n");
    printf("   3. Alta de empleado.\n");
    printf("   4. Alta de empleado con reemplazo.\n");
    printf("   5. Alta de empleado eligiendo posicion.\n");
    printf("   6. Modificar datos de empleado.\n");
    printf("   7. Baja de empleado.\n");
    printf("   8. Buscar y elminar el empleado con mas horas trabajadas.\n");
    printf("   9. Listar empleados.\n");
    printf("   10. Ordenar empleados.\n");
    printf("   11. Crear sublista.\n");
    printf("   12. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("   13. Salir.\n");

    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuDeModificaciones()
{
    int opcion;

    system("cls");
    printf("        *** Menu de Modificaciones ***          \n");
    printf("------------------------------------------------\n");
    printf("   1- Nombre.\n");
    printf("   2- Horas Trabajadas.\n");
    printf("   3- Sueldo.\n");
    printf("   4- Salir\n.");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);
    fflush(stdin);

    return opcion;
}

int menuDeCriterio()
{
    int opcion;

    system("cls");
    printf("        *** Menu de Criterio ***          \n");
    printf("------------------------------------------------\n");
    printf("   0- Descendente. (Z-A) (9-0)\n");
    printf("   1- Ascendente.(A-Z) (0-9)\n");
    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int menuDeOrdenamiento()
{
    int opcion;

    system("cls");
    printf("        *** Menu de Ordenamiento ***            \n");
    printf("------------------------------------------------\n");
    printf("   1- ID.\n");
    printf("   2- Nombre.\n");
    printf("   3- Horas Trabajadas.\n");
    printf("   4- Sueldo.\n");
    printf("   5- Salir.\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int ordenarCaracteresMayuscula(char name[])
{
    int todoOk = 0;
    int i = 0;

    if(name != NULL)
    {
        strlwr(name);
        name[0] = toupper(name[0]);

        while(name[i] != '\0')
        {
            if(name[i] == ' ')
            {
                name[i + 1] = toupper(name [i + 1]);
            }
            i++;
        }
        todoOk = 1;
    }
    return todoOk;
}

int soloLetras(char name[])
{
    int i = 0;
    int todoOk;

    if(name != NULL)
    {
        while(name[i] != '\0')
        {
            if(!isalpha(name[i]) && name[i] != ' ')
            {
				todoOk = 0;

				while(todoOk == 0)
				{
					printf("Error. Ingreselo nuevamente solo con letras(hasta 30 caracteres)\n");
					fflush(stdin);
					gets(name);
					i = 0;
					todoOk = 1;
				}
            }
            i++;
        }
    }
    return todoOk;
}

int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int todoOk = -1;
	char buffer[256];

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(buffer);

		soloLetras(buffer);
		fflush(stdin);

		while(strlen(buffer)>max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(buffer);
			soloLetras(buffer);
		}

		ordenarCaracteresMayuscula(buffer);

		strcpy(cadena, buffer);
		todoOk = 0;
	}
	return todoOk;
}

int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
	int todoOk = -1;
	float numeroIngresado;

	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotante = numeroIngresado;
		todoOk = 0;
	}

	return todoOk;
}

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int todoOk = -1;
	char enteroJr[128];

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		gets(enteroJr);
		fflush(stdin);

		while(validarNumeros(enteroJr) == 0 || atoi(enteroJr) < min || atoi(enteroJr) > max)
		{
			printf("%s", mensajeError);
			gets(enteroJr);
			fflush(stdin);
		}

		*entero = atoi(enteroJr);
		todoOk = 0;
	}

	return todoOk;
}

int validarNumeros(char numeros[])
{
	int todoOk=1;
	if(strlen(numeros) > 0)
		{
			for(int i = 0;i< strlen(numeros);i++)
			{
				if(isdigit(numeros[i]) == 0)
				{
					if(i == 0 && numeros[0] == '-')
					{
	                    todoOk = 1;
					}
					else
					{
						todoOk =0;
					}
				}
			}
		}
	    else
	    {
	        todoOk=0;
	    }
	return todoOk;
}


/*int cambiarValorDeFlag(eBicicleta bicicletas[], int tamBic, int* flag)
{
    int todoOk = 0;

    if(bicicletas != NULL && tamBic > 0)
    {
        for(int i = 0; i < tamBic ; i++)
        {
            if(bicicletas[i].isEmpty == 1)
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
}*/

int pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2)
{
	int todoOk = -1;
	char caracterIngresado;

	if(caracter != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado = tolower(caracterIngresado);

		while(caracterIngresado != caracterVal1 && caracterIngresado != caracterVal2)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado = tolower(caracterIngresado);
		}
		*caracter=caracterIngresado;
		todoOk=0;
	}
	return todoOk;
}
