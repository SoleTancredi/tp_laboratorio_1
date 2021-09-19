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

static int myGets(char* cadena, int longitud);
static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int esLetra(char* cadena);

/**
 * @fn int myGets(char*, int)
 * @brief toma la medida del string con la funcion strlen y le resta un lugar para posicionarse en el \n donde lo pisa
 * y alli escribe un "\0".
 *
 * @param cadena
 * @param longitud
 * @return si todo salio bien o no
 */
static int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferCadena[4016];

	if(cadena != NULL)
	{
		__fpurge(stdin);
		fgets(bufferCadena,longitud, stdin);

		bufferCadena[strlen(bufferCadena)-1]= '\0' ;

		retorno = 0;

		strcpy(cadena, bufferCadena);
	}

	 return retorno;
}

/**
 * @fn int esNumerica(char*)
 * @brief se encarga de recorrer el array hasta el \0 y verifica posicion a posicion del array verificando
 * que lo que contenga sea un numero. En caso de que en la posicion 0 halla un signo '-' l respeta ya que
 * seria un numero negativo.
 *
 * @param cadena
 * @return si todo salio bien o no
 */

static int esNumerica(char* cadena)
{
	int retorno = 1;
	int i = 0;

	if(cadena[0] == '-')
	{
		i = 1;
	}

	for(; cadena[i] != '\0'; i++)
	{
		if(cadena[i] < '0' || cadena[i] > '9')
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}
/**
 * @fn int getInt(int*)
 * @brief toma el array ingresado y si al
 *
 * @param pResultado
 * @return si todo salio bien o no
 */
static int getInt(int* pResultado)
{
	int retorno=-1;
	char bufferInt[4096];

	if(myGets(bufferInt, sizeof(bufferInt)) == 0 && esNumerica(bufferInt))
	{
		retorno=0;
		*pResultado = atoi(bufferInt);
	}
	return retorno;
}

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			//scanf("%d",&bufferInt); //lo eliminamos, vamos a cambiar por una funcion para hacer GetNUmber mas robusta
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	 }
	return retorno;
}
