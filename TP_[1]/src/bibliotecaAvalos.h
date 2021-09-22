/*
 * bibliotecaAvalos.h
 *
 *  Created on: 12 sep. 2021
 *      Author: Avalos Leandro Sebastian
 */

#ifndef BIBLIOTECAAVALOS_H_
#define BIBLIOTECAAVALOS_H_



#endif /* BIBLIOTECAAVALOS_H_ */

/**
 * @fn int mostrarMenu(int, float, int, float)
 * @brief Funcion que muestra un menu de opciones donde el usuario puede ingresar numeros a operar, calcular las operaciones, mostrar los resultados y salir.
 *
 * @param banderaUno Primera bandera inizializada en 0 para saber si el usuario ingreso el primer operando. Una vez ingresado el primer operando la bandera cambia su valor a 1 y se muestra el valor del primer operando en el menu.
 * @param primerNumero Primer operando ingresado por el usuario el cual aparecera en el menu.
 * @param banderaDos Segunda bandera inizializada en 0 para saber si el usuario ingreso el segundo operando. Una vez ingresado el segundo operando la bandera cambia su valor a 1 y se muestra el valor del segundo operando en el menu.
 * @param segundoNumero Segundo operando ingresado por el usuario el cual aparecera en el menu.
 * @return Retorna la opcion del menu elegida por el usuario.
 */
int mostrarMenu(int banderaUno, float primerNumero, int banderaDos, float segundoNumero);

/**
 * @fn float ingresarEntero(char[])
 * @brief Funcion para pedirle mediante un mensaje al usuario que ingrese un operando.
 *
 * @param mensaje Se le pide al usuario que ingrese un operando.
 * @return Retorna el operando ingresado por el usuario.
 */
float ingresarEntero(char mensaje[]);

/**
 * @fn float sumar(float, float)
 * @brief Funcion que recibe dos operandos flotantes y los suma.
 *
 * @param numeroUno Primer operando ingresado por el usuario.
 * @param numeroDos Segundo operando ingresado por el usuario.
 * @return Retorna el resultado de la suma entre los dos operandos ingresados por el usuario.
 */
float sumar(float numeroUno, float numeroDos);

/**
 * @fn float restar(float, float)
 * @brief Funcion que recibe dos operandos flotantes y los resta.
 *
 * @param numeroUno Primer operando ingresado por el usuario.
 * @param numeroDos Segundo operando ingresado por el usuario.
 * @return Retorna el resultado de la resta entre los dos operandos ingresados por el usuario.
 */
float restar(float numeroUno, float numeroDos);

/**
 * @fn int dividir(float, float, float*)
 * @brief Funcion que recibe dos operandos flotantes y los divide de ser posible.
 *
 * @param numeroUno Primer operando ingresado por el usuario.
 * @param numeroDos Segundo operando ingresado por el usuario.
 * @param resultadoDivision Puntero a float que retorna el resultado de la division si fue exitosa.
 * @return Retorna 1 si la division fue exitosa para luego mostrar el resultado. Retorna 0 si la division no logro realizarse.
 */
int dividir(float numeroUno, float numeroDos, float* resultadoDivision);

/**
 * @fn float multiplicar(float, float)
 * @brief Funcion que multiplica dos operandos flotantes ingresados por el usuario.
 *
 * @param numeroUno Primer operando ingresado por el usuario.
 * @param numeroDos Segundo operando ingresado por el usuario.
 * @return Retorna el resultado de la multiplicacion de los dos operandos ingresados por el usuario.
 */
float multiplicar(float numeroUno, float numeroDos);

/**
 * @fn int sacarFactorial(float, int*)
 * @brief Funcion que realiza el factorial de un entero.
 *
 * @param numero Operando ingresado por el usuario.
 * @param resultado Retorna el resultado del factorial si fue exitoso.
 * @return Retorna 1 si el factorial se pudo calcular. Retorna 0 si el factorial no logro realizarse.
 */
int sacarFactorial(float numero, int* resultado);

/**
 * @fn void mostrarResultados(float, float, float, float, int, float, float, int, int, int, int)
 * @brief Funcion que luego de recibir los resultados de cada operacion los muestra al usuario.
 *
 * @param numeroUno Primer numero ingresado por el usuario, el cual en el mensaje del resultado que reciba el usuario se mostrara con que operacion se lo utilizo.
 * @param numeroDos Segundo numero ingresado por el usuario, el cual en el mensaje del resultado que reciba el usuario se mostrara con que operacion se lo utilizo.
 * @param suma Parametro que contiene el resultado de la suma de los operandos ingresados por el usuario.
 * @param resta Parametro que contiene el resultado de la resta de los operandos ingreados por el usuario.
 * @param division Parametro que recibe el valor 1 si la division fue exitosa y recibe el valor 0 si no se pudo realizar la division.
 * @param resultadoDivision Parametro que recibe el resultado de la division de los operandos ingresados por el usuario.
 * @param multiplicacion Parametro que recibe el resultado de la multiplicacion de los operandos ingresados por el usuario.
 * @param factorialA Parametro que recibe el valor 1 si el factorial se pudo calcular y recibe el valor 0 si no se logro calcular.
 * @param factorialB Parametro que recibe el valor 1 si el factorial se pudo calcular y recibe el valor 0 si no se logro calcular.
 * @param resultadoFactorialA Parametro que recibe el resultado de calcular el factorial del primer operando si se logro exitosamente.
 * @param resultadoFactorialB Parametro que recibe el resultado de calcular el factorial del segundo operando si se logro exitosamente.
 */
void mostrarResultados(float numeroUno, float numeroDos, float suma, float resta, int division, float resultadoDivision, float multiplicacion, int factorialA, int factorialB, int resultadoFactorialA, int resultadoFactorialB);

/**
 * @fn int realizarOperaciones(float, float, float*, float*, int*, float*, float*, int*, int*, int*, int*)
 * @brief Funcion que llama a otras funciones para calcular todas las operaciones utilizando los operandos ingresados por el usuario.
 *
 * @param numeroUno Primer operando ingresado por el usuario el cual se utilizara para realizar las operaciones.
 * @param numeroDos Segundo operando ingresado por el usuario el cual se utilizara para realizar las operaciones.
 * @param suma Puntero a float el cual guarda en su direccion de memoria el resultado de la suma.
 * @param resta Puntero a float el cual guarda en su direccion de memoria el resultado de la resta.
 * @param division Puntero a entero el cual guarda en su direccion de memoria el valor 1 o 0 dependiendo si se logro o no realizar la division.
 * @param resultadoDivision Puntero a float el cual guarda en su direccion de memoria el resultado de la division si logro realizarse.
 * @param multiplicacion Puntero a float el cual guarda en su direccion de memoria el resultado de la multiplicacion.
 * @param factorialA Puntero a entero el cual guarda en su direccion de memoria el valor 1 o 0 dependiendo si se logro o no realizar el factorial del primer operando.
 * @param factorialB Puntero a entero el cual guarda en su direccion de memoria el valor 1 o 0 dependiendo si se logro o no realizar el factorial del segundo operando.
 * @param resultadofactorialA Puntero a entero el cual guarda en su direccion de memoria el resultado del factorial del primer operando.
 * @param resultadoFactorialB Puntero a entero el cual guarda en su direccion de memoria el resultado del factorial del segundo operando.
 * @return Retorna 1 o 0 si se logro realizar todas las operaciones.
 */
int realizarOperaciones(float numeroUno, float numeroDos, float* suma, float* resta, int* division, float* resultadoDivision, float* multiplicacion, int* factorialA, int* factorialB, int* resultadofactorialA, int* resultadoFactorialB);
