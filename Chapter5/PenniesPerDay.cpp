#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    short days_worked;
    do{
        cout << "\nEnter the number of days worked: ";
        cin >> days_worked;
        if(days_worked < 1)
            cout <<"\nINVALID INPUT!\n* Payperiod must be at least 1 day\n";

    }while(days_worked < 1);
    
    cout << "\nDay\t\tDollars\n";
    float pay = 0.01, total_pay = 0;
    for(short day_counter = 1; day_counter <= days_worked; day_counter++, pay*=2){
        cout << "\n" << setw(4) << day_counter<<  "\t\t" << setprecision(3) << fixed << setw(7) << pay;
        total_pay += pay;
    }

    cout << "\n\nTotal Earned: $ " << setw(6) << total_pay << "\n\n";
    return 0;
}