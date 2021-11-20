/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"
#include "../inc/inputs.h"

int main(void)
{
	setbuf(stdout,NULL);
	/*startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort */

  /*// ll_newLinkedList  //Usada en main - Linea 78
	// ll_len  //Usada en Controller.c - controller_ListEmployee - linea 446
	// getNode - test_getNode
	// addNode - test_addNode
	// ll_add //Usada en Controller.c - controller_addEmployee - linea 95
	// ll_get //Usada en Controller.c - controller_validarId - linea 39
	// ll_set //Usada en Controller.c - controller_altaEmpleadoConReemplazo - linea 168
	// ll_remove //Usada en Controller.c - controller_removeEmployee - linea 417
	// ll_clear //Usada en main - linea 97
	// ll_deleteLinkedList //Usada en Controller.c - controller_sortEmployee - linea 510
	// ll_indexOf //Usada en Controller.c - controller_eliminarEmpleadoConMasHoras - linea 282
	// ll_isEmpty //Usada en Controller.c - controller_sortEmployee - linea 469
	// ll_push //Usada en Controller.c - controller_altaEligiendoPosicion - 242
	// ll_pop //Usada en Controller.c - controller_eliminarEmpleadoConMasHoras - linea 288
	// ll_contains //Usada en Controller.c - controller_altaEligiendoPosicion - linea 230
	// ll_containsAll //Usada en Controller.c - controller_sortEmployee - linea 469
	// ll_subList //Usada en Controller.c - controller_crearSublista - linea 608
	// ll_clone //Usada en Controller.c - controller_sortEmployee - linea 467
	// ll_sort //Usada en Controller.c - controller_sortEmployee - linea 474 */
	// El proyecto tiene 4 warnings pero son de los testing y no quise meter mano en las bibliotecas de los testing por si se rompe todo.
	setbuf(stdout,NULL);
	char seguir = 'n';
	int banderaDatosTexto = 0;
	char opcion;

	LinkedList* listaEmpleados = ll_newLinkedList();
	do{
		switch(menu())
		{
			case 1:
				if(banderaDatosTexto == 0)
				{
					controller_loadFromText("dataEmpleados.csv",listaEmpleados);
					banderaDatosTexto = 1;
				}
				else
				{
					printf("No puede volver a cargar la lista una vez cargada.\n");
				}
				break;
			case 2:
				if(listaEmpleados->size)
				{
					pedirCaracter(&opcion, "Esta seguro que desea borrar los datos? s(si) n(no)\n", "Error. Ingrese la opcion nuevamente.Esta seguro que desea borrar los datos? s(si) n(no)\n", 's', 'n');
					if(opcion == 's')
					{
						if(ll_clear(listaEmpleados) == 0)
						{
							printf("Lista vaciada exitosamente \n");
							banderaDatosTexto = 0;
						}
						else
						{
							printf("Hubo un problema al vaciar la lista\n");
						}
					}
				}
				break;
			case 3:
				controller_addEmployee(listaEmpleados);
				break;
			case 4:
				if(listaEmpleados->size)
				{

					controller_altaEmpleadoConReemplazo(listaEmpleados);
				}
				else
				{
					printf("Al menos debe dar de alta un empleado o cargar una lista para poder dar de alta y reemplazar.\n");
				}
				break;
			case 5:
				if(listaEmpleados->size)
				{
					controller_altaEligiendoPosicion(listaEmpleados);
				}
				else
				{
					printf("Al menos debe dar de alta un empleado o cargar una lista para poder dar de alta y elegir posicion.\n");
				}
				break;
			case 6:
				if(listaEmpleados->size)
				{
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("Al menos debe dar de alta un empleado para poder entrar a la opcion modificar.\n");
				}
				break;
			case 7:
				if(listaEmpleados->size)
				{
					controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("Al menos debe dar de alta un empleado o cargar una lista para poder entrar a la opcion dar de baja.\n");
				}
				break;
			case 8:
				if(listaEmpleados->size)
				{
					controller_eliminarEmpleadoConMasHoras(listaEmpleados);
				}
				else
				{
					printf("Al menos debe dar de alta un empleado o cargar una lista para poder entrar a la opcion Buscar y elminar el empleado con mas horas trabajadas.\n");
				}
				break;
			case 9:
				if(listaEmpleados->size)
				{
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("Al menos debe dar de alta un empleado para poder entrar a la opcion listar empleados.\n");
				}
				break;
			case 10:
				if(listaEmpleados->size)
				{
					controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("Al menos debe dar de alta un empleado para poder entrar a la opcion ordenar empleados.\n");
				}
				break;
			case 11:
				if(listaEmpleados->size)
				{
					controller_crearSublista(listaEmpleados);
				}
				else
				{
					printf("Al menos debe dar de alta un empleado o cargar una lista para poder crear una sublista.\n");
				}
				break;
			case 12:
				if(listaEmpleados->size)
				{
					controller_saveAsText("dataEmpleados.csv", listaEmpleados);
					printf("Guardado Exitoso!!!\n");
				}
				else
				{
					printf("Al menos debe dar de alta un empleado o cargar una lista para poder guardarla en modo texto.\n");
				}
				break;
			case 13:
				pedirCaracter(&seguir, "¿Esta seguro que desea salir? s(si) y n(no).", "Error. letra invalida. Ingrese s si desea salir o n para continuar.", 's', 'n');
				fflush(stdin);
				if(seguir == 's')
				{
					ll_deleteLinkedList(listaEmpleados);
					printf("Gracias por todo. Hasta la proxima!!!\n");
				}
				break;
			default:
				printf("Opcion invalida!!!\n");
				break;
		}
	}while(seguir == 'n');

    return 0;
}
