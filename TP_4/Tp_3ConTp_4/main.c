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
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "BibliotecaUtn2021.h"

int main()
{
    LinkedList* employeeList = ll_newLinkedList();
    int option;
    int flagCarga = 0;

	 do
	 {
		 printf("\n\t\t »»»»» MENU PRINCIPAL «««««\n");
		if( utn_getNumber(&option,""
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
				"\n »» INGRESE UNA OPCION:  ", "\n × ERROR. ", 1, 10, 1) == 0)
		{
			switch(option)
			{
				case 1:
					if(flagCarga == 0)
					{
						if(controller_loadFromText("data.csv", employeeList) == 0)
						{
							flagCarga = 1;
							printf("\n »» CARGA DE DATOS EXITOSA ");
						}
						else
						{
							printf("\n X No se han cargado los datos.");
						}
					}
					else
					{
					    printf("\n >> Ya se cargaron los datos");
					}

					systemPause("\n »»»» Presione enter para continuar...");
					break;
				case 2:
					if(flagCarga == 0)
					{
						if(controller_loadFromBinary("dataBin.bin", employeeList) == 0)
						{
							flagCarga = 1;
							printf("\n »» CARGA DE DATOS EXITOSA ");
						}
						else
						{
							printf("\n X  No se encontro archivo binario .");
						}
					}
					else
					{
						 printf("\n >> Ya se cargaron los datos");
					}

					systemPause("\n »»»» Presione enter para continuar...");
					break;
				case 3:
					if(flagCarga == 1)
					{
						if(controller_addEmployee(employeeList) == 0)
						{
							printf("\n »» CARGA DE DATOS EXITOSA ");
						}
						else
						{
							printf("\n X No se dio de alta.");
						}
					}
					else
					{
						printf("\n »» Primero se debe cargar el archivo.");
					}
					systemPause("\n »»»» Presione enter para continuar...");
					break;
				case 4:
					if(flagCarga == 1)
					{
						if(controller_editEmployee(employeeList) == 0)
						{
							printf("\n »» MODIFICACION EXITOSA ");
						}
						else
						{
							printf("\n X No se modifico ningun empleado.");
						}
					}
					else
					{
						printf("\n X No existen datos cargados.");
					}
					systemPause("\n »»»» Presione enter para continuar...");
					break;
				case 5:
					if(flagCarga == 1)
					{
						if(controller_removeEmployee(employeeList) == 0)
						{
							printf("\n »» ELIMINACION EXITOSA ");
						}
						else
						{
							printf("\n X No se ha eliminado ningun empleado.");
						}
					}
					else
					{
						printf("\n X No existen datos cargados.");
					}
					systemPause("\n »»»» Presione enter para continuar...");
					break;
				case 6:
					if(flagCarga == 1)
					{
						if(controller_ListEmployee(employeeList) != 0)
						{
							printf("\n X No se ha podido mostrar el listado.");
						}
					}
					else
					{
						printf("\n X No existen datos cargados.");
					}
					systemPause("\n »»»» Presione enter para continuar...");
					break;
				case 7:
					if(flagCarga == 1)
					{
						if(controller_sortEmployee(employeeList) == 0)
						{
							controller_ListEmployee(employeeList);
						}
						else
						{
							printf("\n X No se pudo realizar el ordenamiento.");
						}
					}
					else
					{
						printf("\n X No existen datos cargados.");
					}
					systemPause("\n »»»» Presione enter para continuar...");
					break;
				case 8:
					if(flagCarga == 1)
					{
						if(controller_saveAsText("data.csv", employeeList) == 0)
						{
							printf("\n »» EL ARCHIVO SE GUARDO EXITOSAMENTE.");
						}
						else
						{
							printf("\n X No se pudo guardar el archivo en modo texto.");
						}
					}
					else
					{
						printf("\n X No existen datos cargados.");
					}
					systemPause("\n »»»» Presione enter para continuar...");
					break;
				case 9:
					if(flagCarga == 1)
					{
						if(controller_saveAsBinary("dataBin.bin", employeeList) == 0)
						{
							 printf("\n »» EL ARCHIVO SE GUARDO EXITOSAMENTE.");
						}
						else
						{
							printf("\n X No se pudo guardar el archivo en modo texto.");
						}
					}
					else
					{
						printf("\n X No existen datos cargados.");
					}
					systemPause("\n »»»» Presione enter para continuar...");
					break;
				case 10:
					printf("\n »»» FIN DEL PROGRAMA ««« ");
					ll_deleteLinkedList(employeeList);
					break;
			}
		}
	 }while(option != 10);

    return 0;
}


