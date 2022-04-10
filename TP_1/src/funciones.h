
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

float validarQueSeaMayorA (float variableAComparar, char textoAImprimir[50], int mayorA);

int calcularPrecios (float precio, float km, float* tarjetaDebito, float* tarjetaCredito, float* bitcoin, float* precioPorKm, int* bandera);

int calcularDif(float precioA, float precioL);

int mostrarInformacionA(float precioA, float km, float tarjetaDebitoA, float tarjetaCreditoA, float bitcoinA, float precioPorKmA);

int mostrarInformacionL(float precioL, float km, float tarjetaDebitoL, float tarjetaCreditoL, float bitcoinL, float precioPorKmL);

int mostrarDiferencia (int diferenciaPrecio);

#endif /* FUNCIONES_H_ */
