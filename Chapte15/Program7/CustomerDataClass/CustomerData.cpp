#include "CustomerData.h"
#include <string>

CustomerData::CustomerData(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, std::string zip, std::string phoneNumber, int csNumber, bool mailList) : 
    PersonData(lastName, firstName, address, city, state, zip, phoneNumber){
        customerNumber = csNumber;
        mailingList = mailList;
    }
