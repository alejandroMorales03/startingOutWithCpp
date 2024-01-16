#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <chrono>
#include <ctime>

class Employee{
    private:
        std::string name;
        int number;
        std::tm hireDate;


    public:
        Employee(std::string empName = "", int empNumber = 0, int hireMonth = 0, int hireDay = 1, int hireYear = 0);

        void modifyHireDate(int hireMonth = 0, int hireDay = 1, int hireYear = 0);
        void modifyEmpName(std::string name = "");
        void modifyEmpID(int empNumber = 0);

        std::string getName()const;
        std::string getHireDate();
        int getID() const;

        virtual ~Employee(){};







};

#endif