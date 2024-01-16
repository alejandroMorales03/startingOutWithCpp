#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H

#include "/Users/alejandromorales/projects/Chapte15/Program7/PersonDataClass/PersonData.h"

class CustomerData : public PersonData{
    private:
        int customerNumber;
        bool mailingList;

    public:
        CustomerData(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, std::string zip, std::string phoneNumber, int csNumber, bool mailList);

        bool getMailChoice()const{return mailingList;}
        int getCustomerNumber()const{return customerNumber;}
        virtual ~CustomerData(){};

};

#endif