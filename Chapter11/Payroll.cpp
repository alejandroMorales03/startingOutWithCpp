#include <iostream>
#include <iomanip>
using namespace std;

struct Hourly{
    float hours;
    float hour_rate;

};
struct Salary{
    float salary;
    float bonus;

};

union TypeOfPay{
    Hourly byHour;
    Salary bySalary;
};

bool validateUserInput(float,float,float );

int main(){
    cout << setprecision(2) << fixed;
    TypeOfPay payment;
    short type;

    do{
        cout << "\nSelect payment type for employee: \n\n1. Hourly\n2. Salary\n\nSelection: ";
        cin >> type;
    }while(validateUserInput(type, 1, 2));

    switch(type){
        case 1:
            do{
                cout << "\nEnter hours worked: ";
                cin >> payment.byHour.hours;
            }while(validateUserInput(payment.byHour.hours, 0, 60));
            do{
                cout << "\nEnter hourly rate: ";
                cin >> payment.byHour.hour_rate;
            }while(validateUserInput(payment.byHour.hour_rate, 0, payment.byHour.hour_rate));

            cout << "\nGross Pay: $ " << payment.byHour.hour_rate * payment.byHour.hours;
            break;
        case 2:{
            do{
                cout << "\nEnter employee's salary: ";
                cin >> payment.bySalary.salary;
            }while(validateUserInput(payment.bySalary.salary, 0, payment.bySalary.salary));
            do{
                cout << "\nEnter employee's bonus: ";
                cin >> payment.bySalary.bonus;
            }while(validateUserInput(payment.bySalary.bonus, 0, payment.bySalary.bonus));

            cout << "\nGross Pay: $ " << payment.bySalary.salary + payment.bySalary.bonus;
            break;
        }
    }
    cout << "\n\n";
    return 0;
}

bool validateUserInput(float test, float min, float max){
    if(test >= min && test <= max)
        return false;
    cout << "\nINVALID ENTRY.\n";
    return true;
}