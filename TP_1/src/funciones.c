/*
 * calcular.c
 *
 *  Created on: 8 abr. 2022
 *      Author: AGUSTIN
 */
#include <stdio.h>
#include <stdlib.h>

int calcularAerolineas (float precioA, float km, float* tarjetaDebitoA, float* tarjetaCreditoA, float* bitcoinA, float* precioPorKmA)
{
	float descuentoDebito;
	float descuentoCredito;
	float valorBitcoin;

	descuentoDebito = 0.9;
	descuentoCredito = 1.25;
	valorBitcoin = 4745556.81;

	*tarjetaDebitoA = (precioA*descuentoDebito);
	*tarjetaCreditoA = (precioA*descuentoCredito);
	*bitcoinA = (precioA / valorBitcoin);
	*precioPorKmA = (precioA / km);

	return 0;
}

int calcularLatam (float precioL, float km, float* tarjetaDebitoL, float* tarjetaCreditoL, float* bitcoinL, float* precioPorKmL)
{
	float descuentoDebito;
	float descuentoCredito;
	float valorBitcoin;

	descuentoDebito = 0.9;
	descuentoCredito = 1.25;
	valorBitcoin = 4745556.81;

	*tarjetaDebitoL = (precioL*descuentoDebito);
	*tarjetaCreditoL = (precioL*descuentoCredito);
	*bitcoinL = (precioL / valorBitcoin);
	*precioPorKmL = (precioL / km);

	return 0;
}

int calcularDif(float precioA, float precioL)
{
	float resultado;

	if (precioA == 0 || precioL == 0)
	{
		resultado = 0;
	}
	else
	{
		if (precioA > precioL)
		{
			resultado = precioA - precioL;
		}
		else
		{
			resultado = precioL - precioA;
		}
	}

	return resultado;
}

int mostrarInformacionA(float precioA, float km, float tarjetaDebitoA, float tarjetaCreditoA, float bitcoinA, float precioPorKmA)
{
	printf("\nKMs Ingresados: %.2f km",km);

	if(precioA > 0)
	{
		printf("\n\nPrecio Aerolineas: $%.2f",precioA);
		printf("\nPrecio con tarjeta de débito: %.2f",tarjetaDebitoA);
		printf("\nPrecio con tarjeta de crédito: %.2f",tarjetaCreditoA);
		printf("\nPrecio pagando con bitcoin: %.2f BTC",bitcoinA);
		printf("\nPrecio unitario: %.2f",precioPorKmA);
	}
	else
	{
		printf("\nNo se ingresaron vuelos de Aerolineas\n");
	}

	return 0;
}

int mostrarInformacionL(float precioL, float km, float tarjetaDebitoL, float tarjetaCreditoL, float bitcoinL, float precioPorKmL)
{
	if(precioL > 0)
	{
		printf("\n\nPrecio Latam: $%.2f",precioL);
		printf("\nPrecio con tarjeta de débito: %.2f",tarjetaDebitoL);
		printf("\nPrecio con tarjeta de crédito: %.2f",tarjetaCreditoL);
		printf("\nPrecio pagando con bitcoin: %.2f BTC",bitcoinL);
		printf("\nPrecio unitario: %.2f",precioPorKmL);
	}
	else
	{
		printf("No se ingresaron vuelos de Latam\n");
	}

	return 0;
}

int mostrarDiferencia (float diferenciaPrecio)
{
	if(diferenciaPrecio == 0){}
	else
	{
		printf("\n\nLa diferencia de precio es : %.2f",diferenciaPrecio);
	}

	return 0;
}
