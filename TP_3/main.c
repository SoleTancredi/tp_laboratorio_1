#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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



int main()
{


   // LinkedList* listaEmpleados = ll_newLinkedList();

    LinkedList* pipiList = ll_newLinkedList();

    Employee* pEmpleado = employee_new();
    Employee* pEmpleadoDos=employee_newParametros("100", "papito","8","25600");
    Employee* pEmpleadoTres = employee_newParametros("101", "johnyBGood", "5","154000");
    if(pipiList != NULL)
    {
    	if(pEmpleado != NULL && pEmpleadoDos != NULL)
    	{
    		employee_setNombre(pEmpleado, "Pepito");
			employee_setId(pEmpleado, 102);
         	employee_setHorasTrabajadas(pEmpleado, 3);
			employee_setSueldo(pEmpleado, 26000);

		//	employee_showUnit(pEmpleado);


			if(ll_add(pipiList, pEmpleado)==0 && ll_add(pipiList, pEmpleadoDos) == 0 && ll_add(pipiList, pEmpleadoTres) == 0)
			{
				 controller_addEmployee(pipiList);

				   controller_ListEmployee(pipiList);
				   ll_sort(pipiList, employee_sortSalaryDescendant,1);
				   controller_ListEmployee(pipiList);
			}

			free(pEmpleado);
			ll_deleteLinkedList(pipiList);
    	}

    }

  /*  do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);*/
    return 0;
}

