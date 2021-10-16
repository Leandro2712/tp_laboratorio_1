/*
 * inputs.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Leandro Sebastian Avalos
 */

#ifndef INPUTS_H_
#define INPUTS_H_



#endif /* INPUTS_H_ */

/**
 * @fn int pedirCadena(char*, char*, char*, int)
 * @brief Funcion que sirve para pedir una cadena de caractares y se valida el rango de la cadena de caracteres que no supere el maximo indicado y llama a otras 2 funciones una para que no ingresen numeros en la cadena y la otra para que ordene las letras de manera tal que si ingresan un nombre o un apellido la primera letra sea mayuscula.
 *
 * @param cadena Puntero a char que recibe la cadena de caracteres.
 * @param mensaje Mensaje ingresado para el usuario.
 * @param mensajeError Mensaje de error para el usuario.
 * @param max Maximo de caracteres que puede ingresar el usuario.
 * @return Retorna -1 si fallo. Retorna 0 si esta todo OK.
 */
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);

/**
 * @fn int pedirFlotante(float*, char*, char*, float, float)
 * @brief Funcion que sirve para pedir un valor flotante y valida que no supere el rango designado en la funcion.
 *
 * @param flotante Valor flotante ingresado por usuario.
 * @param mensaje Mensaje ingresado para el usuario.
 * @param mensajeError Mensaje de error para el usuario.
 * @param min Valor minimo que puede ingresar el usuario.
 * @param max Valor maximo que puede ingresar el usuario.
 * @return Retorna -1 si fallo. Retorna 0 si esta todo OK.
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);

/**
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief Funcion que sirve para pedir un valor entero y valida que no supere el rango designado en la funcion.
 *
 * @param entero Valor entero ingresado por usuario.
 * @param mensaje Mensaje ingresado para el usuario.
 * @param mensajeError Mensaje de error para el usuario.
 * @param min Valor minimo que puede ingresar el usuario.
 * @param max Valor maximo que puede ingresar el usuario.
 * @return Retorna -1 si fallo. Retorna 0 si esta todo OK.
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);

/**
 * @fn int ordenarCaracteresMayuscula(char[])
 * @brief Funcion que sirve para ordenar la primera letra de los caracteres ingresados en mayuscula.
 *
 * @param name Puntero a array de caracteres.
 * @return Retorna 1 si esta todo OK. Retorna 0 si fallo.
 */
int ordenarCaracteresMayuscula(char name[]);

/**
 * @fn int soloLetras(char[])
 * @brief Funcion que sirve para chequear que no se ingrese ningun numero en el array de caracteres.
 *
 * @param name Puntero a array de caracteres.
 * @return Retorna 0 si fallo y retorna 1 si esta todo OK.
 */
int soloLetras(char name[]);
