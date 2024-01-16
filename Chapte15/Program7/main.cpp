#include <iostream>
#include "/Users/alejandromorales/projects/Chapte15/Program7/PersonDataClass/PersonData.h"
#include "/Users/alejandromorales/projects/Chapte15/Program7/CustomerDataClass/CustomerData.h"

using namespace std;

int main(){

    PersonData myPerson("Morales", "Alejandro", "13031 SW 259 St", "Homestead", "Fl", "33032", "(786) 576-8083");
    cout << myPerson.getFirst() << "\n";
    cout << myPerson.getLast() << "\n";
    cout << myPerson.getAdd() << "\n";
    cout << myPerson.getCity() << "\n";
    cout << myPerson.getState() << "\n";
    cout << myPerson.getZip() << "\n";
    cout << myPerson.getPhone() << "\n";

    CustomerData myCustomer("Morales", "Alejandro", "13031 SW 259 St", "Homestead", "Fl", "33032", "(786) 576-8083", 123409, true);
    cout << myCustomer.getFirst() << "\n";
    cout << myCustomer.getLast() << "\n";
    cout << myCustomer.getAdd() << "\n";
    cout << myCustomer.getCity() << "\n";
    cout << myCustomer.getState() << "\n";
    cout << myCustomer.getZip() << "\n";
    cout << myCustomer.getPhone() << "\n";
    cout << myCustomer.getCustomerNumber() << "\n";
    cout << myCustomer.getMailChoice() << "\n\n";

    return 0;
}