#include "Date.h"
#include <iostream>

using namespace std;

string Date::monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int Date::lastDayOfMonth = 31;
int Date::lastMonthOfTheYear = 12;

void Date::setLastDayOfMonth(){
    if(month == 2){
        if(checkLeap())
            lastDayOfMonth = 29;
        else
            lastDayOfMonth = 28;
    }
    else if ((month % 2 != 2 && month  <= 7) || (month % 2 == 0 and month > 7)){
        lastDayOfMonth = 31;
    }
    else{
        lastDayOfMonth = 30;
    }
}

bool Date::checkLeap(){
    bool leap = false;
    
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        return true;
    }
    return false;
}

Date::Date(int dMonth, int dDay, int dYear){
    dYear = abs(dYear);
    dMonth = abs(dMonth);
    dDay = abs(dDay);
    
    
    year = dYear;
    if(dMonth > lastMonthOfTheYear){
        month = dMonth - lastMonthOfTheYear;
        year++;
    }
    else
        month = dMonth;

    setLastDayOfMonth();
    
    if(dDay > lastDayOfMonth){
        while(dDay > lastDayOfMonth){
            dDay -= lastDayOfMonth;
        }
        day = abs(dDay);
        month = month == 12? 1 : ++month;
        
        if(month > lastDayOfMonth){
            month = 1;
            year++;
        }
    }
    else{
        day = dDay;
    }
}

void Date::setDate(int dMonth, int dDay, int dYear){
    *this = Date(dMonth, dDay, dYear);
}

void Date::printDate(){
    cout << monthNames[month - 1] + " " + to_string(day) + ", " + to_string(year) << "\n";
}

Date Date::operator++(){
    return Date(this->month, this->day + 1, this->year);
}
Date Date::operator++(int){
    Date temp = *this;
    this->setDate(this->month, this->day + 1, this->year);
    return temp;
}

Date Date::operator--(){
    if(this->month == 1 && this->day == 1){
        this->day = 31;
        this->month = 12;
        this->year--;
    }
    else{
        this->day--;
    }
    return *this;
}
Date Date::operator--(int){
    Date temp = *this;
    if(this->month == 1 && this->day == 1){
        this->day = 31;
        this->month = 12;
        this->year--;
    }
    else{
        this->day--;
    }
    return temp;
}

bool Date::operator!=(const Date& anotherDate){
    if(this->day == anotherDate.day && this->year == anotherDate.year && this->month == anotherDate.month)
        return false;
    return true;
}

bool Date::operator<(const Date& anotherDate){
    if(this->year < anotherDate.year)
        return true;
    else if(this->year == anotherDate.year){
        if(this->month < anotherDate.month)
            return true;
        else if(this->month == anotherDate.month){
            return this->day < anotherDate.day;
        }
        else 
            return false;
    }
    else
        return false;
}

int Date::operator-(const Date& anotherDate){
    bool negative = false;
    int countedDays = 0;
    Date lowerBound, upperBoud;
    if(*this < anotherDate){
        lowerBound = *this;
        upperBoud =  anotherDate;
        negative = true;
    }
    else{
        lowerBound = anotherDate;
        upperBoud =  *this;
    }

    while(lowerBound != upperBoud){
        lowerBound++;
        countedDays++;
    }

    return negative? -countedDays : countedDays;
}

istream &operator>>(istream &stream, Date& obj){
    cout << "\nEnter the month in numeric form: ";
    cin >> obj.month;
    cout << "Enter the day in numeric form: ";
    cin >> obj.day;
    cout << "Enter the year in numeric form: ";
    cin >> obj.year;

    obj = Date(obj.month, obj.day, obj.year);
    return stream;
}

ostream &operator<<(ostream &stream, const Date& obj){
    cout << obj.monthNames[obj.month - 1] << " " << obj.day << ", " << obj.year;
    return stream;
}