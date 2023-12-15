#ifndef PERSONAL_H
#define PERSONAL_H

#include <string>
using namespace std;

class Personal{
    private:
        string name;
        string address;
        int age;
        string phone_number;

        bool checkPhoneNumber(string phone_u);

    public: 
        Personal(string name_u = "N/A", string adds_u = "N/A", int age_u = 1, string phone_u = "(000) 000-0000");
        string getName()const;
        string getAddress()const;
        string getPhoneNumber()const;
        int getAge()const;

        


};

#endif