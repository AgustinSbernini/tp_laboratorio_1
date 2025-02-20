/********************************************************************************************************
*   Programa: TP 3
*
*	Objetivo:
*		Una aerol�nea requiere un sistema para administrar los pasajeros de cada vuelo, para lo cual
*			se deber� desarrollar una soluci�n implementando la biblioteca LinkedList.
*
*		El sistema deber� tener el siguiente men� de opciones:
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
    int len;
    int cargarDatos = 0;
    int contadorPasajerosAgregados = 0;
    int contadorPasajerosAgregadosAntesGuardar = 0;
    int contadorPasajerosBorrados = 0;
    int contadorPasajerosBorradosDespuesDeGuardar = 0;
    int errorEdit;
    int errorRemover;
    int opcionesSort;
    int controlId = 0;
    int cantidadPasajerosLista = 0;
    int ultimoId;

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
							"Elija una opci�n: ", "\nError. Elija una opci�n valida.\n",1,10);
    	len = ll_len(listaPasajeros);
        switch(option)
        {
            case 1:
            	if(cargarDatos == 0)
            	{
					if(controller_loadFromText("data.csv",listaPasajeros) == 0)
					{
						cargarDatos = 1;
						printf("\nLos datos han sido cargados exitosamente desde el modo texto.\n");
						if(contadorPasajerosAgregados != 0 && controlId == 0)
						{
							if(controller_controlarId("data.csv", listaPasajeros, contadorPasajerosAgregados, contadorPasajerosBorrados, &ultimoId) != -1)
							{
								printf("\nSe corrigieron los id de los pasajeros agregados anteriormente correctamente.\n");
								controlId = 1;
							}
							else
							{
								printf("\nNo se pudieron corregir los id de los pasajeros agregados anteriormente.\n");
							}
						}
						else
						{
							controller_controlarRepetidos(listaPasajeros, contadorPasajerosAgregadosAntesGuardar);
						}
					}
					else
					{
						printf("\nLos datos no se han podido cargar.\n");
					}
            	}
            	else
            	{
            		printf("\nYa carg� los datos.\n");
            	}
                break;
            case 2:
            	if(cargarDatos == 0)
            	{
					if(controller_loadFromBinary("data.bin",listaPasajeros) == 0)
					{
						cargarDatos = 1;
						printf("\nLos datos han sido cargados exitosamente desde el modo binario.\n");
						if(contadorPasajerosAgregados != 0 && controlId == 0)
						{
							if(controller_controlarId("data.csv", listaPasajeros, contadorPasajerosAgregados, contadorPasajerosBorrados, &ultimoId) != -1)
							{
								printf("\nSe corrigieron los id de los pasajeros agregados anteriormente correctamente.\n");
								controlId = 1;
							}
							else
							{
								printf("\nNo se pudieron corregir los id de los pasajeros agregados anteriormente.\n");
							}
						}
						else
						{
							controller_controlarRepetidos(listaPasajeros, contadorPasajerosAgregadosAntesGuardar);
						}
					}
					else
					{
						printf("\nLos datos no se han podido cargar.\n");
					}
            	}
            	else
            	{
            		printf("\nYa carg� los datos.\n");
            	}
            	break;
            case 3:
            	if(controller_addPassenger(listaPasajeros, contadorPasajerosBorrados, contadorPasajerosBorradosDespuesDeGuardar, cantidadPasajerosLista, controlId, ultimoId, cargarDatos) == 0)
            	{
            		printf("\nSe ha agregado correctamente el pasajero.\n");
					guardado = 0;
					contadorPasajerosAgregados++;
					if(cargarDatos != 1)
					{
						contadorPasajerosAgregadosAntesGuardar++;
					}
            	}
            	else
            	{
            		printf("\nNo se ha podido agregar al pasajero.\n");
            	}
            	printf("\nVolviendo al menu principal.\n");
				break;
            case 4:
            	if(len != 0)
            	{
            		errorEdit = controller_editPassenger(listaPasajeros);
            		switch(errorEdit)
            		{
            		case -1:
            			printf("\nError. Se encontr� un inconveniente en la lista.\n");
            			break;
            		case -2:
            			printf("Error. El id ingresado no coincide con ninguno en la lista\n");
            			break;
            		case -3:
            			printf("Error. Hubo un inconveniente al intentar obtener los datos del pasajero.\n");
            			break;
            		default:
            			guardado = 0;
            		}
            	}
            	else
            	{
            		printf("\nTodav�a no ingres� ning�n pasajero.\n");
            	}
            	printf("\nVolviendo al menu principal.\n");
				break;
            case 5:
            	errorRemover = controller_removePassenger(listaPasajeros);
            	switch(errorRemover)
            	{
            	case 0:
					contadorPasajerosBorrados++;
					printf("\nSe ha dado de baja correctamente al pasajero de la lista.\n");
					if(controlId == 2)
					{
						contadorPasajerosBorradosDespuesDeGuardar++;
					}
					guardado = 0;
					break;
            	case -1:
            		printf("\nError. La lista se encuentra vacia.\n");
					break;
            	case -2:
            		printf("\nError. El id ingresado no coincide con ningun pasajero de la lista.\n");
            		break;
            	case -3:
            		printf("\nSe ha cancelado la bajada del pasajero de la lista.\n");
            		break;
            	}
            	printf("\nVolviendo al menu principal.\n");
				break;
            case 6:
            	if(controller_ListPassenger(listaPasajeros) != 0)
            	{
            		printf("\nError. La lista se encuentra vac�a.\n");
					printf("\nVolviendo al menu principal.\n");
            	}
				break;
            case 7:
            	opcionesSort = controller_sortPassenger(listaPasajeros);
            	switch(opcionesSort)
            	{
            	case 1:
            		printf("\nSe orden� correctamente los pasajeros por id.\n");
            		break;
            	case 2:
            		printf("\nSe orden� correctamente los pasajeros por apellido.\n");
            		break;
            	case 3:
            		printf("\nSe orden� correctamente los pasajeros por tipo de pasajero.\n");
            		break;
            	case 4:
            		printf("\nSe orden� correctamente los pasajeros por codigo de vuelo.\n");
            		break;
            	default:
            		printf("\nError. No se pudo ordenar correctamente los pasajeros.\n");
            	}
				break;
            case 8:
            case 9:
            	if(cargarDatos == 0 && controlId == 0)
            	{
            		cantidadPasajerosLista = controller_controlarId("data.csv", listaPasajeros, contadorPasajerosAgregados, contadorPasajerosBorrados, &ultimoId);
            		if(cantidadPasajerosLista != -1)
            		{
						controlId = 2;
            		}
            		else
            		{
            			printf("\nError.No se pudo corregir los id de los nuevos pasajeros ingresados al guardar.\n");
            		}
            	}
            	ll_sort(listaPasajeros, Passenger_sortById, 1);
            	if(controller_saveAsText("data.csv", listaPasajeros, cargarDatos) == 0)
            	{
            		if(controller_saveAsBinary("data.bin", listaPasajeros, cargarDatos) == 0)
            		{
						printf("\nSe guardo con exito los datos de los pasajeros en el archivo data.csv.\n");
						guardado = 1;
            		}
            	}
            	else
            	{
					printf("\nError. No se pudo guardar los datos de los pasajeros en el archivo data.csv.\n");
            	}
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

    return 0;
}

