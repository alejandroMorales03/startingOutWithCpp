#include "ProductionWorker.h"
#include <cmath>

ProductionWorker::ProductionWorker(std::string empName, int empNumber, int hireMonth, int hireDay, int hireYear, int empShift, double pay) : 
    Employee(empName, empNumber, hireMonth, hireDay, hireYear){

    changeShift(empShift);
    changePay(pay);
}

void ProductionWorker::changeShift(int newShift){
    shift = newShift < 1?  2 : newShift > 2 ? 1 : newShift;
}
void ProductionWorker::changePay(double newPay){
    hourlyRate = newPay < 0? 0 : newPay;
}

std::string ProductionWorker::getShift()const{
    return shift == 1? "Daytime" : "Nightime";
}

double ProductionWorker::getPay()const{
    return hourlyRate;
}