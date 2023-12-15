#include "Employee.h"
#include <iostream>

Employee:: Employee(long id_u, string name_u, string dept_u, string pos_u){
    id_number = id_u > 0? id_u : 0;
    name = name_u;
    department = dept_u;
    position = pos_u;
}

Employee::Employee(long id_u, string name_u){
    id_number = id_u > 0? id_u : 0;
    name = name_u;
    position = "";
    department = "";
}

Employee::Employee(){
    id_number = 0;
    name = "";
    position = "";
    department = "";

}