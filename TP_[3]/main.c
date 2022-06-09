/********************************************************************************************************
*   Programa: TP 3
*
*	Objetivo:
*		Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo, para lo cual
*			se deberá desarrollar una solución implementando la biblioteca LinkedList.
*
*		El sistema deberá tener el siguiente menú de opciones:
*		 	 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
*			 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
*			 3. Alta de pasajero
*			 4. Modificar datos de pasajero
*			 5. Baja de pasajero
*		 	 6. Listar pasajeros
*			 7. Ordenar pasajeros
*			 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
*			 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
*			10. Salir
*
*	Version: 0.7 del 9 de Junio de 2022
*	Autor: Agustin Sbernini
*
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Funciones_Extras.h"
#include "parser.h"

int main()
{
    int option;
    int guardado = 1;
    int cargarDatos = 0;
    int contadorPasajerosAgregados = 0;
    int errorEdit;
//    char* path = "data.csv";

    LinkedList* listaPasajeros = ll_newLinkedList();

    setbuf(stdout, NULL);

    do{
    	utn_getInt(&option,"\nMenu Principal:\n"
							"  1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
							"  2- Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
							"  3- Alta de pasajero.\n"
							"  4- Modificar datos de pasajero.\n"
							"  5- Baja de pasajero.\n"
							"  6- Listar pasajeros.\n"
							"  7- Ordenar pasajeros.\n"
							"  8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
							"  9- Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
							"  10- Salir.\n"
							"Elija una opción: ", "\nError. Elija una opción valida.\n",1,10);
        switch(option)
        {
            case 1:
            	if(cargarDatos == 0)
            	{
					if(controller_loadFromText("data.csv",listaPasajeros) == 0)
					{
						cargarDatos = 1;
						printf("\nLos datos han sido cargados exitosamente.\n");
						if(contadorPasajerosAgregados != 0)
						{
							if(controller_corregirId(listaPasajeros, contadorPasajerosAgregados) == 0)
							{
								printf("\nSe corrigieron los id de los pasajeros agregados anteriormente correctamente.\n");
							}
							else
							{
								printf("\nNo se pudieron corregir los id de los pasajeros agregados anteriormente.\n");
							}
						}
					}
					else
					{
						printf("\nLos datos no se han podido cargar.\n");
					}
            	}
            	else
            	{
            		printf("\nYa cargó los datos.\n");
            	}
                break;
            case 2:
            	if(cargarDatos == 0)
            	{
            		printf("\nEntro 2\n");
					cargarDatos = 1;
            	}
            	else
				{
					printf("\nYa cargó los datos.\n");
				}
            	break;
            case 3:
            	if(controller_addPassenger(listaPasajeros) == 0)
            	{
            		printf("\nSe ha agregado correctamente el pasajero.\n");
					guardado = 0;
					contadorPasajerosAgregados++;
            	}
            	else
            	{
            		printf("\nNo se ha podido agregar al pasajero.\n");
            	}
				break;
            case 4:
            	if(ll_len(listaPasajeros) != 0)
            	{
            		errorEdit = controller_editPassenger(listaPasajeros);
            		switch(errorEdit)
            		{
            		case -1:
            			printf("\nError. Se encontró un inconveniente en la lista.\n");
            			break;
            		case -2:
            			printf("Error. El id ingresado no coincide con ninguno en la lista\n");
            			break;
            		case -3:
            			printf("Error. Hubo un inconveniente al intentar obtener los datos del pasajero.\n");
            			break;
            		}
            	}
            	else
            	{
            		printf("\nTodavía no ingresó ningún pasajero.\n");
            	}
            	guardado = 0;
				break;
            case 5:
            	guardado = 0;
				break;
            case 6:
            	controller_ListPassenger(listaPasajeros);
				break;
            case 7:
            	guardado = 0;
				break;
            case 8:
            	printf("\nSe guardo con exito los datos de los pasajeros en el archivo data.csv (modo texto).\n");
            	guardado = 1;
				break;
            case 9:
				printf("\nSe guardo con exito los datos de los pasajeros en el archivo data.csv (modo binario).\n");
            	guardado = 1;
				break;
            default:
            	if(guardado == 0)
            	{
            		printf("\nError. No puede cerrar el sistema sin guardar los datos antes\n");
            	}
            	else
            	{
            		printf("\nCerrando sistema.\n");
            	}
        }
    }while(option != 10 || guardado != 1);

    printf("ya se cerro");
    return 0;
}

