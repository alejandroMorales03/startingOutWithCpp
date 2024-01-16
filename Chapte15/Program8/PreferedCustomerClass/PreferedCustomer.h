#ifndef PREFEREDCUSTOMER_H
#define PREFEREDCUSTOMER_H

#include "/Users/alejandromorales/projects/Chapte15/Program7/CustomerDataClass/CustomerData.h"

class PreferedCustomer : public CustomerData{
    private:
        enum SPENDING_THRESHOLDS{SP1 = 500, SP2 = 1000, SP3 = 1500, SP4 = 2000};
        enum DISCOUNT_LVLS{LVL1 = 5, LVL2 = 6, LVL3 = 7, LVL4 = 10};
        double purchaseAmount;
        double discout;

        void setDiscount();

    public:
        PreferedCustomer(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, std::string zip, std::string phoneNumber, int csNumber, bool mailList, double totalSpent);
        void setPurchaseAmount(double amount);

        double getTotalSpent()const{return purchaseAmount;}
        double getDiscount()const{return discout;}
};

#endif