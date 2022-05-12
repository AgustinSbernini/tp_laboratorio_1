#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LIBRE 0
#define OCUPADO 1
int contadorid = 0;

void generarID(int* id)
{
	contadorid++;

	id = contadorid;
}

void pedirNombre(char* nombre[51])
{
	printf("Ingrese el nombre del pasajero");
}

void pedirApellido(char* apellido[51])
{
	printf("Ingrese el apellido del pasajero");
}

void pedirPrecio(float* precio)
{
	printf("Ingrese el precio del vuelo");
}

void pedirTipoDePasajero(int* tipoDePasajero)
{
	printf("Ingrese 1 si es Primera Clase, 2 si es Clase Economica, 3 si es Clase Turista");
}

void pedirCodigoDeVuelo(char* codigoDeVuelo[10])
{
	printf("Ingrese el codigo de vuelo");
}
