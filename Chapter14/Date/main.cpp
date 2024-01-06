#include "Date.h"
#include <iostream>

using namespace std;

int main(){
    Date myBirth(4, 7, 2003);
    Date yourBirth;

    myBirth.printDate();
    myBirth.setDate(11, -62, 2003);
    myBirth.printDate();
    myBirth++;
    myBirth.printDate();

    cout << "\n";
    yourBirth.printDate();
    
    myBirth = yourBirth++;
    cout << "\n";
    myBirth.printDate();
    yourBirth.printDate();

    myBirth = yourBirth--;
    cout << "\n";
    myBirth.printDate();
    yourBirth.printDate();

    cout << "\n" << yourBirth - myBirth;

    cin >> myBirth;
    myBirth.printDate();
    myBirth.setDate(12,31,2003);

    --myBirth;
    --myBirth;
    cout << myBirth;
    cout << "\n";
    return 0;
}