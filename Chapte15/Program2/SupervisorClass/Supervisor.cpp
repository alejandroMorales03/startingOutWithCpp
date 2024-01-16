#include "Supervisor.h"

Supervisor::Supervisor(std::string empName, int empNumber, int hireMonth, int hireDay, int hireYear, double salary, double bonus) :
    Employee(empName, empNumber, hireMonth, hireDay, hireYear){
        setSalary(salary);
        setBonus(bonus);

}

void Supervisor::setBonus(double bonus){
    annualProdBonus = bonus < 0 ? 0 : bonus ;
}

void Supervisor::setSalary(double salary){
    annualSalaray = salary < 0 ? 0 : salary;
}

double Supervisor::getBonus()const{
    return annualProdBonus;
}

double Supervisor::getSalary()const{
    return annualSalaray;
}