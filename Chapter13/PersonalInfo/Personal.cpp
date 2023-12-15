#include "Personal.h"

Personal::Personal(string name_u, string adds_u, int age_u, string phone_u){
    name = name_u;
    address = adds_u;
    age = age_u < 1 ? 1 : age;
    phone_u = checkPhoneNumber(phone_u)? phone_u : "(000) 000-0000";
}

bool Personal::checkPhoneNumber(string phone_u){
    if(phone_u.length() != 14)
        return false;
    if(phone_u.at(0) != '(' || phone_u.at(4) != ')' || phone_u.at(5) != ' ' || phone_u.at(9) != '-')
        return false;
    for(short index = 1; index < 14; index++){
        if(index != 0 && index != 4 && index != 5 && index != 9){
            if(!isdigit(phone_u.at(index)))
                return false;
        }
    }

    return true;
}

string Personal::getName()const{
    return name;

}
string Personal::getAddress()const{
    return address;

}
string Personal::getPhoneNumber()const{
    return phone_number;

}
int Personal::getAge()const{
    return age;

}