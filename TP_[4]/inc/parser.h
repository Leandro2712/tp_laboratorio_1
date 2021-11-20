/*
 * parser.h
 *
 *  Created on: 12 nov. 2021
 *      Author: Avalos Leandro Sebastian
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */

/**
 * @fn int parser_EmployeeFromText(FILE*, LinkedList*)
 * @brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * @param pFile Direccion de memoria del archivo que sera parseado.
 * @param pArrayListEmployee puntero a la lista de empleados.
 * @return Retorna 1 si esta todo OK y 0 si fallo.
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
