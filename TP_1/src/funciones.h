
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//static int getFloat(float* pResultado);

float validarNumeroPositivo (char textoAImprimir[64]);

void calcularPrecios (float precio, float km, float* tarjetaDebito, float* tarjetaCredito, float* bitcoin, float* precioPorKm, int* bandera);

float calcularDif(float precioA, float precioL);

void mostrarInformacionA(float precioA, float km, float tarjetaDebitoA, float tarjetaCreditoA, float bitcoinA, float precioPorKmA);

void mostrarInformacionL(float precioL, float km, float tarjetaDebitoL, float tarjetaCreditoL, float bitcoinL, float precioPorKmL);

void mostrarDiferencia (int diferenciaPrecio);

#endif /* FUNCIONES_H_ */
