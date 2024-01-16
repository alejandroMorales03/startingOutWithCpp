#include "PreferedCustomer.h"

PreferedCustomer::PreferedCustomer(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, std::string zip, std::string phoneNumber, int csNumber, bool mailList, double totalSpent) : 
    CustomerData(lastName, firstName, address, city, state, zip, phoneNumber, csNumber, mailList){
        purchaseAmount = 0;
        setPurchaseAmount(totalSpent);
        setDiscount();

}

void PreferedCustomer::setPurchaseAmount(double amount){
    purchaseAmount = amount < 0 ? 0 : amount;
}

void PreferedCustomer::setDiscount(){
    if(purchaseAmount >= SP4)
        discout = LVL4;
    else if(purchaseAmount >= SP3)
        discout = LVL3;
    else if(purchaseAmount >= SP2)
        discout = LVL2;
    else
        discout = LVL1;
}