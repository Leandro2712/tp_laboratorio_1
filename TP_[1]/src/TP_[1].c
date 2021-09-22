/*
 ============================================================================
 Name        : TP_1.c
 Author      : Avalos Leandro Sebastian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bibliotecaAvalos.h"

int main(void) {

	setbuf(stdout,NULL);

	char seguir = 'n';
	float primerNumero;
	int banderaPrimerNumero = 0;
	float segundoNumero;
	int banderaSegundoNumero = 0;
	char reescribirPrimerOperador;
	char reescribirSegundoOperador;
	float suma;
	float resta;
	float resultadoDivision;
	float multiplicacion;
	int factorialA;
	int resultadoFactorialA;
	int resultadoFactorialB;
	int factorialB;
	int division;
	int banderaRealizoOperaciones = 0;

	do
	{
		switch(mostrarMenu(banderaPrimerNumero, primerNumero, banderaSegundoNumero, segundoNumero))
		{
			case 1:
				if(banderaPrimerNumero == 0)
				{
					primerNumero = ingresarEntero("Ingrese el primer numero a operar: \n");
					banderaPrimerNumero = 1;
				}
				else if(banderaPrimerNumero == 1)
				{
					printf("¿Desea reescribir el primero operador? s/n \n");
					fflush(stdin);
					scanf("%c", &reescribirPrimerOperador);

					if(reescribirPrimerOperador == 's')
					{
						primerNumero = ingresarEntero("Ingrese el primer numero a operar: \n");
					}
				}
				break;
			case 2:
				if(banderaPrimerNumero == 0)
				{
					printf("Primero debes ingresar el primer operador antes de ingresar el segundo\n");
				}
				else if(banderaSegundoNumero == 0)
				{
					segundoNumero = ingresarEntero("Ingrese el segundo numero a operar: \n");
					banderaSegundoNumero = 1;
				}
				else if(banderaSegundoNumero == 1)
				{
					printf("¿Desea reescribir el segundo operando? s/n \n");
					fflush(stdin);
					scanf("%c", &reescribirSegundoOperador);

					if(reescribirSegundoOperador == 's')
					{
						segundoNumero = ingresarEntero("Ingrese el segundo numero a operar: \n");
					}
				}
				break;
			case 3:
				if(banderaPrimerNumero == 0 && banderaSegundoNumero == 0)
				{
					printf("Primero debe ingresar ambos operadores antes de realizar las operaciones\n");
				}
				else if(banderaSegundoNumero == 0)
				{
					printf("Ingrese el segundo operador antes de realizar las operaciones\n");
				}
				else if(realizarOperaciones(primerNumero, segundoNumero, &suma, &resta, &division, &resultadoDivision, &multiplicacion, &factorialA, &factorialB, &resultadoFactorialA, &resultadoFactorialB))
				{
					realizarOperaciones(primerNumero, segundoNumero, &suma, &resta, &division, &resultadoDivision, &multiplicacion, &factorialA, &factorialB, &resultadoFactorialA, &resultadoFactorialB);
					printf("Las operaciones se realizaron con exito por favor seleccione la opcion 4 para mostrar los resultados\n");
					banderaRealizoOperaciones = 1;
				}
				else
				{
					printf("No se pudieron realizar las operaciones");
				}
				break;
			case 4:
				if(banderaRealizoOperaciones == 0)
				{
					printf("Primero debe ingresar los operadores y calcular las operaciones antes de recibir los resultados\n");
				}
				else
				{
					mostrarResultados(primerNumero, segundoNumero, suma, resta, division, resultadoDivision, multiplicacion, factorialA, factorialB, resultadoFactorialA, resultadoFactorialB);
					banderaPrimerNumero = 0;
					banderaSegundoNumero = 0;
					banderaRealizoOperaciones = 0;
				}
				break;
			case 5:
				printf("¿Esta seguro que desea salir? s/n \n");
				fflush(stdin);
				scanf("%c", &seguir);
				seguir = tolower(seguir);
				break;
			default:
				printf("Ingrese una opcion valida\n");
				break;
		}
		system("pause");
	}
	while(seguir == 'n');

	return EXIT_SUCCESS;
}
