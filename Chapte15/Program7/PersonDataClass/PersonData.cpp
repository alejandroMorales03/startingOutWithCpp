#include "PersonData.h"

PersonData::PersonData(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, std::string zip, std::string phoneNumber){
    setLast(lastName);
    setFirst(firstName);
    setAdd(address);
    setCity(city);
    setState(state);
    setZip(zip);
    setPhone(phoneNumber);
}

void PersonData::setLast(std::string lastName){
    this->lastName = lastName;
}
void PersonData::setFirst(std::string firstName){
    this->firstName = firstName;
}
void PersonData::setAdd(std::string address){
    this->address = address;
}
void PersonData::setCity(std::string city){
    this->city = city;
}
void PersonData::setState(std::string state){
    this->state = state;
}
void PersonData::setZip(std::string zip){
    this->zip = zip;
}
void PersonData::setPhone(std::string phoneNumber){
    this->phoneNumber = checkPhoneNumber(phoneNumber);
}


std::string PersonData::checkPhoneNumber(std::string unformatted){
    if(unformatted.length() != 14)
        throw std::runtime_error("PHONE NUMBER FORMAT DOES NOT MATCH EXPECTED FORMAT: (###) ###-#### | ERROR TYPE: LENGTH");
    else if(unformatted.at(0) != '('||unformatted.at(4) != ')' || unformatted.at(5) != ' '|| unformatted.at(9) != '-')
        throw std::runtime_error("PHONE NUMBER FORMAT DOES NOT MATCH EXPECTED FORMAT: (###) ###-#### | ERROR TYPE: SPECIAL CHARS");

    for(short index = 1; index < 14; index++){
        if(index != 4 && index != 5 && index != 9 && !isdigit(unformatted.at(index)))
            throw std::runtime_error("PHONE NUMBER FORMAT DOES NOT MATCH EXPECTED FORMAT: (###) ###-#### | ERROR TYPE: NUMERIC CHARS");
    }

    return unformatted;
}

std::string PersonData::getLast()const{return lastName;}
std::string PersonData::getFirst()const{return firstName;}
std::string PersonData::getAdd()const{return address;}
std::string PersonData::getCity()const{return city;}
std::string PersonData::getState()const{return state;}
std::string PersonData::getZip()const{return zip;}
std::string PersonData::getPhone()const{return phoneNumber;}
