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
	int opcion;
	int flagCarga = 0;
	initEmployees(arrayEmp, TAM);

    do
    {
    	opcion = menuEmployee();

		switch(opcion)
		{
			case 1:
				cargaEmployeeHard(arrayEmp, &id);
				if(registerAnEmployee(arrayEmp, TAM, &id) == 0)
				{
					flagCarga = 1;
					printf("\n// EL EMPLEADO HA SIDO CARGADO EXITOSAMENTE. \\");
				}
				break;
			case 2:
				if(flagCarga == 1 && modifyEmployee(arrayEmp, TAM) == 0)
				{
					printf("\n// EL EMPLEADO HA SIDO MODIFICADO EXITOSAMENTE. \\");
				}
				break;
			case 3:
				if(flagCarga == 1 && deleteEmployee(arrayEmp, TAM))
				{
					printf("\n// EL EMPLEADO HA SIDO ELIMINADO EXITOSAMENTE. \\");
				}
				break;
			case 4:

				if(sortEmployees(arrayEmp, TAM)==0 )
				{
					printf("funciono");
					showListEmployee(arrayEmp, TAM);
				}
				else
				{
					printf("\nNo hay elementos cargados.");
				}
				break;
			case 5:
				printf("FIN DEL PROGRAMA");
				break;
    		}

    }while(opcion != 10);













	return EXIT_SUCCESS;
}
