/*
 * bibliotecaAvalos.c
 *
 *  Created on: 12 sep. 2021
 *      Author: Avalos Leandro Sebastian
 */
#include "bibliotecaAvalos.h"
#include <stdio.h>
#include <stdlib.h>


int mostrarMenu(int banderaUno, float primerNumero, int banderaDos, float segundoNumero)
{

    int opcion;

    system("cls");
    printf("Menu de opciones : \n\n");
    if(banderaUno == 0)
    {
    	printf("1. Ingresar primer operando : \n");
    }
    else
    {
    	printf("1. Ingresar primer operando: (A = %.2f)\n", primerNumero);
    }

    if(banderaDos == 0)
    {
    	printf("2. Ingresar segundo operando: \n");
    }
    else
    {
    	printf("2. Ingresar segundo operando: (B = %.2f)\n", segundoNumero);
    }
    printf("3. Calcular todas las operaciones :\n");
    printf("	a) Calcular la suma (A+B)\n");
    printf("	a) Calcular la resta (A-B)\n");
    printf("	a) Calcular la division (A/B)\n");
    printf("	a) Calcular la multiplicacion (A*B)\n");
    printf("	a) Calcular el factorial (A! y B!)\n");
    printf("4. Informar resultados :\n");
    printf("5. Salir :\n\n");
    printf("¿Que opcion desea elegir?\n");
    scanf("%d",&opcion);
    return opcion;
}

float ingresarEntero(char mensaje[])
{
    float numeroIngresado;
    printf("%s",mensaje);
    scanf("%f",&numeroIngresado);

    return numeroIngresado;
}

float sumar(float numeroUno, float numeroDos)
{
	float resultadoSuma = 0;

	resultadoSuma = numeroUno + numeroDos;

	return resultadoSuma;
}

float restar(float numeroUno, float numeroDos)
{
	float resultadoResta = 0;

	resultadoResta = numeroUno - numeroDos;

	return resultadoResta;
}

int dividir(float numeroUno, float numeroDos, float* resultadoDivision)
{
	int todoOk = 0;

	if(numeroDos != 0 && resultadoDivision != NULL)
	{
		*resultadoDivision = numeroUno / numeroDos;
		todoOk = 1;
	}

	return todoOk;
}

float multiplicar(float numeroUno, float numeroDos)
{
	float resultadoMultiplicacion;

	resultadoMultiplicacion = numeroUno * numeroDos;

	return resultadoMultiplicacion;
}

int sacarFactorial(float numero, int* resultado)
{
	/*En esta funcion utilizo una variable auxiliar donde le asigno el numero flotante
	 ingresado por el usuario para tomar su parte entera. Luego en un IF compruebo si la resta
	 entre el numero ingresado por el usuario y el numero guardado en la variable auxiliar da 0.
	 De ser asi es porque es un numero entero y se puede realizar el factorial. De no ser asi
	 quiero decir que es un numeor flotante por ende el factorial no puede realizarse.*/
    int i;
    int factorial = 1;
    int todoOk = 0;
    int numeroEntero;

    numeroEntero = numero;

    if(numero >= 0 && resultado != NULL && numeroEntero - numero == 0)
    {
    	for(i=1;i<=numero;i++)
		{
			factorial=factorial*i;
		}
    	*resultado = factorial;
    	todoOk = 1;
    }

    return todoOk;
}

int realizarOperaciones(float numeroUno, float numeroDos, float* suma, float* resta, int* division, float* resultadoDivision, float* multiplicacion, int* factorialA, int* factorialB, int* resultadofactorialA, int* resultadoFactorialB)
{
	int todoOk = 0;
	if(suma != NULL && resta != NULL && division != NULL && resultadoDivision != NULL && multiplicacion != NULL && factorialA != NULL && factorialB != NULL && resultadofactorialA != NULL && resultadoFactorialB != NULL)
	{
		*suma = sumar(numeroUno, numeroDos);
		*resta = restar(numeroUno, numeroDos);
		*division = dividir(numeroUno, numeroDos, &*resultadoDivision);
		*multiplicacion = multiplicar(numeroUno, numeroDos);
		*factorialA = sacarFactorial(numeroUno, &*resultadofactorialA);
		*factorialB = sacarFactorial(numeroDos, &*resultadoFactorialB);

		todoOk = 1;
	}

	return todoOk;
}

void mostrarResultados(float numeroUno, float numeroDos, float suma, float resta, int division, float resultadoDivision, float multiplicacion, int factorialA, int factorialB, int resultadoFactorialA, int resultadoFactorialB)
{
	printf("El resultado de la suma de %.2f + %.2f es: %.2f\n", numeroUno, numeroDos, suma);
	printf("El resultado de la resta de %.2f - %.2f es: %.2f\n",numeroUno, numeroDos, resta);
	if(division == 1)
	{
		printf("El resultado de la division de %.2f / %.2f es: %.2f\n",numeroUno, numeroDos, resultadoDivision);
	}
	else
	{
		printf("No se pudo realizar la division\n");
	}
	printf("El resultado de la multiplicacion de %.2f * %.2f es: %.2f\n",numeroUno, numeroDos, multiplicacion);
	if(factorialA == 1)
	{
		printf("El factorial de A es: %d\n", resultadoFactorialA);
	}
	else
	{
		printf("No se pudo realizar el factorial de A\n");
	}
	if(factorialB == 1)
	{
		printf("El factorial de B es: %d\n", resultadoFactorialB);
	}
	else
	{
		printf("No se pudo realizar el factorial de B\n");
	}
}
