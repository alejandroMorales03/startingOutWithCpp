#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <string>
class PersonData{
    private:
        std::string lastName;
        std::string firstName;
        std::string address;
        std::string city;
        std::string state;
        std::string zip;
        std::string phoneNumber;

        std::string checkPhoneNumber(std::string unformatted);

    public:
        PersonData(std::string lastName, std::string firstName, std::string address, std::string city, std::string state, std::string zip, std::string phoneNumber);
        
        void setLast(std::string lastName);
        void setFirst(std::string firstName);
        void setAdd(std::string address);
        void setCity(std::string city);
        void setState(std::string state);
        void setZip(std::string zip);
        void setPhone(std::string phone_number);

        std::string getLast()const;
        std::string getFirst()const;
        std::string getAdd()const;
        std::string getCity()const;
        std::string getState()const;
        std::string getZip()const;
        std::string getPhone()const;

        virtual ~PersonData(){};



};

#endif