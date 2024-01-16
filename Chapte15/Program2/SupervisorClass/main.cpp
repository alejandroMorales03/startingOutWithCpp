#include "Supervisor.h"
#include <iostream>

int main(){
    Supervisor newBoss("Alejandro Morales", 4703, 3, 7, 2003, 70000, 3100);

    std::cout << "\n" <<  newBoss.getName();
    std::cout << "\n" <<  newBoss.getID();
    std::cout << "\n" <<  newBoss.getHireDate();
    std::cout << "\n" <<  newBoss.getSalary();
    std::cout << "\n" <<  newBoss.getBonus() << "\n";

    newBoss.modifyEmpID(1000);
    newBoss.modifyEmpName("Morales Alejandro");
    newBoss.modifyHireDate(9, 26, 1971);
    newBoss.setBonus(0);
    newBoss.setSalary();

    std::cout << "\n" <<  newBoss.getName();
    std::cout << "\n" <<  newBoss.getID();
    std::cout << "\n" <<  newBoss.getHireDate();
    std::cout << "\n" <<  newBoss.getSalary();
    std::cout << "\n" <<  newBoss.getBonus() << "\n";

    std::unique_ptr<Employee> newSup(new Supervisor());
    std::cout << "\n" <<  newSup->getName();
    std::cout << "\n" <<  newSup->getID();
    std::cout << "\n" <<  newSup->getHireDate() << "\n";

    newSup->modifyEmpID(1000);
    newSup->modifyEmpName("Morales Alejandro");
    newSup->modifyHireDate(9, 26, 1971);

    std::cout << "\n" <<  newSup->getName();
    std::cout << "\n" <<  newSup->getID();
    std::cout << "\n" <<  newSup->getHireDate() << "\n\n";


    return 0;
}