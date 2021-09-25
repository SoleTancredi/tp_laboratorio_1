/*
 ============================================================================
 Name        : .c
 Author      : Sole Tancredi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "BibliotecaUtn2021.h"
#include "BibliotecaCalculadora.h"

int main(void)
{
	int opcion;
    float primerOperando;
    float segundoOperando;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMutiplicacion;
    int retornoDivision;
    int retornoPrimerFactorial;
    int retornoSegundoFactorial;
    long int resultadoFactorialUno=0;
    long int resultadoFactorialDos=0;
    int flagPrimerOperando = 0;
    int flagSegundoOperando = 0;
    int flagCalculos = 0;


    do
    {
    	printf("\n***** CALCULADORA *****\n");

		if(utn_getNumber(&opcion, "\nIngrese el numero de la opcion deseada: \n"
				"\n1. Ingresar el 1º operando."
				"\n2. Ingresar el 2º operando."
				"\n3. Calcular todas las operaciones"
				"\n4. Informar resultados."
				"\n5. Salir.\n",
				"ERROR. Reingrese la opcion.\n", 1, 5, 2) == 0)
			{
				switch(opcion)
				{
					case 1:

						if(utn_getNumberFloat(&primerOperando, "\nIngrese el primer operando: "
								, "\nERROR. Reingrese el operando.\n", MinValue, MaxValue, 2) == 0)
						{

							printf("\nUsted ha ingresado el numero %.2f\n", primerOperando);
							flagPrimerOperando = 1;
						}
						break;

					case 2:

						if(utn_getNumberFloat(&segundoOperando, "\nIngrese el segundo operando: "
								, "\nERROR. Reingrese el operando.\n", MinValue, MaxValue, 2) == 0)
						{
							printf("\nUsted ha ingresado el numero %.2f\n", segundoOperando);
							flagSegundoOperando = 1;
						}
						else
						{
							puts("\nAntes ingrese el primer operando.");
						}
						break;

					case 3:

						if(flagPrimerOperando == 1 && flagSegundoOperando == 1)
						{

							if(sumar(primerOperando, segundoOperando, &resultadoSuma) == 0 &&
								restar(primerOperando, segundoOperando, &resultadoResta) == 0 &&
								multiplicar(primerOperando, segundoOperando, &resultadoMutiplicacion) == 0)
							{
								retornoPrimerFactorial = factorial((int)primerOperando,&resultadoFactorialUno);
								retornoSegundoFactorial = factorial((int)segundoOperando,&resultadoFactorialDos);
								retornoDivision = dividir(primerOperando, segundoOperando, &resultadoDivision);
                                printf("\nSe han realizado todos los calculos.\n");
								flagCalculos = 1;
							}
						}
						else
						{
							printf("\nNo se han podido realizar las operaciones. Ingrese correctamente los operandos.\n");
						}

						break;

					case 4:

						if(flagCalculos == 1)
						{
							printf("\nLos resultados de las operaciones realizadas son:\n "
							"\nRESULTADO DE LA SUMA : %.2f \nRESULTADO RESTA: %.2f"
							"\nRESULTADO MULTIPLICACION: %.2f\n", resultadoSuma, resultadoResta, resultadoMutiplicacion);

							if(retornoPrimerFactorial == 0)
							{
								printf("FACTORIAL DEL PRIMER OPERANDO: %ld\n", resultadoFactorialUno);
							}
							else
							{
								printf("FACTORIAL DEL PRIMER OPERANDO: No fue posible calcular el factorial de un numero negativo\n");
							}

							if(retornoSegundoFactorial == 0)
							{
								printf("FACTORIAL DEL SEGUNDO OPERANDO: %ld\n", resultadoFactorialDos);
							}
							else
							{
								printf("FACTORIAL DEL PRIMER OPERANDO: No fue posible calcular el factorial de un numero negativo\n");
							}

							if(retornoDivision == 0)
							{
								printf("RESULTADO DE LA DIVISION: %.2f\n", resultadoDivision);
							}
							else
							{
								printf("RESULTADO DE LA DIVISION: No es posible dividir por 0.\n");
							}
						}
						else
						{
							printf("\nNo se puede mostrar el informe de resultados, sin antes realizar los Calculos de la opcion 3.\n");
						}

						break;

					case 5:

						printf("FIN DEL PROGRAMA.");
						break;

					default:

						printf("\nIngresa una opcion correcta papafrita. Te queda 1 intento.\n");
						break;
					}

			}

    }while(opcion != 5);

	return EXIT_SUCCESS;
}
