#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    char seguir = 'n';
    int banderaDatosTexto = 0;
    int banderaDatosBinario = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
            	if(banderaDatosTexto == 0 && banderaDatosBinario == 1)
            	{
            		printf("No se puede cargar la lista en modo texto si ya se cargo en modo binario.\n");
            	}
            	else if(banderaDatosTexto == 0)
            	{
            		controller_loadFromText("data.csv",listaEmpleados);
					banderaDatosTexto = 1;
            	}
            	else
            	{
            		printf("No puede volver a cargar la lista una vez cargada.\n");
            	}
                break;
            case 2:
            	if(banderaDatosBinario == 0 && banderaDatosTexto == 1)
            	{
            		printf("No se puede cargar la lista en modo binario si ya se cargo en modo texto.\n");
            	}
            	else if(banderaDatosBinario == 0)
            	{
            		controller_loadFromBinary("data.bin", listaEmpleados);
					banderaDatosBinario = 1;
            	}
            	else
            	{
            		printf("No puede volver a cargar la lista una vez cargada.\n");
            	}
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
                break;
            case 4:
            	if(listaEmpleados->size)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Al menos debe dar de alta un empleado para poder entrar a la opcion modificar.\n");
            	}
            	break;
            case 5:
            	if(listaEmpleados->size)
            	{
            		controller_removeEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Al menos debe dar de alta un empleado para poder entrar a la opcion dar de baja.\n");
            	}
            	break;
            case 6:
            	if(listaEmpleados->size)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Al menos debe dar de alta un empleado para poder entrar a la opcion listar empleados.\n");
            	}
            	break;
            case 7:
            	if(listaEmpleados->size)
            	{
            		controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Al menos debe dar de alta un empleado para poder entrar a la opcion ordenar empleados.\n");
            	}
            	break;
            case 8:
            	if(listaEmpleados->size)
            	{
            		controller_saveAsText("data.csv", listaEmpleados);
            		printf("Guardado Exitoso!!!\n");
            	}
            	else
            	{
            		printf("Al menos debe dar de alta un empleado o cargar una lista para poder guardarla en modo texto.\n");
            	}
            	break;
            case 9:
            	if(listaEmpleados->size)
            	{
            		controller_saveAsBinary("data.bin", listaEmpleados);
               		printf("Guardado Exitoso!!!\n");
            	}
            	else
            	{
            		printf("Al menos debe dar de alta un empleado o cargar una lista para poder guardarla en modo binario.\n");
            	}
            	break;
            case 10:
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

