#include "Month.h"
#include <iostream>

using namespace std;

int main(){

    Month myBirthMonth;
    Month anotherMonth;

    cout << "\n" << myBirthMonth.getLitMonth();
    cout << "\n" << myBirthMonth.getNumMonth();

    myBirthMonth.setMonth("April");
    cout << "\n" << myBirthMonth.getLitMonth();
    cout << "\n" << myBirthMonth.getNumMonth();

    myBirthMonth.setMonth(12);
    cout << "\n" << myBirthMonth.getLitMonth();
    cout << "\n" << myBirthMonth.getNumMonth();

    myBirthMonth.setMonth(13);
    cout << "\n" << myBirthMonth.getLitMonth();
    cout << "\n" << myBirthMonth.getNumMonth();

    myBirthMonth.setMonth(-1);
    cout << "\n" << myBirthMonth.getLitMonth();
    cout << "\n" << myBirthMonth.getNumMonth();

    ++myBirthMonth;
    cout << "\n" << myBirthMonth.getLitMonth();
    cout << "\n" << myBirthMonth.getNumMonth();

    --myBirthMonth;
    cout << "\n" << myBirthMonth.getLitMonth();
    cout << "\n" << myBirthMonth.getNumMonth();

    anotherMonth = myBirthMonth++;
    cout << "\n\n" << myBirthMonth.getLitMonth();
    cout << "\n" << myBirthMonth.getNumMonth();
    cout << "\n" << anotherMonth.getLitMonth();
    cout << "\n" << anotherMonth.getNumMonth();

    anotherMonth = myBirthMonth--;
    cout << "\n\n" << myBirthMonth.getLitMonth();
    cout << "\n" << myBirthMonth.getNumMonth();
    cout << "\n" << anotherMonth.getLitMonth();
    cout << "\n" << anotherMonth.getNumMonth();

    Month yetAnotherMonth;
    cout << "\n\n";
    cout << yetAnotherMonth;
    cin >> yetAnotherMonth;
    cout << yetAnotherMonth;

    myBirthMonth.setMonth("Aprill");
    cout << "\n" << myBirthMonth.getLitMonth();
    cout << "\n" << myBirthMonth.getNumMonth();
    return 0;
}