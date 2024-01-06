#include "Numbers.h"
#include <iostream>
using namespace std;

int main(){
    int number; 

    cout << "\nEnter a number to be converted to string: ";
    cin >> number;

    Numbers userNumber(number);
    userNumber.print();
    cout << "\n\n";
    return 0;
}