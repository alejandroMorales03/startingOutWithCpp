#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H

#include "/Users/alejandromorales/projects/Chapte15/Program1/EmployeeClass/Employee.h"

class ProductionWorker : public Employee{
    private:
        int shift;
        double hourlyRate;

    public:
        ProductionWorker(std::string empName = "", int empNumber = 0, int hireMonth = 0, int hireDay = 1, int hireYear = 0, int empShift = 1, double pay = 0);

        void changeShift(int newShift);
        void changePay(double newPay);

        std::string getShift()const;
        double getPay()const;

        virtual ~ProductionWorker(){};
        

};

#endif