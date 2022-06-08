#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "Funciones_Extras.h"

Passenger* Passenger_new()
{
	Passenger* unPasajero;

	if(unPasajero != NULL)
	{
		unPasajero = (Passenger*) malloc (sizeof(Passenger));
	}

	return unPasajero;
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr, char* apellidoStr, char* precio, char* codigo, char* estado)
{
	Passenger* unPasajero;
	unPasajero = Passenger_new();

	if(unPasajero != NULL)
	{
		if(Passenger_setId(unPasajero, atoi(idStr)) == 0)
		{
			if(Passenger_setNombre(unPasajero, nombreStr))
			{
				if(Passenger_setApellido(unPasajero, apellidoStr) == 0)
				{
					if(Passenger_setPrecio(unPasajero, atof(precio)) == 0)
					{
						if(Passenger_setCodigoVuelo(unPasajero, codigo) == 0)
						{
							if(Passenger_setTipoPasajero(unPasajero, atoi(tipoPasajeroStr)) == 0)
							{
								if(Passenger_setEstadoVuelo(unPasajero, estado) == 0)
								{
									return unPasajero;
								}
							}
						}
					}
				}
			}
		}
	}

	return NULL;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		retorno = 0;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setEstadoVuelo (Passenger* this,char* estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno = 0;
	}

	return retorno;
}
int Passenger_getEstadoVuelo (Passenger* this,char* estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
		retorno = 0;
	}

	return retorno;
}

void Passenger_printOne(Passenger* this)
{
	if(this != NULL)
	{
		int id;
		char nombre[TAM_NOMBRES];
		char apellido[TAM_NOMBRES];
		float precio;
		int tipoPasajero;
		char tipoPasajeroConvertido[TAM_RESTODATOS];
		char codigoVuelo[TAM_RESTODATOS];
		char estadoVuelo[TAM_RESTODATOS];

		if(Passenger_getId(this, &id) == 0)
		{
			if(Passenger_getNombre(this, nombre) == 0)
			{
				if(Passenger_getApellido(this, apellido) == 0)
				{
					if(Passenger_getPrecio(this, &precio) == 0)
					{
						if(Passenger_getCodigoVuelo(this, codigoVuelo))
						{
							if(Passenger_getEstadoVuelo(this, estadoVuelo) == 0)
							{
								if(Passenger_getTipoPasajero(this, &tipoPasajero) == 0)
								{
									if(tipoPasajero == 1)
									{
										strcpy(tipoPasajeroConvertido, "FirstClass");
									}
									else
									{
										if(tipoPasajero == 2)
										{
											strcpy(tipoPasajeroConvertido, "ExecutiveClass");
										}
										else
										{
											strcpy(tipoPasajeroConvertido, "EconomyClass");
										}
									}

									printf("%-6d %-17s %-18s %-12.2f %-10s %-15s %s\n", id, nombre, apellido, precio, codigoVuelo, estadoVuelo, tipoPasajeroConvertido);
								}
							}
						}
					}
				}
			}
		}
	}
}
