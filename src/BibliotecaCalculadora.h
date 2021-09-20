/*
 * BibliotecaCalculadora.h
 *
 *  Created on: 19 sep. 2021
 *      Author: sole
 */

#ifndef BIBLIOTECACALCULADORA_H_
#define BIBLIOTECACALCULADORA_H_
#define MaxValueINT 2147483647
#define MinValueINT -2147483647

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_multiplicar(int primerNumero, int segundoNumero, int* pResultado);
float utn_dividir(int primerNumero, int segundoNumero, float* pResultado);
int utn_restar(int primerNumero, int segundoNumero, int* pResultado);
int utn_sumar(int primerNumero, int segundoNumero, int* pResultado);

#endif /* BIBLIOTECACALCULADORA_H_ */
