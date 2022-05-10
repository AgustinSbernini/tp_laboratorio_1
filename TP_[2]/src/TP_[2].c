/****************************************************************************************************
*	Programa: TP 2
*
*	Objetivo:
*		Una aerol�nea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
*		no puede tener m�s de 2000 pasajeros.
*
*		El sistema deber� tener el siguiente men� de opciones:
*			1. ALTAS: Se debe permitir ingresar un pasajero calculando autom�ticamente el
*				n�mero de Id. El resto de los campos se le pedir� al usuario.
*			2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
*				o Precio o Tipo de pasajero o C�digo de vuelo
*			3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
*			4. INFORMAR:
*				1. Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
*				2. Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
*				promedio.
*				3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�
*
*	Version: 0.1 del 10 de Mayo de 2022
*	Autor: Agustin Sbernini
*
*****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int opcionMenuPrincipal;
	int opcionMenuModificar;
	int opcionMenuInformar;

	setbuf(stdout, NULL);

	do{
		printf("Menu principal: \n"
				"1- ALTA de pasajero.\n"
				"2- MODIFICAR pasajero.\n"
				"3- BAJA de pasajero.\n"
				"4- INFORMAR.\n"
				"5- Salir.\n"
				"Elija una opci�n: ");
		fflush(stdin);
		scanf("%d",&opcionMenuPrincipal);

		switch(opcionMenuPrincipal)
		{
			case 1:
				printf("1");
				break;
			case 2:
				do{
					printf("\nMenu de modificaciones de datos del pasajero:\n"
							"1- Nombre.\n"
							"2- Apellido.\n"
							"3- Precio.\n"
							"4- Tipo de pasajero.\n"
							"5- C�digo de vuelo.\n"
							"6- Volver al men� principal.\n"
							"Elija una opci�n: ");
					fflush(stdin);
					scanf("%d", &opcionMenuModificar);
					switch(opcionMenuModificar)
					{
						case 1:
							printf("2a");
							break;
						case 2:
							printf("2b");
							break;
						case 3:
							printf("2c");
							break;
						case 4:
							printf("2d");
							break;
						case 5:
							printf("2e");
							break;
						case 6:
							printf("\nVolviendo al men� principal.\n");
							break;
						default:
							printf("\nElija una opci�n valida.\n");
					}
				}while(opcionMenuModificar != 6);
				break;
			case 3:
				printf("3");
				break;
			case 4:
				do{
					printf("\nMen� para informar pasajeros:\n"
							"1- Listado de pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.\n"
							"2- Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio promedio.\n"
							"3- Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�\n"
							"4- Volver al men� principal\n"
							"Elija una opci�n: ");
					fflush(stdin);
					scanf("%d",&opcionMenuInformar);
					switch(opcionMenuInformar)
					{
					case 1:
						printf("4a");
						break;
					case 2:
						printf("4b");
						break;
					case 3:
						printf("4c");
						break;
					case 4:
						printf("\nVolviendo al men� principal.\n");
						break;
					default:
						printf("\nElija una opci�n valida.\n");
					}
				}while(opcionMenuInformar != 4);
				break;
			case 5:
				printf("Cerrando sistema.\n");
				break;
			default:
				printf("\nElija una opcion valida.\n");
		}

	}while(opcionMenuPrincipal != 5);


	return 0;
}
