#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char strId[50];
	char strNombre[128];
	char strHorasTrabajadas[50];
	char strSueldo[50];
	int leidos;
	Employee* pNewEmpleado;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			leidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", strId, strNombre,strHorasTrabajadas,strSueldo);
			if(leidos == 4)
			{
				pNewEmpleado = employee_newParametros(strId, strNombre,strHorasTrabajadas,strSueldo);
				ll_add(pArrayListEmployee,pNewEmpleado);
				retorno = 0;
			}
			else
			{
				printf("\n »» Error en la lectura.");
				retorno = -1;
				break;
			}

		}while(!feof(pFile));
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int leidos;
	Employee* pNewEmployee;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			pNewEmployee = employee_new();

			leidos = fread(pNewEmployee, sizeof(Employee),1, pFile);

			if(leidos == 1)
			{
				ll_add(pArrayListEmployee, pNewEmployee);
				retorno = 0;
			}
			else
			{
				printf("\n »» Error en la lectura.");
				retorno = -1;
				break;
			}

		}while(!feof(pFile));

	}

    return retorno;
}
