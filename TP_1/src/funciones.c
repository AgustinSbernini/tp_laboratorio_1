#include <stdio.h>
#include <stdlib.h>

float validarNumeroPositivo (char textoAImprimir[64])
{
	float retorno;
	char buffer[64];

	do{
		printf(textoAImprimir);
		fflush(stdin);
		scanf("%s",buffer);
		retorno = atof (buffer);
	}while(retorno <= 0);

	return retorno;
}

void calcularPrecios (float precio, float km, float* precioDescontado, float* precioRecargado, float* precioCriptomoneda, float* precioPorKm, int* bandera)
{
	float descuento;
	float recarga;
	float criptomoneda;

	descuento = 0.9;
	recarga = 1.25;
	criptomoneda = 4745556.81;
	*bandera = 1;

	*precioDescontado = (precio*descuento);
	*precioRecargado = (precio*recarga);
	*precioCriptomoneda = (precio / criptomoneda);
	*precioPorKm = (precio / km);
}

float calcularDif(float precioA, float precioB)
{
	float resultado;

	if (precioA == 0 || precioB == 0)
	{
		resultado = 0;
	}
	else
	{
		if (precioA > precioB)
		{
			resultado = precioA - precioB;
		}
		else
		{
			resultado = precioB - precioA;
		}
	}

	return resultado;
}

void mostrarInformacion(char nombre[64],float precio, float km, float tarjetaDebito, float tarjetaCredito, float bitcoin, float precioPorKm)
{
	if(precio > 0)
	{
		printf("\nPrecio %s: $%.2f",nombre, precio);
		printf("\nPrecio con tarjeta de débito: %.2f",tarjetaDebito);
		printf("\nPrecio con tarjeta de crédito: %.2f",tarjetaCredito);
		printf("\nPrecio pagando con bitcoin: %f BTC",bitcoin);
		printf("\nPrecio unitario: %.2f\n",precioPorKm);
	}
	else
	{
		printf("\nNo se ingresaron vuelos de %s\n",nombre);
	}
}

void mostrarDiferencia (float diferenciaPrecio)
{
	if(diferenciaPrecio != 0)
	{
		printf("\nLa diferencia de precio es : %.2f\n",diferenciaPrecio);
	}
}
