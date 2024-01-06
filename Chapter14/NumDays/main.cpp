#include "Numdays.h"
#include "iostream"

using namespace std;

int main(){
    Numdays employeeOne(12);
    Numdays employeeTwo;
    Numdays employeeThree;

    employeeTwo.setWorkedHours(12);
    
    employeeThree = employeeOne + employeeTwo;
    cout << "Sum: " << employeeThree.getWorkDays() << "\n";

    employeeThree = employeeOne - employeeTwo;
    cout << "Substraction: " << employeeThree.getWorkDays() << "\n";

    ++employeeThree;
    cout << "Prefix addition: " << employeeThree.getWorkDays() << "\n";

    --employeeThree;
    cout << "Prefix Substraction: " << employeeThree.getWorkDays() << "\n";
    
    cout << "Employee One Initial Status: " << employeeOne.getWorkDays() << "\n"; 
    employeeOne = employeeThree--;
    
    cout << "Postfix substraction: " << employeeThree.getWorkDays() << "\n";
    cout << "Employee One New Status: " << employeeOne.getWorkDays() << "\n"; 

    employeeOne = employeeThree++;
    cout << "Postfix addition: " << employeeThree.getWorkDays() << "\n";
    cout << "Employee One Final Status: " << employeeOne.getWorkDays() << "\n"; 

    return 0;


    



    
}