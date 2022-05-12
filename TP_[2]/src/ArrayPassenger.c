#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#define LIBRE 0
#define OCUPADO 1

int initPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL)
	{
		if (len >= 0)
		{
			for (i = 0; i < len; i++)
			{
				list[i].isEmpty = LIBRE;
			}
			retorno = 0;
		}
	}

	return retorno;
}

int findFreeSlot(Passenger* list, int len)
{
	int retorno = -1;
	int indice;

	if (list != NULL)
	{
		if (len >= 0)
		{
			for (indice = 0; indice < len; indice++)
			{
				if(list[indice].isEmpty == LIBRE)
				{
					retorno = indice;
					break;
				}
			}
		}
	}

	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int retorno = -1;
	int slotLibre;
	Passenger auxiliar;

	if (list != NULL)
	{
		if (len >= 0)
		{
			slotLibre = findFreeSlot(list, len);
			if (slotLibre >= 0)
			{
				auxiliar.id = id;
				strcpy(auxiliar.name, name);
				strcpy(auxiliar.lastName, lastName);
				auxiliar.price = price;
				strcpy(auxiliar.flycode, flycode);
				auxiliar.typePassenger = typePassenger;
				auxiliar.isEmpty = OCUPADO;

				list[slotLibre] = auxiliar;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int findPassengerById(Passenger* list, int len,int id)
{
	return 0;
}

int removePassenger(Passenger* list, int len, int id)
{
	return -1;
}

int sortPassengersByLastName(Passenger* list, int len, int order)
{
	Passenger auxiliar;
	int retorno = -1;

	if (list != NULL)
		{
			if (len >= 0)
			{
				if (order == 1)
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; i < len - 1; j++)
						{
							if (strcmp(list[i].lastName, list[j].lastName) > 1)
							{
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
						}
					}
				}
				else
				{
					for (int i = 0; i < len; i++)
					{
						for(int j = i + 1; i < len - 1; j++)
						{
							if (strcmp(list[i].lastName, list[j].lastName) < 1)
							{
								auxiliar = list[j];
								list[j] = list[i];
								list[i] = auxiliar;
							}
						}
					}
				}
				retorno = 0;
			}
		}

	return retorno;
}

int printPassenger(Passenger* list, int length)
{
	int retorno = -1;
	int i;

	if (list != NULL) {
		if (length >= 0) {
			for (i = 0; i < length; i++) {
				if(list[i].isEmpty == OCUPADO){
					printf("ID: %d - Nombre: %s %s - Precio: %.2f - Codigo de vuelo: %s - Tipo de pasajero: %d",
							list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, list[i].typePassenger);
				}
			}
			retorno = 0;
		}
	}

	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	return 0;
}
