#include "TimeOff.h"
#include <iostream>

using namespace std;

int main(){
    TimeOff employee("Alejandro Morales", "4703AM");

    cout << "\nPrinting Employee Data Right After Employment";
    cout << "\nMax Sick Days:      " << employee.getMaxSick();
    cout << "\nTaken Sick Days:    " << employee.getSickTaken();
    cout << "\nMax Vacation Days:  " << employee.getMaxVac();
    cout << "\nTaken Vacation Days " << employee.getVacTaken();
    cout << "\nMax Unpaid Days:    " << employee.getMaxUnp();
    cout << "\nTaken Unpaid Days:  " << employee.getUnpTaken();


    cout << "\n\nPrinting Employee Data Right After 20 Months of Employment";
    int count = 0;
    //while(count < 3){
        count++;
        employee.updateTimeOff(21);
        cout << "\nMax Sick Days:      " << employee.getMaxSick();
        cout << "\nTaken Sick Days:    " << employee.getSickTaken();
        cout << "\nMax Vacation Days:  " << employee.getMaxVac();
        cout << "\nTaken Vacation Days " << employee.getVacTaken();
        cout << "\nMax Unpaid Days:    " << employee.getMaxUnp();
        cout << "\nTaken Unpaid Days:  " << employee.getUnpTaken();
   // }

    return 0; 
}