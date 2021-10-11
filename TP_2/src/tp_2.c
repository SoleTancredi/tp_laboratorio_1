/*
 ============================================================================
 Name        : Tp2.c
 Author      : Sole Tancredi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "BibliotecaUtn2021.h"
#include "Employee.h"
#define TAM 100

int main(void)
{
	Employee arrayEmp[TAM];
	int id = 100;
	int answer;
	initEmployees(arrayEmp, TAM);
    cargaEmployeeHard(arrayEmp, &id);

	answer = utn_menu();

	switch(answer)
	{
		case 1:
			if(registerAnEmployee(arrayEmp, TAM, &id) == 0)
			{
				printf("\n// EL EMPLEADO HA SIDO CARGADO EXITOSAMENTE. \\");
			}
			break;
		case 2:


			break;
		case 3:
			//hacer funcion modif
			break;
		case 4:
			showListEmployee(arrayEmp, TAM);
		    break;
		case 5:
			// hacer funcion ordenar alfab menor a mayor
			break;
		case 6:
			//ordenar alfa mayor a menor
			break;
		case 7:
			//total de salarios
			break;
		case 8:
			//promedio de salarios
			break;
		case 9:
			// cantidad de empleado por sobre el promedio de salario
			break;

	}













	return EXIT_SUCCESS;
}
