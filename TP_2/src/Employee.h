/*
 * Employee.h
 *
 *  Created on: 28 sep. 2021
 *      Author: sole
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#define LEN 51
#define TAM 100


struct
{
	int id;
	char name[LEN];
	char lastName[LEN];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;

int menuEmployee();
void initEmployees(Employee* arrayEmp,int tam);
void cargaEmployeeHard(Employee* arrayEmp, int* id);
void mostrarDatosEmployee(Employee unidadEmp);
int deleteEmployee(Employee* arrayEmp, int len);
void showListEmployee(Employee* arrayEmp, int tam);
int findIsEmpty(Employee* arrayE, int tam);
int findById(Employee* arraEmp, int len, int id, int* index);
int registerAnEmployee(Employee* arrayEmp, int len, int* id);
int addEmployee(Employee* arrayEmp, int* id, char* name, char* lastName, float salary, int sector);
int menuModify(Employee* arrayEmp, int len, int* index, int* option);
int modifyEmployee(Employee* arrayEmp, int len);
int deleteOneEmp(Employee* unitEmployee);
int menuReports();
int sortEmployees(Employee* arrayEmp, int len);
int sortEmployeesSector(Employee* arrayEmp, int len);

#endif /* EMPLOYEE_H_ */
