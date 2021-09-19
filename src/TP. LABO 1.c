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
// MI PAPI ES LO MAS
//buuyguguyguyguy
//oijoijiuihipu
int main(void) {
	int opcion;
    int primerOperando;
    int segundoOperando;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDiision;
    int resultadoMutiplicacion;

    do
    {

		if(utn_getNumber(&opcion, "Ingrese el numero de la opcion deseada: "
					"\n1.Ingresar el 1º operando.\n2. Ingresar el 2º operando.\n3.Calcular todas las operaciones\n"
					"4. Informar resultados.\n5. Salir.\n","ERROR. Reingrese la opcion.\n", 1, 5, 2) == 0)
			{
				switch(opcion)
				{
					case 1:
						if(utn_getNumber(&primerOperando, "Ha elegido la opcion 1. Ingrese el primer operando: "
								, "ERROR. Reingrese el operando, el mismo no puede ser negativo.", 0, 1000000, 2) == 0)
						{
							printf("\nUsted ha ingresado el numero %d\n", primerOperando);
						}
						break;
					case 2:
						if(utn_getNumber(&segundoOperando, "Ha elegido la opcion 2. Ingrese el segundo operando: "
								, "ERROR. Reingrese el operando, el mismo no puede ser negativo.", 0, 1000000, 2) == 0)
						{
							printf("\nUsted ha ingresado el numero %d\n", segundoOperando);
						}
						break;
					case 3:
						/// suponete case 3 tenes funcSuma funDivison funResta
						printf("Usted ha elegido la opcion 3. Se calcularan todas las operaciones.\n");

						utn_sumar(primerOperando, segundoOperando, &resultadoSuma);
						utn_restar(primerOperando, segundoOperando, &resultadoResta);
						utn_dividir(primerOperando, segundoOperando, &resultadoDiision);
						utn_multiplicar(primerOperando, segundoOperando, &resultadoMutiplicacion);
						break;
					case 4:
						/// MOSTRAR CALCULOS REALIZADOS
						printf("Usted ha elegido la opcion nº 4. Se le mostrara un informe de los resultados obtenidos en las operaciones realizadas.\n"
								"RESULTADO DE LA SUMA : %d\n RESULTADO RESTA: %d\n RSULTADO DIVISION: %.2f\n RESULTADO MULTIPLICACION: %d\n",
								resultadoSuma, resultadoResta, resultadoDiision, resultadoMutiplicacion);
						break;
					case 5: // TE vas
						printf("Usted ha elegido la opcion nº 5 SALIR DEL PROGRAMA.");
						break;
					default:
						printf("Ingresa una opcion correcta papafrita. Te queda 1 intento.");
						break;
					}

			}

    }while(opcion != 5);

	return EXIT_SUCCESS;
}
