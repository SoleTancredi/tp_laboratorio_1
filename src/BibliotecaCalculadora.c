/*
 * BibliotecaCalculadora.c
 *
 *  Created on: 19 sep. 2021
 *      Author: sole
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "BibliotecaUtn2021.h"

int sumar(int primerNumero, int segundoNumero, int* pResultado)
{
	int retorno = -1;
	int resultado;

	if(pResultado != NULL)
	{
		resultado = primerNumero + segundoNumero;
		retorno = 0;
	}

	*pResultado = resultado;

	return retorno;
}

int restar(int primerNumero, int segundoNumero, int* pResultado)
{
	int retorno = -1;
	int resultado;

	if(pResultado != NULL)
	{
		resultado = primerNumero - segundoNumero;
		retorno = 0;
	}

	*pResultado = resultado;

	return retorno;
}

int dividir(int primerNumero, int segundoNumero, float* pResultado)
{
	int retorno = -1;
	float resultado;

	if(pResultado != NULL && segundoNumero != 0)
	{
		resultado = (float)primerNumero / segundoNumero;
		retorno = 0;
	}

	*pResultado = resultado;

	return retorno;
}

int multiplicar(int primerNumero, int segundoNumero, int* pResultado)
{
	int retorno = -1;
	int resultado;

	if(pResultado != NULL)
	{
		resultado = primerNumero * segundoNumero;
		retorno = 0;
	}

	*pResultado = resultado;

	return retorno;
}

long int factorial(int primerNumero,long int* pResultado)// te llega un 4
{
	int retorno = -1;
	long int auxPResultado;

	if( pResultado!=NULL )
	{
		retorno = 0;
		if(primerNumero == 0)
		{
			auxPResultado = 1;
		}
		else
		{
			factorial(primerNumero -1, &auxPResultado);// 4 -1 = 3 entonces factorial de 3 = 6
			auxPResultado = primerNumero * auxPResultado;
		}
		*pResultado = auxPResultado ;
	}
	return retorno;
}
long int factorialConFor(int numero)
{
	long int Resultado;
	for(int i=1;i<numero;i++)
	{
		Resultado = i * (i+1);
	}

	return Resultado;
}
long int factorialConWhile(int numero)
{
	long int Resultado;

	while(numero>0)
	{
		Resultado = numero * numero -1;
	}
	return Resultado;
}
