#include "Date.h"
#include <iostream>
#include <algorithm>

const std::string Date::MONTH_NAMES[12] = {"January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December"};

Date::Date(int month_arg, int day_arg, int year_arg) :
    MIN_DAY_AND_MONTH(1), MAX_DAY{28, 30, 30}, MAX_MONTH(12), MIN_YEAR(1900)
{

    if(checkRange(abs(year_arg), MIN_YEAR, year_arg))
        year = year_arg;
    else 
        throw InvalidYearException(year_arg);

    if(checkRange(MAX_MONTH, MIN_DAY_AND_MONTH, month_arg))
        month = month_arg;
    else
        throw InvalidMonthException(month_arg);

    if(month == 2)
        max_day = 28;
    else if((month % 2 != 0 && month <= 7) || (month % 2 == 0))
        max_day = 31;
    else
        max_day = 30;


    if(month == 2 && checkLeap())
        max_day = 29;

    if(checkRange(max_day, MIN_DAY_AND_MONTH, day_arg))
        day = day_arg;
    else{
        throw InvalidDayException(day_arg, month);
    }


}

bool Date::checkRange(int max, int min, int value){
    return value <= max && value >= min;
}

bool Date::checkLeap(){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

std::string Date::getDate()const{
    return MONTH_NAMES[month - 1] + " " + std::to_string(day) +  ", " + std::to_string(year) + "\n";
}



Date::InvalidDayException::InvalidDayException(int day_arg, int month_arg) : except_day(day_arg), except_month(month_arg){
    std::cout << "\nERROR| " << day_arg << " IS NOT A VALID DAY OF ";
    std::string uMonth = MONTH_NAMES[month_arg - 1];

    std::transform(uMonth.begin(), uMonth.end(), uMonth.begin(), [](unsigned char c){ 
        return std::toupper(c);
    });

   std::cout << uMonth;
}

Date::InvalidYearException::InvalidYearException(int year_arg) : except_year(year_arg){
    std::cout << "\nERROR| VALID YEAR MUST BE WITHIN [1900 - INF]";

}
Date::InvalidMonthException::InvalidMonthException(int month_arg) : month_except(month_arg){
    std::cout << "\nERROR| VALID MONTH MUST BE WITHIN [1 - 12]";
}
