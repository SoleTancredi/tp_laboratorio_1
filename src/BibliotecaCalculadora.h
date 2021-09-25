/*
 * BibliotecaCalculadora.h
 *
 *  Created on: 19 sep. 2021
 *      Author: sole
 */

#ifndef BIBLIOTECACALCULADORA_H_
#define BIBLIOTECACALCULADORA_H_
#define MaxValue 2147483647
#define MinValue -2147483647

int multiplicar(float primerNumero, float segundoNumero, float* pResultado);
int dividir(float primerNumero, float segundoNumero, float* pResultado);
int restar(float primerNumero, float segundoNumero, float* pResultado);
int sumar(float primerNumero, float segundoNumero, float* pResultado);
long int factorial(int primerNumero,long int* pResultado);

#endif /* BIBLIOTECACALCULADORA_H_ */
