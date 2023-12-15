#include "mortgage.h"
#include <iostream>

using namespace std;

int main(){

    float loan_amount;
    const float INT_RATE = 0.09;
    const int TERM_1 = 60, TERM_2 = 36;

    cout << "\n* * * WELCOME TO THE BANK * * * \n";
    cout << "\nEnter loan amount requested: ";
    cin >> loan_amount;

    mortgage offer1(loan_amount, INT_RATE, TERM_1/12);
    mortgage offer2;
    offer2.setLoan(loan_amount);
    offer2.setIntt(INT_RATE);
    offer2.setYears(TERM_2/12);

    mortgage offer3(-loan_amount, -INT_RATE, -TERM_1/12);
    mortgage offer4;
    offer4.setLoan(-loan_amount);
    offer4.setIntt(-INT_RATE);
    offer4.setYears(-TERM_2/12);

    cout << "\nOFFERS: \n";
    cout << "\n" << offer1.getPayment();
    cout << "\n" << offer1.getDifference();
    cout << "\n\n" << offer2.getPayment();
    cout << "\n" << offer2.getDifference();
    cout << "\n\n" << offer3.getPayment();
    cout << "\n" << offer3.getDifference();
    cout << "\n\n" << offer4.getPayment();
    cout << "\n" << offer4.getDifference() << "\n\n";
    
    

}