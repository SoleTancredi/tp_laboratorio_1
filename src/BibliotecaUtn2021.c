/*
 * Biblioteca2021.c
 *
 *  Created on: 12 sep. 2021
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

static int esLetra(char* cadena)
{
	int retorno = -1;
	int i = 0;

	for(; cadena[i] != '\0'; i++)
	{
		if((cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 'a' && cadena[i] <= 'z'))
		{
			retorno = 1;
		}
		else
		{
			//printf("\nentro ELSE valor -%d-", cadena[i]);
			retorno = 0;
			break;
		}

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

int utn_getNumberFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%f",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
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

int utn_getCharacter(char* pResultado, char mensaje[] , char* mensajeError, int reintentos)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);

			if(myGets(buffer, sizeof(buffer)) == 0 && esLetra(buffer) == 1)
			{
				stpcpy(pResultado,buffer);
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

int utn_sumar(int primerNumero, int segundoNumero, int* pResultado)
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

int utn_restar(int primerNumero, int segundoNumero, int* pResultado)
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

float utn_dividir(int primerNumero, int segundoNumero, float* pResultado)
{
	int retorno = -1;
	int resultado;

	if(pResultado != NULL)
	{
		resultado = (float)primerNumero / segundoNumero;
		retorno = 0;
	}

	*pResultado = resultado;

	return retorno;
}

int utn_multiplicar(int primerNumero, int segundoNumero, int* pResultado)
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

int utn_nombreOapellido(char* string, char* mensaje, char* mensajeError, int tam, int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	int retornoMyGets;
	int retornoEsLetra;


	if(string != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
		   printf("%s\n", mensaje);

		   retornoMyGets = myGets(buffer, sizeof(buffer));
		   retornoEsLetra = esLetra(buffer);

			if(retornoMyGets == 0 && retornoEsLetra == 1 )
			{
			   retorno = 0;
			   char mayus;
			   char minus;
			   mayus = toupper(buffer[0]);
			   buffer[0] = mayus;

			   for( int i = 1; i < tam - 1; i++)
			   {
				   minus = tolower(buffer[i]);
				   buffer[i] = minus;
			   }

				strcpy(string, buffer);
				break;
			}
			else
			{
				printf("%s\n", mensajeError);
				reintentos --;
			}

		}while(reintentos >= 0);

		if(reintentos < 0)
		{
			printf("\nSe quedo sin intentos para ingresar correctamente sus datos.\n");
		}

		}

	return retorno;
}
int utn_mostrarNumeros(int* array, char* mensaje, int tam)
{
	int retorno = -1;

	if(array != NULL && mensaje != NULL)
	{
		printf("%s",mensaje);

		for(int i = 0; i < tam; i++)
		{
		    printf(" [%d] ", array[i]);
		}

		retorno = 0;
	}

	return retorno;
}

int utn_cargarArrayNumeros(int arrayNumeros[], int tam, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(arrayNumeros != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		printf("%s",mensaje);

		for(int i = 0; i < tam; i++)
		{
			printf("\nIngreso Nº %d", i+ 1);

			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				arrayNumeros[i] = bufferInt;
				retorno = 0;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
				i--;
				if(reintentos == 0)
				{
					printf("\nSe ha quedado sin reintentos para ingresar correctamente los valores\n\n"
							"FIN DEL PROGRAMA.");
					retorno = -1;
					break;
				}
		}

		}
	}
	return retorno;
}

int utn_ordenarArrayCreciente(int* array, int tam)
{
	int retorno = -1;
	int flagSwap;
	int contador = 0;
	int buffer;
	int nuevoLimite;

	if(array != NULL && tam >= 0)
	{
		nuevoLimite = tam -1;

		do
		{
			flagSwap = 0;
			for(int i = 0; i < nuevoLimite; i++)
			{
				contador++;
				if(array[i] > array[i+1])
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1] = buffer;
				}
			}

		}while(flagSwap);

		retorno = contador;
	}
	return retorno;
}

int utn_ordenarArrayDecreciente(int* array, int tam)
{
	int retorno = -1;
	int flagSwap;
	int contador = 0;
	int buffer;
	int nuevoLimite;

	if(array != NULL && tam > 0)
	{
		nuevoLimite = tam -1;

		do
		{
			flagSwap = 0;
			for(int i = 0; i < nuevoLimite; i++)
			{
				contador++;
				if(array[i] < array[i+1])
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1] = buffer;
				}
			}
			nuevoLimite --;
		}while(flagSwap);

		retorno = contador;
	}
	return retorno;
}

int utn_numerosPositivos(int array[], int positivos[], int tam)
{
	int retorno = -1;
	int indiceBuffer = 0;
	int buffer[tam];
	if(tam>0 && array!=NULL && positivos!=NULL)
	{

	}
	return retorno;
}

int inicializacionArray(int array[], int tam)
{
	int retorno = -1;

	if(array != NULL)
	{
		 for(int i = 0 ; i < 5 ; i++)
		{
			array[i] = 0;
		}
		retorno = 0;
	}

    return retorno;
}

int utn_promedio(int numerador, int denominador, float* pResultadoF)
{
	 int retorno = -1;
	 float resultado;

	 if(denominador != 0 && pResultadoF != NULL)
	 {
		 retorno = 0;
		 resultado = (float)numerador / denominador;
	 }
	 else
	 {
		 printf("\nError. No puede realizarse la division por 0.");
	 }

	 *pResultadoF = resultado;

	 return retorno;

}



