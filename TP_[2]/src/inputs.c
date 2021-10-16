/*
 * inputs.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Leandro Sebastian Avalos
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include <ctype.h>
#include <string.h>

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
    int todoOk = 1;

    if(name != NULL)
    {
        while(name[i] != '\0')
        {
            if(name[i] != ' ')
            {
                if((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z'))
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
	int retorno = -1;
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
		retorno = 0;
	}

	return retorno;
}

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

