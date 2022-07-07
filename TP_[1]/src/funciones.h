#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @brief
/// Imprime el texto en el que se le pide al usuario ingresar el valor de algo
/// Pide el valor mediante el scanf en forma de array y lo convierte en un float
/// Para validar de que sea un numero y mediante el while se verifica que sea positivo.
/// @param textoAImprimir Es el texto en donde le pedis al usuario que tipo de dato debe ingresar.
/// @return devuelve el float resultante.
float validarNumeroPositivo (char textoAImprimir[64]);

/// @brief
/// Calcula el precio de los distintos métodos de pago a través del ingreso
/// Del precio del vuelo y los kilometros que recorre y los retorna a través
/// De sus respectivos punteros.
/// También levanta la bandera para que se pueda acceder al siguiente menú.
/// @param precio Debe contener el precio del vuelo a considerar.
/// @param km Debe contener la cantidad de kilometros que recorreá el vuelo.
/// @param precioDescontado Se devuelve al puntero el valor del vuelo con el descuento aplicado.
/// @param precioRecargado Se devuelve al puntero el valor del vuelo con el recargo aplicado.
/// @param precioCriptomoneda Se devuelve al puntero el valor del vuelo en criptomonedas.
/// @param precioPorKm Se devuelve al puntero el valor de cada kilometro recorrido.
/// @param bandera Te permite avanzar al siguiente menú para evitar errores.
void calcularPrecios (float precio, float km, float* precioDescontado, float* precioRecargado, float* precioCriptomoneda, float* precioPorKm, int* bandera);

/// @brief
/// Calcula la diferencia entre dos precios y retorna el resultado.
/// Indiferentemente de como se hayan ingresado los numeros se calculará el mayor - el menor.
/// @param precioA Primer precio a considerar.
/// @param precioB Segundo precio a considerar.
/// @return La diferencia entre el precio mayor y el menor.
float calcularDif(float precioA, float precioB);

/// @brief
/// Imprime los precios previamente calculados o avisa que no se ingresaron vuelos.
/// @param nombre Debe contener el nombre de la empresa del vuelo.
/// @param precio Debe contener el precio del vuelo.
/// @param km Debe contener los kilometros que recorre el vuelo.
/// @param tarjetaDebito Debe contener el precio del vuelo con el descuento ya realizado.
/// @param tarjetaCredito Debe contener el precio del vuelo con el aumento ya realizado.
/// @param bitcoin Debe contener el precio del vuelo en criptomonedas.
/// @param precioPorKm Debe contener el valor de cada kilometro recorrido.
void mostrarInformacion(char nombre[64],float precio, float km, float tarjetaDebito, float tarjetaCredito, float bitcoin, float precioPorKm);

/// @brief
/// Imprime la diferencia entre dos precios previamente calculado.
/// @param diferenciaPrecio
void mostrarDiferencia (float diferenciaPrecio);

#endif /* FUNCIONES_H_ */
