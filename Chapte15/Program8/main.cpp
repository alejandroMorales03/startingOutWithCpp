#include "/Users/alejandromorales/projects/Chapte15/Program8/PreferedCustomerClass/PreferedCustomer.h"
#include <iostream>

int main(){
    PreferedCustomer myFavCustomer("Morales", "Alejandro", "13031 SW 259St", "Homestead", "Florida", "33032", "(786) 576-8083", 34520, true, 1500);
    std::cout << myFavCustomer.getFirst() << "\n";
    std::cout << myFavCustomer.getLast() << "\n";
    std::cout << myFavCustomer.getAdd() << "\n";
    std::cout << myFavCustomer.getCity() << "\n";
    std::cout << myFavCustomer.getState() << "\n";
    std::cout << myFavCustomer.getZip() << "\n";
    std::cout << myFavCustomer.getPhone() << "\n";
    std::cout << myFavCustomer.getCustomerNumber() << "\n";
    std::cout << myFavCustomer.getMailChoice() << "\n";
    std::cout << myFavCustomer.getTotalSpent() << "\n";
    std::cout << myFavCustomer.getDiscount() << "%\n\n";
    return 0;
}