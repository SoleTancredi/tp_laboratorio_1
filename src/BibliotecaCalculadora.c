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

int sumar(float primerNumero, float segundoNumero, float* pResultado)
{
	int retorno = -1;
	float resultado;

	if(pResultado != NULL)
	{
		resultado = primerNumero + segundoNumero;
		retorno = 0;
	}

	*pResultado = resultado;

	return retorno;
}

int restar(float primerNumero, float segundoNumero, float* pResultado)
{
	int retorno = -1;
	float resultado;

	if(pResultado != NULL)
	{
		resultado = primerNumero - segundoNumero;
		retorno = 0;
	}

	*pResultado = resultado;

	return retorno;
}

int dividir(float primerNumero, float segundoNumero, float* pResultado)
{
	int retorno = -1;
	float resultado;

	if(pResultado != NULL && segundoNumero != 0)
	{
		resultado = primerNumero / segundoNumero;
		retorno = 0;
	}

	*pResultado = resultado;

	return retorno;
}

int multiplicar(float primerNumero, float segundoNumero, float* pResultado)
{
	int retorno = -1;
	float resultado;

	if(pResultado != NULL)
	{
		resultado = primerNumero * segundoNumero;
		retorno = 0;
	}

	*pResultado = resultado;

	return retorno;
}

long int factorial(int primerNumero,long int* pResultado)
{
	int retorno = -1;
	long int auxPResultado;

	if( pResultado!=NULL && primerNumero > 0)
	{
		retorno = 0;
		if(primerNumero == 0)
		{
			auxPResultado = 1;
		}
		else
		{
			factorial(primerNumero -1, &auxPResultado);
			auxPResultado = primerNumero * auxPResultado;
		}

		*pResultado = auxPResultado ;
	}
	return retorno;
}

