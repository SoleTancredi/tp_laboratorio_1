#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salaryStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void employee_showUnit(Employee* this);
int employee_showList(LinkedList* this);

int employee_mainModify();
int employee_modify(Employee* this);

void employee_posterSelected();
void employee_posterModified();
void employee_posterPreview();
void employee_posterList();

int employee_add(Employee* this, int* id, char* nombre, int horasTrabajadas, int sueldo);
int employee_register(Employee* this, int id);

int employee_sortSalary(void* thisOne, void* thisTwo);
int employee_sortHours(void* thisOne, void* thisTwo);
int employee_sortNames(void* thisOne, void* thisTwo);

int employee_menuSortStandard();
int employee_menuSortWay();

#endif // employee_H_INCLUDED
