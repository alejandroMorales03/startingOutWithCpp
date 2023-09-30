#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    short years;
    const unsigned short MONTHS = 12;
    float total_inches = 0, monthly_inches;
    do{
        cout << "\nEnter a number of years: ";
        cin >> years;
        if(years < 1)
            cout << "\nINVALID INPUT!\n* Number of years cannot be smaller than 1\n";
    }while(years < 1);

    for(short c_year = 1; c_year <= years; c_year++){
        cout << "\n";
        for(short c_month = 1; c_month <= MONTHS; c_month++){
            do{
                cout << "Enter total monthly rainfall in inches for month " << setw(2) << c_month << " of year " << c_year << ": ";
                cin >> monthly_inches;               
                if(monthly_inches < 0)
                    cout << "\nINVALID INPUT!\n* Rainfall must be positive\n\n";
            }while(monthly_inches < 0);
            total_inches += monthly_inches;
        }
    }

    cout << "\nNumber of months: " << years * MONTHS << "\n";
    cout << "Total Inches of Rainfall: " << total_inches << "\n";
    cout << "Average Monthly Rainfall: " << total_inches / (years * MONTHS) << "\n\n";
    


}