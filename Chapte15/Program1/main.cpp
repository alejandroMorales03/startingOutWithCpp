#include "/Users/alejandromorales/projects/Chapte15/Program1/ProductionWorkerClass/ProductionWorker.h"
#include <iostream>
#include <memory>
using namespace std;

int main(){

    //Test of Corrent Object
    ProductionWorker newWorker("Alejandro Morales", 4703, 3, 7, 2003, 1, 18.15);
    std::cout << "\n" << newWorker.getName();
    std::cout << "\n" << newWorker.getID();
    std::cout << "\n" << newWorker.getHireDate();
    std::cout << "\n" << newWorker.getPay();
    std::cout << "\n" << newWorker.getShift();
    std::cout << "\n* * * * * * * * * \n";

    //Test of Incorrect Objecct

    ProductionWorker otherWorker("Alejandro Morales", 4703, 3, 7, 2023, 1, 18.15);
    std::cout << "\n" << otherWorker.getName();
    std::cout << "\n" << otherWorker.getID();
    std::cout << "\n" << otherWorker.getHireDate();
    std::cout << "\n" << otherWorker.getPay();
    std::cout << "\n" << otherWorker.getShift();
    std::cout << "\n* * * * * * * * * \n";

    std::unique_ptr<Employee>newEmployee(new Employee("Alejandro Morales"));
    std::cout << "\n" << newEmployee->getName();
    std::cout << "\n" << newEmployee->getID();
    std::cout << "\n" << newEmployee->getHireDate();
    std::cout << "\n* * * * * * * * * \n\n";


    return 0;

}