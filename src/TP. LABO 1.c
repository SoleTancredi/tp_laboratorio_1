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
#include "BibliotecaCalculadora.h"

int main(void) {
	int opcion;
    int primerOperando;
    int segundoOperando;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMutiplicacion;
    int retornoDivision;
    long int resultadoFactorialUno=0;
    long int resultadoFactorialDos=0;
    int flagPrimerOperando = 0;
    int flagSegundoOperando = 0;
    int flagCalculos = 0;

    do
    {

		if(utn_getNumber(&opcion, "\nIngrese el numero de la opcion deseada: ""\n1.Ingresar el 1º operando."
				"\n2. Ingresar el 2º operando.\n3.Calcular todas las operaciones\n""4. Informar resultados."
						"\n5. Salir.\n","ERROR. Reingrese la opcion.\n", 1, 5, 2) == 0)
			{
				switch(opcion)
				{
					case 1:

						if(utn_getNumber(&primerOperando, "\nIngrese el primer operando: "
								, "ERROR. Reingrese el operando, el mismo no puede ser negativo.", MinValueINT, MaxValueINT, 2) == 0)
						{
							printf("\nUsted ha ingresado el numero %d\n", primerOperando);
							flagPrimerOperando = 1;
						}
						break;

					case 2:

						if(utn_getNumber(&segundoOperando, "\nIngrese el segundo operando: "
								, "ERROR. Reingrese el operando, el mismo no puede ser negativo.", MinValueINT, MaxValueINT, 2) == 0)
						{
							printf("\nUsted ha ingresado el numero %d\n", segundoOperando);
							flagSegundoOperando = 1;
						}
						else
						{
							puts("\nAntes ingrese primer operando ");
						}
						break;

					case 3:

						if(flagPrimerOperando == 1 && flagSegundoOperando == 1)
						{

							if(sumar(primerOperando, segundoOperando, &resultadoSuma) == 0 &&
								restar(primerOperando, segundoOperando, &resultadoResta) == 0 &&
								multiplicar(primerOperando, segundoOperando, &resultadoMutiplicacion) == 0 &&
								factorial(primerOperando,&resultadoFactorialUno) == 0 && factorial(segundoOperando, &resultadoFactorialDos) == 0)
							{
								retornoDivision = dividir(primerOperando, segundoOperando, &resultadoDivision);

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
							"\nRESULTADO DE LA SUMA : %d \nRESULTADO RESTA: %d\nRESULTADO MULTIPLICACION: %d \n"
							"RESULTADO DEL FACTORIAL DEL PRIMER OPERANDO: %ld \nRESULTADO DEL FACTORIAL DEL SEGUNDO OPERANDO: %ld \n",
							resultadoSuma, resultadoResta, resultadoMutiplicacion, resultadoFactorialUno, resultadoFactorialDos);
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
