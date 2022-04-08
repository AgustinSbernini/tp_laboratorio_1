/*
 * calcular.h
 *
 *  Created on: 8 abr. 2022
 *      Author: AGUSTIN
 */


#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int calcularAerolineas (float precioA, float km, float* tarjetaDebitoA, float* tarjetaCreditoA, float* bitcoinA, float* precioPorKmA);

int calcularLatam (float precioL, float km, float* tarjetaDebitoL, float* tarjetaCreditoL, float* bitcoinL, float* precioPorKmL);

int calcularDif(float precioA, float precioL);

int mostrarInformacionA(float precioA, float km, float tarjetaDebitoA, float tarjetaCreditoA, float bitcoinA, float precioPorKmA);

int mostrarInformacionL(float precioL, float km, float tarjetaDebitoL, float tarjetaCreditoL, float bitcoinL, float precioPorKmL);

int mostrarDiferencia (int diferenciaPrecio);

int datosForzados (float precioA, float precioL, float km);

#endif /* FUNCIONES_H_ */
