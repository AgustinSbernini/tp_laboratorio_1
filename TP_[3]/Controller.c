#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Funciones_Extras.h"
#include "Controller.h"
#include <string.h>

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
int controller_addPassenger(LinkedList* pArrayListPassenger, int contadorBorrados)
{
	int retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		Passenger* unPasajero;
		char idStr[TAM_RESTODATOS];
		char nombre[TAM_NOMBRES];
		char apellido[TAM_NOMBRES];
		char precioStr[TAM_RESTODATOS];
		int tipoPasajero;
		char tipoPasajeroStr[TAM_RESTODATOS];
		char codigoVuelo[TAM_RESTODATOS];
		int estadoVuelo;
		char estadoVueloStr[TAM_RESTODATOS];
		int len;
		int r;
		int id;

		len = ll_len(pArrayListPassenger);
		id = len + 1 + contadorBorrados;
		itoa(id,idStr,TAM_DECIMAL);

		r = utn_getName(nombre, "Ingrese el nombre del pasajero: ", "Error. Ingrese el nombre correctamente.\n");
		if(r == 0)
		{
			r = utn_getName(apellido, "Ingrese el apellido del pasajero: ", "Error. Ingese el apellido correctamente.\n");
			if(r == 0)
			{
				r = utn_getFloat(precioStr, "Ingrese el precio del vuelo: ", "Error. Ingrese un dato valido.\n");
				if(r == 0)
				{
					r = utn_getInt(&tipoPasajero, "Ingrese 1 si es First Class, 2 si es Executive Class, 3 si es Economy Class: ",
							"Error. Ingrese una opción valida.\n", 1, 3);
					itoa(tipoPasajero, tipoPasajeroStr, TAM_DECIMAL);
					pedirCodigoVuelo(codigoVuelo, "Ingrese el codigo de vuelo: ");

					if(r == 0)
					{
						r = utn_getInt(&estadoVuelo, "Ingrese 1 si el vuelo esta Aterrizado, 2 si esta En horario, 3 si esta En vuelo, 4 si esta Demorado: ",
								"Error. Ingrese una opción valida.\n",1,4);
						switch(estadoVuelo)
						{
						case 1:
							strcpy(estadoVueloStr,"Aterrizado");
							break;
						case 2:
							strcpy(estadoVueloStr,"En horario");
							break;
						case 3:
							strcpy(estadoVueloStr,"En vuelo");
							break;
						default:
							strcpy(estadoVueloStr,"Demorado");
						}
						if(r == 0)
						{
							unPasajero = Passenger_newParametros(idStr, nombre, tipoPasajeroStr, apellido, precioStr, codigoVuelo, estadoVueloStr);
							if(unPasajero != NULL)
							{
								ll_add(pArrayListPassenger, unPasajero);
								retorno = 0;
							}
						}
					}
				}
			}
		}
	}

    return retorno;
}

int controller_corregirId(LinkedList* pArrayListPassenger, int cantPasajerosAgregados)
{
	int retorno = -1;
	if(pArrayListPassenger != NULL && cantPasajerosAgregados > 0)
	{
		int len;
		int idInt;
		Passenger* unPasajeroAux;

		len = ll_len(pArrayListPassenger);

		if(len > 0)
		{
			for(int i = 0; i < cantPasajerosAgregados; i++)
			{
				unPasajeroAux = ll_get(pArrayListPassenger,i);
				if(unPasajeroAux != NULL)
				{
					idInt = i + len + 1 - cantPasajerosAgregados;
					if(Passenger_setId(unPasajeroAux, idInt) == 0)
					{
						if(ll_set(pArrayListPassenger, i, unPasajeroAux) == 0)
						{
							retorno = 0;
						}
					}
				}
			}
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

	if(pArrayListPassenger != NULL)
	{
		int len;
		int id;
		int index;
		int campoModificar;
		char nombre[TAM_NOMBRES];
		char apellido[TAM_NOMBRES];
		char precio[TAM_RESTODATOS];
		char codigo[TAM_RESTODATOS];
		int tipoPasajero;
		int estadoVuelo;
		char estadoVueloStr[TAM_RESTODATOS];
		Passenger* pasajeroAux;
		len = ll_len(pArrayListPassenger);
		if(len > 0)
		{
			if(utn_getInt(&id,"Ingrese el id del pasajero que desea modificar: ","Error. El id ingresado no es valido.\n", 1, len) == 0)
			{
				index = Passenger_find(pArrayListPassenger, id);
				if(index > -1)
				{
					pasajeroAux = ll_get(pArrayListPassenger, index);
					if(pasajeroAux != NULL)
					{
						printf("El pasajero que seleccionó para modificar es:\n");
						Passenger_printOne(pasajeroAux);
						do{
							utn_getInt(&campoModificar, "Campos que se pueden modificar:\n"
									"  1- Nombre.\n"
									"  2- Apellido.\n"
									"  3- Precio del Vuelo.\n"
									"  4- Tipo de pasajero.\n"
									"  5- Codigo de vuelo.\n"
									"  6- Estado de vuelo.\n"
									"  7- Guardar cambios y volver al menú principal.\n"
									"Cual desea modificar? ", "Error. Ingrese una opción valida\n", 1, 7);
							switch(campoModificar)
							{
							case 1:
								if(utn_getName(nombre, "Ingrese el nombre del pasajero: ", "Error. Ingrese el nombre correctamente.\n") == 0)
								{
									if(Passenger_setNombre(pasajeroAux, nombre) == 0)
									{
										printf("\nEl nombre del pasajero fue modificado correctamente.\n");
									}
									else
									{
										printf("\nError. No se pudo cambiar el nombre.\n");
									}
								}
								else
								{
									printf("\nError. No se pudo cambiar el nombre.\n");
								}
								break;
							case 2:
								if(utn_getName(apellido, "Ingrese el apellido del pasajero: ", "Error. Ingese el apellido correctamente.\n") == 0)
								{
									if(Passenger_setApellido(pasajeroAux, apellido) == 0)
									{
										printf("\nEl apellido del pasajero fue modificado correctamente.\n");
									}
									else
									{
										printf("\nError. No se pudo cambiar el apellido.\n");
									}
								}
								else
								{
									printf("\nError. No se pudo cambiar el apellido.\n");
								}
								break;
							case 3:
								if(utn_getFloat(precio, "Ingrese el precio del vuelo: ", "Error. Ingrese un dato valido.\n") == 0)
								{
									if(Passenger_setPrecio(pasajeroAux, atof(precio)) == 0)
									{
										printf("\nEl precio del vuelo fue modificado correctamente.\n");
									}
									else
									{
										printf("\nError. No se pudo cambiar el precio del vuelo.\n");
									}
								}
								else
								{
									printf("\nError. No se pudo cambiar el precio del vuelo.\n");
								}
								break;
							case 4:
								utn_getInt(&tipoPasajero, "Ingrese 1 si es First Class, 2 si es Executive Class, 3 si es Economy Class: ",
										"Error. Ingrese una opción valida.\n", 1, 3);
								if(Passenger_setTipoPasajero(pasajeroAux, tipoPasajero) == 0)
								{
									printf("\nEl tipo de pasajero fue modificado correctamente.\n");
								}
								else
								{
									printf("\nError. No se pudo cambiar el tipo de pasajero.\n");
								}
								break;
							case 5:
								pedirCodigoVuelo(codigo, "Ingrese el codigo de vuelo: ");
								if(Passenger_setCodigoVuelo(pasajeroAux, codigo) == 0)
								{
									printf("\nEl codigo del vuelo fue modificado correctamente.\n");
								}
								else
								{
									printf("\nError. No se pudo cambiar el codigo del vuelo.\n");
								}
								break;
							case 6:
								utn_getInt(&estadoVuelo, "Ingrese 1 si el vuelo esta Aterrizado, 2 si esta En horario, 3 si esta En vuelo, 4 si esta Demorado: ",
																	"Error. Ingrese una opción valida.\n",1,4);
								switch(estadoVuelo)
								{
								case 1:
									strcpy(estadoVueloStr,"Aterrizado");
									break;
								case 2:
									strcpy(estadoVueloStr,"En horario");
									break;
								case 3:
									strcpy(estadoVueloStr,"En vuelo");
									break;
								default:
									strcpy(estadoVueloStr,"Demorado");
								}
								if(Passenger_setEstadoVuelo(pasajeroAux, estadoVueloStr) == 0)
								{
									printf("\nEl estado del vuelo fue modificado correctamente.\n");
								}
								else
								{
									printf("\nError. No se pudo cambiar el estado del vuelo.\n");
								}
								break;
							case 7:
								if(ll_set(pArrayListPassenger, index, pasajeroAux) == 0)
								{
									printf("\nEl pasajero fue modificado con exito.\n");
								}
								else
								{
									printf("\nError. No se pudo modificar el pasajero\n");
								}
								printf("\nVolviendo al menú principal.\n");
							}
						}while(campoModificar != 7);
					}
					else
					{
						retorno = -3;
					}
				}
				else
				{
					retorno = -2;
				}
			}
		}
	}
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

	if(pArrayListPassenger != NULL)
	{
		int len;
		int id;
		int index;
		char confirmacion[TAM_RESTODATOS];
		int confirmacionSi;
		int confirmacionNo;
		Passenger* pasajeroAux;
		len = ll_len(pArrayListPassenger);
		if(len > 0)
		{
			if(utn_getInt(&id,"Ingrese el id del pasajero que desea dar de baja: ","Error. El id ingresado no es valido.\n", 1, len) == 0)
			{
				index = Passenger_find(pArrayListPassenger, id);
				if(index > -1)
				{
					pasajeroAux = ll_get(pArrayListPassenger, index);
					if(pasajeroAux != NULL)
					{
						printf("El pasajero a dar de baja es:\n");
						Passenger_printOne(pasajeroAux);
						do{
							utn_getName(confirmacion, "Esta seguro que es quien quiere eliminar? (responda 'si' o 'no'): ", "Error. Ingrese una respuesta valida.\n");
							confirmacionSi = strcmp(confirmacion, "Si");
							confirmacionNo = strcmp(confirmacion, "No");
							if(confirmacionSi == 0)
							{
								if(ll_remove(pArrayListPassenger, index) == 0)
								{
									retorno = 0;
								}
							}
							else
							{
								if(confirmacionNo == 0)
								{
									retorno = -3;
								}
								else
								{
									printf("\nError. Ingrese una respuesta valida.\n");
								}
							}
						}while(confirmacionSi != 0 && confirmacionNo != 0);
					}
				}
				else
				{
					retorno = -2;
				}
			}
		}
	}

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

