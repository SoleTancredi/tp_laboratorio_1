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
	int opcionInformes;
	int flagCarga = 0;
	float totalSalarios;
	float promedioSalarios;
	int cantEmpleadosSobrePromedio;
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

				if(flagCarga == 1)
				{
					opcionInformes = menuReports();

					switch(opcionInformes)
					{
						case 1:
							if(sortEmployeesLastName(arrayEmp, TAM) == 0)
							{
								printf("\n// LISTA ORDENADA CORRECTAMENTE. //");
							}
							else
							{
								printf("\nNo se ha podido realizar la operacion.");
							}
							break;
						case 2:
							if(infoSalaries(arrayEmp, TAM, &totalSalarios, &promedioSalarios, &cantEmpleadosSobrePromedio) == 0)
							{
								printf("\nEl total de todos los salarios es: %.2f", totalSalarios);
								printf("\nEl promedio de todos los salarios es: %.2f", promedioSalarios);
								printf("\nLa cantidad de empleado con un salario por sobre el promedio es: %d", cantEmpleadosSobrePromedio);
							}
							break;
						case 3:

							break;
					}

				}




				break;
			case 5:
				printf("FIN DEL PROGRAMA");
				break;
    		}

    }while(opcion != 5);













	return EXIT_SUCCESS;
}
