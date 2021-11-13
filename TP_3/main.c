/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "BibliotecaUtn2021.h"

int main()
{
    LinkedList* employeeList = ll_newLinkedList();
    int option;

	 do
	 {
		 printf("\n\t\t »»»»» MENU PRINCIPAL «««««\n");
		 utn_getNumber(&option,""
				"\n[1] Cargar datos de empleados desde data.csv (modo texto)."
				"\n[2] Cargar datos de empleados desde  data.bin (modo binario)."
				"\n[3] Agregar empleado "
				"\n[4] Modificar datos de empleado"
				"\n[5] Eliminar empleado "
				"\n[6] Listar todos los empleados"
				"\n[7] Ordenar empleados "
				"\n[8] Guardar informacion de empleados al archivo data.csv (modo texto)."
				"\n[9] Guardar informacion de empleados al archivo data.bin (modo binario)."
				"\n[10] Salir."
				"\n »» INGRESE UNA OPCION:  ", "\n × ERROR. ", 1, 10, 1);
		switch(option)
		{
			case 1:
			    if(controller_loadFromText("data.csv", employeeList) == 0)
			    {
			    	printf("\n »» CARGA DE DATOS EXITOSA ");
			    }
			    else
			    {
			    	printf("\n »» No se han cargado los datos.");
			    }
				break;
			case 2:
				if(controller_loadFromBinary("data.csv", employeeList) == 0)
				{
					printf("\n »» CARGA DE DATOS EXITOSA ");
				}
				else
				{
					printf("\n »» No se han cargado los datos.");
				}

				break;
			case 3:
				if(controller_addEmployee(employeeList) == 0)
				{
					printf("\n »» CARGA DE DATOS EXITOSA ");
				}
				else
				{
					printf("\n »» No se dio de alta ningun empleado.");
				}
				break;
			case 4:
				if(controller_editEmployee(employeeList) == 0)
				{
					printf("\n »» MODIFICACION EXITOSA ");
				}
				else
				{
					printf("\n »» No se modifico ningun empleado.");
				}
				break;
			case 5:
				if(controller_removeEmployee(employeeList) == 0)
				{
					printf("\n »» ELIMINACION EXITOSA ");
				}
				else
				{
					printf("\n »» No se ha eliminado ningun empleado.");
				}
				break;
			case 6:
				controller_ListEmployee(employeeList);
				break;
			case 7:
				controller_sortEmployee(employeeList);
				break;
			case 8:
				if(controller_saveAsText("data.csv", employeeList) == 0)
				{
					printf("\n »» SE HA GUARDADO CORRECTAMENTE EL ARCHIVO.");
				}
				break;
			case 9:
				break;
			case 10:
				printf("\n »»» FIN DEL PROGRAMA ««« ");
				ll_deleteLinkedList(employeeList);
				break;
		}
	}while(option != 10);




    return 0;
}


