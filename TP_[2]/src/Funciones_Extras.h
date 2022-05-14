#ifndef FUNCIONES_EXTRAS_H_
#define FUNCIONES_EXTRAS_H_

void pedirCodigoDeVuelo(char codigoDeVuelo[10], char* mensaje);
int esNumerica(char* cadena);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo);
int getFloat(float *pResultado);
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo);
int utn_getName(char* cadena, char* mensaje, char* mensajeError);
void utn_corregirMayus(char* cadena);















#endif
