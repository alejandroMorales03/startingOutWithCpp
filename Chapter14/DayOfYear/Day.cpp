#include "Day.h"
#include <iostream>
using namespace std;

string Day::monthKeys[]= {"January", "Febraury", "March", "April", "May", "June", 
                          "July", "August", "Septemeber", "October", "November", "December"};
const int Day::MAX_DAYS = 365;
const int Day::MIN_DAYS = 1;


Day::Day(int day){
    this->day = day < MIN_DAYS? MIN_DAYS : day > MAX_DAYS? MAX_DAYS: day;
}

Day::Day(int day, string month){
    bool found = false;

    short index;
    for(index  = 0; index < sizeof(monthKeys)/sizeof(monthKeys[0]) && !found; index++){
        if(month == monthKeys[index])
            found = true;
    }

    if(!found){
        cout << "\nINVALID MONTH\n\n";
        exit(0);
    }
    else{
        if(index == 2){
            if(day < 0 || day > 28){
                cout << "\nINVALID DAY\n\n";
                exit(0);
            }
        }
        else if((index % 2 != 0 && index <= 7 ) || (index % 2 == 0 && index > 7)){
            if(day < 0 || day > 31){
                cout << "\nINVALID DAY\n\n";
                exit(0);
            }
        }
        else{
            if(day < 0 || day > 30){
                cout << "\nINVALID DAY\n\n";
                exit(0);
            }
        }
        
        int count = 1;
        this->day = 0;

        index--;
        while(count <= index){
            if(count == 2){
                this->day += 28;
            }
            else if((count % 2 != 0 && count <= 7 ) || (count % 2 == 0 && count > 7)){
                this->day += 31;
            }
            else{
                this->day += 30;
            }

            count++;

            
        }

        this->day+=day;

        
    }

}

void Day::print(){
    int month = 0;
    int copyOfDay = day;

    while(copyOfDay > 31){
        month++;
        if(month == 2)
            copyOfDay -= 28;
        else if ((month % 2 != 0 && month <= 7) || (month % 2 == 0 && month > 7)){
            copyOfDay -= 31;
        }
        else{
            copyOfDay -= 30;
        }
    }

    cout << "\n" << monthKeys[month] << ", " << copyOfDay << "\n";
}

Day Day::operator++(){
    this->day++;
    this->day = this->day > MAX_DAYS? MIN_DAYS : day;
    return *this;
}

Day Day::operator--(){
    this->day--;
    this->day = this->day < MIN_DAYS? MAX_DAYS : day;
    return *this;
}

Day Day::operator++(int){
  Day temp(this->day);
  ++(*this);
  return temp;
}

Day Day::operator--(int){
    Day temp(this->day);
    --(*this);
    return temp;

}





