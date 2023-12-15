#include "Payroll.h"
#include "iostream"
using namespace std;

int main(){
    Payroll myPayroll[7];
    float hours, pay;
    for(short index = 0; index < sizeof(myPayroll)/sizeof(myPayroll[0]); index++){
        cout << "\nEnter hours for employee " << index + 1 << ": ";
        cin >> hours;
        myPayroll[index].setHours(hours);
        cout << "Enter hourly rate for employee " << index + 1 << ": ";
        cin >> pay;
        myPayroll[index].setPay(pay);
    }

    cout << "\nGROSS INCOME FOR EACH EMPLOYEE\n";
    for(short index = 0; index < sizeof(myPayroll)/sizeof(myPayroll[0]); index++){
        cout << "\nEmployee " << index + 1 << ": " << myPayroll[index].getGross();
    }
    cout << "\n\n";
    return 0;
}
