#include "Employee.h"

#include <iostream>

using namespace std;

int main(){
    Employee CEO(20234703, "Alejandro Morales", "Management", "CEO");
    Employee COO(-202325701, "Jonathan Gutierrez");
    Employee newEmployee;

    cout << "\nName\t\t\tID NUMBER\t\tDepartment\t\tPosition\n";
    cout << CEO.getName() << "\t" <<  CEO.getID() << "\t\t" << CEO.getDepartment() << "\t\t" << CEO.getPosition() << "\n";

    COO.setDepartment("Management");
    COO.setPosition("COO");
    COO.setID(202372502);
    cout << COO.getName() <<  "\t" << COO.getID() << "\t\t" <<  COO.getDepartment() << "\t\t" << COO.getPosition() << "\n";

    newEmployee.setName("Random Hernandez");
    newEmployee.setDepartment("Sales");
    newEmployee.setPosition("Salesman");
    newEmployee.setID(20235600);
    cout << newEmployee.getName() << "\t"<< newEmployee.getID() << "\t\t" << newEmployee.getDepartment() << "\t\t\t" << newEmployee.getPosition() << "\n\n";
    return 0;
}