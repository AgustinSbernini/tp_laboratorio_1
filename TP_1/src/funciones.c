
#include <stdio.h>
#include <stdlib.h>

/*
  Imprime el texto en el que se le pide al usuario ingresar el valor de algo
  Pide el valor mediante el scanf y valida de que el valor ingresado sea
  Mayor al numero indicado
 */

float validarQueSeaMayorA (float variableAComparar, char textoAImprimir[50], int mayorA)
{
	do{
		printf(textoAImprimir);
		fflush(stdin);
		scanf("%f",&variableAComparar);
	}while(variableAComparar < mayorA);

	return variableAComparar;
}

/*
  Calcula el precio de los distintos métodos de pago a través del ingreso
  Del precio del vuelo y los kilometros que recorre y los retorna a través
  De sus respectivos punteros.
  También levanta la bandera para que se pueda acceder al siguiente menú
*/

int calcularPrecios (float precio, float km, float* tarjetaDebito, float* tarjetaCredito, float* bitcoin, float* precioPorKm, int* bandera)
{
	float descuentoDebito;
	float descuentoCredito;
	float valorBitcoin;

	descuentoDebito = 0.9;
	descuentoCredito = 1.25;
	valorBitcoin = 4745556.81;
	*bandera = 1;

	*tarjetaDebito = (precio*descuentoDebito);
	*tarjetaCredito = (precio*descuentoCredito);
	*bitcoin = (precio / valorBitcoin);
	*precioPorKm = (precio / km);

	return 0;
}

// Calcula la diferencia entre dos precios y retorna el resultado.

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

// Imprime los precios previamente calculados o avisa que no se ingresaron vuelos

int mostrarInformacionA(float precioA, float km, float tarjetaDebitoA, float tarjetaCreditoA, float bitcoinA, float precioPorKmA)
{
	printf("\nKMs Ingresados: %.2f km\n",km);

	if(precioA > 0)
	{
		printf("\n\nPrecio Aerolineas: $%.2f",precioA);
		printf("\nPrecio con tarjeta de débito: %.2f",tarjetaDebitoA);
		printf("\nPrecio con tarjeta de crédito: %.2f",tarjetaCreditoA);
		printf("\nPrecio pagando con bitcoin: %f BTC",bitcoinA);
		printf("\nPrecio unitario: %.2f\n",precioPorKmA);
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
		printf("\nPrecio pagando con bitcoin: %f BTC",bitcoinL);
		printf("\nPrecio unitario: %.2f\n",precioPorKmL);
	}
	else
	{
		printf("\nNo se ingresaron vuelos de Latam\n");
	}

	return 0;
}

// Imprime la diferencia entre dos precios previamente calculado.

int mostrarDiferencia (float diferenciaPrecio)
{
	if(diferenciaPrecio == 0){}
	else
	{
		printf("\n\nLa diferencia de precio es : %.2f",diferenciaPrecio);
	}

	return 0;
}
