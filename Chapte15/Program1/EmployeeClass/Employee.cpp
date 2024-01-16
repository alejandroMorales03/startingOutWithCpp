#include "Employee.h"
#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>

Employee::Employee(std::string empName, int empNumber, int hireMonth, int hireDay, int hireYear){
    std::tm zerotime = {0};
    hireDate = zerotime;
    modifyEmpName(empName);
    modifyHireDate(hireMonth, hireDay, hireYear);
    modifyEmpID(empNumber);
}

void Employee::modifyHireDate(int hireMonth, int hireDay, int hireYear){
    hireDate.tm_year = abs(hireYear) - 1900;
    hireDate.tm_mon = abs(hireMonth);
    hireDate.tm_mday = abs(hireDay);
}

void Employee::modifyEmpName(std::string empName){
    name = empName;
}

void Employee::modifyEmpID(int empNumber){
    number = abs(empNumber);
}

std::string Employee::getName()const{
    return name;
}

std::string Employee::getHireDate() {
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* localTimeC = std::localtime(&currentTime);

    char currentBuffer[11];
    std::strftime(currentBuffer, sizeof(currentBuffer), "%m/%d/%Y", localTimeC);

    std::string current_date = std::string(currentBuffer);


    std::time_t convertedHireDate = std::mktime(&hireDate);

    if(convertedHireDate < currentTime){

        std::tm* localTime = std::localtime(&convertedHireDate);

        char buffer[11];
        std::strftime(buffer, sizeof(buffer), "%m/%d/%Y", localTime);
        return std::string(buffer);
    }
    else{
        std::cout << "\nINVALID DATE DETECTED\n";
        exit(0);
    }
}



int Employee::getID() const{
    return number;
}