#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Funciones_Extras.h"
int id = 0;

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		if (path != NULL)
		{
			FILE* pArchivo;
			pArchivo = fopen (path,"r");

			if(pArchivo != NULL)
			{
				if(parser_PassengerFromText(pArchivo, pArrayListPassenger) == 0)
				{
					retorno = 0;
				}
			}
			fclose(pArchivo);
		}
	}

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(char* path, LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		if(path != NULL)
		{
			Passenger* unPasajero;
			char idStr[TAM_RESTODATOS];
			char nombre[TAM_NOMBRES];
			char apellido[TAM_NOMBRES];
			float precio;
			char precioStr[TAM_RESTODATOS];
			int tipoPasajero;
			char tipoPasajeroStr[TAM_RESTODATOS];
			char codigoVuelo[TAM_RESTODATOS];
			char estadoVuelo[TAM_RESTODATOS];
			int len;

			len = ll_len(pArrayListPassenger);

			if(len == 0)
			{
				id = 1;
			}
			else
			{
				id+=len;
			}
			itoa(id,idStr,TAM_RESTODATOS);
			utn_getName(nombre, "Ingrese el nombre del pasajero nombre: ", "Error. Ingrese el nombre correctamente.\n");
			utn_getName(apellido, "Ingrese el apellido del pasajero: ", "Error. Ingese el apellido correctamente.\n");
			utn_getFloat(&precio, "Ingrese el precio del vuelo: ", "Error. Ingrese un dato valido.\n", 1, 999999999999999);
			utn_getInt(&tipoPasajero, "Ingrese 1 si es First Class, 2 si es Executive Class, 3 si es Economy Class: ",
					"Error. Ingrese una opción valida.\n", 1, 3);
			itoa(tipoPasajero, tipoPasajeroStr, TAM_RESTODATOS);
			pedirCodigoDeVuelo(codigoVuelo, "Ingrese el codigo de vuelo: ");
			utn_getInt(&estadoVuelo, "Ingrese 1 si el vuelo esta Aterrizado, 2 si esta En horario, 3 si esta En vuelo, 4 si esta Demorado: ",
					"Error. Ingrese una opción valida.\n",1,4);

			unPasajero =  Passenger_newParametros(idStr, nombre, tipoPasajeroStr, apellido, precioStr, codigoVuelo, estadoVuelo);

		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		int cantElementosPasajeros;
	    Passenger* unPasajero;

		cantElementosPasajeros = ll_len(pArrayListPassenger);

		for(int i = 0; i < cantElementosPasajeros; i++)
		{
			unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_printOne(unPasajero);
		}
	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		if (path != NULL)
		{
			FILE* pArchivo;
			pArchivo = fopen (path,"w");

			if(pArchivo != NULL)
			{
//				if(parser_PassengerFromText(pArchivo, pArrayListPassenger) == 0)
//				{
//					retorno = 0;
//				}
			}
			fclose(pArchivo);
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
    return retorno;
}

