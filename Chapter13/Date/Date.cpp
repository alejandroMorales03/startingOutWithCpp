#include "Date.h"
#include <iomanip>
#include <iostream>

string Date::MONTH_NAMES[] = {"January", "February", "March", "April", "May", "June",
                              "July", "August", "September", "October", "November", "December"};
int Date::FIRST_DAY = 1;
bool Date::INVALID_DATA_DETECTED = false;

Date::Date(int month_u, int day_u, int year_u){
    if(validateRange(month_u, FIRST_MONTH, LAST_MONTH))
        month = month_u;
    else{
        month = FIRST_MONTH;
        INVALID_DATA_DETECTED = true;
    }

    if(validateRange(year_u, FIRST_YEAR, LAST_YEAR))
        year = year_u;
    else{
        year = FIRST_YEAR;
        INVALID_DATA_DETECTED = true;
    }

    if((month % 2 != 0 && month <= 7) || (month % 2 == 0 && month > 7))
        LAST_DAY = 31;
    else if(month == 2){
        if(checkLeap())
            LAST_DAY = 29;
        else
            LAST_DAY = 28;
    }
    else
        LAST_DAY = 30;

    if(validateRange(day_u, FIRST_DAY, LAST_DAY))
        day = day_u;
    else{
        day = FIRST_DAY;
        INVALID_DATA_DETECTED = true;
    }
}

bool Date::validateRange(int value, int low_bound, int high_bound){
    if(value <= high_bound && value >= low_bound)
        return true;
    else return false;
}

bool Date::checkLeap(){
    if((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
        return true;
    return false;
}

void Date::NumbFormat(){
    cout <<  setw(2) << setfill('0') << month << '/' << setw(2) << setfill('0') << day << '/' << year << "\n";
    notifyInvalid();

}
void Date::MixedFormat(){
    cout << day << " " << MONTH_NAMES[month - 1] << " " << year << "\n"; 
    notifyInvalid();

}
void Date::StringFormat(){
    cout <<  MONTH_NAMES[month - 1] << ' ' << day << ", " << year << "\n";
    notifyInvalid();
}

void Date::notifyInvalid(){
    if(Date::INVALID_DATA_DETECTED)
        cout << "\nTHE PRINTED DATE MIGHT NOT MATCH THE ENTERED VALUES BECAUSE ONE OR MORE VALUES WERE FOUND INVALID\n";
}