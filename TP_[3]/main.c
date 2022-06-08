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
*	Version: 0.1 del 1 de Junio de 2022
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
//    int cantElementosPasajeros;
    int cargarDatos = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
//    FILE* pFile;


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
					printf("\nEntro 1\n");
					if(controller_loadFromText("data.csv",listaPasajeros) == 0)
					{
						cargarDatos = 1;
						printf("\nLos datos han sido cargados exitosamente.\n");
					}
            	}
                break;
            case 2:
            	if(cargarDatos == 0)
            	{
            		printf("Entro 2");
					cargarDatos = 1;
            	}
            	break;
            case 3:
            	printf("Entro 3");
            	guardado = 0;
				break;
            case 4:
            	printf("Entro 4");
            	guardado = 0;
				break;
            case 5:
            	printf("Entro 5");
            	guardado = 0;
				break;
            case 6:
            	printf("Entro 6.\n");
            	controller_ListPassenger(listaPasajeros);
				break;
            case 7:
            	printf("Entro 7");
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

