/*******************************************************************
*	Programa: TP 1
*
*	Objetivo:
	Una agencia de viaje necesita calcular costos para sus vuelos
	de Latam y Aerolíneas Argentinas para ofrecerlos a sus clientes.
	Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
	El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
*
*	Version: 0.2 del 9 de Abril de 2022
*	Autor: Agustin Sbernini
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main(void) {
	int opcion;
	float kilometros;
	char latamOAerolineas;
	float precioVueloAerolineas;
	float precioVueloLatam;
	float tarjetaDebitoA;
	float tarjetaDebitoL;
	float tarjetaCreditoA;
	float tarjetaCreditoL;
	float bitcoinA;
	float bitcoinL;
	float precioPorKmA;
	float precioPorKmL;
	float difPrecioAeroLatam;
	int kilometrosForzados;
	int precioAerolineasForzado;
	int precioLatamForzado;

	setbuf(stdout, NULL);

	opcion = 0;
	kilometros = 0;
	precioVueloAerolineas = 0;
	precioVueloLatam = 0;
	kilometrosForzados = 7090;
	precioAerolineasForzado = 162965;
	precioLatamForzado = 159339;

	do{
		printf("\nMenú principal:"
				"\n1. Ingresar Kilometros."
				"\n- Kilometros Ingresados: %.2f"
				"\n2. Ingresar el precio del vuelo."
				"\n- Precio vuelo Aerolineas: %.2f"
				"\n- Precio vuelo Latam: %.2f"
				"\n3. Calcular los costos."
				"\n4. Informar los resultados."
				"\n5. Carga forzada de datos."
				"\n6. Salir."
				"\n\nSeleccione una opción: ", kilometros, precioVueloAerolineas, precioVueloLatam);
		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion)
		{
			case 1:
				do{
					printf("Ingresar Kilómetros: ");
					fflush(stdin);
					scanf("%f",&kilometros);
				}while(kilometros < 0);
				break;

			case 2:
				do{
					printf("Desea ingresar el precio de Aerolineas o de Latam? "
							"\n(Solo una a la vez, responda 'a' para Aerolineas o 'l' para Latam):");
					fflush(stdin);
					scanf("%c",&latamOAerolineas);
					switch(latamOAerolineas)
					{
						case 'a':
							do{
								printf("Ingresar el precio del vuelo de Aerolíneas: $");
								fflush(stdin);
								scanf("%f",&precioVueloAerolineas);
							}while(precioVueloAerolineas < 0);
						break;

						case 'l':
							do{
								printf("Ingresar el precio del vuelo de Latam: $");
								fflush(stdin);
								scanf("%f",&precioVueloLatam);
							}while(precioVueloLatam < 0);
						break;
					}
				}while(latamOAerolineas != 'a' && latamOAerolineas != 'l');
				break;

			case 3:
				if (precioVueloLatam > 0 || precioVueloAerolineas > 0)
				{
					calcularAerolineas (precioVueloAerolineas, kilometros, &tarjetaDebitoA, &tarjetaCreditoA, &bitcoinA, &precioPorKmA);
					calcularLatam (precioVueloLatam, kilometros,&tarjetaDebitoL, &tarjetaCreditoL, &bitcoinL, &precioPorKmL);
					difPrecioAeroLatam = calcularDif(precioVueloLatam, precioVueloAerolineas);
					printf("\nLas cuentas ya estan realizadas y listas para mostrarse\n");
				}
				else
				{
					printf("\nNo ingresó ningún precio de vuelo\n");
				}
				break;

			case 4:

				mostrarInformacionA (precioVueloAerolineas, kilometros, tarjetaDebitoA, tarjetaCreditoA, bitcoinA, precioPorKmA);

				mostrarInformacionL (precioVueloLatam, kilometros, tarjetaDebitoL, tarjetaCreditoL, bitcoinL, precioPorKmL);

				mostrarDiferencia (difPrecioAeroLatam);
				break;
			case 5:
				calcularAerolineas (precioAerolineasForzado, kilometrosForzados, &tarjetaDebitoA, &tarjetaCreditoA, &bitcoinA, &precioPorKmA);
				calcularLatam (precioLatamForzado, kilometrosForzados,&tarjetaDebitoL, &tarjetaCreditoL, &bitcoinL, &precioPorKmL);
				difPrecioAeroLatam = calcularDif(precioLatamForzado, precioAerolineasForzado);

				mostrarInformacionA (precioAerolineasForzado, kilometrosForzados, tarjetaDebitoA, tarjetaCreditoA, bitcoinA, precioPorKmA);
				mostrarInformacionL (precioLatamForzado, kilometrosForzados, tarjetaDebitoL, tarjetaCreditoL, bitcoinL, precioPorKmL);
				mostrarDiferencia (difPrecioAeroLatam);
				break;
		}
	}while(opcion != 6);

	printf("\nGracias por su visita, vuelva pronto!");

	return 0;
}
