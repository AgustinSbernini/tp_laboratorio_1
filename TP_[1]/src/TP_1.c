/*******************************************************************
*	Programa: TP 1
*
*	Objetivo:
		Una agencia de viaje necesita calcular costos para sus vuelos
		de Latam y Aerolíneas Argentinas para ofrecerlos a sus clientes.
		Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
		El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
*
*	Version: 1.0 del 10 de Abril de 2022
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
	int banderaFuncion;
	float difPrecioAeroLatam;
	int kilometrosForzados;
	int precioAerolineasForzado;
	int precioLatamForzado;

	setbuf(stdout, NULL);

	kilometros = 0;
	precioVueloAerolineas = 0;
	precioVueloLatam = 0;
	banderaFuncion = 0;
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
				kilometros = validarNumeroPositivo ("Ingresar Kilómetros: ");
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
						case 'A':
							precioVueloAerolineas = validarNumeroPositivo ("Ingresar el precio del vuelo de Aerolíneas: $");
							break;

						case 'l':
						case 'L':
							precioVueloLatam = validarNumeroPositivo ("Ingresar el precio del vuelo de Latam: $");
							break;
					}
				}while(latamOAerolineas != 'a' && latamOAerolineas != 'A' && latamOAerolineas != 'l' && latamOAerolineas != 'L');
				break;

			case 3:
				if (kilometros > 0 && (precioVueloLatam > 0 || precioVueloAerolineas > 0))
				{
					calcularPrecios (precioVueloAerolineas, kilometros, &tarjetaDebitoA, &tarjetaCreditoA, &bitcoinA, &precioPorKmA, &banderaFuncion);
					calcularPrecios (precioVueloLatam, kilometros,&tarjetaDebitoL, &tarjetaCreditoL, &bitcoinL, &precioPorKmL, &banderaFuncion);
					difPrecioAeroLatam = calcularDif(precioVueloLatam, precioVueloAerolineas);
					printf("\nLas cuentas ya estan realizadas y listas para mostrarse\n");
				}
				else
				{
					printf("\nNo ingresó el precio de ningún vuelo o no ingresó kilometros del vuelo.\n");
				}
				break;

			case 4:
				if (banderaFuncion == 0)
				{
					printf("\nTodavía no calculó los costos del vuelo.\n");
				}
				else
				{
					mostrarInformacion ("Aerolineas", precioVueloAerolineas, kilometros, tarjetaDebitoA, tarjetaCreditoA, bitcoinA, precioPorKmA);

					mostrarInformacion ("Latam", precioVueloLatam, kilometros, tarjetaDebitoL, tarjetaCreditoL, bitcoinL, precioPorKmL);

					mostrarDiferencia (difPrecioAeroLatam);
				}
				break;
			case 5:
				calcularPrecios (precioAerolineasForzado, kilometrosForzados, &tarjetaDebitoA, &tarjetaCreditoA, &bitcoinA, &precioPorKmA, &banderaFuncion);
				calcularPrecios (precioLatamForzado, kilometrosForzados,&tarjetaDebitoL, &tarjetaCreditoL, &bitcoinL, &precioPorKmL, &banderaFuncion);
				difPrecioAeroLatam = calcularDif(precioLatamForzado, precioAerolineasForzado);

				mostrarInformacion ("Aerolineas", precioAerolineasForzado, kilometrosForzados, tarjetaDebitoA, tarjetaCreditoA, bitcoinA, precioPorKmA);
				mostrarInformacion ("Latam",precioLatamForzado, kilometrosForzados, tarjetaDebitoL, tarjetaCreditoL, bitcoinL, precioPorKmL);
				mostrarDiferencia (difPrecioAeroLatam);

				banderaFuncion = 0;
				break;
			case 6:
				printf("\nGracias por su visita, vuelva pronto!");
				break;
			default:
				printf("\nError, ingrese una de las opciones descriptas.\n");
		}
	}while(opcion != 6);

	return 0;
}
