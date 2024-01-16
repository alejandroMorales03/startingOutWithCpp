#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "/Users/alejandromorales/projects/Chapte15/Program1/EmployeeClass/Employee.h"

class Supervisor : public Employee{
    private:
        double annualSalaray;
        double annualProdBonus;

    public:
        Supervisor(std::string empName = "", int empNumber = 0, int hireMonth = 0, int hireDay = 1, int hireYear = 0, double salary = 0, double bonus = 0);

        void setBonus(double bonus = 0);
        void setSalary(double salary = 0);

        double getBonus() const;
        double getSalary() const;


        ~Supervisor(){};

};

#endif