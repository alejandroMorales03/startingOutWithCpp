#include "DivSales.h"
#include <iostream>
#include <iomanip>

using namespace std;

void printTable(DivSales divisions[]);

int main(){
    DivSales myCompany[6];

    for(short index = 0; index < 6; index++){
        double q1, q2, q3, q4;
        cout << "\nFor division " << index + 1 << ": \n";
        cout << "\nEnter sales for quarter one: ";
        cin >> q1;
        cout << "\nEnter sales for quarter two: ";
        cin >> q2;
        cout << "\nEnter sales for quarter three: ";
        cin >> q3;
        cout << "\nEnter sales for quarter four: ";
        cin >> q4;

        myCompany[index] = DivSales(q1, q2, q3, q4);
    }
    printTable(myCompany);
    return 0;

} 

void printTable(DivSales divisions[]){
    cout << setprecision(2) << fixed;
    cout << "Div\tQuarter 1\tQuarter 2\tQuarter 3\tQuarter 4";
    for(short div = 0; div < 6; div++){
        cout << "\n" << div + 1 ; 
        for(short quarter = 0; quarter < 4; quarter++){
            cout << "\t" << setw(6) << divisions[div].inspectQuarter(quarter) << "\t";
        }
    }

    cout << "\n\n" << "Total Corporate Sales: $ " << DivSales::getTotalSales();


}