/*
 * Employee.c
 *
 *  Created on: 28 sep. 2021
 *      Author: sole
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "BibliotecaUtn2021.h"
#include "Employee.h"

/**
 * @fn int utn_menu()
 * @brief muestra un cartel de menu con opciones para que el ususario elija la accion que
 * desea realizar
 *
 * @return devuelve un entero, en este caso indicando la opcion elegida
 */
int menuEmployee()
{
	int option;

	printf("\n** BIENVENIDO AL CENTRO DE MONITOREO DE EMPLEADOS **\n");
	printf("-------------------------------------------------");

	if(utn_getNumber(&option, "\n#### Ingrese una opcion: #### \n"
			"\n1. Registrar un empleado."
			"\n2. Modificar un empleado."
			"\n3. Dar de baja un empleado."
			"\n4. Mostrar lista de empleados."
			"\n5. Salir"
			"\n------------------------------------------------\n", "\nError. Reingrese la opcion:\n", 1, 5, 1) == 0)
	{
		printf("\nUsted ha elegido la opcion: %d\n", option);
	}

	return option;
}

/**
 * @fn void initEmployees(Employee*, int)
 * @brief iniciliza el campo isEmpty dentro del array de tipo Employee para evitar
 *  que muestre basura
 *
 * @param arrayEmp
 * @param tam
 */
void initEmployees(Employee* arrayEmp,int tam)
{
	if(arrayEmp != NULL && tam > 0)
	{
		for(int i=0;i<tam;i++)
		{
			arrayEmp[i].isEmpty=0;
		}
	}

}

/**
 * @fn void cargaEmployeeHard(Employee*, int*)
 * @brief carga en modo harcode de algunos datos
 *
 * @param arrayEmp
 * @param id
 */
void cargaEmployeeHard(Employee* arrayEmp, int* id)
{
	Employee bufferArray[] =
	{
			{100, "Roberta", "Bonanza", 13560.2, 2,1},
			{101, "Magenta", "Perez", 12500, 10,1},
			{102, "Fernando", "Huespedes", 5600.35, 4,1},
	};

    for(int i = 0; i < 3; i++)
    {
    	arrayEmp[i] = bufferArray[i];
    	(*id)++;
    }



}

/**
 * @fn void mostrarDatosEmployee(Employee)
 * @brief muestra los datos de un solo dato de tipo Employee
 *
 * @param unidadEmp
 */
void mostrarDatosEmployee(Employee unidadEmp)
{
		printf("\nId: %d", unidadEmp.id);
		printf("\nName: %s", unidadEmp.name);
		printf("\nLast Name: %s", unidadEmp.lastName);
		printf("\nSalary: %.2f", unidadEmp.salary);
		printf("\nSector: %d", unidadEmp.sector);
		printf("\n----------------------------------------\n");
}

/**
 * @fn void showListEmployee(Employee*, int)
 * @brief muestra una lista del array del tipo Employee
 *
 * @param arrayEmp
 * @param tam
 */
void showListEmployee(Employee* arrayEmp, int tam)
{
	for(int i  = 0; i < tam; i ++)
	{
		if(arrayEmp[i].isEmpty == 1)
		{
			mostrarDatosEmployee(arrayEmp[i]);
		}
	}
}

/**
 * @fn int deleteEmployee(Employee*, int)
 * @brief elimina un dato de tipo Employee del array
 *
 * @param arrayEmp
 * @param len
 * @return si la funcion pudo cumplir con su tarea retorna 0, en caso contrario -1
 */
int deleteEmployee(Employee* arrayEmp, int len)
{
	int retorno = -1;
	int id;
	int index;

	if(arrayEmp != NULL)
	{
		printf("\n***** DAR DE BAJA UN EMPLEADO *****\n");

		showListEmployee(arrayEmp, len);

	 if(utn_getNumber(&id, "Ingrese el Id del empleado que desea eliminar:"
				, "Error. Reingrese el ID:", 100, 1000, 1) == 0 && findById(arrayEmp, len, id, &index))

		if(deleteOneEmp(&arrayEmp[index]) == 0)
		{
			retorno = 0;
		}
	}


   return retorno;
}

/**
 * @fn int registerAnEmployee(Employee*, int)
 * @brief da de alta un empleado dentro del array de tipo employee
 *
 * @param arrayEmp
 * @param len
 * @return si la funcion pudo cumplir con su tarea retorna 0, en caso contrario -1
 */
int registerAnEmployee(Employee* arrayEmp, int len, int* id)
{
	int retorno = -1;
	int i;

	Employee auxEmployee;

    if(arrayEmp != NULL)
    {
    	i = findIsEmpty(arrayEmp, len);

    	if(utn_nombreOapellido(auxEmployee.name, "Ingrese el nombre: ","Error. Reingrese el nombre", TAM, 1) == 0
    			&& utn_nombreOapellido(auxEmployee.lastName,"Ingrese el apellido: ", "Error. Reingrese el apellido", TAM,1) == 0
    			&& utn_getNumberFloat(&auxEmployee.salary,"Ingrese el sueldo: ", "Error. Reingrese el sueldo:", 0, 1000000,1) == 0
    			&& utn_getNumber(&auxEmployee.sector, "Ingrese el sector:","Error. Reingrese el sector:", 1, 50, 1) == 0)
		{
    		printf("ubicacion INDEX -- > %d", i);
			addEmployee(&arrayEmp[i], id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);
			retorno = 0;
		}

    }

    return retorno;
}

/**
 * @fn int isEmpty(Employee*, int, int*)
 * @brief me sirve para saber que ubicaion en el indice tengo disponible para volcar alli nuevo datos
 *
 * @param arrayE
 * @param tam
 * @param indice
 * @return retorna el estado del indice, retorna 0 si esta libre
 */
int findIsEmpty(Employee* arrayE, int tam)
{
	int index = -1;

	if(arrayE != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(arrayE[i].isEmpty == 0)
			{
			  index = i;
			  break;
			}
		}
	}

	return index;
}

int addEmployee(Employee* arrayEmp, int* id, char* name, char* lastName, float salary, int sector)
{
	int retorno = -1;

	if(arrayEmp != NULL && id != NULL && name != NULL && lastName != NULL )
	{
		(*arrayEmp).isEmpty = 1;
		(*arrayEmp).id = (*id)++;
		strcpy((*arrayEmp).name, name);
		strcpy((*arrayEmp).lastName, lastName);
		(*arrayEmp).salary = salary;
		(*arrayEmp).sector = sector;

		retorno = 0;
	}

	return retorno;
}

int findById(Employee* arraEmp, int len, int id, int* index)
{
	int retorno = -1;

	if(arraEmp != NULL && index != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(arraEmp[i].id == id)
			{
				retorno = 0;
				* index = i;
			}
		}
	}

	return retorno;
}

int menuModify(Employee* arrayEmp, int len, int* index, int* option)
{
	int retorno = -1;
	int idWanted;

	if(arrayEmp != NULL && index != NULL && option != NULL)
	{
		if(utn_getNumber(&idWanted,"\nIngrese el ID del empleado que desea modificar."
				,"\nError. Reingrese el ID.",0, 1000, 1) == 0 &&
				findById(arrayEmp, len, idWanted, index) == 0)
		{
			if(utn_getNumber(option,"\nIngrese la opcion del dato que desea modificar: "
					"\n1. NOMBRE. "
					"\n2. APELLIDO. "
					"\n3. SALARIO. "
					"\n4. SECTOR. "
					"\n5. SALIR. "
					, "\nError. Reingrese la opcion.", 1,5, 1) == 0)
			{
				printf("\nUsted ha ingresado la opcion nº %d", *option);
				retorno = 0;
			}

		}
		else
		{
			printf("\nEl ID ingreado es inexistente.");
		}

	}

	return retorno;
}

int modifyEmployee(Employee* arrayEmp, int len)
{
	int retorno = -1;
	int option;
	int index;
	Employee bufferEmp;

	if(arrayEmp != NULL)
	{
		do
		{
			if(menuModify(arrayEmp, len, &index, &option) == 0)
			{
				switch(option)
				{
					case 1:
						if(utn_nombreOapellido(bufferEmp.name, "\nIngrese el nuevo nombre: ",
								"\nError. Reingrese el nombre.", len, 1) == 0)
						{
							printf("\nEl nuevo nombre es: %s", bufferEmp.name);
							strcpy(arrayEmp[index].name,bufferEmp.name);
						}
						else
						{
							printf("\nNo se ha podido realizar la modificacion de manera correcta");
						}
						break;
					case 2:
						if(utn_nombreOapellido(bufferEmp.lastName,"\nIngrese el nuevo apellido."
								,"\nError. Reingrese el apellido.", len, 1) == 0)
						{
							printf("\nEl nuevo apellido es: %s", bufferEmp.lastName);
							strcpy(arrayEmp[index].lastName,bufferEmp.lastName);
						}
						else
						{
							printf("\nNo se ha podido realizar la modificacion de manera correcta");
						}
						break;
					case 3:
						if(utn_getNumberFloat(&bufferEmp.salary, "\nIngrese el nuevo monto del salario."
								, "\nError. Reingrese el salario.", 30000, 300000, 1) == 0)
						{
							printf("\nEl nuevo salario es: %.2f", bufferEmp.salary);
							(arrayEmp[index]).salary = bufferEmp.salary;
						}
						else
						{
							printf("\nNo se ha podido realizar la modificacion de manera correcta");
						}
						break;
					case 4:
						if(utn_getNumber(&bufferEmp.sector, "\nIngrese el nuevo sector."
								, "\nError. Reingrese el sector.", 1, 15, 2) == 0)
						{
							printf("\nEl nuevo sector es: %d", bufferEmp.sector);
							(arrayEmp[index]).sector = bufferEmp.sector;
						}
						else
						{
							printf("\nNo se ha podido realizar la modificacion de manera correcta");
						}
						break;
					case 5:
						printf(" Salir.");
						break;
				}

				retorno = 0;
			}
		}while(option != 5);

	}

	return retorno;

}

int deleteOneEmp(Employee* unitEmployee)
{
	int retorno=-1;

	if(unitEmployee!=NULL)
	{
		(*unitEmployee).isEmpty=0;
		retorno =0 ;
	}
	return retorno;
}

int menuReports()
{
	int option;

	printf("***** INFORMES *****");

	if(utn_getNumber(&option, "\nElija una opcion:"
			"\n1. Listar empleados alfabeticamente."
			"\n2. Informe de Salarios."
			"\n3. Salir de Informes.", "\nError. Reingrese la opcion.", 1,3, 1) == 0)
	{
		printf("\nUsted ha ingresado la opcion nº %d", option);
	}

	return option;
}

int sortEmployeesLastName(Employee* arrayEmp, int len)
{
	int retorno = -1;
	int flag = 1;
	int newLen;
	Employee bufferEmployee;

	if(arrayEmp != NULL)
	{
		newLen = len - 1;
		do
		{
			flag = 1;
			for(int i = 0; i < newLen; i++)
			{
				if(strcmp(arrayEmp[i].lastName, arrayEmp[i+1].lastName) > 0)
				{
					flag = 0;
					bufferEmployee = arrayEmp[i];
					arrayEmp[i] = arrayEmp[i+1];
					arrayEmp[i+1] = bufferEmployee;
					retorno = 0;
				}
				else
				{
					if(strcmp(arrayEmp[i].lastName, arrayEmp[i+1].lastName) == 0)
					{
						if(arrayEmp[i].sector > arrayEmp[i+1].sector)
						{
							flag = 0;
							bufferEmployee = arrayEmp[i];
							arrayEmp[i] = arrayEmp[i+1];
							arrayEmp[i+1] = bufferEmployee;
							retorno = 0;
						}
					}
				}
				newLen--;
			}

		}while(flag == 0);
		}
	return retorno;
}

float totalSalaries(Employee* arrayEmp, int len)
{
	float totalSalaries=0;

	if(arrayEmp != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(arrayEmp[i].isEmpty==1)
			{
				totalSalaries += arrayEmp[i].salary;
			}
		}
	}

	return totalSalaries;
}

int employeeCount(Employee* arrayEmp, int len)
{
	int cantidad = 0;

	for(int i = 0; i < len; i++)
	{
		if(arrayEmp[i].isEmpty==1)
		{
			cantidad++;
		}
	}
	return cantidad;
}


int infoSalaries(Employee* arrayEmp, int len, float* total, float* promedio, int* exceedAverage )
{
	int retorno = -1;
	int counterExceedAverage=0;

	if(arrayEmp != NULL && total != NULL && promedio != NULL && exceedAverage != NULL)
	{
		*total = totalSalaries(arrayEmp, len);
		*promedio =  *total/employeeCount(arrayEmp, len);

		for(int i = 0; i < len; i++)
		{
			if(arrayEmp[i].salary > *promedio)
			{
				counterExceedAverage++;
			}
		}

		*exceedAverage = counterExceedAverage;
		retorno = 0;
	}

	return retorno;
}


