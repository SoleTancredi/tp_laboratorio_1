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
int multiplicar(int primerNumero, int segundoNumero, int* pResultado);
int dividir(int primerNumero, int segundoNumero, float* pResultado);
int restar(int primerNumero, int segundoNumero, int* pResultado);
int sumar(int primerNumero, int segundoNumero, int* pResultado);
long int factorial(int primerNumero,long int* pResultado);

#endif /* BIBLIOTECACALCULADORA_H_ */
