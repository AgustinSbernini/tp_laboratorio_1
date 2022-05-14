/****************************************************************************************************
*	Programa: TP 2
*
*	Objetivo:
*		Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
*		no puede tener más de 2000 pasajeros.
*
*		El sistema deberá tener el siguiente menú de opciones:
*			1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
*				número de Id. El resto de los campos se le pedirá al usuario.
*			2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
*				o Precio o Tipo de pasajero o Código de vuelo
*			3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
*			4. INFORMAR:
*				1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
*				2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
*				promedio.
*				3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
*
*	Version: 1.0 del 14 de Mayo de 2022
*	Autor: Agustin Sbernini
*
*****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Funciones_Extras.h"

#define MAX_PASAJEROS 2000
#define MAX_TIPOPASAJEROSESTADOVUELO 3

int main(void) {

	int opcionMenuPrincipal;
	int opcionMenuModificar;
	int opcionMenuInformar;
	int opcionIdModificar;
	int indiceAModificar;
	int opcionIdBajar;
	int indiceABajar;
	int id = 0;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoDeVuelo[10];
	int tipoDePasajero;
	float precioTotal;
	float precioPromedio;
	int cantPasajeroPorEncimaDelPromedio;
	int estadoDelVuelo;

	Passenger listaDePasajeros[MAX_PASAJEROS];
	StatusFlightAndTypePassenger estadoDelVueloYTipoPasajero[MAX_TIPOPASAJEROSESTADOVUELO];

	setbuf(stdout, NULL);

	if(initPassengers(listaDePasajeros, MAX_PASAJEROS) != 0)
	{
		printf("\nError al inicializar la estructura Passenger.\n");
	}

	if(initStatusFlightAndTypePassenger(estadoDelVueloYTipoPasajero, MAX_TIPOPASAJEROSESTADOVUELO) != 0)
	{
		printf("\nError al inicializar la estructura StatusFlightAndTypePassenger.\n");
	}

	do{
		printf("\nMenu principal: \n"
				"1- ALTA de pasajero.\n"
				"2- MODIFICAR pasajero.\n"
				"3- BAJA de pasajero.\n"
				"4- INFORMAR.\n"
				"5- Carga Forzada.\n"
				"6- Salir.\n"
				"Elija una opción: ");
		fflush(stdin);
		scanf("%d",&opcionMenuPrincipal);

		switch(opcionMenuPrincipal)
		{
			case 1:
				id++;
				utn_getName(nombre, "Ingrese el nombre del pasajero nombre: ", "Error. Ingrese el nombre correctamente.\n");
				utn_getName(apellido, "Ingrese el apellido del pasajero: ", "Error. Ingese el apellido correctamente.\n");
				utn_getFloat(&precio, "Ingrese el precio del vuelo: ", "Error. Ingrese un dato valido.\n", 1, 999999999999999);
				utn_getInt(&tipoDePasajero, "Ingrese 1 si es Primera Clase, 2 si es Clase Económica, 3 si es Clase Turista: ",
						"Error. Ingrese una opción valida.\n", 1, 3);
				pedirCodigoDeVuelo(codigoDeVuelo, "Ingrese el codigo de vuelo: ");
				utn_getInt(&estadoDelVuelo, "Ingrese 1 si el vuelo esta Activo, 2 si esta Inactivo, 3 si esta Demorado: ",
						"Error. Ingrese una opción valida.\n",1,3);
				if(addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  nombre, apellido, precio, tipoDePasajero, codigoDeVuelo, estadoDelVuelo) == 0)
				{
					printf("\nSe ha agregado un pasajero con exito.\n");
				}
				else
				{
					printf("\nHubo un error al intentar agregar al pasajero.\n");
				}
				break;
			case 2:
				do{
					printf("\nMenu de modificaciones de datos del pasajero:\n"
							"1- Nombre.\n"
							"2- Apellido.\n"
							"3- Precio.\n"
							"4- Tipo de pasajero.\n"
							"5- Código de vuelo.\n"
							"6- Volver al menú principal.\n"
							"Elija una opción: ");
					fflush(stdin);
					scanf("%d", &opcionMenuModificar);
					switch(opcionMenuModificar)
					{
						case 1:
						case 2:
						case 3:
						case 4:
						case 5:
							printf("Indique el ID del pasajero que desea modificar: ");
							fflush(stdin);
							scanf("%d", &opcionIdModificar);
							indiceAModificar = findPassengerById(listaDePasajeros, MAX_PASAJEROS, opcionIdModificar);
							if (indiceAModificar > -1)
							{
								if(modifyPassenger(listaDePasajeros, MAX_PASAJEROS, indiceAModificar, opcionMenuModificar) == 0)
								{
									printf("\nSe ha modificado al pasajero con exito.\n");
								}
								else
								{
									printf("\nHubo un error al intentar modificar al pasajero.\n");
								}
							}
							else
							{
								printf("\nEl ID ingresado no coincide con ningún pasajero de la lista.\n");
							}
							break;
						case 6:
							printf("\nVolviendo al menú principal.\n");
							break;
						default:
							printf("\nElija una opción valida.\n");
					}
				}while(opcionMenuModificar != 6);
				break;
			case 3:
				printf("Ingrese el ID del pasajero que desea dar de baja: ");
				fflush(stdin);
				scanf("%d", &opcionIdBajar);
				indiceABajar = findPassengerById(listaDePasajeros, MAX_PASAJEROS, opcionIdBajar);
				if (indiceABajar > -1)
				{
					if(removePassenger(listaDePasajeros, MAX_PASAJEROS, indiceABajar) == 0)
					{
						printf("\nSe ha dado de baja con exito al pasajero.\n");
					}
					else
					{
						printf("\nHubo un error al intentar dar de baja al pasajero.\n");
					}
				}
				else
				{
					printf("\nEl ID ingresado no coincide con ningún pasajero de la lista.\n\n");
				}
				break;
			case 4:
				do{
					printf("\nMenú para informar pasajeros:\n"
							"1- Listado de pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
							"2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
							"3- Listado de los pasajeros por Código de vuelo y estados de vuelos 'ACTIVO'\n"
							"4- Volver al menú principal\n"
							"Elija una opción: ");
					fflush(stdin);
					scanf("%d",&opcionMenuInformar);
					switch(opcionMenuInformar)
					{
					case 1:
						if(sortPassengersByLastName(listaDePasajeros, MAX_PASAJEROS, 1) == 0)
						{
							if(printPassenger(listaDePasajeros, estadoDelVueloYTipoPasajero ,MAX_PASAJEROS, MAX_TIPOPASAJEROSESTADOVUELO) != 0)
							{
								printf("\nLa lista de pasajeros esta vacia.\n");
							}
						}
						else
						{
							printf("\nHubo un error al intentar ordenar los pasajero por apellido.\n");
						}
						break;
					case 2:
						if(averagePassenger(listaDePasajeros,MAX_PASAJEROS , &precioTotal, &precioPromedio) == 0)
						{
							cantPasajeroPorEncimaDelPromedio = aboveAveragePassenger(listaDePasajeros, MAX_PASAJEROS, precioPromedio);
							printf("\nEl precio total de todos los vuelos fue de $%.2f.\nEn promedio cada pasajero pagó $%.2f."
								"\nEn total hay %d pasajeros que paga por encima del promedio.\n", precioTotal, precioPromedio, cantPasajeroPorEncimaDelPromedio);
						}
						else
						{
							printf("\nHubo un error al intentar conseguir los calculos solicitados.\n");
						}
						break;
					case 3:
						if(sortPassengersByCode(listaDePasajeros, MAX_PASAJEROS, 1) == 0)
						{
							if(printPassenger(listaDePasajeros, estadoDelVueloYTipoPasajero ,MAX_PASAJEROS, MAX_TIPOPASAJEROSESTADOVUELO) != 0)
							{
								printf("\nLa lista de pasajeros esta vacia.\n");
							}
						}
						else
						{
							printf("\nHubo un error al intentar ordenar los pasajeros por codigo de vuelo.\n");
						}
						break;
					case 4:
						printf("\nVolviendo al menú principal.\n");
						break;
					default:
						printf("\nElija una opción valida.\n");
					}
				}while(opcionMenuInformar != 4);
				break;
			case 5:
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id, "Agustin", "Sbernini", 15601.23, 3, "ARGBR-23", 1);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Juan Pedro", "Lopez", 24031.35, 2, "CHLPR-42", 3);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Juliana", "Rodriguez", 31150.50, 1, "ARGUS-52", 2);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Joaquin", "Suarez", 17164.31, 3, "CHLPR-42", 1);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Joaquin", "Suarez", 30518, 1, "USPR-61", 1);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Catriel", "Darin", 32051.31, 1, "USPR-61", 3);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Estefania", "Albanessi", 19081, 3, "MXCL-16", 2);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Valentino", "Pedano", 25031.24, 2, "USPR-61", 2);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "Guillermina", "Alonso", 25151.13, 2, "ARGBR-23", 3);
				id++;
				addPassenger(listaDePasajeros,  MAX_PASAJEROS,  id,  "San Sebastian", "Lopez Aguero", 33654.13, 1, "ARGUS-52", 1);
				printf("\nSe han cargado con exito todos los usuarios de la carga forzada.\n");
				break;
			case 6:
				printf("\nCerrando sistema.\n");
				break;
			default:
				printf("\nElija una opción valida.\n");
		}

	}while(opcionMenuPrincipal != 6);

	return 0;
}
